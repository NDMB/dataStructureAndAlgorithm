// ü�̴��� ����ϴ� �ؽ� ���̺�

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using unit = unsigned int;

class hash_map
{
    std::vector<std::list<int>> data;

public:
    hash_map(size_t n)
    {
        data.resize(n);
    }

    // �ʿ��� ��� �̹� ���� �ִ��� Ȯ���ϴ� ���ǹ��� �ִ´�.
    void insert(unit value)
    {
        int n = data.size();
        data[value % n].push_back(value);
        std::cout << "value: " << value << " is saved." << std::endl;
    }

    bool find(unit value)
    {
        int n = data.size();
        auto entries = data[value % n];
        return std::find(entries.begin(), entries.end(), value) != entries.end(); // ��Ʈ������ ���ϴ� ���� ã�� �ڵ�
    }

    void erase(unit value)
    {
        int n = data.size();
        auto entries = data[value % n];
        auto iter = std::find(entries.begin(), entries.end(), value);

        if (iter != entries.end())
        {
            entries.erase(iter);
            std::cout << "value: " << value << " is deleted." << std::endl;
        }
    }
};

int main()
{
    hash_map map(7);

    // ���� �Լ� ĸó
    // [=] : ���� ���� ĸó (call by val)
    // [&] : ������ ���� ĸó (call by ref)
    // [localVar] : Ư�� �������� ���� ĸó
    // [&localVar] : Ư�� ������ ���۷����� ���� ĸó
    auto print = [&](int value) {
        if(map.find(value))
        {
            std::cout << "value: " << value << " is in the hash map.";
        }
        else
        {
            std::cout << "value: " << value << " is not in the hash map.";
        }
        std::cout << std::endl;
    };

    map.insert(2);
    map.insert(25);
    map.insert(10);

    map.insert(100);
    map.insert(55);

    print(100);
    print(2);

    map.erase(2);
}