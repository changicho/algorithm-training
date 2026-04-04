# C - Understory

[링크](https://atcoder.jp/contests/abc451/tasks/abc451_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

쿼리의 수를 Q라 하자.

각 쿼리의 값을 multiset로 관리할 수 있다.

이 경우 쿼리마다 O(log_2(Q)) 시간 복잡도가 소요된다.

이후 삭제에 총 O(Q \* log_2(Q)) 시간 복잡도가 소요된다.

따라서 전체 시간 복잡도는 O(Q \* log_2(Q)) 이다.

힙을 사용할 경우 동일하다.

### 공간 복잡도

multiset에 O(Q)의 공간 복잡도가 소요된다.

힙에 O(Q)의 공간 복잡도가 소요된다.

### 힙

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      46      | O(Q \* log_2(Q)) |    O(Q)     |

top이 최소값인 힙을 사용한다.

쿼리마다 1인 경우 높이를 힙에 추가한다.

2인 경우 현재 높이보다 작은 값들을 힙에서 제거한다.

각 쿼리마다 힙의 크기를 answer에 추가한다.

```cpp
struct Query {
  int type;
  int height;
};

vector<int> solution(int size, vector<Query>& queries) {
  vector<int> answer;

  // 1 height : add height
  // 2 height : remove at most height

  priority_queue<int, vector<int>, greater<int>> pq;

  for (Query& q : queries) {
    if (q.type == 1) {
      pq.push(q.height);
    } else {
      while (!pq.empty() && pq.top() <= q.height) {
        pq.pop();
      }
    }

    answer.push_back(pq.size());
  }

  return answer;
}
```

### multiset

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     120      | O(Q \* log_2(Q)) |    O(Q)     |

```cpp
struct Query {
  int type;
  int height;
};

vector<int> solution(int size, vector<Query>& queries) {
  vector<int> answer;

  // 1 height : add height
  // 2 height : remove at most height

  multiset<int> heights;

  for (Query& q : queries) {
    if (q.type == 1) {
      heights.insert(q.height);
    } else {
      auto it = heights.begin();

      auto target = heights.upper_bound(q.height);
      while (it != target) {
        heights.erase(it);
        it = heights.begin();
      }
    }

    answer.push_back(heights.size());
  }

  return answer;
}
```

## 고생한 점
