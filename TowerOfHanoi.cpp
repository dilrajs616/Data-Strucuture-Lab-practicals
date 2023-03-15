#include<iostream>
#include<stack> 
#include"screenFunctions.h"

using namespace std;

stack<char> operatorsStack; 

int getPriorityValue(char);
string conversion(string);

int main(){
    while(true){
        clearScreen();
        operatorsStack.empty();
        string infixExpression, reversedExpression, outputExpression;
        cout << "\t\t********Expression Conversion*********" << endl
        << endl << "1. Postfix Expression." << endl
        << "2. Exit" << endl << "Choose an option: ";
        
        int option;
        option = int(getch()-48);
        
        switch (option)
        {
        case 1:
            clearScreen();
            cout << "\t\t********Infix to PostFix*********" << endl;
            cout << endl << "Enter the infix expression: ";
            cin >> infixExpression;
            
            for (auto& c : infixExpression)
                c = std::toupper(c);
            outputExpression = conversion(infixExpression);

            cout << endl << "Output Expression is: ";
            for (int i = 0; i < outputExpression.size(); i++)
                cout << outputExpression[i];
            holdScreen();
            break;

        case 2:
            cout << "Thanks for using me." << endl << "bye bye.";
            exit(0);
            break;

        default:
            clearScreen();
            cout << "Enter a valid option" << endl;
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
        if((infixExpression[i]>=65 && infixExpression[i]<=90) || (infixExpression[i]>=48 && infixExpression[i]<=57))
                outputExpression += infixExpression[i];
        
        else{
            priorityValue = getPriorityValue(infixExpression[i]);
            while(!operatorsStack.empty() && priorityValue <= getPriorityValue(operatorsStack.top())){
                outputExpression += operatorsStack.top();
                operatorsStack.pop();
            }
            operatorsStack.push(infixExpression[i]);
            if(operatorsStack.top() == ')'){
                operatorsStack.pop();
                while (!operatorsStack.empty() && operatorsStack.top() != '('){
                    outputExpression += operatorsStack.top();
                    operatorsStack.pop();
                }
                operatorsStack.pop();
            }
        }
    }
    while(!operatorsStack.empty()){
        outputExpression += operatorsStack.top();
        operatorsStack.pop();
    }
    return outputExpression;
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