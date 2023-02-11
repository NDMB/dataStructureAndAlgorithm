#include<iostream>
#include<vector>
#include<ctime>
#include<random>

// 대용량의 데이터를 정렬하는 알고리즘

template <typename T>

std::vector<T> merge(std::vector<T>& arr1, std::vector<T>& arr2)
{
    std::vector<T> merged;

    auto iter1 = arr1.begin();
    auto iter2 = arr2.begin();

    while(iter1 != arr1.end() && iter2 != arr2.end())
    {
        if(*iter1 < *iter2)
        {
            merged.emplace_back(*iter1);
            iter1++;
        }
        else
        {
            merged.emplace_back(*iter2);
            iter2++;
        }
    }

    if(iter1 != arr1.end())
    {
        for(; iter1 != arr1.end(); iter1++)
        {
            merged.emplace_back(*iter1);
        }
    }
    else
    {
        for(; iter2 != arr2.end(); iter2++)
        {
            merged.emplace_back(*iter2);
        }
    }

    return merged;
}


template <typename T>
std::vector<T> merge_sort(std::vector<T> arr)
{
    if(arr.size() > 1)
    {
        auto mid = size_t(arr.size()/2);
        auto left_half = merge_sort<T>(std::vector<T>(arr.begin(), arr.begin() + mid));
        auto right_half = merge_sort<T>(std::vector<T>(arr.begin()+mid, arr.end()));

        return merge<T>(left_half, right_half);
    } 

    return arr;
}

#define N 1000

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

    for(int i = 0; i < N; i++)
    {
        std::cout << vec[i] << " ";

        if((i+1)%10 == 0)
        {
            std::cout << std::endl;
        }
    }


    std::vector<int> sorted_vec = merge_sort<int>(vec);


    
    std::cout << std::endl << "[after sort]" << std::endl;

    for(int i = 0; i < N; i++)
    {
        std::cout << sorted_vec[i] << " ";

        if((i+1)%10 == 0)
        {
            std::cout << std::endl;
        }
    }

}