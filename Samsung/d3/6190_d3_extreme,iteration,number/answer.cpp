#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int check_danjo(int number) {
    if (number < 10) {
        return -1;
    }

    int temp = number / 10;
    int before = number % 10;

    while(temp !=0){
        if( temp % 10 > before){
            return -1;
        }
        before = temp % 10;
        temp /= 10;
    }
    return number;
}

void solution(int test_case) {
    int N;
    cin >> N;
    int arr[1000];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int temp;
    int max = -1;

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            temp = arr[i] * arr[j];
            if (temp < max) {
                continue;
            }

            int danjo = check_danjo(temp);

            if (danjo > max) {
                max = danjo;
            }
        }
    }

    cout << "#" << test_case << " " << max;
    cout << "\n";
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++) {
        solution(test_case);
    }

    return 0;
}