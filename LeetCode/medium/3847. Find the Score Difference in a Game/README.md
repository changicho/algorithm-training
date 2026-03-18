# 3847. Find the Score Difference in a Game

[링크](https://leetcode.com/problems/find-the-score-difference-in-a-game/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

각 숫자를 순회하며 시뮬레이션을 수행할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

시뮬레이션에 O(1)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

시뮬레이션을 수행하며 각 조건에 따라 점수를 계산한다.

이후 두 사람의 점수 차이를 반환한다.

```cpp
int scoreDifference(vector<int>& nums) {
  int size = nums.size();
  int first = 0;
  int second = 0;

  bool isFirst = true;
  for (int i = 0; i < size; i++) {
    int cur = nums[i];

    if (cur % 2 == 1) {
      isFirst = !isFirst;
    }
    if (i % 6 == 5) {
      isFirst = !isFirst;
    }

    if (isFirst) {
      first += cur;
    } else {
      second += cur;
    }
  }

  return first - second;
}
```

## 고생한 점
