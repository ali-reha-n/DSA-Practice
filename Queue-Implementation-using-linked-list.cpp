#include <iostream>

class Node {
public:
	int value;
	Node* next;
};


//Queue inherits the Node class to use its properties
class Queue : public Node {
public:
	//head node creation
	Node* head = new Node();

	//COnstructor
	Queue() { head = nullptr; }

	void enqueue(int val) {

		//creates a new node
		Node* temp = new Node();
		//assigns the node the value
		temp->value = val;

		//points the node to the start of the linked list which is the in point
		temp->next = head;

		//makes head point to the new node
		head = temp;
	}

	void dequeue() {

		//checks if the queue is null
		if (head == nullptr) {
			std::cout << "Queue is null. Aborting" << std::endl;
			return;
		}

		//traverse the queue
		Node* traversal = head;

		//store the previous node to assign it a null value instead of keeping it a dangling pointer.
		Node* prev = nullptr;

		//goes to the last node
		while (traversal->next!= nullptr) {
			prev = traversal;
			traversal = traversal->next;
		}

		//poits the previous node's next to nullptr
		prev->next = nullptr;

		//deletes the last node
		delete traversal;

	}

	void peek() {

		//checks if the queue is null
		if (head == nullptr) {
			std::cout << "Queue is empty" << std::endl;
			return;
		}

		//traverse the queue
		Node* traversal = head;

		//goes to the last element in the list
		while (traversal->next != nullptr) {
			traversal = traversal->next;
		}

		//prints the last element in the list which is the front of the list
		std::cout << "The front element is " << traversal->value << std::endl;

	}

	bool isEmpty() {
		if (head == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	void display() {
		Node* traversal = head;

		std::cout << "{";

		while (traversal != nullptr) {
			std::cout <<  " " << traversal->value << " ";
			traversal = traversal->next;
		}

		std::cout << "}" << std::endl;
	}
};


void main() {
	Queue q;

	std::cout << "Queue Empty? " << q.isEmpty()  << std::endl;

	q.enqueue(1);
	q.enqueue(4);
	q.enqueue(8);
	q.enqueue(6);

	q.display();

	std::cout << "Dequeueing" << std::endl;
	q.dequeue();
	q.display();
	
	std::cout << "Peeking" << std::endl;
	q.peek();

	std::cout << "Queue Empty? " << q.isEmpty() << std::endl;
}
