#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int getUniqueCount(vector<string> gems) {
  set<string> s;
  for (string gem : gems) {
    s.insert(gem);
  }

  return s.size();
}

vector<int> solution(vector<string> gems) {
  vector<int> answer = {1, (int)gems.size()};
  map<string, int> m;
  int totalCount = getUniqueCount(gems);

  for (string gem : gems) {
    m[gem] = 0;
  }

  int count = 0;
  int start = 0;
  int end = 0;

  m[gems[0]] = 1;
  count = 1;
  while (start <= end) {
    if (count < totalCount && end < gems.size() - 1) {
      end++;

      if (m[gems[end]] == 0) count++;
      m[gems[end]] += 1;
    } else {
      if (count == totalCount) {
        if ((end - start) < (answer[1] - answer[0])) {
          answer[0] = start + 1;
          answer[1] = end + 1;
        }
      }

      m[gems[start]] -= 1;
      if (m[gems[start]] == 0) count--;
      start++;
    }
  }

  return answer;
}

struct TestCase {
  vector<string> gems;
  vector<int> result;
};

int main() {
  vector<TestCase> tcs = {
      {{"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"},
       {3, 7}},
      {{"AA", "AB", "AC", "AA", "AC"}, {1, 3}},
      {{"XYZ", "XYZ", "XYZ"}, {1, 1}},
      {{"ZZZ", "YYY", "NNNN", "YYY", "BBB"}, {1, 5}}

  };

  for (TestCase tc : tcs) {
    vector<int> answer = solution(tc.gems);

    cout << "answer : "
         << "(" << tc.result[0] << "," << tc.result[1] << ")"
         << ", myAnswer : "
         << "(" << answer[0] << "," << answer[1] << ")"
         << "\n";
  }

  return 0;
}