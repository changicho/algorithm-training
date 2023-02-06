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

typedef long long ll;

struct Card {
  char key;
  ll len;
};

vector<Card> solution(ll a, ll b, ll c, ll d, int k, vector<Card> &cards) {
  // 0:a, 1:b, 2:c, 3:d;
  ll prefixSum[4] = {a, b, c, d};
  priority_queue<ll> pq[4];

  for (Card &c : cards) {
    pq[c.key - 'A'].push(c.len);
  }

  vector<Card> answer;
  while (k--) {
    vector<Card> temp;
    for (int i = 0; i < 4; i++) {
      if (pq[i].empty()) continue;
      temp.push_back({char(i + 'A'), pq[i].top()});
    }

    sort(temp.begin(), temp.end(), [&](Card &a, Card &b) {
      return (a.len + prefixSum[a.key - 'A']) * prefixSum[b.key - 'A'] >
             (b.len + prefixSum[b.key - 'A']) * prefixSum[a.key - 'A'];
    });

    Card card = temp.front();
    pq[card.key - 'A'].pop();
    prefixSum[card.key - 'A'] += card.len;

    answer.push_back(card);
  }

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

  int N, K;
  cin >> N >> K;
  long long A, B, C, D;
  cin >> A >> B >> C >> D;

  vector<Card> cards(N);
  for (int i = 0; i < N; i++) {
    cin >> cards[i].key >> cards[i].len;
  }

  vector<Card> answer = solution(A, B, C, D, K, cards);

  for (Card &c : answer) {
    cout << c.key << " " << c.len << "\n";
  }

  return 0;
}
