# 4083. Minimum Deletions to Make Array Sharp

[링크](https://leetcode.com/problems/minimum-deletions-to-make-array-sharp/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

각 index를 순회하며 변경해야 하는 값의 수를 세는 데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답의 count를 세는 데 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(1)     |

연속된 같은 숫자들 중에 하나만 남기고 삭제하면 된다.

따라서 직전 값과 같은 수를 센다.

```cpp
int minDeletions(vector<int>& nums) {
  int size = nums.size();

  int answer = 0;

  for (int i = 0; i < size - 1; i++) {
    if (nums[i] == nums[i + 1]) {
      answer++;
    }
  }

  return answer;
}
```

## 고생한 점
