#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
  int score, max = 0;
  cin >> test_case;

  int scores[101] = {
      0,
  };

  for (int i = 0; i < 1000; i++) {
    cin >> score;
    scores[score]++;
  }

  for (int i = 0; i <= 100; i++) {
    if (scores[i] >= scores[max]) {
      max = i;
    }
  }

  cout << "#" << test_case << " " << max << "\n";
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