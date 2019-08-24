/*
	This file is part of OpenWebRX,
	an open-source SDR receiver software with a web UI.
	Copyright (c) 2013-2015 by Andras Retzler <randras@sdr.hu>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
"""
*/

is_firefox=navigator.userAgent.indexOf("Firefox")!=-1;

function arrayBufferToString(buf) {
	//http://stackoverflow.com/questions/6965107/converting-between-strings-and-arraybuffers
	return String.fromCharCode.apply(null, new Uint8Array(buf));
}

function getFirstChars(buf, num)
{
	var u8buf=new Uint8Array(buf);
	var output=String();
	num=Math.min(num,u8buf.length);
	for(i=0;i<num;i++) output+=String.fromCharCode(u8buf[i]);
	return output;
}

var bandwidth;
var center_freq;
var audio_buffer_current_size_debug=0;
var audio_buffer_all_size_debug=0;
var audio_buffer_current_count_debug=0;
var audio_buffer_current_size=0;
var fft_size;
var fft_fps;
var fft_compression="none";
var fft_codec=new sdrjs.ImaAdpcm();
var audio_compression="none";
var waterfall_setup_done=0;
var waterfall_queue = [];
var waterfall_timer;

var audio_server_output_rate=44100;
var audio_client_resampling_factor=1;

var rx_photo_state=1;

function e(what) { return document.getElementById(what); }

ios = /iPad|iPod|iPhone/.test(navigator.userAgent);
//alert("ios="+ios.toString()+"  "+navigator.userAgent);

function init_rx_photo() {
	e("webrx-top-photo-clip").style.maxHeight=rx_photo_height.toString()+"px";
	window.setTimeout(function() { animate(e("webrx-rx-photo-title"),"opacity","",1,0,1,500,30); },1000);
	window.setTimeout(function() { animate(e("webrx-rx-photo-desc"),"opacity","",1,0,1,500,30); },1500);
	window.setTimeout(function() { close_rx_photo() },2500);
}

dont_toggle_rx_photo_flag=0;

function dont_toggle_rx_photo() { dont_toggle_rx_photo_flag=1; }

function toggle_rx_photo() {
	if(dont_toggle_rx_photo_flag) { dont_toggle_rx_photo_flag=0; return; }
	if(rx_photo_state) close_rx_photo();
	else open_rx_photo()
}

function close_rx_photo() {
	rx_photo_state=0;
	animate_to(e("webrx-top-photo-clip"),"maxHeight","px",67,0.93,1000,60,function(){resize_waterfall_container(true);});
	e("openwebrx-rx-details-arrow-down").style.display="block";
	e("openwebrx-rx-details-arrow-up").style.display="none";
}

function open_rx_photo() {
	rx_photo_state=1;
	e("webrx-rx-photo-desc").style.opacity=1;
	e("webrx-rx-photo-title").style.opacity=1;
	animate_to(e("webrx-top-photo-clip"),"maxHeight","px",rx_photo_height,0.93,1000,60,function(){resize_waterfall_container(true);});
	e("openwebrx-rx-details-arrow-down").style.display="none";
	e("openwebrx-rx-details-arrow-up").style.display="block";
}

function style_value(of_what,which) {
	if(of_what.currentStyle) return of_what.currentStyle[which];
	else if (window.getComputedStyle) return document.defaultView.getComputedStyle(of_what,null).getPropertyValue(which);
}

function updateVolume() {
//	volume = volume_factor*parseFloat(e("openwebrx-panel-volume").value) / 1000;
//	volume = parseFloat(e("openwebrx-panel-volume").value) / 1000;
	volume1 = parseFloat(e("openwebrx-panel-volume1").value);
//	volume = 1;
	console.log("volume " +volume1);
	ws.send("SET volume="+volume1);

}

function toggleMute() {
	if (mute) {
		mute = false;
		e("openwebrx-mute-on").id="openwebrx-mute-off";
		e("openwebrx-mute-img").src="pics/openwebrx-speaker.png";
		e("openwebrx-panel-volume").disabled=false;
		e("openwebrx-panel-volume").style.opacity=1.0;
		e("openwebrx-panel-volume").value = volumeBeforeMute;
	} else {
		mute = true;
		e("openwebrx-mute-off").id="openwebrx-mute-on";
		e("openwebrx-mute-img").src="pics/openwebrx-speaker-muted.png";
		e("openwebrx-panel-volume").disabled=true;
		e("openwebrx-panel-volume").style.opacity=0.5;
		volumeBeforeMute = e("openwebrx-panel-volume").value;
		e("openwebrx-panel-volume").value=0;
	}
	updateVolume();
}

function zoomInOneStep ()  { zoom_set(zoom_level+1); }
function zoomOutOneStep () { zoom_set(zoom_level-1); }
function zoomInTotal ()    { zoom_set(zoom_levels.length-1); }
function zoomOutTotal ()   { zoom_set(0); }
function setSquelchDefault() { e("openwebrx-panel-squelch").value=0; }
function setSquelchToAuto() { e("openwebrx-panel-squelch").value=(getLogSmeterValue(smeter_level)+10).toString(); updateSquelch(); }
function updateSquelch()
{
	var sliderValue=parseInt(e("openwebrx-panel-squelch").value);
	var outputValue=(sliderValue==parseInt(e("openwebrx-panel-squelch").min))?0:getLinearSmeterValue(sliderValue);
	ws.send("SET squelch_level="+outputValue.toString());
}

function updateWaterfallColors(which) {
	wfmax=e("openwebrx-waterfall-color-max");
	wfmin=e("openwebrx-waterfall-color-min");
	if(parseInt(wfmin.value)>=parseInt(wfmax.value))
	{
			if(!which) wfmin.value=(parseInt(wfmax.value)-1).toString();
			else wfmax.value=(parseInt(wfmin.value)+1).toString();
	}
	waterfall_min_level=parseInt(wfmin.value);
	waterfall_max_level=parseInt(wfmax.value);
}
function waterfallColorsDefault() {
	waterfall_min_level=waterfall_min_level_default;
	waterfall_max_level=waterfall_max_level_default;
	e("openwebrx-waterfall-color-min").value=waterfall_min_level.toString();
	e("openwebrx-waterfall-color-max").value=waterfall_max_level.toString();
}

function waterfallColorsAuto() {
	e("openwebrx-waterfall-color-min").value=(waterfall_measure_minmax_min-waterfall_auto_level_margin[0]).toString();
	e("openwebrx-waterfall-color-max").value=(waterfall_measure_minmax_max+waterfall_auto_level_margin[1]).toString();
	updateWaterfallColors(0);
}

function setSmeterRelativeValue(value) {
	if(value<0) value=0;
	if(value>1.0) value=1.0;
	var bar=e("openwebrx-smeter-bar");
	var outer=e("openwebrx-smeter-outer");
	bar.style.width=(outer.offsetWidth*value).toString()+"px";
	bgRed="linear-gradient(to top, #ff5939 , #961700)";
	bgGreen="linear-gradient(to top, #22ff2f , #008908)";
	bgYellow="linear-gradient(to top, #fff720 , #a49f00)";
	bar.style.background=(value>0.9)?bgRed:((value>0.7)?bgYellow:bgGreen);
	//bar.style.backgroundColor=(value>0.9)?"#ff5939":((value>0.7)?"#fff720":"#22ff2f");
}

function getLogSmeterValue(value) {
	return 10*Math.log10(value);
}

function getLinearSmeterValue(db_value) {
	return Math.pow(10,db_value/10);
}

function setSmeterAbsoluteValue(value) //the value that comes from `csdr squelch_and_smeter_cc`
{
	var logValue=getLogSmeterValue(value);
	var lowLevel=waterfall_min_level-20;
	var highLevel=waterfall_max_level+20;
	var percent=(logValue-lowLevel)/(highLevel-lowLevel);
	setSmeterRelativeValue(percent);
	e("openwebrx-smeter-db").innerHTML=logValue.toFixed(1)+" dB";
}

function typeInAnimation(element,timeout,what,onFinish) {
	if(!what) { onFinish(); return; }
	element.innerHTML+=what[0];
	window.setTimeout(	function(){typeInAnimation(element,timeout,what.substring(1),onFinish);}, timeout );
}

// ========================================================
// =================  ANIMATION ROUTINES  =================
// ========================================================

function animate(object,style_name,unit,from,to,accel,time_ms,fps,to_exec)
{
	//console.log(object.className);
	if(typeof to_exec=="undefined") to_exec=0;
	object.style[style_name]=from.toString()+unit;
	object.anim_i=0;
	n_of_iters=time_ms/(1000/fps);
	change=(to-from)/(n_of_iters);
	if(typeof object.anim_timer!="undefined") { window.clearInterval(object.anim_timer);  }
	object.anim_timer=window.setInterval(
		function(){
			if(object.anim_i++<n_of_iters)
			{
				if(accel==1) object.style[style_name]=(parseFloat(object.style[style_name])+change).toString()+unit;
				else
				{
					remain=parseFloat(object.style[style_name])-to;
					if(Math.abs(remain)>9||unit!="px") new_val=(to+accel*remain);
					else {if(Math.abs(remain)<2) new_val=to;
					else new_val=to+remain-(remain/Math.abs(remain));}
					object.style[style_name]=new_val.toString()+unit;
				}
			}
			else
				{object.style[style_name]=to.toString()+unit; window.clearInterval(object.anim_timer); delete object.anim_timer; }
			if(to_exec!=0) to_exec();
		},1000/fps);
}

function animate_to(object,style_name,unit,to,accel,time_ms,fps,to_exec)
{
	from=parseFloat(style_value(object,style_name));
	animate(object,style_name,unit,from,to,accel,time_ms,fps,to_exec);
}

// ========================================================
// ================  DEMODULATOR ROUTINES  ================
// ========================================================

demodulators=[]

demodulator_color_index=0;
demodulator_colors=["#ffff00", "#00ff00", "#00ffff", "#058cff", "#ff9600", "#a1ff39", "#ff4e39", "#ff5dbd"]
function demodulators_get_next_color()
{
	if(demodulator_color_index>=demodulator_colors.length) demodulator_color_index=0;
	return(demodulator_colors[demodulator_color_index++]);
}

function demod_envelope_draw(range, from, to, color, line)
{  //                                               ____
	// Draws a standard filter envelope like this: _/    \_
   // Parameters are given in offset frequency (Hz).
   // Envelope is drawn on the scale canvas.
	// A "drag range" object is returned, containing information about the draggable areas of the envelope
	// (beginning, ending and the line showing the offset frequency).
	if(typeof color == "undefined") color="#ffff00"; //yellow
	env_bounding_line_w=5;   //
	env_att_w=5;             //     _______   ___env_h2 in px   ___|_____
	env_h1=17;               //   _/|      \_ ___env_h1 in px _/   |_    \_
	env_h2=5;                //   |||env_att_line_w                |_env_lineplus
	env_lineplus=1;          //   ||env_bounding_line_w
	env_line_click_area=6;
	//range=get_visible_freq_range();
	from_px=scale_px_from_freq(from,range);
	to_px=scale_px_from_freq(to,range);
	if(to_px<from_px) /* swap'em */ { temp_px=to_px; to_px=from_px; from_px=temp_px; }

	/*from_px-=env_bounding_line_w/2;
	to_px+=env_bounding_line_w/2;*/
	from_px-=(env_att_w+env_bounding_line_w);
	to_px+=(env_att_w+env_bounding_line_w);
	// do drawing:
	scale_ctx.lineWidth=3;
	scale_ctx.strokeStyle=color;
	scale_ctx.fillStyle = color;
	var drag_ranges={ envelope_on_screen: false, line_on_screen: false };
	if(!(to_px<0||from_px>window.innerWidth)) // out of screen?
	{
		drag_ranges.beginning={x1:from_px, x2: from_px+env_bounding_line_w+env_att_w};
		drag_ranges.ending={x1:to_px-env_bounding_line_w-env_att_w, x2: to_px};
		drag_ranges.whole_envelope={x1:from_px, x2: to_px};
		drag_ranges.envelope_on_screen=true;
		scale_ctx.beginPath();
		scale_ctx.moveTo(from_px,env_h1);
		scale_ctx.lineTo(from_px+env_bounding_line_w, env_h1);
		scale_ctx.lineTo(from_px+env_bounding_line_w+env_att_w, env_h2);
		scale_ctx.lineTo(to_px-env_bounding_line_w-env_att_w, env_h2);
		scale_ctx.lineTo(to_px-env_bounding_line_w, env_h1);
		scale_ctx.lineTo(to_px, env_h1);
		scale_ctx.globalAlpha = 0.3;
		scale_ctx.fill();
		scale_ctx.globalAlpha = 1;
		scale_ctx.stroke();
	}
	if(typeof line != "undefined") // out of screen?
	{
		line_px=scale_px_from_freq(line,range);
		if(!(line_px<0||line_px>window.innerWidth))
		{
			drag_ranges.line={x1:line_px-env_line_click_area/2, x2: line_px+env_line_click_area/2};
			drag_ranges.line_on_screen=true;
			scale_ctx.moveTo(line_px,env_h1+env_lineplus);
			scale_ctx.lineTo(line_px,env_h2-env_lineplus);
			scale_ctx.stroke();
		}
	}
	return drag_ranges;
}

function demod_envelope_where_clicked(x, drag_ranges, key_modifiers)
{  // Check exactly what the user has clicked based on ranges returned by demod_envelope_draw().
	in_range=function(x,range) { return range.x1<=x&&range.x2>=x; }
	dr=demodulator.draggable_ranges;

	if(key_modifiers.shiftKey)
	{
		//Check first: shift + center drag emulates BFO knob
		if(drag_ranges.line_on_screen&&in_range(x,drag_ranges.line)) return dr.bfo;
		//Check second: shift + envelope drag emulates PBF knob
		if(drag_ranges.envelope_on_screen&&in_range(x,drag_ranges.whole_envelope)) return dr.pbs;
	}
	if(drag_ranges.envelope_on_screen)
	{
		// For low and high cut:
		if(in_range(x,drag_ranges.beginning)) return dr.beginning;
		if(in_range(x,drag_ranges.ending)) return dr.ending;
		// Last priority: having clicked anything else on the envelope, without holding the shift key
		if(in_range(x,drag_ranges.whole_envelope)) return dr.anything_else;
	}
	return dr.none; //User doesn't drag the envelope for this demodulator
}

//******* class demodulator *******
// this can be used as a base class for ANY demodulator
demodulator=function(offset_frequency)
{
	//console.log("this too");
	this.offset_frequency=offset_frequency;
	this.has_audio_output=true;
	this.has_text_output=false;
	this.envelope={};
	this.color=demodulators_get_next_color();
	this.stop=function(){};
}
//ranges on filter envelope that can be dragged:
demodulator.draggable_ranges={none: 0, beginning:1 /*from*/, ending: 2 /*to*/, anything_else: 3, bfo: 4 /*line (while holding shift)*/, pbs: 5 } //to which parameter these correspond in demod_envelope_draw()

//******* class demodulator_default_analog *******
// This can be used as a base for basic audio demodulators.
// It already supports most basic modulations used for ham radio and commercial services: AM/FM/LSB/USB

demodulator_response_time=50;
//in ms; if we don't limit the number of SETs sent to the server, audio will underrun (possibly output buffer is cleared on SETs in GNU Radio

function demodulator_default_analog(offset_frequency,subtype)
{
	//console.log("hopefully this happens");
	//http://stackoverflow.com/questions/4152931/javascript-inheritance-call-super-constructor-or-use-prototype-chain
	demodulator.call(this,offset_frequency);
	this.subtype=subtype;
	this.filter={
		min_passband: 100,
		high_cut_limit: (audio_server_output_rate/2)-1, //audio_context.sampleRate/2,
		low_cut_limit: (-audio_server_output_rate/2)+1 //-audio_context.sampleRate/2
	};
	//Subtypes only define some filter parameters and the mod string sent to server,
	//so you may set these parameters in your custom child class.
	//Why? As of demodulation is done on the server, difference is mainly on the server side.
	this.server_mod=subtype;
	if(subtype=="lsb")
	{
		this.low_cut=-3000;
		this.high_cut=-300;
		this.server_mod="ssb";
	}
	else if(subtype=="usb")
	{
		this.low_cut=300;
		this.high_cut=3000;
		this.server_mod="ssb";
	}
	else if(subtype=="cw")
	{
		this.low_cut=700;
		this.high_cut=900;
		this.server_mod="ssb";
	}
	else if(subtype=="nfm")
	{
		this.low_cut=-4000;
		this.high_cut=4000;
	}
	else if(subtype=="am")
	{
		this.low_cut=-4000;
		this.high_cut=4000;
	}

	this.wait_for_timer=false;
	this.set_after=false;
	this.set=function()
	{ //set() is a wrapper to call doset(), but it ensures that doset won't execute more frequently than demodulator_response_time.
		if(!this.wait_for_timer)
		{
			this.doset(false);
			this.set_after=false;
			this.wait_for_timer=true;
			timeout_this=this; //http://stackoverflow.com/a/2130411
			window.setTimeout(function() {
				timeout_this.wait_for_timer=false;
				if(timeout_this.set_after) timeout_this.set();
			},demodulator_response_time);
		}
		else
		{
			this.set_after=true;
		}
	}

	this.doset=function(first_time)
	{  //this function sends demodulator parameters to the server
		ws.send("SET"+((first_time)?" mod="+this.server_mod:"")+
			" low_cut="+this.low_cut.toString()+" high_cut="+this.high_cut.toString()+
			" offset_freq="+this.offset_frequency.toString());
	}
//	this.doset(true); //we set parameters on object creation

	//******* envelope object *******
   // for drawing the filter envelope above scale
	this.envelope.parent=this;

	this.envelope.draw=function(visible_range)
	{
		this.visible_range=visible_range;
		this.drag_ranges=demod_envelope_draw(range,
				center_freq+this.parent.offset_frequency+this.parent.low_cut,
				center_freq+this.parent.offset_frequency+this.parent.high_cut,
				this.color,center_freq+this.parent.offset_frequency);
	};

	// event handlers
	this.envelope.drag_start=function(x, key_modifiers)
	{
		this.key_modifiers=key_modifiers;
		this.dragged_range=demod_envelope_where_clicked(x,this.drag_ranges, key_modifiers);
		//console.log("dragged_range: "+this.dragged_range.toString());
		this.drag_origin={
			x: x,
			low_cut: this.parent.low_cut,
			high_cut: this.parent.high_cut,
			offset_frequency: this.parent.offset_frequency
		};
		return this.dragged_range!=demodulator.draggable_ranges.none;
	};

	this.envelope.drag_move=function(x)
	{
		dr=demodulator.draggable_ranges;
		if(this.dragged_range==dr.none) return false; // we return if user is not dragging (us) at all
		freq_change=Math.round(this.visible_range.hps*(x-this.drag_origin.x));
		/*if(this.dragged_range==dr.beginning||this.dragged_range==dr.ending)
		{
			//we don't let the passband be too small
			if(this.parent.low_cut+new_freq_change<=this.parent.high_cut-this.parent.filter.min_passband) this.freq_change=new_freq_change;
			else return;
		}
		var new_value;*/

		//dragging the line in the middle of the filter envelope while holding Shift does emulate
		//the BFO knob on radio equipment: moving offset frequency, while passband remains unchanged
		//Filter passband moves in the opposite direction than dragged, hence the minus below.
		minus=(this.dragged_range==dr.bfo)?-1:1;
		//dragging any other parts of the filter envelope while holding Shift does emulate the PBS knob
		//(PassBand Shift) on radio equipment: PBS does move the whole passband without moving the offset
		//frequency.
		if(this.dragged_range==dr.beginning||this.dragged_range==dr.bfo||this.dragged_range==dr.pbs)
		{
			//we don't let low_cut go beyond its limits
			if((new_value=this.drag_origin.low_cut+minus*freq_change)<this.parent.filter.low_cut_limit) return true;
			//nor the filter passband be too small
			if(this.parent.high_cut-new_value<this.parent.filter.min_passband) return true;
			//sanity check to prevent GNU Radio "firdes check failed: fa <= fb"
			if(new_value>=this.parent.high_cut) return true;
			this.parent.low_cut=new_value;
		}
		if(this.dragged_range==dr.ending||this.dragged_range==dr.bfo||this.dragged_range==dr.pbs)
		{
			//we don't let high_cut go beyond its limits
			if((new_value=this.drag_origin.high_cut+minus*freq_change)>this.parent.filter.high_cut_limit) return true;
			//nor the filter passband be too small
			if(new_value-this.parent.low_cut<this.parent.filter.min_passband) return true;
			//sanity check to prevent GNU Radio "firdes check failed: fa <= fb"
			if(new_value<=this.parent.low_cut) return true;
			this.parent.high_cut=new_value;
		}
		if(this.dragged_range==dr.anything_else||this.dragged_range==dr.bfo)
		{
			//when any other part of the envelope is dragged, the offset frequency is changed (whole passband also moves with it)
			new_value=this.drag_origin.offset_frequency+freq_change;
			if(new_value>bandwidth/2||new_value<-bandwidth/2) return true; //we don't allow tuning above Nyquist frequency :-)
			this.parent.offset_frequency=new_value;
		}
		//now do the actual modifications:
		mkenvelopes(this.visible_range);
		this.parent.set();
		//will have to change this when changing to multi-demodulator mode:
		e("webrx-actual-freq").innerHTML=format_frequency("{x} MHz",center_freq+this.parent.offset_frequency,1e6,4);
		return true;
	};

	this.envelope.drag_end=function(x)
	{ //in this demodulator we've already changed values in the drag_move() function so we shouldn't do too much here.
		to_return=this.dragged_range!=demodulator.draggable_ranges.none; //this part is required for cliking anywhere on the scale to set offset
		this.dragged_range=demodulator.draggable_ranges.none;
		return to_return;
	};

}

demodulator_default_analog.prototype=new demodulator();

function mkenvelopes(visible_range) //called from mkscale
{
	scale_ctx.clearRect(0,0,scale_ctx.canvas.width,22); //clear the upper part of the canvas (where filter envelopes reside)
	for (var i=0;i<demodulators.length;i++)
	{
		demodulators[i].envelope.draw(visible_range);
	}
}

function demodulator_remove(which)
{
	demodulators[which].stop();
	demodulators.splice(which,1);
}

function demodulator_add(what)
{
	demodulators.push(what);
	mkenvelopes(get_visible_freq_range());
}

function demodulator_analog_replace(subtype)
{ //this function should only exist until the multi-demodulator capability is added
	var temp_offset=0;
	if(demodulators.length)
	{
		temp_offset=demodulators[0].offset_frequency;
		demodulator_remove(0);
	}
	demodulator_add(new demodulator_default_analog(temp_offset,subtype));
}

function demodulator_set_offset_frequency(which,to_what)
{
	if(to_what>bandwidth/2||to_what<-bandwidth/2) return;
	demodulators[0].offset_frequency=Math.round(to_what);
	demodulators[0].set();
	mkenvelopes(get_visible_freq_range());
}


// ========================================================
// ===================  SCALE ROUTINES  ===================
// ========================================================

var scale_ctx, band_ctx;
var scale_canvas, band_canvas;

function scale_setup()
{
//	e("webrx-actual-freq").innerHTML=format_frequency("{x} MHz",canvas_get_frequency(window.innerWidth/2),1e6,4);
	e("webrx-actual-freq").innerHTML=format_frequency("{x} MHz",center_freq,1e6,4);
	scale_canvas=e("openwebrx-scale-canvas");
	scale_ctx=scale_canvas.getContext("2d");
	scale_canvas.addEventListener("mousedown", scale_canvas_mousedown, false);
	scale_canvas.addEventListener("mousemove", scale_canvas_mousemove, false);
	scale_canvas.addEventListener("mouseup", scale_canvas_mouseup, false);
	
	band_canvas = e("id-band-canvas");	
	band_ctx = band_canvas.getContext("2d");
	bands_init();
	mk_bands_scale();
//	add_canvas_listner(band_canvas);
		
	resize_scale();
}
var zoom_nom = 0, zoom_old_nom = 0;

function bands_init()
{
	var i, z;

//	var bi = band_info();

	for (i=0; i < bands.length; i++) {
		var b = bands[i];
		bands[i].chan = (typeof b.chan == "undefined")? 0 : b.chan;
		b.min -= b.chan/2; b.max += b.chan/2;
		
		// fix LW/NDB/MW band definitions based on ITU region and MW channel spacing configuration settings
/*		if (b.name == 'LW') {
			b.min = bi.LW_lo; b.max = bi.NDB_lo; b.chan = 9;
		}
		if (b.name == 'NDB') {
			b.min = bi.NDB_lo; b.max = bi.NDB_hi; b.chan = 0;
		}
		if (b.name == 'MW') {
			b.min = bi.NDB_hi; b.max = bi.MW_hi; b.chan = bi._9_10;
		}
*/		
		b.min *= 1000; b.max *= 1000; b.chan *= 1000;
		var bw = b.max - b.min;
		for (z=zoom_nom; z >= 0; z--) {
			if (bw <= bandwidth / (1 << z))
				break;
		}
		bands[i].zoom_level = z;
		bands[i].cf = b.min + (b.max - b.min)/2;
		bands[i].longName = b.name +' '+ b.s.name;
		//console.log("BAND "+b.name+" bw="+bw+" z="+z);
	}

	mkscale();
}
 
band_canvas_h = 30;
band_canvas_top = 0;
	band_scale_h = 20;
	band_scale_top = 5;
		band_scale_text_top = 5;

dx_container_h = 80;
dx_container_top = band_canvas_h;
	dx_label_top = 5;
	dx_line_h = dx_container_h - dx_label_top;

scale_canvas_h = 47;
scale_canvas_top = band_canvas_h + dx_container_h;
	
scale_container_h = band_canvas_h + dx_container_h + scale_canvas_h;

 
function mk_bands_scale() {
	var r = get_visible_freq_range();
	
	// band bars & station labels
	var tw = band_ctx.canvas.width;
	var i, x, y=band_scale_top, w, h=band_scale_h, ty=y+band_scale_text_top;
	//console.log("BB fftw="+wf_fft_size+" tw="+tw+" rs="+r.start+" re="+r.end+" bw="+(r.end-r.start));
	//console.log("BB pixS="+scale_px_from_freq(r.start, g_range)+" pixE="+scale_px_from_freq(r.end, g_range));
	band_ctx.globalAlpha = 1;
	band_ctx.fillStyle = "White";
	band_ctx.fillRect(0,band_canvas_top,tw,band_canvas_h);

	for (i=0; i < bands.length; i++) {
		var b = bands[i];
		if (b.region != "-" && b.region != "*" && b.region.charAt(0) != '>') continue;

		var x1=0, x2;
		var min_inside = (b.min >= r.start && b.min <= r.end)? 1:0;
		var max_inside = (b.max >= r.start && b.max <= r.end)? 1:0;
		if (min_inside && max_inside) { x1 = b.min; x2 = b.max; } else
		if (!min_inside && max_inside) { x1 = r.start; x2 = b.max; } else
		if (min_inside && !max_inside) { x1 = b.min; x2 = r.end; } else
		if (b.min < r.start && b.max > r.end) { x1 = r.start; x2 = r.end; }

		if (x1) {
			x = scale_px_from_freq(x1, r); var xx = scale_px_from_freq(x2, r);
			w = xx - x;
			//console.log("BANDS x="+x1+'/'+x+" y="+x2+'/'+xx+" w="+w);
			if (w >= 3) {
				band_ctx.fillStyle = b.s.color;
				band_ctx.globalAlpha = 0.2;
				//console.log("BB x="+x+" y="+y+" w="+w+" h="+h);
				band_ctx.fillRect(x,y,w,h);
				band_ctx.globalAlpha = 1;

				//band_ctx.fillStyle = "Black";
				band_ctx.font = "bold 11px sans-serif";
				band_ctx.textBaseline = "top";
				var tx = x + w/2;
				var txt = b.longName;
				var mt = band_ctx.measureText(txt);
				//console.log("BB mt="+mt.width+" txt="+txt);
				if (w >= mt.width+4) {
					;
				} else {
					txt = b.name;
					mt = band_ctx.measureText(txt);
					//console.log("BB mt="+mt.width+" txt="+txt);
					if (w >= mt.width+4) {
						;
					} else {
						txt = null;
					}
				}
				//if (txt) console.log("BANDS tx="+(tx - mt.width/2)+" ty="+ty+" mt="+mt.width+" txt="+txt);
				if (txt) band_ctx.fillText(txt, tx - mt.width/2, ty);
			}
		}
	}
}

var scale_canvas_drag_params={
	mouse_down: false,
	drag: false,
	start_x: 0,
	key_modifiers: {shiftKey:false, altKey: false, ctrlKey: false}
};

function scale_canvas_mousedown(evt)
{
	with(scale_canvas_drag_params)
	{
		mouse_down=true;
		drag=false;
		start_x=evt.pageX;
		key_modifiers.shiftKey=evt.shiftKey;
		key_modifiers.altKey=evt.altKey;
		key_modifiers.ctrlKey=evt.ctrlKey;
	}
	evt.preventDefault();
}

function scale_offset_freq_from_px(x, visible_range)
{
	if(typeof visible_range === "undefined") visible_range=get_visible_freq_range();
	return (visible_range.start+visible_range.bw*(x/canvas_container.clientWidth))-center_freq;
}

function scale_canvas_mousemove(evt) {
	var event_handled;
	if(scale_canvas_drag_params.mouse_down&&!scale_canvas_drag_params.drag&&Math.abs(evt.pageX-scale_canvas_drag_params.start_x)>canvas_drag_min_delta)	{
	//we can use the main drag_min_delta thing of the main canvas
		scale_canvas_drag_params.drag=true;
		//call the drag_start for all demodulators (and they will decide if they're dragged, based on X coordinate)
		for (var i=0;i<demodulators.length;i++) event_handled|=demodulators[i].envelope.drag_start(evt.pageX,scale_canvas_drag_params.key_modifiers);
		scale_canvas.style.cursor="move";
	}
	else if(scale_canvas_drag_params.drag)
	{
		//call the drag_move for all demodulators (and they will decide if they're dragged)
		for (var i=0;i<demodulators.length;i++) event_handled|=demodulators[i].envelope.drag_move(evt.pageX);
		if (!event_handled) demodulator_set_offset_frequency(0,scale_offset_freq_from_px(evt.pageX));
	}
}

function scale_canvas_end_drag(x)
{
	canvas_container.style.cursor="default";
	scale_canvas_drag_params.drag=false;
	scale_canvas_drag_params.mouse_down=false;
	var event_handled=false;
	for (var i=0;i<demodulators.length;i++) event_handled|=demodulators[i].envelope.drag_end(x);
	//console.log(event_handled);
	if (!event_handled) demodulator_set_offset_frequency(0,scale_offset_freq_from_px(x));
}

function scale_canvas_mouseup(evt)
{
	scale_canvas_end_drag(evt.pageX);
}

function scale_px_from_freq(f,range) { return Math.round(((f-range.start)/range.bw)*canvas_container.clientWidth); }

function get_visible_freq_range()
{
	out={};
	if(wf_display) {
		out.start=left*bandwidth;
		out.end=out.start+bandwidth/Math.pow(2,zoom_level);
		out.center=(out.end+out.start)/2;
		out.bw=out.end-out.start;
		out.hps=out.bw/cc.clientWidth;
		return(out);
	}
	fcalc=function(x) { 
		var canvas = canvases[0];
		return Math.round(((-zoom_offset_px+x)/canvas.clientWidth)*bandwidth)+(center_freq-bandwidth/2); }
	out.start=fcalc(0);
	out.center=fcalc(canvas_container.clientWidth/2);
	out.end=fcalc(canvas_container.clientWidth);
	out.bw=out.end-out.start;
	out.hps=out.bw/canvas_container.clientWidth;
	console.log(out);
	return out;
}

var scale_markers_levels=[
	{
		"large_marker_per_hz":10000000, //large
		"estimated_text_width":70,
		"format":"{x} MHz",
		"pre_divide":1000000,
		"decimals":0
	},
	{
		"large_marker_per_hz":5000000,
		"estimated_text_width":70,
		"format":"{x} MHz",
		"pre_divide":1000000,
		"decimals":0
	},
	{
		"large_marker_per_hz":1000000,
		"estimated_text_width":70,
		"format":"{x} MHz",
		"pre_divide":1000000,
		"decimals":0
	},
	{
		"large_marker_per_hz":500000,
		"estimated_text_width":70,
		"format":"{x} MHz",
		"pre_divide":1000000,
		"decimals":1
	},
	{
		"large_marker_per_hz":100000,
		"estimated_text_width":70,
		"format":"{x} MHz",
		"pre_divide":1000000,
		"decimals":1
	},
	{
		"large_marker_per_hz":50000,
		"estimated_text_width":70,
		"format":"{x} MHz",
		"pre_divide":1000000,
		"decimals":2
	},
	{
		"large_marker_per_hz":10000,
		"estimated_text_width":70,
		"format":"{x} MHz",
		"pre_divide":1000000,
		"decimals":2
	},
	{
		"large_marker_per_hz":5000,
		"estimated_text_width":70,
		"format":"{x} MHz",
		"pre_divide":1000000,
		"decimals":3
	},
	{
		"large_marker_per_hz":1000,
		"estimated_text_width":70,
		"format":"{x} MHz",
		"pre_divide":1000000,
		"decimals":1
	}
];
var scale_min_space_bw_texts=50;
var scale_min_space_bw_small_markers=7;

function get_scale_mark_spacing(range)
{
	out={};
	fcalc=function(freq)
	{
		out.numlarge=(range.bw/freq);
		out.large=canvas_container.clientWidth/out.numlarge; 	//distance between large markers (these have text)
		out.ratio=5; 														//(ratio-1) small markers exist per large marker
		out.small=out.large/out.ratio; 								//distance between small markers
		if(out.small<scale_min_space_bw_small_markers) return false;
		if(out.small/2>=scale_min_space_bw_small_markers&&freq.toString()[0]!="5") {out.small/=2; out.ratio*=2; }
		out.smallbw=freq/out.ratio;
		return true;
	}
	for(i=scale_markers_levels.length-1;i>=0;i--)
	{
		mp=scale_markers_levels[i];
		if (!fcalc(mp.large_marker_per_hz)) continue;
		//console.log(mp.large_marker_per_hz);
		//console.log(out);
		if (out.large-mp.estimated_text_width>scale_min_space_bw_texts) break;
	}
	out.params=mp;
	return out;
}

function mkscale()
{
	//clear the lower part of the canvas (where frequency scale resides; the upper part is used by filter envelopes):
	range=get_visible_freq_range();
	mkenvelopes(range); //when scale changes we will always have to redraw filter envelopes, too
	scale_ctx.clearRect(0,22,scale_ctx.canvas.width,scale_ctx.canvas.height-22);
	scale_ctx.strokeStyle = "#fff";
	scale_ctx.font = "bold 11px sans-serif";
	scale_ctx.textBaseline = "top";
	scale_ctx.fillStyle = "#fff";
	spacing=get_scale_mark_spacing(range);
	//console.log(spacing);
	marker_hz=Math.ceil(range.start/spacing.smallbw)*spacing.smallbw;
	text_h_pos=22+10+((is_firefox)?3:0);
	var text_to_draw;
	var ftext=function(f) {text_to_draw=format_frequency(spacing.params.format,f,spacing.params.pre_divide,spacing.params.decimals);}
	var last_large;
	for(;;)
	{
		var x=scale_px_from_freq(marker_hz,range);
		if(x>window.innerWidth) break;
		scale_ctx.beginPath();
		scale_ctx.moveTo(x, 22);
		if(marker_hz%spacing.params.large_marker_per_hz==0)
		{  //large marker
			if(typeof first_large == "undefined") var first_large=marker_hz;
			last_large=marker_hz;
			scale_ctx.lineWidth=3.5;
			scale_ctx.lineTo(x,22+11);
			ftext(marker_hz);
			var text_measured=scale_ctx.measureText(text_to_draw);
			scale_ctx.textAlign = "center";
			//advanced text drawing begins
			if( zoom_level==0 && (range.start+spacing.smallbw*spacing.ratio>marker_hz) && (x<text_measured.width/2) )
			{ //if this is the first overall marker when zoomed out...                  and if it would be clipped off the screen...
				if(scale_px_from_freq(marker_hz+spacing.smallbw*spacing.ratio,range)-text_measured.width>=scale_min_space_bw_texts)
				{ //and if we have enough space to draw it correctly without clipping
					scale_ctx.textAlign = "left";
					scale_ctx.fillText(text_to_draw, 0, text_h_pos);
				}
			}
			else if( zoom_level==0 && (range.end-spacing.smallbw*spacing.ratio<marker_hz) && (x>window.innerWidth-text_measured.width/2) )
			{ //     if this is the last overall marker when zoomed out...                 and if it would be clipped off the screen...
				if(window.innerWidth-text_measured.width-scale_px_from_freq(marker_hz-spacing.smallbw*spacing.ratio,range)>=scale_min_space_bw_texts)
				{ //and if we have enough space to draw it correctly without clipping
					scale_ctx.textAlign = "right";
					scale_ctx.fillText(text_to_draw, window.innerWidth, text_h_pos);
				}
			}
			else scale_ctx.fillText(text_to_draw, x, text_h_pos); //draw text normally
		}
		else
		{  //small marker
			scale_ctx.lineWidth=2;
			scale_ctx.lineTo(x,22+8);
		}
		marker_hz+=spacing.smallbw;
		scale_ctx.stroke();
	}
	if(zoom_level!=0)
	{ // if zoomed, we don't want the texts to disappear because their markers can't be seen
		// on the left side
		scale_ctx.textAlign = "center";
		var f=first_large-spacing.smallbw*spacing.ratio;
		var x=scale_px_from_freq(f,range);
		ftext(f);
		var w=scale_ctx.measureText(text_to_draw).width;
		if(x+w/2>0) scale_ctx.fillText(text_to_draw, x, 22+10);
		// on the right side
		f=last_large+spacing.smallbw*spacing.ratio;
		x=scale_px_from_freq(f,range);
		ftext(f);
		w=scale_ctx.measureText(text_to_draw).width;
		if(x-w/2<window.innerWidth) scale_ctx.fillText(text_to_draw, x, 22+10);
	}
	mk_bands_scale();
}

function resize_scale()
{
	scale_ctx.canvas.width  = window.innerWidth;
	scale_ctx.canvas.height = 47;
	mkscale();
}

function canvas_mouseover(evt)
{
	if(!waterfall_setup_done) return;
	//e("webrx-freq-show").style.visibility="visible";
}

function canvas_mouseout(evt)
{
	if(!waterfall_setup_done) return;
	//e("webrx-freq-show").style.visibility="hidden";
}

function canvas_get_freq_offset(relativeX) {
	if(wf_display) {
//		rel=(relativeX/canvases[0].clientWidth);
		rel=(relativeX/c.offsetWidth);
		var f = left*bandwidth + rel * bandwidth/Math.pow(2,zoom_level);
	return Math.round((f -(bandwidth/2))/10)*10;
		
		
	}
	rel=(relativeX/canvases[0].clientWidth);
	return Math.round((bandwidth*rel)-(bandwidth/2));
}

function canvas_get_frequency(relativeX)
{
//	return center_freq+canvas_get_freq_offset(relativeX);
	return Math.round((center_freq+canvas_get_freq_offset(relativeX))/10)*10;
}

function format_frequency(format, freq_hz, pre_divide, decimals)
{
	out=format.replace("{x}",(freq_hz/pre_divide).toFixed(decimals));
	at=out.indexOf(".")+4;
	while(decimals>3)
	{
		out=out.substr(0,at)+","+out.substr(at);
		at+=4;
		decimals-=3;
	}
	return out;
}

canvas_drag=false;
canvas_drag_min_delta=1;
canvas_mouse_down=false;

function canvas_mousedown(evt)
{
	canvas_mouse_down=true;
	canvas_drag=false;
	canvas_drag_last_x=canvas_drag_start_x=evt.pageX;
	canvas_drag_last_y=canvas_drag_start_y=evt.pageY;
	evt.preventDefault(); //don't show text selection mouse pointer
}

function canvas_mousemove(evt) {
	if(!waterfall_setup_done) return;
	relativeX=(evt.offsetX)?evt.offsetX:evt.layerX;
	if(canvas_mouse_down) {
		if(!canvas_drag&&Math.abs(evt.pageX-canvas_drag_start_x)>canvas_drag_min_delta) {
			canvas_drag=true;
			canvas_container.style.cursor="move";
		}
		if(canvas_drag) {
			var deltaX=canvas_drag_last_x-evt.pageX;
			var deltaY=canvas_drag_last_y-evt.pageY;
			//zoom_center_where=zoom_center_where_calc(evt.pageX);
			var dpx=range.hps*deltaX;
			if(
				!(zoom_center_rel+dpx>(bandwidth/2-canvas_container.clientWidth*(1-zoom_center_where)*range.hps)) &&
				!(zoom_center_rel+dpx<-bandwidth/2+canvas_container.clientWidth*zoom_center_where*range.hps)
			) { zoom_center_rel+=dpx; }
//			-((canvases_new_width*(0.5+zoom_center_rel/bandwidth))-(winsize*zoom_center_where));
			resize_canvases(false);
			canvas_drag_last_x=evt.pageX;
			canvas_drag_last_y=evt.pageY;
			mkscale();
		}
	}
	else e("webrx-mouse-freq").innerHTML=format_frequency("{x} MHz",canvas_get_frequency(relativeX),1e6,4);
}

function canvas_container_mouseout(evt) {
	canvas_end_drag();
}

//function body_mouseup() { canvas_end_drag(); console.log("body_mouseup"); }
//function window_mouseout() { canvas_end_drag(); console.log("document_mouseout"); }

function canvas_mouseup(evt) {
	if(!waterfall_setup_done) return;
		// if(window_mouseout){
		// window_mouseout = false;
		// return;
		// }
	relativeX=(evt.offsetX)?evt.offsetX:evt.layerX;

	if(!canvas_drag) {
		//ws.send("SET offset_freq="+canvas_get_freq_offset(relativeX).toString());
		demodulator_set_offset_frequency(0, canvas_get_freq_offset(relativeX));
		e("webrx-actual-freq").innerHTML=format_frequency("{x} MHz",canvas_get_frequency(relativeX),1e6,6);
	}
	else {
		canvas_end_drag();
	}
	canvas_mouse_down=false;
}

function canvas_end_drag() {
	canvas_container.style.cursor="crosshair";
	canvas_mouse_down=false;
}

function zoom_center_where_calc(screenposX) {
	//return (screenposX-(window.innerWidth-canvas_container.clientWidth))/canvas_container.clientWidth;
	return screenposX/canvas_container.clientWidth;
}

function canvas_mousewheel(evt)
{
	if(!waterfall_setup_done) return;
	//var i=Math.abs(evt.wheelDelta);
	//var dir=(i/evt.wheelDelta)<0;
	//console.log(evt);
	var relativeX=(evt.offsetX)?evt.offsetX:evt.layerX;
	var dir=(evt.deltaY/Math.abs(evt.deltaY))>0;
	//console.log(dir);
	//i/=120;
	/*while (i--)*/ zoom_step(dir, relativeX, zoom_center_where_calc(evt.pageX));
	evt.preventDefault();
	//evt.returnValue = false; //disable scrollbar move
}


zoom_max_level_hps=33; //Hz/pixel
zoom_levels_count=14;

function get_zoom_coeff_from_hps(hps)
{
	var shown_bw=(window.innerWidth*hps);
	return bandwidth/shown_bw;
}

zoom_levels=[1];
zoom_level=0;
zoom_freq=0;
zoom_offset_px=0;
zoom_center_rel=0;
zoom_center_where=0;

smeter_level=0;

function mkzoomlevels()
{
	zoom_levels=[1];
	maxc=get_zoom_coeff_from_hps(zoom_max_level_hps);
	if(maxc<1) return;
	// logarithmic interpolation
	zoom_ratio = Math.pow(maxc, 1/zoom_levels_count);
	for(i=1;i<zoom_levels_count;i++)
		zoom_levels.push(Math.pow(zoom_ratio, i));
}

function zoom_step(out, where, onscreen)
{
	if((out&&zoom_level==0)||(!out&&zoom_level>=zoom_levels_count-1)) return;
	if(out) --zoom_level;
	else ++zoom_level;

	zoom_center_rel=canvas_get_freq_offset(where);
	//console.log("zoom_step || zlevel: "+zoom_level.toString()+" zlevel_val: "+zoom_levels[zoom_level].toString()+" zoom_center_rel: "+zoom_center_rel.toString());
	zoom_center_where=onscreen;
	console.log(zoom_center_where, zoom_center_rel, where,zoom_level);
	resize_canvases(true);
	mkscale();
}

function zoom_set(level)
{
	if(!(level>=0&&level<=zoom_levels.length-1)) return;
	level=parseInt(level);
	zoom_level = level;
	//zoom_center_rel=canvas_get_freq_offset(-canvases[0].offsetLeft+canvas_container.clientWidth/2); //zoom to screen center instead of demod envelope
	zoom_center_rel=demodulators[0].offset_frequency;
	zoom_center_where=0.5+(zoom_center_rel/bandwidth); //this is a kind of hack
	console.log(zoom_center_where, zoom_center_rel, -canvases[0].offsetLeft+canvas_container.clientWidth/2);
	resize_canvases(true);
	mkscale();
}

function zoom_calc() {
	winsize=canvas_container.clientWidth;
	var canvases_new_width=winsize*zoom_levels[zoom_level];
	zoom_offset_px=-((canvases_new_width*(0.5+zoom_center_rel/bandwidth))-(winsize*zoom_center_where));
	if(zoom_offset_px>0) zoom_offset_px=0;
	if(zoom_offset_px<winsize-canvases_new_width)
		zoom_offset_px=winsize-canvases_new_width;
	//console.log("zoom_calc || zopx:"+zoom_offset_px.toString()+ " maxoff:"+(winsize-canvases_new_width).toString()+" relval:"+(0.5+zoom_center_rel/bandwidth).toString() );
}

function resize_waterfall_container(check_init) {
	if(check_init&&!waterfall_setup_done) return;
	canvas_container.style.height=(window.innerHeight-e("webrx-top-container").clientHeight-e("openwebrx-scale-container").clientHeight).toString()+"px";
}

debug_ws_data_received=0;
max_clients_num=0;

var COMPRESS_FFT_PAD_N=10; //should be the same as in csdr.c

function on_ws_recv(evt) {
		var s=arrayBufferToString(evt.data);
//	console.log(s);
//	divlog(s);
	if(!(evt.data instanceof ArrayBuffer)) { divlog("on_ws_recv(): Not ArrayBuffer received...",1); return; }
	//
	debug_ws_data_received+=evt.data.byteLength/1000;
	firstChars=getFirstChars(evt.data,3);
	if(firstChars=="CLI") {
		var stringData=arrayBufferToString(evt.data);
		if(stringData.substring(0,16)=="CLIENT DE SERVER") divlog("Acknowledged WebSocket connection: "+stringData);
	}
	if(firstChars=="AUD") {
		var audio_data;
		if(audio_compression=="adpcm") audio_data=new Uint8Array(evt.data,4)
		else audio_data=new Int16Array(evt.data,4);
				// audio_codec.reset();

		audio_prepare(audio_data);
		audio_buffer_current_size_debug+=audio_data.length;
		audio_buffer_all_size_debug+=audio_data.length;
		if(!ios && (audio_initialized==0 && audio_prepared_buffers.length>audio_buffering_fill_to)) audio_init();
	}
	else if(firstChars=="FFT") {
		//alert("Yupee! Doing FFT");
		if(fft_compression=="none") {
			var fftdata = new Float32Array(evt.data,4);
			var x = 5;
			waterfall_add_queue(fftdata);
//			waterfall_add_queue(new Float32Array(evt.data,4));
		} else if(fft_compression=="adpcm") {
			fft_codec.reset();
			var waterfall_i16=fft_codec.decode(new Uint8Array(evt.data,4));
			var waterfall_f32=new Float32Array(waterfall_i16.length-COMPRESS_FFT_PAD_N);
			for(var i=0;i<waterfall_i16.length;i++) waterfall_f32[i]=waterfall_i16[i+COMPRESS_FFT_PAD_N]/100;
			waterfall_add_queue(waterfall_f32);
		} else if(fft_compression=="u8bit") {
			var waterfall_u8 = new Uint8Array(evt.data,4);
			var waterfall_f32=new Float32Array(waterfall_u8.length);
			for(var i=0;i<waterfall_u8.length;i++) waterfall_f32[i]=waterfall_u8[i]-256;
			waterfall_add_queue(waterfall_f32);
		} else if(fft_compression=="u8new") {
			var wf = {zoom_level:0,left:0};
			var zl = new Uint32Array(evt.data,4,1);
			var l = new Float32Array(evt.data,8,1);
			wf.zoom_level = zl[0];
			wf.left = l[0];
//			console.log("wf receivered: " + zl[0] + " " + l[0]);
			waterfall_u8 = new Uint8Array(evt.data,12);
			waterfall_f32=new Float32Array(waterfall_u8.length);
			for(var i=0;i<waterfall_u8.length;i++) waterfall_f32[i]=waterfall_u8[i]-256;
			waterfall_f32.wf = wf;
			waterfall_add_queue(waterfall_f32);
		}
	} else if(firstChars=="MSG") {
			var stringData=arrayBufferToString(evt.data);
			console.log(stringData);
			params=stringData.substring(4).split(" ");
			for(i=0;i<params.length;i++)
			{
				param=params[i].split("=");
				switch(param[0])
				{
					case "setup":
						waterfall_init();
						audio_preinit();
//						setSmeterAbsoluteValue(2);
						break;
					case "overmaxuser":
						divlog("Maximum number of users exceeded. Please try later.");
						break;
					case "bandwidth":
						bandwidth=parseInt(param[1]);
						divlog( "BW = "+ bandwidth+"." )
						break;
					case "center_freq":
						center_freq=parseInt(param[1]); //there was no ; and it was no problem... why?
						break;
					case "fft_size":
						fft_size=parseInt(param[1]);
						break;
					case "fft_fps":
						fft_fps=parseInt(param[1]);
						break;
					case "audio_compression":
						audio_compression=param[1];
						divlog( "Audio stream is "+ ((audio_compression=="adpcm")?"compressed":"uncompressed")+"." )
						break;
					case "fft_compression":
						fft_compression=param[1];
						divlog( "FFT stream compression is "+ fft_compression+"." )
//						divlog( "FFT stream is "+ ((fft_compression=="adpcm")?"compressed":"uncompressed")+"." )
						break;
					case "cpu_usage":
						var server_cpu_usage=parseInt(param[1]);
//						progressbar_set(e("openwebrx-bar-server-cpu"),server_cpu_usage/100,"Server CPU ["+param[1]+"%]",server_cpu_usage>85);
						break;
					case "clients":
						var clients_num=parseInt(param[1]);
						progressbar_set(e("openwebrx-bar-clients"),clients_num/max_clients_num,"Clients "+clients_num+" of "+max_clients_num,clients_num>max_clients_num*1.1);
//						progressbar_set(e("openwebrx-bar-clients"),clients_num/max_clients_num,"Clients ["+param[1]+"]",clients_num>max_clients_num*0.85);
						break;
					case "max_clients":
						max_clients_num=parseInt(param[1]);
						break;
					case "s":
						smeter_level=parseFloat(param[1]);
						setSmeterAbsoluteValue(smeter_level);
						break;
				}
			}
	}
}

function add_problem(what)
{
	problems_span=e("openwebrx-problems");
	for(var i=0;i<problems_span.children.length;i++) if(problems_span.children[i].innerHTML==what) return;
	new_span = document.createElement("span");
	new_span.innerHTML=what;
	problems_span.appendChild(new_span);
	window.setTimeout(function(ps,ns) {  ps.removeChild(ns); }, 1000,problems_span,new_span);
}

waterfall_measure_minmax=false;
waterfall_measure_minmax_now=false;
waterfall_measure_minmax_min= 1e100;
waterfall_measure_minmax_max=-1e100;

function waterfall_measure_minmax_do(what)
{
	waterfall_measure_minmax_min=Math.min(waterfall_measure_minmax_min,Math.min.apply(Math,what));
	waterfall_measure_minmax_max=Math.max(waterfall_measure_minmax_max,Math.max.apply(Math,what));
}

function waterfall_measure_minmax_print()
{
	console.log("Waterfall | min = "+waterfall_measure_minmax_min.toString()+" dB | max = "+waterfall_measure_minmax_max.toString()+" dB");
}

function waterfall_add_queue(what)
{
	if(waterfall_measure_minmax) waterfall_measure_minmax_do(what);
	if(waterfall_measure_minmax_now) { waterfall_measure_minmax_do(what); waterfall_measure_minmax_now=false; waterfallColorsAuto(); }
	waterfall_queue.push(what);
}

function waterfall_dequeue()
{
	if(waterfall_queue.length) waterfall_add(waterfall_queue.shift());
	if(waterfall_queue.length>Math.max(fft_fps/2,20)) //in case of emergency
	{
		console.log("waterfall queue length:", waterfall_queue.length);
		add_problem("fft overflow");
		while(waterfall_queue.length) waterfall_add(waterfall_queue.shift());
	}
}

function on_ws_opened()
{
	ws.send("SERVER DE CLIENT openwebrx.js");
//	divlog("WebSocket opened to "+ws_url);
}

var was_error=0;

function divlog(what, is_error)
{
	is_error=!!is_error;
	was_error |= is_error;
	if(is_error)
	{
		what="<span class=\"webrx-error\">"+what+"</span>";
		if(e("openwebrx-panel-log").openwebrxHidden) toggle_panel("openwebrx-panel-log"); //show panel if any error is present
	}
	e("openwebrx-debugdiv").innerHTML+=what+"<br />";
	var wls=e("openwebrx-log-scroll");
	wls.scrollTop=wls.scrollHeight; //scroll to bottom
}

var audio_context;
var audio_initialized=0;
var volume = 1.0;
var volumeBeforeMute = 100.0;
var mute = false;

var audio_received = Array();
var audio_buffer_index = 0;
var audio_codec=new sdrjs.ImaAdpcm();
var audio_compression="unknown";
var audio_node;
//var audio_received_sample_rate = 48000;
var audio_input_buffer_size;

// Optimalise these if audio lags or is choppy:
var audio_buffer_size;
var audio_buffer_maximal_length_sec=3; //actual number of samples are calculated from sample rate
var audio_buffer_decrease_to_on_overrun_sec=2.2;
var audio_flush_interval_ms=500; //the interval in which audio_flush() is called

var audio_prepared_buffers = Array();
var audio_rebuffer;
var audio_last_output_buffer;
var audio_last_output_offset = 0;
var audio_buffering = false;
//var audio_buffering_fill_to=4; //on audio underrun we wait until this n*audio_buffer_size samples are present
								//tnx to the hint from HA3FLT, now we have about half the response time! (original value: 10)

function gain_ff(gain_value,data) //great! solved clicking! will have to move to sdr.js
{
	for(var i=0;i<data.length;i++)
	data[i]*=gain_value;
	return data;
}

var count = 0, N = 10;
function audio_prepare(data) {

	if(audio_compression=="none") {
		var floatdata = sdrjs.ConvertI16_F(data); 
		var sound = gain_ff(volume,floatdata); 
		audio_rebuffer.push(sound); 
//		audio_rebuffer.push(gain_ff(volume,sdrjs.ConvertI16_F(data)));//resampling without ADPCM
//		audio_rebuffer.push(audio_resampler.process(gain_ff(volume,sdrjs.ConvertI16_F(data))));//resampling without ADPCM
		count = count + 1;
		if(count == N) {
//			console.log(volume);
//			console.log(data);
			count = 0;
		}
	} else if(audio_compression=="adpcm") {
//resampling & ADPCM
		var decode = audio_codec.decode(data); 
		var sound = gain_ff(volume,sdrjs.ConvertI16_F(decode)); 
		count = count + 1;
		if(count == N) {
//			console.log(volume);
//			console.log(decode);
			count = 0;
			}
		audio_rebuffer.push(sound); 
		//audio_rebuffer.push(audio_resampler.process(gain_ff(volume,sdrjs.ConvertI16_F(audio_codec.decode(data))))); //resampling & ADPCM
		}
	else return;

	//console.log("prepare",data.length,audio_rebuffer.remaining());
	while(audio_rebuffer.remaining())
	{
		audio_prepared_buffers.push(audio_rebuffer.take());
		audio_buffer_current_count_debug++;
	}
	if(audio_buffering && audio_prepared_buffers.length>audio_buffering_fill_to) { console.log("buffers now: "+audio_prepared_buffers.length.toString()); audio_buffering=false; }
}


function audio_onprocess(e)
{
	//console.log("audio onprocess");
	if(audio_buffering) return;
	if(audio_prepared_buffers.length==0) { audio_buffer_progressbar_update(); /*add_problem("audio underrun");*/ audio_buffering=true; }
	else { e.outputBuffer.copyToChannel(audio_prepared_buffers.shift(),0); }
}

var audio_buffer_progressbar_update_disabled=false;

var audio_buffer_total_average_level=0;
var audio_buffer_total_average_level_length=0;
var audio_overrun_cnt = 0;
var audio_underrun_cnt = 0;

function audio_buffer_progressbar_update()
{
	if(audio_buffer_progressbar_update_disabled) return;
	var audio_buffer_value=(audio_prepared_buffers.length*audio_buffer_size)/audio_context.sampleRate;
	audio_buffer_total_average_level_length++; audio_buffer_total_average_level=(audio_buffer_total_average_level*((audio_buffer_total_average_level_length-1)/audio_buffer_total_average_level_length))+(audio_buffer_value/audio_buffer_total_average_level_length);
	var overrun=audio_buffer_value>audio_buffer_maximal_length_sec;
	var underrun=audio_prepared_buffers.length==0;
	var text="buffer";
	if(overrun) { text="overrun"; console.log("audio overrun, "+(++audio_overrun_cnt).toString()); }
	if(underrun) { text="underrun"; console.log("audio underrun, "+(++audio_underrun_cnt).toString()); }
	if(overrun||underrun)
	{
		audio_buffer_progressbar_update_disabled=true;
		window.setTimeout(function(){audio_buffer_progressbar_update_disabled=false; audio_buffer_progressbar_update();},1000);
	}
	progressbar_set(e("openwebrx-bar-audio-buffer"),(underrun)?1:audio_buffer_value/1.5,"Audio "+text+" ["+(audio_buffer_value).toFixed(1)+" s]",overrun||underrun||audio_buffer_value<0.25);
}

function audio_flush()
{
	flushed=false;
	we_have_more_than=function(sec){ return sec*audio_context.sampleRate<audio_prepared_buffers.length*audio_buffer_size; }
	if(we_have_more_than(audio_buffer_maximal_length_sec)) while(we_have_more_than(audio_buffer_decrease_to_on_overrun_sec))
	{
		if(!flushed) audio_buffer_progressbar_update();
		flushed=true;
		audio_prepared_buffers.shift();
	}
	//if(flushed) add_problem("audio overrun");
}


function audio_onprocess_notused(e) {
	//https://github.com/0xfe/experiments/blob/master/www/tone/js/sinewave.js
	if(audio_received.length==0)
	{ add_problem("audio underrun"); return; }
	output = e.outputBuffer.getChannelData(0);
	int_buffer = audio_received[0];
	read_remain = audio_buffer_size;
	//audio_buffer_maximal_length=120;

	obi=0; //output buffer index
	debug_str=""
	while(1)
	{
		if(int_buffer.length-audio_buffer_index>read_remain)
		{
			for (i=audio_buffer_index; i<audio_buffer_index+read_remain; i++)
				output[obi++] = int_buffer[i]/32768;
			//debug_str+="added whole ibl="+int_buffer.length.toString()+" abi="+audio_buffer_index.toString()+" "+(int_buffer.length-audio_buffer_index).toString()+">"+read_remain.toString()+" obi="+obi.toString()+"\n";
			audio_buffer_index+=read_remain;
			break;
		}
		else
		{
			for (i=audio_buffer_index; i<int_buffer.length; i++)
				output[obi++] = int_buffer[i]/32768;
			read_remain-=(int_buffer.length-audio_buffer_index);
			audio_buffer_current_size-=audio_received[0].length;
			/*if (audio_received.length>audio_buffer_maximal_length)
			{
				add_problem("audio overrun");
				audio_received.splice(0,audio_received.length-audio_buffer_maximal_length);
			}
			else*/
				audio_received.splice(0,1);
			//debug_str+="added remain, remain="+read_remain.toString()+" abi="+audio_buffer_index.toString()+" alen="+int_buffer.length.toString()+" i="+i.toString()+" arecva="+audio_received.length.toString()+" obi="+obi.toString()+"\n";
			audio_buffer_index = 0;
			if(audio_received.length == 0 || read_remain == 0) return;
			int_buffer = audio_received[0];
		}
	}
	//debug_str+="obi="+obi.toString();
	//alert(debug_str);
}

function audio_flush_notused()
{
	if (audio_buffer_current_size>audio_buffer_maximal_length_sec*audio_context.sampleRate)
	{
		add_problem("audio overrun");
		console.log("audio_flush() :: size: "+audio_buffer_current_size.toString()+" allowed: "+(audio_buffer_maximal_length_sec*audio_context.sampleRate).toString());
		while (audio_buffer_current_size>audio_buffer_maximal_length_sec*audio_context.sampleRate*0.5)
		{
			audio_buffer_current_size-=audio_received[0].length;
			audio_received.splice(0,1);
		}
	}
}

function webrx_set_param(what, value)
{
	ws.send("SET "+what+"="+value.toString());
}

function parsehash()
{
	if(h=window.location.hash)
	{
		h.substring(1).split(",").forEach(function(x){
			harr=x.split("=");
			console.log(harr);
			if(harr[0]=="mod") starting_mod = harr[1];
			if(harr[0]=="sql") { e("openwebrx-panel-squelch").value=harr[1]; updateSquelch(); }
			if(harr[0]=="freq") {
			console.log(parseInt(harr[1]));
			console.log(center_freq);
			starting_offset_frequency = parseInt(harr[1])-center_freq;
			}
		});

	}
}

function audio_preinit() {
	try {
		window.AudioContext = window.AudioContext||window.webkitAudioContext;
		audio_context = new AudioContext();
		//console.log(audio_context);
	} catch(e) {
		divlog('Your browser does not support Web Audio API, which is required for WebRX to run. Please upgrade to a HTML5 compatible browser.', 1);
		return;
	}

	if(audio_context.sampleRate<44100*2)
		audio_buffer_size = 4096;
	else if(audio_context.sampleRate>=44100*2 && audio_context.sampleRate<44100*4)
		audio_buffer_size = 4096 * 2;
	else if(audio_context.sampleRate>=44100*4)
		audio_buffer_size = 4096 * 4;
	console.log("sampleRate = " + audio_context.sampleRate.toString() + "  audio_buffer_size = " + audio_buffer_size.toString());

	audio_rebuffer = new sdrjs.Rebuffer(audio_buffer_size,sdrjs.REBUFFER_FIXED);
	audio_last_output_buffer = new Float32Array(audio_buffer_size);

	//we send our setup packet
	parsehash();

	var sr = audio_context.sampleRate;
	console.log("The audio_preinit sample rate is " + sr);
	if( (sr!=44100) && (sr!=48000)) {
		divlog("Please set your audio sample rate to 44100 or 48000, 16 bits and restart your browser to receive sound.",1);
		return;
		}
		audio_server_output_rate = sr;
	ws.send("SET action=new_radio output_rate="+sr.toString()+ " offset_freq="+starting_offset_frequency.toString()+ " mod="+starting_mod.toString()+" action=start"); //now we'll get AUD packets as well
		ws.send("SET zoom="+zoom_level.toString()+" left="+left.toString());
//	ws.send("SET output_rate="+audio_server_output_rate.toString()+ " action=start"); //now we'll get AUD packets as well
}

function audio_init() {
	if(audio_client_resampling_factor==0) return; //if failed to find a valid resampling factor...

	audio_debug_time_start=(new Date()).getTime();
	audio_debug_time_last_start=audio_debug_time_start;

	//https://github.com/0xfe/experiments/blob/master/www/tone/js/sinewave.js
	audio_initialized=1; // only tell on_ws_recv() not to call it again

	//on Chrome v36, createJavaScriptNode has been replaced by createScriptProcessor
	createjsnode_function = (audio_context.createJavaScriptNode == undefined)?audio_context.createScriptProcessor.bind(audio_context):audio_context.createJavaScriptNode.bind(audio_context);
	audio_node = createjsnode_function(audio_buffer_size, 0, 1);
	audio_node.onaudioprocess = audio_onprocess;
	audio_node.connect(audio_context.destination);
	
//	gain_node = audio_context.createGain();
//	gain_node.connect(audio_context.destination);
//	console.log(gain_node);
//	console.log(gain_node.gain);
//	console.log(gain_node.gain.maxValue);
//	console.log(gain_node.gain.minValue);
//	console.log(gain_node.gain.value);

//	webrx_set_param("audio_rate",audio_context.sampleRate); //Don't try to resample //TODO remove this

	window.setInterval(audio_flush,audio_flush_interval_ms);
	divlog('Web Audio API succesfully initialized, sample rate: '+audio_context.sampleRate.toString()+ " sps");

	demodulator_analog_replace(starting_mod);
	if(starting_offset_frequency)
	{
		demodulators[0].offset_frequency = starting_offset_frequency;
		e("webrx-actual-freq").innerHTML=format_frequency("{x} MHz",center_freq+starting_offset_frequency,1e6,4);
		demodulators[0].set();
		mkscale();
	}
	audio_context.resume();
}

function on_ws_closed() {
	try {
		audio_node.disconnect();
	}
	catch (dont_care) {}
	divlog("WebSocket has closed unexpectedly. Please reload the page.", 1);
}

function on_ws_error(event) {
	console.log("WebSocket error.",1);
	divlog("Please disable adblocker for this site. This site will not work correctly with adblocker on. There are no ads on this site.",1);
//	divlog("WebSocket error.",1);
}

String.prototype.startswith=function(str){ return this.indexOf(str) == 0; }; //http://stackoverflow.com/questions/646628/how-to-check-if-a-string-startswith-another-string

function open_websocket() {
		console.log(ws_url);

	if (!("WebSocket" in window))
		divlog("Your browser does not support WebSocket, which is required for WebRX to run. Please upgrade to a HTML5 compatible browser.");
//	ws = new WebSocket(ws_url+client_id);
	ws = new WebSocket(ws_url);

	ws.onopen = on_ws_opened;
	ws.onmessage = on_ws_recv;
	ws.onclose = on_ws_closed;
	ws.onerror = on_ws_error;
	ws.binaryType = "arraybuffer";
	window.onbeforeunload = function() { //http://stackoverflow.com/questions/4812686/closing-websocket-correctly-html5-javascript
		ws.onclose = function () {};
		ws.close();
	};
	ws.onerror = on_ws_error;
}

function waterfall_mkcolor(db_value) {
	if(db_value<waterfall_min_level) db_value=waterfall_min_level;
	if(db_value>waterfall_max_level) db_value=waterfall_max_level;
	full_scale=waterfall_max_level-waterfall_min_level;
	relative_value=db_value-waterfall_min_level;
	value_percent=relative_value/full_scale;
	percent_for_one_color=1/(waterfall_colors.length-1);
	index=Math.floor(value_percent/percent_for_one_color);
	remain=(value_percent-percent_for_one_color*index)/percent_for_one_color;
	return color_between(waterfall_colors[index+1],waterfall_colors[index],remain);
}

function color_between(first, second, percent) {
	output=0;
	for(i=0;i<4;i++) {
		add = ((((first&(0xff<<(i*8)))>>>0)*percent) + (((second&(0xff<<(i*8)))>>>0)*(1-percent))) & (0xff<<(i*8));
		output |= add>>>0;
	}
	return output>>>0;
}

var canvas_context;
var canvases = [];
var canvas_default_height = 200;
var canvas_container;

function add_canvas() {
	new_canvas = document.createElement("canvas");
	new_canvas.width=fft_size;
	new_canvas.height=canvas_default_height;
	canvas_actual_line=canvas_default_height-1;
	new_canvas.style.width=(canvas_container.clientWidth*zoom_levels[zoom_level]).toString()+"px";
	new_canvas.style.left=zoom_offset_px.toString()+"px";
	new_canvas.style.height=canvas_default_height.toString()+"px";
	new_canvas.openwebrx_top=(-canvas_default_height+1);
	new_canvas.style.top=new_canvas.openwebrx_top.toString()+"px";
	canvas_context = new_canvas.getContext("2d");
	canvas_container.appendChild(new_canvas);
	new_canvas.addEventListener("mouseover", canvas_mouseover, false);
	new_canvas.addEventListener("mouseout", canvas_mouseout, false);
	new_canvas.addEventListener("mousemove", canvas_mousemove, false);
	new_canvas.addEventListener("mouseup", canvas_mouseup, false);
	new_canvas.addEventListener("mousedown", canvas_mousedown, false);
	new_canvas.addEventListener("wheel",canvas_mousewheel, false);
	canvases.push(new_canvas);
}

function init_canvas_container() {
	canvas_container=e("webrx-canvas-container");
	canvas_container.addEventListener("mouseout",canvas_container_mouseout, false);
	add_canvas();
}

canvas_maxshift=0;

function shift_canvases() {
	canvases.forEach(function(p)
	{
		p.style.top=(p.openwebrx_top++).toString()+"px";
	});
	canvas_maxshift++;
}

function resize_canvases(zoom) {
	if(typeof zoom == "undefined") zoom=false;
	if(!zoom) mkzoomlevels();
	zoom_calc();
	new_width=(canvas_container.clientWidth*zoom_levels[zoom_level]).toString()+"px";
	var zoom_value=zoom_offset_px.toString()+"px";
	canvases.forEach(function(p)
	{
		p.style.width=new_width;
		p.style.left=zoom_value;
	});
}

function waterfall_init() {
	init_canvas_container();
	waterfall_timer = window.setInterval(waterfall_dequeue,900/fft_fps);
	resize_waterfall_container(false); /* then */ resize_canvases();
	scale_setup();
	mkzoomlevels();
	waterfall_setup_done=1;
}

var waterfall_dont_scale=0;

function waterfall_add(data) {
	if(!waterfall_setup_done) return;
	if(wf_display) {
		wf_waterfall_add(data);
		return;
		}
	var w=fft_size;

	//Add line to waterfall image
	oneline_image = canvas_context.createImageData(w,1);
	for(x=0;x<w;x++) {
		color=waterfall_mkcolor(data[x]);
		for(i=0;i<4;i++)
			oneline_image.data[x*4+i] = ((color>>>0)>>((3-i)*8))&0xff;
	}
	//Draw image
	canvas_context.putImageData(oneline_image, 0, canvas_actual_line--);
	shift_canvases();
	if(canvas_actual_line<0) add_canvas();
}

function openwebrx_resize() {
	resize_canvases();
	resize_waterfall_container(true);
	resize_scale();
}

function iosPlayButtonClick() {
	//On iOS, we can only start audio from a click or touch event.
	audio_init();
	e("openwebrx-big-grey").style.opacity=0;
	window.setTimeout(function(){ e("openwebrx-big-grey").style.display="none"; },1100);
}

var rt = function (s,n) {return s.replace(/[a-zA-Z]/g,function(c){return String.fromCharCode((c<="Z"?90:122)>=(c=c.charCodeAt(0)+n)?c:c-26);});}
var irt = function (s,n) {return s.replace(/[a-zA-Z]/g,function(c){return String.fromCharCode((c>="a"?97:65)<=(c=c.charCodeAt(0)-n)?c:c+26);});}
var sendmail2 = function (s) { window.location.href="mailto:"+irt(s.replace("=",String.fromCharCode(0100)).replace("$","."),8); }

var audio_debug_time_start=0;
var audio_debug_time_last_start=0;

function debug_audio()
{
	if(audio_debug_time_start==0) return; //audio_init has not been called
	time_now=(new Date()).getTime();
	audio_debug_time_since_last_call=(time_now-audio_debug_time_last_start)/1000;
	audio_debug_time_last_start=time_now; //now
	audio_debug_time_taken=(time_now-audio_debug_time_start)/1000;
	kbps_mult=(audio_compression=="adpcm")?8:16;
	//e("openwebrx-audio-sps").innerHTML=
	//	((audio_compression=="adpcm")?"ADPCM compressed":"uncompressed")+" audio downlink:<br/> "+(audio_buffer_current_size_debug*kbps_mult/audio_debug_time_since_last_call).toFixed(0)+" kbps ("+
	//	(audio_buffer_all_size_debug*kbps_mult/audio_debug_time_taken).toFixed(1)+" kbps avg.), feed at "+
	//	((audio_buffer_current_count_debug*audio_buffer_size)/audio_debug_time_taken).toFixed(1)+" sps output";

	var audio_speed_value=audio_buffer_current_size_debug*kbps_mult/audio_debug_time_since_last_call;
	progressbar_set(e("openwebrx-bar-audio-speed"),audio_speed_value/500000,"Audio stream ["+(audio_speed_value/1000).toFixed(0)+" kbps]",false);

	var audio_output_value=(audio_buffer_current_count_debug*audio_buffer_size)/audio_debug_time_taken;
	progressbar_set(e("openwebrx-bar-audio-output"),audio_output_value/55000,"Audio output ["+(audio_output_value/1000).toFixed(1)+" ksps]",audio_output_value>55000||audio_output_value<10000);

	audio_buffer_progressbar_update();

	var network_speed_value=debug_ws_data_received/audio_debug_time_taken;
	progressbar_set(e("openwebrx-bar-network-speed"),network_speed_value*8/2000,"Network usage ["+(network_speed_value*8).toFixed(1)+" kbps]",false);

	audio_buffer_current_size_debug=0;

	if(waterfall_measure_minmax) waterfall_measure_minmax_print();
}

// ========================================================
// =======================  PANELS  =======================
// ========================================================

panel_margin=5.9;

function pop_bottommost_panel(from)
{
	min_order=parseInt(from[0].dataset.panelOrder);
	min_index=0;
	for(i=0;i<from.length;i++)
	{
		actual_order=parseInt(from[i].dataset.panelOrder);
		if(actual_order<min_order)
		{
			min_index=i;
			min_order=actual_order;
		}
	}
	to_return=from[min_index];
	from.splice(min_index,1);
	return to_return;
}

function toggle_panel(what)
{
	var item=e(what);
	if(item.openwebrxDisableClick) return;
	item.style.transitionDuration="599ms";
	item.style.transitionDelay="0ms";
	if(!item.openwebrxHidden)
	{
		window.setTimeout(function(){item.openwebrxHidden=!item.openwebrxHidden; place_panels(); item.openwebrxDisableClick=false;},700);
		item.style.transform="perspective( 599px ) rotateX( 90deg )";
	}
	else
	{
		item.openwebrxHidden=!item.openwebrxHidden; place_panels();
	    window.setTimeout(function(){ item.openwebrxDisableClick=false;},700);
		item.style.transform="perspective( 599px ) rotateX( 0deg )";
	}
	item.style.transitionDuration="0";

	item.openwebrxDisableClick=true;

}

function first_show_panel(panel)
{
	panel.style.transitionDuration=0;
	panel.style.transitionDelay=0;
	rotx=(Math.random()>0.5)?-90:90;
	roty=0;
	if(Math.random()>0.5)
	{
		rottemp=rotx;
		rotx=roty;
		roty=rottemp;
	}
	if(rotx!=0 && Math.random()>0.5) rotx=270;
	//console.log(rotx,roty);
	transformString = "perspective( 599px ) rotateX( %1deg ) rotateY( %2deg )"
		.replace("%1",rotx.toString()).replace("%2",roty.toString());
	//console.log(transformString);
	//console.log(panel);
	panel.style.transform=transformString;
	window.setTimeout(function() {
		panel.style.transitionDuration="599ms";
		panel.style.transitionDelay=(Math.floor(Math.random()*500)).toString()+"ms";
		panel.style.transform="perspective( 599px ) rotateX( 0deg ) rotateY( 0deg )";
		//panel.style.transitionDuration="0ms";
		//panel.style.transitionDelay="0";
	}, 1);
}

function place_panels(function_apply)
{
	if(function_apply == undefined) function_apply = function(x){};
	var hoffset=0; //added this because the first panel should not have such great gap below
	var left_col=[];
	var right_col=[];
	var plist=e("openwebrx-panels-container").children;
	for(i=0;i<plist.length;i++)
	{
		cpan=plist[i];
		if(cpan.className=="openwebrx-panel")
		{
			if(cpan.openwebrxHidden)
			{
				cpan.style.display="none";
				continue;
			}
			cpan.style.display="block";
			cpan.openwebrxPanelTransparent=(!!cpan.dataset.panelTransparent);
			newSize=cpan.dataset.panelSize.split(",");
			if (cpan.dataset.panelPos=="left") { left_col.push(cpan); }
			else if(cpan.dataset.panelPos=="right") { right_col.push(cpan); }
			cpan.style.width=newSize[0]+"px";
			//cpan.style.height=newSize[1]+"px";
			if(!cpan.openwebrxPanelTransparent) cpan.style.margin=panel_margin.toString()+"px";
			else cpan.style.marginLeft=panel_margin.toString()+"px";
			cpan.openwebrxPanelWidth=parseInt(newSize[0]);
			cpan.openwebrxPanelHeight=parseInt(newSize[1]);
		}
	}

	y=hoffset; //was y=0 before hoffset
	while(left_col.length>0)
	{
		pan=pop_bottommost_panel(left_col);
		pan.style.left="0px";
		pan.style.bottom=y.toString()+"px";
		pan.style.visibility="visible";
		y+=pan.openwebrxPanelHeight+((pan.openwebrxPanelTransparent)?0:3)*panel_margin;
		if(function_apply) function_apply(pan);
	}
	y=hoffset;
	while(right_col.length>0)
	{
		pan=pop_bottommost_panel(right_col);
		pan.style.right=(e("webrx-canvas-container").offsetWidth-e("webrx-canvas-container").clientWidth).toString()+"px"; //get scrollbar width
		pan.style.bottom=y.toString()+"px";
		pan.style.visibility="visible";
		y+=pan.openwebrxPanelHeight+((pan.openwebrxPanelTransparent)?0:3)*panel_margin;
		if(function_apply) function_apply(pan);
	}
}

function progressbar_set(obj,val,text,over)
{
	if (val<0.05) val=0;
	if (val>1) val=1;
	var innerBar=null;
	var innerText=null;
	for(var i=0;i<obj.children.length;i++)
	{
		if(obj.children[i].className=="openwebrx-progressbar-text") innerText=obj.children[i];
		else if(obj.children[i].className=="openwebrx-progressbar-bar") innerBar=obj.children[i];
	}
	if(innerBar==null) return;
	//.h: function animate(object,style_name,unit,from,to,accel,time_ms,fps,to_exec)
	animate(innerBar,"width","px",innerBar.clientWidth,val*obj.clientWidth,0.7,700,60);
	//innerBar.style.width=(val*100).toFixed(0)+"%";
	innerBar.style.backgroundColor=(over)?"#ff6262":"#00aba6";
	if(innerText==null) return;
	innerText.innerHTML=text;
}