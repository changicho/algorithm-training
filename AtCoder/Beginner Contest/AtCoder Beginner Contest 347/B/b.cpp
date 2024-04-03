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

int solution(string &s) {
  unordered_set<string> us;

  int size = s.size();

  for (int left = 0; left < size; left++) {
    string temp = "";
    for (int right = left; right < size; right++) {
      temp += s[right];
      us.insert(temp);
    }
  }

  return us.size();
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  string s;
  cin >> s;

  int answer = solution(s);

  cout << answer << endl;

  return 0;
}