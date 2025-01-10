#include<iostream>
#include<string>
#include<cstring>
#include <algorithm>

using namespace std;
bool is_Quistion(string a);

string math(string Fullquistion)
{
    string quistion = Fullquistion;
    while (is_Quistion(quistion))
    {   
        int operatorIndex = -1 ;
        int StartIndex = -1;
        int EndIndex = -1;

        for(size_t aa=0; aa < 2; aa++)  //Get Operator
        {
            for(size_t i=0; i<strlen(quistion.c_str()); i++)
            {
                if(aa == 0)
                {
                    if(quistion[i] == '*')
                    {
                        operatorIndex = i;
                        break;
                    }
                    if(quistion[i] == '/')
                    {
                        operatorIndex = i;
                        break;
                    }
                }

                else if (aa == 1)
                {
                    if(quistion[i] == '+')
                    {
                        operatorIndex = i;
                        break;
                    }
                    if(quistion[i] == '-')
                    {
                        operatorIndex = i;
                        break;
                    }
                }
            }
            if(operatorIndex != -1) // if get Index Number, close for
            {
                break;
            }
        }
        
        // cout << "OperatorIndex = " << operatorIndex << endl;
        
        // Get Range
        for (size_t cycle = 1; cycle <= strlen(quistion.c_str()); cycle++)
        {
            if(quistion[operatorIndex - cycle] == '+' || quistion[operatorIndex - cycle] == '-' || quistion[operatorIndex - cycle] == '*' || quistion[operatorIndex - cycle] == '/' || operatorIndex - cycle == 0)  //Get X Range
            {
                if(operatorIndex - cycle == 0)
                {
                    StartIndex = 0;
                    break;
                }
                else
                {
                    StartIndex = (operatorIndex - cycle) + 1;
                    break;
                }
            }
        }

        for (size_t cycle = 1; cycle <= strlen(quistion.c_str()); cycle++)
        {
            if(operatorIndex + cycle == strlen(quistion.c_str()) - 1 || quistion[operatorIndex + cycle] == '+' || quistion[operatorIndex + cycle] == '-' || quistion[operatorIndex + cycle] == '*' || quistion[operatorIndex + cycle] == '/')
            { 
                if(operatorIndex + cycle == strlen(quistion.c_str()) - 1)
                {
                    EndIndex = strlen(quistion.c_str()) - 1;
                    break;
                }
                else
                {
                    EndIndex = (operatorIndex + cycle) - 1;
                    break;
                }

            }

            // cout << "LenQuistion: " << strlen(quistion.c_str() ) - 1 << endl << endl;
            // cout << "OI: " << operatorIndex + cycle << endl;
        }
        
        //Get X and Y
        string x="";
        for(size_t cycle = StartIndex; cycle < operatorIndex; cycle++)
        {
            x+=quistion[cycle];
        }
        string y="";
        for(size_t cycle = operatorIndex + 1; cycle <= EndIndex; cycle++)
        {
            y+=quistion[cycle];
        }

        string resultTMP = "";
        {   //calculat
            if(quistion[operatorIndex] == '*')
            {
                resultTMP = to_string(stoi(x) * stoi(y));
            }
            else if(quistion[operatorIndex] == '/')
            {
                resultTMP = to_string(stoi(x) / stoi(y));
            }
            else if(quistion[operatorIndex] == '+')
            {
                resultTMP = to_string(stoi(x) + stoi(y));
            }
            else if(quistion[operatorIndex] == '-')
            {
                resultTMP = to_string(stoi(x) - stoi(y));
            }
        }

        quistion.insert(EndIndex + 1, resultTMP);

        for(size_t i=0; i < strlen(quistion.c_str()); i++)  //Delete Old Quistion
        {
            if(i >= StartIndex && i <= EndIndex)
            {
                quistion[i] = ' ';
            }
        }

        
        quistion.erase(std::remove(quistion.begin(), quistion.end(), ' '), quistion.end());    //Delete Free Space

        
    }

    // cout << "Return result Math Sucsessfull: " << quistion << endl;
    return quistion;
}

bool is_Quistion(string a)
{
    for(size_t i=0; i< strlen(a.c_str()); i++)
    {
        if(a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '(' || a[i] == ')')
        {
           return true;
        }
    }

    return false;
}

bool avilableParaantez(string text)
{
    if(text.find('(') == string::npos) // if paraantez is not avilabe
    {
        return false;
    }
    else
    {
        return true;
    }
}


string deleteParaantez(string input)
{
    string Result = input;  // only First Result == input
    
    
    while (is_Quistion(Result))
    {
        if(avilableParaantez(Result) == false)
        {
            break;
        }

        int openPaIndex = -1;
        int closePaIndex = -1;

        Result.erase(remove(Result.begin(), Result.end(), ' '), Result.end());

        cout << "start Cal this: " << Result << endl;

        for(size_t i=0; i<strlen(Result.c_str()); i++)   // Get Open -AND- Close Index 
        {
            if(Result[i] == '(')
            {
                openPaIndex = i;
            }
            else if(Result[i] == ')')
            {
                if(openPaIndex == -1) // if First Close // raise Error
                { 
                    cout << "Parantez Error: First Open Pls ?)" << endl;
                    exit(1);
                    
                }
                else{
                    closePaIndex = i;   //save Close Index
                    break;
                }
            }
        }


        
        string paraantezTMP = "";
        for(size_t a=openPaIndex+1; a<closePaIndex; a++) // Get Quistion
        {
            paraantezTMP += Result[a];
        }
        
        cout << "In Parantez go to cal: " << paraantezTMP << endl;
        paraantezTMP = math(paraantezTMP);  //Calculate


        for(size_t a=openPaIndex; a<=closePaIndex; a++) //  Delete Paraantez Quistion
        {
            Result[a] = ' ';
        }

        // cout << "Open: " << openPaIndex << endl;
        // cout << "Close" << closePaIndex << endl;


        Result.insert(openPaIndex, paraantezTMP);   //Placement Result to Quistion, for create new quistion

        // cout << "NEW QUISTION Generated: " << Result << endl;
        
        

    }
    
    if(!avilableParaantez(Result) && is_Quistion(Result))
    {
        Result = math(Result);
    }
   

    

    return Result;
}


bool cal(string User_quistion)
{
    string quistion = User_quistion;   //Get Quistion Paraantez

    while(is_Quistion(quistion))
    {
        if(User_quistion.find("(") == string::npos)  // if open Paraantez Not found
        {
            if(User_quistion.find(")") != string::npos)  // if close Paraantez avilable
            {
                cout << "Sintax Error: Paraantez Error ?)" <<endl;
                return false;
            }
            else    // iF All Parantez Not Found
            {
                string result = math(User_quistion);
                cout << "Result: " << result << endl;
                break;
            }
        }
        else    // If open Paraantez Exist
        {   // If Close Paraantez Is Found
            if(User_quistion.find(")") == string::npos)  //Check INCOMPLATE , open not found but close found
            {
                cout << "Sintax Error: Paraantez not found ?)" << endl;
                return false;
            }
            else    // Prosess Paraantez
            {
                string RESULT = deleteParaantez(User_quistion);
                cout << "Result: " << RESULT << endl;
                return true;
            }
        }
    }

    return true;
    
    

    
}


int main()
{
    string userInput;
    cout << "# ";
    getline(cin, userInput);
    cout << endl;

    cal(userInput);
    

}