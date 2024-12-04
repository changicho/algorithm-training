# 3362. Zero Array Transformation III

[링크](https://leetcode.com/problems/zero-array-transformation-iii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N, queries의 크기를 Q라 하자.

쿼리들을 오름차순으로 정렬한다. 이후 힙을 사용해 현재까지 적용된 쿼리들로 현재 값을 0으로 만들 수 없는 경우 쿼리를 더 추가한다.

nums를 순회하며 힙을 이용하므로 시간 복잡도는 O(N \* log_2(Q)) 이다.

### 공간 복잡도

힙과 정렬에 O(Q)의 공간 복잡도가 필요하다.

### 힙

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|     126      | O(N * log_2(Q)) |  O(N + Q)   |

각 쿼리를 오름차순으로 정렬해, 가장 먼저 시작하는 쿼리부터 선택한다.

그리고 각 쿼리들을 선택했을 때 감소하는 숫자의 수를 저장할 변수를 선언한다.

각 쿼리마다 끝났을 때 감소하는 수의 변화를 저장할 배열을 선언한다.

nums의 index를 0부터 순회하며 선택한 쿼리의 범위에 들어가지 않는 경우 쿼리를 제거한다.

이후 선택한 쿼리들로 nums를 0으로 만들 수 있는지 판단한다.

가능한 경우 다음 index로 넘어가며, 불가능한 경우 선택가능한 쿼리를 추가한다.

이 때 쿼리를 추가해도 0으로 만들 수 없는 경우는 -1을 반환한다.

```cpp
int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
  int size = nums.size(), qSize = queries.size();

  sort(queries.begin(), queries.end());
  priority_queue<int> pq;

  vector<int> diffs(size + 1, 0);
  int minus = 0, qI = 0;

  for (int i = 0; i < size; i++) {
    minus += diffs[i];

    while (qI < qSize && queries[qI][0] <= i) {
      pq.push(queries[qI][1]);
      qI++;
    }

    while (minus < nums[i]) {
      if (pq.empty() || pq.top() < i) {
        return -1;
      }

      int right = pq.top();
      diffs[right + 1]--;
      pq.pop();

      minus++;
    }
  }

  return pq.size();
}
```

## 고생한 점
