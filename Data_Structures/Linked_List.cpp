#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* head = NULL;

void InserNode(int data);

void Print();

void Delete_Node(int value);

void Insert_Beg(int value);

void Insert_End(int value);

void Delete_Beg();

void Delete_End();

int main()
{
    InserNode(5);
    InserNode(10);
    InserNode(15);
    InserNode(20);

    Print();

    Delete_Node(15);

    Print();

    Insert_Beg(15);

    Print();

    Insert_End(50);

    Print();

    Delete_Beg();
    Print();

    Delete_End();
    Print();


    return 0;
}

void Print()
{
    node* Current_Node;

    if(head == NULL)
    {
        cout << "Linked List is Empty!\n";
    }
    else
    {
        Current_Node = head;
        while(Current_Node != NULL)
        {
            cout << Current_Node->data << "\t";
            Current_Node = Current_Node->next;
        }
    }

    cout <<"\n";

}

void Insert_Beg(int value)
{
    node* New_Node = new node;
    New_Node->data = value;
    New_Node->next  = head;

    head = New_Node;
}


void Delete_Beg()
{

    if(head == NULL)
    {
        cout << "The Linked List is already EMPTY!!\n";
        return;
    }
    else
    {
        node * First_Node = head;
        head =  First_Node->next;
        //free(First_Node);
        delete(First_Node);
    }

}

void Delete_End()
{
    if(head == NULL)
    {
        cout << "The Linked List is already Empty !!\n";
        return;
    }
    else if (head->next == NULL)
    {
        delete(head);
        head = NULL;
    }
    /*
    else
    {
        node * Current = head;
        node * Previous = head;

        Current = Current->next;

        while(Current->next != NULL)
        {
            Previous = Current;
            Current = Current->next;
        } 

        Previous->next = NULL;
        delete(Current);
    }
    */
   else
   {
        node * ptr = head;
        while(ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        delete(ptr->next);
        ptr->next = NULL;
   }
}



void Insert_End(int value)
{
    node * New_Node = new node;
    New_Node->data = value;

    node * Current = new node;
    Current = head;
    while(Current->next != NULL)
    {
        Current = Current->next; 
    }

    Current->next = New_Node;
    New_Node->next = NULL;

}



void InserNode(int data)
{
    node * New_Node , * last;
    New_Node = new node;
    New_Node->data = data;

    if(head == NULL)
    {
        head = New_Node;
        New_Node->next = NULL; 
    }
    else
    {
        last = head;
        while(last->next != NULL)
        {
            last = last->next;
        }
        last->next = New_Node;
        New_Node->next = NULL;
    }
}


void Delete_Node(int value)
{
    node* Current_Node, *Previous;
    Current_Node = head;
    Previous = head;

    if(Current_Node->data == value)
    {
        head = Current_Node->next;
        free(Current_Node);
        return;
    }

    while(Current_Node->data != value)
    {
        Previous = Current_Node;
        Current_Node = Current_Node->next;
    }

    Previous->next = Current_Node->next;
    free(Current_Node);

}
