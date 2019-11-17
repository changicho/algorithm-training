#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 피라미드 층수를 입력받아 시작점과 끝점을 출력해주는 함수
 * argumant : void
 * return : void
 * print : %lf %lf
 */
void solution() {
    long long int N;
    cin >> N;
    long long int first, second;

    first =  2 * N * N - 4 * N + 3;
    second = 2 * N * N - 1;

    cout << first << " " << second;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cout << "#" << i + 1 << " ";
        solution();
        cout << endl;
    }

    return 0;
}