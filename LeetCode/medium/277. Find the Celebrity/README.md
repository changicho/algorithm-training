# 277. Find the Celebrity

[링크](https://leetcode.com/problems/find-the-celebrity/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 개수를 N이라 하자.

한 노드가 celeb인지 구하는 데 O(N)의 시간 복잡도가 소요된다.

이를 모든 노드에 대해 수행해 브루트 포스 방법으로 구할 경우 O(N^2)의 시간 복잡도가 소요된다.

혹은 celeb이 될 수 있는 노드만 찾아 해당 노드에 대해서만 celeb인지 구할 수 있다.

이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

한 노드가 celeb인지 구하는 데 필요한 공간 복잡도는 O(1)이다.

만약 knows 함수를 캐싱할 경우 O(N^2)의 공간 복잡도가 필요하다.

### 브루트포스

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     144      |   O(N^2)    |    O(1)     |

각 노드가 celeb인지는 다음으로 알 수 있다.

한 노드 A에 대해서 다른 모든 노드 B에 대해서 A는 B를 모르고, B는 모두 A를 안다.

이를 각 노드별로 모두 반복하며 celeb이 있는지를 검사한다.

```cpp
bool isCelebrity(int node, int limit) {
  for (int next = 0; next < limit; next++) {
    if (next == node) continue;

    if (knows(next, node) && !knows(node, next)) continue;
    return false;
  }
  return true;
}

int findCelebrity(int n) {
  for (int i = 0; i < n; i++) {
    if (isCelebrity(i, n)) return i;
  }

  return -1;
}
```

knows에 대해서 memoization을 적용할 수 있다.

```cpp
unordered_map<int, unordered_map<int, bool>> um;

bool knowsHash(int a, int b) {
  if (um.find(a) != um.end() && um[a].find(b) != um[a].end()) {
    return um[a][b];
  }
  return um[a][b] = knows(a, b);
}
```

### 그리디

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     120      |    O(N)     |    O(1)     |

각 노드에 대해서 celeb이 될 수 있는 노드를 찾아보자.

celeb이 될 수 있는 노드와 현재 노드를 비교했을 때 celeb 추정 노드가 현재 노드를 알고, 현재 노드가 celeb 추정 노드를 모를 경우 celeb 추정 노드를 현재 노드로 갱신한다.

여기서 실제 celeb 노드는 다른 모든 노드들을 알지 못하므로 최종적으로 celeb 추정 노드는 celeb 노드가 되거나 다른 노드가 된다.

이때 해당 노드에 대해서 실제로 celeb 노드인지를 판별한다.

```cpp
bool isCelebrity(int node, int limit) {
  for (int next = 0; next < limit; next++) {
    if (next == node) continue;

    if (!knows(next, node) || knows(node, next)) return false;
  }
  return true;
}

int findCelebrity(int n) {
  int celebrityCandidate = 0;
  for (int i = 1; i < n; i++) {
    if (knows(celebrityCandidate, i)) {
      celebrityCandidate = i;
    }
  }
  if (isCelebrity(celebrityCandidate, n)) {
    return celebrityCandidate;
  }
  return -1;
}
```

## 고생한 점
