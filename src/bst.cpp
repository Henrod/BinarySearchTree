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
	if (root == nullptr)
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

Node* BST::search(int data) const {
	for (Node* curr = mRoot; curr != nullptr; ) {
	  if (data == curr->getData()) {
			return curr;
		} else if (data > curr->getData()) {
			curr = curr->getRight();
		} else {
			curr = curr->getLeft();
		}
	}
	return nullptr;
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
			Node* tmp = min(root->getRight());

			root->setData(tmp->getData());
			root->setRight(remove(root->getRight(), tmp->getData(), root->getRight()));
			tmp = nullptr;
		}
	}
	return root;
}

Node* BST::min() const {
	return min(mRoot);
}

Node* BST::min(Node* root) const {
	if (!root) return nullptr;
	Node* min;
	for (min = root; min->getLeft() != nullptr; min = min->getLeft());

	return min;
}

Node* BST::max() const {
	return max(mRoot);
}

Node* BST::max(Node* root) const {
	if (!root) return nullptr;

	Node* max;
	for (max = root; max->getRight() != nullptr; max = max->getRight());

	return max;
}

Node* BST::successor(int x) const {
	Node* root = search(x);
	if (!root) return nullptr;

	if (root->getRight() != nullptr) {
		return min(root->getRight());
	}

	Node* node = mRoot;
	Node* succ = nullptr;
	while (node != nullptr) {
		if (node->getData() == root->getData()) {
			break;
		} else if (node->getData() < root->getData()) {
			node = node->getRight();
		} else if (node->getData() > root->getData()) {
			succ = node;
			node = node->getLeft();
		}
	}

	return succ;
}

Node* BST::predecessor(int x) const {
	Node* root = search(x);
	if (!root) return nullptr;

	if (root->getLeft() != nullptr) {
		return max(root->getLeft());
	}

	Node* node = mRoot;
	Node* pred = nullptr;
	while (node != nullptr) {
		if (node->getData() == root->getData()) {
			break;
		} else if (node->getData() > root->getData()) {
			node = node->getLeft();
		} else if (node->getData() < root->getData()) {
			pred = node;
			node = node->getRight();
		}
	}

	return pred;
}
