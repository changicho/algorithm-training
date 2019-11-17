#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solution(int test_case) {
  int answer = 0;

  int N, K;
  cin >> N >> K;

  vector<int> scores(N);

  for (int i = 0; i < N; i++) {
    cin >> scores[i];
  }

  sort(scores.begin(), scores.end(), greater<int>());

  for (int i = 0; i < K; i++) {
    answer += scores[i];
  }

  cout << "#" << test_case << " " << answer << "\n";
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int test_case = 1; test_case <= T; test_case++) {
    solution(test_case);
  }

  return 0;
}