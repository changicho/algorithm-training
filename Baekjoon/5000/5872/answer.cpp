#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int solution(string s) {
  int diff = 0;

  int answer = 0;
  for (char &c : s) {
    if (c == '(') {
      diff += 1;

    } else {
      diff -= 1;
    }

    if (diff < 0) {
      diff = 1;
      answer++;
    }
  }

  if (diff > 0) {
    answer += diff / 2;
  }
  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("input.txt", "r", stdin);

  string S;
  cin >> S;

  int answer = solution(S);

  cout << answer << endl;

  return 0;
}