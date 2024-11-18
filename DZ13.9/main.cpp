#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    // ����� �����
    vector<string> people = { "����", "������", "�����", "����", "����" };

    // �������������� ���� � 5 ��������� (������)
    Graph g(5, people);

    // ���������� ����� (������)
    g.addEdge(0, 1); // ���� - ������
    g.addEdge(1, 2); // ������ - �����
    g.addEdge(2, 3); // ����� - ����
    g.addEdge(3, 4); // ���� - ����

    // ���� ��� ���� � ����������� <= 3
    g.findPairsWithinThreeSteps();

    return 0;
}
