# 1051. Height Checker

[링크](https://leetcode.com/problems/height-checker/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 heights의 크기를 N이라 하자.

정렬 후 비교할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 최대 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      0       | O(N \* log_2(N)) |    O(N)     |

heights를 복사한 배열을 생성하고 이를 정렬한다.

이후 각 index의 값을 비교한다.

```cpp
int heightChecker(vector<int>& heights) {
  vector<int> copied = heights;

  sort(copied.begin(), copied.end());

  int answer = 0;
  for (int i = 0; i < heights.size(); i++) {
    if (heights[i] != copied[i]) answer++;
  }
  return answer;
}
```

## 고생한 점
