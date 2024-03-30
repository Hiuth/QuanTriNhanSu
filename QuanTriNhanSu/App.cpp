#pragma once
#include "App.h"
#include "Frame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	Frame* frame = new Frame("WTF");
	frame->Show();
	frame->SetClientSize(960,540);
	return true;
}
