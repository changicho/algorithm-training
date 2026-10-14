# 4079. Prime Subset Selection I

[링크](https://leetcode.com/problems/prime-subset-selection-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

에라토스테네스의 체를 이용해 N까지의 소수를 구한 뒤 이를 순서대로 더해가며 S이하의 합을 만드는 배열을 생성한다.

이에 O(N \* log_2(log_2(N)))의 시간 복잡도를 사용한다.

### 공간 복잡도

에라토스테네스의 체에 O(N)의 공간 복잡도를 사용한다.

### 에라토스테네스의 체

| 내 코드 (ms) |       시간 복잡도       | 공간 복잡도 |
| :----------: | :---------------------: | :---------: |
|     230      | O(N \* log_2(log_2(N))) |    O(N)     |

에라토스테네스의 체를 이용해 N까지의 소수를 판별한다.

이후 각 수를 순회하며 소수인 경우 현재까지 합에 더해보고 S를 넘지 않는경우 정답에 더한다.

이후 정답 배열을 반환한다.

```cpp
vector<int> maxPrimes(int n, int s) {
  bool isNotPrime[1000001] = {
      false,
  };
  isNotPrime[1] = true;
  for (int i = 2; i * i <= n; i++) {
    for (int j = i * i; j <= n; j += i) {
      isNotPrime[j] = true;
    }
  }

  vector<int> answer;
  long long sum = 0;
  for (int p = 2; p <= n; p++) {
    if (isNotPrime[p]) continue;

    if (sum + p > s) break;
    answer.push_back(p);
    sum += p;
  }

  return answer;
}
```

## 고생한 점
