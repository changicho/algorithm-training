# 17612. 쇼핑몰

[링크](https://www.acmicpc.net/problem/17612)

| 난이도  |
| :-----: |
| 골드 II |

## 설계

### 시간 복잡도

손님의 수를 N, 계산대의 수를 K라 하자.

모든 손님을 순회하며 각 손님의 계산대 번호를 판단한다.

이 때 각 계산대 중 가장 적합한 계산대를 판단하는데 우선순위 큐를 사용한다.

우선순위 큐에 각 계산대 정보를 넣는데 O(K \* log_2(K))의 시간 복잡도가 필요하다.

이후 각 손님들을 순회하며 모두 판단할 경우 시간 복잡도는 O(N \* log_2(K))이다.

이후 각 손님들의 나가는 순서와 할당된 계산대 번호에 대해 정렬하고 순회하며 출력한다.

이 때 정렬에 O(N \* log_2(N))의 시간 복잡도가 필요하다.

따라서 총 시간 복잡도는 O(N \* log_2(N) + O(N + K) \* log_2(K))이다.

### 공간 복잡도

우선순위 큐에 각 계산대 정보를 넣는데 O(K)의 공간 복잡도가 필요하다.

각 손님들이 나가는 순서를 저장하는데 O(N)의 공간 복잡도가 필요하다.

### 시뮬레이션 & 우선순위 큐

| 내 코드 (ms) |               시간 복잡도               | 공간 복잡도 |
| :----------: | :-------------------------------------: | :---------: |
|      48      | O(N \* log_2(N) + O(N + K) \* log_2(K)) |  O(N + K)   |

우선순위 큐에 각 계산대 정보를 넣는다.

이후 각 손님들마다 가장 적합한 계산대를 판단한다.

이 때 우선순위 큐에서 가장 높은 우선순위를 가지는 계산대를 판단하기 위해 계산대별로 끝나는 시간에 대해 정렬한다.

- 끝나는 시간이 빠른 순
- 끝나는 시간이 같은 경우 계산대 번호가 더 작은 것을 우선

각 과정에서 각 계산대별로 대기중인 손님들에 대해 나가는 시간과 함께 저장한다.

이후 각 손님들을 나가는 시간에 대해 정렬한다.

- 나가는 시간이 빠른 순
- 높은 번호의 계산대에서 나오는 순

마지막으로 해당 정렬된 순서대로 손님들의 id와 순서의 곱을 더해 반환한다.

```cpp
struct Customer {
  int id;
  int w;
};

struct Counter {
  int id;
  int endTime;

  const bool operator<(const Counter &c) const {
    if (endTime == c.endTime) {
      return id > c.id;
    }
    return endTime > c.endTime;
  }
};

struct OutCustomer {
  int customerId;
  int counterId;
  int outTime;
};

long long solution(int size, int k, vector<Customer> &customers) {
  priority_queue<Counter> counters;
  for (int counter_id = 0; counter_id < k; counter_id++) {
    counters.push({counter_id, 0});
  }

  vector<OutCustomer> counterWaitingLines[k];
  for (Customer &customer : customers) {
    Counter counter = counters.top();
    counters.pop();
    int lastEndTime = counter.endTime;
    int counterId = counter.id;

    counterWaitingLines[counterId].push_back(
        {customer.id, counterId, lastEndTime + customer.w});
    counter.endTime += customer.w;

    counters.push(counter);
  }

  vector<OutCustomer> outCustomers;
  for (int i = 0; i < k; i++) {
    for (OutCustomer &outCustomer : counterWaitingLines[i]) {
      outCustomers.push_back(outCustomer);
    }
  }

  sort(outCustomers.begin(), outCustomers.end(),
       [](OutCustomer &a, OutCustomer &b) {
         if (a.outTime == b.outTime) {
           return a.counterId > b.counterId;
         }
         return a.outTime < b.outTime;
       });

  vector<int> answerList;
  for (OutCustomer &outCustomer : outCustomers) {
    answerList.push_back(outCustomer.customerId);
  }

  long long answer = 0;
  for (int i = 0; i < answerList.size(); i++) {
    answer += (long long)(i + 1) * answerList[i];
  }
  return answer;
}
```

## 고생한 점
