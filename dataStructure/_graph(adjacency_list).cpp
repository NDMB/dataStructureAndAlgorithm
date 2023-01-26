// 인접 리스트로 그래프 표현하기
// 그래프에서는 N * N 의 행렬이 필요하지만(노드 개수의 제곱)
// 인접 리스트로 표현한 그래프는 에지 개수에 비례한 크기의 메모리를 사용한다.
// 즉, 메모리에 이득이 있음.

#include <iostream>
#include <vector>
#include <algorithm>

enum class city : int
{
    MOSCOE,
    LONDON,
    SEOUL,
    SEATTLE,
    DUBAI,
    SYDNEY
};

std::ostream& operator<<(std::ostream& os, const city c)
{
    switch(c)
    {
        case city::LONDON:
            os << "런던";
            return os;
        case city::MOSCOE:
            os << "모스크바";
            return os;
        case city::SEOUL:
            os << "서울";
            return os;
        case city::SEATTLE:
            os << "시애틀";
            return os;
        case city::DUBAI:
            os << "두바이";
            return os;
        case city::SYDNEY:
            os << "시드니";
            return os;
        default:
            return os;
    }
}


struct graph
{
    std::vector<std::vector<std::pair<int, int>>> data;

    graph(int n)
    {
        data = std::vector<std::vector<std::pair<int, int>>> (n, std::vector<std::pair<int, int>>());
    }

    void addEdge(const city c1, const city c2, int dis)
    {
        std::cout << "add edge: " << c2 << "-" << c2 << "=" << dis << std::endl;

        auto n1 = static_cast<int>(c1);
        auto n2 = static_cast<int>(c2);
        data[n1].push_back({n1, dis});
        data[n2].push_back({n1, dis});
    }

    void removeEdge(const city c1, const city c2)
    {
        std::cout << "remove edge" << c1 << "-" << c2 << std::endl;

        auto n1 = static_cast<int>(c1);
        auto n2 = static_cast<int>(c2);

        // std::remove_if를 이용한 제거함수 생성 (범위1, 범위2, 조건)
        std::remove_if(data[n1].begin(), data[n1].end(), [n2](const auto& pair){
            return pair.first == n2;
        });
        std::remove_if(data[n2].begin(), data[n2].end(), [n1](const auto& pair){
            return pair.first == n1;
        });

    }
};


int main()
{
    graph g(6);

    g.addEdge(city::LONDON, city::MOSCOE, 2500);
    g.addEdge(city::LONDON, city::SEOUL, 9000);
    g.addEdge(city::LONDON, city::DUBAI, 5500);
    g.addEdge(city::SEOUL, city::MOSCOE, 6600);
    g.addEdge(city::SEOUL, city::SEATTLE, 8000);
    g.addEdge(city::SEOUL, city::DUBAI, 7000);
    g.addEdge(city::SEOUL, city::SYDNEY, 8000);
    g.addEdge(city::SEATTLE, city::MOSCOE, 8400);
    g.addEdge(city::SEATTLE, city::SYDNEY, 12000);
    g.addEdge(city::DUBAI, city::SYDNEY, 12000);

    g.addEdge(city::SEATTLE, city::LONDON, 8000);
    g.removeEdge(city::SEATTLE, city::LONDON);
};