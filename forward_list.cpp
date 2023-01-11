//
// basic concept
//
#include <iostream>
#include <forward_list>

int main()
{
    std::forward_list<int> fwd_list = {1,2,3};

    fwd_list.push_front(0);

    auto it = fwd_list.begin(); // 첫번째 원소의 주소

    fwd_list.insert_after(it, 5); // it의 다음에 5를 저장한 노드 추가

    fwd_list.insert_after(it, 6);

    fwd_list.pop_front(); // 맨 앞 원소를 삭제하는 함수

    auto it1 = fwd_list.begin(); // it은 연결리스트의 첫번쨰 원소를 가리키는 포인터

    fwd_list.erase_after(it1); // it 다음 원소 삭제

    fwd_list.erase_after(it1, fwd_list.end()); // 처음부터 끝까지 삭제

    std::forward_list<int> list1 = {23, 0, 1, -3, 34, 32};

    list1.sort(); // 오름차순 정렬
    for(auto &c : list1)
    {
        std::cout << c << ' ';
    }
    std::cout << std::endl;


    list1.sort(std::greater<int>()); // 내림차순 정렬
    for(auto &c : list1)
    {
        std::cout << c << ' ';
    }
    std::cout << std::endl;

    std::forward_list<int> list2 = {2,53,1,0,4,10};

    list2.reverse(); // 리스트를 거꾸로
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

    list2.sort(); // 리스트 정렬
    list2.unique(); // 인접한 같은원소중 하나만 리턴
    for(auto c : list2)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    // 특정 원소가 바로 앞 원소보다 2이상 크지 않으면 삭제
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