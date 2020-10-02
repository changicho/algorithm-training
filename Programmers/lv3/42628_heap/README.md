# 42628. 이중우선순위큐

[링크](https://programmers.co.kr/learn/courses/30/lessons/42628)

| 난이도 | 완료 (명) |
| :----: | :-------: |
|  lv3   |   3715    |

## 설계

### 시간 복잡도

연산의 횟수는 최대 1,000,000번이다.

최악의 경우 원소의 최대 개수는 1,000,000개, 연산마다 정렬해야 되는 순서를 1,000,000번이라고 할 때,

N^2 번의 시간이 소요되며, 이는 제한시간 내에 불가능하다.

따라서 우선순위 큐를 이용해 NlogN 번 이내에 계산이 완료되도록 한다.

### 공간 복잡도

숫자의 범위가 정해지지 않았으므로 long long 형으로 선언한다.

### 우선순위 큐

```cpp
priority_queue<long long> max_pq; // 제일 큰 수가 위에
priority_queue<long long, vector<long long>, greater<long long>> min_pq; // 제일 작은 수가 위에
```

### 이중 우선 순위 큐

최대 큐와 최소 큐를 만든 뒤, map으로 입력받은 각 숫자들을 관리한다.

삽입 연산이 일어났을 때, 수를 key로 map의 value를 증가시키고

삭제 연산이 일어났을 때, 수를 key로 map의 value를 감소시킨다.

매 연산마다 큐의 top에 해당하는 map의 value 가 0인 경우, 이는 그 숫자는 이전에 삭제되었음을 의미하므로

각 큐의 top이 0이 아닐 때까지 pop 연산을 수행한다.

```cpp
if (operation == "D 1") {
  if (max_pq.empty()) break;

  long long target = max_pq.top();
  max_pq.pop();
  m[target] -= 1;
} else {
  if (min_pq.empty()) break;

  long long target = min_pq.top();
  min_pq.pop();
  m[target] -= 1;
}

while (!max_pq.empty() && m[max_pq.top()] == 0) {
  max_pq.pop();
}
while (!min_pq.empty() && m[min_pq.top()] == 0) {
  min_pq.pop();
}
```

## 고생한 점
