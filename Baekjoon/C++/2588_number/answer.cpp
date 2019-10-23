#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
    int num1, num2;

    cin >> num1 >> num2;
    int multi = num1 * num2;

    while (num2 > 0) {
        cout << num1 * (num2 % 10) << "\n";
        num2 /= 10;
    }

    cout << multi << "\n";
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solution();

    return 0;
}