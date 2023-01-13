// 그래프를 사용한 예제
// 힌접 행렬로 그래프 표현하기

#include <iostream>
#include <vector>

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

    void addEdge(const city c1, const city c2, int dis) // 엣지 추가
    {
        std::cout << "Add edge: " << c2 << "-" << c2 << "=" << dis << std::endl;

        auto n1 = static_cast<int>(c1);
        auto n2 = static_cast<int>(c2);

        data[n1][n2] = dis;
        data[n2][n1] = dis;
    }

    void removeEdge(const city c1, const city c2) // 엑지 삭제
    {
        std::cout << "Remove edge: " << c1 << "-" << c2 << std::endl;

        auto n1 = static_cast<int>(c1);
        auto n2 = static_cast<int>(c2);

        data[n1][n2] = -1;
        data[n2][n1] = -1;
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

    return 0;
}