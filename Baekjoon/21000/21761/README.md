# 21761. 초직사각형

[링크](https://www.acmicpc.net/problem/21756)

| 정답률 (%) | 난이도 |
| :--------: | :----: |
|   28.239   | 골드 I |

## 설계

### 시간 복잡도

입력받은 카드의 수를 N, K라 하자.

각 카드중에서 뽑았을 때 현재 상황에서 부피의 크기를 최대한으로 늘릴 수 있는 카드만 뽑을 수 있다.

이 때 각 카드를 종류별로 구분한 뒤 거리를 가장 늘릴 수 있는 순으로 정렬해야 한다.

이 정렬에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 K번 카드를 뽑기 위해 순회하며 O(K)의 시간 복잡도를 사용한다.

카드를 뽑기 위해 순회하며 직전에 우선순위 큐를 사용한 경우 pop에 O(log_2(N))의 시간 복잡도를 사용한다.

이미 정렬된 배열을 사용할 경우 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 카드들을 정렬하기 위해 별도의 공간에 저장할 경우 O(N)의 공간 복잡도를 사용한다.

### 정렬 & 그리디

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|     112      | O((N + K) \* log_2(N)) |    O(N)     |

각 타입마다 해당 상황에서 유리한 카드를 뽑고 적용을 K번 반복한다.

이 때 해당 상황에서 각 카드별로 부피를 늘리는 비율을 계산한다.

부피를 다음과 같다고 하자

- A,B,C,D의 곱

여기서 새로운 부피를 구할 때 A가 갱신되어 A`라고 하자

- A`,B,C,D의 곱

여기서 부피가 늘어난 비율은 A`/A 만큼이다.

따라서 각 상황마다 4개의 카드 중 (4종류를 늘릴 수 있으므로) 선택할 수 있는 카드의 효율을 구할 수 있다.

```cpp
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
```

## 고생한 점
