# 18111. 마인크래프트

[링크](https://www.acmicpc.net/problem/18111)

|   난이도   | 정답률(\_%) |
| :--------: | :---------: |
| Silver III |   31.257    |

## 설계

### 시간 복잡도

지도의 크기는 최대 500^2 이다.

평탄화 작업이 가능한지 여부를 판단하기 위해 모든 좌표를 탐색해야 하므로 500^2의 시간복잡도가 소요된다.

이 평탄화 작업을 모든 좌표에 따라 탐색을 진행할지, 높이에 따라 탐색을 진행할 지 여부에 따라 시간복잡도는 다음과 같다.

- 모든 좌표 : 500^4
- 높이 : 500^2 X 256

모든 좌표의 경우 500^4 이므로 제한시간 내에 불가능하다.

따라서 높이에 따라서 탐색을 진행한다.

### 공간 복잡도

높이의 최대 크기는 256이다. 따라서 int형으로 선언한다.

정답의 경우 최악의 시간의 경우 256 X 2 X 500^2 가 최대이므로 128,000,000 이므로 int형으로 충분하다.

### 평탄화 여부

현재 높이에 따라서 평탄화 작업이 가능한지 모든 좌표에 대해 탐색한다.

이때 인벤토리의 블록의 개수가 평탄화 완료 후 음수가 되는 경우 유효하지 않은 경우이므로 제외한다.

```cpp
void calculate(int height) {
  int time = 0;
  int inventory = B;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      int diff = board[y][x] - height;

      // 깎아내야하는경우
      if (diff > 0) {
        time += 2 * diff;
        inventory += diff;
      } else {
        // 채워야하는 경우
        time += height - board[y][x];
        inventory -= height - board[y][x];
      }
    }
  }

  if (inventory < 0) return;

  if (answerTime > time) {
    answerTime = time;
    answerHeight = height;
  } else if (answerTime == time) {
    answerHeight = max(answerHeight, height);
  }
}
```

이를 입력받은 높이 range에 따라서 수행한다.

```cpp
for (int height = fromHeight; height <= toHeight; height++) {
  calculate(height);
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     160      |       12       |

## 고생한 점
