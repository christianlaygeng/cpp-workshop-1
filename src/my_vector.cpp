#include "my_vector.hpp"

namespace acmtse {
    template <class T>
    my_vector<T>::my_vector() : my_vector(50) {
    }

    template <class T>
    my_vector<T>::my_vector(size_t size) {
        // TODO: Implement size constructor 
    }

    template <class T>
    my_vector<T>::my_vector(const my_vector &other) {
        // TODO: Implement copy constructor 
    }

    template <class T>
    my_vector<T>::~my_vector() {
        // TODO: Implement destructor 
    }

    template <class T>
    void my_vector<T>::swap(my_vector& other) {
        // TODO: Implement swap 
    }

    template <class T>
    void my_vector<T>::reserve(size_t size) {
        // TODO: Implement reserve 
    }

    template <class T>
    void my_vector<T>::push_back(const T& elem) {
        // TODO: Implement push_back 
    }

    template <class T>
    T& my_vector<T>::operator[](size_t idx) {
        // TODO: Implement array access 
        T t;
        return t;
    }

    template <class T>
    size_t my_vector<T>::size() const {
        return d_size;
    }

    template <class T>
    size_t my_vector<T>::capacity() const {
        return d_capacity;
    }
}
