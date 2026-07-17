# E - Range Flip

[링크](https://atcoder.jp/contests/abc466/tasks/abc466_e)

| 난이도 |
| :----: |
|  450   |

## 설계

### 시간 복잡도

카드의 수를 N, 연산의 수를 K라 하자.

각 카드들을 순회하며 현재 뒤집었을 때 점수가 증가하는 곳이 있는지 탐색하는데 O(N)의 시간 복잡도를 사용한다.

이를 최대 K번 반복하며 이는 O(K \* N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 과정마다 앞면과 뒷면의 값의 diff를 사용하는데 O(N)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |  O(K \* N)  |    O(N)     |

정답이 다음과 같이 구간을 뒤집는다 가정하자.

`[A B [C] D E]`

이는 결과적으로 아래 구간을 두번 뒤집는것과 동일하다.

`[A B] C [D E]`

횟수 또한 2번으로 동일한다.

따라서 특정 구간마다 뒤집는게 유리한 경우 뒤집는 것을 K번 반복하면 정답이 생성된다.

```cpp
using ll = long long;
using pll = pair<ll, ll>;

bool check(int size, vector<pll>& cards) {
  vector<ll> diffs(size);
  vector<int> starts(size, 0);
  diffs[0] = cards[0].second - cards[0].first;

  for (int i = 1; i < size; i++) {
    ll diff = cards[i].second - cards[i].first;

    if (diffs[i - 1] < 0) {
      starts[i] = i;
      diffs[i] = diff;
    } else {
      starts[i] = starts[i - 1];
      diffs[i] = diffs[i - 1] + diff;
    }
  }

  long long beforeDiffSum = 0;
  int targetL = 0, targetR = -1;

  for (int i = 0; i < size; i++) {
    if (diffs[i] > beforeDiffSum) {
      beforeDiffSum = diffs[i];
      targetL = starts[i];
      targetR = i;
    }
  }

  if (targetR != -1) {
    for (int i = targetL; i <= targetR; i++) {
      swap(cards[i].first, cards[i].second);
    }

    return true;
  }
  return false;
}

ll solution(int size, vector<pll>& cards, int k) {
  ll answer = 0;

  for (pll& c : cards) {
    answer += c.first;
  }

  for (int i = 0; i < k; i++) {
    if (!check(size, cards)) break;

    ll newAnswer = 0;
    for (pll& c : cards) {
      newAnswer += c.first;
    }
    answer = newAnswer;
  }

  return answer;
}
```

## 고생한 점
