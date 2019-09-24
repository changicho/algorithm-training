#include <math.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct part {
    int start;
    int end;
};

struct part make_part_struct(int start, int end) {
    struct part temp;
    temp.start = start;
    temp.end = end;

    return temp;
}

void solution(int test_case) {
    int K;
    cin >> K;

    int size = pow(2, K) - 1;
    int level_block_count = 0;
    int center, block_size = 1;

    vector<int> arr(size);
    queue<part> Q;

    struct part current;

    Q.push(make_part_struct(0, size - 1));

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "#" << test_case << " ";

    while (Q.size() != 0) {
        current = Q.front();
        Q.pop();

        if (current.start == current.end) {
            cout << arr[current.start];
        } else {
            center = (current.end - current.start) / 2 + current.start;
            cout << arr[center];

            Q.push(make_part_struct(current.start, center - 1));
            Q.push(make_part_struct(center + 1, current.end));
        }

        level_block_count++;
        
        if (level_block_count == block_size) {
            cout << endl;
            level_block_count = 0;
            block_size *= 2;
        } else {
            cout << " ";
        }
    }

    // 벡터의 메모리 초기화
    vector<int>().swap(arr);
}

int main() {
    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++) {
        solution(test_case);
    }

    return 0;
}