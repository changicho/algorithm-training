# D - Goin' to the Zoo

[링크](https://atcoder.jp/contests/abc404/tasks/abc404_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

동물원의 수를 N, 동물의 수를 M이라 하자. (N <= 10, M <= 100)

동물원의 수가 작으므로 동물원을 방문하는 경우의 수에 대해 완전 탐색을 수행할 수 있다.

이때 동물원을 방문하는 경우의 수는 3가지 이므로 O(3^N)의 시간 복잡도를 가진다.

각 동물원마다 동물을 가진 경우를 구하는데 O(M)의 시간이 걸린다.

따라서 총 시간 복잡도는 O(3^N \* M)이다.

### 공간 복잡도

완전 탐색에 재귀호출을 사용할 경우 O(N)의 공간 복잡도를 가진다.

각 동물만큼의 마스크를 가져야 하므로 O(M)의 공간 복잡도를 가진다.

각 동물원마다 비용이 최대 10^9 이므로 int형을 벗어난다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      10      | O(3^N \* M) |  O(N + M)   |

각 동물원을 2번 이상 방문하는 경우는 2번 방문하는 경우와 동일하다.

따라서 각 동물원을 0 ~ 2번만 방문하는 경우에 대해 탐색하면된다.

각 동물원마다 탐색하는 경우의 수를 모두 탐색하며, 이후 각 동물원을 방문한 경우에 대해서 동물들을 각각 만난 수를 구한다.

각 동물들을 모두 2번이상 만난 경우 정답을 갱신한다.

```cpp
string add(string &a, string &b) {
  int size = a.size();
  string result(size, '0');
  for (int i = 0; i < size; i++) {
    int sum = (a[i] - '0') + (b[i] - '0');
    if (sum >= 2) {
      result[i] = '2';
    } else {
      result[i] = '0' + sum;
    }
  }
  return result;
}

long long solution(int n, int m, vector<long long> &costs, vector<vector<int>> &animals) {
  vector<string> zoos(n, string(m, '0'));
  for (int animal = 0; animal < m; animal++) {
    string mask = string(m, '0');
    mask[animal] = '1';

    for (int &zoo : animals[animal]) {
      zoos[zoo - 1] = add(zoos[zoo - 1], mask);
    }
  }

  string END_CONDITION = string(m, '2');

  long long answer = LLONG_MAX;

  function<void(int, string, long long)> dfs = [&](int index, string mask, long long cost) {
    if (index == n) {
      if (mask == END_CONDITION) {
        answer = min(answer, cost);
      }

      return;
    }

    dfs(index + 1, mask, cost);

    string new_mask = mask;
    long long new_cost = cost;
    for (int i = 1; i <= 2; i++) {
      new_mask = add(new_mask, zoos[index]);
      new_cost += costs[index];

      dfs(index + 1, new_mask, new_cost);
    }
  };

  dfs(0, string(m, '0'), 0);

  return answer;
}
```

## 고생한 점
