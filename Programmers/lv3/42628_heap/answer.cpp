#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> operations) {
  vector<int> answer;

  map<long long, int> m;
  priority_queue<long long> max_pq;
  priority_queue<long long, vector<long long>, greater<long long>> min_pq;

  for (string operation : operations) {
    switch (operation[0]) {
      case 'I': {
        long long number = stoll(operation.substr(2));
        max_pq.push(number);
        min_pq.push(number);
        m[number] += 1;
        break;
      }
      case 'D': {
        if (operation == "D 1") {
          if (max_pq.empty()) break;

          long long target = max_pq.top();
          max_pq.pop();
          m[target] -= 1;

          break;
        } else {
          if (min_pq.empty()) break;

          long long target = min_pq.top();
          min_pq.pop();
          m[target] -= 1;

          break;
        }
      }
    }
    while (!max_pq.empty() && m[max_pq.top()] == 0) {
      max_pq.pop();
    }
    while (!min_pq.empty() && m[min_pq.top()] == 0) {
      min_pq.pop();
    }
    // cout << max_pq.size() << ", " << min_pq.size() << endl;
  }

  answer.push_back(max_pq.empty() ? 0 : max_pq.top());
  answer.push_back(min_pq.empty() ? 0 : min_pq.top());

  return answer;
}

struct TestCase {
  vector<string> operations;
  vector<int> answer;
};

string vectorToString(vector<int> v) {
  string ret = "(";
  for (int num : v) {
    ret += to_string(num) + ", ";
  }
  ret.erase(ret.length() - 2, 2);
  return ret + ")";
}

int main() {
  vector<TestCase> tcs = {
      {{"I 16", "D 1"}, {0, 0}},
      {{"I 7", "I 5", "I -5", "D -1"}, {7, 5}},
      {{"I 4", "I 3", "I 2", "I 1", "D 1", "D 1", "D -1", "D -1", "I 5", "I 6"}, {6, 5}}

  };

  for (TestCase tc : tcs) {
    vector<int> answer = solution(tc.operations);

    bool isCorrect = vectorToString(answer) == vectorToString(tc.answer);

    cout << isCorrect << " answer : " << vectorToString(tc.answer) << ", myAnswer : " << vectorToString(answer) << "\n";
  }

  return 0;
}