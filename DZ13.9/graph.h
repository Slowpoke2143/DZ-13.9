#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

class Graph {
public:
    // Конструктор
    Graph(size_t n, const std::vector<std::string>& people);  // Используем size_t

    // Добавление ребра
    void addEdge(size_t u, size_t v);  // Используем size_t

    // Поиск всех пар вершин, минимальное расстояние между которыми не превосходит 3
    void findPairsWithinThreeSteps();

private:
    // Список смежности
    std::vector<std::vector<int>> adjList;
    // Массив имен людей
    std::vector<std::string> names;
};

#endif // GRAPH_H
