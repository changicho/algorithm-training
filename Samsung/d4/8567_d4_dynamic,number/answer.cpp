#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countParams[100001] = {
    1,
};
int memoization[100001] = {
    1,
};

void set() {
  for (int i = 2; i <= 50000; i++) {
    for (int j = 2; i * j <= 100000; j++) {
      countParams[i * j]++;
    }
  }

  int maxCount = 0, number = 0;
  for (int i = 1; i <= 100000; i++) {
    if (countParams[i] >= maxCount) {
      maxCount = countParams[i];
      number = i;
    }
    memoization[i] = number;
  }
}

void solution(int test_case) {
  int answer;
  int N;

  cin >> N;

  cout << "#" << test_case << " " << memoization[N] << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  set();

  int T;
  cin >> T;

  for (int test_case = 1; test_case <= T; test_case++) {
    solution(test_case);
  }

  return 0;
}