// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

#ifndef wxFX3APP_H
#define wxFX3APP_H

#include <wx/app.h>
#include "timeFrame.h"

class wxFX3App : public wxApp
{
    public:
        virtual bool OnInit();
        timeFrame* tFrame;
};

#endif // wxFX3APP_H
