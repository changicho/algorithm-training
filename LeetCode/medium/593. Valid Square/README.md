# 593. Valid Square

[링크](https://leetcode.com/problems/valid-square/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

점의 개수를 N이라 하자

각 점들마다의 거리를 계산해야 하며, 이 연산에는 상수만큼의 연산이 필요하다. O(10)

이 거리들을 이용해 정사각형인지 구할 수 있다.

최종적으로 시간 복잡도는 O(1)이다.

### 공간 복잡도

점들마다의 거리를 저장해야 하며 이는 상수 만큼의 공간이 필요하다.

따라서 공간 복잡도는 O(1)이다.

### 거리 비교

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(1)     |    O(1)     |

정사각형의 경우 4점으로 만들 수 있는 거리는 다음과 같다.

- 정사각형 변의 길이 \* 4
- 정사각형의 내부 대각선 길이 \* 2

따라서 모든 점마다의 거리를 계산하고, 이 거리들이 위 조건을 만족하는지 판별한다.

이 때 점과의 거리가 0인 경우가 하나라도 있는 경우에는 문제 조건에 부합하지 않는다.

거리들을 hash set에 저장한 뒤, 이 hash set의 key의 개수가 2개인 경우에만 정답으로 인정한다.

만약 같은 길이의 변이 3개, 3개 있고 key가 2개인 경우 혹은 1개 5개인 경우는 는 2차원 평면상에 존재할 수 없다.

```cpp
int getDistance(vector<int>& a, vector<int>& b) {
  return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
}

bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
  unordered_set<int> s;

  s.insert(getDistance(p1, p2));
  s.insert(getDistance(p1, p3));
  s.insert(getDistance(p1, p4));
  s.insert(getDistance(p2, p3));
  s.insert(getDistance(p2, p4));
  s.insert(getDistance(p3, p4));

  if (s.count(0) == true) {
    return false;
  }
  return s.size() == 2;
}
```

## 고생한 점
