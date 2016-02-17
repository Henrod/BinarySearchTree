#include "node.hpp"

class BST {
	public:
		BST();
		virtual ~BST						();
		void 		insert					(int data);
		bool		remove					(int data);
		void 		printLevelOrder	();
		int  		getHeight				();
		Node*   getMin					(Node* root);
		bool 		search					(int data);
	private:
		Node* mRoot;
		int 	mHeight;
		Node* insertNext			(Node* root, int data);
		int   getHeight				(Node* root, int level);
		void 	printGivenLevel	(Node* root, int level);
		Node* remove					(Node* root, int data, Node* parent);
};
