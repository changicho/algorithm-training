# 347. Top K Frequent Elements

[링크](https://leetcode.com/problems/top-k-frequent-elements/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N, 입력받은 수를 K라고 하자.

우선 각 수의 빈도를 체크하기 위해 한번 순회해야 한다. 이에 O(N)의 시간 복잡도를 사용한다.

이후 빈도와 값에 따라 순회하며 top K개의 원소를 뽑는다. 이를 위해 정렬을 수행할 경우 O(N \* log_2(N))를 사용한다.

heap을 사용할 경우 O(N \* log_2(K))의 시간 복잡도를 사용한다.

### 공간 복잡도

빈도를 체크하기 위해 O(N)크기의 hash map을 만든다.

heap을 사용할 경우 O(K)의 공간 복잡도를 사용한다.

### hash map & heap

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      16      | O(N \* log_2(K)) |  O(N + K)   |

우선 원소들의 빈도를 체크한다.

이후 각 원소들을 heap에 삽입하며 k개의 원소를 넘어설 경우 pop한다.

값과 빈도중에 빈도에 따라 정렬하기 위해 다음과 같은 구조체를 사용한다.

```cpp
struct Element {
  int num, count;

  bool operator<(const Element &b) const { return count > b.count; }
};
```

이를 구현하면 다음과 같다.

```cpp
vector<int> topKFrequent(vector<int> &nums, int k) {
  unordered_map<int, int> counts;  // key:num, val:count

  for (int &num : nums) {
    counts[num] += 1;
  }

  priority_queue<Element> pq;

  for (auto &it : counts) {
    pq.push({it.first, it.second});

    if (pq.size() > k) pq.pop();
  }

  vector<int> answer;
  while (!pq.empty()) {
    Element cur = pq.top();
    pq.pop();
    answer.push_back(cur.num);
  }

  return answer;
}
```

## 고생한 점
