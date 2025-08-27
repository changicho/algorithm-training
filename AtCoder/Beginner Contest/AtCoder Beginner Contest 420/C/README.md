# C - Sum of Min Query

[링크](https://atcoder.jp/contests/abc420/tasks/abc420_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

두 배열의 크기를 N, 쿼리의 수를 Q라 하자.

각 쿼리마다 직접 정답을 구할 경우 O(N \* Q)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

미리 합을 구한 뒤 변화하는 합만 반영할 경우 O(N + Q)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(Q)의 공간 복잡도를 사용한다.

### diff update

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      67      |  O(N + Q)   |    O(Q)     |

각 쿼리마다 숫자를 변환한 뒤 합을 구하지 않고 미리 구한 합에서 변화하는 부분만 반영한다.

현재 변화하는 index에 해당하는 A, B의 원소 중 작은 값을 미리 합에서 뺀다.

이후 쿼리에 따라 원소를 변화시킨 뒤, 해당 index에 해당하는 A, B의 원소 중 작은 값을 합에 더한다.

```cpp
vector<long long> solution(int size, vector<int> &a, vector<int> &b, int qSize, vector<vector<int>> &queries) {
  vector<long long> answer;

  long long sum = 0;
  for (int i = 0; i < size; i++) {
    sum += min(a[i], b[i]);
  }

  for (vector<int> &query : queries) {
    int c = query[0], x = query[1], y = query[2];

    sum -= min(a[x], b[x]);
    if (c == 0) {
      a[x] = y;
    } else {
      b[x] = y;
    }

    sum += min(a[x], b[x]);
    answer.push_back(sum);
  }

  return answer;
}
```

## 고생한 점
