#ifndef ACMTSE_MY_VECTOR_HPP
#define ACMTSE_MY_VECTOR_HPP

#include <cstddef>

namespace acmtse {

    // Make this work by implementing everything labeled with TODO!
    template<class T>
    class my_vector {
        private:
            T* d_arr_p;
            size_t d_size;
            size_t d_capacity;
        public:
            /*
             * Default constructor will initialize vector
             * to have a capacity of some arbitrary amount.
             * Already implemented.
             */
            my_vector();

            /*
             * Creates a vector containing with {size} capacity.
             *
             * That is, the vector can store maximally {size} elements
             * before it needs to resize.
             *
             * Every element in my_vector can remain uninitialized upon
             * allocation. Note that std::vector does not follow this
             * convention: upon std::vector initialization, every element is
             * default initialized.
             */
            my_vector(size_t size);

            /*
             * Copy constructor
             */
            my_vector(const my_vector& other);

            /*
             * Destructor
             */
            ~my_vector();

            /*
             * Swaps contents of this vector with the other vector.
             */
            void swap(my_vector& other);

            /*
             * Attempts to resize the backing array to an array
             * with capacity {size}. 
             *
             * If {size} is less than or equal to the capacity of
             * the current array, return early. Otherwise, 
             * create a new backing array of capacity {size} and
             * copy the contents of the old backing array into the
             * new array.
             */
            void reserve(size_t size);

            /*
             * Adds an element to the back of the array in the
             * last position that has not been used yet. 
             *
             * If there is no more space for the element to be 
             * added, then a resize is triggered. Assume that
             * the backing array will be resized to at least twice
             * the capacity of the old array.
             */
            void push_back(const T& elem);
            
            /*
             * Assignments other vector into this vector
             */
            my_vector& operator=(const my_vector& other){
                my_vector temp(other);
                swap(temp);
                return *this;
            }

            /*
             * Array/vector access. No bounds checking is required.
             */
            T& operator[](size_t idx);

            /*
             * The number of elements currently in the vector.
             */
            size_t size() const;

            /*
             * The number of elements that the backing array of this
             * vector can support. Must be greater than or equal
             * to size().
             */
            size_t capacity() const;
    };

    template <class T>
    inline my_vector<T>::my_vector() : my_vector(50) {
    }

    template <class T>
    inline my_vector<T>::my_vector(size_t size) :
        // TODO: Implement size constructor
        d_arr_p(new T[size]()), d_size(0), d_capacity(size){ // Initial allocation of array
    }

    template <class T>
    inline my_vector<T>::my_vector(const my_vector &other) :
    // TODO: Copy Constructor
        d_arr_p(new T[other.d_capacity]()), 
        d_size(other.d_size), d_capacity(other.d_capacity){
        for (size_t i = 0; i < d_size; i++) {
            d_arr_p[i] = other.d_arr_p[i];
        }
    }

    template <class T>
    inline my_vector<T>::~my_vector() {
        delete[] d_arr_p;
        /*
        // TODO: Implement destructor 
        for(int i = 0; i < d_size; i++){
            d_arr_p[i].~T();
        }
        // Need to consider that the destructor will never throw or else will never delete
        operator delete(d_arr_p);
        */
    }

    template <class T>
    inline void my_vector<T>::swap(my_vector& other) {
        // TODO: Implement swap 
        using std::swap;
        swap(d_arr_p, other.d_arr_p);
        swap(d_size, other.d_size);
        swap(d_capacity, other.d_capacity);
    }

    template <class T>
    inline void my_vector<T>::reserve(size_t size) {
        // TODO: Implement reserve 
        if(size <= d_capacity) return;

        my_vector temp(size);

        while(temp.d_size < d_size){
            temp.push_back(d_arr_p[temp.d_size]);
        }
        swap(temp);
    }

    template <class T>
    inline void my_vector<T>::push_back(const T& elem) {
        // TODO: Implement push_back 
        if( d_size == d_capacity) 
        {
            reserve(d_size*2 + 1);
        }

        new (d_arr_p+d_size) T(elem);
        ++d_size;
    }



    template <class T>
    inline T& my_vector<T>::operator[](size_t idx) {
        // TODO: Implement array access 
        return d_arr_p[idx];
    }

    template <class T>
    inline size_t my_vector<T>::size() const {
        return d_size;
    }

    template <class T>
    inline size_t my_vector<T>::capacity() const {
        return d_capacity;
    }
}

#endif
