#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N;
  int answer;
  int temp;

  cin >> N;

  vector<int> lis;
  lis.push_back(-1);

  for (int i = 0; i < N; i++) {
    cin >> temp;

    if (lis.back() < temp) {
      lis.push_back(temp);
    } else {
      auto it = lower_bound(lis.begin(), lis.end(), temp);
      *it = temp;
    }
  }

  answer = lis.size() - 1;
  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}