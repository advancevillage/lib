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

}

#endif
