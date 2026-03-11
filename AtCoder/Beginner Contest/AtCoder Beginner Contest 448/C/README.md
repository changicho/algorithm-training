# C - Except and Min

[링크](https://atcoder.jp/contests/abc448/tasks/abc448_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

배열의 크기를 N, 쿼리의 크기를 Q라 하자.

각 쿼리마다 값들의 수의 평균을 K라 하자.

각 쿼리마다 특정 값들을 제외하고 최소값을 구해야한다.

multiset을 사용할 경우 O(K \* log_2(N))의 시간 복잡도를 사용한다.

이를 모든 쿼리에 적용하면 O(Q \* K \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

멀티셋에 O(N)의 공간 복잡도를 사용한다.

### multiset

| 내 코드 (ms) |      시간 복잡도      | 공간 복잡도 |
| :----------: | :-------------------: | :---------: |
|     513      | O(Q \* K \* log_2(N)) |    O(N)     |

각 공들의 값을 multiset에 넣는다.

이후 각 쿼리를 순회하며 삭제되는 공의 번호와 실제 값을 multiset에서 삭제한다.

이후 최소값을 구해 정답에 추가한다.

```cpp
struct Query {
  int size;
  vector<int> nums;
};

auto solution(int size, int qSize, vector<int>& balls, vector<Query>& queries) {
  vector<int> answer;

  multiset<int> ballSet;
  for (int& ball : balls) {
    ballSet.insert(ball);
  }

  for (Query& q : queries) {
    for (int& num : q.nums) {
      ballSet.erase(ballSet.find(balls[num - 1]));
    }
    answer.push_back(*ballSet.begin());

    for (int& num : q.nums) {
      ballSet.insert(balls[num - 1]);
    }
  }

  return answer;
}
```

## 고생한 점

multiset을 사용해 값을 삭제할 때 erase에 값을 바로 넣으면 모든 값을 삭제한다.

따라서 find로 삭제할 iterator를 찾아 erase에 넣어야한다.
