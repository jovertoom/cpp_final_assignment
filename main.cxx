#include "vector.h"
#include "matrix.h"
#include <iostream>
using namespace std;
int main ()
{
    Vector<int> V = {1,2};
    Vector<int> B = {2,3};
    auto a = dot(V,B);
    
    Matrix<int> M(2,2);
    //M[{0,0}]=1; M[{0,1}]=2; M[{1,0}]=3; M[{1,1}]=4;
    
    std::cout<<(V-B).v[1]<<std::endl;
    std::cout<<V<<std::endl;
    std::cout<<a<<std::endl;
    std::cout<<2.5*V<<std::endl;
    std::cout<<V*2.5<<std::endl;
    return 0;
}

