#include <iostream> 
#include <algorithm>
#include "Tree.h"
using namespace std;

int main() {
	Tree<int> intTree;
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	random_shuffle(a, a + 10);

	for (int i = 0; i < 10; ++i) {
		intTree.insertNode(a[i]);
	}
	intTree.preOrder();
	cout << endl;
	intTree.inOrder();
	cout << endl;
	intTree.postOrder();

	return 0;
}
