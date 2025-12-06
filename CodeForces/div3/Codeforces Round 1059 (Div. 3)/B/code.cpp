#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

bool isIncreasing(string& s) {
  int size = s.size();
  if (size == 0) return true;

  for (int i = 1; i < size; i++) {
    if (s[i - 1] > s[i]) {
      return false;
    }
  }
  return true;
}

bool isPalindrome(string& s) {
  int size = s.size();
  if (size == 0) return true;

  for (int i = 0; i < size / 2; i++) {
    if (s[i] != s[size - 1 - i]) {
      return false;
    }
  }

  return true;
}

auto solution(int size, string& s) {
  vector<int> answer;

  for (int bit = 0; bit < (1 << size); bit++) {
    string p, remain;
    for (int i = 0; i < size; i++) {
      if (bit & (1 << i)) {
        p.push_back(s[i]);
      } else {
        remain.push_back(s[i]);
      }
    }

    if (isIncreasing(p) && isPalindrome(remain)) {
      for (int i = 0; i < size; i++) {
        if (bit & (1 << i)) {
          answer.push_back(i + 1);
        }
      }
      return answer;
    }
  }

  answer = {-1};

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N;

    string S;
    cin >> S;

    auto answer = solution(N, S);

    if (answer.size() == 1 && answer[0] == -1) {
      cout << -1 << endl;
      continue;
    }

    cout << answer.size() << endl;
    // cout << (answer ? "Yes" : "No") << endl;
    for (auto& line : answer) {
      cout << line << " ";
    }
    cout << endl;
  }

  return 0;
}