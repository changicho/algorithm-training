# 502. IPO

[링크](https://leetcode.com/problems/ipo/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 배열의 크기를 N, 선택할 수를 K라 하자. (N, K <= 10^5)

각 과정마다 가장 이익이 큰 작업을 선택해야 하며, 이를 위해 정렬과 우선순위 큐를 사용한다.

이 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

우선순위 큐에 O(N)의 공간 복잡도를 사용한다.

### 정렬 & 우선순위 큐

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     216      | O(N \* log_2(N)) |    O(N)     |

각 작업들을 capital을 기준으로 오름차순으로 정렬한다.

이는 현재 W가 작업의 capital보다 작을 경우, 작업을 수행할 수 없기 때문이다.

따라서 각 단계마다 유효한 작업들만 찾기 위해 정렬을 수행한다.

각 과정에서 현재 W로 가능한 작업들을 우선순위 큐에 넣는다.

이후 우선순위 큐에서 가장 이익이 큰 작업을 선택한다. 이를 K번 반복한다.

이를 구현하면 다음과 같다.

```cpp
struct Project {
  int capital;
  int profit;
};

int findMaximizedCapital(int k, int w, vector<int>& profits,
                          vector<int>& capital) {
  int size = profits.size();

  vector<Project> projects;  // capital, profits
  for (int i = 0; i < size; i++) {
    projects.push_back({capital[i], profits[i]});
  }
  sort(projects.begin(), projects.end(),
        [](Project& a, Project& b) { return a.capital < b.capital; });

  priority_queue<int> pq;
  int i = 0;
  while (k--) {
    while (i < size && projects[i].capital <= w) {
      pq.push(projects[i].profit);
      i++;
    }

    if (pq.empty()) break;

    w += pq.top();
    pq.pop();
  }
  return w;
}
```

## 고생한 점
