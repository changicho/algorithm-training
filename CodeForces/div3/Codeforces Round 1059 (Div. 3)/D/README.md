# D. Beautiful Permutation

[링크](https://codeforces.com/contest/2162/problem/D)

| 난이도 |
| :----: |
|  1400  |

## 설계

### 시간 복잡도

순열 P의 크기를 N이라 하자.

순열 P의 특정 구간 left ~ right까지 1을 더한 배열을 A라 하자.

A의 모든 원소의 합과 P의 모든 원소의 합의 차이를 이용해 left ~ right 구간의 길이를 구할 수 있다.

이후 이분 탐색을 이용해 1 ~ X 구간까지의 P의 합과 A의 합을 비교하며 값이 같은 마지막 index를 찾을 수 있다.

이를 이용해 정답을 구할 경우 O(log_2(N))의 시간 복잡도를 가진다.

### 공간 복잡도

각 경우마다 합을 비교하므로 O(1)의 공간 복잡도를 가진다.

### 이분 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     343      | O(log_2(N)) |    O(1)     |

원본 순열 P와 특정 구간에 +1을 더한 A를 비교한다.

P와 A를 다음과 같이 나타낼 수 있다.

```javascript
// O : A와 P가 같은 구간
// X : A와 P가 다른 구간

OOOOOOOOO
OOOXXXOOO

// X 구간의 길이 = A의 합 - P의 합
```

A와 P의 두 배열의 합의 차이를 이용해 특정 구간의 길이를 구할 수 있다.

이 특정 구간을 left ~ right로 표현할 수 있다.

1 ~ (left - 1)까지 구간의 경우 P와 A의 합이 같다.

따라서 이분 탐색을 이용해 1 ~ X 구간까지의 P와 A의 합이 같은 마지막 index를 찾는다.

이후 해당 X+1 ~ X+length 구간이 정답이 된다.

```cpp
long long query(int type, int left, int right) {
  long long x;
  cout << type << ' ' << left << ' ' << right << flush << endl;
  cin >> x;
  return x;
}

vector<int> solution(int n) {
  long long oriSum = 1LL * n * (n + 1) / 2;

  long long sum = query(2, 1, n);

  int length = sum - oriSum;

  int left = 1, right = n;

  // 0 ~ last : oriSum == sum
  // (last + 1) ~ (last + 1 + length) : oriSum < sum
  int last = 0;
  while (left < right) {
    int mid = left + (right - left) / 2;

    long long oriSum = query(1, 1, mid);
    long long sum = query(2, 1, mid);

    if (oriSum >= sum) {
      last = mid;
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  return {last + 1, last + length};
}
```

## 고생한 점
