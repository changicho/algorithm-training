#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// time :
bool check(vector<int> &cards, vector<int> &toBe, int start, int k) {
  int size = cards.size();
  if (k == 0 && start != 0) {
    return false;
  }
  if (k == 1 && start == 0) {
    return false;
  }
  if (size == 2) {
    if (start == 1 && k % 2 == 1) {
      return true;
    }
    if (start == 0 && k % 2 == 0) {
      return true;
    }
    return false;
  }
  return true;
}

bool solution(int size, int k, vector<int> &cards, vector<int> &toBe) {
  for (int i = 0; i < size; i++) {
    toBe.push_back(toBe[i]);
  }

  // use KMP
  vector<int> patternIndexArr(size, 0);
  for (int curIdx = 1, patternIdx = 0; curIdx < size; curIdx++) {
    while (patternIdx > 0 && cards[curIdx] != cards[patternIdx]) {
      patternIdx = patternIndexArr[patternIdx - 1];
    }
    if (cards[curIdx] == cards[patternIdx]) {
      patternIdx++;
      patternIndexArr[curIdx] = patternIdx;
    }
  }

  vector<int> starts;
  for (int lineIdx = 0, patternIdx = 0; lineIdx < 2 * size; lineIdx++) {
    while (patternIdx > 0 && toBe[lineIdx] != cards[patternIdx]) {
      patternIdx = patternIndexArr[patternIdx - 1];
    }

    if (toBe[lineIdx] == cards[patternIdx]) {
      if (patternIdx == size - 1) {
        starts.push_back(lineIdx - size + 1);

        patternIdx = patternIndexArr[patternIdx];
      } else {
        patternIdx++;
      }
    }
  }

  // 1 ~ N-1
  for (int &start : starts) {
    if (start >= size) continue;
    bool ret = check(cards, toBe, start, k);

    if (!ret) continue;
    return true;
  }

  return false;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./consecutive_cuts_chapter_2_input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N, K;
    cin >> N >> K;

    vector<int> A(N), B(N);

    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
      cin >> B[i];
    }

    bool answer = solution(N, K, A, B);

    cout << "Case #" << testCase << ": ";
    cout << (answer ? "YES" : "NO") << "\n";
  }

  return 0;
}