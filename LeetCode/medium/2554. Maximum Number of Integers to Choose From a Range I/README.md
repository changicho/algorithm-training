# 2554. Maximum Number of Integers to Choose From a Range I

[링크](https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/description)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수의 범위를 N, 배열 banned의 크기를 M이라 하자.

banned에 포함된 수를 제거하고 남은 수 중 작은 수부터 선택해 풀이할 수 있다.

이 경우 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash set에 O(M)의 공간 복잡도가 필요하다.

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     177      |  O(N + M)   |    O(M)     |

banned에 포함된 수를 제거하고 남은 수 중 작은 수부터 선택해 더한다.

이 때 합이 maxSum을 넘어가는 경우에는 더 이상 수를 더하지 않는다.

```cpp
int maxCount(vector<int>& banned, int n, int maxSum) {
  unordered_set<int> us(banned.begin(), banned.end());
  int sum = 0;
  int answer = 0;

  for (int num = 1; num <= n; num++) {
    if (us.count(num)) continue;
    if (sum + num > maxSum) break;
    sum += num;
    answer++;
  }

  return answer;
}
```

## 고생한 점
