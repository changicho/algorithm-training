#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Line {
  int from, to;
};

bool compare(Line a, Line b) { return a.from < b.from; }

void solution() {
  int answer = 0;
  int N;
  vector<Line> lines;

  cin >> N;

  for (int i = 0; i < N; i++) {
    Line line;
    cin >> line.from >> line.to;

    lines.push_back(line);
  }

  sort(lines.begin(), lines.end(), compare);

  vector<int> lis;
  lis.push_back(-1);

  for (int i = 0; i < N; i++) {
    int cur = lines[i].to;

    if (lis.back() < cur) {
      lis.push_back(cur);
      answer++;
    } else {
      auto it = lower_bound(lis.begin(), lis.end(), cur);
      *it = cur;
    }
  }

  answer = N - (lis.size() - 1);
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