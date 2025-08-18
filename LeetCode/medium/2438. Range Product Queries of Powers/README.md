# 2438. Range Product Queries of Powers

[링크](https://leetcode.com/problems/range-product-queries-of-powers/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 숫자를 N, 쿼리의 갯수를 Q라 하자.

입력받은 숫자를 2진법으로 변경해 필요한 2의 거듭제곱들을 구할 수 있다.

이에 O(log_2(N))의 시간 복잡도를 사용한다.

이후 각 쿼리마다 해당 범위의 거듭제곱들의 곱을 구해야 한다.

직접 구할 경우 O(Q \* log_2(N))의 시간 복잡도를 사용한다.

미리 모두 구해놓을 경우 O(Q + (log_2(N))^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

2진수로 변환하는데 log_2(N)의 공간 복잡도를 사용한다.

미리 모두 구해놓는데 O((log_2(N))^2)의 공간 복잡도를 사용한다.

### 2진법 변환

| 내 코드 (ms) |     시간 복잡도     |   공간 복잡도   |
| :----------: | :-----------------: | :-------------: |
|      2       | O(Q + (log_2(N))^2) | O((log_2(N))^2) |

입력받은 수에 포함된 2의 제곱수를 찾기 위해 비트 연산을 사용할 수 있다.

2의 제곱수와 &연산을 수행했을 때 겹치는 경우 배열 powers에 추가한다.

이후 구해놓은 powers에 대해 모든 i,j 쌍에 대한 곱을 미리 구해놓는다.

이후 쿼리마다 정답을 구한다.

```cpp
vector<int> productQueries(int n, vector<vector<int>>& queries) {
  const int MOD = 1e9 + 7;

  vector<int> powers;
  for (int i = 0; i < 32; i++) {
    if (n & (1 << i)) {
      powers.push_back(1 << i);
    }
  }

  vector<int> answer;
  for (vector<int>& q : queries) {
    int left = q[0], right = q[1];

    long long cur = 1;
    for (int i = left; i <= right; i++) {
      cur *= powers[i];
      cur %= MOD;
    }

    answer.push_back(cur);
  }
  return answer;
}
```

## 고생한 점
