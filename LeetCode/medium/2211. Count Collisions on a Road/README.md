# 2211. Count Collisions on a Road

[링크](https://leetcode.com/problems/count-collisions-on-a-road/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

순회를 이용해 각 차량의 방향을 확인하며 충돌 횟수를 계산할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회하며 각 자동차의 방향의 수를 저장하는데 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(1)     |

왼쪽부터 순회하며 각 자동차의 방향을 확인한다.

이 때 오른쪽을 바라보는 자동차의 수와 현재 stop된 자동차가 왼쪽에 존재하는지를 저장한다.

만약 왼쪽을 바라보는 자동차나 stop이 존재할 경우 충돌이 발생한다.

충돌이 발생하거나 stop을 만나는 경우마다 오른쪽을 바라보는 자동차의 수를 초기화한다.

```cpp
int countCollisions(string directions) {
  int rCount = 0;
  int sCount = 0;

  int answer = 0;
  for (char& c : directions) {
    if (c == 'L') {
      answer += rCount;
      if (sCount > 0 || rCount > 0) {
        answer += 1;
        sCount = 1;
      }
      rCount = 0;
    } else if (c == 'S') {
      answer += rCount;
      sCount = 1;
      rCount = 0;
    } else if (c == 'R') {
      rCount++;
    }
  }

  return answer;
}
```

## 고생한 점
