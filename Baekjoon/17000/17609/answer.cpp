#include <algorithm>
#include <climits>
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

const int MAX = 1e9 + 1;

bool isPalindrome(string word) {
  int len = word.length();
  for (int i = 0; i < len / 2; i++) {
    if (word[i] != word[len - 1 - i]) {
      return false;
    }
  }
  return true;
}

int solution(string word) {
  int size = word.length();

  int left = 0, right = word.length() - 1;

  while (left < right) {
    if (word[left] != word[right]) {
      if (isPalindrome(word.substr(left + 1, right - left))) {
        return 1;
      }
      if (isPalindrome(word.substr(left, right - left))) {
        return 1;
      }
      return 2;
    }
    left++;
    right--;
  }

  return 0;
}

void init() {}

void clear() {}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // // decimal point
  // cout << fixed;
  // cout.precision(8);

  init();

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  vector<string> words(T);

  for (int i = 0; i < T; i++) {
    cin >> words[i];
  }

  for (int i = 0; i < T; i++) {
    int answer = solution(words[i]);
    cout << answer;
    cout << "\n";
  }

  return 0;
}
