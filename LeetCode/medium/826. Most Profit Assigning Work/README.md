# 826. Most Profit Assigning Work

[링크](https://leetcode.com/problems/most-profit-assigning-work/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 difficulty, profit의 크기를 N, worker의 크기를 M이라 하자.

profit들을 difficulty에 따라 정렬 후 worker가 낮은 순으로 순회하며 현재 선택 가능한 최대값을 선택하며 풀이할 수 있다.

이 경우 두 배열의 정렬에 O(N \* log_2(N) + M \* log_2(M))의 시간 복잡도가 소요된다.

### 공간 복잡도

정렬에 별도의 공간이 필요하므로 O(N + M)의 공간 복잡도가 필요하다.

### 정렬 & 투 포인터

| 내 코드 (ms) |           시간 복잡도            | 공간 복잡도 |
| :----------: | :------------------------------: | :---------: |
|      48      | O(N \* log_2(N) + M \* log_2(M)) |  O(N + M)   |

각 worker를 오름차순으로 정렬하자.

worker가 낮은 순으로 순회하며 현재 선택 가능한 가장 큰 profit을 매번 선택한다.

이 때 선택 가능한 profit은 현재 worker 이하의 difficulty를 가진 job들 중에서 가장 큰 profit을 선택한다.

따라서 difficulty와 profit을 difficulty를 기준으로 정렬하고, difficulty가 worker보다 작은 경우에만 profit을 갱신한다.

이를 위해 투 포인터를 사용한다.

```cpp
int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
  sort(worker.begin(), worker.end());

  int size = profit.size();
  vector<pair<int, int>> arr;
  for (int i = 0; i < size; i++) {
    arr.push_back({difficulty[i], profit[i]});
  }
  sort(arr.begin(), arr.end());

  int index = 0;
  int curMaxProfit = 0;

  int answer = 0;
  for (int& work : worker) {
    while (index < size && arr[index].first <= work) {
      curMaxProfit = max(curMaxProfit, arr[index].second);
      index++;
    }

    answer += curMaxProfit;
  }
  return answer;
}
```

## 고생한 점
