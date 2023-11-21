#include <iostream>
#include <vector>
#include <cmath>
#include <random>

using namespace std;

int main() {
    // 랜덤 수를 생성할 범위
    int min = 0;
    int max = 100;

    // 랜덤 수를 저장할 벡터
    vector<int> numbers;

    // 랜덤 수 생성
    for (int i = 0; i < 100; i++) {
        numbers.push_back(rand() % (max - min + 1) + min);
    }

    // 벡터의 크기
    int size = numbers.size();

    // A 벡터
    vector<int> A;

    // B 벡터
    vector<int> B;

    // euclidean distance 계산
    for (int i = 0; i < size; i++) {
        int distance_a = sqrt((numbers[i] - 30) * (numbers[i] - 30));
        int distance_b = sqrt((numbers[i] - 70) * (numbers[i] - 70));

        // A 벡터에 추가
        if (distance_a <= 10) {
            A.push_back(numbers[i]);
        }

        // B 벡터에 추가
        if (distance_b <= 5) {
            B.push_back(numbers[i]);
        }
    }

    // A 벡터 출력
    cout << "A 벡터: ";
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    // B 벡터 출력
    cout << "B 벡터: ";
    for (int i = 0; i < B.size(); i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    return 0;
}