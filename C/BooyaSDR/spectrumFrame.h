// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

#ifndef SPECTRUMFRAME_H
#define SPECTRUMFRAME_H

#include "timeFrame.h"

typedef struct {
        int kHzS,kHzE;
        } Mark;

    typedef struct {
        unsigned char red;
        unsigned char green;
        unsigned char blue;
    } rgb;

#ifndef WX_PRECOMP
	//(*HeadersPCH(spectrumFrame)
	#include <wx/stattext.h>
	#include <wx/menu.h>
	#include <wx/slider.h>
	#include <wx/panel.h>
	#include <wx/frame.h>
	//*)
#endif
//(*Headers(spectrumFrame)
//*)
class spectrumFrame: public wxFrame
{
	public:

		spectrumFrame(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~spectrumFrame();

		//(*Declarations(spectrumFrame)
		wxMenuItem* khpb250;
		wxMenuItem* nb11;
		wxMenuItem* MenuItem8;
		wxSlider* frequencySlider;
		wxMenuItem* nb12;
		wxMenuItem* Menu7;
		wxMenuItem* MenuItem7;
		wxMenuItem* nb5;
		wxSlider* startMhzSlider;
		wxMenuItem* MenuTimeSample;
		wxMenuItem* MenuSpectrum;
		wxMenuItem* nb16;
		wxMenuItem* MenuItem5;
		wxMenuItem* Menu2;
		wxMenuItem* nb13;
		wxStaticText* StaticText2;
		wxMenuItem* MenuItem2;
		wxMenuItem* AMAGCon;
		wxMenu* NPanelMenu;
		wxMenuItem* nb7;
		wxMenu* Menu3;
		wxStaticText* StaticText6;
		wxMenuItem* AMAGCoff;
		wxMenuItem* MenuItem1;
		wxMenuItem* MenuItem4;
		wxMenu* AMAGC;
		wxMenuItem* MenuItem11;
		wxMenuItem* USBMenu;
		wxMenuItem* AMMenu;
		wxPanel* mainSpectrumPanel;
		wxMenu* ColorCode;
		wxStaticText* StaticText1;
		wxMenuItem* MenuConsole;
		wxStaticText* StaticText3;
		wxStaticText* startMHzLabel;
		wxMenu* Menu1;
		wxMenuItem* MenuItem10;
		wxMenu* kHzPanelBar;
		wxSlider* fineFrequencySlider;
		wxMenuItem* DSBMenu;
		wxMenuItem* MenuItem12;
		wxMenuItem* MenuItem3;
		wxMenuItem* nb8;
		wxMenu* radioMode;
		wxMenuItem* CWMenu;
		wxMenuItem* khpb1000;
		wxMenuItem* khpb2000;
		wxSlider* gainSlider;
		wxMenuItem* Menu4;
		wxMenuItem* nb4;
		wxMenuItem* Widthx1;
		wxMenuItem* nb15;
		wxMenuItem* MenuItem6;
		wxMenuItem* nb9;
		wxMenuItem* nb17;
		wxMenuItem* khpb125;
		wxMenuBar* MenuBar1;
		wxMenuItem* nb14;
		wxMenuItem* Widthx2;
		wxMenuItem* nb6;
		wxMenu* Menu6;
		wxMenuItem* nb18;
		wxMenuItem* MenuItem9;
		wxMenuItem* khpb500;
		wxSlider* brightnessSlider;
		wxStaticText* StaticText4;
		wxMenuItem* MenuQuit;
		wxMenuItem* LSBMenu;
		wxMenuItem* nb10;
		wxMenu* Menu5;
		wxMenuItem* SilentMenu;
		//*)

	protected:

		//(*Identifiers(spectrumFrame)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT6;
		static const long ID_SLIDER6;
		static const long ID_STATICTEXT7;
		static const long ID_SLIDER4;
		static const long ID_SLIDER3;
		static const long ID_SLIDER2;
		static const long ID_SLIDER1;
		static const long ID_SPFRPANEL1;
		static const long ID_MENUITEM1;
		static const long ID_MENUITEM2;
		static const long ID_MENUITEM3;
		static const long ID_MENUITEM4;
		static const long ID_MENUITEM5;
		static const long ID_MENUITEM6;
		static const long ID_MENUITEM31;
		static const long ID_MENUITEM48;
		static const long ID_MENUITEM7;
		static const long ID_MENUITEM8;
		static const long ID_MENUITEM9;
		static const long ID_MENUITEM10;
		static const long ID_MENUITEM11;
		static const long ID_MENUITEM49;
		static const long ID_MENUITEM50;
		static const long ID_MENUITEM12;
		static const long ID_MENUITEM13;
		static const long ID_NB8;
		static const long ID_MENUITEM15;
		static const long ID_MENUITEM16;
		static const long ID_MENUITEM17;
		static const long ID_MENUITEM18;
		static const long ID_MENUITEM19;
		static const long ID_MENUITEM20;
		static const long ID_MENUITEM21;
		static const long ID_MENUITEM22;
		static const long ID_MENUITEM14;
		static const long ID_MENUITEM27;
		static const long ID_MENUITEM23;
		static const long ID_MENUITEM24;
		static const long ID_MENUITEM45;
		static const long ID_MENUITEM46;
		static const long ID_MENUITEM26;
		static const long ID_MENUITEM25;
		static const long ID_MENUITEM28;
		static const long ID_MENUITEM29;
		static const long ID_MENUITEM30;
		static const long ID_MENUITEM36;
		static const long ID_MENUITEM38;
		static const long ID_MENUITEM37;
		static const long ID_MENUITEM39;
		static const long ID_MENUITEM40;
		static const long ID_MENUITEM41;
		static const long ID_MENUITEM42;
		static const long ID_MENUITEM43;
		static const long ID_MENUITEM44;
		static const long ID_MENUITEM32;
		static const long ID_MENUITEM33;
		static const long ID_MENUITEM34;
		static const long ID_MENUITEM35;
		//*)

	private:

		//(*Handlers(spectrumFrame)
		void OnstartMhzSliderCmdScrollChanged(wxScrollEvent& event);
		void OnPanel1EraseBackground(wxEraseEvent& event);
		void OngainSliderCmdScrollChanged(wxScrollEvent& event);
		void OnSilentMenuSelected(wxCommandEvent& event);
		void OnAMMenuSelected(wxCommandEvent& event);
		void OnDSBMenuSelected(wxCommandEvent& event);
		void OnLSBMenuSelected(wxCommandEvent& event);
		void OnUSBMenuSelected(wxCommandEvent& event);
		void Onnb16Selected(wxCommandEvent& event);
		void Onnb9Selected(wxCommandEvent& event);
		void OnfineFrequencySliderCmdScrollChanged(wxScrollEvent& event);
		void Onnb6Selected(wxCommandEvent& event);
		void Onnb7Selected(wxCommandEvent& event);
		void Onnb8Selected(wxCommandEvent& event);
		void Onnb10Selected(wxCommandEvent& event);
		void Onnb11Selected(wxCommandEvent& event);
		void Onnb12Selected(wxCommandEvent& event);
		void Onnb13Selected(wxCommandEvent& event);
		void Onnb14Selected(wxCommandEvent& event);
		void Onnb15Selected(wxCommandEvent& event);
		void OnPanel1MouseEnter(wxMouseEvent& event);
		void Onkhpb125Selected(wxCommandEvent& event);
		void Onkhpb250Selected(wxCommandEvent& event);
		void Onkhpb500Selected(wxCommandEvent& event);
		void Onkhpb1000Selected(wxCommandEvent& event);
		void Onkhpb2000Selected(wxCommandEvent& event);
		void OnCWMenuSelected(wxCommandEvent& event);
		void OnWidthx1Selected(wxCommandEvent& event);
		void OnWidthx2Selected(wxCommandEvent& event);
		void Onnb17Selected(wxCommandEvent& event);
		void Onnb18Selected(wxCommandEvent& event);
		void OnAMAGCoffSelected(wxCommandEvent& event);
		void OnAMAGConSelected(wxCommandEvent& event);
		void OnbrightnessSliderCmdScrollChanged(wxScrollEvent& event);
		void OnfrequencySliderCmdScrollChanged(wxScrollEvent& event);
		void OnQuitSelected(wxCommandEvent& event);
		void OnMenuSpectrumSelected(wxCommandEvent& event);
		void OnMenuTimeSampleSelected(wxCommandEvent& event);
		void OnMenuConsoleSelected(wxCommandEvent& event);
		void OnfrequencySliderCmdScrollPageUp(wxScrollEvent& event);
		void OnfrequencySliderCmdScrollPageDown(wxScrollEvent& event);
		void OnfrequencySliderCmdScrollLineUp(wxScrollEvent& event);
		void OnfrequencySliderCmdScrollLineDown(wxScrollEvent& event);
		void OnfineFrequencySliderCmdScrollPageDown(wxScrollEvent& event);
		void OnfineFrequencySliderCmdScrollPageUp(wxScrollEvent& event);
		void OnbrightnessSliderCmdScrollPageUp(wxScrollEvent& event);
		void OnbrightnessSliderCmdScrollPageDown(wxScrollEvent& event);
		void OngainSliderCmdScrollPageUp(wxScrollEvent& event);
		void OngainSliderCmdScrollPageDown(wxScrollEvent& event);
		void OnstartMhzSliderCmdScrollPageUp(wxScrollEvent& event);
		void OnstartMhzSliderCmdScrollPageDown(wxScrollEvent& event);
		void Onnb5Selected(wxCommandEvent& event);
		void Onnb4Selected(wxCommandEvent& event);
		void OnmainSpectrumPanelPaint(wxPaintEvent& event);
		void OnstartMhzSliderCmdScroll(wxScrollEvent& event);
		void OnstartMhzSliderCmdScroll1(wxScrollEvent& event);
		void OnMenu960Selected(wxCommandEvent& event);
		void OnMenu1280Selected(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()

#define N_IMAGE_BUFFER_MAX 512
#define N_VERT_TILE_MAX 18
#define N_HOR_TILE_MAX 2
#define N_LABEL_MAX 512
#define LABEL_PER_TILE 2
public:
        static const long ID_TIMEWINDOW;
        timeFrame *TimeFrame;

        BYTE **spImageBuffer = NULL;    // buffers hold all data for spectrum images
        BYTE **pImage = NULL;           // point to spectrum image to be plotted to panel
        int imageLineIdx = 0;           // first image line to be plotted index

        int AMTuneInc = 5;
        int radioTuneInc = 5;           // radio tuning increment, kHz, 5 for AM, DSB, 1 otherwise
        int kHzPerTile;
        float kHzPerPix;
        float labelKHzInc;
        float NyquistKHz;

        int wtopmargin  = 60;
        int pheight     = 102;
        int pbottommargin  = 22;
        int menubar  = 20;
        int tleftmargin  = 0;
        int twidth  = 1024;

        wxSize tileSize,windowSize;

        int firstBuffer   = 0;  // first buffer to be plotted
        char s[128][128];       // label string
        int brightness = 0;
        int nHorTile;          // window width in panels
        int nVertTile;         // window height in panels
        int nVertTileMax;      // maximum window height in panels

		wxPanel* Tile[N_VERT_TILE_MAX*N_HOR_TILE_MAX]; // region on screen for plotting spectrum
		long ID_TILE[N_VERT_TILE_MAX*N_HOR_TILE_MAX];
		wxStaticText* frequencyLabel[N_VERT_TILE_MAX*N_HOR_TILE_MAX*LABEL_PER_TILE];
		long ID_FREQUENCY_LABEL[N_VERT_TILE_MAX*N_HOR_TILE_MAX*LABEL_PER_TILE];

        void OnTilePaint(wxPaintEvent& event);
		void OnEraseBackground(wxEraseEvent& event);
		void OnTileMouseDown(wxMouseEvent& event);

		void changeNVertTile(int newNVertTile);
		void changeNHorTile(int newNHorTile);
        void OnkHzPerTile(float resolutionkHzper1024);
        void initImageUpdateThread(void);

        HWND hWnd; // console window handle

// frequency range marks

        Mark AMmark[1];
        Mark HAMmark[30];
        Mark CBmark[1];
        wxMenuItem *AMColor;
        wxMenuItem *HAMColor;
        wxMenuItem *CBColor;
        int HAMmarkLength = 0;
        void initMark(void);
        void makeMark(wxPaintDC *pdc, Mark *pmark, wxColor *pcolor, int kHzinc);

};

#endif
