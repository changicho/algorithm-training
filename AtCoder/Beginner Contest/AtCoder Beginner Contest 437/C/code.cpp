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

struct Reindeer {
  int w, p;
};

int solution(int size, vector<Reindeer>& reindeers) {
  sort(reindeers.begin(), reindeers.end(),
       [](const Reindeer& a, const Reindeer& b) {
         int diffA = a.p + a.w;
         int diffB = b.p + b.w;

         if (diffA == diffB) {
           return a.w < b.w;
         }
         return diffA < diffB;
       });

  long long totalPower = 0;
  long long totalWeight = 0;
  for (Reindeer& reindeer : reindeers) {
    totalPower += reindeer.p;
  }

  int answer = 0;
  for (int i = 0; i < size; i++) {
    Reindeer& reindeer = reindeers[i];
    totalPower -= reindeer.p;
    totalWeight += reindeer.w;

    if (totalPower < totalWeight) {
      totalPower += reindeer.p;
      totalWeight -= reindeer.w;
      continue;
    }
    answer++;
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int tc = 1; tc <= T; tc++) {
    int N;
    cin >> N;

    vector<Reindeer> reindeers(N);
    for (int i = 0; i < N; i++) {
      cin >> reindeers[i].w >> reindeers[i].p;
    }

    auto answer = solution(N, reindeers);

    cout << answer << endl;
    // cout << (answer ? "Yes" : "No") << endl;
    // for (auto &line : answer) {
    //   cout << line << "\n";
    // }
    // cout << endl;
  }

  return 0;
}