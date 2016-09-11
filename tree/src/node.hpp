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
                typedef T*  Pointer;
                typedef T&  Reference;

            public:
                int depth;
                DataType value;
                Pointer pleft;
                Pointer pright;

            public:
                Node();
                Node(DataType v);
                Node(Node<T>& node);
                ~Node();
                void operator=(Node<T>& node);
                void operator=(Node<T>* pnode);
                void operator=(Node<T>::DataType v);
        
        };
    template<typename T>
        Node<T>::Node(){
            if(strcmp(typeid(Node<T>::DataType).name(), (char*)"int")){
                this->value = 0;
            }
            if(strcmp(typeid(Node<T>::DataType).name(), (char*)"double")){
                this->value = 0.0;
            }
            if(strcmp(typeid(Node<T>::DataType).name(), (char*)"char")){
                this->value = '\0';
            }
            this->depth = 0;
            this->pleft = NULL;
            this->pright = NULL;
        }
    template<typename T>
        Node<T>::Node(Node<T>::DataType v){
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
            if(this->pright != NULL){
                delete this->pright;
            }
            if(this->pleft != NULL){
                delete this->pleft;
            }
        }
    template<typename T>
        void Node<T>::operator=(Node<T>& node){
            this->value = node.value;
            this->pleft = node.pleft;
            this->pright = node.pright;
            this->depth = node.depth;
        }
    template<typename T>
        void Node<T>::operator=(Node<T>* pnode){
            this->value = pnode->value;
            this->pleft = pnode->pleft;
            this->pright = pnode->pright;
            this->depth = pnode->depth;
        }
    template<typename T>
        void Node<T>::operator=(Node<T>::DataType v){
            this->value = v;
        }

}

#endif