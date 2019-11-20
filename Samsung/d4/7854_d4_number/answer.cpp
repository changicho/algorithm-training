#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
  int answer = 0;
  long long X;
  cin >> X;

  vector<long long> arr;

  long long decimal = 10;

  while (decimal <= X * 10) {
    for (int i = 2; i <= 10; i++) {
      long long mock = decimal / i;

      if (mock * i == decimal) {
        arr.push_back(mock);
      }
    }

    decimal *= 10;
  }

  sort(arr.begin(), arr.end());
  for (long long i : arr) {
    if (i > X) {
      break;
    }
    answer++;
  }

  cout << "#" << test_case << " ";
  cout << answer << "\n";
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