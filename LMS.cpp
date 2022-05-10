//LMS.cpp

#include<iostream>
#include<stdexcept>
#include<string>
#include<limits>
#include "Library.h"
using namespace std;

void library::insert()
{
    system("cls");

    cout << "\n\n\t\t\t========================================================";
    cout << "\n\n\t\t\t===Library Management System ===========================";
    cout << "\n\n\t\t\t========================================================";
   
        Node* new_node = new Node;
        

        cin.ignore();
        
        while (true)
        {
            cout << "\n\n Book ID";
            if (cin>> (new_node->id))
            {
                break;
            }
            else
            {
                cout << "\n Enter a valid Integer\n";
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        cin.ignore();

        cout << "\n\nEnter Book Name";
        getline(cin, new_node->name);
        cout << "\n\n author Name";
        getline(cin, new_node->author);
        cout << "\n\n Publisher Name";
        getline(cin, new_node->publisher);
        new_node->next_add = NULL;
        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            Node* ptr = head;
            while (ptr->next_add != NULL)
            {
                ptr = ptr->next_add;
            }
            ptr->next_add = new_node;
        }
        cout << "\n\n\t\t\t New Book Inserted successfully";
    
}

void library::search()
{
    system("cls");
    int t_id, found=0;
    cout << "\n\n\t\t\t========================================================";
    cout << "\n\n\t\t\t===Library Management System ===========================";
    cout << "\n\n\t\t\t========================================================";
    if (head == NULL)
    {
        cout << "\n\n Linked List is empty";
    }
    else
    {
        cout << "\n\n Book ID:";
        cin >> t_id;
        Node   *ptr = head;
        while (ptr != NULL)
        {
            if (t_id == ptr->id)
            {
                system("cls");
                cout << "\n\n\t\t\t========================================================";
                cout << "\n\n\t\t\t===Library Management System ===========================";
                cout << "\n\n\t\t\t========================================================";
        
                cout << "\n\n Book ID: " << ptr->id;
                cout << "\n\n Book Name: " << ptr->name;
                cout << "\n\n Author Name: " << ptr->author;
                cout << "\n\n Publisher Name: " << ptr->publisher;
                found++;
            }
            ptr = ptr->next_add;

        }
        if (found == 0)
        {
            cout << "\n\n Book ID is Invalid.....";
        }
    }
}
void library::update()
{

    system("cls");
    int t_id, found=0;
    cout << "\n\n\t\t\t========================================================";
    cout << "\n\n\t\t\t===Library Management System ===========================";
    cout << "\n\n\t\t\t========================================================";
    if (head == NULL)
    {
        cout << "\n\n Linked List is empty";
    }
    else
    {
        cout << "\n\n Book ID:";
        cin >> t_id;
        Node* ptr = head;
        while (ptr != NULL)
        {
            if (t_id == ptr->id)
            {
                system("cls");
            
                cout << "\n\n\t\t\t========================================================";
                cout << "\n\n\t\t\t===Library Management System ===========================";
                cout << "\n\n\t\t\t========================================================";
               // cout << "\n\n Book ID: ";
                while (true)
                {
                    cout << "\n\n Book ID";
                    if (cin >> (ptr->id))
                    {
                        break;
                    }
                    else
                    {
                        cout << "\n Enter a valid Integer\n";
                        cin.clear();
                        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    }
                }
                cin.ignore();
                //cin>>ptr->id;
                cout << "\n\n Book Name: ";

                    getline(cin, ptr->name);
                    cout << "\n\n Author Name: ";
                    getline(cin, ptr->author);
                    cout << "\n\n Publisher Name: "; 
                    getline(cin,ptr->publisher);
                found++;
                cout << "\n\n\t\t\t update Book successfully";
            }
            ptr = ptr->next_add;

        }
        if (found == 0)
        {
            cout << "\n\n Book ID is Invalid.....";
        }
    }

}

void library::del()
{
    system("cls");
    int t_id, found=0;
    cout << "\n\n\t\t\t========================================================";
    cout << "\n\n\t\t\t===Library Management System ===========================";
    cout << "\n\n\t\t\t========================================================";
    try{
    if (head == NULL)
    {
        throw underflow_error("\n\n Linked list is Empty");
    }
    else
    {
        cout << "\n\n Book ID:";
        cin >> t_id;
        if (t_id == head->id)
        {
            Node* ptr = head;
            head = head->next_add;
            delete ptr;
            cout << "\n\n Delete book Successfully";
            found++;
        }
        else
        {
            Node* pre = head;
            Node* ptr = head;
            while (ptr != NULL)
            {
                if (t_id == ptr->id)
                {
                    pre->next_add = ptr->next_add;
                    delete ptr;
                    cout << "\n\n Delete Book successfully";
                    found++;
                    break;
                }
                pre = ptr;
                ptr = ptr->next_add;
            }
        }
        if (found == 0)
        {
            cout << "\n\n Book ID is Invalid";
        }
    }
    }
    catch (underflow_error &error)
    {
        cout << "\nException occured"<<endl;
        cout << error.what();

    }
}

void library::sort()
{
    
    if (head == NULL)
    {

        system("cls");
        cout << "\n\n\t\t\t========================================================";
        cout << "\n\n\t\t\t===Library Management System ===========================";
        cout << "\n\n\t\t\t========================================================";
        cout << "\nLinked list is Empty";
        _getch();
        menu();
    }
    int count = 0, t_id;
    string t_name, t_author, t_publisher;
    Node    *ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next_add;
    }
    for (int i=0;i<=count;i++)
    {
        Node* ptr = head;
        for (int j = 1; j < count; j++)
        {
            if (ptr -> id>ptr->next_add->id)
            {

                //Save data into Temporory Variable
                t_id = ptr->id;
                t_name = ptr->name;
                t_author = ptr->author;
                t_publisher = ptr->publisher;

                //Save data into Current Node
                ptr->id = ptr->next_add->id;
                ptr->name = ptr->next_add->name;
                ptr->author = ptr->next_add->author;
                ptr->publisher = ptr->next_add->publisher;
                //Save data into Next Node
                ptr->next_add->id=t_id;
                ptr->next_add->name=t_name;
                ptr->next_add->author=t_author;
                ptr->next_add->publisher=t_publisher;
                
            }
            ptr = ptr->next_add;

        }
    }

}

void library::show()
{
    system("cls");

    cout << "\n\n\t\t\t========================================================";
    cout << "\n\n\t\t\t===Library Management System ===========================";
    cout << "\n\n\t\t\t========================================================";


        
        Node* ptr = head;
        while (ptr != NULL)
        {
            
                cout << "\n\n Book ID: " << ptr->id;
                cout << "\n\n Book Name: " << ptr->name;
                cout << "\n\n Author Name: " << ptr->author;
                cout << "\n\n Publisher Name: " << ptr->publisher;
                cout << "\n\n\t\t\t========================================================";
            ptr = ptr->next_add;

        }
        
    
}
 
