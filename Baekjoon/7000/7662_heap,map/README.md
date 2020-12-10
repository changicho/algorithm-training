# 7662. 이중 우선순위 큐

[링크](https://www.acmicpc.net/problem/7662)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
| Gold V |   24.486    |

## 설계

### 시간 복잡도

연산의 개수는 최대 1,000,000개이다.

최악의 경우 시간복잡도는 삭제, 삽입연산마다 log(N) 이내에 수행해야한다.

이 경우 시간 복잡도는

```cpp
O(N * log_2(N)) = 1,000,000 * 20 = 20,000,000
```

이므로 제한시간 6초 내에 충분하다.

따라서 map, set, heap과 같은 자료구조를 이용해 시간 복잡도를 log(N) 이하로 한다.

### 공간 복잡도

숫자는 전부 32비트 정수이므로 int형으로 충분하다.

### heap + map을 이용한 방법

1224ms

최대, 최소 힙을 이용해 최대값 최소값을 찾고, 삭제 여부를 판단하기 위해 map을 이용한다.

```cpp
priority_queue<long long, vector<long long>, less<long long>> max_heap;
priority_queue<long long, vector<long long>, greater<long long>> min_heap;
map<long long, int> m;

// push
max_heap.push(number);
min_heap.push(number);

m[number] += 1;

// delete max
if (max_heap.empty()) break;

long long target = max_heap.top();
max_heap.pop();
m[target] -= 1;

// delete min
if (min_heap.empty()) break;

long long target = min_heap.top();
min_heap.pop();
m[target] -= 1;

// trim
while (!max_heap.empty() && m[max_heap.top()] == 0) {
  max_heap.pop();
}
while (!min_heap.empty() && m[min_heap.top()] == 0) {
  min_heap.pop();
}
```

삭제 연산 이후에는 trim을 해줘야 함에 유의한다.

### multi set

1760ms

c++ STL set 중 multiset을 이용해 문제를 풀이할 수 있다.

multiset 컨테이너는 중복 원소를 컨테이너에 저장할 수 있다는 것 외에는 set과 다른 것이 없다.

set 처럼 원소가 자동 정렬되는 연관 컨테이너에 노드 기반 컨테이너이다.

```cpp
// push
ms.insert(number);

// delete
// before delete check multiset is empty
if (ms.empty()) break;

// max
// 끝 pointer 직전의 값이 max 값이다.
ms.erase(--ms.end());
// min
ms.erase(ms.begin());
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     1224     |      260       |

## 고생한 점
