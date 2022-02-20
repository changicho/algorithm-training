# 1492. The kth Factor of n

[링크](https://leetcode.com/problems/the-kth-factor-of-n/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 숫자를 N, K라 하자.

N의 약수의 갯수를 M이라 가정하자.

N의 약수들을 찾기 위해 1부터 sqrt(N)까지 순회하며 나누어떨어지는지 확인해 작은 원소들을 구할 수 있다.

이후 찾은 약수들을 정렬하고 K번째 수를 구할 수 있다. 이 경우 시간 복잡도는 O(sqrt(N) + M \* log_2(M))이다.

힙을 이용해 K개의 수만 탐색해 문제를 풀이할 수 있다.

이 경우 sqrt(N)까지 순회하며 힙의 갱신 연산만 수행하면 되므로 시간 복잡도는 O(sqrt(N) \* log_2(K))가 된다.

수학적인 방법을 이용해 약수들 중 작은 부분만 구하고 이를 이용해 나머지 약수에 대해 구할 수 있다.

이 경우 작은 약수를 구하기위해 O(sqrt(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

약수들을 모두 구할 경우 O(M)의 공간 복잡도를 사용한다.

K개의 약수만 유지하며 구할 경우 O(K)의 공간 복잡도를 사용한다.

약수의 작은 부분만 사용할 경우 O(min(K, sqrt(N)))의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |        시간 복잡도         | 공간 복잡도 |
| :----------: | :------------------------: | :---------: |
|      5       | O(sqrt(N) + M \* log_2(M)) |    O(M)     |

모든 약수를 구한 뒤 정렬하고 K번째 약수를 구한다.

이 때 약수를 구하기 위해 sqrt(N)까지만 순회를 진행한다.

```cpp
int kthFactor(int n, int k) {
  vector<int> factors;

  int sqrtN = sqrt(n);
  for (int num = 1; num <= sqrtN; num++) {
    if (n % num != 0) continue;

    factors.push_back(num);
    if (num != n / num) factors.push_back(n / num);
  }

  sort(factors.begin(), factors.end());
  if (k - 1 >= factors.size()) return -1;
  return factors[k - 1];
}
```

### heap

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|      0       | O(sqrt(N) \* log_2(K)) |    O(K)     |

약수를 구하며 힙에 K개의 원소만 유지되도록 제한한다.

이후 힙의 top에 있는 원소가 K개의 원소이다.

이 때 힙의 크기가 K보다 작은 경우는 정답이 존재하지 않는 경우이다.

```cpp
int kthFactor(int n, int k) {
  priority_queue<int> factors;

  int sqrtN = sqrt(n);
  for (int num = 1; num <= sqrtN; num++) {
    if (n % num != 0) continue;

    factors.push(num);
    if (num != n / num) factors.push(n / num);

    while (factors.size() > k) {
      factors.pop();
    }
  }

  if (k != factors.size()) return -1;
  return factors.top();
}
```

### math, 작은 약수

| 내 코드 (ms) | 시간 복잡도 |    공간 복잡도     |
| :----------: | :---------: | :----------------: |
|      0       | O(sqrt(N))  | O(min(K, sqrt(N))) |

1부터 sqrt(N)에 대해서 작은약수들을 구할 수 있다.

이후 K번째 약수를 구하기 위해 작은 약수의 index를 이용해 K번째를 구한다.

즉 K번째 약수는 K < (M / 2)인 상황에서는 작은 약수배열의 K번째가 되고,

큰 약수에서 찾아야하는 경우는 (M / 2) - K 번째 약수를 찾으면 된다.

이 때 N이 어떤 수의 제곱인 경우는 sqrt(N)이 중복되므로 이에 대해 예외 처리한다.

```cpp
int kthFactor(int n, int k) {
  vector<int> smalls;

  int sqrtN = sqrt(n);
  // we can first ~ k'th factor
  for (int num = 1; num <= sqrtN; num++) {
    if (n % num != 0) continue;

    k--;
    smalls.push_back(num);
    if (k == 0) return num;
  }

  // if n is perfect square
  if (sqrtN * sqrtN == n) {
    k++;
  }

  int smallSize = smalls.size();

  if (k <= smallSize) {
    return n / smalls[smallSize - k];
  }
  return -1;
}
```

## 고생한 점
