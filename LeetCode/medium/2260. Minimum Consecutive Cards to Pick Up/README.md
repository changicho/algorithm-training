# 2260. Minimum Consecutive Cards to Pick Up

[링크](https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

cards의 크기를 N이라 하자.

각 index에서 left, right를 모두 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다.

이는 N이 최대 10^5 이므로 제한시간 내에 불가능하다.

hash map을 이용해 특정 값의 직전에 방문한 가장 마지막 index를 사용할 경우 O(N)의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

hash map을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     472      |    O(N)     |    O(N)     |

현재 방문한 숫자가 A일 때 특정 숫자 A에 대해서 minimum이 될 수 있는 조건은 아래와 같다.

- 직전에 방문한 A부터 현재까지의 거리

따라서 현재 방문을 수행하며, 같은 숫자일 때 이전에 나타난 위치중 가장 마지막 위치를 기억하면 된다.

각 index를 순회하며, 이전에 방문한 위치가 존재하는 경우 정답을 갱신하고 모든 경우에 각 값들의 마지막 위치를 갱신한다.

이를 구현하면 다음과 같다.

```cpp
int minimumCardPickup(vector<int>& cards) {
  int size = cards.size();
  unordered_map<int, int> lasts;

  int minimum = INT_MAX;

  for (int i = 0; i < size; i++) {
    int card = cards[i];

    if (lasts.count(card) > 0) {
      minimum = min(minimum, i - lasts[card] + 1);
    }

    lasts[card] = i;
  }

  return minimum == INT_MAX ? -1 : minimum;
}
```

## 고생한 점
