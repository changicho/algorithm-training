#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void solution() {
  string start;

  int K;
  int answer = 0;
  int count_K = 0;

  cin >> start >> K;
  int length = start.length();

  if (length == 1 || (length == 2 && start[1] == '0')) {
    cout << "-1\n";
    return;
  }

  queue<string> q;
  q.push(start);

  while (!q.empty() && count_K < K) {
    int cur_size = q.size();
    bool visited[1000001] = {false};

    for (int cs = 0; cs < cur_size; cs++) {
      string cur = q.front();
      q.pop();

      for (int from = 0; from < length; from++) {
        for (int to = from + 1; to < length; to++) {
          if (from == 0 && cur[to] == '0') continue;

          swap(cur[from], cur[to]);

          if (visited[stoi(cur)]) {
            swap(cur[from], cur[to]);
            continue;
          }

          if (count_K == K - 1) {
            answer = max(answer, stoi(cur));
          }
          q.push(cur);
          visited[stoi(cur)] = true;

          swap(cur[from], cur[to]);
        }
      }
    }

    count_K += 1;
  }

  if (count_K != K) {
    cout << "-1\n";
  } else {
    cout << answer << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}