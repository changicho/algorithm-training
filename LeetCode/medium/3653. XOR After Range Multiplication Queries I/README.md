# 3653. XOR After Range Multiplication Queries I

[링크](https://leetcode.com/problems/xor-after-range-multiplication-queries-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 각각 N, Q라 하자.

각 쿼리를 순회하며 직접 시뮬레이션을 수행할 경우 O(NQ)의 시간 복잡도가 소요된다.

### 공간 복잡도

입력받은 공간을 제외하고 O(1)의 공간 복잡도가 소요된다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      75      |    O(NQ)    |    O(1)     |

각 쿼리마다 직접 시뮬레이션을 수행한다.

```cpp
int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
  const int MOD = 1e9 + 7;
  for (vector<int>& q : queries) {
    for (int i = q[0]; i <= q[1]; i += q[2]) {
      nums[i] = (1LL * nums[i] * q[3]) % MOD;
    }
  }

  int answer = 0;
  for (int& num : nums) {
    answer ^= num;
  }
  return answer;
}
```

## 고생한 점
