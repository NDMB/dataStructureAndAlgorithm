// ���� ���� �����ϴ� ������ ����
// �ؽ� �Լ� : val % hasp size
// �ؽ� Ű ���� ������ �浹(collision)�� �߻���. ������ ������.

#include <iostream>
#include <vector>

using unit = unsigned int;

class hash_map
{
    std::vector<int> data;

public:
    hash_map(size_t n)
    {
        data = std::vector<int>(n, -1);
    }

    void insert(unit value)
    {
        int n = data.size();
        data[value % n] = value;
        std::cout << "insert " << value << " is success" << std::endl;
    }

    bool find(unit value)
    {
        int n = data.size();
        return (data[value % n] == value);
    }

    void erase(unit value)
    {
        int n = data.size();
        if (data[value % n] == value)
        {
            data[value % n] = -1;
            std::cout << "value: " << value << " is succesfully deleted." << std::endl;
        }
    }
};

int main()
{
    hash_map map(7);

    auto print = [&](int value) {
        if (map.find(value))
            std::cout << "value: " << value << " is in the hash map.";
        else
            std::cout << "value: " << value << " is not in the hash map.";
        std::cout << std::endl;
    };

    map.insert(2);
    map.insert(25);
    map.insert(10);
    print(25);

    map.insert(100);
    print(100);
    print(2);

    map.erase(25);
}