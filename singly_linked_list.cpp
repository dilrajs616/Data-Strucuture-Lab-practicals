/*
1. Create a singly linked list of n students by using front insertion
2. Display the status of singly linked list and count the number of nodes in it
3. Perform insertion/deletion at end of singly linked list
4. Perform insertion and deletion at front of singly linked list
5. Exit*/

#include<iostream>
#include"screenFunctions.h"
#include<string>
using namespace std;

struct Node{
    string name;
    int uni_roll_no;
    int class_roll_no;
    string branch;
    struct Node* next;
};

struct Node * head = NULL;

void initialize_list() {
    clearScreen();
    cout << "Enter the number of students: ";
    int count;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        Node* new_node = new Node;
        cout << "Enter name of "<<i+1<<" student: ";
        cin >> new_node->name;
        cout << "Enter university roll number of "<<i+1<<" student: ";
        cin >> new_node->uni_roll_no;
        cout << "Enter class roll number of "<<i+1<<" student: ";
        cin >> new_node->class_roll_no;
        cout << "Enter Branch of "<<i+1<<" student: ";
        cin >> new_node->branch;
        new_node->next = head;
        head = new_node;
    }
    cout << "Data successfully added";
    holdScreen();
}

void display_list() {
    clearScreen();
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        cout << temp->name << endl
        << temp->uni_roll_no << endl
        << temp-> class_roll_no << endl
        <<temp->branch << endl;
        temp = temp->next;
        count++;
    }
    cout << "Total number of nodes = " << count ;
    cout << endl;
    holdScreen();
}

void insert_front(){
    clearScreen();
    Node* new_node = new Node;
    cout << "Enter name of student: ";
    cin >> new_node->name;
    cout << "Enter university roll number of student: ";
    cin >> new_node->uni_roll_no;
    cout << "Enter class roll number of student: ";
    cin >> new_node->class_roll_no;
    cout << "Enter Branch of student: ";
    cin >> new_node->branch;
    new_node->next = head;
    head = new_node;
    cout << "Data successfully added";
    holdScreen();
}

void delete_front() {
    clearScreen();
    if (head == NULL) {
        cout << "List is empty." << endl;
        holdScreen();
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    cout << "Data successfully deleted." << endl;
    holdScreen();
}

void insert_end(){
    clearScreen();
    Node* new_node = new Node;
    cout << "Enter name of student: ";
    cin >> new_node->name;
    cout << "Enter university roll number of student: ";
    cin >> new_node->uni_roll_no;
    cout << "Enter class roll number of student: ";
    cin >> new_node->class_roll_no;
    cout << "Enter Branch of student: ";
    cin >> new_node->branch;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
        cout << "Data successfully added." << endl;
        holdScreen();
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    cout << "Data successfully added." << endl;
    holdScreen();
}


void delete_end() {
    clearScreen();
    if (head == NULL) {
        cout << "List is empty." << endl;
        holdScreen();
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        cout << "Data successfully deleted." << endl;
        holdScreen();
        return;
    }
    Node* second_last = head;
    while (second_last->next->next != NULL) {
        second_last = second_last->next;
    }
    delete second_last->next;
    second_last->next = NULL;
    cout << "Data successfully deleted." << endl;
    holdScreen();
}

int main(){
    /*Program to store data of students in a singly linked list*/
    while(true){
        clearScreen();
        cout << "Choose form following options: " << endl
        <<"1. Enter data of n students." << endl
        <<"2. Display status of list of students." << endl
        <<"3. Insert from front." << endl
        <<"4. Delete from front." << endl
        <<"5. Insert from end" << endl
        <<"6. Delete from end" << endl
        <<"7. Exit." << endl << endl 
        <<"Enter your option: ";
        int option;
        cin >> option;
        switch (option)
        {
            case 1:
                initialize_list();
                break;
            case 2:
                display_list();
                break;
            case 3:
                insert_front();
                break;
            case 4:
                delete_front();
                break;
            case 5:
                insert_end();
                break;
            case 6:
                delete_end();
                break;
            case 7:
                cout << "Thanks for using.";
                exit(0);
            default:
                cout << "Enter a valid option.";
                break;
        }
    }
    return 0;
}