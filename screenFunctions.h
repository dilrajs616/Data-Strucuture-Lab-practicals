#ifndef SCREEN_FUNCTION_H
#define SCREEN_FUNCTION_H

#include<iostream>
#include<conio.h>
#include<cstdlib>

void clearScreen(){
    system("cls");
}

void  holdScreen(){
    std :: cout << std :: endl << std :: endl 
    <<"Press any key to continue...";
    getch();
}

#endif