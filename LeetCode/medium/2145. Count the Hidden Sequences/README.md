# 2145. Count the Hidden Sequences

[링크](https://leetcode.com/problems/count-the-hidden-sequences/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 differences의 크기를 N이라 하자.

각 diff를 더해가며 이 중 최대값과 최소값을 찾는다.

해당 값의 range와 입력받은 range를 비교해 차이를 구할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

차이를 구하는 데 별도의 배열을 사용하지 않으므로 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

differences를 순회하며 연이은 값들의 최대, 최소 값을 구한다.

해당 두 값의 차이가 값들을 모두 포함하는 range가 된다.

해당 range와 lower, upper의 차이를 구하면 hidden sequence의 개수를 구할 수 있다.

```cpp
int numberOfArrays(vector<int>& differences, int lower, int upper) {
  long long cur = 0;
  long long maximum = 0, minimum = 0;
  for (int& diff : differences) {
    cur += diff;
    maximum = max(cur, maximum);
    minimum = min(cur, minimum);
  }

  long long diff = maximum - minimum;
  long long diffRange = (long long)upper - lower;

  return max(diffRange - diff + 1, 0LL);
}
```

## 고생한 점
