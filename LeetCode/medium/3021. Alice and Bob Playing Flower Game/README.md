# 3021. Alice and Bob Playing Flower Game

[링크](https://leetcode.com/problems/alice-and-bob-playing-flower-game/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 두 수를 N, M이라 하자.

두 수의 합이 홀수일 때 Alice가 이길 수 있고, 짝수일 때 Bob이 이길 수 있다.

이를 이용해 수학적 방법을 이용하면 O(1)의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

수학적 방법을 사용할 경우 O(1)의 공간 복잡도가 필요하다.

### 수학

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(1)     |    O(1)     |

N + M이 홀수일 때 Alice가 이길 수 있다.

이 경우 N과 M은 다음과 같은 경우에 총 합이 홀수가 된다.

- N이 짝수, M이 홀수
- N이 홀수, M이 짝수

따라서 1 ~ N, 1 ~ M까지 각각의 짝수, 홀수의 개수를 구하고 이를 이용해 정답을 구한다.

이 때 가능한 쌍의 갯수는 두 수 각각의 경우의 수의 곱이된다.

```cpp
long long flowerGame(int n, int m) {
  long long oddY = 0, oddX = 0, evenY = 0, evenX = 0;

  evenX = n / 2;
  oddX = n % 2 == 0 ? evenX : evenX + 1;
  evenY = m / 2;
  oddY = m % 2 == 0 ? evenY : evenY + 1;

  return oddX * evenY + evenX * oddY;
}
```

## 고생한 점
