#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int answer = 0;
  int N, M;
  vector<int> crains;
  vector<int> boxes;

  cin >> N;
  crains.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> crains[i];
  }

  cin >> M;
  boxes.resize(M);
  for (int i = 0; i < M; i++) {
    cin >> boxes[i];
  }

  stable_sort(crains.begin(), crains.end(), greater<int>());
  stable_sort(boxes.begin(), boxes.end(), greater<int>());

  if (boxes.front() > crains.front()) {
    cout << "-1\n";
    return;
  }

  while (boxes.size()) {
    int crain_idx = 0;
    for (int box_idx = 0; box_idx < boxes.size(); box_idx++) {
      if (crain_idx == crains.size()) {
        break;
      }

      if (crains[crain_idx] >= boxes[box_idx]) {
        crain_idx += 1;
        boxes.erase(boxes.begin() + box_idx);
        box_idx -= 1;
      }
    }
    answer += 1;
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