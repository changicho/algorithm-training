# 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum

[링크](https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

모든 경우를 탐색할 경우 O(N^2)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

prefix sum과 동적 계획법을 사용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

prefix sum, 동적 계획법에 O(N)의 공간 복잡도를 사용한다.

### prefix sum & 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     178      |    O(N)     |    O(N)     |

prefix sum을 이용해 특정 구간의 합이 target인지 판단할 수 있다.

또한 특정 index까지 조건을 만족하는 이전 range의 최소 길이를 갱신할 수 있다.

이를 이용해 매번 prefix sum으로 합이 target인 구간의 길이를 찾고, 이전에 조건을 만족하는 구간의 길이와 합쳐 정답을 갱신한다.

```cpp
int minSumOfLengths(vector<int>& arr, int target) {
  int size = arr.size();
  unordered_map<int, int> pos;
  pos[0] = -1;

  vector<int> minLens(size);

  int sum = 0;
  int answer = INT_MAX;
  int minL = INT_MAX;

  for (int i = 0; i < size; i++) {
    sum += arr[i];

    if (pos.count(sum - target)) {
      int before = pos[sum - target];

      int len = i - before;

      if (before != -1 && minLens[before] != INT_MAX) {
        answer = min(answer, len + minLens[before]);
      }
      minL = min(minL, len);
    }

    minLens[i] = minL;
    pos[sum] = i;
  }
  if (answer == INT_MAX) return -1;
  return answer;
}
```

## 고생한 점
