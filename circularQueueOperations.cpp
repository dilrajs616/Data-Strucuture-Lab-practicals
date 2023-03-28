//practical number fifth
//design develop and implement a menu driven program for the following operations on circular queue of characters
//1. insert an element onto circular queue
//2. delete an element from circular queue
//3. demonstrate overflow and underflow situations on cirular queue
//4. display the status of circular queue
//5. exit
//Support the program with appropriate functions for each of the above operations.

#include <iostream>
#include "screenFunctions.h"
using namespace std;

#define MAX 6 // Maximum size of circular queue

class CircularQueue {
    private:
        char queue[MAX];
        int front;
        int rear;

    public:
        CircularQueue() {
            front = -1;
            rear = -1;
        }

        // Function to check if circular queue is empty
        bool isEmpty() {
            return (front == -1 && rear == -1);
        }

        // Function to check if circular queue is full
        bool isFull() {
            return ((rear + 1) % MAX == front);
        }

        // Function to insert an element into circular queue
        void enqueue(char value) {
            if (isFull()) {
                cout << "Circular Queue Overflow!" << endl;
            }
            else if (isEmpty()) {
                front = rear = 0;
                queue[rear] = value;
            }
            else {
                rear = (rear + 1) % MAX;
                queue[rear] = value;
            }
            holdScreen();
        }

        // Function to delete an element from circular queue
        void dequeue() {
            if (isEmpty()) {
                cout << "Circular Queue Underflow!" << endl;
            }
            else if (front == rear) {
                front = rear = -1;
            }
            else {
                front = (front + 1) % MAX;
            }
            cout << "Element DELETED";
            holdScreen();
        }

        // Function to display the circular queue
        void display() {
            clearScreen();
            if (isEmpty()){
                cout << "Circular Queue is empty!" << endl;
                return;
            }
            else if (isFull()){
                cout << "Circular queues is full!" << endl;                
            }
            else{
                cout << "Queue has " << rear << " elements. " << endl
                << "There are " << MAX - rear << " free spaces left." << endl;
            }
            cout << "Front element of queue is" << queue[front] << endl;
            holdScreen();
        }
};

int main() {
    int choice;
    char value;
    CircularQueue cq;

    do {
        clearScreen();
        cout << "---------- Menu ----------" << endl;
        cout << "1. Insert an Element" << endl;
        cout << "2. Delete an Element" << endl;
        cout << "3. Display the Circular Queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        choice = int(getch()-'0');

        switch (choice) {
            case 1:
                clearScreen();
                cout << "**************Insert an Element*************" << endl;
                cout << "Enter the element to insert: ";
                cin >> value;
                cq.enqueue(value);
                break;

            case 2:
                cq.dequeue();
                break;

            case 3:
                cq.display();
                break;

            case 4:
                cout << "Exiting Program!" << endl;
                exit(0);

            default:
                cout << "Invalid Choice! Try Again." << endl;
                holdScreen();
                break;
        }

        cout << endl;
    } while (true);

    return 0;
}