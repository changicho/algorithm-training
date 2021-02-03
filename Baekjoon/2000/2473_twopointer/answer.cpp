#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N;
  cin >> N;

  vector<long long> array(N);
  vector<long long> answers(3, 0);

  for (int i = 0; i < N; i++) {
    cin >> array[i];
  }

  sort(array.begin(), array.end());
  long long sum = abs(array[0] + array[1] + array[2]);
  answers[0] = array[0];
  answers[1] = array[1];
  answers[2] = array[2];

  for (int index = 0; index < N - 2; index += 1) {
    int front = index + 1, back = N - 1;

    while (front < back) {
      long long cur_sum = array[front] + array[back] + array[index];
      long long abs_cur = abs(cur_sum);

      if (abs_cur < sum) {
        sum = abs_cur;
        answers[0] = array[index];
        answers[1] = array[front];
        answers[2] = array[back];
      }

      if (cur_sum < 0) {
        front += 1;
      } else {
        back -= 1;
      }
    }
  }

  cout << answers[0] << " " << answers[1] << " " << answers[2] << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}