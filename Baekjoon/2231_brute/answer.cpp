#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int divideSum(int n) {
    int sum = n;

    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void solution() {
    int N;
    cin >> N;
    int answer = 0;
    for (int i = 1; i < N; i++) {
        int temp = divideSum(i);

        if (temp == N) {
            answer = i;
            break;
        }
    }

    cout << answer;
    cout << "\n";
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solution();

    return 0;
}