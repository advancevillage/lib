#include "math.hpp"
#include <cmath>
using namespace std;
unsigned int tools::MathTools::Power(unsigned int n, unsigned int p){
    unsigned int value = 1;
    const unsigned int temp = 1;
    while(p > 1){
        if((p & temp) != 0){
            value = value * n;
        }
        n = n * n;
        p = p >> 1;
    }
    return (n*value);
}
//(X*Y)%Z = ((X%Z)*(Y%Z))%Z
unsigned  int tools::MathTools::PowerModel(unsigned int n, unsigned int p, unsigned int m){
    unsigned int value = 1;
    const unsigned int temp = 1;
    n = n%m;
    while(p > 1){
        if(0 != (p & temp)){
            value = (value*n)%m;
        }
        n =(n*n)%m;
        p = p >> 1;
    }
    return (n*value)%m;
}
//IsPrime
bool tools::MathTools::IsPrime(unsigned int n){
    if(n < 2){
        return false;
    }
    unsigned int limit = (unsigned int)sqrt((double)n);
    for(unsigned int i = 2; i <= limit; ++i){
        if(0 == (n%i)) return false;
    }
    return true;
}
unsigned int tools::MathTools::GCD(unsigned int m, unsigned int n){
    unsigned r = m%n;
    while(r > 0){
        m = n;
        n = r;
        r = m%n;
    }
    return n;
}
int tools::MathTools::GCD(int m, int n){
    int r = m%n;
    while(r > 0){
        m = n;
        n = r;
        r = m%n;
    }
    return n;
}
unsigned int tools::MathTools::LCM(unsigned int m, unsigned int n){
    unsigned int gcd = tools::MathTools::GCD(m, n);
    return (m*n)/gcd;
}
int tools::MathTools::LCM(int m, int n){
    int gcd = tools::MathTools::GCD(m,n);
    return (m*n)/gcd;
}
