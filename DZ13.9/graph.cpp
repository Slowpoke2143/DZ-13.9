#include "graph.h"
#include <iostream>
#include <queue>

using namespace std;

Graph::Graph(size_t n, const vector<string>& people) {  // ���������� size_t
    adjList.resize(n);
    names = people;
}

void Graph::addEdge(size_t u, size_t v) {  // ���������� size_t
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void Graph::findPairsWithinThreeSteps() {
    size_t n = adjList.size();  // ���������� size_t

    // ������� �� ������ ������� � �������� BFS
    for (size_t start = 0; start < n; ++start) {  // ���������� size_t
        // ������ ��� �������� ����������
        vector<int> dist(n, -1);
        dist[start] = 0;

        queue<int> q;
        q.push(start);

        // BFS
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // ������� �� �������
            for (int neighbor : adjList[node]) {
                if (dist[neighbor] == -1) {  // ���� ��� �� �������� �������
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        // �������� ��� ���� � ����������� �� ����� 3
        for (size_t end = 0; end < n; ++end) {  // ���������� size_t
            if (start != end && dist[end] > 0 && dist[end] <= 3) {
                cout << "����: " << names[start] << " - " << names[end]
                    << " (����������: " << dist[end] << ")" << endl;
            }
        }
    }
}
