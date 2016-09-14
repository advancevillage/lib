#include<iostream>
#include<vector>
#include"binarytree.hpp"
#include<algorithm>
#include<typeinfo>
using namespace std;
using namespace tools;
template<typename T>
void display(T& value){
	cout << value << " ";
}

int main(){
	const int size = 20;
	int arr[size] = {
		4, 5, 343, 44, 980, 98, 23, 55, 99, 45,
		8, 9, 11, 234, 452, 231, 12334, 232, 89, 787
	};
	int arrtwo[5] = { 50, 30, 60, 40, 35 };
	vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
	vector<int> vectwo(arrtwo, arrtwo + sizeof(arrtwo) / sizeof(int));
	cout << "Vector " << endl;
	for_each(vec.begin(), vec.end(), display<int>);
	cout << endl;
	cout << "typeinfo(int) = " << typeid(int).name() << endl;
	tools::BinaryTree<int> bt;
	bt.Insert(vec);
	Node<int> node(555);
	Node<int>* pnode = new Node<int>(666);
	//bt.Insert(node);
	//bt.Insert(pnode);
	bt.Mirror(bt.GetRoot());
	int max_depth = 0;
	max_depth = bt.GetMaxDepth(bt.GetRoot(), max_depth);
	cout << "max_depth = " << max_depth << endl;
	int i = 0;

	AVLTree<int> avltree;
	avltree.Insert(vectwo);
	return 0;
}
