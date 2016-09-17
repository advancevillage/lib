#ifndef __MATH_H_
#define __MATH_H_
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
    };
}
#endif
