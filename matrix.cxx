//Methods
using namespace std;

template<typename T> Matrix<T>::Matrix(int h,int w) :rows(h), cols(w), data(rows,Vector<T>(h))//Constructor
{
}

template<typename T> Matrix<T>& Matrix<T>::operator[](std::initializer_list<T> list)
{
    std::uninitialized_copy(list.begin(), list.end(), index);
    return *this;
};

template<typename T> Matrix<T>& Matrix<T>::operator=(T value) //sets value of the index
{
    data[index[0]].v[index[1]]=value;
    return *this;
};


/**
template<typename T, typename S> // Matrix x Scalar
Matrix<typename std::common_type<T,S>::type> operator*(const Matrix<T>& mat,const S s)
{
    Matrix<typename std::common_type<T,S>::type> result(mat.rows,mat.cols);
    for(auto i = 0;i<mat.h;i++)
    {
        result[i]=mat[i]*s;
    }
    return result;
};

template<typename T, typename S> //Scalar x Matrix
Matrix<typename std::common_type<T,S>::type> operator*(const S s,const Matrix<T>& mat)
{
    return mat*s;
};**/


template<typename T, typename M>    //Matrix x Vector
Vector<typename std::common_type<T,M>::type> operator*(const Matrix<T>& mat,Vector<M> vec)
{
    Vector<typename std::common_type<T,M>::type> result(mat.rows);
    for(auto i = 0;i<mat.h;i++)
    {
        result.v[i]=dot(mat[i],vec);
    }
    return result;
};
