// 반복자 무효화

#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::vector<int> vec = {1,2,3,4,5};

    auto v_it4 = vec.begin() + 4; // 벡터에서는 적절하지 않은 이터레이터

    vec.insert(vec.begin() + 2, 0); // v_it4은 다른곳을 가르킨다.

    std::list<int> lst = {1,2,3,4,5};

    auto l_it4 = next(lst.begin(), 4); // 5를 저장한 노드를 가리킴

    lst.insert(next(lst.begin(), 2), 0);

    std::cout << *l_it4; // 여전히 5를 가리킨다.
}