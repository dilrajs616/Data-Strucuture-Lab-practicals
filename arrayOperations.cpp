#include<iostream>
#include<stdlib.h>
#include<vector>
#include<conio.h>

using namespace std;

class Arrays
{
    vector<int> arr;
  public:
    Arrays();
    void condition();
    void create();
    void display();
    void add();
    void deleting();
    int getIndex(int condition);
};

Arrays :: Arrays(){
    condition();
}

void Arrays :: condition(){
    int condition = 1, number;
    while(condition)
    {   
        system("cls");
        cout << "Press 1 to create an array." << endl
        << "Press 2 to display the the array." << endl
        << "Press 3 to add an element at a given index." << endl
        << "Press 4 to delete a particular index." << endl
        << "Press 5 to exit." << endl ;
        number = int(getch()-48);
        
        switch(number){
            case 1: create();
            break;
            case 2: display();
            break;
            case 3: add();
            break;
            case 4: deleting();
            break;
            case 5: cout << "Thanks for using me." << endl;
            condition = 0;
            break;
            default: cout << "Please choose a valid option." << endl;
        }
    }
}

void Arrays :: create(){
    system("cls");
    cout << "********Create an Array*********" << endl;
    int size;
    size = getIndex(1);
    cout << "Enter the values: ";
    for (int i = 0; i < size; i++)
    {
        int value;
        cin >> value;
        arr.push_back(value);
    }
    cout << "Array has been successfully created." << endl << endl 
    << "Press any key to continue";
    if(getch());
}

void Arrays :: display(){
    system("cls");
    if(arr.empty())
        cout << "Please create an array first." << endl;
    else {
        cout << "Your array is: " ;
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << " " ;
        cout << endl << "Press any key to continue." ;
        if (getch());
    }
}

void Arrays :: add(){
    system("cls");
    cout << "********Add an Element*********" << endl;
    int index, value;
    index = getIndex(0);
    cout << "Enter the value: ";
    cin >> value;
    arr.insert(arr.begin() + index-1, value);
    cout << "Element has been successfully inserted."
    << endl << endl <<"Press any key to continue.";
    if(getch());
}

void Arrays :: deleting(){
    system("cls");
    cout << "********Remove an Index*********" << endl;
    int index;
    index = getIndex(0);
    arr.erase(arr.begin() + index-1);
    cout << "Element has been successfully deleted."
    << endl << endl <<"Press any key to continue.";
    if(getch());
}

int Arrays :: getIndex(int condition){
    if(condition){
        cout << "Enter the size of array: ";
        cin >> condition;
        return condition;
    }
    else{
        cout << "Enter the index: ";
        cin >> condition;
        return condition;
    }
}

int main()
{
    Arrays ob;
}
