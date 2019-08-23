///////////////////////////////////////////////////////////////////////////////////////////
var color_map = new Uint32Array(256);
var color_map_r = new Uint8Array(256);
var color_map_g = new Uint8Array(256);
var color_map_b = new Uint8Array(256);

mkcolormap();

var c,cc, w0,h0;
var store, record;

// var zoom = { N:7, level: 0, min: 0, max: 7, maxmax:10, left:0, maxLeft:1 };
var Nzoom = 7;
var zoom_level = 0;
var zoom_display = 0;
var minZoom = 0;
var maxZoom = Nzoom-1;
var maxmaxZoom = maxZoom + 5;
var left = 0;
var leftMax = 1;

var drawLineTimer;
var local;
var scrollWidth = 16;
var ctx;
var window_mouseout = false;

function wfdisplay_init() {
	var x = new ArrayBuffer(20);
	var y = new Uint8Array(x);
	y.set([1],0);
	y.set([2],8);
	var z = new Uint32Array(x,8,1);
	var xx = z[0];

	c=document.getElementById("wf-canvas");
	cc=document.getElementById("wf-canvas-container");
	local = true;

	if(c == null) {
		local = false;
		c = document.createElement('canvas');
		cc=document.getElementById("webrx-canvas-container");
		body = document.getElementsByTagName("body")[0];
		cc.appendChild(c);
		c.width  = 1024;
		c.height =  800;
		c.style.width = cc.clientWidth.toString() + "px";
		c.style.position 	= "absolute";
		c.style.display 	= "block";
		c.style.boarder 	= "5px";
		c.style.height 	= "800px";
		c.style.resize 	= "horizontal";
		c.setAttribute("id","js-wfdisplay");
		init_rx_photo();
	}

	scrollWidth = getScrollBarWidth();
	c.ctx=c.getContext("2d");
	ctx = c.ctx;
	ctx.mozImageSmoothingEnabled = false;
	ctx.imageSmoothingEnabled = false;
	ctx.mozImageSmoothingEnabled = true;
	ctx.imageSmoothingEnabled = true;
	w0 = c.width;
	h0 = c.height;
	c.ctx.fillStyle = "white";

	if(!local) {
		cc.width = c.style.width;
		cc.style.width = c.style.width.toString() + "px";
	}
	store = {x:0};
	record = {start: 0, end: 0, len: 0, data: new Array(h0)};

	Nzoom = 7;
	zoom_level = 0;
	minZoom = 0;
	maxZoom = Nzoom-1;
	left = 0;
	leftMax = 1;

	// create a storage canvas, context and image
	store.c = document.createElement('canvas');
	store.c.style.position = "absolute";
	store.c.style.display = "none";
	store.c.width = w0;
	store.c.height = h0;
	store.c.style.height = h0;
	var body = document.getElementsByTagName("body")[0];
	body.appendChild(store.c);
	store.ctx = store.c.getContext("2d");
	store.ctx.mozImageSmoothingEnabled = false;
	store.ctx.imageSmoothingEnabled = false;
	store.img = store.ctx.createImageData( w0,h0);

	c.addEventListener("wheel",		wf_mousewheel, false);
	c.addEventListener("mousedown",	wf_mousedown, false);
	c.addEventListener("mousemove",	wf_mousemove, false);
	c.addEventListener("mouseup",		wf_mouseup, false);
	c.addEventListener("mouseout", 	wf_mouseout, false);
	window.addEventListener("mouseout", 	window_mouseoutf, false);
	window.addEventListener("resize",wf_resize);

	wf_resize();
	if(!local) {
		place_panels(first_show_panel);
		open_websocket();
		window.setTimeout(function(){window.setInterval(debug_audio,1000);},1000);
		window.addEventListener("resize",openwebrx_resize);

		updateVolume(); //get volume from slider
		waterfallColorsDefault();
	   init_demodulator_mod(e("am-button"),'am');

	} else {
		drawLineTimer = setInterval( function() { draw_line(c,0); }, 100 );
	}
}

function wf_waterfall_add(data) {
	var w=w0;
	//Add line to waterfall image
	for(x=0;x<w;x++) {
		color=waterfall_mkcolor(data[x]);
		for(i=0;i<4;i++) store.img.data[record.end*4*w0+x*4+i] = ((color>>>0)>>((3-i)*8))&0xff;
	}
	draw_line(c,data.wf);
	if(data[100]<-255)
	console.log(data[100]);
}

function wf_resize() {
	c.style.resize = "horizontal";
	var new_width=(window.innerWidth-scrollWidth).toString()+"px";
	c.style.width = new_width;
}

function  make_line(zoom_level,left) {
	var idx;

	var Left = left;
	var Zoom = zoom_level;

	var wid0 = Math.pow(.5,Zoom);
	if(Zoom > maxZoom) Zoom = maxZoom;
	var wid1 = Math.pow(.5,Zoom);
	Left = Left + wid0/2 - wid1/2;
	Left = ( Left < 0 ? 0 : Left);
	Left = ( Left > (1-wid1) ? (1-wid1) : Left);
	Left = Math.round(Left*w0*Math.pow(2,Zoom))/w0/Math.pow(2,Zoom);

	var wf = { zoom_level: Zoom, left: Left};

	for(var x=0;x<w0;x++) {
		idx = 255;
		for(var y = 0; y<1 ; y += .005)
			if(Math.round((y - Left)*w0*Math.pow(2,Zoom)) == x) idx = 0;
		color=color_map[idx];
		for(i=0;i<4;i++) store.img.data[record.end*4*w0+x*4+i] = ((color>>>0)>>((3-i)*8))&0xff;
	}
	idx = 0;
	color=color_map[idx];
	for(i=0;i<4;i++) store.img.data[record.end*4*w0+(w0-1)*4+i] = ((color>>>0)>>((3-i)*8))&0xff;
	return wf;
}

var idx = 0;
function draw_line(cv,wfa) {
	if(pause) return;
	var wf;
	if(local) {	wf = make_line(zoom_level,left);
	} else		wf = wfa;

	ctx = cv.ctx;
	rep = 1;
	if(local) rep = 1;
	Xsource = .5;
	Wsource = w0;
	Hsource = 1;
	Hdest = 1;
	Ydest = 0;
	zd = zoom_level;	// zd - zoom of destination

	for(var z = 0; z<rep; z++) {
		ctx.drawImage(cv,0,0,w0,h0,0,1,w0,h0); 	// shift down
		store.ctx.putImageData(store.img,0,0,0,record.end+z,w0,1); // store line on line canvas for later redraw
		// putImageData(image,Xdest,Ydest,Xsource,Ysource,Wdest,Hdest)
		if(zoom_level <= maxZoom)
			ctx.putImageData(store.img,0,-record.end-z,0,record.end+z,w0,1); // copy line from line canvas onto main canvas
		else {
		// zs - zoom of source
			zs = wf.zoom_level;
			Ysource = record.end+z;
			Xdest = w0*Math.pow(2,zd)*(wf.left-left);
			Wdest = w0*Math.pow(2,zd-zs);
			ctx.fillRect(0,Ydest,c.width,1);
			ctx.drawImage(store.c,Xsource,Ysource,Wsource,Hsource,Xdest,Ydest,Wdest,Hdest);
		}
	}

	for(var z = 0; z<rep; z++)
		record.data[record.end++] = {zoom: wf.zoom_level, left: wf.left};

	if(record.len < h0) {
		record.len+=rep;
		record.end = record.end%h0;
	} else {
		record.end = record.end%h0;
		record.start = record.end; // since image is painted in reverse
	}

	new_zoomf();
}

function redraw(zoom, left) {
	if(local) e("zoom-label").innerHTML = "Zoom level: " + zoom;
	var ctx = c.ctx;
	Xsource = .5;
	Wsource = w0;
	Hsource = 1;
	Hdest = 1;
	var Rstart = record.start;
	var Len = record.len;
// zs - zoom of source
// zd - zoom of destination
	zd = zoom;
	var yi = Rstart;
	for(m = 0; m < Len;m++) {
		zs = record.data[yi].zoom;
		Ysource = yi;
		Xdest = (w0*Math.pow(2,zd)*(record.data[yi].left-left));
		Wdest = w0*Math.pow(2,zd-zs);
		Ydest = Len-m-1;
		ctx.fillRect(0,Ydest,c.width,1);
		ctx.drawImage(store.c,Xsource,Ysource,Wsource,Hsource,Xdest,Ydest,Wdest,Hdest);
		yi++;
		yi%= h0;
	}
}

function new_zoomf() {
	if(!new_zoom.update) return;
	drag.Xstart = drag.Xend;
	zoom_level = new_zoom.level;
	left = new_zoom.left;
	Zoom = new_zoom.level;
	Left = new_zoom.left;

	 if(!local) {
		if(zoom_level>maxZoom) {
			var wid0 = Math.pow(.5,Zoom);
			if(Zoom > maxZoom) Zoom = maxZoom;
			var wid1 = Math.pow(.5,Zoom);
			Left = Left + wid0/2 - wid1/2;
			Left = ( Left < 0 ? 0 : Left);
			Left = ( Left > (1-wid1) ? (1-wid1) : Left);
			Left = Math.round(Left*w0*Math.pow(2,Zoom))/w0/Math.pow(2,Zoom);

		}
		ws.send("SET zoom="+Zoom.toString()+" left="+Left.toString());
	}
	redraw(zoom_level,left);
	if(!local) {
		resize_scale();
		mkscale();
		e("webrx-mouse-freq").innerHTML=format_frequency("{x} MHz",canvas_get_frequency(relativeX),1e6,4);
	}
	new_zoom.update = false;
}

function set_demodulator_mod(t,mod) {
	var x = document.getElementsByClassName("openwebrx-button openwebrx-demodulator-button");
	for (var i = 0; i < x.length; i++) {
		x[i].style.color = "White";
	}
	t.style.color = '#00FF00';
	var set_mod = "SET mod="+mod;
	ws.send(set_mod);
	demodulator_analog_replace(mod);
}

function init_demodulator_mod(t,mod) {
	var x = document.getElementsByClassName("openwebrx-button openwebrx-demodulator-button");
	for (var i = 0; i < x.length; i++) {
		x[i].style.color = "White";
	}
	t.style.color = '#00FF00';
}

function freqstep(arg) {
	console.log("freqstep arg "+arg);
	switch (arg) {
		case 0: df = 	-1000; 	break;
		case 1: df = 	-100; 	break;
		case 2: df = 	-10;		break;
		case 3: df =  	 10;		break;
		case 4: df =  	 100; 	break;
		case 5: df = 	 1000; 	break;
		default:	df = 0; break;
	}
	var new_offset_frequency = demodulators[0].offset_frequency + df;
	demodulator_set_offset_frequency(0,new_offset_frequency);
	e("webrx-actual-freq").innerHTML=format_frequency("{x} MHz",center_freq+new_offset_frequency,1e6,6);
}

var drag = {Xstart:0, Xend:0};
var indrag = false;
var new_zoom = {level:0 , left: 0 , update: false };

function wf_mousedown(evt) {
	drag.Xstart = evt.offsetX;
	drag.Xend = drag.Xstart;
	indrag = true;
	canvas_drag = false;
}

var cnt = 0;
function wf_mousemove(evt) {
	if(indrag == false) {
		relativeX=(evt.offsetX)?evt.offsetX:evt.layerX;
		if(!local)
		e("webrx-mouse-freq").innerHTML=format_frequency("{x} MHz",canvas_get_frequency(relativeX),1e6,4);
		return;
	}
	var Left = left;
	var Zoom_level = zoom_level;
	drag.Xend = evt.offsetX;
	dX = (drag.Xstart - drag.Xend);
//	if(cnt%10 == 0) console.log(dX);

	if(Math.abs(dX)>0) canvas_drag = true;

//	drag.Xstart = drag.Xend;
	if(Math.abs(dX) == 0) return;
	var zf = Math.pow(2,Zoom_level);
	Left += dX/evt.target.offsetWidth/zf;
	Left = (Left<0? 0 : Left);
	leftMax = 1-1/zf;
	Left = ( Left > leftMax ? leftMax : Left);
	new_zoom.level = Zoom_level;
	new_zoom.left = Left;
	new_zoom.update = true;
	if(!local)
		e("webrx-mouse-freq").innerHTML=format_frequency("{x} MHz",canvas_get_frequency(relativeX),1e6,4);
}

function wf_mouseup(evt)  { indrag = false; canvas_mouseup(evt);}
function wf_mouseout(evt) { indrag = false; }
function window_mouseoutf(evt) { window_mouseout = true; console.log("window_mouseout")}

function wf_mousewheel(evt) {
	var offsetX = evt.offsetX-1; 									// zoom location
	var offsetWidth = evt.target.offsetWidth;
//	console.log("offsetX " + offsetX + "   offsetWidth "+offsetWidth+ "   innerWidth "+window.innerWidth);
	var out = ((evt.deltaY / Math.abs(evt.deltaY)) > 0); 	// zoom direction
	var changed = false;
	var Zoom_level = zoom_level;
	var Left = left;
	var widMax = Math.pow(.5,maxZoom);
	if(out) { // zoom out
		if(Zoom_level>minZoom) {
			var zf0 = Math.pow(2,Zoom_level);
			Zoom_level--;
			var zf1 = Math.pow(2,Zoom_level);
			Left += (offsetX)/(offsetWidth)*(1/zf0 - 1/zf1);
			leftMax = 1-1/zf1;
			Left = (Left<0? 0 : Left);
			Left = ( Left > leftMax ? leftMax : Left);
			changed = true;
		}
	} else { // zoom in
		if(Zoom_level < maxmaxZoom) {
			var zf0 = Math.pow(2,Zoom_level);
			Zoom_level++;
			var zf1 = Math.pow(2,Zoom_level);
			Left += (offsetX)/(offsetWidth)*(1/zf0 - 1/zf1);
			leftMax = 1-1/zf1;
			Left = ( Left < 0 ? 0 : Left);
			Left = ( Left > leftMax ? leftMax : Left);
			changed = true;
		}
	}
	if(changed) {
		new_zoom.left = Left;
		new_zoom.level = Zoom_level;
		new_zoom.update = true;
	}
	evt.preventDefault();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

function wf_zoomInOneStep(){
	var changed = false;
	var Zoom_level = zoom_level;
	var Left = left;
	if(Zoom_level<maxZoom) {
		var zf0 = Math.pow(2,Zoom_level);
		Zoom_level++;
		var zf1 = Math.pow(2,Zoom_level);
		Left += 0.5*(1/zf0 - 1/zf1);
		leftMax = 1-1/zf1;
		Left = ( Left < 0 ? 0 : Left);
		Left = ( Left > leftMax ? leftMax : Left);
		changed = true;
	}
	if(changed) {
		new_zoom.left = Left;
		new_zoom.level = Zoom_level;
		new_zoom.update = true;
	}
}

function wf_zoomOutOneStep(){
	var changed = false;
	var Zoom_level = zoom_level;
	var Left = left;
	if(Zoom_level>minZoom) {
		var zf0 = Math.pow(2,Zoom_level);
		Zoom_level--;
		var zf1 = Math.pow(2,Zoom_level);
		Left += 0.5*(1/zf0 - 1/zf1);
		leftMax = 1-1/zf1;
		Left = (Left<0? 0 : Left);
		Left = ( Left > leftMax ? leftMax : Left);
		changed = true;
	}
	if(changed) {
		new_zoom.left = Left;
		new_zoom.level = Zoom_level;
		new_zoom.update = true;
	}
}
function wf_zoomInTotal(){
	var changed = false;
	var Zoom_level = zoom_level;
	var Left = left;
	if(Zoom_level<maxZoom) {
		var zf0 = Math.pow(2,Zoom_level);
		Zoom_level=maxZoom;
		var zf1 = Math.pow(2,Zoom_level);
		Left += 0.5*(1/zf0 - 1/zf1);
		leftMax = 1-1/zf1;
		Left = ( Left < 0 ? 0 : Left);
		Left = ( Left > leftMax ? leftMax : Left);
		changed = true;
	}
	if(changed) {
		new_zoom.left = Left;
		new_zoom.level = Zoom_level;
		new_zoom.update = true;
	}
}
function wf_zoomOutTotal(){
	var changed = false;
	var Zoom_level = zoom_level;
	var Left = left;
	if(Zoom_level>minZoom) {
		var zf0 = Math.pow(2,Zoom_level);
		Zoom_level=minZoom;
		var zf1 = Math.pow(2,Zoom_level);
		Left += 0.5*(1/zf0 - 1/zf1);
		leftMax = 1-1/zf1;
		Left = ( Left < 0 ? 0 : Left);
		Left = ( Left > leftMax ? leftMax : Left);
		changed = true;
	}
	if(changed) {
		new_zoom.left = Left;
		new_zoom.level = Zoom_level;
		new_zoom.update = true;
	}
}
var stop = false;
var pause = false;
function goButton() { stop = true; }
function pauseButton() {
	var whf = document.hasFocus();
	if(!whf) return;
	if(!pause) pause = true;
	else pause = false;
}

function mkcolormap() {
	for (var i=0; i<256; i++) {
		var r, g, b;
		colormap_select = 0;

		switch (colormap_select) {

		case 1:
			// new default
			if (i < 32) {
				r = 0; g = 0; b = i*255/31;
			} else if (i < 72) {
				r = 0; g = (i-32)*255/39; b = 255;
			} else if (i < 96) {
				r = 0; g = 255; b = 255-(i-72)*255/23;
			} else if (i < 116) {
				r = (i-96)*255/19; g = 255; b = 0;
			} else if (i < 184) {
				r = 255; g = 255-(i-116)*255/67; b = 0;
			} else {
				r = 255; g = 0; b = (i-184)*128/70;
			}
			break;

		case 0:
		default:
			// old one from CuteSDR
			if (i<43) {
				r = 0; g = 0; b = i*255/43;
			} else if (i<87) {
				r = 0; g = (i-43)*255/43; b = 255;
			} else if (i<120) {
				r = 0; g = 255; b = 255-(i-87)*255/32;
			} else if (i<154) {
				r = (i-120)*255/33; g = 255; b = 0;
			} else if (i<217) {
				r = 255; g = 255-(i-154)*255/62; b = 0;
			} else {
				r = 255; g = 0; b = (i-217)*128/38;
			}
			break;
		}

		color_map[i] = (r<<24) | (g<<16) | (b<<8) | 0xff;
//		color_map_transparent[i] = (r<<24) | (g<<16) | (b<<8) | spectrum_scale_color_map_transparency;
		color_map_r[i] = r;
		color_map_g[i] = g;
		color_map_b[i] = b;
	}
}

function e(x) {
	var y = document.getElementById(x);
	return y;
}

function getScrollBarWidth () {
  var inner = document.createElement('p');
  inner.style.width = "100%";
  inner.style.height = "200px";

  var outer = document.createElement('div');
  outer.style.position = "absolute";
  outer.style.top = "0px";
  outer.style.left = "0px";
  outer.style.visibility = "hidden";
  outer.style.width = "200px";
  outer.style.height = "150px";
  outer.style.overflow = "hidden";
  outer.appendChild (inner);

  document.body.appendChild (outer);
  var w1 = inner.offsetWidth;
  outer.style.overflow = 'scroll';
  var w2 = inner.offsetWidth;
  if (w1 == w2) w2 = outer.clientWidth;

  document.body.removeChild (outer);

  return (w1 - w2);
};
