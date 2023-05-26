# 2542. Maximum Subsequence Score

[링크](https://leetcode.com/problems/maximum-subsequence-score/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

두 배열의 크기를 N, 입력받은 수를 K라 하자.

두 배열에서 유리한 순서로 숫자를 뽑아내기 위해 정렬을 사용한다.

이에 O(N * log_2(N))의 시간 복잡도를 사용한다.

이후 두 배열중 min에 영향을 주는 값을 내림차순으로 순회하며 priority_queue에 sum에 해당하는 값을 삽입한다. (K개)

각 과정마다 min과 sum의 합을 이용해 정답을 갱신한다.

이에 우선순위 큐를 사용하며 O(N * log_2(K))의 시간 복잡도를 사용한다.

따라서 총 O(N * log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬을 위해 새로운 배열을 생성하는 데 O(N)의 공간 복잡도를 사용한다.

우선순위 큐에 O(K)의 공간 복잡도를 사용한다.

### 우선순위 큐

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|     268      | O(N * log_2(N)) |    O(N)     |

선택할 수 있는 숫자는 다음과 같은 정보를 가지고 있다.

- min에 영향
- add에 영향

두 값이 총합을 계산할 때 미치는 영향이 다르다.

여기서 min값은 선택한 값중 최소값을 선택하게 되므로 min에 대해 정렬을 수행해야한다.

각 경우마다 현재 min을 선택했을 때 sum중의 가장 큰 K개의 값을 선택해야 한다.

따라서 min은 클수록, sum또한 클수록 우선순위가 높아야한다.

두 값 모두 내림차순으로 정렬하고 (min을 우선) K개의 값을 선택한다.

선택한 값을 우선순위 큐에 삽입한다.

이후 값을 순차적으로 순회하며 현재 값을 선택하고, 이전 값 중에서 가장 작은 값을 제거한다.

이를 끝까지 반복한다.

```cpp
long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
  int size = nums1.size();

  // min, add
  vector<pair<int, int>> arr;
  for (int i = 0; i < size; i++) {
    arr.push_back({nums2[i], nums1[i]});
  }

  sort(arr.begin(), arr.end(), greater<pair<int, int>>());

  priority_queue<int, vector<int>, greater<int>> pq;

  long long answer = 0;
  long long cur = 0;
  for (int i = 0; i < k - 1; i++) {
    cur += arr[i].second;
    pq.push(arr[i].second);
  }

  for (int i = k - 1; i < size; i++) {
    cur += arr[i].second;
    pq.push(arr[i].second);
    answer = max(answer, cur * arr[i].first);

    cur -= pq.top();
    pq.pop();
  }

  return answer;
}
```

## 고생한 점
