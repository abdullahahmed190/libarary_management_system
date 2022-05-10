//Libtary.h

#pragma once
//#include <iostream>
#include<conio.h>

#define getch() _getch()
using namespace std;
class library
{
private:
    struct Node
    {
        int id;
        string name, author, publisher;
        Node* next_add;
    };

public:
    Node* head = NULL;
    void menu();
    void insert();
    void del();


    void sort();
    void update();
    void search();
    void show();

};