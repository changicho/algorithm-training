# 2612. Minimum Reverse Operations

[링크](https://leetcode.com/problems/minimum-reverse-operations/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

선택 가능한 subArray의 크기를 K라 할 때, 이동 가능한 좌표는 K가 홀수, 짝수인지 여부에 따라 다르다.

각 원소들에 대해 BFS를 수행할 경우 O(N \* K)의 시간 복잡도가 소요된다. 이는 제한시간 내에 불가능하다.

각 좌표들을 set으로 저장 후, 이미 방문한 좌표는 탐색 과정에서 제외할 수 있다.

이 경우 최종적으로 각 좌표들을 한번씩 방문하므로 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

방문 좌표들을 별도로 저장할 경우 O(N)의 공간 복잡도를 사용한다.

### BFS with set

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     555      | O(N \* log_2(N)) |    O(N)     |

입력받은 K에 대해 다음과 같은 이동이 가능하다.

- K가 홀수인 경우 : 좌표를 짝수만큼 이동 가능하다.
- K가 짝수인 경우 : 좌표를 홀수만큼 이동 가능하다.

이는 아래와 같이 subArray의 범위를 조정하며 이동가능한 위치를 탐색하면 알 수 있다.

```
[...left, 0, 0, 0, 1, 0, 0, 0, ...right];

// K = 4 (짝수)
[0, 0, 0, 1][0, 0, 1, 0][0, 1, 0, 0][1, 0, 0, 0];

// K = 5 (홀수)
[0, 0, 0, 0, 1][0, 0, 0, 1, 0][0, 0, 1, 0, 0][0, 1, 0, 0, 0][1, 0, 0, 0, 0];
```

좌우 대칭으로 이동시킨다 할 때 위와같이 이동이 가능하다.

따라서 K와 현재 위치에 대해서 다음 이동하는 좌표들이 홀수, 짝수인지 구분할 수 있다.

각 경우들마다 짝수, 홀수 로만 이동 가능하므로 각 좌표들을 짝수, 홀수에 대해 묶는다.

이후 각 좌표들을 BFS를 이용해 탐색하며 방문했던 좌표들은 앞으로의 탐색 목록에서 삭제한다.

각 과정에서 이동 가능 범위 내의 좌표만 탐색하며 이는 범위에 해당하는 좌표를 뽑으면 되므로 이분 탐색으로 찾을 수 있다.

이를 위해 각 좌표들을 set으로 저장해 관리한다.

이 때 이동 가능한 범위가 (subArray를 만들 때의 범위) 0 ~ N-1 이므로 이를 벗어나는 좌표들은 탐색하지 않는다.

```cpp
pair<int, int> getRange(int n, int pivot, int k) {
  int l1 = max(0, pivot - k + 1);
  int r1 = l1 + k - 1;

  int r2 = min(n - 1, pivot + k - 1);
  int l2 = r2 - k + 1;

  int left = r1 - (pivot - l1);
  int right = l2 + (r2 - pivot);
  return {left, right};
}

vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
  vector<int> answer(n, INT_MAX);

  for (int& ban : banned) {
    answer[ban] = -1;
  }

  set<int> indexes[2];
  for (int i = 0; i < n; i++) {
    if (answer[i] == -1) continue;
    indexes[i % 2].insert(i);
  }

  int step = 0;
  queue<int> q;
  q.push(p);

  answer[p] = 0;

  while (!q.empty()) {
    int size = q.size();

    while (size--) {
      int cur = q.front();
      q.pop();

      pair<int, int> range = getRange(n, cur, k);

      int leftFar = range.first, rightFar = range.second;
      int isOdd = (cur % 2 + ((k + 1) % 2)) % 2;

      auto leftIt = indexes[isOdd].lower_bound(leftFar);
      auto rightIt = indexes[isOdd].upper_bound(rightFar);

      for (auto it = leftIt; it != rightIt; it++) {
        int next = *it;

        if (answer[next] != INT_MAX) continue;
        answer[next] = step + 1;
        q.push(next);
      }

      indexes[isOdd].erase(leftIt, rightIt);
    }

    step++;
  }

  for (int i = 0; i < n; i++) {
    if (answer[i] == INT_MAX) {
      answer[i] = -1;
    }
  }
  return answer;
}
```

## 고생한 점
