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
		static void EffectiveValue(T min, T& value, T max);
        //HeapSort [begin, end)
        static int MaintainHeap(Container& con,int begin, int end, HeapType ht = MAXHEAP);    
        static int CreateHeap(Container& con, int begin, int end, HeapType ht = MAXHEAP);
	public:
		//BubbleSort
		static int BubbleSort(Container& con, SortRule sr = ASCEND);
		static int BubbleSort(Container& con, int begin, int end, SortRule sr = ASCEND);
		//InsertSort
		static int InsertSort(Container& con, SortRule sr = ASCEND);
		static int InsertSort(Container& con, int begin, int end, SortRule sr = ASCEND);
		//QuickSort
		static int QuickSort(Container& con, SortRule sr = ASCEND);
		static int QuickSort(Container& con, int begin, int end, SortRule sr = ASCEND);
		//MergeSort
		static int MergeSort(Container& con, SortRule sr = ASCEND);
		static int MergeSort(Container& con, int begin, int end, SortRule sr = ASCEND);
        //HeapSort
        static int HeapSort(Container& con, SortRule sr = ASCEND);

	private:
		static int Partition(Container& con, int begin, int end, int index, SortRule sr = ASCEND);
		static int  Merge(Container& con, Container& left, const int leftSize, Container& right, const int rightSize, SortRule sr = ASCEND);

	};

	//Swap
	template<typename T, typename Container >
	void Sort<T, Container>::Swap(T& fir, T& sec){
		T temp = fir;
		fir = sec;
		sec = temp;
	}
	//EffectiveValue [min, max]
	template<typename T, typename Container >
	void Sort<T, Container>::EffectiveValue(T min, T& value, T max){
		value = value >= min ? (value <= max ? value : max) : min;
	}
	//BubbleSort
	template<typename T, typename Container >
	int Sort<T, Container>::BubbleSort(Container& con, SortRule sr){
		bool  isEmpty = con.empty();
		if (isEmpty){
			return -1;
		}
		int begin = 0;
		int end = (int)con.size();
		BubbleSort(con, begin, end, sr);
		return 0;
	}
	//BubbleSort [begin, end) 
	template<typename T, typename Container >
	int  Sort<T, Container>::BubbleSort(Container& con, int begin, int end, SortRule sr){
		int maxlen = (int)con.size();
		EffectiveValue(0, begin, maxlen);
		EffectiveValue(0, end, maxlen);
		int len = end - begin;
		bool isEmpty = con.empty();
		if (len <= 0 || isEmpty){
			return -1;
		}
		else{
			bool isSwap = true;
			for (int i = 0; isSwap && i < len - 1; ++i){
				isSwap = false;
				for (int j = begin; j < end - 1 - i; ++j){
					switch (sr){
					case ASCEND:
						if (con[j] > con[j + 1]){
							Sort<T, Container>::Swap(con[j], con[j + 1]);
							isSwap = true;
						}
						break;
					case DESCEND:
						if (con[j] < con[j + 1]){
							Sort<T, Container>::Swap(con[j], con[j + 1]);
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
		bool isEmpty = con.empty();
		if (isEmpty){
			return -1;
		}
		int begin = 0;
		int end = (int)con.size();
		InsertSort(con, begin, end, sr);
		return 0;
	}
	//InsertSort [begin, end)
	template<typename T, typename Container >
	int Sort<T, Container>::InsertSort(Container& con, int begin, int end, SortRule sr){
		int maxlen = (int)con.size();
		EffectiveValue(0, begin, maxlen);
		EffectiveValue(0, end, maxlen);
		bool isEmpty = con.empty();
		if (isEmpty){
			return -1;
		}
		for (int i = begin + 1; i < end; ++i){
			T temp = con[i];
			int j = i;
			while (j > begin){
				switch (sr){
				case ASCEND:
					if (con[j] < con[j - 1]){
						Sort<T, Container>::Swap(con[j], con[j - 1]);
					}
					break;
				case DESCEND:
					if (con[j] > con[j - 1]){
						Sort<T, Container>::Swap(con[j], con[j - 1]);
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
	int Sort<T, Container>::Partition(Container& con, int begin, int end, int index, SortRule sr){
		int maxlen = (int)con.size();
		EffectiveValue(0, begin, maxlen);
		EffectiveValue(0, end, maxlen);
		bool isEmpty = con.empty();
		if (isEmpty || index < begin || index >= end){
			return -1;
		}
		if (index != begin)
			Sort<T, Container>::Swap(con[index], con[begin]);
		end = end - 1;
		index = begin;
		T value = con[index];
		//[beign, end]
		int  i = begin, j = end;
		while (j > i){
			switch (sr){
			case ASCEND:
				while (j > i && con[j] > value) --j;
				if (j > i){
					con[i] = con[j];
					++i;
				}
				while (j > i && con[i] <= value) ++i;
				if (j > i){
					con[j] = con[i];
					--j;
				}
				break;
			case DESCEND:
				while (j > i && con[j] < value) --j;
				if (j > i){
					con[j] = con[i];
					++i;
				}
				while (j > i && con[i] >= value) ++i;
				if (j > i){
					con[j] = con[i];
					--j;
				}
				break;
			default:
				break;
			}
		}
		//i==j
		con[i] = value;

		return i;
	}
	//QuickSort
	template<typename T, typename Container>
	int Sort<T, Container>::QuickSort(Container& con, SortRule sr){
		bool isEmpty = con.empty();
		if (isEmpty){
			return -1;
		}
		//[begin, end)
		int begin = 0;
		int end = (int)con.size();
		QuickSort(con, begin, end, sr);
		return 0;
	}
	//QuickSort [begin, end)
	template<typename T, typename Container>
	int Sort<T, Container>::QuickSort(Container& con, int begin, int end, SortRule sr){
		int maxlen = (int)con.size();
		EffectiveValue(0, begin, maxlen);
		EffectiveValue(0, end, maxlen);
		bool isEmpty = con.empty();
		if (isEmpty || begin >= end){
			return -1;
		}
		//[begin, end)
		std::stack<int> posStack;
		posStack.push(begin);
		posStack.push(end);
		while (!posStack.empty()){
			end = posStack.top();
			posStack.pop();
			begin = posStack.top();
			posStack.pop();
			int pos = Sort<T, Container>::Partition(con, begin, end, begin, sr);
			if (pos >= 0 && pos > begin){
				//[begin, pos)
				posStack.push(begin);
				posStack.push(pos);
			}
			if (pos >= 0 && pos < end){
				//[pos, end)
				posStack.push(pos+1);
				posStack.push(end);
			}
		}
		return 0;
	}
	//Merge
	template<typename T, typename Container >
	int  Sort<T, Container>::Merge(Container& con, Container& left, const int leftSize, Container& right, const int rightSize, SortRule sr){
		bool isEmpty = con.empty() || left.empty() || right.empty();
		if (isEmpty){
			return -1;
		}
		int i = 0, j = 0, index = 0;
		while (i < leftSize && j < rightSize){
			switch (sr){
			case ASCEND:
				con[index++] = left[i] < right[j] ? left[i++] : right[j++];
				break;
			case DESCEND:
				con[index++] = left[i] > right[j] ? left[i++] : right[j++];
				break;
			default:
				break;
			}
		}
		while (i < leftSize){
			con[index++] = left[i++];
		}
		while (j < rightSize){
			con[index++] = right[j++];
		}
		return 0;
	}
	//MergeSort
	template<typename T, typename Container >
	int Sort<T, Container>::MergeSort(Container& con, SortRule sr){
		bool isEmpty = con.empty();
		if (isEmpty){
			return -1;
		}
		int begin = 0;
		int end = (int)con.size();
		if (end <= 1 || begin >= end){
			return 0;
		}
		int middle = (begin + end) / 2;
		Container left(con.begin() + begin, con.begin() + middle);
		Container right(con.begin() + middle, con.begin() + end);
		MergeSort(left, sr);
		MergeSort(right, sr);
		int ret = Merge(con, left, (int)left.size(), right, (int)right.size(), sr);
		if (ret == -1){
			return -1;
		}
		return 0;
	}
	//MergeSort [begin, end)
	template<typename T, typename Container >
	int Sort<T, Container>::MergeSort(Container& con, int begin, int end, SortRule sr){
		bool isEmpty = con.empty();
		if (isEmpty){
			return -1;
		}
		int maxsize = (int)con.size();
		EffectiveValue(0, begin, maxsize);
		EffectiveValue(0, end, maxsize);
		if (begin >= end){
			return 0;
		}
		Container temp(con.begin() + begin, con.begin() + end);
		MergeSort(temp, sr);
		for (int i = begin; i < end; ++i) con[i] = temp[i-begin];
		return 0;
	}
    //HeapSort [begin, end)
    template<typename T, typename Container >
        int  Sort<T,Container>::MaintainHeap(Container& con, int begin, int end, HeapType ht){
            int maxsize = (int)con.size();
            bool isEmpty = con.empty();
            if(isEmpty){
                return -1;
            }
            EffectiveValue(0, begin, maxsize);
            EffectiveValue(0, end, maxsize);    
            int root = begin;
            int left = 2*root+1;
            while(left < end){
                switch(ht){
                    case MAXHEAP:
                        if((left+1) < end && con[left] < con[left+1]) ++left;
                        if(con[root] > con[left]){
                           return 0;
                        }
                       break;
                    case MINHEAP:
                        if((left+1) < end && con[left] > con[left+1]) ++left;
                        if(con[root] < con[left]){
                            return 0;
                        }
                        break;
                    default:
                        break;
                }
                Sort<T,Container>::Swap(con[root], con[left]);
                root = left;
                left = 2*root+1;
            }
            return 0;
        }
    //HeapSort [beign, end)
    template<typename T, typename Container >
        int Sort<T, Container>::CreateHeap(Container& con, int begin, int end, HeapType ht){
            int maxsize = (int)con.size();
            bool isEmpty = con.empty();
            if(isEmpty){
                return -1;
            }
            EffectiveValue(0, begin, maxsize);
            EffectiveValue(0, end, maxsize);
            int len = end - begin;
            for(int i = begin + (len/2) - 1; i >= begin; --i){
                Sort<T,Container>::MaintainHeap(con, i, end, ht); 
            }
            return 0;
        }
    //HeapSort [begin, end)
    template<typename T, typename Container >
        int Sort<T,Container>::HeapSort(Container& con, SortRule sr){
            bool isEmpty = con.empty();
            if(isEmpty){
                return -1;
            }
            int end =(int)con.size();
            int begin = 0;
            HeapType ht = MAXHEAP;
            switch(sr){
                case ASCEND:
                    ht = MAXHEAP;
                    break;
                case DESCEND:
                    ht = MINHEAP;
                    break;
                default:
                    break;
            }
            Sort<T,Container>::CreateHeap(con, begin, end, ht);
            while(end > 0){
                Sort<T,Container>::Swap(con[0], con[end-1]);
                --end;
                Sort<T,Container>::MaintainHeap(con, begin, end, ht);
            }
           return 0; 
        }
}

#endif

