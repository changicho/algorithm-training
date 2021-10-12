# 201. Bitwise AND of Numbers Range

[링크](https://leetcode.com/problems/bitwise-and-of-numbers-range/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 left ~ right에 대해서 모두 탐색할 경우 제한시간 내에 불가능하다.

이는 최악의 경우 시간 복잡도는 O(N) 이며 이는 2^31 - 1이기 때문이다.

AND연산의 성질을 이용해 비트의 most left part를 구해야 한다.

이는 O(log_2(N))의 시간복잡도를 사용한다.

### 공간 복잡도

비트의 most left part를 구하는 데 별도의 공간이 필요하지 않으므로 O(1)의 공간 복잡도를 사용한다.

### find most left part

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(log_2(N)) |    O(1)     |

AND연산의 경우 각 자리수에 하나라도 0이 있는 경우는 해당 자리의 연산 결과는 0이 된다.

따라서 left에서 right까지 모든 수가 1을 유지하는 부분만 찾으면 된다.

26 ~ 30의 경우를 예로 들어보자

```sh
# 26 to 30
11010
11011
11100
11101
11110
```

가장 왼쪽에서부터 1번째, 2번째 비트는 항상 1을 유지함을 알 수 있다.

따라서 left 부터 right까지 가장 왼쪽에서부터 공통된 유지하는 비트를 찾는다.

맨 오른쪽 비트를 없애가면서 left와 right가 같을 때 까지 반복한다.

이 방법으로 most left part를 찾을 수 있다.

해당 비트의 자리수를 복원한 것이 정답이다.

```cpp
int rangeBitwiseAnd(int left, int right) {
  int count = 0;
  while (left != right) {
    ++count;
    left >>= 1;
    right >>= 1;
  }

  int answer = left << count;
  return answer;
}
```

## 고생한 점
