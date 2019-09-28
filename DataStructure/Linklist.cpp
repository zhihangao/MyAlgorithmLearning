#include<iostream>
using namespace std;

class node {
public:
	int value;
	node* next;
	node(int val) {
		value = val;
		next = NULL;
	}
};

class linklist {
public:
	node* head;
	linklist(int head_value) {
		head = new node(head_value);
	}
	void push_back(int value);
	int get_num();
	void print_list();
	void insert(int value, int position);
	void erase(int position);
};

void linklist::push_back(int value) {
	node* new_one = new node(value);
	node* cursor = head;
	while (cursor->next != NULL) {
		cursor = cursor->next;
	}
	cursor->next = new_one;
}

int linklist::get_num() {
	int count = 0;
	node* cursor = head;
	while (cursor != NULL) {
		count++;
		cursor = cursor->next;
	}
	return count;
}

void linklist::print_list() {
	node* cursor = head;
	while (cursor != NULL)
	{
		cout << cursor->value << " ";
		cursor = cursor->next;
	}
	cout << endl;
}

void linklist::insert(int value, int position) {
	int length = get_num();
	int count = 1;
	node* cursor = head;
    node* insert_node = new node(value);
	if (position < 0) {
		position = length + position;
	}
	if (position >= length) {
		cout << "position error" << endl;
	}
	else if (position == 0) {
		insert_node->next = head;
		head = insert_node;
	}else
	{
		while (count != position)
		{
			count++;
			cursor = cursor->next;
		}
		insert_node->next = cursor->next;
		cursor->next = insert_node;
	}

}

void linklist::erase(int position) {
	int length = get_num();
	int count = 1;
	node* cursor = head;
	if (position < 0) {
		position = position + length;
	}
	if (position >= length) {
		cout << "position error!" << endl;
	}
	else if (position == 0) {
		head = cursor->next;
		delete cursor;
	}
	else    
	{
		while (count != position)
		{
			count++;
			cursor = cursor->next;
		}
		node* p = cursor->next;
		cursor->next = p->next;
		delete p;
	}
}

int main(void) {
	linklist mylinklist = linklist(0);
	cout << mylinklist.get_num() << endl;
	mylinklist.push_back(1);
	mylinklist.push_back(3);
	mylinklist.push_back(4);
	mylinklist.print_list();
	cout << mylinklist.get_num() << endl;
	mylinklist.insert(2, 2);
	mylinklist.print_list();
	mylinklist.erase(4);
	mylinklist.print_list();
	mylinklist.erase(0);
	mylinklist.print_list();
    mylinklist.erase(3);
	mylinklist.print_list();
}