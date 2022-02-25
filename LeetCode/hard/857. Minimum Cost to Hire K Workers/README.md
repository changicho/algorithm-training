# 857. Minimum Cost to Hire K Workers

[링크](https://leetcode.com/problems/minimum-cost-to-hire-k-workers/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

quality와 wage의 크기를 N이라 하자.

주어진 데이터를 worker로 묶고 (임금 / 생산성)에 대한 비율로 정렬할 수 있다.

정렬에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 각 worker를 비율이 낮은 순서대로 (생산성 대비 낮은 임금) 순회한다. O(N)

이 때 maxHeap에 quality를 push하며 정답을 갱신한다. O(log_2(N))

따라서 총 시간 복잡도는 O(N \* log_2(N)) 이다.

### 공간 복잡도

주어진 데이터를 worker로 묶는데 O(N)의 공간 복잡도를 사용한다.

힙을 사용하는 데 O(N)의 공간복잡도를 사용한다.

### greedy & heap

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      53      | O(N \* log_2(N)) |    O(N)     |

각 데이터를 index에 따라 묶어 workers 배열을 만든다.

이 때 worker데이터는 다음과 같이 정의한다.

```cpp
struct Worker {
  int quality, wage;
  double ratio;

  bool operator<(const Worker& b) const { return ratio < b.ratio; }
};
```

(임금 / 생산성)에 대한 비율로 정렬하며, 이는 임금 대비 생산성이 높은 직원이 앞으로 오도록 비율이 오름차순으로 정렬하기 위함이다.

같은 그룹의 노동자들은 그들이 원하는 최소한의 임금 이상으로 지급받아야한다.

또한 각 노동자들은 그들의 임금과 생산성에 대한 비율을 갖고있다. 따라서 총 임금을 줄이기 위해 가장 작은 ratio를 이용한다.

(총 임금 : (모든 생산성의 합) \* (비율) 로 구할 수 있다.)

K명의 노동자를 비율이 작은순부터 순회하며 다음 동작을 수행한다.

- 힙에 생산성을 push한다.
- 그룹의 전체 생산성에 현재 생산성을 더한다.

만약 힙의 크기가 K를 넘었을 경우 생산성이 가장 높은 노동자를 현재 그룹의 생산성의 합에서 제거한다. (생산성이 높은쪽이 최소 임금을 만드는데 불리하므로)

순회를 지속하며 비율을 점점 증가시키며 K명이 선택 완료되었을 때마다 (힙의 크기가 K일 때) 정답을 갱신한다.

```cpp
double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
  int size = quality.size();
  // O(N)
  vector<Worker> workers;

  for (int i = 0; i < size; i++) {
    workers.push_back(
        {quality[i], wage[i], (double)wage[i] / (double)quality[i]});
  }
  // O(N * log_2(N))
  sort(workers.begin(), workers.end());

  double answer = DBL_MAX;
  int sumQ = 0;

  priority_queue<int> maxHeap;
  for (Worker& w : workers) {
    maxHeap.push(w.quality);
    sumQ += w.quality;

    if (maxHeap.size() > k) {
      sumQ -= maxHeap.top();
      maxHeap.pop();
    }

    if (maxHeap.size() == k) {
      answer = min(answer, sumQ * w.ratio);
    }
  }

  return answer;
}
```

## 고생한 점
