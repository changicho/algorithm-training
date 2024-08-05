# 1508. Range Sum of Sorted Subarray Sums

[링크](https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 부분합을 구하는데 시간 복잡도는 O(N^2)이다.

이를 정렬하는데 O(N^2 \log_2(N^2))의 시간 복잡도가 소요된다. 이는 로그의 성질로 인해 O(N^2 \log_2(N))으로 표현할 수 있다.

이후 순회하며 정답을 구하는데 O(N^2)의 시간 복잡도가 소요된다. 따라서 총 시간 복잡도는 O(N^2 \log_2(N))이다.

### 공간 복잡도

정렬에 O(N^2)의 공간 복잡도가 필요하다.

### 정렬

| 내 코드 (ms) |    시간 복잡도    | 공간 복잡도 |
| :----------: | :---------------: | :---------: |
|      97      | O(N^2 * log_2(N)) |   O(N^2)    |

모든 부분합을 구하고 이를 정렬한 뒤 정답을 구한다.

```cpp
const int MOD = 1e9 + 7;

int rangeSum(vector<int>& nums, int n, int left, int right) {
  vector<int> sums;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += nums[j];
      sum %= MOD;

      sums.push_back(sum);
    }
  }

  sort(sums.begin(), sums.end());

  int answer = 0;
  for (int i = left - 1; i < right; i++) {
    answer += sums[i];
    answer %= MOD;
  }
  return answer;
}
```

## 고생한 점
