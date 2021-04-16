# 119. Pascal's Triangle II

[링크](https://leetcode.com/problems/pascals-triangle-ii/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

index 번째의 파스칼의 삼각형의 row를 구해야 한다. 이전까지 row들을 구하면 현재 row를 구할 수 있다.

이경우 시간 복잡도는 O(N^2)이다. N은 최대 33이므로 최악의 경우 O(1,089) 이다.

파스칼의 삼각형에서 내부 원소를 결정하는 규칙을 알 경우 바로 해당 row를 구할 수 있다.

이경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

이전 row들을 구하는 경우 메모이제이션을 사용하지 않으면 이전에 계산한 결과를 중복해서 사용해야 하기 때문에 제한시간 내에 풀이가 불가능하다.

따라서 메모이제이션을 사용해야 하며 이 때 크기는 O(N^2)이 소요된다.

바로 해당 row를 구하는 경우 공간 복잡도는 O(N)이다.

### 조합론

> 0ms

- 시간 복잡도 : O(N^2)
- 공간 복잡도 : O(N^2)

파스칼의 삼각형의 n번째 row의 i번째 요소의 값은 다음과 같다.

- C(n,i)

여기서 C는 조합에서의 c이다.

따라서 특정 row만 구하고 싶을 경우 combination 함수를 이용해 구할 수 있다.

이 때 combination 함수를 구할 때 연산을 최적화 하기 위해 메모이제이션을 이용한다.

```cpp
int memo[34][34];
vector<int> getRow(int rowIndex) {
  vector<int> answer;

  for (int i = 0; i <= rowIndex; i++) {
    answer.push_back(combination(rowIndex, i));
  }

  return answer;
}

int combination(int n, int c) {
  if (memo[n][c] != 0) return memo[n][c];
  if (n == c || c == 0) {
    memo[n][c] = 1;
    return 1;
  }
  if (c == 1) {
    memo[n][c] = n;
    return n;
  }
  memo[n][c] = combination(n - 1, c) + combination(n - 1, c - 1);
  return memo[n][c];
}
```

### 파스칼의 삼각형

> 0ms

- 시간 복잡도 : O(N)
- 공간 복잡도 : O(N)

파스칼의 삼각형에서 n번째 줄의 i번째 요소의 값은 다음과 같다.

```cpp
pascal[n][i] = pascal[n][i - 1] \* (n - i + 1) / i;
```

위 공식을 이용해 바로 해당 row를 구할 수 있다.

```cpp
class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> res;

    long c = 1;
    for (int i = 1; i <= rowIndex + 1; i++) {
      res.push_back(c);
      c = c * (rowIndex + 1 - i) / i;
    }
    return res;
  }
};
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      0       |

## 고생한 점
