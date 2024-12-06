# 3360. Stone Removal Game

[링크](https://leetcode.com/problems/stone-removal-game/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자. 가능한 수행 횟수는 1~10까지의 합 이내이다.

이를 시뮬레이션으로 수행할 경우 O(1)의 시간 복잡도가 소요된다.

### 공간 복잡도

시뮬레이션에 O(1)의 공간 복잡도가 필요하다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

앨리스와 밥의 순서대로 시뮬레이션을 수행한다.

```cpp
bool canAliceWin(int n) {
  int alice = 10, bob = 9;

  while (n > 0) {
    if (n < alice) return false;
    n -= alice;
    alice -= 2;

    if (n < bob) return true;
    n -= bob;
    bob -= 2;
  }
  return false;
}
```

## 고생한 점
