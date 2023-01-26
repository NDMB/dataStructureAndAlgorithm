// 체이닝을 사용하는 해시 테이블

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

    // 필요한 경우 이미 값이 있는지 확인하는 조건문을 넣는다.
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
        return std::find(entries.begin(), entries.end(), value) != entries.end(); // 엔트리에서 원하는 값을 찾는 코드
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

    // 람다 함수 캡처
    // [=] : 값에 의한 캡처 (call by val)
    // [&] : 참조에 의한 캡처 (call by ref)
    // [localVar] : 특정 변수값에 의한 캡처
    // [&localVar] : 특정 변수를 레퍼런스에 의한 캡처
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