# 2073. Time Needed to Buy Tickets

[링크](https://leetcode.com/problems/time-needed-to-buy-tickets/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

tickets의 크기를 N이라고 하자.

큐를 이용해 직접 시뮬레이션 할 경우 순회 횟수는 k번째 값의 크기에 따라 정해진다.

이를 T라고 할 경우 시간 복잡도는 O(N \* T)이다.

한번의 순회를 이용해 반복되는 횟수를 계산할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

큐를 사용할 경우 큐에 O(N)의 공간 복잡도를 사용한다.

한번의 순회를 할 경우 상수크기의 공간 복잡도를 사용하지 않으므로 O(1)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |  O(N \* T)  |    O(N)     |

큐를 이용해 직접 시뮬레이션을 수행한다.

T의 범위가 매우 작으므로 (100까지) 이를 제한시간 내에 풀이할 수 있다.

이 때 k번째 값이 0이 되었을 때까지의 시간을 체크해야 하며 이를 위해 값과 index를 동시에 저장한다.

이를 구현하면 다음과 같다.

```cpp
struct Person {
  int index, left;
};

int timeRequiredToBuy(vector<int>& tickets, int k) {
  int size = tickets.size();

  queue<Person> q;
  for (int i = 0; i < size; i++) {
    q.push({i, tickets[i]});
  }

  int time = 0;
  while (!q.empty()) {
    time++;

    Person cur = q.front();
    q.pop();

    cur.left--;

    if (cur.left > 0) {
      q.push(cur);
    } else if (cur.index == k) {
      break;
    }
  }
  return time;
}
```

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       |    O(N)     |    O(1)     |

k번째 까지 순회할 때 다음과 같이 두 부분으로 나눠 생각할 수 있다.

- 1 ~ k번째 까지 : k번째가 0일 때 까지 모두 순회할 수 있다.
- k+1 ~ 마지막 까지 : k번째가 0이 된 이후 더 순회하지 않는다.

따라서 시뮬레이션 하지 않아도 현재 순번은 k번째 ticket, 현재 값 중 적은 만큼 순회함이 보장된다.

이를 이용해 계산 한 뒤, k+1번째 순번부터는 제거해준다.

이를 구현하면 다음과 같다.

```cpp
int timeRequiredToBuy(vector<int>& tickets, int k) {
  int size = tickets.size();
  int time = 0;

  for (int i = 0; i < size; i++) {
    // loop case
    time += min(tickets[i], tickets[k]);

    // skip case
    if (i > k && tickets[i] >= tickets[k]) time--;
  }

  return time;
}
```

## 고생한 점
