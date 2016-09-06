#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include "sort.hpp"
using namespace std;
template<typename T>
void display(T& value){
    cout << value << "  ";
}
int main(){

    int arr[10] = {1, 5, 9, 199, 22, 55, 2, 4, 55, 88};
    vector<int> vec(arr, arr+sizeof(arr)/sizeof(int));
    deque<int> deq(arr, arr+sizeof(arr)/sizeof(int));
    cout << "Vector " <<endl;
    for_each(vec.begin(), vec.end(), display<int>);
    cout << endl;
    cout << "Deque" << endl;
    for_each(deq.begin(), deq.end(), display<int>);
    cout << endl;
    cout << "Vector Sort" << endl;
    enum SortRule sr = DESCEND;
    tools::Sort<int>::BubbleSort(vec, sr);
    for_each(vec.begin(), vec.end(), display<int>);
    cout << endl;
    cout << "Deque Sort"  <<endl;
    sr = ASCEND;
    tools::Sort<int, deque<int> >::BubbleSort(deq, sr);
    for_each(deq.begin(), deq.end(), display<int>);
    cout << endl;
    cout << "Vector Sort range"<<endl;
    sr = ASCEND;
    tools::Sort<int>::BubbleSort(vec, 0, 5, sr);
    for_each(vec.begin(), vec.end(), display<int>);
    cout << endl;
    cout << "InsertSort"<<endl;
    tools::Sort<int>::InsertSort(vec);
    for_each(vec.begin(), vec.end(), display<int>);
    cout << endl;
    cout << "InsertSort range" << endl;
    sr = DESCEND;
    tools::Sort<int>::InsertSort(vec, 5,10, sr);
    for_each(vec.begin(), vec.end(), display<int>);
    cout << endl;
    cout << "QuickSort " << endl;
    sr =ASCEND;
    tools::Sort<int>::QuickSort(vec, sr);
    for_each(vec.begin(), vec.end(), display<int>);
    cout << endl;
    cout << "MergeSort " << endl;
    sr = DESCEND;
    tools::Sort<int>::MergeSort(vec, sr);
    for_each(vec.begin(), vec.end(), display<int>);
    cout << endl;
    return 0;
}
