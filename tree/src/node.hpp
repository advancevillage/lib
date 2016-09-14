#ifndef __NODE_H_
#define __NODE_H_
#include<typeinfo>
#include<cstring>
using namespace std;

namespace tools{
	template<typename T>
	class Node{
	public:
		typedef T   DataType;
		typedef Node<T>*  Pointer;
		typedef Node<T>&  Reference;

	public:
		int depth;
		T value;
		Pointer pleft;
		Pointer pright;

	public:
		Node();
		Node(DataType v);
		Node(Node<T>& node);
		~Node();
		Node<T> operator=(Node<T>& node);
		Node<T> operator=(Node<T>* pnode);
		Node<T> operator=(T v);

	};
	template<typename T>
	Node<T>::Node(){
		if (strcmp(typeid(T).name(), (char*)"int") == 0){
			this->value = 0;
		}
		if (strcmp(typeid(T).name(), (char*)"double") == 0){
			this->value = 0.0;
		}
		if (strcmp(typeid(T).name(), (char*)"char") == 0){
			this->value = '\0';
		}
		this->depth = 0;
		this->pleft = NULL;
		this->pright = NULL;
	}
	template<typename T>
	Node<T>::Node(T v){
		this->value = v;
		this->depth = 0;
		pleft = NULL;
		pright = NULL;
	}
	template<typename T>
	Node<T>::Node(Node<T>& node){
		this->value = node.value;
		this->pleft = node.pleft;
		this->pright = node.pright;
		this->depth = node.depth;
	}
	template<typename T>
	Node<T>::~Node(){
		this->pleft = NULL;
		this->pright = NULL;
	}
	template<typename T>
	Node<T> Node<T>::operator=(Node<T>& node){
		this->value = node.value;
		this->pleft = node.pleft;
		this->pright = node.pright;
		this->depth = node.depth;
		return (*this);
	}
	template<typename T>
	Node<T> Node<T>::operator=(Node<T>* pnode){
		this->value = pnode->value;
		this->pleft = pnode->pleft;
		this->pright = pnode->pright;
		this->depth = pnode->depth;
		return (*this);
	}
	template<typename T>
	Node<T> Node<T>::operator=(T v){
		this->value = v;
		return (*this);
	}

	template<typename T>
	class AVLNode{
	public:
		typedef T	DataType;
		typedef AVLNode<T>* Pointer;
		typedef AVLNode<T>& Reference;
	public:
		T	value;
		int depth;
		int leftTreeMaxDepth;
		int rightTreeMaxDepth;
		int leftTreeHeight;
		int rightTreeHeight;
		int alpha;
		Pointer pleft;
		Pointer	pright;
	public:
		AVLNode();
		AVLNode(T v);
		AVLNode(AVLNode<T>& avlnode);
		AVLNode(AVLNode<T>* pavlnode);
		~AVLNode();
		AVLNode<T> operator=(AVLNode<T>& avlnode);
		AVLNode<T> operator=(AVLNode<T>* pavlnode);
		AVLNode<T> operator=(T v);
	public:
		int ComputeLeftTreeHeight();
		int ComputeRightTreeHeight();
		int ComputeAlpha();

	};
	template<typename T>
	AVLNode<T>::AVLNode() :depth(0), leftTreeMaxDepth(depth), rightTreeMaxDepth(depth){
		if (strcmp(typeid(T).name(), (char*)"int") == 0){
			this->value = 0;
		}
		if (strcmp(typeid(T).name(), (char*)"double") == 0){
			this->value = 0.0;
		}
		if (strcmp(typeid(T).name(), (char*)"char") == 0){
			this->value = '\0';
		}
		leftTreeHeight = leftTreeMaxDepth - depth;
		rightTreeHeight = rightTreeMaxDepth - depth;
		alpha = -leftTreeHeight + rightTreeHeight;
		pleft = NULL;
		pright = NULL;
	}
	template<typename T>
	AVLNode<T>::AVLNode(AVLNode<T>& avlnode){
		value = avlnode.value;
		depth = avlnode.depth;
		leftTreeMaxDepth = avlnode.leftTreeMaxDepth;
		rightTreeMaxDepth = avlnode.rightTreeMaxDepth;
		leftTreeHeight = leftTreeMaxDepth - depth;
		rightTreeHeight = rightTreeMaxDepth - depth;
		alpha = -leftTreeHeight + rightTreeHeight;
		pleft = avlnode.pleft;
		pright = avlnode.pright;
	}
	template<typename T>
	AVLNode<T>::AVLNode(AVLNode<T>* pavlnode){
		value = pavlnode->value;
		depth = pavlnode->depth;
		leftTreeMaxDepth = pavlnode->leftTreeMaxDepth;
		rightTreeMaxDepth = pavlnode->rightTreeMaxDepth;
		leftTreeHeight = leftTreeMaxDepth - depth;
		rightTreeHeight = rightTreeMaxDepth - depth;
		alpha = -leftTreeHeight + rightTreeHeight;
		pleft = pavlnode->pleft;
		pright = pavlnode->pright;
	}
	template<typename T>
	AVLNode<T>::AVLNode(T v){
		value = v;
		depth = 0;
		leftTreeMaxDepth = depth;
		rightTreeMaxDepth = depth;
		leftTreeHeight = leftTreeMaxDepth - depth;
		rightTreeHeight = rightTreeMaxDepth - depth;
		alpha = -leftTreeHeight + rightTreeHeight;
		pleft = NULL;
		pright = NULL;
	}
	template<typename T>
	AVLNode<T>::~AVLNode(){
		this->pleft = NULL;
		this->pright = NULL;
	}
	template<typename T>
	AVLNode<T> AVLNode<T>::operator=(AVLNode<T>& avlnode){
		value = avlnode.value;
		depth = avlnode.depth;
		leftTreeMaxDepth = avlnode.leftTreeMaxDepth;
		rightTreeMaxDepth = avlnode.rightTreeMaxDepth;
		leftTreeHeight = leftTreeMaxDepth - depth;
		rightTreeHeight = rightTreeMaxDepth - depth;
		alpha = -leftTreeHeight + rightTreeHeight;
		pleft = avlnode.pleft;
		pright = avlnode.pright;
		return (*this);
	}
	template<typename T>
	AVLNode<T> AVLNode<T>::operator=(AVLNode<T>* pavlnode){
		value = pavlnode->value;
		depth = pavlnode->depth;
		leftTreeMaxDepth = pavlnode->leftTreeMaxDepth;
		rightTreeMaxDepth = pavlnode->rightTreeMaxDepth;
		leftTreeHeight = leftTreeMaxDepth - depth;
		rightTreeHeight = rightTreeMaxDepth - depth;
		alpha = -leftTreeHeight + rightTreeHeight;
		pleft = pavlnode->pleft;
		pright = pavlnode->pright;
		return (*this);
	}
	template<typename T>
	AVLNode<T> AVLNode<T>::operator=(T v){
		value = v;
		depth = 0;
		leftTreeMaxDepth = depth;
		rightTreeMaxDepth = depth;
		leftTreeHeight = leftTreeMaxDepth - depth;
		rightTreeHeight = rightTreeMaxDepth - depth;
		alpha = -leftTreeHeight + rightTreeHeight;
		pleft = NULL;
		pright = NULL;
		return (*this);
	}
	template<typename T>
	int AVLNode<T>::ComputeLeftTreeHeight(){
		this->leftTreeHeight = this->leftTreeMaxDepth - this->depth;
		return this->leftTreeHeight;
	}
	template<typename T>
	int AVLNode<T>::ComputeRightTreeHeight(){
		this->rightTreeHeight = this->rightTreeMaxDepth - this->depth;
		return this->rightTreeHeight;
	}
	template<typename T>
	int AVLNode<T>::ComputeAlpha(){
		this->alpha = -this->leftTreeHeight + this->rightTreeHeight;
		return this->alpha;
	}
}

#endif
