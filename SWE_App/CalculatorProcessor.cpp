#include "CalculatorProcessor.h"
#include<math.h>

//#include "ButtonFactory.cpp"

CalculatorProcessor* CalculatorProcessor::_processor = nullptr;

CalculatorProcessor* CalculatorProcessor::GetInstance()
{

  if (CalculatorProcessor::_processor == nullptr)
  {
    
    _processor = new CalculatorProcessor();
  }
  return _processor;
}



void PostFixSort(wxTextCtrl* textbox, std::vector<wxString>textTokens, std::queue<wxString> outQueue, std::stack<wxString> opStack) 
{

  for (size_t i = 0; i < textTokens.size(); i++) //begin token sort   
  {
    wxString textStr = textTokens[i];
    std::string stlstring = std::string(textStr.mbc_str()); //convert wxString to std string 

    bool chkStr = CalculatorProcessor::chkNum(stlstring); //check if num or op

    if (chkStr == true) //number 
    {

      wxString num = textStr;
      outQueue.push(num); //push to output queue     
    }

    if (chkStr == false) //not a number 
    {
      if (opStack.size() == 0) //operator stack is empty 
      {
        /*wxString opFuncInc = textTokens[i];*/  //grab incoming operator 

        opStack.push(textStr); //push the incoming operator onto the operator stack.
        continue;//get next token 
      }

      if (opStack.size() > 0) //operator stack != empty
      {

        wxString opToCompare = opStack.top(); //grab top sorted operator 
        std::string opToComp_Str = std::string(opToCompare.mbc_str()); //convert from wxString to std::string

        int opPrecSorted = CalculatorProcessor::opPrec(opToComp_Str); //retrieve operator precedence for top operator 

      
        std::string opFuncInc_Str = std::string(textStr.mbc_str()); //convert incoming token from wxString to std::string

        int opPrecInc = CalculatorProcessor::opPrec(opFuncInc_Str); //retrieve operator precedence for incoming operator
        if (opPrecInc > opPrecSorted)
        {
          opStack.push(textStr);
        }
        if ((opPrecInc < opPrecSorted) || (opPrecInc == opPrecSorted)) //incoming operator has LOWER precedence than what’s currently at top of the operator stack
        {

          opToCompare = opStack.top();
          outQueue.push(opToCompare); //push the operator onto the outQueue
          opStack.pop(); //remove operator from op stack
          if (opStack.size() > 0)
          {
            opToCompare = opStack.top(); //grab top operator 
            std::string opToComp_Str = std::string(opToCompare.mbc_str()); //convert from wxString to std::string

            int opPrecSorted = CalculatorProcessor::opPrec(opToComp_Str); //retrieve operator precedence
            if (opPrecInc > opPrecSorted)
            {
              opStack.push(textStr);
              break;
            }
          }

          if (opStack.size() == 0)
          {
            opStack.push(textStr);
          }
        }
      }
    } 

  }

  while (opStack.size() > 0)   //if i == texttokens.
  {
    wxString opOutQueue = opStack.top();
    outQueue.push(opOutQueue);
    if (opStack.size() == 0)
    {
      continue;
    }

    opStack.pop();
  }

  CalculatorProcessor::Ans(outQueue, textbox);
 
#pragma region postFix Sort Test 
 /* while (outQueue.size() > 0)
  {
    wxString mystring = outQueue.front();
    textbox->AppendText(mystring);
    if (outQueue.size() == 0)
    {
      continue;
    }
    outQueue.pop();
  }*/
#pragma endregion

}


void CalculatorProcessor::tokenize(wxTextCtrl* textbox, std::vector<wxString>textTokens, std::queue<wxString> outQueue, std::stack<wxString>opStack) //extracts user input from textbox as string, breaks apart string using space as delim, tokenizes substrings and sorts by operator or number
{
  wxString str = textbox->GetValue(); //extract input into string 
  textbox->Clear(); //clear textbox for calculation answer 

  wxStringTokenizer tokenizer(str, " "); //break string apart into tokens using space as delim 

  while (tokenizer.HasMoreTokens()) //loop until no tokens left  
  {
    wxString token = tokenizer.GetNextToken();
    textTokens.push_back(token); //push token into vector
  }

  PostFixSort(textbox, textTokens, outQueue, opStack); //begin calculations
}
 
  bool CalculatorProcessor::chkNum(std::string str) //verify if str is number or operator
  {

    for (size_t i = 0; i < str.length(); i++)
    {
      if (!std::isdigit(str[i]))
      {
        char checkDot = str.at(i);
        char checkNeg = str.at(i);
        if ((checkDot == '.') || (checkDot == '-') && (str.size() > 1)) //number has decimal or is negative 
        {
          break; //check next digit 
        }

        else //not a number 
        {
          return false;
        }
      }

    }
    return true;
  }

  int CalculatorProcessor::opPrec(std::string str)
  {
   
    if (str == '+') //ADD
    {
      return (int)1;
    }

    if (str == '-') //SUB
    {
      return (int)1;
    }

    if (str == '*') //MULT
    {
      return (int)2;
    }
    if (str == '/') //DIVIDE
    {
      return (int)2;
    }
    else
    {
      return (int)3; //not num or operator == FUNC
    }
    
  }

  void CalculatorProcessor::errorReturn(wxTextCtrl* textbox)
  {
    textbox->Clear();
    textbox->AppendText("**ERROR**");  //display error to user 
  }

  void CalculatorProcessor::Ans(std::queue<wxString> outQueue, wxTextCtrl* textbox)
  {
    std::stack<wxString>ansStack; 
    int queueSize = outQueue.size(); //get total number of operator/operands to process 
    bool errorFlag = false;
    while (!errorFlag)
    {
      while (outQueue.size() > 0)
      {
        wxString scanQueue = outQueue.front(); //character to process 
        std::string stlstring = std::string(scanQueue.mbc_str()); //convert wxString to std string 

        bool chkStr = CalculatorProcessor::chkNum(stlstring); //check if num or op

        if (chkStr == true) //number 
        {

          ansStack.push(scanQueue); //push to ans stack
          outQueue.pop(); //pop number off of stack 
        }

        if (chkStr == false) //not a number 
        {
          std::string stlstring = std::string(scanQueue.mbc_str());
         
          if (stlstring == "sin") //catch trig functions here
          {
            if (ansStack.size() == 0)
            {
              CalculatorProcessor::errorReturn(textbox);
              errorFlag = true;
              break;
            }
            float trigNum = (float)wxAtof(ansStack.top());
            ansStack.pop();

            float trigAns = sin(trigNum);
            wxString mystring = wxString::Format(wxT("%f"), trigAns);

            ansStack.push(mystring);
            outQueue.pop();
          }

          if (stlstring == "tan")
          {
            if (ansStack.size() == 0)
            {
              CalculatorProcessor::errorReturn(textbox);
              errorFlag = true;
              break;
            }
            float trigNum = (float)wxAtof(ansStack.top());
            ansStack.pop();

            float trigAns = tan(trigNum);
            wxString mystring = wxString::Format(wxT("%f"), trigAns);

            ansStack.push(mystring);
            outQueue.pop();
          }

          if (stlstring == "cos")
          {
            if (ansStack.size() == 0)
            {
              CalculatorProcessor::errorReturn(textbox);
              errorFlag = true;
              break;

            }
            float trigNum = (float)wxAtof(ansStack.top());
            ansStack.pop();

            float trigAns = cos(trigNum);
            wxString mystring = wxString::Format(wxT("%f"), trigAns);

            ansStack.push(mystring);
            outQueue.pop();
          }


          if (((ansStack.size() < 2) && (outQueue.size() > 0)) && ((stlstring != "sin") || (stlstring != "cos") || (stlstring != "tan")))
          {
            CalculatorProcessor::errorReturn(textbox);
            errorFlag = true;
            break;
          }

          if ((ansStack.size() >= 2) && (outQueue.size() > 0))
          {
           
            
            float secondNum = (float)wxAtof(ansStack.top());
            ansStack.pop();

            
            float firstNum = (float)wxAtof(ansStack.top());
            ansStack.pop();

            if (outQueue.size() == 0)
            {
              CalculatorProcessor::errorReturn(textbox);
              errorFlag = true;
              break;
            }

            wxString opFuncGet = outQueue.front(); //character to process 
          
            std::string opFunc = std::string(opFuncGet.mbc_str());

            if (opFunc == "+")
            {
              float ans = firstNum + secondNum;
              wxString mystring = wxString::Format(wxT("%f"), ans);
              ansStack.push(mystring);
              outQueue.pop();
            }
            if (opFunc == "-")
            {
              float ans = firstNum - secondNum;
              wxString mystring = wxString::Format(wxT("%f"), ans);
              ansStack.push(mystring);
              outQueue.pop();
            }
            if (opFunc == "*")
            {
              float ans = firstNum * secondNum;
              wxString mystring = wxString::Format(wxT("%f"), ans);
              ansStack.push(mystring);
              outQueue.pop();
            }
            if (opFunc == "/")
            {
              float ans = firstNum / secondNum;
              wxString mystring = wxString::Format(wxT("%f"), ans);
              ansStack.push(mystring);
              outQueue.pop();
            }
            if (opFunc == "%")
            {
              int ans = (int)firstNum % (int)secondNum;
              wxString mystring = wxString::Format(wxT("%i"), ans);
              ansStack.push(mystring);
              outQueue.pop();
            }
          }
        }
      }
      if (ansStack.size() == 0)
      {
      
        errorFlag = true;
        break;
      }
      float answer = (float)wxAtof(ansStack.top());
      ansStack.pop();
      wxString mystring = wxString::Format(wxT("%f"), answer);
      textbox->AppendText(mystring);

    }
  }
    

 


