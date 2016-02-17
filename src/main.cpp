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
		if (!bst.search(x)) {
			cout << "Number i: " << x << endl;
			bst.insert(x);
		} else {
			--i;
		}
	}

	cout << endl;
	bst.printLevelOrder();

	while (true) {
		cout << "Remove > "; cin >> x; cout << endl;
		bst.remove(x);
		bst.printLevelOrder();
	}

	return 0;
}
