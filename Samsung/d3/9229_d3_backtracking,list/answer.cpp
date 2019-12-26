#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solution(int test_case) {
  int answer = -1, N, M, weight, sum;
  cin >> N >> M;

  vector<int> weights;

  for (int i = 0; i < N; i += 1) {
    cin >> weight;
    if (weight >= M) {
      continue;
    }
    weights.push_back(weight);
  }

  sort(weights.begin(), weights.end());

  for (int i = 0; i < weights.size(); i++) {
    for (int j = i + 1; j < weights.size(); j++) {
      sum = weights[i] + weights[j];

      if (sum > M) {
        break;
      }
      answer = max(sum, answer);
    }
  }

  cout << "#" << test_case << " " << answer << "\n";
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