#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, v, used[101]; // ���� ������� (n), ������� ���� �� ��������� (v), ����� �� ��������� �� ���������� �������
vector<int> a[101];  // ������ �� ���������, ���������� ���� �������� ����� ���� �������

// ������� �� ���������� ����� ������� (DFS) �� ���� k
void dfs(int k) {
	// ��������� �� ������� ����
	printf("%d ", k);

	// ��������� �� ������ ������ �� ������� ����
	for (int i = 0; i < a[k].size(); i++) {
		// ��� ��������� ���� ���� � �������, ���������� ��
		if (used[a[k][i]]) continue;

		// ��������� ����� ���� �������
		used[a[k][i]] = 1;
		// ���������� ��������� �������� ����
		dfs(a[k][i]);
	}
}

int main() {
	// ��������� �� ���� ������� � �������� ���� �� ���������
	cout << "Enter the number of vertices and the starting vertex:" << endl;
	scanf("%d %d", &n, &v); // ���� ������� (n) � ������� ���� (v)

	int b, c; // ������� (b) � ����� (c) ���� �� �����

	cout << "Enter edges (enter '0 0' to stop):" << endl;
	// ��������� �� �������� �� �����
	while (true) {
		scanf("%d %d", &b, &c);
		// ������� ��� ��������� �� 0 0 (������� �� ���� �� �����������)
		if (b == 0 && c == 0) break;

		// �������� �� �������� ��� ������� �� ���������
		// ��� ���� ������ � ������������, �������� �������� ����������
		a[b].push_back(c);
		a[c].push_back(b);
	}

	// ��������� �� �������� �� ����� ���� ��� �������� ���
	// ���� ��������� ��������� �� ��������� � ��������� ���
	for (int i = 0; i < n; i++) {
		sort(a[i].begin(), a[i].end());
	}

	// ��������� �������� ���� ���� �������
	used[v] = 1;
	// ��������� ����������� ���� DFS �� �������� ����
	dfs(v);

	return 0;
}