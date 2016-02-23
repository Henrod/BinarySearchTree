#include <utility>
#include "node.hpp"

Node::Node(int data) {
	mRight = std::unique_ptr<Node>(nullptr);
	mLeft  = std::unique_ptr<Node>(nullptr);
	mData  = data;
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

std::unique_ptr<Node>& Node::getLeft(){
	return mLeft;
}
void 	Node::setLeft(std::unique_ptr<Node>& node){
	mLeft = std::move(node);
}

std::unique_ptr<Node>& Node::getRight(){
	return mRight;
}
void Node::setRight(std::unique_ptr<Node>& node){
	mRight = std::move(node);
}
