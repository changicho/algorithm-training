# 1493. Longest Subarray of 1's After Deleting One Element

[링크](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

각 원소중 하나를 skip하는 모든 경우의 수에 대해 탐색을 진행할 수 있다. 이 경우 O(N^2)의 시간 복잡도를 사용한다.

한번의 순회로 직전의 1의 연속된 갯수와 위치를 기억하며 탐색을 진행할 수 있다. 이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

직전값과 현재값의 범위만 저장하면 되므로 O(1)의 공간 복잡도를 사용한다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      46      |    O(N)     |    O(1)     |

연속된 1의 범위를 Range라 하자.

직전의 1이 연속된 값의 범위를 before, 현재 1이 연속된 값의 범위를 cur이라 하자.

만약 before과 cur을 연결할 수 있는 경우 (중간에 0이 하나만 존재) 두 길이를 합쳐 정답을 갱신할 수 있다.

그 외의 경우는 cur의 길이만 갱신한다.

이를 반복하며 정답을 갱신한다.

만약 모든 원소가 1인 경우는 정답은 size - 1이다. (한 개를 무조건 빼야 하므로)

이를 구현하면 다음과 같다.

```cpp
struct Range {
  int left, right;
};

int longestSubarray(vector<int>& nums) {
  int size = nums.size();

  Range before = {INT_MIN, INT_MIN};
  Range cur = {INT_MIN, INT_MIN};
  int answer = 0;
  int zeroCount = 0;
  for (int i = 0; i < size; i++) {
    if (nums[i] == 0) {
      zeroCount++;
      before = cur;

      cur = {INT_MIN, INT_MIN};
    } else {
      if (cur.left == INT_MIN) cur.left = i;
      cur.right = i;
    }

    if (cur.left != INT_MIN) {
      answer = max(answer, cur.right - cur.left + 1);
    }

    if (before.right + 2 == cur.left) {
      int beforeLength = before.right - before.left + 1;
      int curLength = cur.right - cur.left + 1;
      answer = max(answer, beforeLength + curLength);
    }
  }

  if (zeroCount == 0) return size - 1;
  return answer;
}
```

## 고생한 점
