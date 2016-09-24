#include<iostream>
#include"math.hpp"
using namespace std;


int main(void){

    int n = 4;
    int p = 5;
    int m = 7;

    cout << "Power(" << n <<","<<p<<") = " << tools::MathTools::Power(n, p)<< endl;;
    cout << tools::MathTools::PowerModel(n, p, m) << endl;    
    for(unsigned int i = 0; i < 1000; ++i){
        if(tools::MathTools::IsPrime(i)){
            cout << i << " ";
        }
    }
    int arr[] = {3, -1, 2, 5, -3, 4, -6, -7, 1, 8, -3, 5, 9};
    int len = sizeof(arr)/sizeof(int);
    cout << "MaxSubArray = " << tools::MathTools::MaxSubArray<int>(arr, 0, len) << endl;
    return 0;
}
