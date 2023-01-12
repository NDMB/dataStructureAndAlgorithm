// stack (Last In First Out)
// 스택의 기능: 
// empty(), size(), top(), push(), pop(), emplace()

#include <iostream>
#include <stack>
#include <vector>
#include <list>

int main()
{
    std::stack<int, std::vector<int>> stk; // 주로 사용하는 stack
    // std::stack<int, std::list<int>> stk;

    for (int i = 0; i < 5; i++)
    {
        stk.push(i);
    }

    while(!stk.empty())
    {
        std::cout << stk.top() << " ";

        stk.pop();
    }

}