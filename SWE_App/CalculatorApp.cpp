#include "CalculatorApp.h"

wxIMPLEMENT_APP(CalculatorApp);

bool CalculatorApp::OnInit()
{
  window = new Window();
  window->SetBackgroundColour(wxColor::wxColor(*wxBLACK));
  window->Show();

    return true;
}
