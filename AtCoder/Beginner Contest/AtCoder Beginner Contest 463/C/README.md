# C - Tallest at the Moment

[링크](https://atcoder.jp/contests/abc463/tasks/abc463_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

배열의 크기를 N, 쿼리의 크기를 Q라 하자.

각 인원별로 떠나는 시간에 대해 정렬하는데 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 각 쿼리를 시간별로 정렬하는데 O(Q \* log_2(Q))의 시간 복잡도를 사용한다.

각 시간마다 떠나는 인원들과 남은 인원들의 키 중 가장 큰 값을 구하는데 multiset을 사용할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N \* log_2(N) + Q \* log_2(Q)) 이다.

### 공간 복잡도

정렬, multiset에 O(N + Q)의 시간 복잡도를 사용한다.

### 정렬 & 멀티셋

| 내 코드 (ms) |           시간 복잡도            | 공간 복잡도 |
| :----------: | :------------------------------: | :---------: |
|     281      | O(N \* log_2(N) + Q \* log_2(Q)) |  O(N + Q)   |

각 인원들을 퇴장하는 순서대로 정렬하며 multiset에 키를 저장한다.

이후 각 쿼리를 시간순으로 순회하며 각 시간별로 빠지는 인원들의 키를 multiset에서 제거 후 가장 큰 값을 정답에 추가한다.

```cpp
struct Data {
  int h, l;

  bool operator<(const Data& b) const { return l > b.l; }
};

vector<int> solution(int size, vector<Data>& arr, int qSize, vector<int>& queries) {
  sort(arr.begin(), arr.end(), [](auto& a, auto& b) { return a.l < b.l; });
  priority_queue<Data> pq;
  multiset<int> ms;
  for (Data& cur : arr) {
    pq.push(cur);
    ms.insert(cur.h);
  }

  vector<int> answer(qSize);
  vector<pii> q;
  for (int i = 0; i < qSize; i++) {
    q.push_back({queries[i], i});
  }
  sort(q.begin(), q.end());

  for (int i = 0; i < qSize; i++) {
    int time = q[i].first;
    int target = q[i].second;

    while (!pq.empty() && pq.top().l <= time) {
      ms.erase(pq.top().h);
      pq.pop();
    }

    if (!ms.empty()) {
      answer[target] = *ms.rbegin();
    } else {
      answer[target] = 0;
    }
  }

  return answer;
}
```

## 고생한 점
