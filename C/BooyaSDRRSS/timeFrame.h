// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

#ifndef TIMEFRAME_H
#define TIMEFRAME_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(timeFrame)
	#include <wx/stattext.h>
	#include <wx/slider.h>
	#include <wx/panel.h>
	#include <wx/frame.h>
	#include <wx/timer.h>
	//*)
#endif
//(*Headers(timeFrame)
//*)

class timeFrame: public wxFrame
{
	public:

		timeFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~timeFrame();

		//(*Declarations(timeFrame)
		wxStaticText* StaticText2;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxSlider* gainSlider;
		wxPanel* Panel2;
		wxSlider* levelSlider;
		wxTimer Timer1;
		//*)

	protected:

		//(*Identifiers(timeFrame)
		static const long ID_PANEL2;
		static const long ID_SLIDER1;
		static const long ID_SLIDER2;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_PANEL1;
		static const long ID_TIMER1;
		//*)

	private:

		//(*Handlers(timeFrame)
		void OnPaint(wxPaintEvent& event);
		void OnPanel2Paint(wxPaintEvent& event);
		void OnTimer1Trigger(wxTimerEvent& event);
		void OngainSliderCmdScrollChanged(wxScrollEvent& event);
		void OnlevelSliderCmdScrollChanged(wxScrollEvent& event);
		//*)

		DECLARE_EVENT_TABLE()


        float dc = 0;
        float timeGain = 0;
        float timeLevel = 0;

        int tfirst = 0, tsecond = 1, ttemp = 0;

};

#endif
