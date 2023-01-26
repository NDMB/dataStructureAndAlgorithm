// deque
// 양방향 que (double-ended queue)
// vector와 비슷함 앞 뒤 원소 접근을 지원하는 함수가 있고 벡터와 마찬가지로 원하는 위치로 한번에 접근 가능

#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> deq = {1,2,3,4,5};

    deq.push_front(0); // 맨 앞에 원소 추가

    deq.push_back(6); // 맨 뒤에 원소 추가

    deq.insert(deq.begin() + 2, 10); //  맨 앞에서 2 번쨰 칸에 10 삽입

    deq.pop_back(); // 맨 뒤 원소 삭제

    deq.pop_front(); // 맨 앞 원소 삭제

    deq.erase(deq.begin() + 1); // 맨 앞에서 1 번째 칸 원소 삭제

    deq.erase(deq.begin() + 3, deq.end()); // 맨 앞에서 3 번째 원소부터 끝까지 삭제
}