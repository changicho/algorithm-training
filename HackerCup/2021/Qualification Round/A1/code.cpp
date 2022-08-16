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

unordered_set<char> vowels({'A', 'E', 'I', 'O', 'U'});

bool isVowel(char c) { return vowels.count(c) > 0; }

// time : 10min
int solution(string &s) {
  int length = s.length();
  unordered_map<char, int> counts;

  int vowelCount = 0;
  int consonantCount = 0;

  for (char &c : s) {
    counts[c]++;

    if (isVowel(c)) {
      vowelCount++;
    } else {
      consonantCount++;
    }
  }

  int answer = length * 2;
  for (char target = 'A'; target <= 'Z'; target++) {
    int curCost = 0;
    for (auto &it : counts) {
      char c = it.first;
      int count = it.second;

      if (c == target) continue;

      if (isVowel(c) && isVowel(target) || !isVowel(c) && !isVowel(target)) {
        curCost += count * 2;
      } else {
        curCost += count;
      }
    }

    answer = min(answer, curCost);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    string S;
    cin >> S;

    int answer = solution(S);

    cout << "Case #" << testCase << ": ";
    cout << answer << "\n";
  }

  return 0;
}