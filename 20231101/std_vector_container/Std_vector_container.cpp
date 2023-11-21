#include <iostream>
#include <vector>
#include <cmath>
#include <random>

using namespace std;

int main() {
    // ���� ���� ������ ����
    int min = 0;
    int max = 100;

    // ���� ���� ������ ����
    vector<int> numbers;

    // ���� �� ����
    for (int i = 0; i < 100; i++) {
        numbers.push_back(rand() % (max - min + 1) + min);
    }

    // ������ ũ��
    int size = numbers.size();

    // A ����
    vector<int> A;

    // B ����
    vector<int> B;

    // euclidean distance ���
    for (int i = 0; i < size; i++) {
        int distance_a = sqrt((numbers[i] - 30) * (numbers[i] - 30));
        int distance_b = sqrt((numbers[i] - 70) * (numbers[i] - 70));

        // A ���Ϳ� �߰�
        if (distance_a <= 10) {
            A.push_back(numbers[i]);
        }

        // B ���Ϳ� �߰�
        if (distance_b <= 5) {
            B.push_back(numbers[i]);
        }
    }

    // A ���� ���
    cout << "A ����: ";
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    // B ���� ���
    cout << "B ����: ";
    for (int i = 0; i < B.size(); i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    return 0;
}