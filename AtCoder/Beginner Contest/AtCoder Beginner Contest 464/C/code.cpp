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

struct Bird {
  int a, d, b;
};

vector<int> solution(int size, int day, vector<Bird>& birds) {
  vector<vector<Bird>> changes(day);

  unordered_map<int, int> count;
  for (Bird& b : birds) {
    count[b.a]++;

    changes[b.d - 1].push_back(b);
  }

  vector<int> answer(day);

  for (int d = 0; d < day; d++) {
    for(Bird &b : changes[d]){
      count[b.a]--;
      if(count[b.a] == 0){
        count.erase(b.a);
      }

      count[b.b]++;
    }

    answer[d] = count.size();
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, M;
  cin >> N >> M;

  vector<Bird> birds(N);
  for (int i = 0; i < N; i++) {
    cin >> birds[i].a >> birds[i].d >> birds[i].b;
  }

  auto answer = solution(N, M, birds);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto &line : answer) {
    cout << line << "\n";
  }
  cout << endl;

  return 0;
}