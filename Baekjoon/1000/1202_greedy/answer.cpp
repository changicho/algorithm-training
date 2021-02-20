#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Jewel {
  int weight;
  int value;

  bool operator<(const Jewel &b) const {
    return weight < b.weight;
  }
};

void solution() {
  int N, K;
  cin >> N >> K;

  vector<Jewel> jewels(N);
  vector<int> bags(K);

  for (int i = 0; i < N; i++) {
    cin >> jewels[i].weight >> jewels[i].value;
  }
  for (int i = 0; i < K; i++) {
    cin >> bags[i];
  }

  sort(jewels.begin(), jewels.end());
  sort(bags.begin(), bags.end());

  long long answer = 0;
  int jewel_index = 0;
  priority_queue<int> pq;

  for (int bag : bags) {
    while (jewel_index < N && jewels[jewel_index].weight <= bag) {
      pq.push(jewels[jewel_index].value);
      jewel_index++;
    }

    if (!pq.empty()) {
      answer += pq.top();
      pq.pop();
    }
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