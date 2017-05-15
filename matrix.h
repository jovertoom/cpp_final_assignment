#ifndef MATRIX_H
#define MATRIX_H

#include <memory>
using namespace std;

template<typename T> class Matrix{
public :
    std::vector<Vector<T>> data;
    int index[2];
    int rows, cols;
    
    Matrix(int h,int w); 
    Matrix<T>& operator[](std::initializer_list<T> list);
    Matrix<T>& operator=(T value);
};


template<typename T, typename M>    //Matrix x Vector
Matrix<typename std::common_type<T,M>::type> operator*(const Matrix<T>& mat,Vector<M> vec);

template<typename T, typename S>
Matrix<typename std::common_type<T,S>::type> operator*(const Matrix<T>& mat,const S s); 

template<typename T, typename S>
Matrix<typename std::common_type<T,S>::type> operator*(const S s,const Matrix<T>& mat); 

#include "matrix.cxx"
#endif 
