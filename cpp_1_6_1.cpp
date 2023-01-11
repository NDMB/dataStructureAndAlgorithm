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
    std::cout << "가장 최근 우승자: " << *it << std::endl;

    it+=7;
    std::cout << "8년 전 우승자: " << *it << std::endl;

    advance(it, -3);
    std::cout << "그후 3년 뒤 우승자: " << *it << std::endl;

    std::forward_list<std::string> fwd(vec.begin(), vec.end());

    auto it1 = fwd.begin();
    std::cout << "가장 최근 우승자: " << *it1 << std::endl;

    advance(it1, 5); // std::forward_list는 순방향으로만 움직일 수 있음 advance(it1, -2)의 경우 에러!
    std::cout << "5년 전 우승자: " << *it1 << std::endl;
}
