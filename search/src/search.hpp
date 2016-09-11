#ifndef __SEARCH_H_
#define __SEARCH_H_
#include <vector>
#include "searchdef.h"
using namespace std;
namespace tools{
    template<typename T, typename Container = std::vector<T> >
        class Search{
            public:
                static int SequenceSearch(Container& con, T& value);
                static int BinarySearch(Container& con, T& value, SortRule sr = ASCEND);
        };
    template<typename T, typename Container >
        int Search<T,Container>::SequenceSearch(Container& con, T& value){
                bool isEmpty = con.empty();
                if(isEmpty){
                    return -1;
                }
                int len = (int)con.size();
                for(int index = 0;  index < len; ++index){
                    if(con[index] == value){
                        return index;
                    }
                }
                return -1;
        }
    template<typename T, typename Container >
        int Search<T,Container>::BinarySearch(Container& con, T& value, SortRule sr){
            bool isEmpty = con.empty();
            if(isEmpty){
                return -1;
            }
            int begin = 0;
            int end =(int)con.size()-1;
            while(begin <= end){
                int middle = begin + ((end-begin) >> 1);
                if(con[middle] == value){
                    return middle;
                }
                switch(sr){
                    case ASCEND:
                        if(con[middle] < value){
                            begin =  middle+1;
                        }else{
                            end = middle-1;
                        }
                        break;
                    case DESCEND:
                        if(con[middle] < value){
                            end = middle-1;
                        }else{
                            begin = middle+1;
                        }
                        break;
                    default:
                        break;
                }
            }
            return -1;
        }

}

#endif
