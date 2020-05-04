#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  long long answer;
  int K, N;
  long long min_wire = 0, max_wire = 0;

  cin >> K >> N;

  vector<long long> wires(K);

  for (int i = 0; i < K; i++) {
    cin >> wires[i];
    max_wire = max(max_wire, wires[i]);
  }
  max_wire += 1;

  while (min_wire + 1 < max_wire) {
    long long mid = (min_wire + max_wire) / 2;
    long long count = 0;

    for (long long wire : wires) {
      count += wire / mid;
    }

    if (count >= N) {
      min_wire = mid;
    } else {
      max_wire = mid;
    }
  }

  answer = min_wire;
  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}