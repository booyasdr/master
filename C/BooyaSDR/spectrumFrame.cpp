// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

/*
spectrumFrame Class, main window
Panels are on screen regions, wx objects to display the spectrum
spImageBuffer are arrays to holds all the plot data in panel size chunks
pImage are pointers to spImageBuffer data to be plotted on the Panels

Spectrum display runs on timer loop.
The time call has the variables:
    sp.idx - spectum action index
    sp.period - spectrum action period
The time call does the following:
    increment sp.idx modulo sp.period
    on sp.idx == 0, call spctrumf() to do the fft
    on sp.idx == 3, update image buffers with the resulting data
*/

#include <sys/time.h>
#include "spectrumFrame.h"
#include "monitor.h"
#include "radio.h"
#include "spectrum.h"
#include "global.h"
#include "thisApp.h"
#include "fftw3.h"

static void sighandler(int signum) {
	fprintf(stderr, "Signal caught, exiting!\n");
    global.run = false;
	Sleep(300);
}

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(spectrumFrame)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(spectrumFrame)
#include <wx/settings.h>
//*)

//(*IdInit(spectrumFrame)
const long spectrumFrame::ID_STATICTEXT1 = wxNewId();
const long spectrumFrame::ID_STATICTEXT2 = wxNewId();
const long spectrumFrame::ID_STATICTEXT3 = wxNewId();
const long spectrumFrame::ID_STATICTEXT4 = wxNewId();
const long spectrumFrame::ID_STATICTEXT6 = wxNewId();
const long spectrumFrame::ID_SLIDER6 = wxNewId();
const long spectrumFrame::ID_STATICTEXT7 = wxNewId();
const long spectrumFrame::ID_SLIDER4 = wxNewId();
const long spectrumFrame::ID_SLIDER3 = wxNewId();
const long spectrumFrame::ID_SLIDER2 = wxNewId();
const long spectrumFrame::ID_SLIDER1 = wxNewId();
const long spectrumFrame::ID_SPFRPANEL1 = wxNewId();
const long spectrumFrame::ID_MENUITEM1 = wxNewId();
const long spectrumFrame::ID_MENUITEM2 = wxNewId();
const long spectrumFrame::ID_MENUITEM3 = wxNewId();
const long spectrumFrame::ID_MENUITEM4 = wxNewId();
const long spectrumFrame::ID_MENUITEM5 = wxNewId();
const long spectrumFrame::ID_MENUITEM6 = wxNewId();
const long spectrumFrame::ID_MENUITEM31 = wxNewId();
const long spectrumFrame::ID_MENUITEM48 = wxNewId();
const long spectrumFrame::ID_MENUITEM7 = wxNewId();
const long spectrumFrame::ID_MENUITEM8 = wxNewId();
const long spectrumFrame::ID_MENUITEM9 = wxNewId();
const long spectrumFrame::ID_MENUITEM10 = wxNewId();
const long spectrumFrame::ID_MENUITEM11 = wxNewId();
const long spectrumFrame::ID_MENUITEM49 = wxNewId();
const long spectrumFrame::ID_MENUITEM50 = wxNewId();
const long spectrumFrame::ID_MENUITEM12 = wxNewId();
const long spectrumFrame::ID_MENUITEM13 = wxNewId();
const long spectrumFrame::ID_NB8 = wxNewId();
const long spectrumFrame::ID_MENUITEM15 = wxNewId();
const long spectrumFrame::ID_MENUITEM16 = wxNewId();
const long spectrumFrame::ID_MENUITEM17 = wxNewId();
const long spectrumFrame::ID_MENUITEM18 = wxNewId();
const long spectrumFrame::ID_MENUITEM19 = wxNewId();
const long spectrumFrame::ID_MENUITEM20 = wxNewId();
const long spectrumFrame::ID_MENUITEM21 = wxNewId();
const long spectrumFrame::ID_MENUITEM22 = wxNewId();
const long spectrumFrame::ID_MENUITEM14 = wxNewId();
const long spectrumFrame::ID_MENUITEM27 = wxNewId();
const long spectrumFrame::ID_MENUITEM23 = wxNewId();
const long spectrumFrame::ID_MENUITEM24 = wxNewId();
const long spectrumFrame::ID_MENUITEM45 = wxNewId();
const long spectrumFrame::ID_MENUITEM46 = wxNewId();
const long spectrumFrame::ID_MENUITEM26 = wxNewId();
const long spectrumFrame::ID_MENUITEM25 = wxNewId();
const long spectrumFrame::ID_MENUITEM28 = wxNewId();
const long spectrumFrame::ID_MENUITEM29 = wxNewId();
const long spectrumFrame::ID_MENUITEM30 = wxNewId();
const long spectrumFrame::ID_MENUITEM36 = wxNewId();
const long spectrumFrame::ID_MENUITEM38 = wxNewId();
const long spectrumFrame::ID_MENUITEM37 = wxNewId();
const long spectrumFrame::ID_MENUITEM39 = wxNewId();
const long spectrumFrame::ID_MENUITEM40 = wxNewId();
const long spectrumFrame::ID_MENUITEM41 = wxNewId();
const long spectrumFrame::ID_MENUITEM42 = wxNewId();
const long spectrumFrame::ID_MENUITEM43 = wxNewId();
const long spectrumFrame::ID_MENUITEM44 = wxNewId();
const long spectrumFrame::ID_MENUITEM32 = wxNewId();
const long spectrumFrame::ID_MENUITEM33 = wxNewId();
const long spectrumFrame::ID_MENUITEM34 = wxNewId();
const long spectrumFrame::ID_MENUITEM35 = wxNewId();
//*)

const long spectrumFrame::ID_TIMEWINDOW = wxNewId();

BEGIN_EVENT_TABLE(spectrumFrame,wxFrame)
	//(*EventTable(spectrumFrame)
	//*)
END_EVENT_TABLE()

spectrumFrame* sf; // global pointer to spectrumFrame for pthread, set in initializer
void *imageUpdateThread(void *arg);
pthread_t image_update_thread[10];
pthread_mutex_t mutexImageUpdate;


spectrumFrame::spectrumFrame(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(spectrumFrame)
	Create(parent, wxID_ANY, _("Booya SDR Spectrum Window"), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
	SetClientSize(wxSize(1024,800));
	Move(wxPoint(10,800));
	mainSpectrumPanel = new wxPanel(this, ID_SPFRPANEL1, wxPoint(0,20), wxSize(1024,500), 0, _T("ID_SPFRPANEL1"));
	StaticText1 = new wxStaticText(mainSpectrumPanel, ID_STATICTEXT1, _("    Radio\nFrequency\n     kHz"), wxPoint(10,4), wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(mainSpectrumPanel, ID_STATICTEXT2, _("      Fine\n Frequency\n   100 Hz"), wxPoint(370,4), wxSize(56,40), wxALIGN_RIGHT, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(mainSpectrumPanel, ID_STATICTEXT3, _("Display\nBrightness"), wxPoint(696,16), wxSize(55,32), wxALIGN_RIGHT, _T("ID_STATICTEXT3"));
	StaticText4 = new wxStaticText(mainSpectrumPanel, ID_STATICTEXT4, _("Audio\nGain"), wxPoint(540,16), wxSize(33,32), wxALIGN_RIGHT, _T("ID_STATICTEXT4"));
	StaticText6 = new wxStaticText(mainSpectrumPanel, ID_STATICTEXT6, _("Start\nMHz"), wxPoint(872,4), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	startMhzSlider = new wxSlider(mainSpectrumPanel, ID_SLIDER6, 0, 0, 60, wxPoint(900,0), wxDefaultSize, wxSL_AUTOTICKS|wxSL_LABELS, wxDefaultValidator, _T("ID_SLIDER6"));
	startMhzSlider->SetPageSize(1);
	startMhzSlider->SetThumbLength(1);
	startMHzLabel = new wxStaticText(mainSpectrumPanel, ID_STATICTEXT7, _("0"), wxPoint(875,36), wxSize(13,13), wxALIGN_RIGHT, _T("ID_STATICTEXT7"));
	gainSlider = new wxSlider(mainSpectrumPanel, ID_SLIDER4, 0, -7, 7, wxPoint(575,0), wxDefaultSize, wxSL_AUTOTICKS|wxSL_LABELS, wxDefaultValidator, _T("ID_SLIDER4"));
	gainSlider->SetPageSize(1);
	gainSlider->SetLineSize(1);
	brightnessSlider = new wxSlider(mainSpectrumPanel, ID_SLIDER3, 0, -7, 7, wxPoint(750,0), wxDefaultSize, wxSL_AUTOTICKS|wxSL_LABELS, wxDefaultValidator, _T("ID_SLIDER3"));
	brightnessSlider->SetPageSize(1);
	brightnessSlider->SetLineSize(1);
	fineFrequencySlider = new wxSlider(mainSpectrumPanel, ID_SLIDER2, 0, -6, 6, wxPoint(432,0), wxDefaultSize, wxSL_AUTOTICKS|wxSL_LABELS, wxDefaultValidator, _T("ID_SLIDER2"));
	fineFrequencySlider->SetPageSize(1);
	fineFrequencySlider->SetLineSize(1);
	fineFrequencySlider->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
	frequencySlider = new wxSlider(mainSpectrumPanel, ID_SLIDER1, 0, 0, 32000, wxPoint(64,0), wxSize(300,50), wxSL_AUTOTICKS|wxSL_LABELS, wxDefaultValidator, _T("ID_SLIDER1"));
	frequencySlider->SetPageSize(5);
	frequencySlider->SetTick(1000);
	frequencySlider->SetToolTip(_("Tune the Radio"));
	frequencySlider->SetHelpText(_("Tune the Radio"));
	MenuBar1 = new wxMenuBar();
	radioMode = new wxMenu();
	SilentMenu = new wxMenuItem(radioMode, ID_MENUITEM1, _("Silent"), wxEmptyString, wxITEM_RADIO);
	radioMode->Append(SilentMenu);
	AMMenu = new wxMenuItem(radioMode, ID_MENUITEM2, _("AM"), wxEmptyString, wxITEM_RADIO);
	radioMode->Append(AMMenu);
	DSBMenu = new wxMenuItem(radioMode, ID_MENUITEM3, _("DSB"), wxEmptyString, wxITEM_RADIO);
	radioMode->Append(DSBMenu);
	LSBMenu = new wxMenuItem(radioMode, ID_MENUITEM4, _("LSB"), wxEmptyString, wxITEM_RADIO);
	radioMode->Append(LSBMenu);
	USBMenu = new wxMenuItem(radioMode, ID_MENUITEM5, _("USB"), wxEmptyString, wxITEM_RADIO);
	radioMode->Append(USBMenu);
	CWMenu = new wxMenuItem(radioMode, ID_MENUITEM6, _("CW"), wxEmptyString, wxITEM_RADIO);
	radioMode->Append(CWMenu);
	radioMode->AppendSeparator();
	MenuQuit = new wxMenuItem(radioMode, ID_MENUITEM31, _("Quit"), wxEmptyString, wxITEM_NORMAL);
	radioMode->Append(MenuQuit);
	MenuBar1->Append(radioMode, _("Radio Mode"));
	kHzPanelBar = new wxMenu();
	MenuItem10 = new wxMenuItem(kHzPanelBar, ID_MENUITEM48, _("kHz/Panel"), wxEmptyString, wxITEM_NORMAL);
	kHzPanelBar->Append(MenuItem10);
	kHzPanelBar->AppendSeparator();
	khpb125 = new wxMenuItem(kHzPanelBar, ID_MENUITEM7, _("125"), wxEmptyString, wxITEM_RADIO);
	kHzPanelBar->Append(khpb125);
	khpb250 = new wxMenuItem(kHzPanelBar, ID_MENUITEM8, _("250"), wxEmptyString, wxITEM_RADIO);
	kHzPanelBar->Append(khpb250);
	khpb500 = new wxMenuItem(kHzPanelBar, ID_MENUITEM9, _("500"), wxEmptyString, wxITEM_RADIO);
	kHzPanelBar->Append(khpb500);
	khpb1000 = new wxMenuItem(kHzPanelBar, ID_MENUITEM10, _("1000"), wxEmptyString, wxITEM_RADIO);
	kHzPanelBar->Append(khpb1000);
	khpb2000 = new wxMenuItem(kHzPanelBar, ID_MENUITEM11, _("2000"), wxEmptyString, wxITEM_RADIO);
	kHzPanelBar->Append(khpb2000);
	MenuBar1->Append(kHzPanelBar, _("Resolution"));
	NPanelMenu = new wxMenu();
	nb4 = new wxMenuItem(NPanelMenu, ID_MENUITEM49, _("4"), wxEmptyString, wxITEM_RADIO);
	NPanelMenu->Append(nb4);
	nb5 = new wxMenuItem(NPanelMenu, ID_MENUITEM50, _("5"), wxEmptyString, wxITEM_RADIO);
	NPanelMenu->Append(nb5);
	nb6 = new wxMenuItem(NPanelMenu, ID_MENUITEM12, _("6"), wxEmptyString, wxITEM_RADIO);
	NPanelMenu->Append(nb6);
	nb7 = new wxMenuItem(NPanelMenu, ID_MENUITEM13, _("7"), wxEmptyString, wxITEM_RADIO);
	NPanelMenu->Append(nb7);
	nb8 = new wxMenuItem(NPanelMenu, ID_NB8, _("8"), wxEmptyString, wxITEM_RADIO);
	NPanelMenu->Append(nb8);
	nb9 = new wxMenuItem(NPanelMenu, ID_MENUITEM15, _("9"), wxEmptyString, wxITEM_RADIO);
	NPanelMenu->Append(nb9);
	nb10 = new wxMenuItem(NPanelMenu, ID_MENUITEM16, _("10"), wxEmptyString, wxITEM_RADIO);
	NPanelMenu->Append(nb10);
	nb11 = new wxMenuItem(NPanelMenu, ID_MENUITEM17, _("11"), wxEmptyString, wxITEM_RADIO);
	NPanelMenu->Append(nb11);
	nb12 = new wxMenuItem(NPanelMenu, ID_MENUITEM18, _("12"), wxEmptyString, wxITEM_RADIO);
	NPanelMenu->Append(nb12);
	nb13 = new wxMenuItem(NPanelMenu, ID_MENUITEM19, _("13"), wxEmptyString, wxITEM_RADIO);
	NPanelMenu->Append(nb13);
	nb14 = new wxMenuItem(NPanelMenu, ID_MENUITEM20, _("14"), wxEmptyString, wxITEM_RADIO);
	NPanelMenu->Append(nb14);
	nb15 = new wxMenuItem(NPanelMenu, ID_MENUITEM21, _("15"), wxEmptyString, wxITEM_RADIO);
	NPanelMenu->Append(nb15);
	nb16 = new wxMenuItem(NPanelMenu, ID_MENUITEM22, _("16"), wxEmptyString, wxITEM_RADIO);
	NPanelMenu->Append(nb16);
	nb17 = new wxMenuItem(NPanelMenu, ID_MENUITEM14, _("17"), wxEmptyString, wxITEM_RADIO);
	NPanelMenu->Append(nb17);
	nb18 = new wxMenuItem(NPanelMenu, ID_MENUITEM27, _("18"), wxEmptyString, wxITEM_RADIO);
	NPanelMenu->Append(nb18);
	MenuBar1->Append(NPanelMenu, _("Height"));
	Menu6 = new wxMenu();
	Widthx1 = new wxMenuItem(Menu6, ID_MENUITEM23, _("1024"), wxEmptyString, wxITEM_RADIO);
	Menu6->Append(Widthx1);
	Widthx2 = new wxMenuItem(Menu6, ID_MENUITEM24, _("2048"), wxEmptyString, wxITEM_RADIO);
	Menu6->Append(Widthx2);
	MenuItem11 = new wxMenuItem(Menu6, ID_MENUITEM45, _("960"), wxEmptyString, wxITEM_RADIO);
	Menu6->Append(MenuItem11);
	MenuItem12 = new wxMenuItem(Menu6, ID_MENUITEM46, _("1280"), wxEmptyString, wxITEM_RADIO);
	Menu6->Append(MenuItem12);
	MenuBar1->Append(Menu6, _("Width"));
	AMAGC = new wxMenu();
	AMAGCoff = new wxMenuItem(AMAGC, ID_MENUITEM26, _("Off"), wxEmptyString, wxITEM_RADIO);
	AMAGC->Append(AMAGCoff);
	AMAGCon = new wxMenuItem(AMAGC, ID_MENUITEM25, _("On"), wxEmptyString, wxITEM_RADIO);
	AMAGC->Append(AMAGCon);
	MenuBar1->Append(AMAGC, _("AM AGC"));
	Menu1 = new wxMenu();
	MenuSpectrum = new wxMenuItem(Menu1, ID_MENUITEM28, _("Spectrum"), _("Bring Spectrum window to top"), wxITEM_NORMAL);
	Menu1->Append(MenuSpectrum);
	MenuTimeSample = new wxMenuItem(Menu1, ID_MENUITEM29, _("Time Sample"), _("Bring Time window to top"), wxITEM_NORMAL);
	Menu1->Append(MenuTimeSample);
	MenuConsole = new wxMenuItem(Menu1, ID_MENUITEM30, _("Console"), _("Bring Console to top"), wxITEM_NORMAL);
	Menu1->Append(MenuConsole);
	MenuBar1->Append(Menu1, _("Window"));
	Menu3 = new wxMenu();
	Menu4 = new wxMenuItem(Menu3, ID_MENUITEM36, _("Radio Mode - Choose radio demodulation type"), wxEmptyString, wxITEM_NORMAL);
	Menu3->Append(Menu4);
	Menu7 = new wxMenuItem(Menu3, ID_MENUITEM38, _("Resolution - Set freqeuency resolution in kHz/Panel"), wxEmptyString, wxITEM_NORMAL);
	Menu3->Append(Menu7);
	MenuItem1 = new wxMenuItem(Menu3, ID_MENUITEM37, _("Hieght - Number of vertical panels in window"), wxEmptyString, wxITEM_NORMAL);
	Menu3->Append(MenuItem1);
	MenuItem4 = new wxMenuItem(Menu3, ID_MENUITEM39, _("Width - Set window width in panels"), wxEmptyString, wxITEM_NORMAL);
	Menu3->Append(MenuItem4);
	MenuItem5 = new wxMenuItem(Menu3, ID_MENUITEM40, _("AM AGC - Turn AGC on and off for AM mode"), wxEmptyString, wxITEM_NORMAL);
	Menu3->Append(MenuItem5);
	MenuItem6 = new wxMenuItem(Menu3, ID_MENUITEM41, _("Window - Bring selected window to the front"), wxEmptyString, wxITEM_NORMAL);
	Menu3->Append(MenuItem6);
	MenuItem7 = new wxMenuItem(Menu3, ID_MENUITEM42, _("Reduce the Audio Gain slider, if strong signals are distorted"), wxEmptyString, wxITEM_NORMAL);
	Menu3->Append(MenuItem7);
	MenuItem8 = new wxMenuItem(Menu3, ID_MENUITEM43, _("Thumb wheel changes the start frequency"), wxEmptyString, wxITEM_NORMAL);
	Menu3->Append(MenuItem8);
	MenuItem9 = new wxMenuItem(Menu3, ID_MENUITEM44, _("Tune radio by clicking on frequency display"), wxEmptyString, wxITEM_NORMAL);
	Menu3->Append(MenuItem9);
	Menu5 = new wxMenu();
	MenuItem2 = new wxMenuItem(Menu5, ID_MENUITEM32, _("booyasdr.sf.net"), wxEmptyString, wxITEM_NORMAL);
	Menu5->Append(MenuItem2);
	MenuItem3 = new wxMenuItem(Menu5, ID_MENUITEM33, _("booyasdr@gmail.com"), wxEmptyString, wxITEM_NORMAL);
	Menu5->Append(MenuItem3);
	Menu2 = new wxMenuItem(Menu5, ID_MENUITEM34, _("MIT License 2017, Booya Corp."), wxEmptyString, wxITEM_NORMAL);
	Menu5->Append(Menu2);
	Menu3->Append(ID_MENUITEM35, _("About"), Menu5, wxEmptyString);
	MenuBar1->Append(Menu3, _("Help"));
	ColorCode = new wxMenu();
	MenuBar1->Append(ColorCode, _("Color Code"));
	SetMenuBar(MenuBar1);

	Connect(ID_SLIDER6,wxEVT_SCROLL_PAGEUP,(wxObjectEventFunction)&spectrumFrame::OnstartMhzSliderCmdScrollPageUp);
	Connect(ID_SLIDER6,wxEVT_SCROLL_PAGEDOWN,(wxObjectEventFunction)&spectrumFrame::OnstartMhzSliderCmdScrollPageDown);
	Connect(ID_SLIDER6,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&spectrumFrame::OnstartMhzSliderCmdScrollChanged);
	Connect(ID_SLIDER4,wxEVT_SCROLL_PAGEUP,(wxObjectEventFunction)&spectrumFrame::OngainSliderCmdScrollPageUp);
	Connect(ID_SLIDER4,wxEVT_SCROLL_PAGEDOWN,(wxObjectEventFunction)&spectrumFrame::OngainSliderCmdScrollPageDown);
	Connect(ID_SLIDER4,wxEVT_SCROLL_THUMBTRACK,(wxObjectEventFunction)&spectrumFrame::OngainSliderCmdScrollChanged);
	Connect(ID_SLIDER4,wxEVT_SCROLL_THUMBRELEASE,(wxObjectEventFunction)&spectrumFrame::OngainSliderCmdScrollChanged);
	Connect(ID_SLIDER3,wxEVT_SCROLL_PAGEUP,(wxObjectEventFunction)&spectrumFrame::OnbrightnessSliderCmdScrollPageUp);
	Connect(ID_SLIDER3,wxEVT_SCROLL_PAGEDOWN,(wxObjectEventFunction)&spectrumFrame::OnbrightnessSliderCmdScrollPageDown);
	Connect(ID_SLIDER3,wxEVT_SCROLL_THUMBTRACK,(wxObjectEventFunction)&spectrumFrame::OnbrightnessSliderCmdScrollChanged);
	Connect(ID_SLIDER3,wxEVT_SCROLL_THUMBRELEASE,(wxObjectEventFunction)&spectrumFrame::OnbrightnessSliderCmdScrollChanged);
	Connect(ID_SLIDER2,wxEVT_SCROLL_PAGEUP,(wxObjectEventFunction)&spectrumFrame::OnfineFrequencySliderCmdScrollPageUp);
	Connect(ID_SLIDER2,wxEVT_SCROLL_PAGEDOWN,(wxObjectEventFunction)&spectrumFrame::OnfineFrequencySliderCmdScrollPageDown);
	Connect(ID_SLIDER2,wxEVT_SCROLL_THUMBTRACK,(wxObjectEventFunction)&spectrumFrame::OnfineFrequencySliderCmdScrollChanged);
	Connect(ID_SLIDER2,wxEVT_SCROLL_THUMBRELEASE,(wxObjectEventFunction)&spectrumFrame::OnfineFrequencySliderCmdScrollChanged);
	Connect(ID_SLIDER1,wxEVT_SCROLL_LINEUP,(wxObjectEventFunction)&spectrumFrame::OnfrequencySliderCmdScrollLineUp);
	Connect(ID_SLIDER1,wxEVT_SCROLL_LINEDOWN,(wxObjectEventFunction)&spectrumFrame::OnfrequencySliderCmdScrollLineDown);
	Connect(ID_SLIDER1,wxEVT_SCROLL_PAGEUP,(wxObjectEventFunction)&spectrumFrame::OnfrequencySliderCmdScrollPageUp);
	Connect(ID_SLIDER1,wxEVT_SCROLL_PAGEDOWN,(wxObjectEventFunction)&spectrumFrame::OnfrequencySliderCmdScrollPageDown);
	Connect(ID_SLIDER1,wxEVT_SCROLL_THUMBTRACK,(wxObjectEventFunction)&spectrumFrame::OnfrequencySliderCmdScrollChanged);
	Connect(ID_SLIDER1,wxEVT_SCROLL_THUMBRELEASE,(wxObjectEventFunction)&spectrumFrame::OnfrequencySliderCmdScrollChanged);
	mainSpectrumPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&spectrumFrame::OnmainSpectrumPanelPaint,0,this);
	Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::OnSilentMenuSelected);
	Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::OnAMMenuSelected);
	Connect(ID_MENUITEM3,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::OnDSBMenuSelected);
	Connect(ID_MENUITEM4,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::OnLSBMenuSelected);
	Connect(ID_MENUITEM5,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::OnUSBMenuSelected);
	Connect(ID_MENUITEM6,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::OnCWMenuSelected);
	Connect(ID_MENUITEM31,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::OnQuitSelected);
	Connect(ID_MENUITEM7,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::Onkhpb125Selected);
	Connect(ID_MENUITEM8,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::Onkhpb250Selected);
	Connect(ID_MENUITEM9,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::Onkhpb500Selected);
	Connect(ID_MENUITEM10,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::Onkhpb1000Selected);
	Connect(ID_MENUITEM11,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::Onkhpb2000Selected);
	Connect(ID_MENUITEM49,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::Onnb4Selected);
	Connect(ID_MENUITEM50,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::Onnb5Selected);
	Connect(ID_MENUITEM12,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::Onnb6Selected);
	Connect(ID_MENUITEM13,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::Onnb7Selected);
	Connect(ID_NB8,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::Onnb8Selected);
	Connect(ID_MENUITEM15,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::Onnb9Selected);
	Connect(ID_MENUITEM16,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::Onnb10Selected);
	Connect(ID_MENUITEM17,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::Onnb11Selected);
	Connect(ID_MENUITEM18,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::Onnb12Selected);
	Connect(ID_MENUITEM19,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::Onnb13Selected);
	Connect(ID_MENUITEM20,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::Onnb14Selected);
	Connect(ID_MENUITEM21,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::Onnb15Selected);
	Connect(ID_MENUITEM22,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::Onnb16Selected);
	Connect(ID_MENUITEM14,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::Onnb17Selected);
	Connect(ID_MENUITEM27,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::Onnb18Selected);
	Connect(ID_MENUITEM23,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::OnWidthx1Selected);
	Connect(ID_MENUITEM24,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::OnWidthx2Selected);
	Connect(ID_MENUITEM45,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::OnMenu960Selected);
	Connect(ID_MENUITEM46,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::OnMenu1280Selected);
	Connect(ID_MENUITEM26,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::OnAMAGCoffSelected);
	Connect(ID_MENUITEM25,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::OnAMAGConSelected);
	Connect(ID_MENUITEM28,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::OnMenuSpectrumSelected);
	Connect(ID_MENUITEM29,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::OnMenuTimeSampleSelected);
	Connect(ID_MENUITEM30,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&spectrumFrame::OnMenuConsoleSelected);
	Connect(wxEVT_ERASE_BACKGROUND,(wxObjectEventFunction)&spectrumFrame::OnPanel1EraseBackground);
	//*)


    halfFftSp1024 = round(global.fs/2./1000./500.);  // init spectrum global
    khpb500->Check();

    NyquistKHz      = global.fs/1000/2;                     // NyQuist rate in kHz
    kHzPerTile      = NyquistKHz/halfFftSp1024;             // Max Frequency over number of twidth panels
    kHzPerPix       = float(kHzPerTile)/float(twidth);      // Panel kHz divided by twidth pixels per panel
    labelKHzInc     = kHzPerTile/LABEL_PER_TILE;            // label increment kHz
    nVertTileMax    = NyquistKHz/kHzPerTile/nHorTile;

// Initialize menu settings
    AGC.on = true;
    AMAGCon->Check();
    AGC.on = false;
    AMAGCoff->Check();

    nHorTile = 2;
    Widthx2->Check();
    nHorTile = 1;
    Widthx1->Check();

    nVertTile = 9; // number of panels vertically
    char str[128];
    sprintf(str,"%d",nVertTile);
    int mid = NPanelMenu->FindItem(str);
    NPanelMenu->Check(mid,true);

// Initialize control settings
	startMhzSlider->SetPageSize(1);
	startMhzSlider->SetLineSize(1);
	startMhzSlider->SetThumbLength(1);

 	startMhzSlider->SetTickFreq(4,0);
    frequencySlider->SetMax((int)NyquistKHz);
 	frequencySlider->SetTickFreq(1000,0);
    frequencySlider->SetValue(radioCntrl.AMkHz);

// Switch focus to startSlider for mouse wheel control
    gainSlider->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&spectrumFrame::OnPanel1MouseEnter,0,this);
    brightnessSlider->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&spectrumFrame::OnPanel1MouseEnter,0,this);
    fineFrequencySlider->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&spectrumFrame::OnPanel1MouseEnter,0,this);
    frequencySlider->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&spectrumFrame::OnPanel1MouseEnter,0,this);

// Initialize tile settings (a tile is twidth wide by 90 high)
    tileSize =  wxSize(twidth,90);
    windowSize = wxSize(2*tleftmargin + nHorTile*tileSize.x, menubar+wtopmargin+pheight*nVertTile+pbottommargin);

// create tiles
    for(int n = 0; n<N_VERT_TILE_MAX*N_HOR_TILE_MAX;n++) {
		ID_TILE[n] = wxNewId();
        Tile[n]= new wxPanel(mainSpectrumPanel, ID_TILE[n], wxPoint(tleftmargin,wtopmargin + n*pheight), tileSize,
                                    wxTAB_TRAVERSAL,_T("wxID_ANY"));
        Tile[n]->Connect(wxEVT_PAINT,(wxObjectEventFunction)&spectrumFrame::OnTilePaint,0,this);
        Tile[n]->Connect(wxEVT_ERASE_BACKGROUND,(wxObjectEventFunction)&spectrumFrame::OnEraseBackground,0,this);
        Tile[n]->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&spectrumFrame::OnTileMouseDown,0,this);
        Tile[n]->Connect(wxEVT_RIGHT_DOWN,(wxObjectEventFunction)&spectrumFrame::OnTileMouseDown,0,this);
    }

// arrange tiles for double window width
    if(nHorTile == 2) {
        for(int n = 0; n<N_VERT_TILE_MAX*N_HOR_TILE_MAX;n++) {
            int X = tleftmargin+(n%nHorTile)*tileSize.x;
            int Y = wtopmargin + (n/2)*pheight;
            Tile[n]->Move(X,Y);
        }
    }

// initialize frequency labels
    startMhzSlider->SetMax(halfFftSp1024/nHorTile-nVertTile);
    // create the frequency labels
    float kHz = 0;
    for(int n = 0; n < N_VERT_TILE_MAX*N_HOR_TILE_MAX*
                    LABEL_PER_TILE; n++,kHz+=labelKHzInc) {
		int pan = kHz/int(kHzPerTile*nHorTile);
		int x = int(float(int(kHz)%int(kHzPerTile*nHorTile))/kHzPerPix);
		ID_FREQUENCY_LABEL[n] = wxNewId();
		sprintf(s[n],"%d",(int)kHz);
        frequencyLabel[n] = new wxStaticText(mainSpectrumPanel, ID_FREQUENCY_LABEL[n],
                s[n], wxPoint(tleftmargin+x,wtopmargin + (pan+1)*pheight-13),
                                   wxSize(30,12), 0, _T("wxID_ANY"));
    }
    // position the frequency labels
    kHz = 0;
    for(int n = 0, kHz = 0; n < N_VERT_TILE_MAX*N_HOR_TILE_MAX*
                    LABEL_PER_TILE; n++,kHz+=labelKHzInc) {
        int vertPanel = kHz/int(kHzPerTile*nHorTile);
        int x = tleftmargin + int(float(int(kHz)%int(kHzPerTile*nHorTile))/kHzPerPix);
        int y = wtopmargin + (vertPanel+1)*pheight-13;
        frequencyLabel[n]->Move(wxPoint(x,y));
    }
// end initialize frequency labels

// initialize spImageBuffer, pImage, imageLineIdx
    int dataLength = tileSize.x*tileSize.y*2;
    dataLength = 1280*tileSize.y*2;
    spImageBuffer = (BYTE**) malloc(N_IMAGE_BUFFER_MAX*sizeof(BYTE *));
    pImage      = (BYTE**) malloc(N_IMAGE_BUFFER_MAX*sizeof(BYTE *));
    for( int n = 0; n < N_IMAGE_BUFFER_MAX; n ++){
        spImageBuffer[n] = (BYTE*) malloc(dataLength *3 +10);
        pImage[n] = spImageBuffer[n]; // initialize
    }
    imageLineIdx = 0;      // start at first line

    for (int o = 0; o <halfFftSp1024; o++) {
        for (int m = 0; m < tileSize.x*3; m+=3) {
            for (int n = 0; n < tileSize.y*3; n+=3) // light blue
            {
                spImageBuffer[o][m+n*tileSize.x  ] = 150;
                spImageBuffer[o][m+n*tileSize.x+1] = 255;
                spImageBuffer[o][m+n*tileSize.x+2] = 255;
            }
        }
    }
// end initialize spImageBuffer

   char title[256];
	sprintf(title,"BooyaSDR Plain ""%s %d MHz Spectrum Window",global.execName,(int)round(global.fs/1e6));
	SetTitle(title);

// setup console window
    SetConsoleCtrlHandler( (PHANDLER_ROUTINE) sighandler, TRUE );
    hWnd = GetConsoleWindow();

// setup time window
    TimeFrame = new timeFrame(this,ID_TIMEWINDOW);
    TimeFrame->Move(80,300);
    TimeFrame->Show();
	sprintf(title,"Booya %d MHz Time Sample Window",(int)round(global.fs/1e6));
	TimeFrame->SetTitle(title);

// setup this frequency spectrum window
    SetSize(windowSize);
    Move(10,0);
    Show();

// order window
    TimeFrame->Raise();
    TimeFrame->Update();
    SetWindowPos(hWnd,HWND_TOP,400,100,800,400,0); // Console window
	sprintf(title," Booya %d MHz Console",(int)round(global.fs/1e6));
    SetWindowTextA(hWnd,title); // Console window

    initMark(); // initialize the frequency range color markers and the color code menu

    mainSpectrumPanel->ClearBackground();
    mainSpectrumPanel->Refresh();
    Update();

    wxIcon icon(wxT("aaaa")); // get application icon and set window icon
    bool a = icon.IsOk();
    SetIcon(icon);

    initImageUpdateThread();
    sf = this;

}

spectrumFrame::~spectrumFrame() {
    global.run = false;
	Sleep(300);
	//(*Destroy(spectrumFrame)
	//*)
}

// main spectrum tile paint function, called to update any tile
void spectrumFrame::OnTilePaint(wxPaintEvent& event)
{
// find panel
    wxPanel *paintTile;
    BYTE *image;
    int n;
    bool found = false;
    int id = event.GetId(); // get the panel id
    for( n = 0; n<N_IMAGE_BUFFER_MAX;n++) { // find the panel by panel id
        if (ID_TILE[n] == id) {
            image = pImage[n];
            paintTile = Tile[n];
            found = true;
            break;
        }
    }
    if(!found) return;

// paint panel
    wxPaintDC dc( paintTile ); // paint the found panel
    wxImage pWxImg = wxImage(twidth,tileSize.y,image, TRUE);
    wxBitmap bmp = wxBitmap(pWxImg);
    dc.DrawBitmap(bmp, 0,0,false);

// find the tune frequency panel
//    int tunePanel = radioCntrl.AMkHz/kHzPerTile-firstBuffer;
    int tunePanel = radioCntrl.AMkHz/kHzPerTile;
    tunePanel -= firstBuffer;
    if( n == tunePanel ) {
        wxColor Magenta(255,0,255);
        wxPen myMagentaPen(Magenta,2,wxSOLID);
        dc.SetPen(myMagentaPen);
        int x = ((int)radioCntrl.AMkHz%kHzPerTile)/kHzPerPix;
        dc.DrawLine(x,0,x,100);
    }
    pWxImg.Destroy();
}

long tt = 0;
void spectrumFrame::initImageUpdateThread(void) {

    pthread_mutex_init(&mutexImageUpdate, NULL);
    pthread_mutex_lock(&mutexImageUpdate);

    int rc = pthread_create(&image_update_thread[tt], NULL, imageUpdateThread, (void *)&tt);
    if (rc) {
        printf("ERROR; return code from pthread_create() imageUpdateThreadf is %d\n", rc);
    }
}

rgb grey[256];
// Thread triggered by spectrumThreadf output
void *imageUpdateThread(void *arg)
{
    while (true) {
        pthread_mutex_lock(&mutexImageUpdate);
        if(global.pause)continue;
        if(!global.run)continue;

        unsigned short *plotdata = waterfall;   // get output of spectrumf()

        // update all the image buffers
        for( int o=0; o < halfFftSp1024; o++) {
        // record the last line
            rgb *imb =(rgb *) sf->spImageBuffer[o];
    //       for (int n = 0, m = sf->imageLineIdx *sf->twidth*3; n< sf->twidth ; m+=3, n++) {
           for (int n = 0, m = sf->imageLineIdx *sf->twidth ; n< sf->twidth ;  n++, m++) {
                int pix = (172-plotdata[n]-sf->brightness*2)*20;
                if(pix < 0) pix = 0;
                if(pix > 255) pix = 255;
                imb[m] = grey[pix];
            }
            // copy the last line for the second identical image in the buffer
            memcpy(&sf->spImageBuffer[o][(sf->imageLineIdx+sf->tileSize.y) *sf->twidth*3],
                &sf->spImageBuffer[o][sf->imageLineIdx *sf->twidth*3],  sf->twidth*3);
            // increment data source pointer for next buffer
            plotdata += sf->twidth;
        }
        ++sf->imageLineIdx %= sf->tileSize.y;
        // set the image pointer for painting the panel
        for( int o=0; o < sf->nVertTile*sf->nHorTile; o++) {
            sf->pImage[o] = &sf->spImageBuffer[o + sf->firstBuffer][sf->imageLineIdx *sf->twidth*3];
            sf->Tile[o]->Refresh(); // call paint
        }
    }
}

void spectrumFrame::OnTileMouseDown(wxMouseEvent& event) {
    // change the radio tune frequency based on mouse click on panel
    int id = event.GetId(); // get the panel id
    int n;
    for(n = 0; n<N_IMAGE_BUFFER_MAX;n++) { // find the panel by panel id
        if (ID_TILE[n] == id) break;
    }
    int x = event.GetX();
    radioCntrl.AMkHz = int(((n+firstBuffer)*kHzPerTile + x*kHzPerPix + float(radioTuneInc)/2)/radioTuneInc)*radioTuneInc;
    radioCntrl.ffHz = 0;
//    printf("panel %d, x %d, y %d AMkHz %f\n",n,x,y,radioCntrl.AMkHz);
    frequencySlider->SetValue(radioCntrl.AMkHz);
    fineFrequencySlider->SetValue(radioCntrl.ffHz);

    this->Refresh();
}

void spectrumFrame::OnmainSpectrumPanelPaint(wxPaintEvent& event) {

// paint the labels
    float kHz = firstBuffer*kHzPerTile;
    for(int m = 0; m < nHorTile*nVertTile*LABEL_PER_TILE; m++, kHz+=labelKHzInc) {
        sprintf(s[m],"%d",(int)kHz);
        if(kHz >= NyquistKHz) s[m][0] = '\0';
        frequencyLabel[m]->SetLabel( s[m] );
    }

    int kHzinc = kHzPerTile*nHorTile;
    wxPaintDC dcp1( mainSpectrumPanel );

// paint frequency color code
    wxColor Red(255,0,0);
    makeMark(&dcp1,&AMmark[0],&Red,kHzinc);

    wxColor Green(30,180,30);
    makeMark(&dcp1,&CBmark[0],&Green,kHzinc);

    wxColor Blue(0,0,255);
    for( int n = 0 ; n < HAMmarkLength; n++ )
        makeMark(&dcp1,&HAMmark[n],&Blue,kHzinc);
}


void spectrumFrame::initMark(void) {
    AMmark[0].kHzS = 530;
    AMmark[0].kHzE  = 1710;

    CBmark[0].kHzS = 26960;
    CBmark[0].kHzE  = 27410;

    HAMmark[ HAMmarkLength   ].kHzS = 1800;
    HAMmark[ HAMmarkLength++ ].kHzE = 2000;

    HAMmark[ HAMmarkLength   ].kHzS = 3500;
    HAMmark[ HAMmarkLength++ ].kHzE = 4000;

    HAMmark[ HAMmarkLength   ].kHzS = 5330;
    HAMmark[ HAMmarkLength++ ].kHzE = 5405;

    HAMmark[ HAMmarkLength   ].kHzS = 7000;
    HAMmark[ HAMmarkLength++ ].kHzE = 7300;

    HAMmark[ HAMmarkLength   ].kHzS = 10100;
    HAMmark[ HAMmarkLength++ ].kHzE = 10150;

    HAMmark[ HAMmarkLength   ].kHzS = 14000;
    HAMmark[ HAMmarkLength++ ].kHzE = 14350;

    HAMmark[ HAMmarkLength   ].kHzS = 18068;
    HAMmark[ HAMmarkLength++ ].kHzE = 18168;

    HAMmark[ HAMmarkLength   ].kHzS = 21000;
    HAMmark[ HAMmarkLength++ ].kHzE = 21450;

    HAMmark[ HAMmarkLength   ].kHzS = 24890;
    HAMmark[ HAMmarkLength++ ].kHzE = 24990;

    HAMmark[ HAMmarkLength   ].kHzS = 28000;
    HAMmark[ HAMmarkLength++ ].kHzE = 29700;

    rgb im[16*16];
    rgb red = { 255, 0, 0};
    rgb green = { 30, 180, 30};
    rgb blue = { 0, 0, 255};


    for(int n = 0; n < 256; n++) {
        grey[n].red   = n;
        grey[n].blue  = n;
        grey[n].green = n;
    }

    for(int n = 0; n < 16*16; n++ ) im[n] = red;
	AMColor = new wxMenuItem(ColorCode, wxID_ANY, _("AM"), wxEmptyString, wxITEM_NORMAL);
	AMColor->SetBitmap(wxBitmap(wxImage(16,16,(BYTE *)im,TRUE)));
	ColorCode->Append(AMColor);

    for(int n = 0; n < 16*16; n++ ) im[n] = blue;
	HAMColor = new wxMenuItem(ColorCode, wxID_ANY, _("HAM"), wxEmptyString, wxITEM_NORMAL);
	HAMColor->SetBitmap(wxBitmap(wxImage(16,16,(BYTE *)im,TRUE)));
	ColorCode->Append(HAMColor);

    for(int n = 0; n < 16*16; n++ ) im[n] = green;
	CBColor = new wxMenuItem(ColorCode, wxID_ANY, _("CB"), wxEmptyString, wxITEM_NORMAL);
	CBColor->SetBitmap(wxBitmap(wxImage(16,16,(BYTE *)im,TRUE)));
	ColorCode->Append(CBColor);
}

void spectrumFrame::makeMark(wxPaintDC *pdc, Mark *pmark, wxColor *pcolor, int kHzinc) {

    wxPen myPen(*pcolor,3,wxSOLID);
    pdc->SetPen(myPen);

    for (int kHzS = pmark->kHzS,kHzE = pmark->kHzE;
        kHzS < pmark->kHzE; kHzS = kHzE ) {
        kHzE = (kHzS/kHzinc + 1)*kHzinc;
        if(  kHzE > pmark->kHzE ) kHzE = pmark->kHzE;

        int vertPanelStart = kHzS/kHzinc - firstBuffer/nHorTile;
        int xstart = tleftmargin + int(float(kHzS%kHzinc)/kHzPerPix);
        int xend   = tleftmargin + int(float((kHzE-1)%kHzinc)/kHzPerPix);

        int y = wtopmargin + (vertPanelStart+1)*pheight-13 + 6;
        if(y < wtopmargin) continue;
        pdc->DrawLine(xstart,y,xend,y);
    }
}

// SLIDER START

#define SLIDER_DEBUG (1)
#define SLIDER_DEBUG (0)

void debugSlider(float dt, wxScrollEvent event, wxSlider *slider, float variable){
    printf("dt = %f\n",dt);
    printf("Event id %d type %d position %d\n",event.GetId(),event.GetEventType(),event.GetPosition());
    printf("Slider value %d\n",slider->GetValue());
    printf("Variable value %.2f\n",variable);
}

 float dckick = .15;

// Start Frequency Slider   // Start Frequency Slider   // Start Frequency Slider
    timeval last_tv;
void spectrumFrame::OnfrequencySliderCmdScrollChanged(wxScrollEvent& event)
{
    timeval now_tv;
    gettimeofday(&now_tv,NULL);
    double dt = double(now_tv.tv_sec-last_tv.tv_sec)+
                double(now_tv.tv_usec-last_tv.tv_usec)/1000000.0;
    last_tv = now_tv;

    radioCntrl.AMkHz = event.GetPosition();

    int pageSize = frequencySlider->GetPageSize();
    radioCntrl.AMkHz = (int(radioCntrl.AMkHz)/pageSize)*pageSize;
    frequencySlider->SetValue(radioCntrl.AMkHz);

// zero fine frequency
    radioCntrl.ffHz = 0;
    fineFrequencySlider->SetValue(radioCntrl.ffHz);
    this->Refresh();

    if(SLIDER_DEBUG) debugSlider(dt,event,frequencySlider,radioCntrl.AMkHz);
}

void spectrumFrame::OnfrequencySliderCmdScrollPageUp(wxScrollEvent& event)
{
    timeval now_tv;
    gettimeofday(&now_tv,NULL);
    double dt = double(now_tv.tv_sec-last_tv.tv_sec)+
                double(now_tv.tv_usec-last_tv.tv_usec)/1000000.0;
    last_tv = now_tv;
    if (dt < dckick)
        frequencySlider->SetValue(radioCntrl.AMkHz);
    else
        radioCntrl.AMkHz-=frequencySlider->GetPageSize();

    int maxi = frequencySlider->GetMax();
    int mini = frequencySlider->GetMin();
    if(radioCntrl.AMkHz > maxi) radioCntrl.AMkHz = maxi;
    if(radioCntrl.AMkHz < mini) radioCntrl.AMkHz = mini;

// zero fine frequency
    radioCntrl.ffHz = 0;
    fineFrequencySlider->SetValue(radioCntrl.ffHz);
    this->Refresh();

    if(SLIDER_DEBUG) debugSlider(dt,event,frequencySlider,radioCntrl.AMkHz);
}

void spectrumFrame::OnfrequencySliderCmdScrollPageDown(wxScrollEvent& event)
{
    timeval now_tv;
    gettimeofday(&now_tv,NULL);
    double dt = double(now_tv.tv_sec-last_tv.tv_sec)+
                double(now_tv.tv_usec-last_tv.tv_usec)/1000000.0;
    last_tv = now_tv;
    if (dt < dckick)
       frequencySlider->SetValue(radioCntrl.AMkHz);
    else
        radioCntrl.AMkHz+=frequencySlider->GetPageSize();

    int maxi = frequencySlider->GetMax();
    int mini = frequencySlider->GetMin();
    if(radioCntrl.AMkHz > maxi) radioCntrl.AMkHz = maxi;
    if(radioCntrl.AMkHz < mini) radioCntrl.AMkHz = mini;

// zero fine frequency
    radioCntrl.ffHz = 0;
    fineFrequencySlider->SetValue(radioCntrl.ffHz);
    this->Refresh();

    if(SLIDER_DEBUG) debugSlider(dt,event,frequencySlider,radioCntrl.AMkHz);
}

void spectrumFrame::OnfrequencySliderCmdScrollLineUp(wxScrollEvent& event)
{ printf("line up\n"); }

void spectrumFrame::OnfrequencySliderCmdScrollLineDown(wxScrollEvent& event)
{ printf("line down\n");}

// End Frequency Slider         // End Frequency Slider         // End Frequency Slider
// Start Fine Frequency Slider  // Start Fine Frequency Slider  // Start Fine Frequency Slider

void spectrumFrame::OnfineFrequencySliderCmdScrollChanged(wxScrollEvent& event) {
    radioCntrl.ffHz = event.GetPosition();

    if(SLIDER_DEBUG) debugSlider(-1,event,brightnessSlider,radioCntrl.ffHz);
}

void spectrumFrame::OnfineFrequencySliderCmdScrollPageUp(wxScrollEvent& event)
{
    timeval now_tv;
    gettimeofday(&now_tv,NULL);
    double dt = double(now_tv.tv_sec-last_tv.tv_sec)+
                double(now_tv.tv_usec-last_tv.tv_usec)/1000000.0;
    last_tv = now_tv;
    if (dt < dckick)
        fineFrequencySlider->SetValue(radioCntrl.ffHz);
    else
        radioCntrl.ffHz--;

    int mini = fineFrequencySlider->GetMin();
    if(radioCntrl.ffHz < mini) radioCntrl.ffHz = mini;
    fineFrequencySlider->SetValue(radioCntrl.ffHz);

    if(SLIDER_DEBUG) debugSlider(dt,event,fineFrequencySlider,radioCntrl.ffHz);
}

void spectrumFrame::OnfineFrequencySliderCmdScrollPageDown(wxScrollEvent& event)
{
    timeval now_tv;
    gettimeofday(&now_tv,NULL);
    double dt = double(now_tv.tv_sec-last_tv.tv_sec)+
                double(now_tv.tv_usec-last_tv.tv_usec)/1000000.0;
    last_tv = now_tv;
    if (dt < dckick)
        fineFrequencySlider->SetValue(radioCntrl.ffHz);
    else
        radioCntrl.ffHz++;

    int maxi = fineFrequencySlider->GetMax();
    if(radioCntrl.ffHz > maxi) radioCntrl.ffHz = maxi;
    fineFrequencySlider->SetValue(radioCntrl.ffHz);

    if(SLIDER_DEBUG) debugSlider(dt,event,fineFrequencySlider,radioCntrl.ffHz);
}

// End Fine Frequency Slider   // End Fine Frequency Slider   // End Fine Frequency Slider
// Start Audio Gain Slider     // Start Audio Gain Slider     // Start Audio Gain Slider

void spectrumFrame::OngainSliderCmdScrollChanged(wxScrollEvent& event) {
    radioCntrl.gain = event.GetPosition();

    if(SLIDER_DEBUG) debugSlider(-1,event,gainSlider,radioCntrl.gain);
}

void spectrumFrame::OngainSliderCmdScrollPageUp(wxScrollEvent& event) {
    timeval now_tv;
    gettimeofday(&now_tv,NULL);
    double dt = double(now_tv.tv_sec-last_tv.tv_sec)+
                double(now_tv.tv_usec-last_tv.tv_usec)/1000000.0;
    last_tv = now_tv;
    if (dt < dckick)
        gainSlider->SetValue(radioCntrl.gain);
    else
        radioCntrl.gain--;

    int mini = gainSlider->GetMin();
    if(radioCntrl.gain < mini) radioCntrl.gain = mini;
    gainSlider->SetValue(radioCntrl.gain);
//    scaleRadiof(radioCntrl.gain);

    if(SLIDER_DEBUG) debugSlider(dt,event,gainSlider,radioCntrl.gain);
}

void spectrumFrame::OngainSliderCmdScrollPageDown(wxScrollEvent& event) {
    timeval now_tv;
    gettimeofday(&now_tv,NULL);
    double dt = double(now_tv.tv_sec-last_tv.tv_sec)+
                double(now_tv.tv_usec-last_tv.tv_usec)/1000000.0;
    last_tv = now_tv;
    if (dt < dckick)
        gainSlider->SetValue(radioCntrl.gain);
    else
        radioCntrl.gain++;

    int maxi = gainSlider->GetMax();
    if(radioCntrl.gain > maxi) radioCntrl.gain = maxi;
    gainSlider->SetValue(radioCntrl.gain);
//    scaleRadiof(radioCntrl.gain);

    if(SLIDER_DEBUG) debugSlider(dt,event,gainSlider,radioCntrl.gain);
}

//  End Audio Gain Slider        // End Audio Gain Slider        // End Audio Gain Slider
//  Start Brightness Slider      // Start Brightness Slider      // Start Brightness Slider

void spectrumFrame::OnbrightnessSliderCmdScrollChanged(wxScrollEvent& event)
{
    brightness = brightnessSlider->GetValue();

    if(SLIDER_DEBUG) debugSlider(0,event,brightnessSlider,brightness);
}

void spectrumFrame::OnbrightnessSliderCmdScrollPageUp(wxScrollEvent& event)
{
    timeval now_tv;
    gettimeofday(&now_tv,NULL);
    double dt = double(now_tv.tv_sec-last_tv.tv_sec)+
                double(now_tv.tv_usec-last_tv.tv_usec)/1000000.0;
    last_tv = now_tv;
    if (dt < dckick)
        brightnessSlider->SetValue(brightness);
    else
        brightness--;

    int mini = brightnessSlider->GetMin();
    if(brightness < mini) brightness = mini;
    brightnessSlider->SetValue(brightness);

    if(SLIDER_DEBUG) debugSlider(dt,event,brightnessSlider,brightness);
}

void spectrumFrame::OnbrightnessSliderCmdScrollPageDown(wxScrollEvent& event) {

    timeval now_tv;
    gettimeofday(&now_tv,NULL);
    double dt = double(now_tv.tv_sec-last_tv.tv_sec)+
                double(now_tv.tv_usec-last_tv.tv_usec)/1000000.0;
    last_tv = now_tv;
    if (dt < dckick)
        brightnessSlider->SetValue(brightness);
    else
        brightness++;

    int maxi = brightnessSlider->GetMax();
    if(brightness > maxi) brightness = maxi;
    brightnessSlider->SetValue(brightness);

    if(SLIDER_DEBUG) debugSlider(dt,event,brightnessSlider,brightness);
}

//  End Frequency Slider     //  End Frequency Slider     //  End Frequency Slider
//  Start Start MHz Slider   //  Start Start MHz  Slider  //  Start Start MHz Slider

void spectrumFrame::OnstartMhzSliderCmdScrollChanged(wxScrollEvent& event) {
    firstBuffer = nHorTile*event.GetPosition();
    char s[128];
    sprintf(s,"%.1f",float(firstBuffer*kHzPerTile)/1000);
    startMHzLabel->SetLabel(s);
//    printf("Changed, event type %d\n",event.GetEventType());
    mainSpectrumPanel->Refresh();
}

void spectrumFrame::OnstartMhzSliderCmdScrollPageUp(wxScrollEvent& event) {
    firstBuffer -= nHorTile;
    int mini = startMhzSlider->GetMin();
    if(firstBuffer < mini*nHorTile) firstBuffer = mini*nHorTile;
    startMhzSlider->SetValue(firstBuffer/nHorTile);
    char s[128];
    sprintf(s,"%.1f",float(firstBuffer*kHzPerTile)/1000);
    startMHzLabel->SetLabel(s);
//    printf("page up, event type %d\n",event.GetEventType());
    mainSpectrumPanel->Refresh();
}

void spectrumFrame::OnstartMhzSliderCmdScrollPageDown(wxScrollEvent& event) {
    firstBuffer += nHorTile;
    int maxi = startMhzSlider->GetMax();
    if(firstBuffer > maxi*nHorTile) firstBuffer = maxi*nHorTile;
    startMhzSlider->SetValue(firstBuffer/nHorTile);
    char s[128];
    sprintf(s,"%.1f",float(firstBuffer*kHzPerTile)/1000);
    startMHzLabel->SetLabel(s);
//    printf("page down, event type %d\n",event.GetEventType());
    mainSpectrumPanel->Refresh();
}
//  End Start MHz Slider   //  End Start MHz  Slider  //  End Start MHz Slider

// SLIDER END

void spectrumFrame::OnSilentMenuSelected(wxCommandEvent& event) {
        radioCntrl.mode = Silent;
        radioTurnOff();
}

void spectrumFrame::OnAMMenuSelected(wxCommandEvent& event) {
        radioCntrl.mode = AM;
        radioTurnOn();
        this->radioTuneInc = AMTuneInc;
        this->frequencySlider->SetPageSize(AMTuneInc);
        this->frequencySlider->SetLineSize(AMTuneInc);
        radioCntrl.AMkHz = round(radioCntrl.AMkHz/AMTuneInc)*AMTuneInc;
        frequencySlider->SetValue(radioCntrl.AMkHz);
        if ( gainSlider->GetValue() > -2) { // initialize AM gain at -2
            radioCntrl.gain = -2;
            gainSlider->SetValue(radioCntrl.gain);
//            scaleRadiof(radioCntrl.gain);
        }
}

void spectrumFrame::OnDSBMenuSelected(wxCommandEvent& event) {
        radioCntrl.mode = DSB;
        radioTurnOn();
        this->radioTuneInc = AMTuneInc;
        this->frequencySlider->SetPageSize(AMTuneInc);
        this->frequencySlider->SetLineSize(AMTuneInc);
        radioCntrl.AMkHz = round(radioCntrl.AMkHz/AMTuneInc)*AMTuneInc;
        frequencySlider->SetValue(radioCntrl.AMkHz);
}

void spectrumFrame::OnLSBMenuSelected(wxCommandEvent& event) {
        radioCntrl.mode = LSB;
        radioTurnOn();
        this->radioTuneInc = 1;
        this->frequencySlider->SetPageSize(1);
        this->frequencySlider->SetLineSize(1);
}

void spectrumFrame::OnUSBMenuSelected(wxCommandEvent& event) {
        radioCntrl.mode = USB;
        radioTurnOn();
        this->radioTuneInc = 1;
        this->frequencySlider->SetPageSize(1);
        this->frequencySlider->SetLineSize(1);
}

void spectrumFrame::OnCWMenuSelected(wxCommandEvent& event) {
        radioCntrl.mode = CW;
        radioTurnOn();
        this->radioTuneInc = 1;
        this->frequencySlider->SetPageSize(1);
        this->frequencySlider->SetLineSize(1);
}

void spectrumFrame::changeNVertTile(int newNVertTile) {
// limit number of veritical panels based on frequency resolution and display width
    nVertTileMax = NyquistKHz/kHzPerTile/nHorTile;
    if(newNVertTile > nVertTileMax) newNVertTile = nVertTileMax;
    nVertTile = newNVertTile;
// reset NbarMenu incase nVertTile changed
    char str[128];
    sprintf(str,"%d",nVertTile);
    int mid = NPanelMenu->FindItem(str);
    NPanelMenu->Check(mid,true);
// limit startMhzSlider based on maximum possible
    int firstBufferMax = halfFftSp1024/nHorTile-nVertTile;
    if(0 > firstBufferMax) firstBufferMax = 0;
    if(firstBuffer > firstBufferMax*nHorTile) firstBuffer = firstBufferMax*nHorTile;
// reset startMhzSlider in case anything changed
    startMhzSlider->SetValue(firstBuffer/nHorTile);
    startMhzSlider->SetMax(firstBufferMax);
// reset window size based on nVertTile
    windowSize.y = menubar+wtopmargin+pheight*nVertTile+pbottommargin;

    SetMaxSize(windowSize);
    SetSize(windowSize);
// reset startMHzLabel in case of change
    char s[128];
    sprintf(s,"%.1f",float(firstBuffer*kHzPerTile)/1000);
    startMHzLabel->SetLabel(s);

    mainSpectrumPanel->Refresh();
}

void spectrumFrame::Onnb4Selected(wxCommandEvent& event){ changeNVertTile(4); }
void spectrumFrame::Onnb5Selected(wxCommandEvent& event){ changeNVertTile(5); }
void spectrumFrame::Onnb6Selected(wxCommandEvent& event) { changeNVertTile(6); }
void spectrumFrame::Onnb7Selected(wxCommandEvent& event) { changeNVertTile(7); }
void spectrumFrame::Onnb8Selected(wxCommandEvent& event) { changeNVertTile(8); }
void spectrumFrame::Onnb9Selected(wxCommandEvent& event) { changeNVertTile(9); }
void spectrumFrame::Onnb10Selected(wxCommandEvent& event) { changeNVertTile(10); }
void spectrumFrame::Onnb11Selected(wxCommandEvent& event) { changeNVertTile(11); }
void spectrumFrame::Onnb12Selected(wxCommandEvent& event) { changeNVertTile(12); }
void spectrumFrame::Onnb13Selected(wxCommandEvent& event) { changeNVertTile(13); }
void spectrumFrame::Onnb14Selected(wxCommandEvent& event) { changeNVertTile(14); }
void spectrumFrame::Onnb15Selected(wxCommandEvent& event) { changeNVertTile(15); }
void spectrumFrame::Onnb16Selected(wxCommandEvent& event) { changeNVertTile(16); }
void spectrumFrame::Onnb17Selected(wxCommandEvent& event) { changeNVertTile(17); }
void spectrumFrame::Onnb18Selected(wxCommandEvent& event) { changeNVertTile(18); }

// change focus to startMhzSlider when leaving other window
// so that mouse wheel controls startMhzSlider by default
void spectrumFrame::OnPanel1MouseEnter(wxMouseEvent& event) {
    wxWindow *window = FindFocus(); // find window or control with focus
    if( (gainSlider == window ) ||
            (frequencySlider == window ) ||
            (fineFrequencySlider == window ) ||
            (brightnessSlider == window ) )

    startMhzSlider->SetFocus();
}

void spectrumFrame::Onkhpb125Selected(wxCommandEvent& event) { OnkHzPerTile(125.); }
void spectrumFrame::Onkhpb250Selected(wxCommandEvent& event) { OnkHzPerTile(250.); }
void spectrumFrame::Onkhpb500Selected(wxCommandEvent& event) { OnkHzPerTile(500.); }
void spectrumFrame::Onkhpb1000Selected(wxCommandEvent& event) { OnkHzPerTile(1000.); }
void spectrumFrame::Onkhpb2000Selected(wxCommandEvent& event) { OnkHzPerTile(2000.); }

void spectrumFrame::OnkHzPerTile(float resolutionkHzper1024) {

    global.pause = true;
    Sleep(200); // wait for paused threads to finish

    int halfFft = round(global.fs/2./1000./resolutionkHzper1024);
    sizeSpectrumf(halfFft, twidth); // halfFftSp1024 is set to halfFft in this function

    imageLineIdx = 0;      // start at top

    for (int o = 0; o <halfFftSp1024; o++) {    // reset panel color to light blue
        for (int m = 0; m < tileSize.x*3; m+=3) {
            for (int n = 0; n < tileSize.y*3; n+=3)
            {
                spImageBuffer[o][m+n*tileSize.x  ] = 150;
                spImageBuffer[o][m+n*tileSize.x+1] = 255;
                spImageBuffer[o][m+n*tileSize.x+2] = 255;
            }
        }
    }
// calculate firstBufferMax and limit firstBuffer to it
    firstBuffer = nHorTile*startMhzSlider->GetValue();
    int firstBufferMax = halfFftSp1024/nHorTile-nVertTile;
    if(0 > firstBufferMax) firstBufferMax = 0;
    if(firstBuffer > firstBufferMax*nHorTile) firstBuffer = firstBufferMax*nHorTile;
// calculate firstBufferMax and limit firstBuffer to it
    startMhzSlider->SetValue(firstBuffer/nHorTile);
    startMhzSlider->SetMax(firstBufferMax);
// recalculate parameters based on the new Fft size as held in halfFftSp1024
//    kHzPerTile = global.fs/1000/halfFftSp1024/2;
    kHzPerTile = resolutionkHzper1024;
    labelKHzInc = float(kHzPerTile)/float(LABEL_PER_TILE);
    kHzPerPix = float(kHzPerTile)/float(twidth);
// limit number of veritical panels
    changeNVertTile(nVertTile);

    global.pause = false; // resume processing
}

void spectrumFrame::OnWidthx1Selected(wxCommandEvent& event) { changeNHorTile(1); Refresh(); }
void spectrumFrame::OnWidthx2Selected(wxCommandEvent& event) { changeNHorTile(2); Refresh(); }

void spectrumFrame::changeNHorTile(int newNHorTile) {
    nHorTile = newNHorTile;
// rearrange the panels
    for(int n = 0; n<N_VERT_TILE_MAX*N_HOR_TILE_MAX;n++) {
        int X = tleftmargin+(n%nHorTile)*tileSize.x;
        int Y = wtopmargin + (n/nHorTile)*pheight;
        Tile[n]->Move(X,Y);
    }
// rearrange frequency labels
    float kHz = 0;
    for(int n = 0; n < N_VERT_TILE_MAX*N_HOR_TILE_MAX*
                    LABEL_PER_TILE; n++,kHz+=labelKHzInc) {
        int panel = kHz/int(kHzPerTile*nHorTile);
        int x = tleftmargin+ int(float(int(kHz)%int(kHzPerTile*nHorTile))/kHzPerPix);
        int y = wtopmargin + (panel+1)*pheight-13;
        sprintf(s[n],"%d",kHz);
        frequencyLabel[n]->Move(wxPoint(x,y));
    }
// calculate firstBufferMax and limit firstBuffer to it
    firstBuffer = nHorTile*startMhzSlider->GetValue();
    int firstBufferMax = halfFftSp1024/nHorTile-nVertTile;
    if( firstBufferMax < 0) firstBufferMax = 0;
    if(firstBuffer > firstBufferMax*nHorTile) firstBuffer = firstBufferMax*nHorTile;
    if(firstBuffer < 0) firstBuffer = 0;
// calculate firstBufferMax and limit firstBuffer to it
    startMhzSlider->SetValue(firstBuffer/nHorTile);
    startMhzSlider->SetMax(firstBufferMax);

    char s[128];
    sprintf(s,"%.1f",float(firstBuffer*kHzPerTile)/1000);
    startMHzLabel->SetLabel(s);

// limit numbsizeSpectrumfer of veritical panels
    changeNVertTile(nVertTile);

// resize window
    windowSize.x = 2*tleftmargin + nHorTile*tileSize.x;

    SetMaxSize(windowSize);
    SetSize(windowSize);
}

// turn AM agc on and off
void spectrumFrame::OnAMAGCoffSelected(wxCommandEvent& event)
{    AGC.on = false; }
void spectrumFrame::OnAMAGConSelected(wxCommandEvent& event)
{    AGC.on = true; }

void spectrumFrame::OnQuitSelected(wxCommandEvent& event) { Destroy(); }
void spectrumFrame::OnMenuSpectrumSelected(wxCommandEvent& event) {
    Raise();
    Update();
}

void spectrumFrame::OnMenuTimeSampleSelected(wxCommandEvent& event) {
    TimeFrame->Raise();
    TimeFrame->Update();
}

void spectrumFrame::OnMenuConsoleSelected(wxCommandEvent& event) {
    SetWindowPos(hWnd,HWND_TOP,1100,100,800,400,0); // Console window
}

// these null function help reduce display flicker
void spectrumFrame::OnEraseBackground(wxEraseEvent& event){}
void spectrumFrame::OnPanel1EraseBackground(wxEraseEvent& event){}

void spectrumFrame::OnMenu960Selected(wxCommandEvent& event)
{
    global.pause = true;
    Sleep(200); // wait for paused threads to finish

    int halfFft = round(global.fs/2./1000./kHzPerTile);
    twidth = 960;
    sizeSpectrumf(halfFft, twidth); // halfFftSp1024 is set to halfFft in this function
    windowSize.x = 960;
    SetSize(windowSize);
    imageLineIdx = 0;      // start at top

    for (int o = 0; o <halfFftSp1024; o++) {    // reset panel color to light blue
        for (int m = 0; m < tileSize.x*3; m+=3) {
            for (int n = 0; n < tileSize.y*3; n+=3)
            {
                spImageBuffer[o][m+n*tileSize.x  ] = 150;
                spImageBuffer[o][m+n*tileSize.x+1] = 255;
                spImageBuffer[o][m+n*tileSize.x+2] = 255;
            }
        }
    }
// calculate firstBufferMax and limit firstBuffer to it
    firstBuffer = nHorTile*startMhzSlider->GetValue();
    int firstBufferMax = halfFftSp1024/nHorTile-nVertTile;
    if(0 > firstBufferMax) firstBufferMax = 0;
    if(firstBuffer > firstBufferMax*nHorTile) firstBuffer = firstBufferMax*nHorTile;
// calculate firstBufferMax and limit firstBuffer to it
    startMhzSlider->SetValue(firstBuffer/nHorTile);
    startMhzSlider->SetMax(firstBufferMax);
// recalculate parameters based on the new Fft size as held in halfFftSp1024
//    kHzPerTile = global.fs/1000/halfFftSp1024/2;
//    kHzPerTile = resolutionkHzper1024;
    labelKHzInc = float(kHzPerTile)/float(LABEL_PER_TILE);
    kHzPerPix = float(kHzPerTile)/float(twidth);
// limit number of veritical panels
    changeNVertTile(nVertTile);
    for(int n = 0; n<N_VERT_TILE_MAX*N_HOR_TILE_MAX;n++) {
        wxSize s = Tile[n]->GetSize();
        s.x = twidth;
        Tile[n]->SetSize(s);
    }

    global.pause = false; // resume processing

}

void spectrumFrame::OnMenu1280Selected(wxCommandEvent& event)
{
    global.pause = true;
    Sleep(200); // wait for paused threads to finish

    int halfFft = round(global.fs/2./1000./kHzPerTile);
    twidth = 1280;
    sizeSpectrumf(halfFft, twidth); // halfFftSp1024 is set to halfFft in this function
    windowSize.x = 1280;
    SetSize(windowSize);
    imageLineIdx = 0;      // start at top

    for (int o = 0; o <halfFftSp1024; o++) {    // reset panel color to light blue
        for (int m = 0; m < tileSize.x*3; m+=3) {
            for (int n = 0; n < tileSize.y*3; n+=3)
            {
                spImageBuffer[o][m+n*tileSize.x  ] = 150;
                spImageBuffer[o][m+n*tileSize.x+1] = 255;
                spImageBuffer[o][m+n*tileSize.x+2] = 255;
            }
        }
    }
// calculate firstBufferMax and limit firstBuffer to it
    firstBuffer = nHorTile*startMhzSlider->GetValue();
    int firstBufferMax = halfFftSp1024/nHorTile-nVertTile;
    if(0 > firstBufferMax) firstBufferMax = 0;
    if(firstBuffer > firstBufferMax*nHorTile) firstBuffer = firstBufferMax*nHorTile;
// calculate firstBufferMax and limit firstBuffer to it
    startMhzSlider->SetValue(firstBuffer/nHorTile);
    startMhzSlider->SetMax(firstBufferMax);
// recalculate parameters based on the new Fft size as held in halfFftSp1024
//    kHzPerTile = global.fs/1000/halfFftSp1024/2;
//    kHzPerTile = resolutionkHzper1024;
    labelKHzInc = float(kHzPerTile)/float(LABEL_PER_TILE);
    kHzPerPix = float(kHzPerTile)/float(twidth);
// limit number of veritical panels
    changeNVertTile(nVertTile);
    for(int n = 0; n<N_VERT_TILE_MAX*N_HOR_TILE_MAX;n++) {
        wxSize s = Tile[n]->GetSize();
        s.x = twidth;
        Tile[n]->SetSize(s);
    }


    global.pause = false; // resume processing

}
