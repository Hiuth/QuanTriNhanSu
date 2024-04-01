#pragma once
#include <wx/wx.h>
#include <iostream>
using namespace std;

class LoginFrame : public wxFrame
{
public:
	LoginFrame(const string& title);
private:
	void OnButtonClicked(wxCommandEvent& evt);
	wxTextCtrl* accCtrl;
	wxTextCtrl* passCtrl;
};

class HomeFrame : public wxFrame
{
public:
	HomeFrame(const string& title);
};