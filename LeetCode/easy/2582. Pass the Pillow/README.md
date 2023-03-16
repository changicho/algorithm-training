# 2582. Pass the Pillow

[링크](https://leetcode.com/problems/pass-the-pillow/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N, 시간을 T라 하자. (1 <= N <= 1,000, 1 <= T <= 1,000)

각 시간별로 직접 순회를 할 경우 O(T)의 시간 복잡도를 사용한다.

### 공간 복잡도

시뮬레이션에 O(1)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(T)     |    O(1)     |

T초동안 시작 위치부터 이동을 진행한다.

```cpp
int passThePillow(int n, int time) {
  bool isLeft = true;
  int index = 0;
  while (time--) {
    if (isLeft) {
      index++;
    } else {
      index--;
    }

    if (index == 0 || index == (n - 1)) {
      isLeft = !isLeft;
    }
  }
  return index + 1;
}
```

### 시뮬레이션 (사이클)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(T)     |    O(1)     |

위 방법에서 한번 순회를 마친 경우 다시 처음으로 돌아오게 된다.

따라서 순회를 한번 마친 경우를 cycle이라 하고, 한번 순회에 들어가는 시간들을 빼고 실제로 이동한 경우만 count한다.

```cpp
int passThePillow(int n, int time) {
  int cycleTime = (n - 1) * 2;
  time %= cycleTime;

  bool isLeft = true;
  int index = 0;
  while (time--) {
    if (isLeft) {
      index++;
    } else {
      index--;
    }

    if (index == 0 || index == (n - 1)) {
      isLeft = !isLeft;
    }
  }
  return index + 1;
}
```

### 나누기

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

각 사이클에 들어가는 시간은 (N - 1) \* 2 이다.

한쪽 끝에서 반대쪽 끝으로 이동하는 시간은 (N - 1)초 이므로, 이를 이용해 맨 마지막에 이동해야 하는 만큼만 이동시킬 수 있다.

이 때 시작위치가 왼쪽인지, 오른쪽인지는 짝수번째 사이클인지 홀수번째 사이클인지에 따라 결정된다.

```cpp
int passThePillow(int n, int time) {
  int cycleCount = time / (n - 1);
  int toMove = time % (n-1);

  if(cycleCount % 2 == 0){
    // left to right case
    return toMove + 1;
  }else{
    // right to left case
    return n - toMove;
  }
}
```

## 고생한 점
