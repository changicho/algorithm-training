# 1202. 보석 도둑

[링크](https://www.acmicpc.net/problem/1202)

| 난이도  | 정답률(\_%) | 시간 제한(초) |
| :-----: | :---------: | :-----------: |
| Gold II |   23.078    |       1       |

## 설계

### 시간 복잡도

보석의 갯수 N은 300,000, 가방의 개수 K는 최대 300,000 까지이다.

매 경우마다 비교할 경우 시간 복잡도를 초과하므로 O(N \* log(N)) 이내에 수행해야 한다.

탐욕 알고리즘을 이용해 비교를 최적화한다.

### 공간 복잡도

보석의 무게는 1,000,000 이하의 양의 정수이다.

최악의 경우 정답은 1,000,000 \* 300,000 이므로 int형을 초과한다.

따라서 long long 으로 선언한다.

### 탐욕 알고리즘

크기가 작은 배낭부터 채울 수 있는 가치의 최고의 보석을 채운다.

이 때 크기가 작은 배낭부터 비교하므로 보석을 크기순으로 정렬해 탐색한다.

각 가방에서 채울 수 있는 보석 리스트 중 가치가 가장 높은 보석만 찾아야 한다.

이를 매번 탐색할 경우 시간복잡도를 초과하므로 (탐색에 O(N) 이내가 걸려야함) 보석 리스트를 내림차순 하기 위해 우선순위 큐를 이용한다.

이미 보석 리스트에 추가된 보석은 제외하기 위해 배낭을 탐색할 때마다 보석 리스트는 그래도 유지해야한다.

```cpp
struct Jewel {
  int weight;
  int value;

  bool operator<(const Jewel &b) const {
    return weight < b.weight;
  }
};
```

```cpp
sort(jewels.begin(), jewels.end());
sort(bags.begin(), bags.end());

long long answer = 0;
int jewel_index = 0;
priority_queue<int> pq;

for (int bag : bags) {
  while (jewel_index < N && jewels[jewel_index].weight <= bag) {
    pq.push(jewels[jewel_index].value);
    jewel_index++;
  }

  if (!pq.empty()) {
    answer += pq.top();
    pq.pop();
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     152      |       76       |

## 고생한 점
