# 3191. Minimum Operations to Make Binary Array Elements Equal to One I

[링크](https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

탐욕 알고리즘을 사용해 순회하며 풀이할 수 있다. 이 경우 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

입력받은 배열을 사용할 경우 O(1)의 공간 복잡도가 필요하다.

### 탐욕 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      11      |    O(N)     |    O(1)     |

왼쪽부터 순회하며 현재 원소를 1로 바꿔야 하는 경우 현재 원소를 시작점으로 3개의 원소를 모두 바꾼다.

이를 끝까지 반복하며 이후 1로 바꿔야 하는 원소가 남아있는 경우 -1을 반환한다.

그 외의 경우 바꾼 횟수를 반환한다.

```cpp
int minOperations(vector<int>& nums) {
  int size = nums.size();
  int answer = 0;
  for (int i = 0; i < size - 2; i++) {
    if (nums[i] == 0) {
      answer++;
      for (int j = 0; j < 3; j++) {
        nums[i + j] = !nums[i + j];
      }
    }
  }

  if (nums[size - 1] == 0 || nums[size - 2] == 0) return -1;
  return answer;
}
```

## 고생한 점
