# 2672. 여러 직사각형의 전체 면적 구하기

[링크](https://www.acmicpc.net/problem/2672)

| 난이도  | 정답률(\_%) | 시간 제한(초) |
| :-----: | :---------: | :-----------: |
| Gold II |   29.792    |       1       |

## 설계

### 시간 복잡도

직사각형의 개수 N은 최대 30개 이다. 좌표가 실수형으로 주어지므로 좌표를 모두 탐색해 수행할 경우 제한시간 내에 불가능하다.

소숫점 첫째자리. 시작부터 끝까지 0 ~ 20,000이므로 20,000^2 = 400,000,000 이므로 제한시간 내에 불가능하다.

따라서 스위핑을 이용해 시간복잡도를 최적화한다.

### 공간 복잡도

좌표는 소숫점 첫째자리까지 주어진다. 0.1을 단위로 배열을 생성할 경우 20,000 크기의 배열이 필요하다.

각 배열에는 0.1 단위의 영역에 포함되는 직사각형의 수를 표시해야한다. 이는 최대 30까지 표현해야 하므로 int형으로 선언한다.

### 스위핑 (Sweeping)

스위핑 알고리즘이란 단어의 뜻 그대로 휩쓸고 지나가며 문제를 해결하는 방식으로, 특정 기준에 따라 정렬한 후 순서대로 처리하는 알고리즘이다.

### 영역 넓이 구하기

소숫점 첫째자리 까지만 주어지므로 10을 곱해 정수형으로 문제를 풀이한다.

각 직사각형 별로 x축에 수직인 세로 부분을 다음과 같이 저장한다. 이를 다음과 같이 정렬한다.

- x좌표 순으로 정렬
- x좌표가 같은경우 시작 변이 먼저 오도록 정렬

```cpp
struct Rectangle {
  int x;  // x 좌표
  int yStart, yEnd; // y좌표의 시작과 끝
  bool isLeft;  // 직사각형의 시작점, 끝점 여부

  bool operator<(const Rectangle &b) const {
    if (x != b.x) {
      return x < b.x;
    }
    return !isLeft && b.isLeft;
  }
};
```

이후 각 직사각형마다 시작 변과 끝 변을 저장한다.

```cpp
for (int i = 0; i < N; i++) {
  double x, y, width, height;
  Rectangle rectangle;
  cin >> x >> y >> width >> height;

  x *= 10;
  y *= 10;
  width *= 10;
  height *= 10;

  rectangle = {(int)x, (int)y, (int)(y + height), true};
  rectangles.push_back(rectangle);

  rectangle = {(int)(x + width), (int)y, (int)(y + height), false};
  rectangles.push_back(rectangle);
}

sort(rectangles.begin(), rectangles.end());
```

이후 각 세로 변을 탐색하며 직사각형과 겹쳐있는 부분을 count한다.

```cpp
long long answer = 0;
int currentX = 0;
for (Rectangle rectangle : rectangles) {
  int count = 0;
  for (int y = 0; y <= 20000; y++) {
    if (board[y] > 0) {
      count++;
    }
  }

  answer += count * (rectangle.x - currentX);

  for (int y = rectangle.yStart + 1; y <= rectangle.yEnd; y++) {
    board[y] += rectangle.isLeft ? 1 : -1;
  }
  currentX = rectangle.x;
}
```

이후 문제에 따라 답을 출력한다.

```cpp
if (answer % 100 == 0) {
  cout << answer / 100 << "\n";
} else {
  cout << answer / 100.0 << "\n";
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
