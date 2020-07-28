#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
  int answer = 0;

  sort(people.begin(), people.end());

  int start = 0, end = people.size() - 1;

  while (start <= end) {
    if (start == end) {
      answer += 1;
      break;
    }
    if (people[start] + people[end] > limit) {
      end -= 1;

      answer += 1;
    } else {
      start += 1;
      end -= 1;

      answer += 1;
    }
  }

  return answer;
}

struct TestCase {
  vector<int> people;
  int limit;
  int answer;
};

int main() {
  vector<TestCase> tcs = {
      {{70, 50, 80, 50}, 100, 3},
      {{70, 80, 50}, 100, 3},
  };

  for (TestCase tc : tcs) {
    int answer = solution(tc.people, tc.limit);

    cout << answer << ", " << tc.answer << "\n";
  }

  return 0;
}