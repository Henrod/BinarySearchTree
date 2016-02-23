#include <memory>

class Node {
  private:
		int mData;
		std::unique_ptr<Node> mLeft;
		std::unique_ptr<Node> mRight;

	public:
		Node(int data);
		virtual ~Node();
		int 		getData();
		void 		setData(int data);
		std::unique_ptr<Node>& 	getLeft();
		std::unique_ptr<Node>&	getRight();
		void 		setLeft(std::unique_ptr<Node>& node);
		void 		setRight(std::unique_ptr<Node>& node);
};
