#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct number {
  int value, index;
};

void solution() {
  int N, L;

  cin >> N >> L;

  deque<number> dq;
  vector<int> arr;

  arr.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < N; i++) {
    if (!dq.empty() && dq.front().index < i - L + 1) {
      dq.pop_front();
    }

    // delete which value bigger than arr[i]
    while (!dq.empty() && dq.back().value > arr[i]) {
      dq.pop_back();
    }

    dq.push_back(number{arr[i], i});
    cout << dq.front().value << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}