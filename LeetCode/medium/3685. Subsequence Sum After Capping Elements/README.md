# 3685. Subsequence Sum After Capping Elements

[링크](https://leetcode.com/problems/subsequence-sum-after-capping-elements/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 arr의 크기를 N, 만들고자 하는 합을 K라 하자.

배열의 원소를 오름차순으로 정렬 후 X에 대해 순회한다.

정렬에 O(N \* log_2(N))의 시간이 소요된다.

이 때 현재 원소를 이용해 만들 수 있는 합을 동적 계획법으로 갱신한다.

해당 순회에 O(N \* K)의 시간이 소요된다.

따라서 총 시간 복잡도는 O(N \* (log_2(N) + K))이다.

### 공간 복잡도

정렬과 정답, 동적 계획법에 O(N + K)의 공간 복잡도를 사용한다.

### 정렬 & 동적 계획법

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|      87      | O(N \* (log_2(N) + K)) |  O(N + K)   |

x를 1부터 N까지 순회하며, x보다 큰 원소를 처리하기 위해 배열을 오름차순으로 정렬한다.

이전 index까지 원소를 사용해 만들 수 있는 합을 저장한다.

이후 현재 원소를 이용해 만들 수 있는 합을 모든 원소를 순회하며 갱신한다.

이후 현재 index까지 사용했을 떄 만들 수 있는 합이 존재하므로, 나머지 x보다 큰 원소들을 x로 바꿔 만들 수 있는지 확인한다.

이 때 x보다 큰 원소를 모두 사용하지 않아도 된다.

```cpp
vector<bool> subsequenceSumAfterCapping(vector<int> &arr, int k) {
  int size = arr.size();
  sort(arr.begin(), arr.end());
  bool isPossible[4001] = {
      false,
  };

  vector<bool> answer;
  isPossible[0] = true;

  for (int i = 0, x = 1; x <= size; x++) {
    while (i < size && arr[i] < x) {
      for (int sum = k; sum >= arr[i]; sum--) {
        isPossible[sum] |= isPossible[sum - arr[i]];
      }

      i++;
    }

    bool canMake = false;
    int bigCount = size - i;
    for (int count = 0; count <= bigCount && count * x <= k; count++) {
      if (isPossible[k - count * x]) {
        canMake = true;
        break;
      }
    }

    answer.push_back(canMake);
  }
  return answer;
}
```

## 고생한 점
