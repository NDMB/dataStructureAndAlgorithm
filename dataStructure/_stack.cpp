// stack (Last In First Out)
// ������ ���: 
// empty(), size(), top(), push(), pop(), emplace()

#include <iostream>
#include <stack>
#include <vector>
#include <list>

int main()
{
    std::stack<int, std::vector<int>> stk; // �ַ� ����ϴ� stack
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