# 427. Construct Quad Tree

[링크](https://leetcode.com/problems/construct-quad-tree/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 정방 행렬의 한 변의 크기를 N이라 하자.

현재 구역에 대해 압축 가능한지 판단하기 위해 각 좌표들을 순회해야 한다.

따라서 최소 O(N^2)의 시간 복잡도를 사용한다.

분할 정복을 사용할 경우 각 구역을 절반씩 탐색 가능하다. 이에 O(log_2(N))의 시간 복잡도를 사용한다.

따라서 분할 정복을 사용할 경우 O(N^2 \* log_2(N))의 시간 복잡도를 사용한다.

여기서 중복해서 검사하는 로직을 최적화 할 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

call stack에 O(log_2(N))의 공간 복잡도를 사용한다.

### 분할 정복

| 내 코드 (ms) |    시간 복잡도     | 공간 복잡도 |
| :----------: | :----------------: | :---------: |
|      13      | O(N^2 \* log_2(N)) | O(log_2(N)) |

현재 구역을 4개의 구역으로 나눠 탐색할 수 있다.

만약 현재 구역이 압축 가능하다면 하나의 노드로 압축한다.

그렇지 않은 경우 4개의 구역으로 나눠 탐색한다.

탐색을 재귀호출로 구현하며, 반환값을 현재 구역의 노드로 설정한다.

```cpp
vector<vector<int>> grid;

bool isAreaSameValue(int x1, int y1, int length) {
  for (int x = x1; x < x1 + length; x++) {
    for (int y = y1; y < y1 + length; y++) {
      if (grid[x][y] != grid[x1][y1]) return false;
    }
  }
  return true;
}

Node* recursive(int x1, int y1, int length) {
  if (isAreaSameValue(x1, y1, length)) {
    return new Node(grid[x1][y1], true);
  }

  Node* root = new Node(false, false);

  int half = length / 2;

  root->topLeft = recursive(x1, y1, half);
  root->topRight = recursive(x1, y1 + half, half);
  root->bottomLeft = recursive(x1 + half, y1, half);
  root->bottomRight = recursive(x1 + half, y1 + half, half);

  return root;
}

Node* construct(vector<vector<int>>& grid) {
  int length = grid.size();
  this->grid = grid;

  return recursive(0, 0, length);
}
```

### 분할 정복 (시간 최적화)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      17      |   O(N^2)    | O(log_2(N)) |

현재 구역을 4개로 나눈 서브 구역이 있다고 하자.

만약 서브 구역이 모두 리프 노드이고 (하나의 노드로 압축가능한 구역) 값이 모두 같은 경우 현재 구역은 하나의 노드로 압축 가능하다.

따라서 압축 가능한지 판별하는 시간을 줄일 수 있다.

이 경우 최종적으로 각 좌표들을 한번 씩 방문하는 모양이 되므로 O(N^2)의 시간 복잡도를 사용한다.

```cpp
vector<vector<int>> grid;

Node* recursive(int x1, int y1, int length) {
  // leaf case
  if (length == 1) {
    return new Node(grid[x1][y1], true);
  }

  int half = length / 2;

  Node* topLeft = recursive(x1, y1, half);
  Node* topRight = recursive(x1, y1 + half, half);
  Node* bottomLeft = recursive(x1 + half, y1, half);
  Node* bottomRight = recursive(x1 + half, y1 + half, half);

  if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf &&
      bottomRight->isLeaf && topLeft->val == topRight->val &&
      topRight->val == bottomLeft->val &&
      bottomLeft->val == bottomRight->val) {
    return new Node(topLeft->val, true);
  }

  return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
}

Node* construct(vector<vector<int>>& grid) {
  int length = grid.size();
  this->grid = grid;

  return recursive(0, 0, length);
}
```

## 고생한 점
