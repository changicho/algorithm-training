# 305. Number of Islands II

[링크](https://leetcode.com/problems/number-of-islands-ii/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

행의 개수를 M, 열의 개수를 N, 입력받은 위치들의 개수를 P라 하자.

섬이 총 몇개있는지 (연결된 섬은 하나로 취급) 탐색하는 데 BFS를 이용할 경우 O(N \* M)의 시간 복잡도로 판별이 가능하다.

이를 모든 position마다 반복할 경우 최악의 경우 시간 복잡도는 O(N \* M \* P)이므로 제한시간 내에 불가능하다.

유니온 파인드를 이용해 연결된 땅들을 집합으로 묶는다.

이후 집합의 개수 (부모의 개수)를 땅을 생성할 때마다 증가시키고, 연결시킬 때마다 감소시켜 O(1)에 참조 가능하게 만든다.

유니온 파인드를 사용하기 위해 배열을 초기화 하는데 O(N \* M)의 시간 복잡도가 소요된다.

이후 merge, find를 수행하는데 애크만 상수 시간복잡도가 소요되므로 이는 거의 상수이다.

따라서 position의 순회와 parent초기화에 시간 복잡도를 소요한다.

이 경우 시간 복잡도는 O(P + M \* N)의 시간 복잡도가 소요된다.

### 공간 복잡도

유니온 파인드를 사용할 경우 O(N \* M)크기의 공간 복잡도를 사용한다.

### 정리

| 내 코드 (ms) |  시간 복잡도  | 공간 복잡도 |
| :----------: | :-----------: | :---------: |
|      76      | O(P + M \* N) |  O(N \* M)  |

유니온 파인드를 이용해 땅을 채울때 마다 인접한 땅과 연결한다.

이 때 초기에 모든 땅(노드)의 부모를 초기화 하지 않고 땅을 채울때만 부모를 초기화한다.

이는 땅을 채울때 마다 부모의 수를 찾아 정답에 삽입해야 하므로, 모든 땅을 순회하며 부모를 세지 않고 바로 찾기 위함이다.

또한 이전에 땅을 채운 좌표에 다시 땅을 채우는 경우 이를 무시한다.

이는 해당 좌표에 대한 부모는 이미 갱신되었을수도 있기 때문이다. (부모의 수도 이미 증가함)

```cpp
// data structure definition
vector<int> parents;
// we use count variable to find parents number O(1)
int count = 0;

// when we set parent, increase count
void setParent(int node) {
  parents[node] = node;
  count += 1;
}
```

이후 merge할 때마다 두 노드의 부모가 다른 경우 count를 감소시킨다.

```cpp
int find(int a) {
  if (parents[a] == a) return a;

  return parents[a] = find(parents[a]);
}

void merge(int a, int b) {
  a = find(a);
  b = find(b);
  // if a, b has same parent return
  if (a == b) return;

  // set lower value to be parent
  if (a > b) swap(a, b);
  parents[b] = a;
  // we merged it so decrease count
  count -= 1;
}
```

또한 position에서 y, x에 대해서 index로 변환하기 위해 다음과 같이 사용한다.

```cpp
int index = y * n + x;
```

이를 이용해 구현할 경우 다음과 같다.

```cpp
vector<int> numIslands2(int m, int n, vector<vector<int>> &positions) {
  int size = m * n;
  // initialize parents. -1 means there are no island in that index (axis)
  parents.resize(size, -1); // O(M * N)

  vector<int> answer;
  // iterate all position
  for (vector<int> &position : positions) { // O(P)
    int y = position[0], x = position[1];
    // convert axis to index
    int index = y * n + x;

    // if there are only island in that axis, skip it
    if (parents[index] != -1) {
      answer.push_back(count);
      continue;
    }
    // make parent
    setParent(index);

    // iterate 4 direction
    for (vector<int> &dir : dirs) {
      int nextY = dir[0] + y;
      int nextX = dir[1] + x;

      int nextIndex = nextY * n + nextX;

      if (nextY < 0 || nextY >= m || nextX < 0 || nextX >= n) continue;
      // if there are no island in that axis
      if (parents[nextIndex] == -1) continue;

      // if next axis is valid, merge it
      merge(index, nextIndex); // O(1)
    }

    // push current count to answer
    answer.push_back(count);
  }

  return answer;
}
```

## 고생한 점
