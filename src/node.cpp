#include "node.hpp"

Node::Node(int data) {
	mData 	= data;
	mRight 	= nullptr;
	mLeft 	= nullptr;
}
Node::~Node() {
	mData = -1;
}

int Node::getData(){
	return mData;
}
void Node::setData(int data){
	mData = data;
}

Node* Node::getLeft(){
	return mLeft;
}
void 	Node::setLeft(Node* node){
	mLeft = node;
}

Node* Node::getRight(){
	return mRight;
}
void Node::setRight(Node* node){
	mRight = node;
}
