# 2551. Put Marbles in Bags

[링크](https://leetcode.com/problems/put-marbles-in-bags/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 배열의 크기를 N, 수를 K라 하자. (K <= N <= 10^5)

N에 대해 가능한 모든 경우를 탐색할 경우 combination(N-1, K-1)가지 경우를 모두 탐색해야 한다.

이는 매우 크며 각 과정마다 O(N)의 시간 복잡도를 사용하므로 제한시간 내에 불가능하다.

cost를 계산할 때 포함되는 값의 boundary에 대해 정렬 후 큰순으로 K-1개, 작은순으로 K-1개를 뽑아 정답을 구할 수 있다.

이 경우 정렬에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 K개의 값을 뽑는 데 O(K)의 시간 복잡도를 사용한다.

### 공간 복잡도

boundary값의 합을 저장하는데 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |     시간 복잡도      | 공간 복잡도 |
| :----------: | :------------------: | :---------: |
|     209      | O(N \* log_2(N) + K) |    O(N)     |

아래 배열에 대해서 K 조각으로 나눴을 때의 cost에 대해 생각해보자.

```javascript
const arr = [A, B, C, D, E, F]

// 여기서 A, F는 한번씩 cost에 무조건 들어감

// 임의로 2조각을 나눈다 하자. (K = 2)
// 여기서 C,D가 boundary이므로 cost에 들어간다.
[A,B,C], [D,E,F]
const cost = A + C + D + F

// 임의로 3조각을 나눈다 하자. (K = 3)
// 여기서 B,C, C,D가 boundary이므로 cost에 들어간다.
[A,B], [C], [D,E,F]
const cost = A + B + C + C + D + F

// 즉 정답에 무조건 포함되는 A, F를 제외하고는 boundary의 K-1개의 합으로 정답을 구할 수 있다.
```

따라서 가능한 boundary를 모두 구한 뒤 정렬 후 큰순,작은순으로 K-1개를 뽑고 이 차이를 구한다.

```cpp
long long putMarbles(vector<int>& weights, int k) {
  int size = weights.size();
  if (size == k) return 0;

  vector<long long> diffs;
  for (int i = 0; i < size - 1; i++) {
    diffs.push_back(weights[i + 1] + weights[i]);
  }
  sort(diffs.begin(), diffs.end());

  long long minimum = 0;
  long long maximum = 0;
  for (int i = 0; i < k - 1; i++) {
    minimum += diffs[i];
    maximum += diffs[size - 2 - i];
  }

  return maximum - minimum;
}
```

## 고생한 점
