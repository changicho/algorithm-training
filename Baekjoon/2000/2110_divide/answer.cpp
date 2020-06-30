#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> xs;

int setWifi(int distance) {
  int wifi_count = 1;
  int start = xs[0];

  for (int index = 1; index < xs.size(); index++) {
    if (distance <= xs[index] - start) {
      start = xs[index];
      wifi_count += 1;
    }
  }

  return wifi_count;
}

void solution() {
  int N, C, answer;
  cin >> N >> C;

  xs.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> xs[i];
  }

  sort(xs.begin(), xs.end());

  int start = 1, end = xs.back() - xs.front();
  while (start <= end) {
    int mid = (start + end) / 2;
    int count = setWifi(mid);

    if (count < C) {
      end = mid - 1;
    } else {
      answer = mid;
      start = mid + 1;
    }
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./data/input.txt", "r", stdin);
  solution();

  return 0;
}