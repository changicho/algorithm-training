#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
  int answer = 0;
  int count = 0;
  int size = name.length();

  int opposite = name.length() - 1;

  for (int i = 0; i < name.length(); i++) {
    int up = name[i] - 'A';
    int down = 'Z' + 1 - name[i];

    count += min(up, down);

    int nextIndex = i + 1;
    while (nextIndex < size && name[nextIndex] == 'A') {
      nextIndex += 1;
    }

    // 전부 반대방향으로 이동했을 때의 최대 이동 횟수
    opposite = min(opposite, i + size - nextIndex + min(i, size - nextIndex));
  }
  count += opposite;

  return answer = count;
}

struct TestCase {
  string name;
  int answer;
};

int main() {
  vector<TestCase> tcs = {
      {"JEROEN", 56},
      {"JAN", 23}};

  for (TestCase tc : tcs) {
    int answer = solution(tc.name);

    cout << answer << ", " << tc.answer << "\n";
  }

  return 0;
}