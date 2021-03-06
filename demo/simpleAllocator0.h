#ifndef __SALLOCATOR_0__
#define __SALLOCATOR_0__

#include <new>
#include <cstddef>
#include <cstdlib>
#include <climits>
#include <iostream>

namespace SA0 {
    template <typename T>
    inline T* _allocate(ptrdiff_t size, T* hint) {
        std::set_new_handler(0);
        T* tmp = (T*)(::operator new((size_t)(size*sizeof(T))));
        if(!tmp) {
            std::cerr << "out of mem" << std::endl;
            exit(1);
        }
        return tmp;
    }

    template <typename T>
    inline void _deallocate(T* buffer) {
        ::operator delete(buffer);
    }

    template <typename T1, typename T2>
    inline void _construct(T1* p, const T2& val) {
        new(p) T1(val);
    }

    template <typename T>
    inline void _destroy(T* p) {
        p->~T();
    }

    template <typename T>
    class allocator {
    public:
        typedef T value_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef T& reference;
        typedef const T& const_reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        
        template <typename U>
        struct rebind {
            typedef allocator<U> other;
        };

        pointer allocate(size_type n, const void* hint = nullptr) {
            return _allocate((difference_type)n, (pointer)0);
        }

        void deallocate(pointer p, size_type n) {
            _deallocate(p);
        }

        void construct(pointer p, const T& val) {
            _construct(p, val);
        }

        void destroy(pointer p) {
            _destroy(p);
        }

        pointer address(reference x) {
            return (pointer)&x;
        }

        const_pointer const_address(const_reference x) {
            return (const_pointer)&x;
        }

        size_type max_size() const {
            return size_type(UINT_MAX/sizeof(T));
        }
    }; // end of class allocator
} // end of namespace SA0;

#endif