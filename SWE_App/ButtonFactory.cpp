//#include "ButtonFactory.h"
#include "Window.h"

wxButton* ButtonFactory::MakeButton() { return nullptr; } //default constructor 

wxButton* ButtonFactory::MakeButton(wxWindow* parent, wxWindowID id, const wxString label, const wxPoint& pos, const wxSize& size) //overloaded default for basic button 
{
  wxButton* newButton = new wxButton(parent, id, label, pos, size);

  newButton->SetBackgroundColour(wxColor(255, 0, 255));
  newButton->Bind(wxEVT_BUTTON, &Window::OnButtonClick, (Window*)parent);
  return newButton;
}

void ButtonFactory::launchCalculatorProcessor(wxWindow* parent, wxTextCtrl* textbox, std::vector<wxString> textTokens, std::queue<wxString> outQueue, std::stack<wxString> opStack)
{
  CalculatorProcessor* calc = CalculatorProcessor::GetInstance();
  calc->tokenize(textbox, textTokens, outQueue, opStack);

}

wxButton* ButtonFactory::OPButton(wxWindow* parent, wxWindowID id, const wxString label, const wxPoint& pos, const wxSize& size) //operator button 
{
  
  wxButton* newOPButton = new wxButton(parent, id, label, pos, size);

  newOPButton->SetBackgroundColour(wxColor(150, 0, 255));
  newOPButton->Bind(wxEVT_BUTTON, &Window::OnButtonClick, (Window*)parent);

  return newOPButton;
}

wxButton* ButtonFactory::numModButton(wxWindow* parent, wxWindowID id, const wxString label, const wxPoint& pos, const wxSize& size) //negative or . buttons 
{

  wxButton* numModButton = new wxButton(parent, id, label, pos, size);

  numModButton->SetBackgroundColour(wxColor(100,25,255));
  numModButton->Bind(wxEVT_BUTTON, &Window::OnButtonClick, (Window*)parent);
  return numModButton;
}

wxButton* ButtonFactory::EQButton(wxWindow* parent, wxWindowID id, const wxString label, const wxPoint& pos, const wxSize& size) //equal button 
{

  wxButton* newEQButton = new wxButton(parent, id, label, pos, size);

  newEQButton->SetBackgroundColour(*wxGREEN);
  newEQButton->Bind(wxEVT_BUTTON, &Window::OnButtonClick, (Window*)parent);
  return newEQButton;
}

#pragma region ButtonClickEvent

void Window::OnButtonClick(wxCommandEvent& event)
{

  int id = event.GetId();
  switch (id)
  {
  case 1002:
  {
    AppendTextBox(this, button0, textbox);
   
    break;
  }
  case 1003:
  {
    AppendTextBox(this, button1, textbox);
    break;
  }
  case 1004:
  {
    AppendTextBox(this, button2, textbox);
    break;
  }
  case 1005:
  {
    AppendTextBox(this, button3, textbox);
    break;
  }
  case 1006:
  {
    AppendTextBox(this, button4, textbox);
    break;
  }
  case 1007:
  {
    AppendTextBox(this, button5, textbox);
    break;
  }
  case 1008:
  {
    AppendTextBox(this, button6, textbox);
    break;
  }
  case 1009:
  {
    AppendTextBox(this, button7, textbox);
    break;
  }
  case 1010:
  {
    AppendTextBox(this, button8, textbox);
    break;
  }
  case 1011:
  {
    AppendTextBox(this, button9, textbox);
    break;
  }
  case 1012:
  {
    AppendTextBox(this, buttonDot, textbox);
    break;
  }
  case 1013:
  {
    AppendTextBox(this, buttonNegative, textbox); //negative sign 
    break;
  }
  case 1014:
  {
    textbox->AppendText(" sin ");
    break;
  }
  case 1015:
  {
    textbox->AppendText(" cos ");
    break;
  }
  case 1016:
  {
    textbox->AppendText(" tan ");
    break;
  }
  case 1017: //mod button 
  {
    textbox->AppendText(" % ");
    break;
  }
  case 1018: //addition button 
  {
    textbox->AppendText(" + ");
    break;
  }
  case 1019: //subtract button 
  {
    textbox->AppendText(" - ");
    break;
  }
  case 1020: //multiply button 
  {
    textbox->AppendText(" * ");
    break;
  }
  case 1021: //divide button 
  {
    textbox->AppendText(" / ");
    break;
  }
  case 1022:  // = button 
  {

    ButtonFactory::launchCalculatorProcessor(this, textbox, textTokens, outQueue, opStack);
 
  }

  break;

  case 1023: //Clear button 
  {
    textbox->Clear();
    break;
  }
  case 1024: //Del button 
  {
    wxString str = textbox->GetValue();
    if (str.size() == 0)
    {
      break;
    }
    else
    {
      str.erase(str.size() - 1, 1);
      textbox->Clear();
      textbox->AppendText(str);
      break;
    }
  }
  default:
    break;
  }
}
#pragma endregion

 void Window::AppendTextBox(wxWindow* parent, wxButton* button, wxTextCtrl* textbox)
{
  wxString text = button->GetLabel();
  textbox->AppendText(text);
}
 

 
 


