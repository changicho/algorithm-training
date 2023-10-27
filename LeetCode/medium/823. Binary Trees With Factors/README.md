# 823. Binary Trees With Factors

[링크](https://leetcode.com/problems/binary-trees-with-factors/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 배열의 크기를 N이라 하자.

모든 경우를 탐색할 경우 제한시간 내에 불가능하다.

각 루트에 따른 경우의 수를 동적 계획법으로 구한 후 이를 사용할 수 있다.

이 때 루트의 값이 작은 순으로 탐색을 진행해야 한다. 따라서 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이 경우 O(N^2)의 시간 복잡도를 사용한다.

총 O(N^2 + N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|      38      | O(N^2 + N \* log_2(N)) |    O(N)     |

각 루트마다의 경우의 수를 알고 있을 경우 현재 루트의 수가 x인 경우의 수는 다음과 같이 구할 수 있다.

- x = a \* b 인 경우
- a의 경우의 수 \* b의 경우의 수
- 이를 모든 a,b에 대해 구한 값을 더한 값이 x의 경우의 수

따라서 x가 작은 순으로 dp를 갱신해 나가며 모든 경우의 수를 구할 수 있다.

```cpp
const int MOD = 1e9 + 7;

int numFactoredBinaryTrees(vector<int> &arr) {
  unordered_map<int, int> dp;
  sort(arr.begin(), arr.end());

  for (int &num : arr) {
    dp[num]++;
  }

  for (int i = 0; i < arr.size(); i++) {
    int num = arr[i];

    for (int leftI = 0; leftI < i; leftI++) {
      int left = arr[leftI];
      int right = num / left;

      if (left * right != num) continue;
      if (dp.count(right) == 0) continue;

      dp[num] += ((long long)dp[left] * dp[right]) % MOD;
      dp[num] %= MOD;
    }
  }

  int answer = 0;
  for (auto &it : dp) {
    answer += it.second;
    answer %= MOD;
  }
  return answer;
}
```

## 고생한 점
