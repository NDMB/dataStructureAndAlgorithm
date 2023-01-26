// deque
// ����� que (double-ended queue)
// vector�� ����� �� �� ���� ������ �����ϴ� �Լ��� �ְ� ���Ϳ� ���������� ���ϴ� ��ġ�� �ѹ��� ���� ����

#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> deq = {1,2,3,4,5};

    deq.push_front(0); // �� �տ� ���� �߰�

    deq.push_back(6); // �� �ڿ� ���� �߰�

    deq.insert(deq.begin() + 2, 10); //  �� �տ��� 2 ���� ĭ�� 10 ����

    deq.pop_back(); // �� �� ���� ����

    deq.pop_front(); // �� �� ���� ����

    deq.erase(deq.begin() + 1); // �� �տ��� 1 ��° ĭ ���� ����

    deq.erase(deq.begin() + 3, deq.end()); // �� �տ��� 3 ��° ���Һ��� ������ ����
}