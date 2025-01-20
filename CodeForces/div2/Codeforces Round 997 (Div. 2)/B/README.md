# B. Find the Permutation

[링크](https://codeforces.com/contest/2056/problem/B)

| 난이도 |
| :----: |
|  1163  |

## 설계

### 시간 복잡도

정점의 갯수를 N이라 하자. (N <= 1,000)

간선 정보의 크기는 N^2 이다.

간선 정보를 이용해 각 정점마다 다른 정점보다 우선하는 순서를 찾을 수 있다.

이에 O(N^2)의 시간 복잡도가 필요하다.

이후 정렬을 사용해 정답을 찾는데 O(N \* log_2(N))의 시간 복잡도가 필요하다.

### 공간 복잡도

정답에 O(N)의 공간 복잡도가 필요하다.

간선 우선 정보에 O(N^2)의 공간 복잡도가 필요하다.

### 정점의 우선순위

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      93      |   O(N^2)    |   O(N^2)    |

간선 정보를 순회하며 현재 정점이 다른 정점보다 우선하는 경우를 찾을 수 있다.

만약 현재 정점과 다른 정점이 0으로 되어있는 경우 둘 사이 정점이 없으며 이는 현재 정점이 다른 정점보다 순서상 뒤에 나와야 함을 의미한다.

이 때 현재 정점보다 작은 index의 정점은 탐색하지 않는다. (큰 index만 탐색)

정점별로 순회하며 현재 정점이 다른 정점보다 우선하는 경우를 찾는다.

이후 정렬을 이용해 정답을 찾는다.

```cpp
vector<int> solution(int n, vector<string>& graph) {
  vector<int> answer;

  vector<unordered_set<int>> behindThan(n);

  for (int node = 0; node < n; node++) {
    for (int next = node + 1; next < n; next++) {
      if (graph[node][next] == '0') behindThan[node].insert(next);
    }
  }

  for (int i = 0; i < n; i++) {
    answer.push_back(i);
  }

  sort(answer.begin(), answer.end(), [&](int a, int b) {
    if (a > b) {
      return behindThan[b].count(a) > 0;
    } else {
      return !(behindThan[a].count(b) > 0);
    }
  });

  for (int i = 0; i < n; i++) {
    answer[i]++;
  }

  return answer;
}
```

### 정점의 우선순위

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      46      |   O(N^2)    |   O(N^2)    |

간선 정보에서 i < j인 경우 정점 i를 a, 정점 j를 b라고 하자.

```cpp
vertex[i] = 'a'
vertex[j] = 'b'
```

b가 a보다 뒤에 나오기 위해선 두 정점이 연결되어있어야 한다.

반대로 i > j인 경우 b가 뒤에 나오기 위해선 두 정점이 연결되어있지 않아야 한다.

이를 정리하면 아래와 같다. (b가 a보다 뒤에 나오기 위한 조건)

- graph[a][b] == 1 : a < b
- graph[a][b] == 0 : a > b

```cpp
vector<int> solution(int n, vector<string>& graph) {
  vector<int> answer;

  for (int i = 0; i < n; i++) {
    answer.push_back(i);
  }

  sort(answer.begin(), answer.end(), [&](int a, int b) {
    if (a < b)
      return graph[a][b] == '1';
    else
      return graph[a][b] == '0';
  });

  for (int i = 0; i < n; i++) {
    answer[i]++;
  }

  return answer;
}
```

## 고생한 점
