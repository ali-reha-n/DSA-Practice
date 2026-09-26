#include <iostream>

class Node {
public:
	int value;
	Node* next;
};


class CircularList {

public:
	Node* head=nullptr ;
	Node* tail=nullptr ;

	void insert(int val) {
		Node* temp = new Node();
		temp->value = val;
		if (head == nullptr) {//if one node only point head and tail to same node and make the node point to itself through head node
			head = temp;
			tail = temp;
			temp->next = head;
		}
		else {
			//add the node to the tail
			tail->next = temp;
			//point the last new node to the head again
			temp->next = head;
			//point tail to the new last node
			tail = temp;
		}
	}

	void deleteFront() {
		if (head == nullptr) {
			std::cout << "List Empty!!!" << std::endl;
			return;
		}
		else if (head == tail) {//case if one node only
			head = nullptr;
			tail = nullptr;
			return;
		}

		Node* temp;
		temp = head; //temporarily store the first node
		head = head->next; //move the head one place ahead
		tail->next = head; //point the last node to the new head node
		delete temp; //deleting the first node
	}

	void display() {
		if (head == nullptr) return;
		Node* traversal = head;
		std::cout << "{";
		do {
			std::cout << " " << traversal->value << " ";
			traversal = traversal->next;
		} while (traversal != head); //traverse by a do while loop so that the head is not compared first time but only when it appears the second time
		std::cout << "}" << std::endl;
	}

	bool isCircular() {
		if (tail->next == head) {
			return true;
		}
		else {
			return false;
		}
	}
};


void main() {
	CircularList c;

	c.insert(1);
	c.insert(2);
	c.insert(3);
	c.insert(4);
	c.insert(5);

	c.display();

	std::cout << "Deleting the front node....." << std::endl;
	c.deleteFront();
	c.display();

	std::cout << "Is the list ACTUALLY circular? " << c.isCircular() << std::endl;

}
