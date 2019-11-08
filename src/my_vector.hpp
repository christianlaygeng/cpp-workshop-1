#ifndef ACMTSE_MY_VECTOR_HPP
#define ACMTSE_MY_VECTOR_HPP

#include <cstddef>

namespace acmtse {
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
             * Assignment operator
             */
            my_vector& operator=(const my_vector& other);

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
}

#endif
