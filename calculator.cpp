// Problems 
// It's one file

#include <iostream>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Output.H>
#include <string>
#include "stack.h"
#include <cmath>
#include <typeinfo>

Fl_Window *window = new Fl_Window(500, 550);

Fl_Output *display = new Fl_Output(25,20,450,50, "");

Fl_Button *seven = new Fl_Button(25,100,75,75, "7");
Fl_Button *eight = new Fl_Button(115,100,75,75, "8");
Fl_Button *nine = new Fl_Button(205,100,75,75, "9");

Fl_Button *four = new Fl_Button(25,200,75,75, "4");
Fl_Button *five = new Fl_Button(115,200,75,75, "5");
Fl_Button *six = new Fl_Button(210,200,75,75, "6");

Fl_Button *one = new Fl_Button(25,300,75,75, "1");
Fl_Button *two = new Fl_Button(115,300,75,75, "2");
Fl_Button *three = new Fl_Button(210,300,75,75, "3");

Fl_Button *zero = new Fl_Button(210,400,75,75, "0");

Fl_Button *myplus = new Fl_Button(300,400,75,75, "+");
Fl_Button *myminus = new Fl_Button(300,300,75,75, "-");
Fl_Button *mymultiply = new Fl_Button(300,200,75,75, "*");
Fl_Button *mydivide = new Fl_Button(300,100,75,75, "/");

Fl_Button *exponent = new Fl_Button(395,100,75,75, "^");
Fl_Button *root = new Fl_Button(395,200,75,75, "sqrt");
Fl_Button *change = new Fl_Button(395,300,75,75, "+/-");

Fl_Button *enter = new Fl_Button(25,400,165,75, "Enter");
Fl_Button *drop = new Fl_Button(395,400,75,75, "Drop");

std::string number = "";
const char * current = number.c_str();
Stack<int> displayStack;

void sevencb(Fl_Widget*, void*);
void eightcb(Fl_Widget*, void*);
void ninecb(Fl_Widget*, void*);

void fourcb(Fl_Widget*, void*);
void fivecb(Fl_Widget*, void*);
void sixcb(Fl_Widget*, void*);

void onecb(Fl_Widget*, void*);
void twocb(Fl_Widget*, void*);
void threecb(Fl_Widget*, void*);

void zerocb(Fl_Widget*, void*);

void pluscb(Fl_Widget*, void*);
void minuscb(Fl_Widget*, void*);
void multiplycb(Fl_Widget*, void*);
void dividecb(Fl_Widget*, void*);

void exponentcb(Fl_Widget*, void*);
void rootcb(Fl_Widget*, void*);
void changecb(Fl_Widget*, void*);

void entercb(Fl_Widget*, void*);
void dropcb(Fl_Widget*, void*);

int main (int argc, char* argv[]) {
	// End of window stuff
	window->end();
	window->show(argc, argv);

	seven->callback(sevencb);
	eight->callback(eightcb);
	nine->callback(ninecb);

	four->callback(fourcb);
	five->callback(fivecb);
	six->callback(sixcb);

	one->callback(onecb);
	two->callback(twocb);
	three->callback(threecb);

	zero->callback(zerocb);

	myplus->callback(pluscb);
	myminus->callback(minuscb);
	mymultiply->callback(multiplycb);
	mydivide->callback(dividecb);

	exponent->callback(exponentcb);
	root->callback(rootcb);
	change->callback(changecb);

	enter->callback(entercb);
	drop->callback(dropcb);

	return Fl::run();
}

void sevencb(Fl_Widget*, void*) {
	number += "7";
	current = number.c_str();
	display->value(current);
}
void eightcb(Fl_Widget*, void*) {
	number += "8";
	current = number.c_str();
	display->value(current);
}
void ninecb(Fl_Widget*, void*) {
	number += "9";
	current = number.c_str();
	display->value(current);
}

void fourcb(Fl_Widget*, void*) {
	number += "4";
	current = number.c_str();
	display->value(current);
}
void fivecb(Fl_Widget*, void*) {
	number += "5";
	current = number.c_str();
	display->value(current);
}
void sixcb(Fl_Widget*, void*) {
	number += "6";
	current = number.c_str();
	display->value(current);
}

void onecb(Fl_Widget*, void*) {
	number += "1";
	current = number.c_str();
	display->value(current);
}
void twocb(Fl_Widget*, void*) {
	number += "2";
	current = number.c_str();
	display->value(current);
}
void threecb(Fl_Widget*, void*) {
	number += "3";
	current = number.c_str();
	display->value(current);
}

void zerocb(Fl_Widget*, void*) {
	number += "0";
	current = number.c_str();
	display->value(current);
}

void pluscb(Fl_Widget*, void*) {
	if (number != "") {
		int numbero = stoi(number);
		displayStack.push(numbero);
	}
	number = "";
	int x = displayStack.pop();
	int y = displayStack.pop();
	displayStack.push(x + y);

	std::string s = std::to_string(x+y);
	const char *dchar = s.c_str();
	display->value(dchar);
}
void minuscb(Fl_Widget*, void*) {
	if (number != "") {
		int numbero = stoi(number);
		displayStack.push(numbero);
	}
	number = "";

	int x = displayStack.pop();
	int y = displayStack.pop();
	displayStack.push(y-x);

	std::string s = std::to_string(y-x);
	const char *dchar = s.c_str();
	display->value(dchar);
}
void multiplycb(Fl_Widget*, void*) {
	if (number != "") {
		int numbero = stoi(number);
		displayStack.push(numbero);
	}
	number = "";

	int x = displayStack.pop();
	int y = displayStack.pop();
	displayStack.push(x * y);

	std::string s = std::to_string(x*y);
	const char *dchar = s.c_str();
	display->value(dchar);
}
void dividecb(Fl_Widget*, void*) {
	if (number != "") {
		int numbero = stoi(number);
		displayStack.push(numbero);
	}
	number = "";

	int x = displayStack.pop();
	int y = displayStack.pop();
	displayStack.push(y/x);

	std::string s = std::to_string(y/x);
	const char *dchar = s.c_str();
	display->value(dchar);
}

void exponentcb(Fl_Widget*, void*) {
	if (number != "") {
		int numbero = stoi(number);
		displayStack.push(numbero);
	}
	number = "";

	int x = displayStack.pop();
	int y = displayStack.pop();
	displayStack.push(pow(y,x));

	std::string s = std::to_string(pow(y,x));
	const char *dchar = s.c_str();
	display->value(dchar);
}
void rootcb(Fl_Widget*, void*) {
	if (number != "") {
		int numbero = stoi(number);
		displayStack.push(numbero);
	}
	number = "";

	int x = displayStack.pop();
	displayStack.push(sqrt(x));

	std::string s = std::to_string(sqrt(x));
	const char *dchar = s.c_str();
	display->value(dchar);
}
void changecb(Fl_Widget*, void*) {
	if (number != "") {
		int numbero = stoi(number);
		displayStack.push(numbero);
	}
	number = "";

	int x = displayStack.pop();
	displayStack.push(x * -1);

	std::string s = std::to_string(x * -1);
	const char *dchar = s.c_str();
	display->value(dchar);
}

void entercb(Fl_Widget*, void*) {
	int numbero = stoi(number);
	displayStack.push(numbero);
	number = "";
}
void dropcb(Fl_Widget*, void*) {
	if (!displayStack.isEmpty()) {
		displayStack.pop();

		std::string s = std::to_string(displayStack.top());
		const char *dchar = s.c_str();
		display->value(dchar);
	}
	else {
		std::string s = std::to_string(0);
		const char *dchar = s.c_str();
		display->value(dchar);
	}
}