// heap

#include <iostream>
#include <queue>
#include <vector>

int main()
{
    std::priority_queue<int> maxHeap; // 최대 힙 초기화
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // 최소 힙 초기화

    for (int i = 0; i < 10; i++)
    {
        maxHeap.push(i);
        minHeap.push(i);
    }

    std::cout << "Max Heap top: " << maxHeap.top() << std::endl;
    std::cout << "Min Heap top: " << minHeap.top() << std::endl;
}