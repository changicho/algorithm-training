# 1200. Minimum Absolute Difference

[링크](https://leetcode.com/problems/minimum-absolute-difference/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N^2)이다.

정렬을 사용할 경우 시간 복잡도는 O(N \* log_2(N))이다.

### 공간 복잡도

정렬에 O(N)만큼의 공간 복잡도가 필요하다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      16      | O(N \* log_2(N)) |    O(N)     |

두 수의 차이가 최소가 되기 위해선 정렬 후 연이은 수를 선택하는 것이 최적이다.

배열을 정렬 후 연이은 수의 차이를 구하며 최소 차이를 갱신한다.

이후 최소 차이에 해당하는 수 쌍을 모두 구해 반환한다.

```cpp
vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
  sort(arr.begin(), arr.end());

  int size = arr.size();

  int minDiff = INT_MAX;
  for (int i = 0; i < size - 1; i++) {
    int diff = arr[i + 1] - arr[i];
    minDiff = min(minDiff, diff);
  }

  vector<vector<int>> answer;
  for (int i = 0; i < size - 1; i++) {
    int diff = arr[i + 1] - arr[i];

    if (diff == minDiff) {
      answer.push_back({arr[i], arr[i + 1]});
    }
  }
  return answer;
}
```

## 고생한 점
