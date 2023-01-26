// grap

#include <iostream>
#include <vector>

struct graph
{
    std::vector<std::vector<int>> data;

    graph(int n) // �־��� ������ ����� ������ �׷����� �����ϴ� �����ڸ� �߰�
    {
        data.reserve(n);
        std::vector<int> row(n);
        std::fill(row.begin(), row.end(), -1);

        for (int i = 0; i < n; i++)
        {
            data.push_back(row);
        }
    }

    void addEdge(const int c1, const int c2, int dis) // ���� �߰�
    {
        std::cout << "Add edge: " << c2 << "-" << c2 << "=" << dis << std::endl;

        auto n1 = static_cast<int>(c1); // static_cast<�ٲٷ��� Ÿ��>(���), compile Ÿ�ӿ� ����ȯ�� ���� Ÿ�� ������ ����ش�.
        auto n2 = static_cast<int>(c2);

        data[n1][n2] = dis;
        data[n2][n1] = dis;
    }

    void removeEdge(const int c1, const int c2) // ���� ����
    {
        std::cout << "Remove edge: " << c1 << "-" << c2 << std::endl;

        auto n1 = static_cast<int>(c1);
        auto n2 = static_cast<int>(c2);

        data[n1][n2] = -1;
        data[n2][n1] = -1;
    }
};
