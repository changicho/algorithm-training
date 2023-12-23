# 661. Image Smoother

[링크](https://leetcode.com/problems/image-smoother/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

2차원 배열 img의 원소의 갯수를 N이라 하자.

각 좌표마다 주변 8방향을 탐색해야 하므로 시간 복잡도는 O(N) 이다.

### 공간 복잡도

정답으로 반환할 배열을 새로 생성할 경우 O(N)의 공간 복잡도가 필요하다.

img의 원소의 값의 범위가 1 ~ 256 이므로 해당 값에 정답을 같이 저장할 수 있다. 이 경우 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      48      |    O(N)     |    O(N)     |

각 좌표를 순회하며 인접 좌표들의 합과 수를 이용해 정답을 갱신한다.

```cpp
int calc(vector<vector<int>>& img, int y, int x) {
  int rows = img.size(), cols = img[0].size();
  int count = 0;
  double sum = 0;

  for (int dy = -1; dy <= 1; dy++) {
    for (int dx = -1; dx <= 1; dx++) {
      int ny = y + dy, nx = x + dx;
      if (ny < 0 || ny >= rows || nx < 0 || nx >= cols) continue;
      count++;
      sum += img[ny][nx];
    }
  }

  return sum / count;
}

vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
  int rows = img.size(), cols = img[0].size();

  vector<vector<int>> answer(rows, vector<int>(cols));

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      answer[y][x] = calc(img, y, x);
    }
  }
  return answer;
}
```

### 완전 탐색 (공간 최적화)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      46      |    O(N)     |    O(1)     |

img의 원소의 값의 범위는 1 ~ 256이다.

따라서 각 좌표에서 계산한 정답을 함께 저장한 뒤, 해당 값을 분리해 이후 좌표에 계산시 사용할 수 있다.

```cpp
int calc(vector<vector<int>>& img, int y, int x) {
  int rows = img.size(), cols = img[0].size();
  int count = 0;
  double sum = 0;

  for (int dy = -1; dy <= 1; dy++) {
    for (int dx = -1; dx <= 1; dx++) {
      int ny = y + dy, nx = x + dx;
      if (ny < 0 || ny >= rows || nx < 0 || nx >= cols) continue;
      count++;
      sum += img[ny][nx] % 256;
    }
  }

  return sum / count;
}

vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
  int rows = img.size(), cols = img[0].size();

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      img[y][x] += calc(img, y, x) * 256;
    }
  }

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      img[y][x] /= 256;
    }
  }
  return img;
}
```

## 고생한 점
