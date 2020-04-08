#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isNotPrime[1001] = {
    false,
};

void solution() {
  int N, number;
  int answer = 0;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> number;

    if (!isNotPrime[number]) {
      answer += 1;
    }
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  isNotPrime[1] = true;

  for (int i = 2; i < 1001; i++) {
    int temp = i * 2;

    while (temp < 1001) {
      isNotPrime[temp] = true;
      temp += i;
    }
  }

  solution();

  return 0;
}