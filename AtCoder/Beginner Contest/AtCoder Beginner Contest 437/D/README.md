# D - Sum of Differences

[링크](https://atcoder.jp/contests/abc437/tasks/abc437_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

두 배열의 크기를 N, M이라 하자.

prefix sum과 이분 탐색을 사용할 경우 O(N + M \* log_2(M))의 시간 복잡도를 가진다.

### 공간 복잡도

정렬에 O(M)의 공간 복잡도를 사용하며, prefix sum에 O(M)의 공간 복잡도를 사용한다.

### prefix sum & 이분 탐색

| 내 코드 (ms) |     시간 복잡도      | 공간 복잡도 |
| :----------: | :------------------: | :---------: |
|      72      | O(N + M \* log_2(M)) |    O(M)     |

특정 `A[0]` 값에 대해 정답을 구하기 위한 식은 다음과 같다.

`|A[0] - B[0]| + |A[0] - B[1]| + |A[0] - B[2]| + ...`

여기서 `A[0]`부분은 반복되며, 해당 값보다 큰 `B[i]` 값과 작은 `B[i]` 값에 대해 각각 나누어 생각할 수 있다.

- `(A[0] - B[i]) + (A[0] - B[j]) + ...` (A[0] > B[i], B[j], ...)
- `(B[k] - A[0]) + (B[l] - A[0]) + ...` (B[k], B[l], ... > A[0])

따라서 특정 A의 값에 대해 이분 탐색을 통해 B 배열에서 해당 값보다 큰 값과 작은 값의 개수를 구할 수 있다.

이후 prefix sum을 통해 각 부분의 B원소들의 합을 구한 뒤 정답에 더해주면 된다.

```cpp
long long solution(int size1, vector<int>& nums1, int size2, vector<int>& nums2) {
  const long long MOD = 998244353;
  long long answer = 0;

  sort(nums2.begin(), nums2.end());

  vector<long long> prefixSum(size2 + 1, 0);
  for (int i = 0; i < size2; i++) {
    prefixSum[i + 1] = prefixSum[i] + nums2[i];
    prefixSum[i + 1] %= MOD;
  }

  for (int i = 0; i < size1; i++) {
    long long curSum = 0;

    long long leftCount =
        lower_bound(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
    long long rightCount = size2 - leftCount;

    long long leftSum = prefixSum[leftCount];
    long long rightSum = (prefixSum[size2] - prefixSum[leftCount] + MOD) % MOD;

    curSum += ((nums1[i] * leftCount) % MOD - leftSum + MOD) % MOD;
    curSum %= MOD;

    curSum += (rightSum - (nums1[i] * rightCount) % MOD + MOD) % MOD;
    curSum %= MOD;

    answer += curSum;
    answer %= MOD;
  }

  return answer;
}
```

## 고생한 점
