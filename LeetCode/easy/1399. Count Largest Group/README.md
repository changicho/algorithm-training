# 1399. Count Largest Group

[링크](https://leetcode.com/problems/count-largest-group/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

완전 탐색을 수행할 경우 O(N \* log_10(N))의 시간 복잡도를 가진다.

### 공간 복잡도

최대 log_10(N)개의 0~9가 자리마다 존재할 수 있으며 해당 수들의 합인 10 \* log_10(N)가지 경우가 생길 수 있다.

이에 O(log_10(N))의 공간 복잡도를 가진다.

### 완전 탐색

| 내 코드 (ms) |    시간 복잡도    | 공간 복잡도  |
| :----------: | :---------------: | :----------: |
|      1       | O(N \* log_10(N)) | O(log_10(N)) |

1부터 N까지 모든 수를 순회하며 각 자리수를 더한 값을 구한다.

해당 값의 count를 증가시키며, 가장 많이 등장한 값의 count를 구한다.

해당 count와 같은 값들을 세어준다.

```cpp
int calc(int num) {
  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

int countLargestGroup(int n) {
  unordered_map<int, int> counts;

  int maximum = 0;
  for (int i = 1; i <= n; i++) {
    int sum = calc(i);
    counts[sum]++;
    maximum = max(maximum, counts[sum]);
  }

  int answer = 0;
  for (auto [key, val] : counts) {
    if (val == maximum) answer++;
  }
  return answer;
}
```

## 고생한 점
