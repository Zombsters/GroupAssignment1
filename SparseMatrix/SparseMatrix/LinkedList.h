#pragma once
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<sstream>
using namespace std;

struct Node {
	int data;
	Node* right;
	Node* down;
};

class LinkedList {
private:
	Node* head;
	int size;

public:
	LinkedList();
	~LinkedList();
	
	void addAtHead(int data);
	Node* getNewNode(int data);

	void Print();
	int getSize();
};

LinkedList::LinkedList() { //default contructor
	head = NULL;
	size = 0;
}

LinkedList::~LinkedList() {
	Node* traverse = head;
	while (traverse != NULL) {
		Node* temp = traverse;
		traverse = traverse->right;
		delete temp; size--;
	}
}

void LinkedList::Print() {
	Node* traverse = head;
	while (traverse != NULL) {
		cout << traverse->data << " ";
		traverse = traverse->right;
	}
}

int LinkedList::getSize() {
	return size;
}

Node* LinkedList::getNewNode(int data) {
	Node* temp = new Node; 
	temp->data = data; temp->right = NULL; temp->down = NULL;
	return temp;
}

void LinkedList::addAtHead(int data) {
	Node* temp = getNewNode(data);
	temp->right = head;//point to what head is previously pointing to
	head = temp;
	size++;
}