#pragma once
#include "Iterator.h"
#include <iostream>
using namespace std;

class List
{
private:
    class Node
    {
    public:
        Node(int data = 0, Node* previous = NULL, Node* next = NULL)
        {
            this->data = data;
            this->previous = previous;
            this->next = next;
        };

        ~Node()
        {  }

        int data;
        Node* next;
        Node* previous;
    };

    Node* head; //head list
    Node* tail;  //tail list
    size_t list_size;  //list size

public:
    List(Node* head = NULL, Node* tail = NULL) {
        this->head = head;
        this->tail = tail;
        list_size = 0;
    };

    void push_back(int); // add item to end
    void push_front(int); //add to begin
    size_t get_size(); // get list size
    void pop_back(); // delete last item
    void pop_front(); // delete first item
    int at(size_t); // get item by index
    void remove(size_t); // delete item by index
    void insert(int, size_t); // add item before "size_t" item
    void print_to_console(); // print item to console
    void clear(); // clear list
    void set(size_t, int); // change "size_t" item to "int"
    bool isEmpty(); // test for emptiness
    void push_back(List); // add another list to end
    Iterator* create_iterator(int); // iterator

    class List_Iterator : public Iterator
    {
    private:
        Node* current;
        int size;
    public:
        List_Iterator(Node* head, int start, int max) {
            size = max;
            current = head;
            int i = 0;

            if (head != NULL)
            {
                if (start >= size)
                {
                    throw out_of_range("Index is greater than list size");
                }

                while ((i < start) && (current->next != NULL))
                    current = current->next;
            }
        };

        int next();
        bool has_next();
        ~List_Iterator() {
            delete current;
        }
    };

    ~List()
    {
        while (head->next != NULL) //while there are more elements
        {
            head = head->next;
            delete head->previous;
        }
        list_size = 0;
        delete head;
    };
};