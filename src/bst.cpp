#include <iostream>
#include "bst.hpp"

using namespace std;

BST::BST() {
	mRoot = unique_ptr<Node>(nullptr);
}

void BST::insert(int data) {
	mRoot = move(insertNext(mRoot, data));
}

unique_ptr<Node>& BST::insertNext(unique_ptr<Node>& root, int data) {
	if (root.get() == nullptr)
		root = unique_ptr<Node>(new Node(data));
	else if (data <= root->getData())
		root->setLeft(insertNext(root->getLeft(), data));
	else if (data >  root->getData())
		root->setRight(insertNext(root->getRight(), data));

	return root;
}

void BST::printLevelOrder() const {
	mHeight = getHeight();

	for (int level = 0; level < mHeight; ++level) {
		printGivenLevel(mRoot, level);
		cout << endl;
	}
}
void 	BST::printGivenLevel	(const unique_ptr<Node>& root, int level) const {
	if (root.get() == nullptr) {
		cout << "-- ";
	} else if (level == 0) {
		cout << root->getData() << " ";
	} else {
		printGivenLevel(root->getLeft(), level - 1);
		printGivenLevel(root->getRight(), level - 1);
	}
}

int BST::getHeight() const {
	return getHeight(mRoot, 0);
}
int BST::getHeight	(const unique_ptr<Node>& root, int level) const {
	if (root.get() == nullptr) return level;

	int n1 = getHeight(root->getLeft() , level + 1);
	int n2 = getHeight(root->getRight(), level + 1);

	return n1 >= n2 ? n1 : n2;
}

	bool BST::remove(int data) {
		mRoot = move(remove(mRoot, data, mRoot));
		return mRoot != nullptr;
	}

	unique_ptr<Node>& BST::remove(unique_ptr<Node>& root, int data, unique_ptr<Node>& parent) {
		if (root.get() == nullptr) return root;
		else if (data > root->getData()) remove(root->getRight(), data, root);
		else if (data < root->getData()) remove(root->getLeft(), data, root);
		else {
			/* No child */
			if (root->getLeft().get() == nullptr && root->getRight().get() == nullptr) {
				if (parent->getRight() == root) {
					unique_ptr<Node> right (nullptr);
					parent->setRight(right);
				} else if (parent->getLeft() == root) {
					unique_ptr<Node> left (nullptr);
					parent->setLeft(left);
				}

				root = unique_ptr<Node>(nullptr);
			}
				/* One child */
		else if (root->getLeft().get() == nullptr)
		{
			if (parent->getRight() == root) {
				parent->setRight(root->getRight());
			} else if (parent->getLeft() == root) {
				parent->setLeft(root->getRight());
			}
			root = move(root->getRight());
		}
		else if (root->getRight().get() == nullptr)
		{
			if (parent->getRight() == root) {
				parent->setRight(root->getLeft());
			} else if (parent->getLeft() == root) {
				parent->setLeft(root->getLeft());
			}
			root = move(root->getLeft());
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

Node* BST::getMin (const unique_ptr<Node>& root) const {
	Node* min;
	for (min = root.get(); min->getLeft() != nullptr; min = min->getLeft().get());

	return min;
}

void BST::printInorder() const {
	printInorder(mRoot);
}

void BST::printInorder(const unique_ptr<Node>& root) const {
	if (root.get() == nullptr) return;
	printInorder(root->getLeft());
	cout << root->getData() << " ";
	printInorder(root->getRight());
}

unique_ptr<Node>& BST::search(const int data) {
	return search(mRoot, data);
}

unique_ptr<Node>& BST::search(unique_ptr<Node>& root, const int data) {
	if (root.get() == nullptr) return root;

	if (root->getData() == data) return root;
	unique_ptr<Node>& node = search(root->getLeft(), data);

	return node.get() == nullptr ? search(root->getRight(), data) : node;
}

void BST::swap(const int data) {
	unique_ptr<Node>& node = search(data);
	swap(node);
}

void BST::swap(unique_ptr<Node>& root) {
	unique_ptr<Node> tmp = move(root->getRight());
	root->setRight(root->getLeft());
	root->setLeft(tmp);

}
