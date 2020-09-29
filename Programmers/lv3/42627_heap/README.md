# 42627. 디스크 컨트롤러

[링크](https://programmers.co.kr/learn/courses/30/lessons/42627)

| 난이도 | 완료 (명) |
| :----: | :-------: |
|  lv3   |   3191    |

## 설계

### 시간 복잡도

작업의 크기는 최대 500개, 각 작업당 걸리는 시간은 최대 1000 이다.

최악의 경우 작업은 500개 1,000초가 걸리는 작업이 동시에 들어왔을 경우 이며, 이 경우 최대 500,000 초가 소요된다.

각 경우마다 정답이 최소가 되기 위해서는, 대기 목록들 중에서 가장 빨리 완료되는 작업을 선택해야 한다.

이 때 가장 빨리 완료되는 작업을 선택할 때 매번 비교할 경우, 500번이 소요되고

총 시간 복잡도는 250,000,000번 소요되므로 제한시간 내에 불가능하다.

따라서 최적의 작업을 찾기 위해 우선순위 큐를 사용한다.

이는 각 시간별로 자료의 삭제와 생성이 자주 일어나기 때문에 기존 정렬로는 풀이가 불가능하기 때문이다.

### 공간 복잡도

각 자료들은 전부 절대값이 1000 이하이다. 따라서 int형으로 선언한다.

최악의 경우 시간의 총 합 또한 500,000 이하이므로 int형으로 선언한다.

### 우선순위 큐

작업에는 세가지 정보가 필요하다

- 작업이 들어온 시간
- 작업 시작 시간
- 작업이 끝나는 시간 (시작 시간 + 걸리는 시간)

따라서 작업을 다음과 같이 설정한다

```cpp
struct Job {
  int arrived_time;
  int start_time;
  int cost;

  bool operator<(const Job &b) const {
    return cost > b.cost;
  }
};
```

이 떄 우선순위 큐를 작업에 대해 만들어야 하므로 operator 연산을 만들어준다.

시간에 대한 정보 time을 0부터 증가시키며 정답을 갱신한다.

```cpp
for (int time = 0; time <= 1000000; time++) {
  if (count < jobs.size() && jobs[count][0] <= time) {
    pq.push({jobs[count][0], time, jobs[count][1]});
    count += 1;
  }

  if (!q.empty() && q.front().start_time + q.front().cost == time) {
    answer += time - q.front().arrived_time;
    q.pop();
  }

  if (q.empty() && !pq.empty()) {
    q.push({pq.top().arrived_time, time, pq.top().cost});
    pq.pop();
  }
}
```

이 때 현재 작업이 끝나고 새로운 작업이 들어올 수있으므로 비교의 순서는

- 기존 작업이 끝났는지 판단
- 새 작업이 들어올 수 있는지 판단

으로 이루어진다.

## 고생한 점
