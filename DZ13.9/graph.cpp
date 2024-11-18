#include "graph.h"
#include <iostream>
#include <queue>

using namespace std;

Graph::Graph(size_t n, const vector<string>& people) {  // Используем size_t
    adjList.resize(n);
    names = people;
}

void Graph::addEdge(size_t u, size_t v) {  // Используем size_t
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void Graph::findPairsWithinThreeSteps() {
    size_t n = adjList.size();  // Используем size_t

    // Пройдем по каждой вершине и запустим BFS
    for (size_t start = 0; start < n; ++start) {  // Используем size_t
        // Массив для хранения расстояний
        vector<int> dist(n, -1);
        dist[start] = 0;

        queue<int> q;
        q.push(start);

        // BFS
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // Пройдем по соседям
            for (int neighbor : adjList[node]) {
                if (dist[neighbor] == -1) {  // Если еще не посещали вершину
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        // Печатаем все пары с расстоянием не более 3
        for (size_t end = 0; end < n; ++end) {  // Используем size_t
            if (start != end && dist[end] > 0 && dist[end] <= 3) {
                cout << "Пара: " << names[start] << " - " << names[end]
                    << " (расстояние: " << dist[end] << ")" << endl;
            }
        }
    }
}
