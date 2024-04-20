# 621. Task Scheduler

[링크](https://leetcode.com/problems/task-scheduler/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

tasks의 길이를 N이라 하자.

각 task를 순회하며 알파벳의 갯수를 세는데 O(N)의 시간 복잡도가 필요하다.

이후 각 경우마다 가장 갯수가 많은 알파벳들을 순서대로 선택하며 배치한다.

이를 위해 우선순위 큐를 사용할 경우 O(log_2(26))의 시간 복잡도가 필요하다.

따라서 총 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

우선순위 큐에 O(26)의 공간 복잡도를 사용한다.

따라서 총 O(1)의 공간 복잡도를 사용한다.

### 우선순위 큐

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      86      |    O(N)     |    O(1)     |

하나의 문자를 현재 실행할 경우, 해당 문자는 입력받은 n 이상의 시간 초과 이후에 다시 실행할 수 있다.

이 때 현재 가장 많이 남은 문자부터 실행하는 편이 유리하다.

따라서 현재 사이클에서 가장 많이 남은 문자들을 N+1개 선택해 실행한 뒤 다음 사이클로 넘어가는 방식으로 구현한다.

이 때 가장 많이 남은 문자들을 빠르게 찾기 위해 우선순위 큐를 사용한다.

```cpp
int leastInterval(vector<char>& tasks, int n) {
  int counts[26] = {
      0,
  };
  for (char& c : tasks) {
    counts[c - 'A']++;
  }

  priority_queue<int> pq;
  for (int i = 0; i < 26; i++) {
    if (counts[i] > 0) {
      pq.push(counts[i]);
    }
  }

  int time = 0;
  while (!pq.empty()) {
    int canChoose = n + 1;
    vector<int> remains;
    int chosen = 0;

    for (int i = 0; i < canChoose && !pq.empty(); i++) {
      int cur = pq.top() - 1;
      pq.pop();

      if (cur > 0) {
        remains.push_back(cur);
      }
      chosen++;
    }

    for (int& count : remains) {
      pq.push(count);
    }
    time += (pq.empty() ? chosen : n + 1);
  }

  return time;
}
```

## 고생한 점
