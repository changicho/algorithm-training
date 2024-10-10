# 2838. Maximum Coins Heroes Can Collect

[링크](https://leetcode.com/problems/maximum-coins-heroes-can-collect/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 heroes의 길이를 N, monsters의 크기를 M이라 하자.

monsters와 coin을 쌍으로 만들어 정렬한다. 이후 heroes를 순회하며 잡을 수 있는 monster를 이분 탐색을 이용해 찾는다.

이후 prefix sum을 이용해 구간합을 빠르게 구한다.

이에 정렬, 이분탐색에 O(M \* log_2(M)), O(N \* log_2(M))의 시간 복잡도가 소요된다.

따라서 총 시간 복잡도는 O((N + M) \* log_2(M)) 이다.

### 공간 복잡도

정렬, 정답을 저장할 공간에 O(N + M)의 공간 복잡도가 필요하다.

### 정렬 & prefix sum & 이분 탐색

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|     161      | O((N + M) \* log_2(M)) |  O(N + M)   |

monsters와 coin을 쌍으로 만들어 monsters를 기준으로 정렬한다.

이후 각 hero마다 잡을 수 있는 몬스터의 index를 이분 탐색으로 찾는다.

이후 해당 index까지 coin의 합을 구한다.

이 때 coin의 합을 미리 prefix sum을 이용해 구해놓는다.

```cpp
vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters, vector<int>& coins) {
  int n = heroes.size(), m = monsters.size();
  vector<pair<int, int>> arr;
  for (int i = 0; i < m; i++) {
    arr.push_back({monsters[i], coins[i]});
  }
  sort(arr.begin(), arr.end());
  vector<long long> prefixes(m, 0);
  for (int i = 0; i < m; i++) {
    prefixes[i] = ((i > 0) ? prefixes[i - 1] : 0) + arr[i].second;
  }

  vector<long long> answer(n);
  for (int i = 0; i < n; i++) {
    int hero = heroes[i];

    int left = 0, right = m;
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (arr[mid].first <= hero) {
        // pick right
        left = mid + 1;
      } else {
        // pick left
        right = mid;
      }
    }
    int target = left - 1;

    answer[i] = target == -1 ? 0 : prefixes[target];
  }
  return answer;
}
```

## 고생한 점
