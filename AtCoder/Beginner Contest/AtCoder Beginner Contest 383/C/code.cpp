#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Rank {
  string name;
  int score;
};

vector<string> solution(vector<int> &score) {
  vector<string> answer;

  vector<Rank> ranks;
  function<void(string &, int)> dfs = [&](string &name, int index) {
    if (index == 5) {
      if (name.size() == 0) return;
      int cur = 0;
      for (char &c : name) {
        cur += score[c - 'A'];
      }
      ranks.push_back({name, cur});
      return;
    }

    name += ('A' + index);
    dfs(name, index + 1);
    name.pop_back();
    dfs(name, index + 1);
  };

  string name = "";
  dfs(name, 0);

  sort(ranks.begin(), ranks.end(), [](Rank &a, Rank &b) {
    if (a.score == b.score) {
      return a.name < b.name;
    }
    return a.score > b.score;
  });

  for (Rank &r : ranks) {
    answer.push_back(r.name);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  vector<int> score(5);
  for (int i = 0; i < 5; i++) {
    cin >> score[i];
  }

  vector<string> answer = solution(score);

  // cout << (answer ? "Yes" : "No") << endl;
  for (auto &line : answer) {
    cout << line << "\n";
  }
  cout << endl;

  return 0;
}