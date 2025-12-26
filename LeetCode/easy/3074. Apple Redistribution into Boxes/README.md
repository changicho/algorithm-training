# 3074. Apple Redistribution into Boxes

[링크](https://leetcode.com/problems/apple-redistribution-into-boxes/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

두 배열의 크기를 각각 N, M, 각 값의 범위를 K라 하자.

정렬을 이용해 최적의 capacity 갯수를 구할 수 있다.

이 경우 O(M \* log_2(M) + N)의 시간 복잡도를 가진다.

카운팅 정렬을 사용할 경우 O(M + K + N)의 시간 복잡도를 가진다.

### 공간 복잡도

카운팅 정렬에 O(K)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도 |
| :----------: | :----------: | :---------: |
|      0       | O(N + M + K) |    O(K)     |

사과의 합을 구한 뒤, capacity를 차례로 선택하며 사과를 모두 담을 수 있는 최소 갯수를 구한다.

이 때 capacity의 최소 갯수를 구하기 위해선 매번 가장 큰 capacity부터 선택해야 한다.

따라서 capacity를 카운팅 정렬을 이용해 정렬한 뒤, 가장 큰 값부터 사과를 담는다.

```cpp
int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
  int size = capacity.size();

  int count[51] = {
      0,
  };
  for (int& c : capacity) {
    count[c]++;
  }

  int sum = accumulate(apple.begin(), apple.end(), 0);

  int prefix = 0;
  int useCount = 0;
  for (int val = 50; val >= 0; val--) {
    int diff = sum - prefix;

    if (diff > count[val] * val) {
      useCount += count[val];
      prefix += count[val] * val;
      count[val] = 0;
      continue;
    }

    int valCount = ceil((double)diff / val);
    useCount += valCount;
    return useCount;
  }

  return size;
}
```

## 고생한 점
