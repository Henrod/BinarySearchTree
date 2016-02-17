#include <iostream>
#include "bst.hpp"

using namespace std;

BST::BST() {
	mRoot = nullptr;
}

BST::~BST() {
	delete mRoot;
}
void BST::insert(int data) {
	mRoot = insertNext(mRoot, data);
}

Node* BST::insertNext(Node* root, int data) {
	if 			(root == nullptr)
		root = new Node(data);
	else if (data <= root->getData())
		root->setLeft(insertNext(root->getLeft(), data));
	else if (data >  root->getData())
		root->setRight(insertNext(root->getRight(), data));

	return root;
}

void BST::printLevelOrder() {
	mHeight = getHeight();

	for (int level = 0; level < mHeight; ++level) {
		printGivenLevel(mRoot, level);
		std::cout << std::endl;
	}
}
void BST::printGivenLevel(Node* root, int level){
	if (root == nullptr) {
		std::cout << "-- ";
	} else if (level == 0) {
		std::cout << root->getData() << " ";
	} else {
		printGivenLevel(root->getLeft(), level - 1);
		printGivenLevel(root->getRight(), level - 1);
	}
}

int BST::getHeight() {
	return getHeight(mRoot, 0);
}
int BST::getHeight(Node* root, int level) {
	if (root == nullptr) return level;

	int n1 = getHeight(root->getLeft() , level + 1);
	int n2 = getHeight(root->getRight(), level + 1);

	return n1 >= n2 ? n1 : n2;
}

bool BST::search(int data) {
	for (Node* curr = mRoot; curr != nullptr; ) {
	  if (data == curr->getData()) {
			return true;
		} else if (data > curr->getData()) {
			curr = curr->getRight();
		} else {
			curr = curr->getLeft();
		}
	}
	return false;
}

bool BST::remove(int data) {
	mRoot = remove(mRoot, data, mRoot);
	return mRoot != nullptr;
}

Node* BST::remove(Node* root, int data, Node* parent) {
	if (root == nullptr) return nullptr;
	else if (data > root->getData()) remove(root->getRight(), data, root);
	else if (data < root->getData()) remove(root->getLeft(), data, root);
	else {
		/* No child */
		if (root->getLeft() == nullptr && root->getRight() == nullptr) {
			if (parent->getRight() == root) {
				parent->setRight(nullptr);
			} else if (parent->getLeft() == root) {
				parent->setLeft(nullptr);
			}

			delete root;
			root = nullptr;
		}
		/* One child */
		else if (root->getLeft() == nullptr)
		{
			Node* tmp = root;

			if (parent->getRight() == root) {
				parent->setRight(root->getRight());
			} else if (parent->getLeft() == root) {
				parent->setLeft(root->getRight());
			}

			root = root->getRight();
			delete tmp;
			tmp = nullptr;
		}
		else if (root->getRight() == nullptr)
		{
			Node* tmp = root;

			if (parent->getRight() == root) {
				parent->setRight(root->getLeft());
			} else if (parent->getLeft() == root) {
				parent->setLeft(root->getLeft());
			}

			root = root->getLeft();
			delete tmp;
			tmp = nullptr;
		}
		/* Two childs */
		else
		{
			Node* tmp = getMin(root->getRight());

			root->setData(tmp->getData());
			root->setRight(remove(root->getRight(), tmp->getData(), root->getRight()));
			tmp = nullptr;
		}
	}
	return root;
}

Node* BST::getMin(Node* root) {
	Node* min;
	for (min = root; min->getLeft() != nullptr; min = min->getLeft());

	return min;
}
