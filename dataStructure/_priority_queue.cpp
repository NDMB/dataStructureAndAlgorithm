// priority queue
// 원소 삽입에는 자유롭지만 원소 제거에 한해서는 최소/최대 원소에 대해서만 가능
// 최소/최대 원소 중 하나에 대해서 정렬되어 있음

#include <iostream>
#include <queue>
#include <vector>

int main()
{
    std::priority_queue<int, std::vector<int>> pq;

    for (int i = 0; i < 20; i++)
    {
        pq.push(i);
    }

    for (int i = 0; i < 7; i++)
    {
        pq.push(i);
    }

    for (int i = 0; i < 10; i++)
    {
        pq.push(i);
    }

    std::cout << pq.top();
}



