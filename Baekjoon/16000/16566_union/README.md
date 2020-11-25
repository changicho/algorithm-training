# 16566. 카드 게임

[링크](https://www.acmicpc.net/problem/16566)

|   난이도   | 정답률(\_%) |
| :--------: | :---------: |
| Platinum V |   29.485    |

## 설계

### 시간 복잡도

N과 M은 최대 4,000,000 까지이며, K는 최대 10,000 까지이다.

매번 제시된 수보다 가지고 있는 큰 수를 찾아야하므로 이는 이분탐색으로 logN번 만에 구한다.

이 때 이미 사용한 카드는 사용할 수 없으므로, 사용한 카드를 제외하고 탐색 할 때, 최악의 경우 K번이 소요된다.

이는 최악의 경우 사용한 카드의 수 만큼만 탐색을 진행하면 되기 때문이다.

따라서 최악의 경우 시간 복잡도는

```cpp
// O(K(K+log_2(M)))
10,000 * (10,000 + log_2(4,000,000)) = 10,000 * (10,000  + 22) = 100,220,000
```

이며 제한시간 1.2초 내에 충분하다.

### 공간 복잡도

입력받는 수는 최대 4,000,000 까지이므로 int형으로 충분하다.

### 이분탐색을 이용한 방법 (upper bound)

매 쿼리마다 이분탐색으로 입력받은 값을 초과하는 값을 빠르게 찾아낸다.

이 떄의 시간 복잡도는 O(K(K+log_2(M))) 이다.

```cpp
sort(cards.begin(), cards.end());

for (int i = 0; i < K; i++) {
  int target;
  cin >> target;

  int index = upper_bound(cards.begin(), cards.end(), target) - cards.begin();

  while (visited[index]) index += 1;

  answers.push_back(cards[index]);
  visited[index] = true;
}
```

### 분리 집합을 이용한 방법 (disjoint set, union find)

Disjoint Set으로 다음으로 큰 수를 가리켜 문제래르 해결할 수 있다.

하나의 수를 사용했다면 그 다음 수와 병합하여 다음 수를 가리키게 한다.

이 경우 시간 복잡도는 O(K log_2(M)) 번에 문제를 해결하는 것이 가능하다

Disjoint set은 서로 중복되지 않는 부분 집합들로 나누어진 원소들에 대한 정보를 저장하고 조작하는 자료구조이다.

union find와 같다고 생각할 수 있다.

find(x)

- 트리의 높이와 시간 복잡도가 동일하다.
- 최악의 경우 O(N - 1)이다.

union(x, y)

- find 연산이 전체 수행시간을 지배한다.
- 즉, 최악의 경우 O(N - 1)이다.

트리 구조로 제작한 disjoint set이 한쪽으로 치우치는것을 방지하기 위해 높이를 나타내는 배열을 사용한다.

합칠 두 노드의 높이를 비교에 높이가 더 높은 트리에 낮은 트리를 합친다.

이 때 서로의 높이가 같은 경우 높이를 한단계 증가시킨다.

```cpp
struct DisjointSet {
  vector<int> parents;
  vector<int> ranks;

  DisjointSet(int size) {
    parents.resize(size);
    ranks.resize(size);

    for (int i = 0; i < size; i++) {
      parents[i] = i;
      ranks[i] = 1;
    }
  }

  int find(int index) {
    if (parents[index] == index) return index;

    return parents[index] = find(parents[index]);
  }

  void merge(int first, int second) {
    if (first > second) swap(first, second);

    first = find(first);
    second = find(second);

    if (first == second) return;
    if (levels[first] < levels[second]) swap(first, second);

    parents[second] = first;
    if (levels[first] == levels[second]) levels[second]++;
  }
};
```

이 문제에서는 다음 수를 가리켜야 하므로 merge부분이 다음과 같음에 유의한다.

```cpp
void merge(int u, int v) {
  u = find(u);
  v = find(v);

  if (u != v) parents[v] = u;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     772      |      140       |

## 고생한 점
