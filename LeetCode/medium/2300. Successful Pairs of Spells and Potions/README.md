# 2300. Successful Pairs of Spells and Potions

[링크](https://leetcode.com/problems/successful-pairs-of-spells-and-potions/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

spells의 크기를 N, potions의 크기를 M이라 하자.

매번 모든 potion에 spell을 곱하고 비교할 경우 O(N \* M)의 시간 복잡도를 사용한다.

이는 매우 크기 때문에 제한시간 내에 불가능하다.

potions을 정렬 하고 spell과 곱하지 않고 success와 spell로 나눈 값을 이용해 구할 수 있다.

이 경우 정렬에 O(M \* log_2(M))의 시간 복잡도를 사용한다.

이후 spell을 순회하며 이분탐색을 사용할 경우 O(N \* log_2(M))의 시간 복잡도를 사용한다.

따라서 최종 시간 복잡도는 O((N + M) \* log_2(M)) 이다.

### 공간 복잡도

정답 배열에 O(N)의 공간 복잡도를 사용한다.

기존에 입력받은 배열을 정렬하고, 이분 탐색에 O(1)의 공간 복잡도를 사용한다.

### 정렬 & 이분 탐색

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|     575      | O((N + M) \* log_2(M)) |    O(N)     |

potions을 오름차순으로 정렬한다.

이후 각 spell에 대해서 spells[i]와 potions[i]의 곱이 success를 넘어서는 갯수를 매번 찾지 않고, success / spell 값을 넘은 potion의 갯수를 센다.

이를 lower_bound를 이용해 찾고, 각 spell마다의 값을 배열에 담아 반환한다.

이를 구현하면 다음과 같다.

```cpp
vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
  int size = spells.size();
  vector<int> ret(size, 0);

  sort(potions.begin(), potions.end());

  for (int i = 0; i < size; i++) {
    int cur = spells[i];
    double target = (double)success / cur;

    int idx =
        lower_bound(potions.begin(), potions.end(), target) - potions.begin();

    ret[i] = potions.size() - idx;
  }
  return ret;
}
```

## 고생한 점
