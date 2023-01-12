// list
// doubly linked list�̴�.
// ��忡 ���� ���, ���� ����� �ּҰ� ���� �Ǿ� �ִ�.

#include <iostream>
#include <list>

int main()
{
    std::list<int> list1 = {1,2,3,4,5}; // ����Ʈ �ʱ�ȭ

    list1.push_back(6); // �� �ڿ� ���� �߰�

    list1.insert(next(list1.begin()), 0); // ���� ��ġ�� ���� ����

    list1.insert(list1.end(), 7);

    list1.pop_back(); // �� �� ���� ����

    std::cout << "���� & ���� �� ����Ʈ: ";
    for (auto i : list1)
    {
        std::cout << i << " ";
    }

    // �� �� remove(), remove_if(), sort(), unique(), revers() ���� �Լ��� foward_list�� �����ϰ� �۵�
}