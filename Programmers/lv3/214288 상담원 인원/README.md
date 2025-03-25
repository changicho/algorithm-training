# 상담원 인원

[링크](https://school.programmers.co.kr/learn/courses/30/lessons/214288)

| 난이도 |
| :----: |
|  lv3   |

## 설계

### 시간 복잡도

상담의 타입의 종류를 K, 선생의 수를 N, 찾아오는 학생의 수를 M이라 하자.

모든 경우를 탐색할 경우 제한시간 내에 불가능하다.

각 학생마다 찾아오는 시간에 대해 오름차순으로 정렬하는 데 O(M \* log_2(M))의 시간 복잡도가 필요하다.

동적 계획법을 사용해 각 타입별로 선생의 수마다의 비용을 구할 수 있다.

이 때 우선순위 큐를 이용해 현재 경우의 최소 비용을 O(M \* log_2(N))의 시간 복잡도로 구할 수 있다.

이에 시간 복잡도는 O(K \* N \* M \* log_2(N)) 이다.

각 타입마다 상담 인원을 배정하는 경우를 모두 탐색하는데 O(N^K) 이하의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N^K + K \* N \* M * log_2(N \* M)) 이다.

### 공간 복잡도

재귀 호출로 완전 탐색할 경우 재귀호출에 O(K)의 시간 복잡도가 필요하다.

각 타입별 선생의 수마다 최소 비용을 저장하는데 O(K \* N)의 공간 복잡도가 필요하다.

각 학생을 정렬하는데 O(M)의 공간 복잡도를 사용한다.

### 동적 계획법 & 완전 탐색

|             시간 복잡도              |  공간 복잡도  |
| :----------------------------------: | :-----------: |
| O(N^K + K \* N \* M * log_2(N \* M)) | O(K \* N + M) |

각 타입별로 선생을 배정하는 경우를 완전 탐색한다.

이 때 각 타입마다 선생의 수마다의 최소 비용을 미리 구해놓는다.

이를 구하기 위해 우선순위 큐를 이용해 먼저 상담이 끝나는 학생의 시간과, 현재 학생이 도달한 시간을 비교하며 비용을 구한다.

```cpp
struct Student {
  int arrive, time;
  int type;
};

int calc(int people, vector<Student> &students) {
  int time = 0;

  priority_queue<int, vector<int>, greater<int>> pq;  // minHeap
  int ret = 0;
  for (Student &s : students) {
    while (!pq.empty() && pq.top() <= s.arrive) {
      pq.pop();
    }

    if (pq.size() < people) {
      pq.push(s.arrive + s.time);
      continue;
    }

    int beforeEnd = pq.top();
    pq.pop();

    ret += beforeEnd - s.arrive;

    pq.push(max(beforeEnd, s.arrive) + s.time);
  }
  return ret;
}

int solution(int k, int n, vector<vector<int>> reqs) {
  vector<Student> students[5];

  sort(reqs.begin(), reqs.end(), [](auto &a, auto &b) { return a[0] < b[0]; });

  for (vector<int> &req : reqs) {
    int arrive = req[0], time = req[1], type = req[2] - 1;

    students[type].push_back({arrive, time, type});
  }

  // [type][people]
  int times[5][21] = {
      0,
  };

  for (int type = 0; type < k; type++) {
    times[type][0] = INT_MAX;

    for (int people = 1; people <= n; people++) {
      times[type][people] = calc(people, students[type]);
    }
  }

  long long answer = INT_MAX;

  function<void(int, int, int)> recursive = [&](int index, int left,
                                                long long cost) {
    if (index == k) {
      if (left == 0) {
        answer = min(answer, cost);
      }
      return;
    }

    for (int people = 1; people <= left; people++) {
      long long newCost = cost + times[index][people];
      recursive(index + 1, left - people, newCost);
    }
  };

  recursive(0, n, 0);

  return (int)answer;
}
```

## 고생한 점
