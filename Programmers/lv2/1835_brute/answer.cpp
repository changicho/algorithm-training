#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Case {
  char from;
  char to;
  char diff;
  int size;
};

bool isFine(vector<char> arr, Case cur) {
  int fromIdx, toIdx;

  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == cur.from) fromIdx = i;
    if (arr[i] == cur.to) toIdx = i;
  }

  switch (cur.diff) {
    case '=': {
      if (cur.size + 1 == abs(fromIdx - toIdx)) return true;
      return false;
    }
    case '>': {
      if (cur.size < abs(fromIdx - toIdx) - 1) return true;
      return false;
    }
    case '<': {
      if (cur.size > abs(fromIdx - toIdx) - 1) return true;
      return false;
    }
  }
  return false;
}

int solution(int n, vector<string> data) {
  int answer = 0;
  vector<char> arr = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
  vector<Case> cases;

  sort(arr.begin(), arr.end());

  for (string line : data) {
    Case cur;
    cur.from = line[0];
    cur.to = line[2];
    cur.diff = line[3];
    cur.size = line[4] - '0';

    cases.push_back(cur);
  }

  do {
    bool flag = true;
    for (Case cur : cases) {
      if (!flag) break;
      if (!isFine(arr, cur)) flag = false;
    }

    if (flag) answer += 1;

  } while (next_permutation(arr.begin(), arr.end()));

  return answer;
}

struct TestCase {
  int n;
  vector<string> data;
  int answer;
};

int main() {
  vector<TestCase> tcs = {
      {2, {"N~F=0", "R~T>2"}, 3648},
      {2, {"M~C<2", "C~M>1"}, 0},

  };

  for (TestCase tc : tcs) {
    int answer = solution(tc.n, tc.data);

    cout << "answer : " << tc.answer << ", myAnswer : " << answer << "\n";
  }

  return 0;
}