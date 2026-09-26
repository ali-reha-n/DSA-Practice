#include <iostream>


//THe class for the linked list
class Node {
public:
	int value;
	Node* next;
};

void insertAtHead(Node*&head, int new_value) {
	//new node creation
	Node* temp = new Node();

	//adding value to new node
	temp->value = new_value;

	//Pointing the new node to the current head
	temp->next = head;

	//pointing the head to the new node
	head = temp;
}


void insertAtThird(Node* head, int val ) {

	//checking if the list is null or has only one node
	if (head == nullptr || head->next == nullptr ) {
		std::cout << "Your list is empty or has less than two nodes so cannot insert a node at 3rd position." << std::endl;
		return;
	}

	//initializing the node to insert
	Node* temp = new Node();
	temp->value = val;

	//moving to the second node
	head = head->next;

	//pointing the new node to the fourth node
	temp->next = head->next;


	//pointing the second node to the new third node
	head->next = temp;
}



void displayList(Node * head) {
	int i = 1;
	while(head->next != nullptr) {
		std::cout << "Node-" << i << ": " << head->value << std::endl;
		i++;
		head = head->next;
	}
}

void deleteNode( int val , Node* head) {
	Node* temp = new Node();

	//loop runs until the list is traversed completely
	while (head->next != nullptr) {


		//stops before the node to be deleted
		if (head->next->value == val) {
			temp = head->next;


			head->next = head->next->next;
			
			std::cout << "Node containing value " << temp->value << " deleted " << std::endl;
			delete temp;

			return;
		}

		head = head->next;
	}
	std::cout << "Node not found in list. Nothing deleted." << std::endl;
}

void countNodes(Node* head) {
	int count = 0;
	while (head->next != nullptr) {
		count++;
		head = head->next;
	}

	std::cout << "Number of Nodes in the list: "<< count << std::endl;
}

void main() {
	char c;
	int val;

	Node* head = new Node();

	//creating linked list
	do {
		std::cout << "Enter value for linked list node" << std::endl;
		std::cin >> val;

		insertAtHead(head , val);

		std::cout << "Do you want to add more nodes? (Y/n)" << std::endl;
		std::cin >> c;
	} while (c!='n');

	//displaying the list
	std::cout << "Your list is: " << std::endl;
	displayList(head);


	//inserting a value at the third node. 
	std::cout << "What value do you want to insert at the third node?" << std::endl;
	std::cin >> val;
	insertAtThird(head , val);

	//printing
	std::cout << "Now your list is:" << std::endl;
	displayList(head);

	//deleting a  node by value
	std::cout << "What value node do you want to delete?" << std::endl;
	std::cin >> val;
	deleteNode(val, head);

	//counting the number of nodes
	countNodes(head);

}
