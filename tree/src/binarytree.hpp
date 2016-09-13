#ifndef __BINARYTREE_H_
#define __BINARYTREE_H_
#include<vector>
#include "node.hpp"

namespace tools{
	template<typename T>
	class BinaryTree{
	public:
		int size;
		tools::Node<T>* root;
	public:
		BinaryTree();
		BinaryTree(T v);
		BinaryTree(Node<T> node);
		~BinaryTree();

	public:
		bool isEmptyTree();
		//insert
		int Insert(Node<T>& node);
		int Insert(Node<T>* pnode);
		int Insert(T& value);
		int Insert(std::vector<T>& con);
		//search
		Node<T>* BinaryTreeSearch(const T& value);
		//MaintainDepth
		void MaintainDepth(Node<T>* refer_node, Node<T>* change_node);
		//Delete
		int Delete(const T& value);
	};
	template<typename T>
	BinaryTree<T>::BinaryTree() :root(NULL), size(0){
	}
	template<typename T>
	BinaryTree<T>::BinaryTree(T v) : size(1){
		root = new Node<T>();
		root = v;
		root->depth = 0;
	}
	template<typename T>
	BinaryTree<T>::BinaryTree(Node<T> node) :size(1){
		root = new Node<T>();
		root = node;
		root->depth = 0;
	}
	template<typename T>
	BinaryTree<T>::~BinaryTree(){
		if (root != NULL) delete root;
	}
	template<typename T>
	bool BinaryTree<T>::isEmptyTree(){
		return size <= 0 ? true : false;
	}
	//insert
	//-1  The value has existed
	template<typename T>
	int BinaryTree<T>::Insert(Node<T>& node){
		if (this->size == 0){
			root = new Node<T>();
			(*root) = node;
			root->depth = 0;
			++this->size;
			return 0;
		}
		Node<T>* dad = NULL;
		Node<T>* son = root;
		while (son != NULL){
			if (son->value == node.value){
				return -1;
			}else if (node.value < son->value){
				dad = son;
				son = son->pleft;
			}else{
				dad = son;
				son = son->pright;
			}
		}
		Node<T>* pn = new Node<T>(node.value);
		if (dad != NULL && pn->value < dad->value){
			dad->pleft = pn;
			pn->depth = dad->depth + 1;
			++this->size;
		}
		if (dad != NULL && pn->value > dad->value){
			dad->pright = pn;
			pn->depth = dad->depth + 1;
			++this->size;
		}
		return 0;
	}
	template<typename T>
	int BinaryTree<T>::Insert(Node<T>* pnode){
		if (this->size == 0){
			root = new Node<T>();
			(*root) = pnode;
			root->depth = 0;
			++this->size;
			return 0;
		}
		Node<T>* dad = NULL;
		Node<T>* son = root;
		while (son != NULL){
			if (pnode->value == son->value){
				return -1;
			}else if (pnode->value < son->value){
				dad = son;
				son = son->pleft;
			}else{
				dad = son;
				son = son->pright;
			}
		}
		Node<T>* pn = new Node<T>(pnode->value);
		if (dad != NULL && pn->value < dad->value){
			dad->pleft = pn;
			pn->depth = dad->depth + 1;
			++this->size;
		}
		if (dad != NULL && pn->value > dad->value){
			dad->pright = pn;
			pn->depth = dad->depth + 1;
			++this->size;
		}
		return 0;
	}
	template<typename T>
	int BinaryTree<T>::Insert(T& value){
		if (this->size == 0){
			root = new Node<T>();
			(*root) = value;
			root->depth = 0;
			++this->size;
			return 0;
		}
		Node<T>* dad = NULL;
		Node<T>* son = root;
		while (son != NULL){
			if (value == son->value){
				return -1;
			}else if (value < son->value){
				dad = son;
				son = son->pleft;
			}else{
				dad = son;
				son = son->pright;
			}
		}
		Node<T>* pn = new Node<T>(value);
		if (dad != NULL && pn->value < dad->value){
			dad->pleft = pn;
			pn->depth = dad->depth + 1;
			++this->size;
		}
		if (dad != NULL && pn->value > dad->value){
			dad->pright = pn;
			pn->depth = dad->depth + 1;
			++this->size;
		}
		return 0;
	}
	template<typename T>
	int BinaryTree<T>::Insert(std::vector<T>& con){
		bool isEmpty = con.empty();
		if (isEmpty){
			return -1;
		}
		int len = (int)con.size();
		for (int i = 0; i < len; ++i){
			T value = con[i];
			BinaryTree<T>::Insert(value);
		}
		return 0;
	}
	template<typename T>
	Node<T>* BinaryTree<T>::BinaryTreeSearch(const T& value){
		if (this->size == 0){
			return NULL;
		}
		Node<T>* node = this->root;
		while (node != NULL){
			if (value == node->value){
				break;
			}
			else if (value < node->value){
				node = node->pleft;
			}
			else{
				node = node->pright;
			}
		}
		return node;
	}
	//MaintainDepth
	template<typename T>
	void BinaryTree<T>::MaintainDepth(Node<T>* refer_node, Node<T>* change_node){
		if (refer_node == NULL || change_node == NULL){
			return;
		}
		change_node->depth = refer_node->depth + 1;
		BinaryTree<T>::MaintainDepth(change_node, change_node->pleft);
		BinaryTree<T>::MaintainDepth(change_node, change_node->pright);
	}
	//Delete
	template<typename T>
	int BinaryTree<T>::Delete(const T& value){
		if (this->size == 0){
			return -1;
		}
		Node<T>* dad = NULL;
		Node<T>* son = this->root;
		while (son != NULL){
			if (value == son->value){
				break;
			}
			else if (value < son->value){
				dad = son;
				son = son->pleft;
			}
			else{
				dad = son;
				son = son->pright;
			}
		}
		if (son == NULL){
			return -1;
		}
		if (dad == NULL){
			if (root->pleft == NULL && root->pright == NULL){
				delete root;
				root = NULL;
			}else if (root->pleft != NULL && root->pright == NULL){
				Node<T>* temp = root;
				root = root->pleft;
				delete temp;
				root->depth = 0;
				MaintainDepth(root, root->pleft);
				MaintainDepth(root, root->pright);
			}else if (root->pleft == NULL && root->pright != NULL){
				Node<T>* temp = root;
				root = root->pright;
				delete temp;
				root->depth = 0;
				MaintainDepth(root, root->pleft);
				MaintainDepth(root, root->pright);
			}
			else{
				Node<T>* p = root->pleft;
				if (p->pright == NULL){
					root->value = p->value;
					root->pleft = p->pleft;
					delete p;
					MaintainDepth(root, root->pleft);
				}
				else{
					Node<T>* s = p->pright;
					while (s->pright != NULL){
						p = s;
						s = s->pright;
					}
					root->value = s->value;
					p->pright = s->pleft;
					delete s;
					MaintainDepth(p, p->pright);
				}
			}
		}
		else{
			if (son->pleft == NULL && son->pright == NULL){
				if (dad->pleft == son) dad->pleft = NULL;
				if (dad->pright == son) dad->pright = NULL;
				delete son;
			}
			else if (son->pleft != NULL && son->pright == NULL){
				if (dad->pleft == son){
					dad->pleft = son->pleft;
					MaintainDepth(dad, dad->pleft);
				}
				if (dad->pright == son){
					dad->pright = son->pleft;
					MaintainDepth(dad, dad->pright);
				}
				delete son;
			}
			else if (son->pleft == NULL && son->pright != NULL){
				if (dad->pleft == son){
					dad->pleft = son->pright;
					MaintainDepth(dad, dad->pleft);
				}
				if (dad->pright == son){
					dad->pright = son->pright;
					MaintainDepth(dad, dad->pright);
				}
				delete son;
			}
			else{
				Node<T>* p = son->pleft;
				if (p->pright == NULL){
					son->value = p->value;
					son->pleft = p->pleft;
					MaintainDepth(son, son->pleft);
					delete p;
				}
				else{
					Node<T>* s = p->pright;
					while (s->pright != NULL){
						p = s;
						s = s->pright;
					}
					son->value = s->value;
					p->pright = s->pleft;
					delete s;
					MaintainDepth(p, p->pright);
				}
			}
		}
		--this->size;
		return 0;
	}
}
#endif




