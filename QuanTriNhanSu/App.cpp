#pragma once
#include "App.h"
#include "Frame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	//tiengviet
	wxLocale locale;
	locale.Init(wxLANGUAGE_VIETNAMESE);

	LoginFrame* login = new LoginFrame();
	//login->Show();

	QLTKFrame* test = new QLTKFrame("");
	test->Show();

	return true;
}
