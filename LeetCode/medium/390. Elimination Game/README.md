# 390. Elimination Game

[링크](https://leetcode.com/problems/elimination-game/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 숫자를 N이라 하자.

완전 탐색으로 풀이할 경우 각 배열에서 필요한 원소만 새로 담은 배열을 만든다.

이는 결국 모든 원소를 한번씩 순회하게 되므로 총 시간 복잡도는 O(N)이다. 이는 N이 매우 크므로 제한시간 내에 불가능하다.

결과적으로 우리는 배열의 크기가 1일때의 시작점을 찾아야 한다.

각 과정마다 배열의 크기는 절반씩 줄어드므로 O(log_2(N))의 시간 복잡도로 풀이할 수 있다.

### 공간 복잡도

매번 새로운 배열을 생성할 경우 O(N)의 공간 복잡도를 사용한다.

수학적인 방법을 이용해 절반씩 나눠 탐색할 경우 O(1)의 공간 복잡도를 사용한다.

만약 이를 재귀호출로 구현할 경우 O(log_2(N))의 공간 복잡도를 사용한다.

### 수학

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      11      | O(log_2(N)) |    O(1)     |

```cpp
int lastRemaining(int n) {
  int head = 1, step = 1;
  bool isLeft = true;

  while (n > 1) {
    if (isLeft) {
      head += step;
    } else {
      head += n % 2 == 0 ? 0 : step;
    }

    step *= 2;
    n /= 2;

    isLeft = !isLeft;
  }

  return head;
}
```

## 고생한 점
