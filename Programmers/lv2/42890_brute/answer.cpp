#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> answers;

string translate(vector<bool> target) {
  string str = "";

  for (int i = 0; i < target.size(); i++) {
    if (target[i]) {
      str += "1";
    } else {
      str += "0";
    }
  }

  return str;
}

bool has_contain(string target) {
  // target이 1의 수가 더 많음
  for (string answer : answers) {
    bool flag = true;

    for (int i = 0; i < target.length(); i++) {
      if (answer[i] == '1' && target[i] == '0') {
        flag = false;
        break;
      }
    }

    if (flag) {
      return true;
    }
  }

  return false;
}

int solution(vector<vector<string>> relation) {
  int rows = relation.size();     // 줄 수
  int cols = relation[0].size();  // 종류 수

  for (int count = 1; count <= cols; count++) {
    vector<bool> bits(cols - count, false);

    for (int i = 0; i < count; i++) {
      bits.push_back(true);
    }

    // 모든 조건을 탐색
    do {
      vector<string> vs(rows, "");

      // 현재 비트가 유효하지 않은경우 continue;
      string bit_str = translate(bits);

      if (has_contain(bit_str)) continue;

      for (int col = 0; col < bits.size(); col++) {
        if (bits[col]) {
          for (int row = 0; row < vs.size(); row++) {
            vs[row] += "/";
            vs[row] += relation[row][col];
          }
        }
      }

      map<string, bool> m;

      for (string s : vs) {
        m[s] = true;
      }

      if (m.size() == rows) {
        answers.push_back(bit_str);
      }
    } while (next_permutation(bits.begin(), bits.end()));
  }

  return answers.size();
}

int main() {
  vector<vector<string>> relation = {
      {"100", "ryan", "music", "2"},    {"200", "apeach", "math", "2"},
      {"300", "tube", "computer", "3"}, {"400", "con", "computer", "4"},
      {"500", "muzi", "music", "3"},    {"600", "apeach", "music", "2"}};

  cout << solution(relation) << endl;

  return 0;
}