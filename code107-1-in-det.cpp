#include <iostream>
using namespace std;

// ���������� �� ��������� �� ������� �� �������
struct plist {
	int i;          // ������������� ���� �� ��� int
	plist* next;    // �������� ��� ��������� ������� - ���������� ���������� �� �����������
};

// ����������� �� ��������� �� ������� � �������� �� ������
void insertBegin(plist*& l, int x) {
	plist* p = new plist;  // ��������� �� ��� �������. ��������� ����� �� "p", ����� � �������� ��� ������� �� �������.
	p->i = x;              // �������� �������� �� ��������������� ���� "i" �� ����� ������� ��� ���������� "x".
	p->next = l;           // ���������� "next" �� ����� ������� ��������� ��� ������ ����� �������, �.�. "l".
	l = p;                 // ������������ ��������� "l" �� ���� ��� ����� �������. ���� ������ ������� ����� �����.
}

// ��������� �� ������� ���� ����� ������� (l) � ������
void insertAfter(plist*& l, int x) {
	if (l == NULL) {
		insertBegin(l, x); // ��� �������� � ������, �������� ������� � ��������, ����������� insertBegin.
	} else {
		plist* p = new plist;  // ��������� ��� ������� - ��������� ����� �� "p", ����� � �������� ��� ����� �������.
		p->i = x;              // ����������� ���������� "x" �� ��������������� ���� �� ����� �������.
		p->next = l->next;     // ���������� "next" �� ����� ������� ��������� ��� ��������, ����� � ���� ������� (l->next).
		l->next = p;           // ��������� "next" �� ������� ������� (l) ��� ����� ������� (p), �� �� �� ������� � �������.
	}
}

// ��������� �� ������� ����� ����� ������� (l) � ������
void insertBefore(plist*& l, int x) {
	if (l == NULL) {
		insertBegin(l, x); // ��� �������� � ������, �������� ������� � ��������, ����������� insertBegin.
	} else {
		plist* p = new plist;  // ��������� ��� ������� - ��������� ����� �� "p".
		p->i = l->i;           // �������� �������� �������� �� �������� (l->i) � ����� ������� (p->i).
		p->next = l->next;     // ��������� ��������� "next" �� ����� ������� ��� ��������� ������� (l->next).
		l->i = x;              // ��������� ���������� �� ������� �������, ���� �� ����������� "x".
		l->next = p;           // ��������� "next" �� ������� ������� ��� ����� �������, �� �� �� ������� � �������.
	}
}

// ����������� �� ��������� �� ������� � ������ �������� �� ������
void deletel(plist*& l, int x) {
	plist* p = l;              // ���������� �������� "p", ����� ���� ��� ������� ������� (l).
	plist* q = NULL;           // ���������� �������� "q" �� ��������, ����� �� ������� (������������ �� ���� ������).

	// �������� ���� ������� ������� ������� ���������� "x"
	if (l != NULL && l->i == x) {
		l = l->next;           // ��� ��, ��������� "l" ��� ��������� �������.
		delete p;              // ������������� ������� �� ������ ������� (p).
	} else {
		// ������ �������� � �����, ������ �� ������� ��� ���� �� �������
		while (p->next != NULL && p->next->i != x) {
			p = p->next;       // ����������� ��� ��������� �������.
		}
		// ��� ������� ��������
		if (p->next != NULL) {
			q = p->next;       // ���������� "q" ���� ��� �������� �� ���������.
			p->next = p->next->next; // ���������� ���� �������.
			delete q;          // ������������� ������� �� �������� "q".
		}
	}
}

// ����������� �� ������� �� ������� � �������
plist* search(plist* l, int x) {
	while (l != NULL) {        // ��������� �������, ������ �� ������� ���� (NULL).
		if (l->i == x) {       // ����������� ���� �������� ������� ������� ��������� ��������.
			return l;          // ��� � �������, ������� �������� ��� ���� �������.
		}
		l = l->next;           // ����������� ��� ��������� �������.
	}
	return NULL;               // ��� �� ������� ��������, ������� NULL.
}

// ����������� �� ��������� � ����������� �� �������
void printl(plist* l) {
	while (l != NULL) {        // ������ ��� �������� � �������
		cout << l->i << endl;  // ����������� ���������� �� ������� �������
		l = l->next;           // ����������� ��� ��������� �������
	}
}

// ������ �������
int main() {
	int n, i, a;
	plist* list = NULL;        // �������������� ������ ������

	cout << "Enter the number of elements: "; // ��������� ���� �� ����������
	cin >> n;

	// �������� �������� � �������� �� �������
	for (i = 1; i <= n; i++) {
		cout << "Enter element " << i << ": "; // ��������� ���������� �� ������� �������
		cin >> a;
		insertBegin(list, a); // ��������� �������� � �������� �� �������
	}

	cout << "Enter the value to search: "; // ���������� �� �������� �� �������
	cin >> a;
	if (search(list, a) != NULL)            // ����������� ���� �������� ����������
		cout << "Yes" << endl;             // ��� � �������, ��������� "Yes"
	else
		cout << "No" << endl;              // ��� �� � �������, ��������� "No"

	cout << "List elements:" << endl;
	printl(list); // ����������� ������ �������� �� �������

	return 0;
}