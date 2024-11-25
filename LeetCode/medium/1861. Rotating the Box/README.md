# 1861. Rotating the Box

[링크](https://leetcode.com/problems/rotating-the-box/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열 box의 크기를 R \* C라 하자.

모든 칸을 순회하며 각 좌표마다 이동을 직접 수행할 경우 O(R \* C^2)의 시간 복잡도가 필요하다.

다음 이동 포인터를 관리해 이동을 구현할 경우 O(R \* C)의 시간 복잡도가 필요하다.

### 공간 복잡도

정답 배열에 O(R \* C)의 공간 복잡도가 필요하다.

### 이동 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     200      |  O(R \* C)  |  O(R \* C)  |

각 경우마다 블록의 이동을 시뮬레이션을 이용해 구현한다.

이 때 다음 이동 포인터를 관리해 이동을 구현한다.

```cpp
vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
  int rows = box.size(), cols = box[0].size();

  vector<vector<char>> answer(cols, vector<char>(rows, '.'));
  for (int y = 0; y < rows; y++) {
    int count = 0;

    int lastI = cols - 1;
    while (lastI > 0 && box[y][lastI] == '*') {
      lastI--;
    }
    for (int x = cols - 1; x >= 0; x--) {
      if (box[y][x] != '#') {
        if (box[y][x] == '*') {
          lastI = x - 1;
          while (lastI > 0 && box[y][lastI] == '*') {
            lastI--;
          }
        }
        continue;
      }

      box[y][x] = '.';
      box[y][lastI] = '#';

      lastI--;
      while (lastI > 0 && box[y][lastI] == '*') {
        lastI--;
      }
    }

    for (int x = 0; x < cols; x++) {
      answer[x][rows - 1 - y] = box[y][x];
    }
  }

  return answer;
}
```

## 고생한 점
