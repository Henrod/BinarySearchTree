#include <iostream>
#include "bst.hpp"

using namespace std;

BST::BST() {
	mRoot = std::unique_ptr<Node>(nullptr);
}

void BST::insert(int data) {
	mRoot = std::move(insertNext(mRoot, data));
}

std::unique_ptr<Node>& BST::insertNext(std::unique_ptr<Node>& root, int data) {
	if (root.get() == nullptr)
		root = std::unique_ptr<Node>(new Node(data));
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
void 	BST::printGivenLevel	(const std::unique_ptr<Node>& root, int level) const {
	if (root.get() == nullptr) {
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
int BST::getHeight	(const std::unique_ptr<Node>& root, int level) const {
	if (root.get() == nullptr) return level;

	int n1 = getHeight(root->getLeft() , level + 1);
	int n2 = getHeight(root->getRight(), level + 1);

	return n1 >= n2 ? n1 : n2;
}

	bool BST::remove(int data) {
		mRoot = std::move(remove(mRoot, data, mRoot));
		return mRoot != nullptr;
	}

	std::unique_ptr<Node>& BST::remove(std::unique_ptr<Node>& root, int data, std::unique_ptr<Node>& parent) {
		if (root.get() == nullptr) return root;
		else if (data > root->getData()) remove(root->getRight(), data, root);
		else if (data < root->getData()) remove(root->getLeft(), data, root);
		else {
			/* No child */
			if (root->getLeft().get() == nullptr && root->getRight().get() == nullptr) {
				if (parent->getRight() == root) {
					std::unique_ptr<Node> right (nullptr);
					parent->setRight(right);
				} else if (parent->getLeft() == root) {
					std::unique_ptr<Node> left (nullptr);
					parent->setLeft(left);
				}

				root = std::unique_ptr<Node>(nullptr);
			}
				/* One child */
		else if (root->getLeft().get() == nullptr)
		{
			std::unique_ptr<Node> tmp = std::move(root);

			if (parent->getRight() == tmp) {
				parent->setRight(tmp->getRight());
			} else if (parent->getLeft() == tmp) {
				parent->setLeft(tmp->getRight());
			}

			root = std::move(tmp->getRight());
		}
		else if (root->getRight().get() == nullptr)
		{
			std::unique_ptr<Node> tmp = std::move(root);

			if (parent->getRight() == tmp) {
				parent->setRight(tmp->getLeft());
			} else if (parent->getLeft() == tmp) {
				parent->setLeft(tmp->getLeft());
			}

			root = std::move(tmp->getLeft());
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

Node* BST::getMin (const std::unique_ptr<Node>& root) const {
	Node* min;
	for (min = root.get(); min->getLeft() != nullptr; min = min->getLeft().get());

	return min;
}
