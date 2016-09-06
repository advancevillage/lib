#ifndef __SORT_H_
#define __SORT_H_
#include "sortdef.h"
#include <cstddef>
#include <vector>
#include <stack>
using namespace std;
namespace tools{
    template<typename T, typename Container = std::vector<T> >
    class Sort{
        public:
            static void Swap(T& fir, T& sec);
        public:
            //BubbleSort
            static int BubbleSort(Container& con, SortRule sr = ASCEND);
            static int BubbleSort(Container& con, unsigned int begin,unsigned int end, SortRule sr = ASCEND);
            //InsertSort
            static int InsertSort(Container& con, SortRule sr = ASCEND);
            static int InsertSort(Container& con, unsigned int begin, unsigned int end, SortRule sr = ASCEND);
            //QuickSort
            static int QuickSort(Container& con, SortRule sr = ASCEND);
            static int QuickSort(Container& con, unsigned int begin, unsigned int end, SortRule sr = ASCEND);
            //MergeSort
            static int MergeSort(Container& con, SortRule sr = ASCEND);
            static int MergeSort(Container& con, unsigned int begin, unsigned int end, SortRule sr = ASCEND);

        private: 
            static size_t Partition(Container& con, unsigned int begin, unsigned int end, unsigned int index, SortRule sr = ASCEND);
            static int  Merge(Container& con, Container& left, const size_t leftSize, Container& right, const size_t rightSize, SortRule sr = ASCEND);
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
    //InsertSort
    template<typename T, typename Container>
        int Sort<T, Container>::InsertSort(Container& con, SortRule sr){
            size_t len = con.size();
            bool isEmpty = con.empty();
            if(isEmpty){
                return -1;
            }
            for(size_t i = 1; i < len; ++i){
                T temp = con[i];
                size_t j = i;
                while(j > 0){
                    switch(sr){
                        case ASCEND:
                            if(con[j] < con[j-1]){
                                Sort<T,Container>::Swap(con[j], con[j-1]);
                            }
                            break;
                        case DESCEND:
                            if(con[j] > con[j-1]){
                                Sort<T,Container>::Swap(con[j], con[j-1]);
                            }
                            break;
                        default:
                            break;
                    }
                    --j;
                }
            }
            return 0;
        }
    //InsertSort [begin, end)
    template<typename T, typename Container >
        int Sort<T,Container>::InsertSort(Container& con, unsigned int begin, unsigned int end, SortRule sr){
            size_t maxsize = con.size();
            begin = begin <= maxsize? begin:maxsize;
            end = end <= maxsize? end:maxsize;
            bool isEmpty = con.empty();
            if(isEmpty){
                return -1;
            }
            for(size_t i = begin+1; i < end; ++i){
                T temp = con[i];
                size_t j = i;
                while(j > begin){
                    switch(sr){
                        case ASCEND:
                            if(con[j] < con[j-1]){
                                Sort<T,Container>::Swap(con[j], con[j-1]);
                            }
                            break;
                        case DESCEND:
                            if(con[j] > con[j-1]){
                                Sort<T,Container>::Swap(con[j], con[j-1]);
                            }
                            break;
                        default:
                            break;
                    }
                    --j;
                }
            }
            return 0;
        }
    //QuickSort [begin, end) Partition
    template<typename T, typename Container >
        size_t Sort<T, Container>::Partition(Container& con, unsigned int begin, unsigned int end, unsigned int index, SortRule sr){
            size_t maxsize = con.size();
            begin = begin <= maxsize? begin:maxsize;
            end = end <= maxsize? end:maxsize;
            bool isEmpty = con.empty();
            if(isEmpty || index < begin || index > end){
                return -1;
            }
            if(index != begin)
                Sort<T,Container>::Swap(con[index], con[begin]);
            end = end-1;
            index = begin;
            T value = con[index];
            //[beign, end]
            unsigned int  i = begin, j = end;
            while(j > i){
                switch(sr){
                    case ASCEND:
                        while(j > i && con[j] > value) --j;
                        if(j > i){
                            con[i] = con[j];
                            ++i;
                        }
                        while(j > i && con[i] <= value) ++i;
                        if(j > i){
                            con[j] = con[i];
                            --j;
                        }
                        break;
                    case DESCEND:
                        while(j > i && con[j] < value) --j;
                        if(j > i ){
                            con[j] = con[i];
                            ++i;
                        }
                        while(j > i && con[i] >= value) ++i;
                        if(j > i){
                            con[j] = con[i];
                            --j;
                        }
                        break;
                    default:
                        break;
                }
            }
            //i==j
            con[i] =value;
            
            return i;
        }
    //QuickSort
    template<typename T, typename Container>
        int Sort<T,Container>::QuickSort(Container& con, SortRule sr){
            bool isEmpty = con.empty();
            if(isEmpty){
                return -1;
            }
            //[begin, end)
            size_t begin = 0;
            size_t end = con.size();
            std::stack<size_t> posStack;
            posStack.push(begin);
            posStack.push(end);
            while(!posStack.empty()){
                end = posStack.top();
                posStack.pop();
                begin = posStack.top();
                posStack.pop();
                size_t pos = Sort<T,Container>::Partition(con, begin, end, begin, sr);  
                if(pos > begin){
                     //[begin, pos)
                     posStack.push(begin);
                     posStack.push(pos);
                 }
                if(pos < end){
                     //[pos+1, end)
                     posStack.push(pos+1);
                     posStack.push(end);
                }
            }
            return 0;
        }
    //QuickSort [begin, end)
    template<typename T, typename Container>
        int Sort<T,Container>::QuickSort(Container& con, unsigned int begin, unsigned int end, SortRule sr){
            size_t maxsize = con.size();
            begin = begin <= maxsize? begin:maxsize;
            end = end <= maxsize?end:maxsize;
            bool isEmpty = con.empty();
            if(isEmpty || begin >= maxsize){
                return -1;
            }
            //[begin, end)
            std::stack<size_t> posStack;
            posStack.push(begin);
            posStack.push(end);
            while(!posStack.empty()){
                end = posStack.top();
                posStack.pop();
                begin = posStack.top();
                posStack.pop();
                size_t pos = Sort<T,Container>::Partition(con, begin, end, begin, sr);
                if(pos > begin){
                    //[begin, pos)
                    posStack.push(begin);
                    posStack.push(pos);
                }
                if(pos < end){
                    //[pos, end)
                    posStack.push(pos);
                    posStack.push(end);
                }
            }
            return 0;
        }
    //Merge
    template<typename T, typename Container >
        int  Sort<T, Container>::Merge(Container& con, Container& left, const size_t leftSize, Container& right, const size_t rightSize, SortRule sr){
            bool isEmpty = con.empty() || left.empty() || right.empty();
            if(isEmpty){
                return -1;
            }
            size_t i = 0, j = 0, index = 0;
            while(i < leftSize && j < leftSize){
                switch(sr){
                    case ASCEND:
                        con[index++] = left[i] < right[j]? left[i++]:right[j++];
                        break;
                    case DESCEND:
                        con[index++] = left[i] > right[j]? left[i++]:right[j++];
                        break;
                    default:
                        break;
                } 
            }
            while(i < leftSize){
                con[index++] = left[i++];
            }
            while(j < rightSize){
                con[index++] = right[j++];
            }
            return 0;
        }
    //MergeSort
    template<typename T, typename Container >
        int Sort<T, Container>::MergeSort(Container& con, SortRule sr){
            bool isEmpty = con.empty();
            if(isEmpty){
                return -1;
            }
            size_t begin = 0;
            size_t end = con.size();
            MergeSort(con, begin, end, sr);
            return 0;
        }
    //MergeSort [begin, end)
    template<typename T, typename Container >
        int Sort<T, Container>::MergeSort(Container& con, unsigned int begin, unsigned int end, SortRule sr){
            size_t maxsize = con.size();
            begin = begin <= maxsize? begin:maxsize;
            end = end <= maxsize? end:maxsize;
            bool isEmpty = con.empty();
            if(isEmpty || begin >= end){
                return -1;
            }
            if((end-begin) < 2){
                return 0;
            }
            unsigned int middle = (begin+end)/2;
            //[begin, middle)
            Container left(con.begin()+begin, con.begin()+middle);
            //[middle, end)
            Container right(con.begin()+middle, con.begin()+end);
            MergeSort(left, begin, middle, sr);
            MergeSort(right,middle, end, sr);
            int ret = Merge(con, left, left.size(), right, right.size(), sr);
            if(ret == -1){
                return -1;
            }
            return 0;
        }
}
#endif


































