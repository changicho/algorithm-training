# 1503. Last Moment Before All Ants Fall Out of a Plank

[링크](https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

오른쪽, 왼쪽 각 방향에 존재하는 개미의 위치를 R, L이라 하자.

각 개미는 이동한 뒤 다른 개미를 만날 때 방향을 바꾼다. 이를 방향을 바꾸지 않고 개미만 변경한 채 계속 이동하는것으로 생각할 수 있다.

이 경우 각 위치들의 도착 시간은 시작 위치에 따라 정해진다.

따라서 순회하며 최대값을 구하고 이를 비교하면 된다. 이에 O(R + L)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 순회마다 최대값을 저장할 공간이 필요하다. 이에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      14      |  O(R + L)   |    O(1)     |

각 개미들이 마주친 뒤 방향을 바꾸는 것을, 두 개미가 서로를 지나치는 것으로 생각할 수 있다.

이 경우 각 개미들은 시작 위치에서부터 끝 방향으로 다른 개미들을 지나치며 이동하게 된다.

따라서 각 개미들이 이동한 뒤 도착한 시간은 시작 위치와 방향에 따라 정해진다.

```cpp
int getLastMoment(int n, vector<int>& left, vector<int>& right) {
  int answer = 0;
  for (int& l : left) {
    answer = max(answer, l);
  }
  for (int& r : right) {
    answer = max(answer, (n - r));
  }
  return answer;
}
```

## 고생한 점
