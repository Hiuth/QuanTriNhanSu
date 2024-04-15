#include <wx/wx.h>
#include "hethong.h"
#include "frame.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<wxframe*> framestack;

//khai bao
hethong* hethong = new hethong();

//font
wxfont consolasb(wxfontinfo(40).facename("eras bold itc")); //tiêu đề đẹp, lớn
wxfont calibri(wxfontinfo(15).facename("calibri")); //chữ cái bình thường
wxfont calibrib(wxfontinfo(15).facename("calibri").bold()); //chữ bình thường in hoa
wxfont scalibri(wxfontinfo(12).facename("calibri")); //chữ bé trên menu, thanh search
wxfont calibribi(wxfontinfo(40).facename("calibri").bold().italic()); //chữ to tiêu đề lớn
wxfont scalibribi(wxfontinfo(30).facename("calibri").bold().italic()); //chữ to tiêu đề vừa
wxfont sscalibribi(wxfontinfo(25).facename("calibri").bold().italic()); //chữ to tiêu đề nhỏ

//window size
int windowheight = 540;
int windowwidth = 960;

baseframe::baseframe(const wxstring& title) : wxframe(null, wxid_any, title, wxpoint(280,140), wxsize(windowwidth, windowheight), wxdefault_frame_style & ~(wxresize_border | wxmaximize_box)) {}

void baseframe::onbackclicked(wxcommandevent& evt) {
	if (!framestack.empty()) {
		this->hide();
		framestack.top()->show();
		framestack.pop();
	}
}

void baseframe::onclose(wxcloseevent& evt) {
	this->destroy();
	while (!framestack.empty()) {
		framestack.top()->destroy();
		framestack.pop();
	}

	/*tắt tất cả các cửa số còn hoạt động - tắt lâu nhưng ko có chạy ngầm :d*/
	while (!wxtoplevelwindows.empty()) {
		wxtoplevelwindows[0]->close();
	}
}

void baseframe::createmenu(wxwindow* parent, wxstring username) {
	wxpanel* menu = new wxpanel(parent, wxid_any, wxpoint(0, 0), wxsize(960, 25));
	menu->setbackgroundcolour(wxcolour(255, 255, 255));

	wxbutton* back = new wxbutton(menu, wxid_any, "back", wxpoint(10, 5), wxsize(40, 15), wxno_border);
	back->setbackgroundcolour(wxcolour(255, 255, 255));
	back->setfont(scalibri);
	back->bind(wxevt_button, &baseframe::onbackclicked, this);
	wxstring welcome = "welcome, ";
	welcome = welcome.append(username);
	welcome = welcome.append("!");
	int wlocate = 850 - username.length() * 8;
	wxstatictext* welcometext = new wxstatictext(menu, wxid_any, welcome, wxpoint(wlocate, 3), wxsize(-1, 12));
	welcometext->setfont(scalibri);
}

void baseframe::updatesoon(wxcommandevent& evt) {
	wxlogmessage("update soon!");
}

loginframe::loginframe() : baseframe("human resources managerment") {
	wxpanel* panel = new wxpanel(this);
	
	//frame1
	wxstatictext* text1 = new wxstatictext(panel, wxid_any, "login", wxpoint(370, 120));
	text1->setfont(consolasb);

	//account
	wxstatictext* text2 = new wxstatictext(panel, wxid_any, "account", wxpoint(250, 200));
	text2->setfont(calibri);
	wxtextctrl* space2 = new wxtextctrl(panel, wxid_any, "", wxpoint(370, 190), wxsize(300, 35), wxte_process_enter);
	wxfont font = space2->getfont();
	font.setpointsize(15);
	space2->setfont(font);
	accctrl = space2;

	//password
	wxstatictext* text3 = new wxstatictext(panel, wxid_any, "password", wxpoint(250, 250));
	text3->setfont(calibri);
	wxtextctrl* space3 = new wxtextctrl(panel, wxid_any, "", wxpoint(370, 240), wxsize(300, 35), wxte_password | wxte_process_enter);
	font = space3->getfont();
	font.setpointsize(15);
	space3->setfont(font);
	passctrl = space3;

	//next button
	wxbutton* button1 = new wxbutton(panel, wxid_any, "next", wxpoint(650, 300), wxsize(80, 40));
	button1->setfont(calibri);

	//event
	button1->bind(wxevt_button, &loginframe::onbuttonclicked, this);
	space2->bind(wxevt_text_enter, &loginframe::entertext, this);
	space3->bind(wxevt_text_enter, &loginframe::entertext, this);
	bind(wxevt_key_down, &loginframe::enterdown, this);
	bind(wxevt_close_window, &baseframe::onclose, this);
}

void loginframe::next() {
	wxstring acc = accctrl->getvalue();
	wxstring pass = passctrl->getvalue();
	if (hethong->checkaccount(acc.tostdstring(), pass.tostdstring())) {
		framestack.push(this);
		this->hide();
		(new homeframe(accctrl->getvalue()))->show();
	}
	else {
		wxlogmessage("sai tai khoan hoac mat khau");
	}
}

void loginframe::onbuttonclicked(wxcommandevent& evt) {
	next();
}

void loginframe::enterdown(wxkeyevent& evt) {
	if (evt.getkeycode() == wxk_return) {
		next();
	}
}

void loginframe::entertext(wxcommandevent& evt) {
	next();
}

homeframe::homeframe(wxstring accname) : baseframe("home") {
	wxpanel* panel = new wxpanel(this);
	username = accname;
	createmenu(panel, username);

	//frame2
	wxbutton* button1 = new wxbutton(panel, wxid_any, "quan li\ntai khoan", wxpoint(15, 40), wxsize(450, 210));
	button1->setfont(calibribi);
	button1->setbackgroundcolour(wxcolour(89, 102, 200));
	button1->setforegroundcolour(wxcolour(255, 255, 255));
	wxbutton* button2 = new wxbutton(panel, wxid_any, "quan li\nnhan su", wxpoint(480, 40), wxsize(450, 210));
	button2->setfont(calibribi);
	button2->setbackgroundcolour(wxcolour(61, 201, 113));
	button2->setforegroundcolour(wxcolour(255, 255, 255));
	wxbutton* button3 = new wxbutton(panel, wxid_any, "quan li\ntien luong", wxpoint(15, 265), wxsize(450, 210));
	button3->setfont(calibribi);
	button3->setbackgroundcolour(wxcolour(192, 162, 70));
	button3->setforegroundcolour(wxcolour(255, 255, 255));
	wxbutton* button4 = new wxbutton(panel, wxid_any, "khac", wxpoint(480, 265), wxsize(450, 210));
	button4->setfont(calibribi);
	button4->setbackgroundcolour(wxcolour(193, 68, 112));
	button4->setforegroundcolour(wxcolour(255, 255, 255));

	//event
	button1->bind(wxevt_button, &homeframe::onbutton1clicked, this);
	button2->bind(wxevt_button, &homeframe::onbutton2clicked, this);
	button3->bind(wxevt_button, &homeframe::onbutton3clicked, this);
	button4->bind(wxevt_button, &homeframe::onbutton4clicked, this);
	bind(wxevt_close_window, &baseframe::onclose, this);
}

void homeframe::onbutton1clicked(wxcommandevent& evt) {
	if (hethong->checkdata(username.tostdstring(), "admin")) {
		framestack.push(this);
		this->hide();
		(new qltkframe(username))->show();
	}
	else {
		wxlogmessage("khong co quyen truy cap!");
	}
}

void homeframe::onbutton2clicked(wxcommandevent& evt) {
	
	if (hethong->checkdata(username.tostdstring(), "admin")) {
		framestack.push(this);
		this->hide();
		(new qlnsframe(username))->show();
	} else if (hethong->checkdata(username.tostdstring(), "quanlynhansu")) {
		framestack.push(this);
		this->hide();
		(new qlnsframe(username))->show();
	} else {
		wxlogmessage("khong co quyen truy cap!");
	}
}

void homeframe::onbutton3clicked(wxcommandevent& evt) {
	if (hethong->checkdata(username.tostdstring(), "admin")) {
		framestack.push(this);
		this->hide();
		(new qltlframe(username))->show();
	}
	else if (hethong->checkdata(username.tostdstring(), "quanlytienluong")) {
		framestack.push(this);
		this->hide();
		(new qltlframe(username))->show();
	}
	else {
		wxlogmessage("khong co quyen truy cap!");
	}
}

void homeframe::onbutton4clicked(wxcommandevent& evt) {
	framestack.push(this);
	this->hide();
	(new kframe(username))->show();
}

qltkframe::qltkframe(wxstring accname) : baseframe("quan li tai khoan") {
	wxpanel* panel = new wxpanel(this);
	username = accname;
	createmenu(panel, username);

	//frame3
	wxstatictext* text1 = new wxstatictext(panel, wxid_any, "tim kiem", wxpoint(20, 40));
	text1->setfont(calibrib);
	wxtextctrl* search = new wxtextctrl(panel, wxid_any, "search", wxpoint(105, 40), wxsize(200, -1));
	search->setfont(scalibri);

	wxstatictext* text2 = new wxstatictext(panel, wxid_any, "tags", wxpoint(435, 40));
	text2->setfont(calibrib);
	wxarraystring tags;
	tags.add("ten tai khoan");
	tags.add("quyen han");
	wxchoice* tag = new wxchoice(panel, wxid_any, wxpoint(480, 40), wxsize(200, -1), tags);
	tag->select(0);
	tag->setfont(scalibri);

	//event
	bind(wxevt_close_window, &baseframe::onclose, this);
}

qlnsframe::qlnsframe(wxstring accname) : baseframe("quan li nhan su") {
	wxpanel* panel = new wxpanel(this);
	username = accname;
	createmenu(panel, username);

	//frame
	wxbutton* button1 = new wxbutton(panel, wxid_any, "quan li ho so nhan vien", wxpoint(22, 40), wxsize(900, 140));
	button1->setfont(calibribi);
	button1->setbackgroundcolour(wxcolour(64, 22, 204));
	button1->setforegroundcolour(wxcolour(255, 255, 255));
	wxbutton* button2 = new wxbutton(panel, wxid_any, "quan li chuc vu", wxpoint(22, 190), wxsize(900, 140));
	button2->setfont(calibribi);
	button2->setbackgroundcolour(wxcolour(18, 132, 205));
	button2->setforegroundcolour(wxcolour(255, 255, 255));
	wxbutton* button3 = new wxbutton(panel, wxid_any, "quan li phong ban", wxpoint(22, 340), wxsize(900, 140));
	button3->setfont(calibribi);
	button3->setbackgroundcolour(wxcolour(13, 190, 92));
	button3->setforegroundcolour(wxcolour(255, 255, 255));

	//event
	button1->bind(wxevt_button, &qlnsframe::onbutton1clicked, this);
	button2->bind(wxevt_button, &qlnsframe::onbutton2clicked, this);
	button3->bind(wxevt_button, &qlnsframe::onbutton3clicked, this);
	bind(wxevt_close_window, &baseframe::onclose, this);
}

void qlnsframe::onbutton1clicked(wxcommandevent& evt) {
	framestack.push(this);
	this->hide();
	(new qlnsframe2(username))->show();
}

void qlnsframe::onbutton2clicked(wxcommandevent& evt) {
	framestack.push(this);
	this->hide();
	(new qlnsframe10(username))->show();
}

void qlnsframe::onbutton3clicked(wxcommandevent& evt) {
	framestack.push(this);
	this->hide();
	(new qlnsframe16(username))->show();
}

qlnsframe2::qlnsframe2(wxstring accname) : baseframe("quan li ho so nhan vien") {
	wxpanel* panel = new wxpanel(this);
	username = accname;
	createmenu(panel, username);

	//event
	bind(wxevt_close_window, &baseframe::onclose, this);
}

qlnsframe10::qlnsframe10(wxstring accname) : baseframe("quan li chuc vu") {
	wxpanel* panel = new wxpanel(this);
	username = accname;
	createmenu(panel, username);

	//event
	bind(wxevt_close_window, &baseframe::onclose, this);
}

qlnsframe16::qlnsframe16(wxstring accname) : baseframe("quan li phong ban") {
	wxpanel* panel = new wxpanel(this);
	username = accname;
	createmenu(panel, username);

	//event
	bind(wxevt_close_window, &baseframe::onclose, this);
}

qltlframe::qltlframe(wxstring accname) : baseframe("quan li tien luong") {
	wxpanel* panel = new wxpanel(this);
	username = accname;
	createmenu(panel, username);

	//frame
	wxbutton* button1 = new wxbutton(panel, wxid_any, "xem tat ca\nthong tin", wxpoint(22, 45), wxsize(400, 440));
	button1->setfont(calibribi);
	button1->setbackgroundcolour(wxcolour(192, 18, 67));
	button1->setforegroundcolour(wxcolour(255, 255, 255));
	wxbutton* button2 = new wxbutton(panel, wxid_any, "thong tin cham cong,\nluong co ban", wxpoint(433, 45), wxsize(490, 215));
	button2->setfont(scalibribi);
	button2->setbackgroundcolour(wxcolour(14, 116, 194));
	button2->setforegroundcolour(wxcolour(255, 255, 255));
	wxbutton* button3 = new wxbutton(panel, wxid_any, "thong tin\nlam them", wxpoint(433, 270), wxsize(490, 215));
	button3->setfont(scalibribi);
	button3->setbackgroundcolour(wxcolour(14, 166, 29));
	button3->setforegroundcolour(wxcolour(255, 255, 255));

	//event
	button1->bind(wxevt_button, &qltlframe::onbutton1clicked, this);
	button2->bind(wxevt_button, &qltlframe::onbutton2clicked, this);
	button3->bind(wxevt_button, &qltlframe::onbutton3clicked, this);
	bind(wxevt_close_window, &baseframe::onclose, this);
}

void qltlframe::onbutton1clicked(wxcommandevent& evt) {
	framestack.push(this);
	this->hide();
	(new qltlframe2(username))->show();
}

void qltlframe::onbutton2clicked(wxcommandevent& evt) {
	framestack.push(this);
	this->hide();
	(new qltlframe3(username))->show();
}

void qltlframe::onbutton3clicked(wxcommandevent& evt) {
	framestack.push(this);
	this->hide();
	(new qltlframe5(username))->show();
};

qltlframe2::qltlframe2(wxstring accname) : baseframe("xem tien luong") {
	wxpanel* panel = new wxpanel(this);
	username = accname;
	createmenu(panel, username);

	//event
	bind(wxevt_close_window, &baseframe::onclose, this);
}

qltlframe3::qltlframe3(wxstring accname) : baseframe("cham cong va luong co ban") {
	wxpanel* panel = new wxpanel(this);
	username = accname;
	createmenu(panel, username);

	//event
	bind(wxevt_close_window, &baseframe::onclose, this);
}

qltlframe5::qltlframe5(wxstring accname) : baseframe("lam them") {
	wxpanel* panel = new wxpanel(this);
	username = accname;
	createmenu(panel, username);

	//event
	bind(wxevt_close_window, &baseframe::onclose, this);
}

kframe::kframe(wxstring accname) : baseframe("khac") {
	wxpanel* panel = new wxpanel(this);
	username = accname;
	createmenu(panel, username);

	//frame
	wxbutton* button1 = new wxbutton(panel, wxid_any, "quan li\nchinh sach\ndai ngo", wxpoint(22, 43), wxsize(400, 440));
	button1->setfont(calibribi);
	button1->setbackgroundcolour(wxcolour(83, 13, 170));
	button1->setforegroundcolour(wxcolour(255, 255, 255));
	wxbutton* button2 = new wxbutton(panel, wxid_any, "sap cap nhat", wxpoint(433, 43), wxsize(490, 215));
	button2->setfont(scalibribi);
	button2->setbackgroundcolour(wxcolour(20, 78, 122));
	button2->setforegroundcolour(wxcolour(255, 255, 255));
	wxbutton* button3 = new wxbutton(panel, wxid_any, "huong dan\nsu dung", wxpoint(433, 268), wxsize(240, 215));
	button3->setfont(sscalibribi);
	button3->setbackgroundcolour(wxcolour(22, 124, 80));
	button3->setforegroundcolour(wxcolour(255, 255, 255));
	wxbutton* button4 = new wxbutton(panel, wxid_any, "reset\ndu lieu", wxpoint(683, 268), wxsize(240, 215));
	button4->setfont(sscalibribi);
	button4->setbackgroundcolour(wxcolour(184, 11, 109));
	button4->setforegroundcolour(wxcolour(255, 255, 255));

	//event
	button1->bind(wxevt_button, &kframe::onbutton1clicked, this);
	button2->bind(wxevt_button, &baseframe::updatesoon, this);
	button3->bind(wxevt_button, &baseframe::updatesoon, this);
	button4->bind(wxevt_button, &baseframe::updatesoon, this);
	bind(wxevt_close_window, &baseframe::onclose, this);
}

void kframe::onbutton1clicked(wxcommandevent& evt) {
	framestack.push(this);
	this->hide();
	(new kframe2(username))->show();
}

kframe2::kframe2(wxstring accname) : baseframe("quan li chinh sach dai ngo") {
	wxpanel* panel = new wxpanel(this);
	username = accname;
	createmenu(panel, username);

	//frame
	wxbutton* button1 = new wxbutton(panel, wxid_any, "quan li\nbao hiem", wxpoint(25, 43), wxsize(445, 440));
	button1->setfont(calibribi);
	button1->setbackgroundcolour(wxcolour(20, 70, 152));
	button1->setforegroundcolour(wxcolour(255, 255, 255));
	wxbutton* button2 = new wxbutton(panel, wxid_any, "quan li\nkhen thuong\nki luat", wxpoint(475, 43), wxsize(445, 440));
	button2->setfont(calibribi);
	button2->setbackgroundcolour(wxcolour(22, 124, 80));
	button2->setforegroundcolour(wxcolour(255, 255, 255));

	//event
	button1->bind(wxevt_button, &kframe2::onbutton1clicked, this);
	button2->bind(wxevt_button, &kframe2::onbutton2clicked, this);
	bind(wxevt_close_window, &baseframe::onclose, this);
}

void kframe2::onbutton1clicked(wxcommandevent& evt) {
	framestack.push(this);
	this->hide();
	(new kframe3(username))->show();
}

void kframe2::onbutton2clicked(wxcommandevent& evt) {
	framestack.push(this);
	this->hide();
	(new kframe6(username))->show();
}

kframe3::kframe3(wxstring accname) : baseframe("quan li bao hiem") {
	wxpanel* panel = new wxpanel(this);
	username = accname;
	createmenu(panel, username);

	//event
	bind(wxevt_close_window, &baseframe::onclose, this);
}

kframe6::kframe6(wxstring accname) : baseframe("quan li khen thuong, ki luat") {
	wxpanel* panel = new wxpanel(this);
	username = accname;
	createmenu(panel, username);

	//event
	bind(wxevt_close_window, &baseframe::onclose, this);
}