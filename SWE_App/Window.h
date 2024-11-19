#pragma once
#include "wx/wx.h"
#include "ButtonFactory.h"
#include "CalculatorProcessor.h"
#include <iostream>
#include <wx/tokenzr.h>
#include <vector>
#include <stdio.h>
#include <stack>
#include <queue>

class Window : public wxFrame
{
  wxButton* newButton = nullptr;
  wxButton* button0 = nullptr;
  wxButton* button1 = nullptr;
  wxButton* button2 = nullptr;
  wxButton* button3 = nullptr;
  wxButton* button4 = nullptr;
  wxButton* button5 = nullptr;
  wxButton* button6 = nullptr;
  wxButton* button7 = nullptr;
  wxButton* button8 = nullptr;
  wxButton* button9 = nullptr;
  wxButton* buttonDot = nullptr;
  wxButton* buttonNegative = nullptr;
  wxButton* buttonSin = nullptr;
  wxButton* buttonCos = nullptr;
  wxButton* buttonTan = nullptr;
  wxButton* buttonMod = nullptr;
  wxButton* buttonAdd = nullptr;
  wxButton* buttonSub = nullptr;
  wxButton* buttonMult = nullptr;
  wxButton* buttonDiv = nullptr;
  wxButton* buttonClear = nullptr;
  wxButton* buttonEqual = nullptr;
  wxButton* buttonDel = nullptr;

  wxTextCtrl* textbox = nullptr;

  

public:

  Window();
 
   void OnButtonClick(wxCommandEvent& event);
   static void AppendTextBox(wxWindow* parent, wxButton* button, wxTextCtrl* textbox);
   std::vector<wxString> textTokens;
   std::queue<wxString> outQueue;
   std::stack<wxString> opStack;

};

