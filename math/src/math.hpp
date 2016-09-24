#ifndef __MATH_H_
#define __MATH_H_
#include <limits>
namespace tools{
    class MathTools{
        public:
            //n^p
            static unsigned int Power(unsigned int n, unsigned int p);
            //(n^p)%m
            static unsigned int PowerModel(unsigned int n, unsigned int p, unsigned int m);
            //IsPrime
            static bool IsPrime(unsigned int n);        
            //Greatest Common Divisor
            static unsigned int GCD(unsigned int m, unsigned int n);
            static int GCD(int m, int n);
            //Least Common Multiple
            static unsigned  int LCM(unsigned int m, unsigned int n);
            static int LCM(int m, int n);

        public:
            template<typename T>
            static T MaxSubArray(T* arr, int low, int high);   
    };
    template<typename T>
    T   MathTools::MaxSubArray(T* arr, int low, int high){//[log, high)
            if(arr == 0) return -1;
            T sumax = std::numeric_limits<T>::min();
            T temp = 0;
            for(int i = low; i < high; ++i){
                temp += arr[i];
                if(temp > sumax) sumax = temp;
                if(temp < 0) temp = 0;
            }
            return sumax;
    }
}
#endif
