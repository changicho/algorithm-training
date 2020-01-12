#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> trees;

long long calcul(int height) {
  long long answer = 0;

  for (int i = 0; i < trees.size(); i += 1) {
    if (trees[i] > height) {
      answer += trees[i] - height;
    }
  }

  return answer;
}

void solution() {
  int N, M;
  int start = 0, end = 0, mid;  // using at binary search
  int temp;
  int answer = 0;
  long long answer_length = -1;

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> temp;
    trees.push_back(temp);

    if (end < trees[i]) end = trees[i];
  }

  start = 0;

  while (end - start >= 0) {
    mid = (start + end) / 2;
    long long current_length = calcul(mid);

    if (current_length >= M) {
      if (current_length < answer_length || answer_length == -1) {
        answer = mid;
        answer_length = current_length;
      }

      // backtracking
      if (answer_length - M == 0) {
        break;
      }
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  cout << answer << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}