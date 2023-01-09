# 1833. Maximum Ice Cream Bars

[링크](https://leetcode.com/problems/maximum-ice-cream-bars/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 coins의 크기를 N이라 하자.

가장 큰 coin을 M이라 하자.

작은 coin부터 우선 선택할 경우 coins를 정렬해야 한다.

이 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

카운팅 정렬을 사용할 경우 정렬과 순회에 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용할 수 있다.

카운팅 정렬에 O(M)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     444      | O(N \* log_2(N)) |    O(1)     |

매번 가능한 작은 cost부터 선택하는 것이 최대 갯수를 선택할 수 있다.

따라서 정렬을 수행후 작은 cost부터 선택한다.

```cpp
int maxIceCream(vector<int>& costs, int coins) {
  sort(costs.begin(), costs.end());

  int count = 0;
  for (int& cost : costs) {
    if (cost <= coins) {
      count++;
      coins -= cost;
    }
  }
  return count;
}
```

### 카운팅 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     444      |  O(N + M)   |    O(M)     |

카운팅 정렬을 이용하고, 작은 값부터 선택해 coins에서 감소시킨다.

```cpp
int maxIceCream(vector<int>& costs, int coins) {
  int size = costs.size();
  int maximum = *max_element(costs.begin(), costs.end());

  vector<int> costsFrequency(maximum + 1);
  for (int& cost : costs) {
    costsFrequency[cost]++;
  }

  int answer = 0;
  for (int cost = 1; cost <= maximum && cost <= coins; ++cost) {
    if (costsFrequency[cost] == 0) continue;

    int count = min(costsFrequency[cost], coins / cost);
    coins -= cost * count;
    answer += count;
  }

  return answer;
}
```

## 고생한 점
