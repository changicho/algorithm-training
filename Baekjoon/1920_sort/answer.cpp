#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N, M, temp;
  vector<int> answers;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> temp;
    answers.push_back(temp);
  }

  sort(answers.begin(), answers.end());

  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> temp;

    if (temp > answers[answers.size() - 1]) {
      cout << "0\n";
      continue;
    }

    bool is_find = false;
    int start = 0;
    int end = answers.size() - 1;
    int mid;

    while (end - start >= 0) {
      mid = (start + end) / 2;

      if (answers[mid] == temp) {
        is_find = 1;
        break;
      } else if (answers[mid] > temp) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }

    if (is_find) {
      cout << "1\n";
    } else {
      cout << "0\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}