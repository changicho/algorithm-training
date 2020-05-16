#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long answers[10];

void counting(long long number, long long count) {
  while (number > 0) {
    answers[number % 10] += count;
    number /= 10;
  }
}

void addAll(long long diff) {
  for (int i = 0; i < 10; i++) {
    answers[i] += diff;
  }
}

void recur(long long start, long long end, long long digits) {
  while (start % 10 != 0 && start <= end) {
    counting(start, digits);
    start++;
  }

  if (start > end) return;
  while (end % 10 != 9 && end >= start) {
    counting(end, digits);
    end--;
  }

  long long cnt = (end / 10 - start / 10 + 1);
  addAll(cnt * digits);

  recur(start / 10, end / 10, digits * 10);
}

void solution(int test_case) {
  long long answer = 0;
  long long start, end;

  cin >> start >> end;

  if (start < 1) start = 1;
  recur(start, end, 1);

  for (long long i = 1; i < 10; i++) {
    answer += i * answers[i];
  }

  cout << "#" << test_case << " " << answer << "\n";
}

void init() { memset(answers, 0, sizeof(answers)); }

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int test_case = 1; test_case <= T; test_case++) {
    init();
    solution(test_case);
  }

  return 0;
}