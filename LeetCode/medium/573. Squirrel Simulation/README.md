# 573. Squirrel Simulation

[링크](https://leetcode.com/problems/squirrel-simulation/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 도토리의 좌표의 갯수를 N이라 하자.

모든 경우를 수행할 경우 O(N!)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

도토리를 주운 후에는 무조건 트리로 가야하며 트리에서 다음 도토리를 주우러 갈 수 있다.

이 경우 다람쥐가 시작 도토리를 고르는 경우에 대해서만 탐색하면 되므로 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

별도의 배열을 사용하지 않아도 되므로 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      18      |    O(N)     |    O(1)     |

다람쥐는 도토리를 주운 후 나무로 가야한다. 이후 나무에서 다른 도토리로 이동을 반복한다.

즉 다람쥐가 결국에 트리에서 도토리까지 이동하는 경우들은 항상 일어나므로 이 경우만 고려한다.

트리-도토리-트리-도토리 순서로 모두 이동하는 거리의 합을 S라 하자.

여기서 다람쥐가 어떤 도토리를 처음에 고르느냐에 따라서

- 트리-도토리까지의 거리를 S에서 빼고
- 다람쥐-도토리 까지의 거리를 S에 더한 값이

해당 도토리를 골랐을 때의 총 이동 거리가 된다.

따라서 각 도토리별로 시작 도토리로 설정했을 때의 총 이동 거리를 구하고 이 중 최소값을 구한다.

```cpp
int getDist(vector<int>& from, vector<int>& to) {
  return abs(from[0] - to[0]) + abs(from[1] - to[1]);
}

int minDistance(int height, int width, vector<int>& tree,
                vector<int>& squirrel, vector<vector<int>>& nuts) {
  int nutSize = nuts.size();

  int sum = 0;
  int diff = INT_MAX;
  for (vector<int>& nut : nuts) {
    int sdist = getDist(squirrel, nut);
    int dist = getDist(tree, nut);

    diff = min(diff, sdist - dist);
    sum += dist * 2;
  }

  return sum + diff;
}
```

## 고생한 점
