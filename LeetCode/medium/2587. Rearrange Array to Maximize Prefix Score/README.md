# 2587. Rearrange Array to Maximize Prefix Score

[링크](https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자. (N <= 10^5, -10^6 <= nums[i] <= 10^6)

가장 유리한 순으로 배열하고 prefix sum이 양수인 경우가 가장 많도록 배열한다.

이를 위해 수를 내림차순으로 정렬 후, prefix sum이 0 이하가 되기 직전 경우를 찾는다.

이때 정렬에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 최대 O(N)의 공간 복잡도를 사용한다.

직전의 prefix sum만을 사용하면 되므로 O(1)의 공간 복잡도를 사용한다.

정답의 범위에 prefix sum이 최대 10^11까지 될 수 있으므로 long long 형으로 선언한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     190      | O(N \* log_2(N)) |    O(1)     |

```cpp
int maxScore(vector<int>& nums) {
  sort(nums.begin(), nums.end(), greater<int>());

  long long score = 0;
  int answer = 0;
  for (int& num : nums) {
    score += num;
    if (score <= 0) break;
    answer++;
  }
  return answer;
}
```

## 고생한 점
