#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

class Graph {
public:
    // �����������
    Graph(size_t n, const std::vector<std::string>& people);  // ���������� size_t

    // ���������� �����
    void addEdge(size_t u, size_t v);  // ���������� size_t

    // ����� ���� ��� ������, ����������� ���������� ����� �������� �� ����������� 3
    void findPairsWithinThreeSteps();

private:
    // ������ ���������
    std::vector<std::vector<int>> adjList;
    // ������ ���� �����
    std::vector<std::string> names;
};

#endif // GRAPH_H
