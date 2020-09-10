#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> transform(string line) {
  int from = 0;
  int to = 0;

  string hour = line.substr(11, 2);
  string minute = line.substr(14, 2);
  string second = line.substr(17, 6);

  to = stoi(hour) * 60 * 60 * 1000 + stoi(minute) * 60 * 1000 + stod(second) * 1000;

  string left = line.substr(24);
  string leftSecond = "";

  for (char c : left) {
    if (c >= '0' && c <= '9') {
      leftSecond += c;
    } else if (c == 's') {
      for (int i = leftSecond.length(); i < 4; i++) {
        leftSecond += "0";
      }
    }
  }
  from = to - stoi(leftSecond);

  return {from, to};
}

int solution(vector<string> lines) {
  int answer = 0;

  vector<int> starts;
  vector<int> ends;

  for (string line : lines) {
    vector<int> trans = transform(line);
    // cout << trans[0] << " ~ " << trans[1] << ", " << trans[1] - trans[0] << endl;

    starts.push_back(trans[0]);
    ends.push_back(trans[1]);
  }

  for (int index = 0; index < ends.size(); index++) {
    int from = ends[index];
    int to = from + 999;
    int count = 1;

    for (int j = index + 1; j < ends.size(); j++) {
      if (starts[j] < to) {
        count++;
      }
    }

    answer = max(answer, count);
  }

  return answer;
}

struct TestCase {
  vector<string> lines;
  int answer;
};

int main() {
  vector<TestCase> tcs = {
      {{"2016-09-15 01:00:04.001 2.0s",
        "2016-09-15 01:00:07.000 2s"},
       1},
      {{"2016-09-15 23:59:59.999 0.001s"}, 1},
      {{"2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s"}, 1},
      {{"2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"}, 2},
      {{"2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s", "2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s", "2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s", "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s", "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s"}, 7},
      {{"2016-09-15 00:00:00.000 2.3s", "2016-09-15 23:59:59.999 0.1s"}, 1}};

  for (TestCase tc : tcs) {
    int answer = solution(tc.lines);

    cout << "answer : " << tc.answer << ", myAnswer : " << answer << "\n";
  }

  return 0;
}