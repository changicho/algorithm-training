#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool canDivide(string number, int m) {
	int temp = 0;

	for (int i = 0; i < number.length(); i++) {
		temp *= 10;
		temp += number[i]-'0';
		temp %= m;
	}
	return temp == 0;
}

void solution() { 
	int N;
	long long multi;

	while (cin >> N) {
		string ones = "1";

		while (true) {
			if (canDivide(ones, N)) {
				cout << ones.length() << "\n";
				break;
			}
			ones += "1";
		}
	}
	cout << "\n"; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}