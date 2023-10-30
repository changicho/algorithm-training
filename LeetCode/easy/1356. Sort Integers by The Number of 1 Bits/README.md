# 1356. Sort Integers by The Number of 1 Bits

[링크](https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 배열의 크기를 N이라 하자.

정렬에 O(N \* log_2(N))의 시간 복잡도가 소요된다. 각 수의 비트를 세는 데 O(log_2(10^4))의 시간 복잡도를 사용하며 이는 O(1)이다.

### 공간 복잡도

정렬에 최대 O(N)의 공간 복잡도를 사용한다.

### 정리

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      6       | O(N \* log_2(N)) |    O(N)     |

정렬에 사용되는 비교 연산자를 직접 설정해 구현한다.

이 때 비트의 수를 세는 데 내장되어있는 함수를 사용할 수도 있다.

```cpp
__builtin_popcount(num)
```

```cpp
int getScore(int num) {
  int count = 0;
  while (num > 0) {
    count += num % 2;
    num /= 2;
  }
  return count;
}

vector<int> sortByBits(vector<int> &arr) {
  sort(arr.begin(), arr.end(), [&](int &a, int &b) {
    int retA = getScore(a), retB = getScore(b);
    if (retA == retB) return a < b;
    return retA < retB;
  });

  return arr;
}
```

## 고생한 점
