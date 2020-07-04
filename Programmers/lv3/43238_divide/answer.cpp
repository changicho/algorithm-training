#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long calculPeople(long long totalTime, vector<int> &times) {
  long long sum = 0;

  for (int t : times) {
    sum += totalTime / (long long)t;
  }

  return sum;
}

long long solution(int n, vector<int> times) {
  long long answer = 1000000000000000000;

  long long start = 1, end = 0, mid;

  for (int time : times) {
    end = max(end, (long long)time);
  }
  end *= (long long)n;

  while (start <= end) {
    mid = (start + end) / 2;

    long long peoples = calculPeople(mid, times);

    // 대기 인원보다 현재 시간에서 검사할 수 있는 인원이 더 많으면
    if (n > peoples) {
      start = mid + 1;
    } else {
      answer = min(mid, answer);
      end = mid - 1;
    }
  }

  return answer;
}

struct TestCase {
  int n;
  vector<int> times;
  long long answer;
};

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<TestCase> testCases = {{6, {7, 10}, 28}};

  for (TestCase tc : testCases) {
    long long answer = solution(tc.n, tc.times);

    cout << tc.answer << " : " << answer << "\n";
  }
  return 0;
}