# 17679. [1차] 프렌즈4블록

[링크](https://programmers.co.kr/learn/courses/30/lessons/17679)

| 난이도 | 완료(명) |
| :----: | :------: |
|  lv2   |   2361   |

## 설계

### 시간 복잡도

N의 최대 크기는 30이다. 최악의 경우의 시간 복잡도는 모든 경우에서 폭탄이 터진다고 가정하는 경우이므로,

터질 블록을 검색하는데 N^2, 모든 경우에서 연쇄적으로 블록이 터지는 경우 N^2 이므로

```cpp
30^4 = 810,000
```

이므로 제한시간 내에 충분하다.

### 공간 복잡도

배열이 문자열의 형태로 들어온다.

이 문자열의 각 char 요소 값 그대로를 사용하고, 빈 블록은 0을 이용해 나타낸다.

따라서 30^2 크기의 int형 2차원 배열로 충분하다.

### 함수

다음과 같은 함수를 생성한다.

- 파괴해야 할 위치를 탐색하는 함수 (파괴해야 할 위치들을 반환)
- 파괴하는 함수 (파괴한 블록의 개수를 반환)
- 블록을 당기는 함수

```cpp
while (true) {
  vector<Axis> destoryList = detect();
  if (destoryList.size() == 0) break;

  answer += destory(destoryList);
  pull();
}
```

### 당기는 함수

모든 x좌표에 대해서, y의 끝에서 부터 탐색을 진행한다.

- 현재 좌표의 값이 0인 경우,
- 남은 y좌표를 탐색하며 한칸식 밑으로 당긴다.
- 이를 끝까지 반복.
  - 이 때 남은 좌표의 값들이 전부 0인 경우 다음 x좌표로 넘어감

```cpp
void pull() {
  for (int x = 0; x < limit.x; x++) {
    for (int y = limit.y - 1; y >= 0; y--) {
      while (board[y][x] == 0) {
        int zeroCount = 0;

        for (int y2 = y - 1; y2 >= 0; y2--) {
          if (board[y2][x] != 0) zeroCount += 1;
          board[y2 + 1][x] = board[y2][x];
        }
        board[0][x] = 0;

        if (zeroCount == 0) break;
      }
    }
  }
}
```

## 고생한 점
