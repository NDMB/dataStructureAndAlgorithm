// binary search example

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

bool linear_search(int N, std::vector<int>& s) // ���� �˻� �Լ�
{
    for (auto i : s)
    {
        if (N == i)
        {
            return true;
        }

        return false;
    }
}

bool binary_search(int N, std::vector<int>& s)
{
    auto first = s.begin();
    auto last = s.end();

    while(1)
    {
        // ���� �˻� ������ �߰� ���Ҹ� mid_element�� ����
        auto range_length = std::distance(first, last);
        auto mid_element_index = std::floor(range_length / 2);
        auto mid_element = *(first + mid_element_index);

        if (mid_element == N)
        {
            return true;
        } 
        else if (mid_element < N)
        {
            first = first + mid_element_index;
        }
        else
        {
            last = first + mid_element_index;
        }

        if(range_length == 1)
        {
            return false;
        }
    }
}

void run_large_search_test(int size, int N)
{
    std::vector<int> S;
    std::random_device rd;
    std::mt19937 rand(rd());

    // [1, size] �������� ���� ���� �߻�
    std::uniform_int_distribution<std::mt19937::result_type> uniform_dist(1, size);

    // S�� ���� �߰�
    for (auto i = 0; i < size; i++)
    {
        S.push_back(uniform_dist(rand));
    }

    std::sort(S.begin(), S.end());

    // �˻� �ð� ���� ����
    std::chrono::system_clock::time_point begin = std::chrono::system_clock::now();

    bool search_result = binary_search(N, S);

    std::chrono::system_clock::time_point end = std::chrono::system_clock::now();

    auto delay = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

    std::cout << "���� �˻� ���� �ð�: " << delay.count() << std::endl;

    if (search_result == true)
    {
        std::cout << "���Ҹ� ã�ҽ��ϴ�!" << std::endl;
    }
    else
    {
        std::cout << "���Ҹ� ã�� ���߽��ϴ�." << std::endl;
    }
}

int main()
{
    run_large_search_test(100000, 36543);
    run_large_search_test(1000000, 36543);
    run_large_search_test(10000000, 36543);

    return 0;
}

