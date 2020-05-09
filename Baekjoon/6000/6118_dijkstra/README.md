# 6118. 숨바꼭질

[링크](https://www.acmicpc.net/problem/6118)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Silver I |   50.024    |

## 설계

### 시간복잡도

이 문제는 1번 노드에서 가장 거리가 먼 노드를 구하는 문제이다.

정점의 갯수를 E, 간선의 갯수를 V라고 했을 때
다이크스트라의 시간복잡도는 O(ElogV) 이다.

정점의 갯수(헛간의 갯수)는 최대 20,000, 간선의 갯수(양방향 길의 갯수)는 최대 50,000개 이므로 제한시간 1초 내에 충분하다.

### 다이크스트라알고리즘

다이트스크라 알고리즘은 두 노드간의 최단거리를 구하는 알고리즘이다.

탐색할 노드들을 찾기 위해 큐를 이용하는데, 시간복잡도를 줄이기 위해 우선순위 큐를 이용한다.

우선순위 큐에서 현재노드의 가중치가 큰 순으로 정렬함에 유의한다!

현재 노드에서 연결된 다음 노드가 존재하면 다음 노드의 가중치를 갱신한다.

- 다음 노드의 가중치 = min(다음 노드의 가중치, 현재노드의 가중치 + 연결된 간선의 가중치)

이를 코드로 구현하면 다음과 같다.

사용하는 구조체

```cpp
struct edge {
  int end, cost;
};

struct node {
  int cost, index;
};

struct compare {
  bool operator()(node a, node b) { return a.cost > b.cost; }
};
```

초기화

```cpp
// 끊어짐을 표현하기 위해 초기값을 매우 큰 수 대신 -1로 표시한다.
// resize하기 보다는 직접 for문으로 초기화 하는편이 빠르다.
links.resize(N);
costs.resize(N, -1);
costs[start] = 0;

// vector를 이용하지 않은 경우 memset을 이용하는게 더 빠르다.
```

다이크스트라 알고리즘

```cpp
void dijikstra(int start) {
  priority_queue<node, vector<node>, compare> pq;

  pq.push({0, start});

  while (!pq.empty()) {
    node cur = pq.top();
    pq.pop();

    for (edge current : links[cur.index]) {
      int new_val = costs[cur.index] + current.cost;
      int before_val = costs[current.end];

      if (new_val < before_val || before_val == -1) {
        int destination = current.end;

        costs[destination] = new_val;
        pq.push({new_val, destination});
      }
    }
  }
}
```

### 우선순위큐의 compare함수

우선순위 큐의 경우 compare함수를 구조체로 정의해야한다.

구조체 내부의 operator 함수가 compare 함수임에 유의한다.

```cpp
struct compare {
  bool operator()(node a, node b) { return a.cost > b.cost; }
};
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      20      |       8        |

## 고생한 점
