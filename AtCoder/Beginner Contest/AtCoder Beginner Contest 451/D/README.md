# D - Concat Power of 2

[링크](https://atcoder.jp/contests/abc451/tasks/abc451_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

완전 탐색으로 중복을 제외한 가능한 모든 경우를 순회하자.

가능한 모든 경우를 순회할 때, 최악의 경우 O(1099898)의 시간 복잡도가 소요된다.

### 공간 복잡도

가능한 모든 경우를 저장할 때, 최악의 경우 O(1099898)의 공간 복잡도가 소요된다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     896      | O(1099898)  | O(1099898)  |

문제 조건에 맞는 모든 수를 완전 탐색으로 구한다.

이후 값을 정렬 후 N번째 수를 반환한다.

```cpp
long long solution(long long n) {
  const long long LIMIT = 1e9;

  int lengths[31] = {
      0,
  };
  for (int i = 0; i < 31; i++) {
    lengths[i] = to_string(1LL << i).length();
  }

  int pows[10] = {
      1,
  };
  for (int i = 1; i < 10; i++) {
    pows[i] = pows[i - 1] * 10;
  }

  vector<long long> nums;
  unordered_set<long long> visited;

  function<void(long long)> dfs = [&](long long num) {
    for (int i = 0; i < 31; i++) {
      long long cur = (1LL << i);

      int length = lengths[i];
      long long next = num * pows[length] + cur;

      if (next > LIMIT) continue;

      if (visited.count(next)) continue;
      visited.insert(next);
      nums.push_back(next);

      dfs(next);
    }
  };

  dfs(0);

  sort(nums.begin(), nums.end());

  return nums[n - 1];
}
```

## 고생한 점
