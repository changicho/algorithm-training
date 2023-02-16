# 2561. Rearranging Fruits

[링크](https://leetcode.com/problems/rearranging-fruits/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

두 바구니 각각의 크기를 N이라 하자.

모든 경우를 선택할 경우 매우 많은 경우의 수가 나타나므로 제한시간 내에 불가능하다.

map을 이용해 변환해야 하는 값들을 추린 후, 이를 변경하며 cost를 구한다.

이 경우 map에 저장하는 데 구현 방법에 따라 최소 O(N), 이후 가장 작은 값들을 찾아 변경하는 데 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

hash map을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### map

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     247      | O(N \* log_2(N)) |    O(N)     |

각 바구니에서 같은 수가 존재하는 경우 이는 변경하지 않는 편이 유리하다.

각 수중에서 basket1에 있는 경우 +1, basket2에 있는 경우 -1로 카운트해 불균형한 경우의 수를 모두 count한다.

이후 각 불균형한 경우를 순회한다.

만약 불균형한 수가 홀수인 경우 이를 절반으로 나눠도 한쪽이 무조건 남으므로 균일하게 나눌 수 없다.

불균형한 수의 절반만 반대쪽으로 변경하면 되므로 절반을 변경해야 하는 목록에 추가한다.

이후 변경해야 하는 수 목록을 생성한 뒤에 수들을 둘로 나눈다.

이 변경해야 하는 수 목록에서 절반만 이동하면 되므로, 이 중 크기가 작은 절반 개를 이동시킨다.

이 때 직접 수를 이동하는 경우보다, 각 바구니에 있는 수중 가장 작은 값을 이용해 2번 이동하는 편이 cost가 싸므로 이를 계산해 유리한 경우만 이동시킨다.

- swap(A, B)의 경우 cost는 min(A,B)이다.
- swap(A, minimum) swap(minimum, B)의 경우 cost는 minimum의 2배이다.

이를 구현하면 다음과 같다.

```cpp
long long minCost(vector<int>& basket1, vector<int>& basket2) {
  int size = basket1.size();

  map<int, long long> counts;
  for (int& fruit : basket1) {
    counts[fruit]++;
  }
  for (int& fruit : basket2) {
    counts[fruit]--;
  }

  long long minimum = counts.begin()->first;  // minimum value to swap
  vector<long long> swaps;
  for (auto [fruit, count] : counts) {
    // check it can make all pair
    if (count % 2) return -1;

    for (int i = 0; i < abs(count) / 2; i++) {
      swaps.push_back(fruit);
    }
  }

  long long answer = 0;
  for (int i = 0; i < swaps.size() / 2; i++) {
    answer += min(swaps[i], minimum * 2);
  }
  return answer;
}
```

## 고생한 점
