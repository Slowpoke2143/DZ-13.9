#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    // Имена людей
    vector<string> people = { "Олег", "Никита", "Настя", "Ваня", "Женя" };

    // Инициализируем граф с 5 вершинами (людьми)
    Graph g(5, people);

    // Добавление ребер (дружбы)
    g.addEdge(0, 1); // Олег - Никита
    g.addEdge(1, 2); // Никита - Настя
    g.addEdge(2, 3); // Настя - Ваня
    g.addEdge(3, 4); // Ваня - Женя

    // Ищем все пары с расстоянием <= 3
    g.findPairsWithinThreeSteps();

    return 0;
}
