#include "node.hpp"

class BST {
	public:
		BST();
		virtual ~BST();
		void insert	(int data);
		bool remove	(int data);
		void printLevelOrder ();
		int getHeight ();
		Node* min () const;
		Node* max() const;
		Node* search (int data) const;
		Node* successor (int x) const;
		Node* predecessor (int x) const;
	private:
		Node* mRoot;
		int mHeight;
		Node* insertNext (Node* root, int data);
		int getHeight (Node* root, int level);
		void printGivenLevel (Node* root, int level);
		Node* remove (Node* root, int data, Node* parent);
		Node* min (Node* root) const;
		Node* max(Node* root) const;
};
