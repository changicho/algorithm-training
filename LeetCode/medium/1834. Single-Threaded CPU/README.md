# 1834. Single-Threaded CPU

[링크](https://leetcode.com/problems/single-threaded-cpu/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

task의 갯수를 N이라 하자.

매 시간마다 task들이 정해진 시간에 작업 목록에 들어오고 이중 가방 빨리 끝나는 작업을 매번 선택한다.

이 경우 힙을 이용해 각 경우마다의 가장 빨리 끝나는 작업을 고를 수 있다.

이 경우 매 작업마다 순회하며 삽입하고 삭제하는 데 총 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 IDLE시간동안 time을 이동 시켜야 한다. 이를 모든 time에 대해서 진행할 경우 O(T)만큼의 시간복잡도를 소요하므로 제한시간 내에 불가능하다.

따라서 IDLE상태일때 시간을 다음 작업의 enqueTime으로 이동시켜버린다. 이 경우 O(1)의 시간 복잡도를 사용해 바로 이동할 수 있다.

따라서 총 시간 복잡도는 O(N \* log_2(N))이다.

### 공간 복잡도

힙을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

입력받은 task에 대해서 index를 함께 저장해야 하므로 O(N)의 공간 복잡도를 사용한다.

### 힙

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     452      | O(N \* log_2(N)) |    O(N)     |

힙을 사용하기 위해 다음과 같은 구조체를 사용한다.

```cpp
struct Data {
  int index;
  long came, cost;

  bool operator<(const Data &b) const {
    if (cost != b.cost) {
      return cost > b.cost;
    }
    return index > b.index;
  }
};
```

우선 각 데이터들을 index를 함께 추가해 저장한다.

이후 입력받은 데이터들을 enqueTime순으로 정렬한다.

시간에 대해서 유효한 시간들만을 탐색하기 위해 초기 시간은 가장 빠른 데이터의 enqueTime으로 설정한다.

이후 모든 작업을 완료할 때까지 아래의 작업을 반복한다.

- 현재 시간 이전에 enque된 작업들을 힙에 저장한다.
- 힙에서 가장 빨리 끝나는 작업을 뽑아 진행한다.
- 시간을 갱신한다. (작업에 소요한 만큼)
- 만약 힙이 비어있는 경우 시간을 다음 작업의 enqueTime만큼 증가시킨다.

이를 구현하면 다음과같다.

```cpp
vector<int> getOrder(vector<vector<int>> &tasks) {
  int size = tasks.size();

  vector<Data> datas;
  for (int i = 0; i < size; i++) {
    vector<int> &t = tasks[i];
    datas.push_back({i, t[0], t[1]});
  }

  sort(datas.begin(), datas.end(),
        [&](Data &a, Data &b) { return a.came < b.came; });

  vector<int> answer;
  priority_queue<Data> pq;

  int time = datas.front().came;
  int index = 0;

  // until all task over
  while (answer.size() < size) {
    // push enqued tasks
    while (index < size && datas[index].came <= time) {
      pq.push(datas[index]);
      index++;
    }

    // if pq is empty, move time to next task
    if (pq.empty()) {
      time = datas[index].came;
      continue;
    }

    Data cur = pq.top();
    pq.pop();
    answer.push_back(cur.index);

    time += cur.cost;
  }

  return answer;
}
```

## 고생한 점
