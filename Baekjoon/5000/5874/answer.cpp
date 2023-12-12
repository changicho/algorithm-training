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

long long solution(string s) {
  int size = s.size();

  vector<int> lefts;
  vector<int> rights;

  for (int i = 1; i < size; i++) {
    if (s[i] == '(' && s[i - 1] == '(') {
      lefts.push_back(i);
    }
  }
  for (int i = 0; i < size - 1; i++) {
    if (s[i] == ')' && s[i + 1] == ')') {
      rights.push_back(i);
    }
  }

  long long answer = 0;
  int rightI = 0;
  for (int leftI = 0; leftI < lefts.size(); leftI++) {
    while (rightI < rights.size() && rights[rightI] < lefts[leftI]) {
      rightI++;
    }

    long long rightCount = rights.size() - rightI;

    long long count = rightCount;
    answer += count;
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("input.txt", "r", stdin);

  string S;
  cin >> S;

  long long answer = solution(S);

  cout << answer << endl;

  return 0;
}