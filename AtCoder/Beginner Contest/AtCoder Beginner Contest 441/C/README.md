# C - Sake or Water

[링크](https://atcoder.jp/contests/abc441/tasks/abc441_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

액체의 수를 N이라 하자.

정렬을 이용해 가장 유리한 액체를 우선적으로 선택할 수 있도록 한다. 정렬에 O(N \* log_2(N))의 시간이 소요된다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      35      | O(N \* log_2(N)) |    O(N)     |

타카하시가 A개의 액체를 선택한다고 하자.

사케가 아닌 물은 N - K 개가 존재할 수 있으며 물을 선택한 이후에는 사케가 자동적으로 선택된다.

따라서 현재 사케를 고른 갯수는 A - (N - K)개가 된다.

따라서 만약 A개의 큰 액체를 고른 경우 (A - (N - K))개의 사케를 고르게 된다.

해당 사케의 양이 원하는 사케의 양을 초과하는지 확인한다.

```cpp
long long solution(int size, int k, long long x, vector<long long>& liquids) {
  sort(liquids.begin(), liquids.end());

  long long sakeSum = 0;
  for (int choosen = 1; choosen <= size; choosen++) {
    int maybeSake = max(0, k - (size - choosen));
    if (maybeSake == 0) continue;

    sakeSum += liquids[size - choosen];

    if (sakeSum >= x) {
      return choosen;
    }
  }

  return -1;
}
```

## 고생한 점

타카하시는 매번 A개의 액체를 선택하는데 최선의 방법을 사용한다고 가정하고 풀어야 한다.

즉 가장 유리한 (양이 많은) 액체를 우선적으로 선택한다고 가정해야 한다.