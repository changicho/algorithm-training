#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct picture {
  int number, count, time;
};

bool compare(picture a, picture b) {
  if (a.count > b.count) return true;

  if (a.count == b.count) {
    if (a.time > b.time) return true;
  }

  return false;
}

void solution() {
  int N, K, number;
  vector<picture> frame;
  cin >> N >> K;

  for (int i = 0; i < K; i++) {
    cin >> number;

    bool is_find = false;
    for (int index = 0; index < frame.size(); index++) {
      if (frame[index].number == number) {
        frame[index].count += 1;
        is_find = true;
        break;
      }
    }
    if (!is_find) {
      picture current;
      current.number = number;
      current.count = 1;
      current.time = i;

      if (frame.size() < N) {
        frame.push_back(current);
      } else {
        frame[frame.size() - 1] = current;
      }
    }

    sort(frame.begin(), frame.end(), compare);
  }

  vector<int> answer;
  for (picture p : frame) {
    answer.push_back(p.number);
  }
  sort(answer.begin(), answer.end());

  for (int i : answer) {
    cout << i << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}