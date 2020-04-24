#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  if (a < b) {
    swap(a, b);
  }
  int temp;

  while (b != 0) {
    temp = a % b;
    a = b;
    b = temp;
  }

  return a;
}

void solution() {
  int N;

  cin >> N;
  vector<int> arr(N);
  vector<int> answer;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  vector<int> diff;
  for (int i = 1; i < N; i++) {
    diff.push_back(arr[i] - arr[i - 1]);
  }

  int pattern;
  if (diff.size() == 1) {
    pattern = diff[0];
  } else {
    pattern = gcd(diff[0], diff[1]);
    for (int num : diff) {
      pattern = gcd(pattern, num);
    }
  }

  for (int i = 2; i * i <= pattern; i++) {
    if (pattern % i == 0) {
      answer.push_back(i);
      answer.push_back(pattern / i);
    }
  }

  answer.push_back(pattern);
  sort(answer.begin(), answer.end());

  answer.erase(unique(answer.begin(), answer.end()), answer.end());

  for (int a : answer) {
    cout << a << " ";
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