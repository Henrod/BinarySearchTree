#include <iostream>
#include <cstdlib>
#include "bst.hpp"

using namespace std;

int main() {
	BST bst;
	int n, x;

	cout << "Number of nodes: ";
	cin >> n; cout << endl;

	for (int i = 0; i < n; i++) {
		x = rand() % 100;
		cout << "Number i: " << x << endl;
		bst.insert(x);
	}

	cout << endl;
	bst.printLevelOrder();

	while (true) {
		cout << "Remove > "; cin >> x; cout << endl;
		bst.remove(x);
		bst.printLevelOrder();
		cout << endl;
		bst.printInorder();
	}

	return 0;
}
