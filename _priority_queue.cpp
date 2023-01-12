// priority queue
// ���� ���Կ��� ���������� ���� ���ſ� ���ؼ��� �ּ�/�ִ� ���ҿ� ���ؼ��� ����
// �ּ�/�ִ� ���� �� �ϳ��� ���ؼ� ���ĵǾ� ����

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



