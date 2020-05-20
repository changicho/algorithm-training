#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long answer;
int N, S;
vector<int> first;
vector<int> arr;

void make_part_first(int index, int sum) {
  if (index == N / 2) {
    first.push_back(sum);
    return;
  }

  make_part_first(index + 1, sum);
  make_part_first(index + 1, sum + arr[index]);
}

void make_part_second(int index, int sum) {
  if (index == N) {
    answer += upper_bound(first.begin(), first.end(), S - sum) -
              lower_bound(first.begin(), first.end(), S - sum);
    return;
  }

  make_part_second(index + 1, sum);
  make_part_second(index + 1, sum + arr[index]);
}

void solution() {
  cin >> N >> S;

  arr.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  make_part_first(0, 0);
  sort(first.begin(), first.end());
  make_part_second(N / 2, 0);

  if (S == 0) {
    answer -= 1;
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}