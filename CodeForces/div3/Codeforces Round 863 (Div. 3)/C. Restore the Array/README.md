# C. Restore the Array

[링크](https://codeforces.com/contest/1811/problem/C)

## 시간 복잡도

입력받은 배열의 크기를 N이라 하자.

각 수를 왼쪽부터 순회하며 변환된 배열 B의 값과 직전 값을 비교해 채워넣는다.

이 경우 순회에 O(N)의 시간 복잡도를 사용한다.

## 공간 복잡도

별도의 배열을 생성해야 하므로 O(N)의 공간 복잡도를 사용한다.

## 순회

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(N)     |

B의 값은 다음과 같이 정의된다.

```cpp
B[i] = max(A[i], A[i+1]);
```

즉 이를 이용해 A의 현재값과 이전값 중 큰 값이 B의 현재값이 된다.

따라서 왼쪽에서 부터 순회를 지속하며 값을 채워 넣는다.

만약 이전 값이 현재 B의 값에 영향을 주는 경우 현재 값을 0으로 채워넣는다. (초기값)

만약 B의 값이 감소하는 경우 현재 채워넣은 값이 B의 다음값에 영향을 줄 수 있으므로 직전 값과 현재 값을 swap한다.

```cpp
auto solution(int size, vector<int> &converted) {
  vector<int> arr(size, 0);
  arr[0] = converted[0];
  for (int i = 1; i < size; i++) {
    // converted[i-1] = max(arr[i-1], arr[i]);

    if (converted[i - 1] == arr[i - 1]) {
      arr[i] = 0;
    } else {
      arr[i] = converted[i - 1];
    }
    if (i + 1 < size && converted[i - 1] > converted[i] &&
        arr[i] > arr[i - 1]) {
      swap(arr[i], arr[i - 1]);
    }
  }

  return arr;
}
```