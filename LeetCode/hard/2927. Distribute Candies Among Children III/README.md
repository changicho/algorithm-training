# 2927. Distribute Candies Among Children III

[링크](https://leetcode.com/problems/distribute-candies-among-children-iii/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자. (N <= 10^8)

N이 크므로 O(N)이하의 시간복잡도로 해결해야 한다.

조합론을 사용할 경우 O(1)의 시간복잡도로 해결할 수 있다.

### 공간 복잡도

조합론을 사용하는 경우 O(1)의 공간복잡도로 해결할 수 있다.

### 조합론

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(1)     |    O(1)     |

```cpp
long long combination(int n, int m) {
  if (n < m) return 0;
  return (long long)n * (n - 1) / m / (m - 1);
}

long long distributeCandies(int n, int limit) {
  long long answer = 0;
  answer += combination(n + 2, 2);
  answer -= 3 * combination(n - limit + 1, 2);
  answer += 3 * combination(n - 2 * limit, 2);
  answer -= combination(n - 3 * limit - 1, 2);
  return answer;
}
```

## 고생한 점
