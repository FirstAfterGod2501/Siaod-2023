//
// Created by first on 08.09.23.
//

#ifndef TASK1_MERGESORT_H
#define TASK1_MERGESORT_H

#include <algorithm>
#include <iterator>
#include <omp.h>
#include <memory>

#include <new>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int number_of_allocs = 0;

void* operator new(std::size_t size) noexcept(false) {
    number_of_allocs+=size;
    void *p = malloc(size);
    if(!p) throw std::bad_alloc();
    return p;
}


void* operator new  [](std::size_t size) noexcept(false) {
    number_of_allocs+=size;
    void *p = malloc(size);
    if(!p) throw std::bad_alloc();
    return p;
}

void* operator new  [](std::size_t size, const std::nothrow_t&) throw() {
    number_of_allocs+=size;
    return malloc(size);
}
void* operator new   (std::size_t size, const std::nothrow_t&) throw() {
    number_of_allocs+=size;
    return malloc(size);
}


void operator delete(void* ptr) throw() { number_of_allocs-=sizeof(ptr); free(ptr); }
void operator delete (void* ptr, const std::nothrow_t&) throw() { number_of_allocs-=sizeof(ptr); free(ptr); }
void operator delete[](void* ptr) throw() {number_of_allocs-=sizeof(ptr); free(ptr); }
void operator delete[](void* ptr, const std::nothrow_t&) throw() {number_of_allocs-=sizeof(ptr); free(ptr); }




template <typename Iterator>
void mergesort(Iterator from, Iterator to)
{
#pragma omp parallel
    {
#pragma omp single nowait
        static_assert(!std::is_same<typename std::iterator_traits<Iterator>::value_type, void>::value, "");

        auto n = std::distance(from, to);

        if (1 < n)
        {
#pragma omp task firstprivate (from, to, n)
            {
                Iterator l_from = from;
                Iterator l_to = l_from;
                std::advance(l_to, n/2);
                mergesort(l_from, l_to);
            }
#pragma omp task firstprivate (from, to, n)
            {
                Iterator r_from = from;
                std::advance(r_from, n/2);
                Iterator r_to = r_from;
                std::advance(r_to, n-(n/2));
                mergesort(r_from, r_to);
            }
#pragma omp taskwait

            auto tmp_array = std::make_unique<typename Iterator::value_type[]>(n);
            Iterator l_iter = from;
            Iterator l_end = l_iter;
            std::advance(l_end, n/2);
            Iterator r_iter = l_end;
            Iterator& r_end = to;

            auto tmp_iter = tmp_array.get();

            while (l_iter != l_end || r_iter != r_end)
            {
                if (*l_iter < *r_iter)
                {
                    *tmp_iter = std::move(*l_iter);
                    ++l_iter;
                    ++tmp_iter;
                }
                else
                {
                    *tmp_iter = std::move(*r_iter);
                    ++r_iter;
                    ++tmp_iter;
                }

                if (l_iter == l_end)
                {
                    std::copy(
                            std::make_move_iterator(r_iter),
                            std::make_move_iterator(r_end),
                            tmp_iter
                    );

                    break;
                }

                if (r_iter == r_end)
                {
                    std::copy(
                            std::make_move_iterator(l_iter),
                            std::make_move_iterator(l_end),
                            tmp_iter
                    );

                    break;
                }
            }

            std::copy(
                    std::make_move_iterator(tmp_array.get()),
                    std::make_move_iterator(&tmp_array[n]),
                    from
            );
        }
    }
}
#endif
