# 2070. Most Beautiful Item for Each Query

[링크](https://leetcode.com/problems/most-beautiful-item-for-each-query/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 item의 갯수를 N, query의 수를 M이라 하자.

query를 순회하며 item을 찾는 경우 시간 복잡도는 O(N \* M)이다. 이는 제한시간 내에 불가능하다.

item을 정렬 후 쿼리마다 이분 탐색을 사용할 경우 시간 복잡도는 O(N \* log_2(N) + M \* log_2(N)) 이므로 제한시간 내에 충분하다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도가 필요하다.

정답에 O(M)의 공간 복잡도가 필요하다.

### 정렬 & 이분 탐색

| 내 코드 (ms) |      시간 복잡도      | 공간 복잡도 |
| :----------: | :-------------------: | :---------: |
|      59      | O((N + M) * log_2(N)) |  O(N + M)   |

각 쿼리 이하의 최대 beauty를 찾아야 한다.

이 때 price가 낮아도 beauty가 더 높을 수 있음에 유의한다.

item을 price에 대해 정렬 후, 현재까지 도달한 최대 beauty 값으로 각 price마다 갱신한다.

이후 쿼리를 순회하며 이분 탐색을 이용해 현재 price 이하의 beauty중 가장 큰 값을 찾는다.

```cpp
vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
  int size = items.size();

  sort(items.begin(), items.end());

  int maximum = 0;
  for (vector<int>& item : items) {
    maximum = max(maximum, item[1]);
    item[1] = maximum;
  }

  vector<int> answer;
  for (int& q : queries) {
    int left = 0, right = size;
    int target = -1;

    while (left < right) {
      int mid = left + (right - left) / 2;

      if (items[mid][0] <= q) {
        // pick right
        left = mid + 1;
        target = mid;
      } else {
        // pick left
        right = mid;
      }
    }

    if (target == -1) {
      answer.push_back(0);
    } else {
      answer.push_back(items[target][1]);
    }
  }
  return answer;
}
```

## 고생한 점
