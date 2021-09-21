#include "List.h"
using namespace std;


void List::push_back(int add_data)
{
	if (list_size == 0) //if list is empty
	{
		head = new Node(add_data); //create head
		tail = head;
	}
	else
	{
		Node* current = new Node(add_data);
		current->previous = tail;
		tail->next = current;
		tail = current;  //set new tail
	}
	list_size++;
}

void List::push_front(int add_data)
{
	if (list_size == 0)
	{
		head = new Node(add_data);
		tail = head;
	}
	else
	{
		Node* current = new Node(add_data);
		current->next = head;
		head->previous = current;
		head = current;  //set new head
	}
	list_size++;
}

size_t List::get_size()
{
	return list_size;
}

void List::pop_back()
{
	if (list_size == 1)
	{
		list_size = 0;
		head = NULL;
		tail = NULL;
	}
	else if (list_size > 1) //list contains more than one element
	{
		tail = tail->previous; //set new tail
		delete tail->next;
		tail->next = NULL;
		list_size--;
	}
	else 
		throw out_of_range("Segmentation fault");
}

void List::pop_front()
{
	if (list_size == 1)
	{
		list_size = 0;
		head = NULL;
		tail = NULL;
	}
	else if (list_size > 1) //list contains more than one element
	{
		head = head->next; //set new head
		delete head->previous;
		head->previous = NULL;
		list_size--;
	}
	else
		throw out_of_range("Segmentation fault");
}

void List::remove(size_t index)
{
	if (index >= list_size) //index out of range
		throw out_of_range("Index is greater than list size");
	else if (index == 0) //it is first element
		pop_front();
	else if (index == list_size - 1)//it is last element
		pop_back();
	else
	{
		Node* current = head;
		while (index) //go to "index" item
		{
			current = current->next;
			index--;
		}
		current->previous->next = current->next; //cut item from list
		list_size--;
		delete current;
	}
}

int List::at(size_t index)
{
	if (index >= list_size) //index out of range
		throw out_of_range("Index is greater than list size");
	else if (index == list_size - 1)
	{
		return tail->data;
	}
	else {
		Node* current = head;
		while (index) //go to "index" item
		{
			current = current->next;
			index--;
		}
		return current->data;
	}
}

void List::insert(int add_data, size_t index)
{
	if (index >= list_size)  //index is out of range
		throw out_of_range("Index is greater than list size");
	else if (index == 0) //inserts before firs element
		push_front(add_data);
	else
	{
		Node* current = head;
		while (index)
		{
			current = current->next;
			index--;
		}
		Node* newNode = new Node(add_data, current->previous, current);  //new Node with new connections
		current->previous->next = newNode;
		current->previous = newNode;
		list_size++;
	}
}

void List::print_to_console()
{
	Node* current = head;
	while (current != NULL)
	{
		cout << current->data << "| ";
		current = current->next;
	}
}

void List::clear()
{
	if (head != NULL)
	{
		while (head->next != NULL)  //delete all elements
		{
			head = head->next;
			delete head->previous;
		}
		list_size = 0;
		head = NULL;
		tail = NULL;
	}
}

void List::set(size_t index, int data)
{
	if (index >= list_size) //index is out of range
		throw out_of_range("Index is greater than list size");
	else {
		Node* current = head;
		while (index) //go to "index" item
		{
			current = current->next;
			index--;
		}
		current->data = data; //change content
	}
}

bool List::isEmpty()
{
	if (head == NULL)
		return true;
	return false;
}

void List::push_back(List AddToEnd)
{
	Node* head_AddToEnd = AddToEnd.head;
	while (head_AddToEnd != NULL)
	{
		this->push_back(head_AddToEnd->data); //push new item to the end with content from transmitted list
		head_AddToEnd = head_AddToEnd->next;
	}
}

Iterator* List::create_iterator(int start) {
	return new List_Iterator(head, start, list_size);
}

bool List::List_Iterator::has_next() {
	return (current != NULL);
}

int List::List_Iterator::next() {
	if (!has_next()) {
		throw out_of_range("No more elements");
	}
	int tmp = current->data;
	current = current->next;
	return tmp;
}