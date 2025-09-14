# F - Erase between X and Y

[링크](https://atcoder.jp/contests/abc421/tasks/abc421_f)

| 난이도 |
| :----: |
|  525   |

## 설계

### 시간 복잡도

입력받은 쿼리의 수를 Q라 하자.

매번 모든 경우를 직접 구할 경우 O(Q^2)의 시간 복잡도를 사용한다.

연결 리스트를 사용해 삭제되는 부분들과 연결을 관리할 경우 O(Q)의 시간 복잡도를 사용한다.

이 때 삭제되는 부분을 찾을 때 양 방향 탐색을 동시에 진행하지 않는 경우 제한시간 내에 불가능하다.

### 공간 복잡도

연결 리스트에 O(Q)의 공간 복잡도를 사용한다.

### 연결 리스트

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      93      |    O(Q)     |    O(Q)     |

입력받은 쿼리를 살펴보면 배열을 생성할 때 특정 index의 뒤에 삽입하며, 삭제시 특정 구간을 전부 삭제한다.

이를 빠르게 처리하기 위해 연결 리스트로 관리한다.

이 때 이미 삭제된 노드들은 이후 쿼리에서도 삭제되어있으므로,

한번 삭제 시킬 때 노드들의 합을 구하고 연결 관계를 끊어버릴 경우, 이후 탐색에서 무시해도 된다.

따라서 각 삭제 쿼리 마다 삭제되는 노드들의 합을 매번 구해도 전체 쿼리에서의 삭제의 시간 복잡도는 O(Q)가 된다.

이 때 삭제되는 노드 구간에 대해 양방향 탐색을 진행해야 하며, 각 방향 중 일찍 끝나는 방향으로 답을 구해야 한다.

만약 매번 양방향 탐색을 직렬로 수행할 경우, 각 삭제 쿼리마다 최악의 경우 O(Q)의 시간 복잡도를 사용하므로 전체 시간 복잡도는 O(Q^2)가 되어 제한시간 내에 불가능하다.

따라서 병렬적으로 양방향 탐색을 진행하며 먼저 탐색이 끝나는 방향으로 답을 구해야 한다.

```cpp
vector<long long> solution(int size, vector<vector<int>> &queries) {
  vector<long long> answer;

  vector<int> nexts(size + 1, -1);

  for (int i = 0; i < size; i++) {
    int cur = i + 1;
    vector<int> &q = queries[i];

    int type = q[0];
    if (type == 1) {
      int x = q[1];

      int next = nexts[x];
      nexts[x] = cur;
      nexts[cur] = next;
    } else {
      int x = q[1], y = q[2];

      // x -> y
      int curX = nexts[x];
      long long sumX = 0;
      // y -> x
      int curY = nexts[y];
      long long sumY = 0;

      while (true) {
        if (curX == y) {
          answer.push_back(sumX);
          nexts[x] = y;
          break;
        }
        if (curY == x) {
          answer.push_back(sumY);
          nexts[y] = x;
          break;
        }

        if (curX != -1) {
          sumX += curX;
          curX = nexts[curX];
        }
        if (curY != -1) {
          sumY += curY;
          curY = nexts[curY];
        }
      }
    }
  }

  return answer;
}
```

## 고생한 점
