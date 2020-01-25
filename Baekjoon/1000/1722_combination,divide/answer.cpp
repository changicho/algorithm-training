#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long fact[21];

void solution() {
  int N, command;
  long long facto = 1;

  fact[1] = 1;
  for (int i = 2; i <= 20; i++) {
    fact[i] = i * fact[i - 1];
  }

  cin >> N;

  vector<int> nums;
  vector<bool> visited(N + 1, false);

  for (int i = 1; i <= N; i++) {
    nums.push_back(i);
  }

  cin >> command;

  if (command == 1) {
    long long target;
    cin >> target;

    vector<int> combi;

    for (int depth = 0; depth < N; depth++) {
      for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;

        if (target > fact[N - 1 - depth]) {
          target -= fact[N - 1 - depth];
        } else if (target < fact[N - depth]) {
          visited[i] = true;
          combi.push_back(i);

          break;
        }
      }
    }

    for (int i = 1; i <= N; i++) {
      if (!visited[i]) {
        combi.push_back(i);
        break;
      }
    }

    for (int i : combi) {
      cout << i << " ";
    }
    cout << "\n";

    return;
  } else if (command == 2) {
    vector<int> combi(N);

    for (int i = 0; i < N; i++) {
      cin >> combi[i];
    }

    long long count = 0;
    int choose_count = 0;

    for (int c : combi) {
      facto = fact[N - 1 - choose_count];

      for (int n : nums) {
        if (visited[n]) {
          continue;
        }

        if (n == c) {
          visited[n] = true;
          choose_count += 1;
          break;
        }
        count += facto;
      }
    }

    cout << count + 1 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}