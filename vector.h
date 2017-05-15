#ifndef VECTOR_H
#define VECTOR_H

#include <memory>

template<typename T> class Vector{
public :
    T* v; int length; 
    
    Vector();
    Vector(int n);
    Vector(const Vector& other);
    Vector(std::initializer_list<T> list);
    Vector<T>& operator=(const Vector& other); // copy operator
    
};

template<typename M, typename T>
Vector<typename std::common_type<M,T>::type> operator-(const Vector<T>& a,const Vector<M>& b);

template<typename M, typename T>
Vector<typename std::common_type<M,T>::type> operator+(const Vector<T>& a,const Vector<M>& b);

template<typename T>
std::ostream& operator << (std::ostream& os, const Vector<T>& V);

template<typename T,typename M>
typename std::common_type<M,T>::type dot(const Vector<T>& a, const Vector<M>& b);

template<typename T, typename S>
Vector<typename std::common_type<T,S>::type> operator*(const Vector<T>& vec,const S s); 

template<typename T, typename S>
Vector<typename std::common_type<T,S>::type> operator*(const S s,const Vector<T>& vec); 


#include "vector.cxx"
#endif 
