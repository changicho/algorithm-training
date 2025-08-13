# C - Flush

[링크](https://atcoder.jp/contests/abc418/tasks/abc418_c)

| 난이도 |
| :----: |
|  350   |

## 설계

### 시간 복잡도

배열의 크기를 N, 쿼리의 크기를 Q라고 하자.

배열의 원소를 정렬하는데 O(N \* log_2(N))의 시간 복잡도를 사용한다.

각 쿼리마다 배열의 원소에 대해 이분 탐색을 수행할 경우 O(log_2(N))의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O((N + Q) \* log_2(N))이다.

### 공간 복잡도

정렬, prefix sum에 O(N)의 공간 복잡도를 사용한다.

정답에 O(Q)의 공간 복잡도를 사용한다.

### 그리디 & 이분 탐색 & prefix sum

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|     104      | O((N + Q) \* log_2(N)) |  O(N + Q)   |

딜러는 최대한 불리하게 차를 분배한다.

따라서 특정 쿼리 B에 대해서, 각각의 차 종류에 대해서 최대한 B-1개 까지 분배하려 한다.

따라서 각 차 종류들이 최대 B-1개 까지 분배되는 값에 1을 더한 값을 요구하는 경우 어떠한 경우라도 B개의 하나의 종류의 차를 받을 수 있다.

차들의 수를 정렬한 뒤 prefix sum을 생성한다.

이후 각 쿼리에 대해서 쿼리보다 작은 차들의 갯수를 이분탐색으로 구하며, 이들의 합은 prefix sum을 이용해 빠르게 구한다.

이후 나머지 차들에 대해서는 (쿼리 - 1)개씩 분배되도록 만든다.

마지막으로 해당 값에 1을 더한 값을 구한다.

이 때 가장 갯수가 많은 차보다 큰 쿼리가 들어오는 경우 정답을 생성하지 못함에 유의한다.

```cpp
auto solution(int size, vector<int> &arr, int qSize, vector<long long> &queries) {
  sort(arr.begin(), arr.end());

  vector<long long> answer;

  vector<long long> prefixSum(size + 1, 0);
  for (int i = 1; i < size + 1; i++) {
    prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
  }

  for (long long &query : queries) {
    // impossible case
    if (query > arr.back()) {
      answer.push_back(-1);
      continue;
    }

    int leftSize = lower_bound(arr.begin(), arr.end(), query) - arr.begin();
    int rightSize = size - leftSize;

    long long need =
        prefixSum[leftSize] + rightSize * ((long long)query - 1) + 1LL;
    if (need > prefixSum.back()) {
      answer.push_back(-1);
      continue;
    }
    answer.push_back(need);
  }

  return answer;
}
```

## 고생한 점
