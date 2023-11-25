# Islands

[링크](https://www.acmicpc.net/problem/5885)

| 난이도 | 정답률(\_%) | 시간 제한(초) |
| :----: | :---------: | :-----------: |
| 골드 V |   52.564    |       1       |

## 설계

### 시간 복잡도

입력받은 높이들의 수를 N이라 하자. 높이의 범위를 M라 하자.

모든 경우를 시뮬레이션 할 경우 O(N \* M)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

정렬 이후 높이가 낮은 순으로 순회하며 각 높이마다 물을 채워넣어 남은 섬의 갯수를 알 수 있다.

이 경우 정렬에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

각 섬들이 물에 잠겻는지 여부를 판단하기 위해 O(N)의 공간 복잡도를 사용한다.

## 정렬

|   시간 복잡도    | 공간 복잡도 |
| :--------------: | :---------: |
| O(N \* log_2(N)) |    O(N)     |

물은 각 높이들마다 채워넣었을 때 정답을 변화시킬 수 있다.

따라서 각 높이들마다 해당 높이의 x좌표들을 모두 물에 잠기게 처리하고 남은 섬의 갯수를 센다.

이 때 물에 잠긴 좌표를 x라 할 때 x-1, x+1 좌표가 물에 잠겨있지 않다면 새로운 섬이 생긴것이다.

따라서 물에 잠긴 좌표 양 옆의 좌표들이 잠겼는지를 판단하기 위해 boolean 배열을 사용한다.

이후 높이들을 물에 잠그며 섬의 갯수를 세는 과정을 반복한다.

```cpp
int solution(vector<int> &heights) {
  // 100,000
  int size = heights.size();

  vector<bool> underwater(size, false);

  map<int, vector<int>> orderedX;

  for (int x = 0; x < size; x++) {
    orderedX[heights[x]].push_back(x);
  }

  int numIslands = 1;
  int maxIslands = 1;

  for (auto &[h, xs] : orderedX) {
    for (int &x : xs) {
      underwater[x] = true;
      bool landToLeft = (x > 0 && !underwater[x - 1]);
      bool landToRight = (x < size - 1 && !underwater[x + 1]);

      if (landToLeft && landToRight) {
        numIslands++;
      } else if (!landToLeft && !landToRight) {
        numIslands--;
      }
    }
    maxIslands = max(maxIslands, numIslands);
  }

  return maxIslands;
}
```

## 고생한 점
