# 1792. Maximum Average Pass Ratio

[링크](https://leetcode.com/problems/maximum-average-pass-ratio/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 classes의 크기를 N, 입력받은 수를 K라 하자.

힙을 이용해 가장 유리한 값을 바꿀 수 있다. 이 경우 O(log_2(N))의 시간 복잡도가 소요된다.

이를 모든 classes와 extraStudents만큼 반복해야 하므로 시간 복잡도는 O((N + K) \* log_2(N))이다.

### 공간 복잡도

힙에 O(N)의 공간 복잡도가 필요하다.

### 힙

| 내 코드 (ms) |      시간 복잡도      | 공간 복잡도 |
| :----------: | :-------------------: | :---------: |
|     426      | O((N + K) * log_2(N)) |    O(N)     |

각 class마다 인원을 더했을 때 증가폭이 가장 큰 값에 대해 더해준다.

매 경우마다 가장 유리한 값을 찾기 위해 힙을 사용하며 힙의 비교식에서 사람이 더해졌을 때 증가값을 이용해 비교한다.

```cpp
struct Data {
  int pass, total;

  bool operator<(const Data &b) const {
    double cur = (double)(pass + 1) / (total + 1) - (double)(pass) / (total);
    double comp =
        (double)(b.pass + 1) / (b.total + 1) - (double)(b.pass) / (b.total);
    return cur < comp;
  }
};

double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
  int size = classes.size();

  priority_queue<Data> pq;

  for (vector<int> &c : classes) {
    int pass = c[0], total = c[1];

    pq.push({pass, total});
  }

  while (extraStudents--) {
    Data cur = pq.top();
    pq.pop();

    cur.pass += 1;
    cur.total += 1;

    pq.push(cur);
  }

  double sum = 0;
  while (!pq.empty()) {
    Data cur = pq.top();
    pq.pop();

    double ratio = (double)cur.pass / cur.total;
    sum += ratio;
  }
  return sum / size;
}
```

## 고생한 점
