#include "node.hpp"

class BST {
	public:
		BST();
		void 		insert					(int data);
		bool		remove					(int data);
		void 		printLevelOrder	();
		int  		getHeight				();
		Node*   getMin (const std::unique_ptr<Node>& root) const;
	private:
		std::unique_ptr<Node> mRoot;
		int 	mHeight;
		std::unique_ptr<Node>& insertNext (std::unique_ptr<Node>& root, int data);
		int   getHeight				(const std::unique_ptr<Node>& root, int level) const;
		void 	printGivenLevel	(const std::unique_ptr<Node>& root, int level) const;
		std::unique_ptr<Node>& remove (std::unique_ptr<Node>& root, int data, std::unique_ptr<Node>& parent);
};
