# 3047. Find the Largest Area of Square Inside Two Rectangles

[링크](https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

직사각형 영역의 수를 N이라 하자.

두 직사각형이 겹치는 구역중 가장 큰 구역을 완전 탐색으로 구한다. 이에 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

겹치는 구간을 구하는 데 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      96      |   O(N^2)    |    O(1)     |

주어진 직사각형 모양의 영역들 중 겹치는 구간이 있는 경우 겹치는 구간 중 정사각형이 들어가는 가장 큰 구역을 구한다.

이를 위해 직사각형 쌍을 모두 탐색하며 2개의 영역이 겹치는 구간 중 가장 큰 정사각형의 넓이를 구한다.

각 x, y좌표마다 시작점과 끝점이 존재한다.

겹치는 영역의 각 축의 길이는 (두 끝점 중 작은점) - (두 시작점 중 큰점) 으로 구할 수 있다.

이 때 해당 값이 음수인 경우는 겹치는 영역이 없는 경우이다.

두 축의 길이 중 작은 값이 정사각형의 크기가 된다. 이를 이용해 정답을 갱신한다.

```cpp
long long calc(vector<int>& aBottomLeft, vector<int>& aTopRight, vector<int>& bBottomLeft, vector<int>& bTopRight) {
  long long x =
      min(aTopRight[0], bTopRight[0]) - max(aBottomLeft[0], bBottomLeft[0]);
  long long y =
      min(aTopRight[1], bTopRight[1]) - max(aBottomLeft[1], bBottomLeft[1]);

  long long length = min(y, x);
  if (length < 0) return 0;

  return length * length;
}

long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
  int size = bottomLeft.size();

  long long answer = 0;
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      long long cur =
          calc(bottomLeft[i], topRight[i], bottomLeft[j], topRight[j]);

      answer = max(answer, cur);
    }
  }

  return answer;
}
```

## 고생한 점
