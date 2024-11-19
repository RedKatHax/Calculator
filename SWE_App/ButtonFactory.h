#pragma once
#include "Window.h"

#include <vector>
#include <stack>
#include <queue>


class ButtonFactory : public wxFrame
{

public:
   
   static wxButton* MakeButton();
   static wxButton* MakeButton(wxWindow* parent, wxWindowID id, const wxString label, const wxPoint& pos, const wxSize& size);
   static wxButton* OPButton(wxWindow* parent, wxWindowID id, const wxString label, const wxPoint& pos, const wxSize& size);
   static wxButton* EQButton(wxWindow* parent, wxWindowID id, const wxString label, const wxPoint& pos, const wxSize& size);
   static wxButton* numModButton(wxWindow* parent, wxWindowID id, const wxString label, const wxPoint& pos, const wxSize& size); //negative or . buttons
   static bool chkNum(std::string str);
   static void launchCalculatorProcessor(wxWindow* parent, wxTextCtrl* textbox, std::vector<wxString> textTokens, std::queue<wxString> outQueue, std::stack<wxString> opStack);


};



