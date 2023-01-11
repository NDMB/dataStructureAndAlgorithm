#include <iostream>
#include <forward_list>
#include <vector>

int main()
{
    std::vector<std::string> vec = {
        "Lewis Hamilton", "Lewis Hamilton", "Nico Roseberg",
        "Sebastian Vettel" "Lewis Haimlton", "Sebastian Vettel",
        "Sebastian Vettel", "Sabastian Vettel", "Fernando Alonso"
    };

    auto it = vec.begin();
    std::cout << "���� �ֱ� �����: " << *it << std::endl;

    it+=7;
    std::cout << "8�� �� �����: " << *it << std::endl;

    advance(it, -3);
    std::cout << "���� 3�� �� �����: " << *it << std::endl;

    std::forward_list<std::string> fwd(vec.begin(), vec.end());

    auto it1 = fwd.begin();
    std::cout << "���� �ֱ� �����: " << *it1 << std::endl;

    advance(it1, 5); // std::forward_list�� ���������θ� ������ �� ���� advance(it1, -2)�� ��� ����!
    std::cout << "5�� �� �����: " << *it1 << std::endl;
}
