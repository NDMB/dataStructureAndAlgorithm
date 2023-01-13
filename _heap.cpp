// heap

#include <iostream>
#include <queue>
#include <vector>

int main()
{
    std::priority_queue<int> maxHeap; // �ִ� �� �ʱ�ȭ
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // �ּ� �� �ʱ�ȭ

    for (int i = 0; i < 10; i++)
    {
        maxHeap.push(i);
        minHeap.push(i);
    }

    std::cout << "Max Heap top: " << maxHeap.top() << std::endl;
    std::cout << "Min Heap top: " << minHeap.top() << std::endl;
}