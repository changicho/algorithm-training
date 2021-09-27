# 1882. Process Tasks Using Servers

[링크](https://leetcode.com/problems/process-tasks-using-servers/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

서버의 개수를 N, 작업의 개수를 M이라 하자.

각 작업마다 최적의 서버를 찾아 배정해야 한다.

이 때 매번 탐색을 수행할 경우 시간 복잡도는 O(N \* M)이 되며 이는 제한시간 내에 불가능하다.

따라서 각 경우마다 최적의 경우를 찾을 수 있도록 heap을 사용한다.

이 경우 시간 복잡도는 O(log_2(N) \* M)이다.

### 공간 복잡도

서버에 대한 heap을 사용하므로 O(N)의 공간 복잡도를 사용한다.

### heap

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     408      | O(log_2(N) \* M) |    O(N)     |

각 작업마다 최적의 서버를 찾아 배정해줘야한다.

이 때 각 서버의 작업이 끝난 경우 해당 서버 또한 가능한 서버 목록에 추가해줘야한다.

매번 정렬할 경우 최악의 경우 O(N \* log_2(N))의 시간 복잡도가 매 경우마다 사용되므로 적합하지 않다.

따라서 각 작업마다 최적의 서버를 찾기 위해 heap 자료 구조를 사용한다.

힙의 정렬 기준은 다음과 같다.

- 서버의 weight가 작은순
- 서버의 index가 작은 순

이를 위해 다음과 같은 구조의 우선순위 큐를 생성한다.

```cpp
typedef pair<int, int> Data;

priority_queue<Data, vector<Data>, greater<Data>> pq, busy;
```

여기서 동작중인 서버에 대한 큐를 사용하는 이유는 각 작업 중에서 가장 빨리 끝나는 작업들을 찾기 위함이다. (시간순 정렬)

각 서버들을 서버 목록 큐에 삽입한다.

이후 각 작업마다 다음과 같은 순서로 작업을 진행한다.

1. 작업이 들어오므로 현재 시간을 갱신한다.
2. 가능한 서버가 없는 경우 작업중인 서버 중에서 가장 빨리 끝나는 작업의 끝나는 시간으로 시간을 갱신한다.
3. 현재 시간보다 이전에 끝나는 작업들을 끝내고 서버목록에 저장한다.
4. 현재 작업에 대해서 최적의 서버를 선택한다.

이를 구현하면 다음과 같다.

```cpp
vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
  int N = servers.size();
  int M = tasks.size();

  priority_queue<Data, vector<Data>, greater<Data>> pq, busy;
  vector<int> answer;

  for (int i = 0; i < N; ++i) {
    pq.push({servers[i], i});
  }

  int time = 0;
  for (int i = 0; i < M; ++i) {
    time = max(i, time);

    if (pq.empty() && busy.top().first > time) {
      time = busy.top().first;
    }

    while (!busy.empty() && busy.top().first <= time) {
      Data info = busy.top();
      pq.push({servers[info.second], info.second});
      busy.pop();
    }

    Data info = pq.top();
    busy.push({time + tasks[i], info.second});
    pq.pop();

    answer.emplace_back(info.second);
  }

  return answer;
}
```

## 고생한 점
