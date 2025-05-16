# 3356. Zero Array Transformation II

[링크](https://leetcode.com/problems/zero-array-transformation-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N, queries의 크기를 M이라 하자.

모든 경우를 직접 수행할 경우 O(N \* M)의 시간 복잡도가 소요되므로 제한시간 내에 불가능하다.

스위핑 알고리즘을 사용할 경우 O(N + M)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

스위핑 알고리즘에 각 index마다의 줄어드는 값을 저장하는데 O(N)의 공간 복잡도가 필요하다.

### 라인 스위핑

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |  O(N + M)   |    O(N)     |

각 index를 순차적으로 순회하며 현재 값이 0이 될 때까지 쿼리를 사용한다.

이 때 현재 쿼리가 감소시키는 값과 범위를 별도 배열을 이용해 관리하며 값의 변화가 일어나는 index에 해당 값들을 저장한다.

이를 이용해 현재 적용되는 diff들을 관리하며, diff가 현재 index의 값보다 작을 때까지 쿼리를 적용한다.

```cpp
int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
  int size = nums.size(), qSize = queries.size();

  int answer = 0;

  int diff = 0;
  vector<int> diffs(size + 1);
  for (int i = 0; i < size; i++) {
    while (diff + diffs[i] < nums[i]) {
      if (answer >= qSize) {
        return -1;
      }

      vector<int>& query = queries[answer];
      answer++;

      int left = query[0], right = query[1], val = query[2];

      if (right >= i) {
        diffs[max(left, i)] += val;
        diffs[right + 1] -= val;
      }
    }

    diff += diffs[i];
  }
  return answer;
}
```

## 고생한 점
