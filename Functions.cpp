#include <iostream>
#include <clocale>
using namespace std;
int i, j, n, m, matrix[100][100];
int element;
int masi[] = { 101 };
int masi2[] = { 102 };
int sum = 0;
bool stroka_is = false;
#include "Namespace.h"

//���� �������
void my_space::size_of_matrix() {
    setlocale(LC_ALL, "Rus");
    //������ ����������� �������
    cout << "������� ���������� ����� �������: ";
    cin >> n;
    cout << "������� ���������� �������� �������: ";
    cin >> m;

}
void my_space::Input() {
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
}

//�������� - ���� �� ������� �����
void my_space::Finding_a_simple() {
    bool is_simple = true;
    element = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            for (int k = 2; k <= matrix[i][j] - 1; k++) {
                if (matrix[i][j] % k == 0) {
                    is_simple = false;
                }
            }
            if (is_simple == true) {
                masi[element] = i;
                element += 1;
            }
            is_simple = true;
        }
    }
}

//�������� - ���� �� ������, ����� ��������� ������� ����� ����
void my_space::Zero_sum_of_elements() {
    element = 0;
    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = 0; j < m; j++) {
            sum += matrix[i][j];
        }
        if (sum == 0) {
            masi2[element] = i;
            element += 1;
        }
    }
}

//�������� - ���� �� ������, ��������� ������� ����� � ����� �������� ������� ����� ����
void my_space::Final_check() {
    for (i = 0; i < sizeof(masi); i++) {
        for (j = 0; j < sizeof(masi2); j++) {
            if (masi[i] == masi2[j]) {
                stroka_is = true;
            }
        }
    }
}

//����� ������
void my_space::Print() {
    if (stroka_is == false) {
        cout << "��� ������, ��������������� �������";
        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
                cout << matrix[i][j] << ' ';
            }
            cout << endl;
        }
    }
    else {
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                for (int k = 0; k < m; k++) {
                    int a;
                    if (matrix[j][i] > matrix[k][i]) {
                        a = matrix[j][i];
                        matrix[j][i] = matrix[k][i];
                        matrix[k][i] = a;
                    }
                }
            }
        }
        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
                cout << matrix[i][j] << ' ';
            }
            cout << endl;
        }
    }
}