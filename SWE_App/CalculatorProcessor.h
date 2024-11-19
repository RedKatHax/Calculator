#pragma once
#include "Window.h"
#include <vector>
#include <stack>
#include <queue>


class CalculatorProcessor
{
  //ABOUT CalculatorProcessor Class:
  // 
  //CalculatorProcessor is a Singleton class that defines 'GetInstance' method to replace constructor
  //
  //Allows clients to access same instance of class over and over
  //
  //Singletons constructor needs to be private to prevent calls with 'new' operator (preventing multiple instances)

 
private:

  static CalculatorProcessor* _processor;

  CalculatorProcessor() {};

protected:

  wxString value_;
  CalculatorProcessor(const wxString value) : value_(value)
  {

  } 

public:

  CalculatorProcessor(CalculatorProcessor& other) = delete; //should not be cloneable 
  void operator=(const CalculatorProcessor&) = delete; //should not be assignable
 
  static CalculatorProcessor* GetInstance(); //controls access to singleton. First run creates singleton object and places in static field. Subsequent runs returns the client existing object stored in the static field.

  wxString value() const
  {
    return value_;
  }
  
 /* static void ShuntingYardCalc(wxWindow* parent, wxTextCtrl* textbox, std::vector<wxString> textTokens, std::queue<wxString> outQueue, std::stack<wxString> opStack);*/
  void tokenize(wxTextCtrl* textbox, std::vector<wxString> textTokens, std::queue<wxString> outQueue, std::stack<wxString> opStack); //convert user input to tokens 
  static bool chkNum(std::string str);
  static int opPrec(std::string str);
  static void Ans(std::queue<wxString> outQueue, wxTextCtrl* textbox);
  static void errorReturn(wxTextCtrl* textbox);
};

