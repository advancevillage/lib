#ifndef __SORT_H_
#define __SORT_H_
#include "sortdef.h"
#include <cstddef>
#include <vector>
using namespace std;
namespace tools{
    template<typename T, typename Container = std::vector<T> >
    class Sort{
        public:
            static void Swap(T& fir, T& sec);
        public:
            static int BubbleSort(Container& con, SortRule sr = ASCEND);
            static int BubbleSort(Container& con, unsigned int begin,unsigned int end, SortRule sr = ASCEND);
    };
    //Swap
    template<typename T, typename Container >
        void Sort<T, Container>::Swap(T& fir, T& sec){
            T temp = fir;
            fir = sec;
            sec = temp;
        }

    //BubbleSort
    template<typename T, typename Container >
    int Sort<T, Container>::BubbleSort(Container& con, SortRule sr){
        bool  isEmpty = con.empty();
        if(isEmpty){
            return -1;
        }
        else{
           size_t len = con.size(); 
           bool isSwap = true; 
           for(size_t i = 0; isSwap && i < len-1; ++i){
               isSwap = false;
               for(size_t j = 0; j < len-1-i; ++j){
                   switch(sr){
                       case ASCEND:
                           if(con[j] > con[j+1]){
                                Sort<T,Container>::Swap(con[j], con[j+1]);
                                isSwap = true;
                            }
                            break;
                       case DESCEND:
                           if(con[j] < con[j+1]){
                                Sort<T,Container>::Swap(con[j], con[j+1]);
                                isSwap = true;
                            }
                            break;
                       default: 
                            break;
                    }
                }
            }
            return 0;
        }
    }
   //BubbleSort [begin, end) 
    template<typename T, typename Container >
        int Sort<T, Container>::BubbleSort(Container& con, unsigned int begin, unsigned int end, SortRule sr){
            size_t maxlen = con.size();
            begin = begin <= maxlen?  begin:maxlen;
            end = end <= maxlen? end:maxlen;
            size_t len = end -begin;
            bool isEmpty = con.empty();
            if(len <= 0 || isEmpty){
                return -1;
            }
            else{
                bool isSwap = true;
                for(unsigned int i = 0; isSwap && i < len-1; ++i){
                   isSwap = false;
                   for(unsigned int j = begin; j < end-1-i; ++j){
                       switch(sr){
                           case ASCEND:
                               if(con[j] > con[j+1]){
                                   Sort<T,Container>::Swap(con[j], con[j+1]);
                                   isSwap = true;
                               } 
                               break;
                           case DESCEND:
                               if(con[j] < con[j+1]){
                                   Sort<T,Container>::Swap(con[j], con[j+1]);
                                   isSwap = true;
                               }
                               break;
                            default:
                               break;
                       }
                   }
                }
                
            }
            return 0;
        }
}





#endif


































