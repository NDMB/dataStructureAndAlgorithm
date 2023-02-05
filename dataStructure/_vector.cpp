// vector
// iterator가 순서적으로 되어 있다. (원하는 위치에 한번에 접근 가능)
// 원하는 위치에서 원소 수정 삽입 가능.

#include<vector>
#include<iostream>

int main()
{
    std::vector<int> vec = {1,2,3,4,5};

    vec.insert(vec.begin(), 0);

    std::vector<int> vec1;

    vec1.push_back(1);
    vec1.push_back(2);

    vec1.insert(vec1.begin(), 0);

    vec1.emplace_back(3);
    vec1.emplace_back(4);

    vec1.emplace(vec1.begin(), -1);

    for(int i = 0; i < vec1.size(); i++)
    {
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int> vec2 = {0,1,2,3,4,5,6,7,8,9};

    vec2.pop_back();

    vec2.erase(vec2.begin());

    vec2.erase(vec2.begin()+1, vec2.begin()+4);

    for(int i = 0; i < vec2.size(); i++)
    {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;

    vec2.clear();

    vec2.shrink_to_fit(); // 벡터 크기에 맞추어 용량 줄임

    vec1.emplace_back(1); // 벡터의 자료형에 맞게 객체 생성후 삽입.
}