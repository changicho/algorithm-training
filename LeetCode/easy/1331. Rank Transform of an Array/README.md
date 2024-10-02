# 1331. Rank Transform of an Array

[링크](https://leetcode.com/problems/rank-transform-of-an-array/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 arr의 크기를 N이라 하자.

정렬 후 중복을 제거하면서 순서를 매길 경우 시간 복잡도는 O(N \* log_2(N))이다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      56      | O(N \* log_2(N)) |    O(N)     |

각 수를 정렬 후 랭크를 매긴다.

이후 원본 배열을 순회하며 해당 랭크를 찾아 answer에 저장한다.

```cpp
vector<int> arrayRankTransform(vector<int>& arr) {
  unordered_map<int, int> ranks;

  vector<int> answer = arr;

  sort(arr.begin(), arr.end());

  for (int& num : arr) {
    if (ranks.count(num)) continue;
    ranks[num] = ranks.size() + 1;
  }

  for (int i = 0; i < answer.size(); i++) {
    answer[i] = ranks[answer[i]];
  }
  return answer;
}
```

## 고생한 점
