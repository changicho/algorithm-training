#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int table[8002];
int numbers[500000];

int compare(const void *a, const void *b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2) return -1;

    if (num1 > num2) return 1;

    return 0;
}

void solution() {
    int N;
    cin >> N;
    int min = 4000, max = -4000;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;

        // 산술평균을 구하기 위해 저장
        sum += temp;

        // 중앙값을 구하기 위한 배열에 할당.
        numbers[i] = temp;

        // 최빈값을 구하기 위한 table의 카운트
        table[temp + 4000]++;

        // 범위를 구하기 위한 최대, 최소값 갱신
        if (temp > max) {
            max = temp;
        }
        if (temp < min) {
            min = temp;
        }
    }

    long long avg = round((double)sum / (double)N);
    qsort(numbers, N, sizeof(int), compare);

    int mode = 0;
    int max_mod = 0;

    for (int i = 0; i < 8001; i++) {
        if (max_mod < table[i]) {
            max_mod = table[i];
            mode = i - 4000;
        }
    }

    int count = 0;
    for (int i = 0; i < 8001; i++) {
        if (max_mod == table[i]) {
            count++;
        }
        if (count == 2) {
            mode = i - 4000;
            break;
        }
    }

    cout << avg << "\n";
    cout << numbers[N / 2] << "\n";
    cout << mode << "\n";
    cout << max - min << "\n";
    cout << "\n";
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solution();

    return 0;
}