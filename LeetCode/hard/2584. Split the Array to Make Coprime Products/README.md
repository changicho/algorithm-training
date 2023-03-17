# 2584. Split the Array to Make Coprime Products

[링크](https://leetcode.com/problems/split-the-array-to-make-coprime-products/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

nums의 크기를 N, nums의 값 중 최대값을 M이라 하자. (N <= 10^4, M <= 10^6)

prefix, suffix의 gcd가 1이 되는 경우는 두 구간의 공통된 소인수가 없는 경우이다.

하나의 num에 소인수 분해를 수행할 경우 O(sqrt(M)) 이다.

이를 모든 num에 대해 수행할 경우 O(N \* sqrt(M)) 이 소요된다.

nums를 prefix와 suffix로 나눌 경우 각 경우에 O(N)의 시간 복잡도를 사용한다.

각 과정을 탐색하며 현재 num의 소인수 분해와 각 부분의 소인수들이 겹치는지를 판단할 수 있다.

따라서 총 시간 복잡도는 O(N \* sqrt(M)) 이다.

### 공간 복잡도

에라토스테네스의 채를 이용해 소수를 구할 경우 O(sqrt(M))의 공간 복잡도가 필요하다.

각 prefix, suffix에 대한 소인수를 저장하는데 O(sqrt(M))의 공간 복잡도가 필요하다.

### 소인수분해 & 소인수 count

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|     469      | O(N \* sqrt(M)) | O(sqrt(M))  |

각 값들을 소인수 분해하고, 유일한 소인수들을 반환한다.

소인수를 분해할 때, sqrt(M)까지만 탐색하면 된다.

이는 sqrt(M)까지만 소인수 분해를 했을때, 남은 수는 무조건 소수이기 때문이다.

(두 소수 A, B에 대해서 A \* B가 M일 때 A와 B중 한 수는 무조건 sqrt(M) 이하이다. 만약 A또는 B가 소수가 아닌 경우 이전 소인수 분해에서 이미 소인수로 나누어져 있으므로 무조건 sqrt(M) 이하이다.)

이 때 prefix, suffix에 있는 소인수들이 겹치지 않는 경우 두 구간의 gcd값은 1이 된다.

따라서 각 구간의 소인수들을 count하고, 겹치는 소인수들의 개수를 구한다.

이를 모든 구간에 대해 직접 구할 경우 탐색에만 O(N^2)의 시간 복잡도를 사용하므로, index를 증가시키며 이전의 결과를 이용한다.

모든 값에 대한 소인수들을 모두 suffix에 count한다.

이후 index를 증가시키면서 현재까지의 소인수들을 prefix에 count한다.

이 때 현재 소인수에 대해 prefix에서 처음 소인수가 증가하는 경우와, prefix의 소인수의 갯수가 suffix와 같아지는 경우를 구분해 생각할 수 있다.

처음 소인수가 증가하는 경우는 현재 소인수가 suffix와 prefix에 공통된 소인수가 되는 경우이다.

prefix의 소인수의 갯수가 suffix와 같아지는 경우는 현재 소인수가 prefix에 전부 있으므로 더이상 공통된 소인수가 되지 않는 경우이다.

이를 이용해 두 구간의 소인수들이 겹치는지를 판단한다.

```cpp
vector<int> factorize(int num) {
  vector<int> res;
  for (int divider = 2; num > 1 && divider < 1000;
        divider += 1 + (divider % 2)) {
    if (num % divider == 0) {
      res.push_back(divider);

      while (num % divider == 0) {
        num /= divider;
      }
    }
  }

  if (num > 1) res.push_back(num);
  return res;
}

int findValidSplit(vector<int>& nums) {
  int size = nums.size();

  unordered_map<int, int> left, right;

  for (int num : nums) {
    for (int factor : factorize(num)) {
      right[factor]++;
    }
  }

  for (int i = 0, common = 0; i < size - 1; i++) {
    int num = nums[i];

    for (int factor : factorize(num)) {
      if (left[factor] == 0) common++;
      left[factor]++;
      if (left[factor] == right[factor]) common--;
    }

    if (common == 0) return i;
  }

  return -1;
}
```

### 소인수분해 & 소인수 count & 에라토스테네스의 채

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|     252      | O(N \* sqrt(M)) | O(sqrt(M))  |

위 방법에서 에라토스테네스의 채를 이용해 소수를 미리 구하고 사용해 시간을 단축한다.

```cpp
bool isNotPrime[1001];

vector<int> primes;

vector<int> factorize(int num) {
  vector<int> res;
  for (int& prime : primes) {
    if (num % prime == 0) {
      res.push_back(prime);

      while (num % prime == 0) {
        num /= prime;
      }
    }
  }

  if (num > 1) res.push_back(num);
  return res;
}

int findValidSplit(vector<int>& nums) {
  int size = nums.size();

  for (int num = 2; num <= 1e3; num++) {
    if (isNotPrime[num]) continue;

    for (int multiple = 2 * num; multiple <= 1e3; multiple += num) {
      isNotPrime[multiple] = true;
    }
  }

  for (int num = 2; num <= 1e3; num++) {
    if (!isNotPrime[num]) primes.push_back(num);
  }

  unordered_map<int, int> left, right;

  for (int num : nums) {
    for (int factor : factorize(num)) {
      right[factor]++;
    }
  }

  for (int i = 0, common = 0; i < size - 1; i++) {
    int num = nums[i];

    for (int factor : factorize(num)) {
      if (left[factor] == 0) common++;
      left[factor]++;
      if (left[factor] == right[factor]) common--;
    }

    if (common == 0) return i;
  }

  return -1;
}
```

## 고생한 점
