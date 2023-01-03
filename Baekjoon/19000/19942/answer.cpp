#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAX = 1e9 + 1;

struct Food {
  int p, f, s, v, cost;
};

bool isFine(Food &cur, Food &need) {
  return cur.f >= need.f && cur.p >= need.p && cur.s >= need.s &&
         cur.v >= need.v;
}

int getTotalCost(vector<int> &choose, vector<Food> &foods) {
  if (choose.empty()) return INT_MAX;
  int cost = 0;
  for (int &i : choose) {
    cost += foods[i].cost;
  }
  return cost;
}

void recursive(int index, Food &need, vector<Food> &foods, Food cur,
               vector<int> &choose, vector<int> &answer) {
  int size = foods.size();

  if (index == size) {
    if (!isFine(cur, need)) return;

    int answerCost = getTotalCost(answer, foods);
    if (cur.cost == answerCost) {
      answer = min(answer, choose);
    } else if (cur.cost < answerCost) {
      answer = choose;
    }
    return;
  }
  // not choose
  recursive(index + 1, need, foods, cur, choose, answer);
  // choose
  cur.f += foods[index].f;
  cur.p += foods[index].p;
  cur.s += foods[index].s;
  cur.v += foods[index].v;
  cur.cost += foods[index].cost;
  choose.push_back(index);

  recursive(index + 1, need, foods, cur, choose, answer);
  choose.pop_back();
}

// use brute force
// time : O(N * 2^N)
// space : O(N)
vector<int> solution(Food &need, vector<Food> &foods) {
  int answerCost = 0;
  vector<int> answer;
  vector<int> choose;
  Food cur = {0, 0, 0, 0, 0};
  recursive(0, need, foods, cur, choose, answer);

  return answer;
}

void init() {}

void clear() {}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // // decimal point
  // cout << fixed;
  // cout.precision(8);

  init();

  // freopen("./input.txt", "r", stdin);

  clear();

  int N;
  cin >> N;

  vector<Food> foods(N);
  Food need;

  cin >> need.p >> need.f >> need.s >> need.v;

  for (int i = 0; i < N; i++) {
    cin >> foods[i].p >> foods[i].f >> foods[i].s >> foods[i].v >>
        foods[i].cost;
  }

  vector<int> answer = solution(need, foods);
  if (answer.empty()) {
    cout << "-1\n";
  } else {
    cout << getTotalCost(answer, foods) << "\n";
    for (int &i : answer) {
      cout << i + 1 << " ";
    }
    cout << "\n";
  }

  return 0;
}
