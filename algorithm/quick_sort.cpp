#include<iostream>
#include<vector>
#include<ctime>
#include<random>
#define N 1000

template <typename T>
auto partition(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end)
{
    auto pivot_val = *begin;
    auto left_iter = begin + 1;
    auto right_iter = end;

    while(1)
    {
        while(*left_iter <= pivot_val && std::distance(left_iter, right_iter) > 0)
            left_iter++;
        
        while(*right_iter > pivot_val && std::distance(left_iter, right_iter) > 0)
            right_iter--;

        if(left_iter == right_iter)
        {
            break;
        }
        else
        {
            std::iter_swap(left_iter, right_iter);
        }
    }

    if(pivot_val > *right_iter)
    {
        std::iter_swap(begin, right_iter);
    }

    return right_iter;
}

template <typename T>
void quick_sort(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator last)
{
    if(std::distance(begin, last) >= 1)
    {
        auto partition_iter = partition<T>(begin, last);

        quick_sort<T>(begin, partition_iter -1);
        quick_sort<T>(partition_iter, last);
    }
}

template <typename T>
void print_vector(std::vector<T> arr)
{
    int count = 1;

    for(auto i : arr)
    {
        std::cout << i << " ";

        if(count%10 == 0)
        {
            std::cout << std::endl;
        }
        
        count++;
    }
}


int main()
{
    srand(time(NULL));
    
    std::vector<int> vec(N);
    int rand_val;

    for(int i = 0; i < N; i++)
    {
        rand_val = rand() % N + 1;
        vec[i] = rand_val;
    }

    print_vector(vec);

    quick_sort<int>(vec.begin(), vec.end() - 1);

    std::cout << std::endl << "[after sort]" << std::endl;
    print_vector(vec);
}