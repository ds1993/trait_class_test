#include <stdio.h>
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <stdexcept>

template<typename IterT>
void doAdvance(IterT& iter, int d, std::random_access_iterator_tag)
{
    printf("random_access_iterator_tag\n");
    iter += d;
}

template<typename IterT>
void doAdvance(IterT& iter, int d, std::bidirectional_iterator_tag)
{
    printf("bidirectional_iterator_tag\n");
    if (d >= 0) {
        while (d--) ++iter;
    }
    else {
        while (d++) --iter;
    }
}

template<typename IterT>
void doAdvance(IterT& iter, int d, std::input_iterator_tag)
{
    printf("input_iterator_tag\n");
    if (d < 0) {
        throw std::out_of_range("Negative distance");
    }
    else {
        while (d--) ++iter;
    }
}

template<typename IterT>
void advance(IterT& iter, int d)
{
    doAdvance(iter, d, typename std::iterator_traits<IterT>::iterator_category());
}

int main()
{
    std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int>::iterator vec_iter = vec.begin();
    advance(vec_iter, 5);
    printf("vec_iter = %d\n", *vec_iter);
    std::list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int>::iterator lst_iter = lst.begin();
    advance(lst_iter, 5);
    printf("lst_iter = %d\n", *lst_iter);
}
