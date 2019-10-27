#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numbers[1000001];

void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

void solution() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    // 제일 큰 수를 root로 올려 최대 힙을 만듬
    for (int i = 1; i < N; i++) {
        int current_index = i;

        do {
            int root = (current_index - 1) / 2;

            if (numbers[root] < numbers[current_index]) {
                swap(&numbers[root], &numbers[current_index]);
            }

            current_index = root;
        } while (current_index != 0);
    }

    // i를 순회하며 index = i 일때 값을 구해줌.
    // 크기를 줄이며 매번 최대 힙을 구성하므로, 반복문이 끝날 때는 오름차순으로 정렬된다.
    for (int i = N - 1; i >= 0; i--) {
        // 힙정렬을 수행하며 제일 큰 값인 0번째 값을
        // 각 단계의 맨 마지막과 swap
        swap(&numbers[0], &numbers[i]);

        int root = 0;
        int current_index = 1;

        do {
            current_index = 2 * root + 1;
            // 자식 중에 더 큰 값을 찾기
            if (current_index < i - 1 &&
                numbers[current_index] < numbers[current_index + 1]) {
                current_index++;
            }
            // 루트보다 자식이 크다면 교환
            if (current_index < i && numbers[root] < numbers[current_index]) {
                swap(&numbers[root], &numbers[current_index]);
            }

            root = current_index;
        } while (current_index < i);
    }

    for (int index = 0; index < N; index++) {
        cout << numbers[index] << "\n";
    }

    cout << "\n";
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solution();

    return 0;
}