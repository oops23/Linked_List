# include <iostream>
# include <sstream>
# include <string>
# include "LinkedList.h"
# include "Node.h"

using std::string, std::ostream;

LinkedList::LinkedList(): head(nullptr), tail(nullptr) {
	// TODO: implement this function
}

LinkedList::~LinkedList() {
	// TODO: implement this function
	clear();
}

//copy constructor
LinkedList::LinkedList(const LinkedList& source) {
	// TODO: implement this function
	Node* source_node = source.head;
	Node* prev = nullptr;
	while(source_node != nullptr){
		Node* newNode = new Node {source_node->data.id,source_node->data.year,source_node->data.month,source_node->data.temperature};
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else{
			prev->next = newNode;
			tail = newNode;
		}
		prev = newNode;
		source_node = source_node->next;
	}
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// TODO: implement this function
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	// TODO: implement this function
	if (year > MAX_YEAR || year < MIN_YEAR){
		std::cout << "Incorrect" << std::endl;
	}
	if (temperature > 50.0 || temperature < -50.0){
		std::cout << "Incorrect" << std::endl;
	}
	if (month == 0){
		std::cout << "Incorrect" << std::endl;	
	}
	else {
		Node* newNode = new Node {location, year, month, temperature};
		//check to see if linked list is empty
		if (head == nullptr){
			head = newNode;
			tail = newNode;
		}
		//sort
		else {
			Node* currentNode = head;
			Node* prevNode;
			while (currentNode!=nullptr){
				if (*newNode < *currentNode){
					//insert to beginning of linked list
					if (currentNode == head){
						std::cout << "work1" << std::endl;
						if (currentNode == tail){
							tail = currentNode;
							currentNode->next = nullptr;
						}
						head = newNode;
						newNode->next = currentNode;
						std::cout << head->data.year << std::endl;
						std::cout << tail->data.year << std::endl;
						break;
					}
					//insert in between two nodes
					else{
						std::cout << "work2" << std::endl;
						prevNode->next = newNode;
						newNode->next = currentNode;
						break;
					}
				}
				//insert at end of linked list
				else if (currentNode == tail) {
					std::cout << "work3" << std::endl;
					tail = newNode;
					currentNode->next = newNode;
					newNode->next = nullptr;
					break;
				}
				prevNode = currentNode;
				currentNode = currentNode->next;
			}
		}
	}
}

void LinkedList::clear() {
	// TODO: implement this function
	Node* end = head;
    Node* tempEnd;
    while (end != nullptr){
        tempEnd = end->next;
        delete end;
        end = tempEnd;
    }
    head = nullptr;
}

Node* LinkedList::getHead() const {
	// TODO: implement this function, it will be used to help grade other functions
	return head;
}

string LinkedList::print() const {
	string outputString;
	std::stringstream ss;
	Node* end = head;
	while (end != nullptr){
		ss << end->data.id;
		ss << " ";
		ss << end->data.year;
		ss << " ";
		ss << end->data.month;
		ss << " ";
		ss << end->data.temperature;
		ss << "\n";
        end = end->next;
    }
	outputString = ss.str();
	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	os << ll.print();
	return os;
}
