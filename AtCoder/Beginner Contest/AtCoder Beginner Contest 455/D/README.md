# D - Card Pile Query

[링크](https://atcoder.jp/contests/abc455/tasks/abc455_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

카드의 수를 N, 쿼리의 수를 Q라 하자.

각 이동마다 카드를 직접 이동시키는 경우 O(N \* Q)의 시간 복잡도를 사용한다.

연결 리스트를 사용해 카드의 바로 아래 카드만 기억할 경우 O(N + Q)의 시간 복잡도를 사용한다.

### 공간 복잡도

연결 리스트에 O(N)의 공간 복잡도를 사용한다.

### 연결 리스트

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      45      |  O(N + Q)   |    O(N)     |

각 카드별로 바로 아래 있는 카드의 번호를 기억하는 배열을 관리한다.

이 때 맨 아래에 아무것도 없을 경우 위치를 기억하기 위해 음수로된 index를 지정한다.

각 쿼리마다 카드를 이동시킨 후, 마지막에 1번카드부터 어느위치에 존재하는지 탐색한다.

이 때 바로 아래 배열을 탐색할 때 중복방문을 제거하기 위해 DFS로 탐색하며 카드뭉치 index의 위치로 배열의 값을 모두갱신한다.

```cpp
vector<long long> solution(int n, int qSize, vector<int>& c, vector<int>& p) {
  vector<int> parents(n + 1);

  // -i is the pile number
  for (int i = 1; i <= n; i++) {
    parents[i] = -i;
  }

  function<int(int)> find = [&](int i) {
    if (i < 0) {
      return i;
    }

    return parents[i] = find(parents[i]);
  };

  for (int i = 0; i < qSize; i++) {
    int card = c[i], to = p[i];

    parents[card] = to;
  }

  vector<long long> answer(n);
  for (int i = 1; i <= n; i++) {
    int target = find(i);

    answer[abs(target) - 1]++;
  }

  return answer;
}
```

## 고생한 점
