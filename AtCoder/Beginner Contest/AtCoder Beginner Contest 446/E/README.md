# E - Multiple-Free Sequences

[링크](https://atcoder.jp/contests/abc446/tasks/abc446_e)

| 난이도 |
| :----: |
|  450   |

## 설계

### 시간 복잡도

입력받은 수를 M, A, B라 하자.

각 숫자 순열에 대해서 M으로 떨어지는지 확인해야하며, 각 과정마다 나머지값만을 사용할 수 있다.

이 경우 총 경우의 수를 계산하는데 O(M^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 숫자 쌍에 대해서 방문 여부를 저장하는데 O(M^2)의 공간 복잡도를 사용한다.

### 나머지 & 방문 DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |   O(M^2)    |   O(M^2)    |

A, B값은 고정되며 0 ~ (M-1) 범위의 x, y 쌍에 대해서 생성되는 순열을 확인한다.

이 때 각 순열의 값이 M으로 떨어지는지만 확인하면 되므로 각 순열의 값에서 M으로 나눈 나머지만을 사용할 수 있다.

또한 각 순열을 생성할 때 현재값과 직전값만을 사용하므로 해당 두 값의 경우의 수를 다음과 같이 제한할 수 있다.

- x는 0 ~ (M-1) 범위의 값
- y는 0 ~ (M-1) 범위의 값

따라서 모든 경우의 수에 대해 M으로 떨어지는지 DFS로 순열을 생성하며 확인할 수 있다.

이 때 방문배열을 이용해 해당 쌍이 이미 안전한지, 위험한지, 방문중인지 등을 저장하여 중복 계산을 방지할 수 있다.

모든 쌍에 대해서 DFS를 수행한 후 안전한 쌍의 개수를 세어 반환한다.

```cpp
long long solution(int m, int a, int b) {
  long long answer = 0;

  // 0 = unvisited
  // 1 = visiting
  // 2 = safe
  // 3 = bad
  vector<vector<int>> state(m, vector<int>(m, 0));

  function<bool(int, int)> recursive = [&](int x, int y) {
    if (x == 0 || y == 0) return false;

    if (state[x][y] == 2) return true;
    if (state[x][y] == 3) return false;
    if (state[x][y] == 1) {
      return true;
    }
    state[x][y] = 1;

    int nx = y;
    int ny = ((long long)a * y + (long long)b * x) % m;

    bool isFine = recursive(nx, ny);

    state[x][y] = isFine ? 2 : 3;
    return isFine;
  };

  for (int x = 0; x < m; x++) {
    for (int y = 0; y < m; y++) {
      if (state[x][y] == 0) {
        recursive(x, y);
      }
    }
  }

  for (int x = 0; x < m; x++) {
    for (int y = 0; y < m; y++) {
      if (state[x][y] == 2) {
        answer++;
      }
    }
  }

  return answer;
}
```

## 고생한 점
