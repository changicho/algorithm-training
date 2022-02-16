# 1648. Sell Diminishing-Valued Colored Balls

[링크](https://leetcode.com/problems/sell-diminishing-valued-colored-balls/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

inventory의 크기를 N이라 하자.

우선순위가 높은 색 부터 고르는 쪽이 더 유리하므로 우선순위에 따라 정렬을 수행해야 한다.

정렬에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 우선순위가 높은 순서대로 매번 수행할 경우 orders의 크기만큼의 시간 복잡도를 사용한다. 이 값이 너무 크므로 제한시간 내에 불가능하다.

따라서 inventory를 순회하며 orders개 만큼 빠르게 고른다.

이 경우 순회에 시간 복잡도는 O(N)를 사용한다.

따라서 총 시간 복잡도는 O(N \* log_2(N))이다.

### 공간 복잡도

입력받은 inventory를 직접 정렬할 경우 별도의 배열을 사용하지 않는다.

따라서 공간 복잡도는 O(1)이다.

### 정렬 & 그리디

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     132      | O(N \* log_2(N)) |    O(1)     |

수가 많은 색이 가치가 높으므로 가치가 높은 (많은) 순으로 정렬한다.

정렬된 inventory를 순회하며 고를 수 있을만큼 고른다.

이 때 다음과 같이 정렬되어있다고 가정하자.

```javascript
[a, b, c, ...]; // a >= b >= c
```

여기서 최대 a를 (a - b)개만큼 골랐을 때 이익을 최대로 할 수 있다.

이는 a를 (a - b)개 이상으로 고를 경우 b를 고르는 경우와 이익이 같기 때문이다.

따라서 a에서 해당 갯수만큼 고른 뒤 다음에 b를 고를 때는 a에서 같은 수를 고를 수 있다.

따라서 지나온 원소만큼 같은 수를 더 고를 수 있으므로 이를 고려해 orders개까지 공을 고른다.

이 때 현재 고를 수 있는 공의 갯수는 다음 중 작은 값이다.

- (orders / colors) : 현재 색을 모두 다 고르지 못하는 경우
- (a - b)

a ~ (a - b)까지 합을 구하기 위해 다음 공식을 사용해 O(1)의 시간 복잡도로 구한다.

```cpp
int sumZeroToN(int n) {
  return n * (n + 1) / 2;
}
```

이를 이용해 구현하면 다음과 같다.

```cpp
int maxProfit(vector<int>& inventory, int orders) {
  int size = inventory.size();
  // O(N * log_2(N))
  sort(begin(inventory), end(inventory), greater<int>());
  inventory.push_back(0);  // push end value

  long answer = 0, colors = 1;

  // O(N)
  for (int i = 0; i < size && orders > 0; i++, colors++) {
    long cur = inventory[i];
    long next = inventory[i + 1];

    bool isLast = (orders / colors) < (cur - next);
    long count = isLast ? (orders / colors) : (cur - next);

    orders -= count * colors;

    long rightPart = cur * (cur + 1) / 2;
    long leftPart = (cur - count) * (cur - count + 1) / 2;

    answer += (rightPart - leftPart) * colors;
    answer %= MOD;

    if (isLast) {
      answer += orders * (cur - count);
      answer %= MOD;
      break;
    }
  }
  return answer;
}
```

## 고생한 점
