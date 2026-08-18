# 4024. Nearest Available Drone

[링크](https://leetcode.com/problems/nearest-available-drone/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

배열을 순회하며 정답을 갱신하는 데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

각 드론을 순회하며 멘하탄 거리를 구하고 정답을 갱신한다.

```cpp
int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
  int answer = -1;
  int dist = INT_MAX;

  int size = drones.size();

  for (int i = 0; i < size; i++) {
    vector<int>& d = drones[i];
    int curDist = abs(d[0] - target[0]) + abs(d[1] - target[1]);
    if (curDist > d[2]) continue;

    if (curDist < dist) {
      answer = i;
      dist = curDist;
    }
  }

  return answer;
}
```

## 고생한 점
