#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

#define MAX 500000 + 1

using namespace std;

struct Line {
  int from, to;

  bool operator<(const Line &a) const {
    return from < a.from;
  }
};

struct LIS {
  int index, from;
};

vector<int> longestIncreasingSubsequence(int N, vector<Line> lines) {
  vector<LIS> lis;
  int line_cache[MAX] = {
      0,
  };
  int index = 0;

  line_cache[index] = lines[0].to;
  lis.push_back({0, lines[0].from});

  for (int i = 1; i < N; i++) {
    if (line_cache[index] < lines[i].to) {
      index++;
      line_cache[index] = lines[i].to;
      lis.push_back({index, lines[i].from});
    } else {
      int new_index = lower_bound(line_cache, line_cache + index, lines[i].to) - line_cache;

      line_cache[new_index] = lines[i].to;
      lis.push_back({new_index, lines[i].from});
    }
  }

  stack<int> s;
  for (int i = N - 1; i >= 0; i--) {
    if (lis[i].index == index) {
      s.push(lis[i].from);
      index--;
    }
  }

  vector<int> ret;
  while (!s.empty()) {
    ret.push_back(s.top());
    s.pop();
  }

  return ret;
}

void solution() {
  bool answers[MAX] = {
      0,
  };

  int N;
  cin >> N;

  vector<Line> lines(N);

  for (int i = 0; i < N; i++) {
    cin >> lines[i].from >> lines[i].to;

    answers[lines[i].from] = true;
  }

  sort(lines.begin(), lines.end());
  vector<int> lis = longestIncreasingSubsequence(N, lines);

  for (int node : lis) {
    answers[node] = false;
  }

  cout << N - lis.size() << endl;
  for (int index = 0; index < MAX; index++) {
    if (answers[index]) {
      cout << index << "\n";
    }
  }
  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}