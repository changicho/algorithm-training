#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution() {
  int K;

  cin >> K;

  if (K == 0) return false;

  vector<int> arr(K);
  vector<bool> combi(K, true);

  for (int i = 0; i < K; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < 6; i++) {
    combi[i] = false;
  }

  do {
    for (int i = 0; i < K; i++) {
      if (!combi[i]) {
        cout << arr[i] << " ";
      }
    }

    cout << "\n";

  } while (next_permutation(combi.begin(), combi.end()));

  cout << "\n";
  return true;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true) {
    if (!solution()) break;
  }

  return 0;
}