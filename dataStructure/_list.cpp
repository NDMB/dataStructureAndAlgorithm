// list
// doubly linked list이다.
// 노드에 이전 노드, 다음 노드의 주소가 저장 되어 있다.

#include <iostream>
#include <list>

int main()
{
    std::list<int> list1 = {1,2,3,4,5}; // 리스트 초기화

    list1.push_back(6); // 맨 뒤에 원소 추가

    list1.insert(next(list1.begin()), 0); // 지정 위치에 원소 삽입

    list1.insert(list1.end(), 7);

    list1.pop_back(); // 맨 뒤 원소 삭제

    std::cout << "삽입 & 삭제 후 리스트: ";
    for (auto i : list1)
    {
        std::cout << i << " ";
    }

    // 그 외 remove(), remove_if(), sort(), unique(), revers() 등의 함수도 foward_list와 동일하게 작동
}