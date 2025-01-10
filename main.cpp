#include<iostream>
#include<string>
#include<cstring>
#include <algorithm>
#include<cmath>

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
    string quistion = User_quistion;   // Updatable quistion
    if(!is_Quistion(quistion))
    {
        #ifdef _WIN32
            cout << "Result: " << quistion << endl;
        #else
            cout << "\033[5;32mResult: " << quistion << "\033[0m" << endl;
        #endif
    }
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

                #ifdef _WIN32
                    cout << "Result: " << result << endl;
                #else
                    cout << "\033[5;32mResult: " << result << "\033[0m" << endl;
                #endif
                
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

                #ifdef _WIN32
                    cout << "Result: " << RESULT << endl;
                #else
                    cout << "\033[5;32mResult: " << RESULT << "\033[0m" << endl;
                #endif


                return true;
            }
        }
    }

    return true;
    
    

    
}

string FixBackParaantezOperator(string txt)
{   
    string text = txt;
    if(text.find('(') == string::npos) //Paraantez is Not Found
    {
        return text;
    }
    else   //Paraantez Exist
    {
        for(size_t i=0; i < strlen(text.c_str()); i++)
        {
            if(i > 0)   // FIX text[-1] code, fix
            {
                if(text[i] == '(')
                {
                    if(text[i - 1] == '(' || text[i - 1] == '*' || text[i - 1] == '/' || text[i - 1] == '+' || text[i - 1] == '-')
                    {
                        continue;
                    }
                    else
                    {
                        text.insert(i, "*");
                    }
                }
            }
            if(text[i] == ')')
            {
                if(text[i + 1] == ')' || text[i + 1] == '*' || text[i + 1] == '/' || text[i + 1] == '+' || text[i + 1] == '-' || strlen(text.c_str()) - 1 == i)
                {
                    continue;
                }
                else
                {
                    text.insert(i + 1, "*");
                }

            }
            // cout << "In Loop: "<< text << endl;
        }
        return  text;
    }
}


double tanCal(string text)
{
    return tan(stoi(text));
}

double sinCal(string text)
{
    return sin(stoi(text));
}

double cosCal(string text)
{
    return cos(stoi(text));
}


int main()
{
    string userInput;
    cout << "Welcome To CCC (CLI Calculator)" << endl;
    while (true)
    {
        
        cout << "-------------------------------" << endl;
        cout << "0-Exit" << endl;
        cout << "1-tan" << endl;
        cout << "2-sin" << endl;
        cout << "3-cos" << endl;
        cout << "OR Type Math Quistion EX: 1(2+2)" << endl;
        cout << "-------------------------------" << endl;

        cout << "# ";
        getline(cin, userInput);
        cout << endl;

        
        if (userInput == "0") //exit
        {
            exit(0);
        }
        else if(userInput == "1")   // tan
        {
            cout << "tan-# ";
            getline(cin, userInput);
            cout << endl;

            cout << "-------------------------------" << endl;
            
            #ifdef _WIN32
                cout << "tan Result:" << tanCal(userInput) << endl;
            #else
                cout << "\033[5;33mtan Result:" << tanCal(userInput)  << "\033[0m" << endl;
            #endif

            
        }
        else if(userInput == "2")   //Sin
        {
            cout << "Sin-# ";
            getline(cin, userInput);
            cout << endl;

            cout << "-------------------------------" << endl;

            #ifdef _WIN32
                cout << "sin Result:" << sinCal(userInput) << endl;
            #else
                cout << "\033[5;33msin Result:" << sinCal(userInput)  << "\033[0m" << endl;
            #endif

        }
        else if(userInput == "3") // Cos
        {
            cout << "Cos-# ";
            getline(cin, userInput);
            cout << endl;

            cout << "-------------------------------" << endl;

            #ifdef _WIN32
                cout << "Cos Result:" << cosCal(userInput) << endl;
            #else
                cout << "\033[5;33mCos Result:" << cosCal(userInput)  << "\033[0m" << endl;
            #endif

            

        }
        else    // More Calculate
        {
            userInput = FixBackParaantezOperator(userInput);
            cal(userInput);
        }
    

    }
    

}