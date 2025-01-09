#include<iostream>
#include<string>
#include<cstring>
#include<vector>

// // if Quistion is Bad Sintax Ex: a+(*-+)
//         if(nonParaantez[indexOf -1] == '*' || nonParaantez[indexOf -1] == '/' || nonParaantez[indexOf -1] == '*' || nonParaantez[indexOf -1] == '-') 
//         {
//             cout << "\033[5;31mSintax Error" << endl;
//             return false;
//         }
//         else if (nonParaantez[indexOf +1] == '*' || nonParaantez[indexOf +1] == '/' || nonParaantez[indexOf +1] == '*' || nonParaantez[indexOf +1] == '-')
//         {
//             cout << "\033[5;31mSintax Error" << endl;
//             return false;
//         }

using namespace std;

string deleteParaantez(string input)
{
    int openPaIndex = -1;
    int closePaIndex = -1;
    for(size_t i=0; i<strlen(input.c_str()); i++)
    {
        if(input[i] == '(')
        {
            openPaIndex = i;
        }
        else if(input[i] == ')')
        {
            if(openPaIndex == -1) // if First Close // raise Error
            { 
                cout << "Parantez Error (?)" << endl;
                return "err";
            }
            else{
                closePaIndex = i;   //save Close Index
                break;
            }
        }
    }

    // now avilable start and end (Parantez), now Get Math String

    string Result;
    for(size_t a=openPaIndex+1;a<closePaIndex; a++) // Get Quistion, NON Paraantez()
    {
        if(input[a] == ' ') //Delete EMPTY Index
        {
            continue;
        }
        Result += input[a];
    }

    return Result;
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


string math(string QuistionInput)
{

    string nonParaantez;
    for(size_t u=0; u < strlen(QuistionInput.c_str()); u++) // Delete Empty Index
    {
        if(QuistionInput[u] == ' ')
        {
            continue;
        }
        else
        {
            nonParaantez += QuistionInput[u];
        }
    }

    cout << "Quistion: " <<nonParaantez << endl;

    while (is_Quistion(nonParaantez))
    {

        
        string x,y;
        char operatorSym;
        int startQuistionIndex = -1;
        int endQuistionIndex = -1;
        int indexOf = -1;
        for (size_t op = 0; op < 2; op++)   // Dected OPERATOR Index
        {
            
            for (size_t i = 0; i < strlen(nonParaantez.c_str()); i++)   // For All String
            {
                if(op == 0) // First * /
                {
                    if(nonParaantez[i] == '*')
                    {
                        operatorSym = '*';
                        indexOf = i;
                        break;
                    }
                    else if(nonParaantez[i] == '%')
                    {
                        operatorSym = '%';
                        indexOf = i;
                        break;
                    }
                }
                if(op == 1) 
                {
                    if(nonParaantez[i] == '+')
                    {
                        operatorSym = '+';
                        indexOf = i;
                        break;
                    }
                    else if(nonParaantez[i] == '-')
                    {
                        operatorSym = '-';
                        indexOf = i;
                        break;
                    }
                }
                
            }
            if(indexOf != -1)   // IF sucsessfully to get IndexOf OPERATOR
            {
                break;
            }

            if(op == 3 && indexOf == -1)// operator Not Found
            {
                cout << "Sintax Error: Operator Can not Dected" << endl;
                exit(1);
            }
        }


        cout << "indexOfOperator: " << indexOf << endl;
        
        for(size_t i=1; i <= strlen(nonParaantez.c_str()); i++) // get x and y arg Range
            {

                if(nonParaantez[indexOf - i] == '*' || nonParaantez[indexOf - i] == '/' || nonParaantez[indexOf - i] == '+' || nonParaantez[indexOf - i] == '-' || (indexOf - i) == 0)
                {
                    if(startQuistionIndex == -1)
                    {
                        startQuistionIndex = indexOf - i;

                    }
                }

                if(nonParaantez[indexOf + i] == '*' || nonParaantez[indexOf + i] == '/' || nonParaantez[indexOf + i] == '+' || nonParaantez[indexOf + i] == '-' || (indexOf + i) == strlen(nonParaantez.c_str()) )
                {
                    if(endQuistionIndex == -1)
                    {
                        endQuistionIndex = indexOf + i;
                    }

                }


            }

            cout << "Start: " << startQuistionIndex << endl; 
            cout << "End: " << endQuistionIndex << endl; 
                

            ////////////////////////////////////////////////////////////////////////////////////////////

        if(startQuistionIndex == -1 || endQuistionIndex == -1 ) // IF Fill start and end index is Fail
        {
            cout << "Start OR End Index Dected Fail" << endl;
            break;
        }
        else // if fill is SUCSESSFULL
        {
            string x = "";
            for (size_t i = startQuistionIndex; i < indexOf; i++)   //Get X With Range, Filter Operator
                {
                    x += nonParaantez[i];
                }

            string y = "";
            for(size_t o=indexOf + 1; o < endQuistionIndex; o++)// Get Y With Range 
                {
                    y += nonParaantez[o];
                    
                }     
                ////////////////////////////////////////////////////////////////////////////////////////

            string result;
            if(operatorSym == '*')
                    {
                        result = to_string(multiplication(stoi(x), stoi(y)));
                    }
            else if(operatorSym == '/')
                    {
                        result =  stoi(x) / stoi(y);
                    }
            else if(operatorSym == '+')
                    {
                        result =  stoi(x) + stoi(y);
                    }
            else if(operatorSym == '-')
                    {
                        result =  stoi(x) - stoi(y);
                    }
            else
                    {
                        cout << "Not Quistion" << endl;
                        return 0;
                    } 
            

            cout << "X: " << x << endl << "Y: " << y << endl;
            cout << "Debugs Result: " << stoi(x) +  stoi(y) << endl;
            
            nonParaantez.erase(startQuistionIndex, endQuistionIndex);

            nonParaantez.insert(startQuistionIndex, result);

            cout << "\033[5;32mResultTMP: " << result << "\033[0m" <<  endl;
            cout << "\033[5;32mFULLResult: " << nonParaantez << "\033[0m" <<  endl;


        }
    }
    return nonParaantez;
}

bool cal(string User_quistion)
{
    string nonParaanteze = User_quistion;   //Get Quistion Paraantez
    while(is_Quistion(nonParaanteze))
    {
        if(User_quistion.find("(") >= 1844674407370900000)  // if open Paraantez Not found
        {
            if(User_quistion.find(")") <= 1844674407370900000)
            {
                cout << "Sintax Error: Paraantez Error ?)" <<endl;
                return false;
            }
            else    // iF All Parantez Not Found
            {
                math(User_quistion);
                cout << "End Prosess" << endl;
                break;
            }
        }
        else
        {   // If Paraantez Is Found
            if(User_quistion.find(")") <= 1844674407370900000)  //Check INCOMPLATE , open not found but close found
            {
                cout << "Sintax Error: Paraantez not found ?)" << endl;
                return false;
            }
            else    // Prosess Paraantez
            {
                //coming Soon
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