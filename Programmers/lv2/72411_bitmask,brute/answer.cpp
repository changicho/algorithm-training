#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Menu {
  string menu;
  int count;
};

bool compare(Menu a, Menu b) {
  return a.count > b.count;
}

vector<string> solution(vector<string> orders, vector<int> course) {
  vector<string> answer;
  int size = orders.size();
  int ALPHA_SIZE = 'z' - 'a' + 1;

  vector<int> table;
  for (string order : orders) {
    int bitMask = 0;

    for (char c : order) {
      bitMask |= 1 << (c - 'A');
    }

    table.push_back(bitMask);
  }

  vector<Menu> menus[11];
  for (int curCount : course) {
    vector<bool> visited(ALPHA_SIZE, false);
    for (int i = 0; i < curCount; i++) {
      visited[i] = true;
    }
    sort(visited.begin(), visited.end());

    do {
      int bitMask = 0;
      for (int i = 0; i < ALPHA_SIZE; i++) {
        if (visited[i]) {
          bitMask |= 1 << i;
        }
      }

      int count = 0;
      for (int order : table) {
        if ((bitMask & order) == bitMask) count += 1;
      }
      if (count < 2) continue;

      string menu = "";
      for (int i = 0; i < ALPHA_SIZE; i++) {
        if (visited[i]) {
          menu += (char)('A' + i);
        }
      }
      menus[curCount].push_back({menu, count});
    } while (next_permutation(visited.begin(), visited.end()));
  }

  for (int i = 1; i <= 10; i++) {
    if (menus[i].size() == 0) continue;
    sort(menus[i].begin(), menus[i].end(), compare);

    int count = menus[i].front().count;

    for (Menu cur : menus[i]) {
      if (cur.count == count) {
        answer.push_back(cur.menu);
      }
    }
  }

  sort(answer.begin(), answer.end());
  return answer;
}

struct TestCase {
  vector<string> orders;
  vector<int> course;
  vector<string> result;
};

string vectorToString(vector<string> v) {
  string ret = "(";
  for (string cur : v) {
    ret += cur + ", ";
  }
  int length = ret.length();
  ret.erase(length - 2, 2);
  return ret + ")";
}

int main() {
  vector<TestCase> tcs = {
      {{"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"}, {2, 3, 4}, {"AC", "ACDE", "BCFG", "CDE"}},
      {{"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"}, {2, 3, 5}, {"ACD", "AD", "ADE", "CD", "XYZ"}},
      {{"XYZ", "XWY", "WXA"}, {2, 3, 4}, {"WX", "XY"}},
  };

  for (TestCase tc : tcs) {
    string answer = vectorToString(solution(tc.orders, tc.course));
    string result = vectorToString(tc.result);

    char isCorrect = answer == result ? 'O' : 'X';

    cout << isCorrect << " "
         << "answer : " << result << ", myAnswer : " << answer << "\n";
  }

  return 0;
}
