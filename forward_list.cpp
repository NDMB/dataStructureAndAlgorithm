//
// basic concept
//
#include <iostream>
#include <forward_list>

int main()
{
    std::forward_list<int> fwd_list = {1,2,3};

    fwd_list.push_front(0);

    auto it = fwd_list.begin(); // ù��° ������ �ּ�

    fwd_list.insert_after(it, 5); // it�� ������ 5�� ������ ��� �߰�

    fwd_list.insert_after(it, 6);

    fwd_list.pop_front(); // �� �� ���Ҹ� �����ϴ� �Լ�

    auto it1 = fwd_list.begin(); // it�� ���Ḯ��Ʈ�� ù���� ���Ҹ� ����Ű�� ������

    fwd_list.erase_after(it1); // it ���� ���� ����

    fwd_list.erase_after(it1, fwd_list.end()); // ó������ ������ ����

    std::forward_list<int> list1 = {23, 0, 1, -3, 34, 32};

    list1.sort(); // �������� ����
    for(auto &c : list1)
    {
        std::cout << c << ' ';
    }
    std::cout << std::endl;


    list1.sort(std::greater<int>()); // �������� ����
    for(auto &c : list1)
    {
        std::cout << c << ' ';
    }
    std::cout << std::endl;

    std::forward_list<int> list2 = {2,53,1,0,4,10};

    list2.reverse(); // ����Ʈ�� �Ųٷ�
    for(auto &c : list2)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    list2 = {0,1,0,1,-1,10,5,5,10,0};
    list2.unique();
    for (auto &c : list2)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    list2.sort(); // ����Ʈ ����
    list2.unique(); // ������ ���������� �ϳ��� ����
    for(auto c : list2)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    // Ư�� ���Ұ� �ٷ� �� ���Һ��� 2�̻� ũ�� ������ ����
    list2.unique([](int a, int b) 
    {
        return (b-a) < 2;
    });

    for (auto c : list2)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;
}