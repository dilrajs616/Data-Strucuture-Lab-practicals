#include<iostream>
#include<stack> 
#include<cctype>
// to use the toupper function
#include<algorithm>
//to use the inbuilt string reverse function
#include"screenFunctions.h"
/*user defined header file which includes 
clearScreen() and holdScreen() functions*/

using namespace std;

stack<char> operatorsStack; //to store operators of infix expression

string takeInput();
void displayOutput(string);
int getPriorityValue(char);
string conversion(string);

int main(){
    while(true){
        clearScreen();
        operatorsStack.empty();
        /*this statement clears the stack everytime the loop is executed*/

        string infixExpression, reversedExpression, outputExpression;
    
        cout << "\t\t********Expression Conversion*********" << endl
        << endl << "1. Postfix Expression." << endl
        << "2. Prefix Expression." << endl
        << "3. Exit." << endl
        << endl << "Choose an option: ";
        
        int option;
        option = int(getch()-48);
        
        switch (option)
        {
        case 1:
            clearScreen();
            cout << "\t\t********Infix to PostFix*********" << endl;
            infixExpression = takeInput();
            outputExpression = conversion(infixExpression);

            displayOutput(outputExpression);
            holdScreen();
            break;
        
        case 2:
            clearScreen();
            cout << "\t\t********Infix to PreFix*********" << endl;
            infixExpression = takeInput();
            for (int i = infixExpression.size()-1; i >=0; i--)
            {
                if(infixExpression[i] == ')')
                    infixExpression[i] = '(';

                else if(infixExpression[i] == '(')
                    infixExpression[i] = ')';
                
                reversedExpression += infixExpression[i];
            }
            
            outputExpression = conversion(reversedExpression);

            reverse(outputExpression.begin(), outputExpression.end());

            displayOutput(outputExpression);
            holdScreen();
            break;

        case 3:
            cout << "Thanks for using me." << endl << "bye bye.";
            exit(0);
            break;

        default:
            clearScreen();
            cout << "Enter a valid expression" << endl;
            holdScreen();
            break;
        }
    }
    return 0;
}

string conversion(string infixExpression){
    string outputExpression;
    int priorityValue;

    for (int i = 0; i < infixExpression.size(); i++)
    {
        // Operands will be pushed to the outputExpression string directly.
        if((infixExpression[i]>=65 && infixExpression[i]<=90) 
            || (infixExpression[i]>=48 && infixExpression[i]<=57))
                outputExpression += infixExpression[i];
        
        /* Operators will invoke the else block. Here they will be assigned
        with a priority value*/
        else{
            priorityValue = getPriorityValue(infixExpression[i]);
            
            /*if operatorsStack is empty then the operator will be pushed to stack
            else they'll check previously entered operators*/
            if(operatorsStack.empty())
                operatorsStack.push(infixExpression[i]);
            
            else{
                /*if the priority value of previously entered operator in stack
                is higher than the current operand then previous operand will be
                popped and added to outputExpression string and then current
                operator is pushed to stack*/
                if(priorityValue > 0 && priorityValue < 4)
                    while(!operatorsStack.empty() 
                        && priorityValue <= getPriorityValue(operatorsStack.top())){
                            outputExpression += operatorsStack.top();
                            operatorsStack.pop();
                    }
                
                operatorsStack.push(infixExpression[i]);

                /*if a bracket is closed then all the operators in the stack
                till the opening bracket will be popped and added to the 
                outputExpression according to their priority*/
                if(operatorsStack.top() == ')'){
                    operatorsStack.pop();
                    
                    while (!operatorsStack.empty() && operatorsStack.top() != '(')
                    {
                        outputExpression += operatorsStack.top();
                        operatorsStack.pop();
                    }
                    
                    operatorsStack.pop();
                }
            }
        }
    }
    /*All the remaining operators will be added to outputExpression*/
    if(!operatorsStack.empty()){
        
        while(!operatorsStack.empty()){
            outputExpression += operatorsStack.top();
            operatorsStack.pop();
        }
    }
    
    return outputExpression;
}

string takeInput(){
    string inputExpression;
    cout << endl << "Enter the infix expression: ";
    cin >> inputExpression;
    
    for (auto& c : inputExpression)
        c = std::toupper(c);
    
    return inputExpression;
}

int getPriorityValue(char symbol){
    if(symbol == '^')
        return 3;
    
    else if(symbol == '*' || symbol == '/')
        return 2;
    
    else if(symbol == '+' || symbol == '-')
        return 1;
    
    else
        return 0;
}

void displayOutput(string outputString){
    
    cout << endl << "Output Expression is: ";

    for (int i = 0; i < outputString.size(); i++)
        cout << outputString[i];
}