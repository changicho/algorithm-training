#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    vector<int> arr(7);
    vector<bool> check(7);
    vector<int> sum;
    for (int i = 0; i < 7; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < 3; i++) {
        check[i] = true;
    }
    sort(check.begin(), check.end());

    do {
        int temp = 0;
        for (int i = 0; i < 7; i++) {
            if (check[i]) {
                temp += arr[i];
            }
        }
        sum.push_back(temp);
    } while (next_permutation(check.begin(), check.end()));

    sort(sum.begin(), sum.end(), greater<int>());
    unique(sum.begin(), sum.end());

    cout << "#" << test_case << " " << sum[4];
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