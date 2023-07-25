# 373. Find K Pairs with Smallest Sums

[링크](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums1, nums2의 크기를 각각 N, M이라 하자.

선택할 수를 K라고 했을 때 정답의 개수는 min(K, N \* M)개 이하이다.

K를 N \* M 이하라고 가정하자.

각 경우마다 힙을 이용해 정답을 찾을 수 있다.

이 경우 중복을 제거했을 때 최대 K개의 조합을 방문할 수 있다.

각 경우마다 힙에 최소 합을 더해야 하므로 O(K \* log_2(K))의 시간 복잡도를 사용한다.

### 공간 복잡도

힙에 O(K)의 공간 복잡도가 필요하다.

중복 방문을 처리하기 위해 O(K)의 공간 복잡도를 사용한다.

### 우선순위 큐

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     353      | O(K \* log_2(K)) |    O(K)     |

예외 케이스 중 하나는 K가 N \* M보다 큰 경우이다. (모든 쌍의 수가 K보다 작을 때)

각 경우마다 nums1, nums2중 하나를 선택했을 때 더 작은 쪽으로 탐색을 진행한다.

이 때 현재 최선의 값이 이전에 방문한 조합에서 생성될 수 있으므로 현재 좌표를 방문할 때마다 두 경우를 모두 힙에 저장한다.

따라서 힙에는 가능한 조합들이 존재하고, 각 경우마다 해당 조합에서 최선의 값을 찾을 수 있다.

최선의 값은 nums1, nums2에서 두 수의 합이 최소가 되는 경우이므로 합과 index를 저장한 구조체를 사용한다.

이를 구현하면 다음과 같다.

```cpp
struct Data {
  int sum, idx1, idx2;

  bool operator<(const Data& other) const { return sum > other.sum; }
};

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
  int size1 = nums1.size(), size2 = nums2.size();

  vector<vector<int>> answer;
  set<pair<int, int>> visited;

  priority_queue<Data> pq;
  pq.push({nums1[0] + nums2[0], 0, 0});

  while (answer.size() < k && !pq.empty()) {
    Data cur = pq.top();
    pq.pop();

    int idx1 = cur.idx1, idx2 = cur.idx2;

    if (visited.count({idx1, idx2}) > 0) continue;
    visited.insert({idx1, idx2});

    answer.push_back({nums1[idx1], nums2[idx2]});

    if (idx1 + 1 < size1) {
      pq.push({nums1[idx1 + 1] + nums2[idx2], idx1 + 1, idx2});
    }
    if (idx2 + 1 < size2) {
      pq.push({nums1[idx1] + nums2[idx2 + 1], idx1, idx2 + 1});
    }
  }

  return answer;
}
```

## 고생한 점
