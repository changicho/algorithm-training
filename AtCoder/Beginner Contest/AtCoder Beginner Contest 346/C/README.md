# C - Σ

[링크](https://atcoder.jp/contests/abc346/tasks/abc346_c)

| 난이도 |
| :----: |
|  250   |

## 설계

### 시간 복잡도

입력받은 배열의 크기를 N, 수를 K라 하자.

배열의 원소를 hash set에 집어넣고 1부터 K까지 순회할 경우 O(N + K)의 시간 복잡도를 사용한다.

이는 K가 매우 크므로 제한시간 내에 불가능하다.

배열을 순회하며 K 이하의 값들을 찾아 1~K까지의 합에서 제거할 수 있다.

이 경우 1~K의 합을 구하는데 O(1), 배열의 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

수의 범위가 2 \* 10^9 이며 합을 구해야 하므로 long long형으로 선언한다.

hash set에 O(min(N, K))의 공간 복잡도가 필요하다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도  |
| :----------: | :---------: | :----------: |
|      45      |    O(N)     | O(min(N, K)) |

1부터 K까지의 합을 미리 구해놓는다.

이후 nums를 순회하며 K이하의 값을 중복되지 않게 찾는다.

이후 해당 합에서 빼준다.

```cpp
long long solution(vector<int> &nums, long long k) {
  long long sum = k * (k + 1) / 2;

  unordered_set<int> us;
  for (int &num : nums) {
    if (us.count(num)) continue;
    if (num > k) continue;
    us.insert(num);
    sum -= num;
  }
  return sum;
}
```

## 고생한 점
