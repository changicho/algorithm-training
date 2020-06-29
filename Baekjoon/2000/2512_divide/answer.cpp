#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> arr;

int sumOfLimit(int limit) {
  int sum = 0;

  for (int budget : arr) {
    if (budget < limit) {
      sum += budget;
    } else {
      sum += limit;
    }
  }

  return sum;
}

void solution() {
  int N, M;
  int answer = 0;

  cin >> N;

  arr.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  cin >> M;

  sort(arr.begin(), arr.end());
  int end = arr.back() + 1, start = 0, mid;

  while (start + 1 < end) {
    mid = (start + end) / 2;

    int temp = sumOfLimit(mid);
    if (temp <= M) {
      start = mid;
    } else {
      end = mid;
    }
  }

  cout << start << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./data/input.txt", "r", stdin);
  solution();

  return 0;
}