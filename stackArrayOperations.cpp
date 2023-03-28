#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<vector>

using namespace std;

class StackArrayOperations{
    vector<int> array;
    int sizeOfArray;
  public:
    StackArrayOperations();
    void initial();
    void choice(int);
    void createStack();
    void pushElement();
    void popElement();
    void displayStatus();
    void checkPallindorme();
    void pressButton();
    bool isEmpty();
};


StackArrayOperations :: StackArrayOperations(){
    sizeOfArray = 0;
    initial();
}

void StackArrayOperations :: initial(){
    int option;
    bool condition = true;
    while(condition){
        system("cls");
        cout << "1. Create a Stack of characters." << endl
        << "2. Push an element into the stack." << endl
        << "3. Pop an element from the stack." << endl
        << "4. Display the status of the stack."<< endl
        << "5. Check Pallindrome."<<endl
        << "6. Exit" << endl
        << "Choose from the given options: ";
        option = int(getch()-48);
        if(option==6){
            cout << endl << "Thanks for using me";
            condition = false;
        }
        else    
            choice(option);
    }
}

void StackArrayOperations :: choice(int option){
    switch(option){
        case 1:
            createStack();
            break;
        case 2:
            pushElement();
            break;
        case 3:
            popElement();
            break;
        case 4:
            displayStatus();
            break;
        case 5:
            checkPallindorme();
            break;
        default:
            cout << "Choose a Valid option.";
            pressButton();
    }
}

void StackArrayOperations :: createStack(){
    system("cls");
    cout << "********Create a Stack**********" << endl << endl; 
    cout<<"Enter the size of the stack: ";
    cin >> sizeOfArray;
    if(sizeOfArray <= 0)
        cout << "******INVALID******" << endl << "Enter a positive number." << endl;
    else
        cout << "Stack has been created." << endl ;
    pressButton();
}

void StackArrayOperations :: pushElement(){
    system("cls");
    cout << "**********Push Element*********" << endl
    <<"Enter only one element at a time." << endl
    <<"If you enter multiple elements then only first element will be pushed." << endl << endl;
    if(sizeOfArray==0)
        cout << "******INVALID******" << endl << "Create a stack first" << endl; 
    else{
        if(array.size() == sizeOfArray)
            cout<<"Stack Overflown. Can't push element.";
        else{
            int element;
            cin >> element;
            array.push_back(element);
            cout << "Element has been pushed." << endl; 
        }
    }
    pressButton();
}

void StackArrayOperations :: popElement(){
    system("cls");
    cout << "**********Pop Element*********" << endl;
    if(isEmpty());
    else{
        array.pop_back();
        cout << "Element has been successfully popped." << endl;
    }
    pressButton();
}

void StackArrayOperations :: displayStatus(){
    if(isEmpty());
    else{
        int top = array.size();
        system("cls");
        cout << "**********Display Status*********" << endl;
        cout<<"The stack has "<< top <<" elements."
        <<endl<<"Element at top of stack is '"<<array[top-1] << "'"<<endl;
    }
    pressButton();
}

void StackArrayOperations :: checkPallindorme(){    
    system("cls");
    cout << "**********Check Pallindrome*********" << endl;
    if(isEmpty());
    else{
        int topIndex = array.size()-1, indicator = 0, bottomIndex = 0;
        while(bottomIndex < topIndex){
            if(array[bottomIndex++] != array[topIndex--]){
                indicator = 1;
                break;
            }
            else 
                continue;
        }
        if(indicator)
            cout << "Stack does not form a pallindrome" << endl;
        else
            cout << "Stack forms a pallindrome." << endl;
    }
    pressButton();
}

bool StackArrayOperations :: isEmpty(){
    if(array.empty()){
        cout << "Stack is empty" << endl;
        return true;
    }
    else return false;
}

void StackArrayOperations :: pressButton(){
    cout << endl <<"Press any key to continue...";
    getch();
}

int main(){
    StackArrayOperations ob;
    return 0;
}