// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

#include "wx_pch.h"
#include "timeFrame.h"
#include "openFX3.h"
#include "main_loop.h"      //idx, buffers
#include "global.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(timeFrame)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(timeFrame)
#include <wx/settings.h>
//*)

//(*IdInit(timeFrame)
const long timeFrame::ID_PANEL2 = wxNewId();
const long timeFrame::ID_SLIDER1 = wxNewId();
const long timeFrame::ID_SLIDER2 = wxNewId();
const long timeFrame::ID_STATICTEXT1 = wxNewId();
const long timeFrame::ID_STATICTEXT2 = wxNewId();
const long timeFrame::ID_PANEL1 = wxNewId();
const long timeFrame::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(timeFrame,wxFrame)
	//(*EventTable(timeFrame)
	//*)
END_EVENT_TABLE()

#define Length 1024
wxPoint time_points[2][Length];

timeFrame::timeFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(timeFrame)
	Create(parent, wxID_ANY, _("Booya Time Sample Window"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(1024,578));
	Move(wxPoint(10,300));
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(200,280), wxSize(578,450), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel2 = new wxPanel(Panel1, ID_PANEL2, wxPoint(0,56), wxSize(1024,522), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	Panel2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHTTEXT));
	levelSlider = new wxSlider(Panel1, ID_SLIDER1, 0, -15, 15, wxPoint(574,0), wxSize(300,53), wxSL_AUTOTICKS|wxSL_LABELS, wxDefaultValidator, _T("ID_SLIDER1"));
	levelSlider->SetPageSize(1);
	levelSlider->SetLineSize(1);
	gainSlider = new wxSlider(Panel1, ID_SLIDER2, 2, 0, 10, wxPoint(150,0), wxSize(300,53), wxSL_AUTOTICKS|wxSL_LABELS, wxDefaultValidator, _T("ID_SLIDER2"));
	gainSlider->SetPageSize(1);
	gainSlider->SetLineSize(1);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Level"), wxPoint(536,24), wxSize(32,13), 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Gain"), wxPoint(112,24), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	Timer1.SetOwner(this, ID_TIMER1);
	Timer1.Start(400, false);

	Panel2->Connect(wxEVT_PAINT,(wxObjectEventFunction)&timeFrame::OnPanel2Paint,0,this);
	Connect(ID_SLIDER1,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&timeFrame::OnlevelSliderCmdScrollChanged);
	Connect(ID_SLIDER2,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&timeFrame::OngainSliderCmdScrollChanged);
	Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&timeFrame::OnTimer1Trigger);
	//*)

    for(int n = 0;n<Length;n++) {
        time_points[0][n].x =  n;
        time_points[0][n].y = 50*(1.1+sin((float)n/50));
        time_points[1][n].x =  n;
        time_points[1][n].y = 50*(1.1-sin((float)n/50));
    }

    dc = pow(2,15);
    gainSlider->SetValue(2);
    timeGain = pow(2,gainSlider->GetValue())/128.;

    levelSlider->SetValue(0);
    timeLevel = levelSlider->GetValue()*2048.;

    wxIcon icon(wxT("aaaa")); // set window icon to program icon
    bool a = icon.IsOk();
    SetIcon(icon);

}

timeFrame::~timeFrame()
{
    Close();
	//(*Destroy(timeFrame)
	//*)
}

void timeFrame::OnTimer1Trigger(wxTimerEvent& event)
{
    if(global.run == false) return;
    ttemp = tsecond;
    tsecond = tfirst;
    tfirst = ttemp;
    unsigned short *y = (unsigned short *) buffers[idx];
    for(int n=0;n<Length;n++) time_points[tfirst][n].y = (y[n]-dc -timeLevel)*timeGain+256;
    this->Refresh();
    Update();
}

void timeFrame::OnPanel2Paint(wxPaintEvent& event)
{
    wxPaintDC dc( Panel2 );

    wxColor White(255,255,255);
    wxColor Black(0,0,0);

    wxPen myWhitePen(White,1,wxSOLID);
    wxPen myBlackPen(Black,1,wxSOLID);

    dc.SetPen(myWhitePen);
    dc.DrawLines(Length,time_points[tfirst],0,0);
    dc.SetPen(myBlackPen);
    dc.DrawLines(Length,time_points[tsecond],0,0);
}

void timeFrame::OngainSliderCmdScrollChanged(wxScrollEvent& event)
{        timeGain = pow(2,gainSlider->GetValue())/128.;   }

void timeFrame::OnlevelSliderCmdScrollChanged(wxScrollEvent& event)
{        timeLevel = levelSlider->GetValue()*2048.;  }
