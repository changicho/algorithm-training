# 1942. The Number of the Smallest Unoccupied Chair

[링크](https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 times의 크기를 N이라 하자.

times를 도착 시간순으로 정렬한다.

의자는 빠른 순으로 선택해야 하므로 최소 힙을 이용한다.

이후 떠나는 시간과 의자의 상태를 저장하는 힙을 생성한다.

이후 각 시간을 순회하며 시간마다 떠나는 손님과 배정하는 의자를 처리한다.

이 경우 시간 복잡도는 O(N \* log_2(N))이다.

### 공간 복잡도

힙에 O(N)의 공간 복잡도를 사용한다.

### 정렬 & 힙

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     131      | O(N \* log_2(N)) |    O(N)     |

각 인원을 도착 시간 순으로 정렬한다.

의자는 총 N개가 필요하다. 빠른 순으로 선택하기 위해 의자에 대한 최소 힙을 생성한다.

인원이 의자를 배정받았을 때 떠나는 시간이 빠른 순서대로 퇴장해야 한다.

이를 관리하기 위해 떠나는 시간과 배정받은 의자 쌍의 최소 힙을 사용한다.

이후 각 인원을 순회하며 현재 도착시간보다 빨리 떠나는 인원들의 의자를 반환하고 최소 힙에서 제거한다.

이후 현재 의자 중 가장 작은 의자를 배정하고 최소 힙에 현재 인원이 떠나는 시간을 삽입한다.

이 때 정답으로 반환할 인원의 도착시간인 경우 배정받은 의자를 반환한다.

```cpp
int smallestChair(vector<vector<int>>& times, int targetFriend) {
  int size = times.size();

  int targetArrive = times[targetFriend][0];
  sort(times.begin(), times.end());

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leaves;
  priority_queue<int, vector<int>, greater<int>> pq;

  int answer = -1;

  for (int i = 0; i < size; i++) {
    pq.push(i);
  }
  for (vector<int>& time : times) {
    int arrive = time[0], leave = time[1];

    while (!leaves.empty() && leaves.top().first <= arrive) {
      pq.push(leaves.top().second);
      leaves.pop();
    }

    int chair = pq.top();
    pq.pop();

    if (arrive == targetArrive) {
      answer = chair;
      break;
    }
    leaves.push({leave, chair});
  }
  return answer;
}
```

## 고생한 점
