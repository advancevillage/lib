#ifndef __BINARYTREE_H_
#define __BINARYTREE_H_
#include "node.hpp"

namespace tools{
    template<typename T>
        class BinaryTree{
            public:
                int size;
                tools::Node<T> root;
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
                //search
                Node<T>* BinaryTreeSearch(const T& value);
        };
    template<typename T>
        BinaryTree<T>::BinaryTree():root(), size(0){

        }
    template<typename T>
        BinaryTree<T>::BinaryTree(T v):root(v),size(1){

        }
    template<typename T>
        BinaryTree<T>::BinaryTree(Node<T> node):root(node),size(1){

        }
    template<typename T>
        bool BinaryTree<T>::isEmptyTree(){
            return size <= 0? true:false;
        }
    //insert
    //-1  The value has existed
    template<typename T>
        int BinaryTree<T>::Insert(Node<T>& node){
            if(this->size == 0){
                this->root = node;
                this->root.depth = 0;
                ++this->size;
                return 0;
            }
            Node<T>* dad = NULL;
            Node<T>* son = &root;
            while(son != NULL){
                if(son->value ==  node.value){
                     return -1;
                }else if(node.value < son->value){
                    dad = son;
                    son = son->pleft;
                }else{
                    dad = son;
                    son = son->pright;
                }
            }
            Node<T>* pn = new Node<T>(node->value);
            if(dad != NULL && pn->value < dad->value){
                dad->pleft = pn;
                pn->depth = dad->depth+1;
                ++this->size;
            }
            if(dad != NULL && pn->value > dad->value){
                dad->pright = pn;
                pn->depth = dad->depth+1;
                ++this->size;
            } 
            return 0;
        }
    template<typename T>
        int BinaryTree<T>::Insert(Node<T>* pnode){
            if(this->size == 0){
                root = pnode;
                root.depth = 0;
                ++this->size;
                return 0;
            }
            Node<T>* dad = NULL;
            Node<T>* son = pnode;
            while(son != NULL){
                if(pnode->value == son->value){
                    return -1;
                }else if(pnode->value < son->value){
                    dad = son;
                    son = son->pleft;
                }else{
                    dad = son;
                    son = son->pright;
                }
            }
            Node<T>* pn = new Node<T>(pnode->value);
            if(dad != NULL && pn->value < dad->value){
                dad->pleft = pn;
                pn->depth = dad->depth+1;
                ++this->size;
            }
            if(dad != NULL && pn->value > dad->value){
                dad->pright = pn;
                pn->depth = dad->depth+1;
                ++this->size;
            }
            return 0;
        }
    template<typename T>
        int BinaryTree<T>::Insert(T& value){
            if(this->size == 0){
                root = value;
                root.depth = 0;
                ++this->size;
                return 0;
            }
            Node<T>* dad = NULL;
            Node<T>* son = &root;
            while(son != NULL){
                if(value == son->value){
                    return -1;
                }
                if(value < son->value){
                    dad = son;
                    son = son->pleft;
                }
                if(value > son->value){
                    dad = son;
                    son = son->pright;
                }
            }
            Node<T>* pn = new Node<T>(value);
            if(dad != NULL && pn->value < dad->value){
                dad->pleft = pn;
                pn->depth = dad->depth+1;
                ++this->size;
            }
            if(dad != NULL && pn->value > dad->value){
                dad->pright = pn;
                pn->depth = dad->depth+1;
                ++this->size;
            }
            return 0;
        }

                
       

}
#endif
