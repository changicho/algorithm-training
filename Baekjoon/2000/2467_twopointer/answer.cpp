#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N;
  cin >> N;

  vector<int> array(N);

  for (int i = 0; i < N; i++) {
    cin >> array[i];
  }

  sort(array.begin(), array.end());
  int left = 0, right = N - 1;
  int diff = abs(array.back() + array.front());
  int answer_start = array.front(), answer_end = array.back();

  while (left < right) {
    int new_diff = array[left] + array[right];

    if (abs(new_diff) < diff) {
      diff = abs(new_diff);

      answer_start = array[left];
      answer_end = array[right];
    }

    if (new_diff < 0) {
      left++;
    } else {
      right--;
    }
  }

  cout << answer_start << " " << answer_end << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}