#include "Window.h"

Window::Window() :
  wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(400, 200), wxSize(305, 380))
  
{
  textbox = new wxTextCtrl(this, 100, "", wxPoint(10, 10), wxSize(270, 50)); 

  button0 = ButtonFactory::ButtonFactory::MakeButton(this, 1002, "0", wxPoint(120, 280), wxSize(50, 50));
  button1 = ButtonFactory::ButtonFactory::MakeButton(this, 1003, "1", wxPoint(70, 230), wxSize(50, 50));
  button2 = ButtonFactory::ButtonFactory::MakeButton(this, 1004, "2", wxPoint(120, 230), wxSize(50, 50));
  button3 = ButtonFactory::ButtonFactory::MakeButton(this, 1005, "3", wxPoint(170, 230), wxSize(50, 50));
  button4 = ButtonFactory::ButtonFactory::MakeButton(this, 1006, "4", wxPoint(70, 180), wxSize(50, 50));
  button5 = ButtonFactory::ButtonFactory::MakeButton(this, 1007, "5", wxPoint(120, 180), wxSize(50, 50));
  button6 = ButtonFactory::ButtonFactory::MakeButton(this, 1008, "6", wxPoint(170, 180), wxSize(50, 50));
  button7 = ButtonFactory::ButtonFactory::MakeButton(this, 1009, "7", wxPoint(70, 130), wxSize(50, 50));
  button8 = ButtonFactory::ButtonFactory::MakeButton(this, 1010, "8", wxPoint(120, 130), wxSize(50, 50));
  button9 = ButtonFactory::ButtonFactory::MakeButton(this, 1011, "9", wxPoint(170, 130), wxSize(50, 50));

  buttonDot = ButtonFactory::ButtonFactory::numModButton(this, 1012, ".", wxPoint(70, 280), wxSize(50, 50));
  buttonNegative = ButtonFactory::ButtonFactory::numModButton(this, 1013, "-", wxPoint(170, 280), wxSize(50, 50));

  buttonSin = ButtonFactory::ButtonFactory::OPButton(this, 1014, "sin", wxPoint(120, 70), wxSize(50, 50));
  
  buttonCos = ButtonFactory::ButtonFactory::OPButton(this, 1015, "cos", wxPoint(70, 70), wxSize(50, 50));
  
  buttonTan = ButtonFactory::ButtonFactory::OPButton(this, 1016, "tan", wxPoint(170, 70), wxSize(50, 50));
  

  buttonMod = ButtonFactory::ButtonFactory::OPButton(this, 1017, "mod", wxPoint(10, 70), wxSize(50, 50));
  buttonAdd = ButtonFactory::ButtonFactory::OPButton(this, 1018, " + ", wxPoint(10, 130), wxSize(50, 50));
  buttonSub = ButtonFactory::ButtonFactory::OPButton(this, 1019, " - ", wxPoint(10, 180), wxSize(50, 50));
  buttonMult = ButtonFactory::ButtonFactory::OPButton(this, 1020, " * ", wxPoint(10, 230), wxSize(50, 50));
  buttonDiv = ButtonFactory::ButtonFactory::OPButton(this, 1021, " / ", wxPoint(10, 280), wxSize(50, 50));

  buttonEqual = ButtonFactory::ButtonFactory::EQButton(this, 1022, "=", wxPoint(230, 230), wxSize(50, 100));
  buttonClear = ButtonFactory::ButtonFactory::OPButton(this, 1023, "C", wxPoint(230, 130), wxSize(50, 100));
  buttonDel = ButtonFactory::ButtonFactory::OPButton(this, 1024, "Del", wxPoint(230, 70), wxSize(50, 50));
  buttonDel->SetBackgroundColour(*wxRED);
}




