// ���� ����Ʈ�� �׷��� ǥ���ϱ�
// �׷��������� N * N �� ����� �ʿ�������(��� ������ ����)
// ���� ����Ʈ�� ǥ���� �׷����� ���� ������ ����� ũ���� �޸𸮸� ����Ѵ�.
// ��, �޸𸮿� �̵��� ����.

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
            os << "����";
            return os;
        case city::MOSCOE:
            os << "��ũ��";
            return os;
        case city::SEOUL:
            os << "����";
            return os;
        case city::SEATTLE:
            os << "�þ�Ʋ";
            return os;
        case city::DUBAI:
            os << "�ι���";
            return os;
        case city::SYDNEY:
            os << "�õ��";
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

        // std::remove_if�� �̿��� �����Լ� ���� (����1, ����2, ����)
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