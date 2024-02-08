# 3028. Ant on the Boundary

[링크](https://leetcode.com/problems/ant-on-the-boundary/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

순회하며 개미를 이동시키고 처음 시작 위치로 돌아오는 경우들을 찾아야 한다.

이를 위해 순회를 해야 하므로 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

현재 좌표 위치를 저장하는데 O(1)의 공간 복잡도가 필요하다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

각 단계마다 이동하는 크기 만큼 현재 개미의 위치를 이동한다.

처음 위치를 0으로 지정하고 이동한 위치가 0인 경우에만 처음 위치로 돌아온 것으로 판단한다.

각 경우마다 위치가 0인 경우 count를 증가시키고 이를 반환한다.

```cpp
int returnToBoundaryCount(vector<int>& nums) {
  int answer = 0;
  int curX = 0;
  for (int& move : nums) {
    curX += move;

    if (curX == 0) answer++;
  }
  return answer;
}
```

## 고생한 점
