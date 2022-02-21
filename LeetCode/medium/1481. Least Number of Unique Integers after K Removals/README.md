# 1481. Least Number of Unique Integers after K Removals

[링크](https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

arr의 크기를 N, 이중 원소의 종류를 M, 삭제할 수를 K라 하자.

(M <= N, K <= N)

각 경우마다 원소의 갯수가 작은 순서대로 제거해 종류의 수를 최소로 줄일 수 있다.

BST기반의 map을 이용해 현재 존재하는 원소의 갯수가 작은 순으로 종류를 정렬해 사용할 수 있다.

이 경우 시간 복잡도는 O(N + K + M \* log_2(M))이 소요된다.

힙을 이용해 위 과정을 좀더 최적화 할 수 있다.

이 경우 시간 복잡도는 O(N + (M + K) \* log_2(M))이 된다.

### 공간 복잡도

BST기반의 map을 사용할 경우 각 값들의 종류의 수 만큼의 공간을 사용한다.

따라서 공간 복잡도는 O(M)이다.

힙을 사용하는 경우도 동일하다. 따라서 O(M)의 공간 복잡도를 사용한다.

### BST map

| 내 코드 (ms) |       시간 복잡도        | 공간 복잡도 |
| :----------: | :----------------------: | :---------: |
|     204      | O(N + K + M \* log_2(M)) |    O(M)     |

각 값들을 count한다. 이를 다음과 같은 map에 저장한다

- key : count
- value : 값의 종류

BST기반의 map에서 count가 작은 값들부터 바로 순회할 수 있다.

항상 count가 작은 수 부터 삭제하는 편이 적은 종류의 값을 남길 수 있다.

따라서 count가 낮은 수부터 지운다.

만약 지워도 해당 값이 남는 경우는 삭제연산을 종료한다. (삭제해도 해당 수는 어차피 남으므로)

```cpp
int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
  map<int, unordered_set<int>> countByKey;

  unordered_map<int, int> counts;
  // O(N)
  for (int &num : arr) {
    counts[num]++;
  }
  // O(M * log_2(M))
  for (auto &it : counts) {
    countByKey[it.second].insert(it.first);
  }

  int deleteCount = 0;
  // O(K)
  while (deleteCount < k) {
    // O(1)
    auto it = countByKey.begin();
    int count = it->first;
    int target = *it->second.begin();

    if (deleteCount + count > k) break;

    it->second.erase(target);
    deleteCount += count;
    if (it->second.size() == 0) {
      // O(1)
      countByKey.erase(it);
    }
  }

  int answer = 0;
  // O(M)
  for (auto &it : countByKey) {
    answer += it.second.size();
  }
  return answer;
}
```

### heap

| 내 코드 (ms) |        시간 복잡도         | 공간 복잡도 |
| :----------: | :------------------------: | :---------: |
|     213      | O(N + (M + K) \* log_2(M)) |    O(M)     |

각 값들을 count한 뒤 count한 값들을 minHeap에 삽입한다.

(각 count들은 다른 count에 영향을 끼치지 않는다. 타입이 다르므로)

이는 minHeap에 top에는 항상 작은 count만이 존재하며 이를 우선적으로 삭제하기 위함이다.

k개의 숫자를 삭제한 뒤에 남은 minHeap의 크기가 남은 숫자의 종류가 된다.

```cpp
int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
  unordered_map<int, int> counts;
  priority_queue<int, vector<int>, greater<int>> minHeap;

  // O(N)
  for (int &num : arr) {
    counts[num]++;
  }

  // O(M)
  for (auto &it : counts) {
    // O(log_2(M))
    minHeap.push(it.second);
  }

  int deleteCount = 0;
  // O(K)
  while (deleteCount < k) {
    if (minHeap.top() + deleteCount > k) break;

    deleteCount += minHeap.top();
    // O(log_2(M))
    minHeap.pop();
  }

  return minHeap.size();
}
```

## 고생한 점
