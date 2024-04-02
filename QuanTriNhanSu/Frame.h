#pragma once
#include <wx/wx.h>
#include <iostream>
using namespace std;

class BaseFrame : public wxFrame //menu ke thua wxframe
{
public:
	BaseFrame(const wxString& title);
	void OnBackClicked(wxCommandEvent& evt);
	void OnClose(wxCloseEvent& evt);
	wxTextCtrl* accCtrl;
	wxTextCtrl* passCtrl;
};

class LoginFrame : public BaseFrame //frame ke thua menu ke thua wxframe
{
public:	
	LoginFrame();
private:
	void OnButtonClicked(wxCommandEvent& evt);
};

class HomeFrame : public BaseFrame
{
public:
	HomeFrame();
private:
};