#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList{
    Node* head;
    LinkedList()
    {
        head = nullptr;
    }

    void reverse();
    void orint();
    void push(int data){
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};