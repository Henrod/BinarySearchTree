class Node {
  private:
		int mData;
		Node* mLeft;
		Node* mRight;

	public:
		Node(int data);
		virtual ~Node();
		int 		getData();
		void 		setData(int data);
		Node* 	getLeft();
		Node*		getRight();
		void 		setLeft(Node* node);
		void 		setRight(Node* node);
};
