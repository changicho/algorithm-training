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

void req(int start, int end, vector<int> arr) {
    if (start == end) {
        cout << arr[start] << " ";
        return;
    }

    int center = (end - start) / 2 + 1;
    cout << arr[center] << " ";
}

void solution(int test_case) {
    int K;
    cin >> K;

    int size = pow(2, K) - 1;
    int content = 0;
    int center;

    vector<int> arr(size);
    queue<part> Q;

    cout << "#" << test_case << " ";

    struct part init;
    struct part current;
    struct part temp;

    init.start = 0;
    init.end = size - 1;

    Q.push(init);

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    while (Q.size() != 0) {
        current = Q.front();
        Q.pop();

        if (current.start == current.end) {
            cout << arr[current.start] << " " << endl;
        } else {
            center = (current.end - current.start) / 2 + current.start;
            cout << arr[center] << " " << endl;

            temp.start = current.start;
            temp.end = center - 1;

            Q.push(temp);
            // cout<< "axis is " << center + 1 << " " << current.end << endl;
            temp.start = center + 1;
            temp.end = current.end;
            Q.push(temp);
        }
    }

    // 벡터의 메모리 초기화
    vector<int>().swap(arr);
}

int main() {
    int T;a-
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++) {
        solution(test_case);
    }

    return 0;
}