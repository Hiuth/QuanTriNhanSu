#include <wx/wx.h>
#include "Frame.h"
#include <iostream>
using namespace std;

Frame::Frame(const string& title): wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxDefaultSize) {
	wxPanel* panel1 = new wxPanel(this);
	wxStaticText* text1 = new wxStaticText(panel1, wxID_ANY, "LOGIN", wxPoint(440, 150));

	wxStaticText* text2 = new wxStaticText(panel1, wxID_ANY, "ACCOUNT", wxPoint(300, 200));
	wxTextCtrl* space2 = new wxTextCtrl(panel1, wxID_ANY, "", wxPoint(400, 190), wxSize(200,-1));

	wxStaticText* text3 = new wxStaticText(panel1, wxID_ANY, "PASSWORD", wxPoint(300, 235));
	wxTextCtrl* space3 = new wxTextCtrl(panel1, wxID_ANY, "", wxPoint(400, 225), wxSize(200,-1),wxTE_PASSWORD);

	wxButton* button1 = new wxButton(panel1, wxID_ANY, "Check", wxPoint(620,280), wxSize(80,40));
	wxCheckBox* checkbox1 = new wxCheckBox(panel1, wxID_ANY, "Remember me", wxPoint(400, 260));
}
