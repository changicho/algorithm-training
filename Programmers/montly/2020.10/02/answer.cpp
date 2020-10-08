#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<int, int> counts;

struct Axis {
  int y, x;
};

void req(Axis start, Axis end, vector<vector<int>> &arr) {
  if (start.y == end.y - 1 && start.x == end.x - 1) {
    counts[arr[start.y][start.x]] += 1;
    return;
  }

  int target = arr[start.y][start.x];
  bool canCompose = true;

  for (int y = start.y; y < end.y; y++) {
    if (!canCompose) break;
    for (int x = start.x; x < end.x; x++) {
      if (arr[y][x] != target) {
        canCompose = false;
        break;
      }
    }
  }

  if (canCompose) {
    counts[target] += 1;
    return;
  }

  int diff = abs(end.y - start.y) / 2;

  req({start.y, start.x}, {start.y + diff, start.x + diff}, arr);
  req({start.y, start.x + diff}, {start.y + diff, start.x + diff * 2}, arr);
  req({start.y + diff, start.x}, {start.y + diff * 2, start.x + diff}, arr);
  req({start.y + diff, start.x + diff}, {end.y, end.x}, arr);
}

vector<int> solution(vector<vector<int>> arr) {
  vector<int> answer;

  int size = arr.size();

  req({0, 0}, {size, size}, arr);

  answer.push_back(counts[0]);
  answer.push_back(counts[1]);
  return answer;
}

struct TestCase {
  vector<vector<int>> arr;
  vector<int> answer;
};

string vectorToString(vector<int> v) {
  string ret = "(";
  for (int i : v) {
    ret += to_string(i) + ", ";
  }
  ret.erase(ret.length() - 2, 2);
  return ret + ")";
}

void init() {
  counts.clear();
}

int main() {
  vector<TestCase> tcs = {
      {{{1, 1, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 1}, {1, 1, 1, 1}}, {4, 9}},
      {{{1, 1, 1, 1, 1, 1, 1, 1}, {0, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 1, 1, 1, 1}, {0, 1, 0, 0, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 0, 1, 1, 1, 1}}, {10, 15}},

  };

  for (TestCase tc : tcs) {
    init();
    vector<int> answer = solution(tc.arr);

    bool isCorrect = vectorToString(answer) == vectorToString(tc.answer);
    cout << isCorrect << " answer : " << vectorToString(tc.answer) << ", myAnswer : " << vectorToString(answer) << "\n";
  }

  return 0;
}