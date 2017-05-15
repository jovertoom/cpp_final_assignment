#include <memory>
#include <type_traits>
#include <cassert>
#include <iostream>
#include <string>

//Class Methods
template <typename T> Vector<T>::Vector() : v(nullptr)
{
}

template <typename T> Vector<T>::Vector(int n) 
:length(n), v(new T[n])
{
}

template <typename T> Vector<T>::Vector(const Vector& other) //copy constructor
: Vector(other.length) 
{
}

template <typename T> Vector<T>::Vector(std::initializer_list<T> list)  //constructor with list
: Vector((int)list.size())
{
    std::uninitialized_copy(list.begin(), list.end(), v);
}

template<typename T> Vector<T>& Vector<T>::operator=(const Vector& other) // copy operator
{
    assert(length == other.length);
    if (this!=&other) {
        delete[] v;
        v = new T[other.length];
        for (int i = 0; i<length; i++) {
            v[i]=other.v[i];
        }
    }
    return *this;
}
//  End of class methods

// Vectors operating on other vectors


template<typename M, typename T> // Substraction
Vector<typename std::common_type<M,T>::type> operator-(const Vector<T>& a, const Vector<M>& b) 
{
    assert(a.length == b.length); 
    int l = a.length;
    Vector<typename std::common_type<M,T>::type> result(l);
    
    for (auto i = 0; i<l; i++) {
        result.v[i] = a.v[i] - b.v[i];
    }
    return result;
};

template<typename M, typename T> // Addition
Vector<typename std::common_type<M,T>::type> operator+(const Vector<T>& a,
                                                        const Vector<M>& b) 
{
    assert(a.length == b.length); 
    int l = a.length;
    Vector<typename std::common_type<M,T>::type> result(l);
    
    for (auto i = 0; i<l; i++) {
        result.v[i] = a.v[i] + b.v[i];
    }
    return result;
};

template<typename T>
std::ostream& operator << (std::ostream& os, const Vector<T>& obj)
{
    os << "{";
    for(auto i=0;i<obj.length;i++)
    {
        os << " " << obj.v[i] << " ";
    }
    os<< "}" << std::endl;
    return os;
}; 

template<typename T,typename M>
typename std::common_type<M,T>::type dot(const Vector<T>& a, const Vector<M>& b)
{
    assert(a.length == b.length);
    typename std::common_type<M,T>::type result=0;
    for (auto i=0; i<a.length; i++) {
        result += a.v[i]+b.v[i];
    }
    return result;
};

template<typename T, typename S>
Vector<typename std::common_type<T,S>::type> operator*(const Vector<T>& vec,const S s) 
{
    Vector<typename std::common_type<T,S>::type> result(vec.length);
    for (int i = 0; i<vec.length; i++) {
        result.v[i]=vec.v[i]*s; 
    }
    return result;
}

template<typename T, typename S>
Vector<typename std::common_type<T,S>::type> operator*(const S s,const Vector<T>& vec)
{
    return vec*s;
}
