# 3987. Minimum Total Cost to Process All Elements

[링크](https://leetcode.com/problems/minimum-total-cost-to-process-all-elements/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

각 숫자별로 시뮬레이션을 수행할 경우 연산을 최적화 하지 않으면 제한시간 내에 불가능하다.

각 연산마다 나누기를 사용해 연산횟수를 줄일 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(1)     |

각 수를 순회하며 현재 숫자와 남은 resource를 비교하며 부족한 경우 필요한 만큼 더하며 코스트를 증가시킨다.

이후 현재 코스트의 값만큼 누적합을 구해 총 비용을 구한다.

```cpp
int minimumCost(vector<int>& nums, int k) {
  const int MOD = 1e9 + 7;

  int cost = 0;
  long long r = k;
  for (int& num : nums) {
    if (r >= num) {
      r -= num;
    } else {
      int diff = num - r;
      int count = (diff + k - 1) / k;

      r += (long long)k * count;
      r -= num;
      cost += count;
      cost %= MOD;
    }
  }

  int answer = ((long long)(cost) * (cost + 1) / 2) % MOD;
  return answer;
}
```

## 고생한 점
