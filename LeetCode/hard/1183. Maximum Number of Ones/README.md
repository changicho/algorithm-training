# 1183. Maximum Number of Ones

[링크](https://leetcode.com/problems/maximum-number-of-ones/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 높이와 너비를 R, C, 그리고 sideLength의 길이를 N이라 하자.

sideLength크기의 정사각형의 패턴이 반복될경우 모든 경우에 같은 수의 maxOnes까지 채울 수 있다.

여기서 각 패턴의 자리들 중 가장 많이 R,C크기의 직사각형에 포함되는 자리와 갯수를 maxOnes개 구하고 이를 더하면 된다.

각 좌표를 모두 순회하며 패턴을 채울경우 O(R \* C)의 시간 복잡도를 사용한다. 이를 좌표의 길이의 차를 이용해 계산할 경우 O(1)의 시간 복잡도를 사용한다.

각 패턴에서 가장 많은 빈도좌표와 count를 정렬로 구할 경우 O(N^2 \* log_2(N^2))의 시간 복잡도를 사용한다.

### 공간 복잡도

패턴의 count를 채울 공간이 필요하므로 O(N^2)의 공간 복잡도를 사용한다.

### 그리디 알고리즘 & 패턴 카운팅

| 내 코드 (ms) |          시간 복잡도          | 공간 복잡도 |
| :----------: | :---------------------------: | :---------: |
|      3       | O(R \* C + N^2 \* log_2(N^2)) |   O(N^2)    |

주어진 height, width에 대해서 가능한 모든 좌표를 순회하며 패턴의 갯수를 채운다.

이후 각 패턴의 좌표의 갯수들 중 가장 많은 maxOnes개를 더한다.

```cpp
int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
  int pattern[101][101] = {
      0,
  };

  for (int y = 0; y < height; y += sideLength) {
    for (int x = 0; x < width; x += sideLength) {
      // y,x;
      for (int i = 0; i < sideLength && y + i < height; i++) {
        for (int j = 0; j < sideLength && x + j < width; j++) {
          pattern[i][j]++;
        }
      }
    }
  }

  int answer = 0;
  vector<int> counts;
  for (int y = 0; y < sideLength; y++) {
    for (int x = 0; x < sideLength; x++) {
      counts.push_back(pattern[y][x]);
    }
  }
  sort(counts.begin(), counts.end());

  for (int i = 0; i < maxOnes; i++) {
    int cur = counts.back();
    counts.pop_back();
    answer += cur;
  }
  return answer;
}
```

### 그리디 알고리즘 & 패턴 카운팅 (시간 최적화)

| 내 코드 (ms) |     시간 복잡도      | 공간 복잡도 |
| :----------: | :------------------: | :---------: |
|      5       | O(N^2 \* log_2(N^2)) |   O(N^2)    |

위 방법에서 각 좌표마다의 count를 구할 때 주어진 길이와 값들을 이용할 수 있다.

```cpp
int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
  vector<int> counts;
  for (int y = 0; y < sideLength; y++) {
    for (int x = 0; x < sideLength; x++) {
      int count = (1 + (width - 1 - x) / sideLength) *
                  (1 + (height - 1 - y) / sideLength);
      counts.push_back(count);
    }
  }
  sort(counts.begin(), counts.end());

  int answer = 0;
  for (int i = 0; i < maxOnes; i++) {
    int cur = counts.back();
    counts.pop_back();
    answer += cur;
  }
  return answer;
}
```

## 고생한 점
