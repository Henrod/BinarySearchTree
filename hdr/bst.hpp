#include "node.hpp"

enum ORDER {
	PRE_ORDER,
	IN_ORDER,
	POS_ORDER
};

class BST {
	public:
		BST();
		void insert (int data);
		bool remove (int data);
		void printLevelOrder () const;
		void printInorder () const;
		void print(ORDER order) const;
		int getHeight () const;
		Node* getMin (const std::unique_ptr<Node>& root) const;
		void swap (const int data);
	private:
		std::unique_ptr<Node> mRoot;
		int mutable mHeight;
		std::unique_ptr<Node>& insertNext (std::unique_ptr<Node>& root, int data);
		int getHeight (const std::unique_ptr<Node>& root, int level) const;
		void printGivenLevel (const std::unique_ptr<Node>& root, int level) const;
		void printInorder (const std::unique_ptr<Node>& root) const;
		void printPreorder (const std::unique_ptr<Node>& root) const;
		void printPosorder (const std::unique_ptr<Node>& root) const;
		std::unique_ptr<Node>& remove (std::unique_ptr<Node>& root, int data, std::unique_ptr<Node>& parent);
		void swap(std::unique_ptr<Node>& root);
		std::unique_ptr<Node>& search(const int data);
		std::unique_ptr<Node>& search(std::unique_ptr<Node>& root, const int data);
};
