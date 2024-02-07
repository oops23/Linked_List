# include <string>
# include "Node.h"
# include <sstream>

using std::string;

//constructor
Node::Node() : data(),  next(nullptr){
	// TODO: implement this function
}

//call constructor for temperature data
Node::Node(string id, int year, int month, double temperature):data(id,year,month,temperature){
	// TODO: implement this functions
	//Node* newNode = new Node(data,next);
}

bool Node::operator<(const Node& b) {
	return this->data < b.data;
}
