// grap

#include <iostream>
#include <vector>

struct graph
{
    std::vector<std::vector<int>> data;

    graph(int n) // 주어진 개수의 누드로 구성된 그래프를 구성하는 생성자를 추가
    {
        data.reserve(n);
        std::vector<int> row(n);
        std::fill(row.begin(), row.end(), -1);

        for (int i = 0; i < n; i++)
        {
            data.push_back(row);
        }
    }

    void addEdge(const int c1, const int c2, int dis) // 엣지 추가
    {
        std::cout << "Add edge: " << c2 << "-" << c2 << "=" << dis << std::endl;

        auto n1 = static_cast<int>(c1); // static_cast<바꾸려는 타입>(대상), compile 타임에 형변환에 대한 타입 오류를 잡아준다.
        auto n2 = static_cast<int>(c2);

        data[n1][n2] = dis;
        data[n2][n1] = dis;
    }

    void removeEdge(const int c1, const int c2) // 엑지 삭제
    {
        std::cout << "Remove edge: " << c1 << "-" << c2 << std::endl;

        auto n1 = static_cast<int>(c1);
        auto n2 = static_cast<int>(c2);

        data[n1][n2] = -1;
        data[n2][n1] = -1;
    }
};
