#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long answers[10];

void counting(int number, int count) {
  while (number != 0) {
    answers[number % 10] += count;
    number /= 10;
  }
}

void addAll(int diff) {
  for (int i = 0; i < 10; i++) {
    answers[i] += diff;
  }
}

void recur(int start, int end, int digits) {
  while (start % 10 != 0 && start <= end) {
    counting(start, digits);
    start++;
  }

  if (start > end) return;
  while (end % 10 != 9 && end >= start) {
    counting(end, digits);
    end--;
  }

  int diff = (end / 10 - start / 10 + 1);
  addAll(diff * digits);

  recur(start / 10, end / 10, digits * 10);
}

void solution() {
  int N;
  cin >> N;

  recur(1, N, 1);

  for (long long ans : answers) {
    cout << ans << " ";
  }
  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}