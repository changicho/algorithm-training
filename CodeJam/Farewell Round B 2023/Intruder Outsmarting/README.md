# Intruder Outsmarting (4pts, 10pts)

[링크](https://codingcompetitions.withgoogle.com/codejam/round/0000000000c9607c/0000000000cad13d)

## 설계

### 시간 복잡도

입력받은 숫자의 갯수를 W, 숫자의 최대 크기를 N이라 하자.

각 숫자를 회문으로 만들기 위해 양 끝에서부터 비교해봐야 한다. 이에 O(W)의 시간 복잡도를 사용한다.

이후 각 숫자쌍 마다 같은 수로 만들기 위한 최소 횟수를 구해야 한다.

이에 확장 유클리드 알고리즘을 사용한다. 이에 O(log_2(N))의 시간 복잡도를 사용한다.

따라서 총 O(W \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

확장 유클리드 알고리즘을 재귀로 구현할 경우 O(log_2(N))의 공간 복잡도를 사용한다.

반복문으로 구현할 경우 O(1)의 공간 복잡도를 사용한다.

### 확장 유클리드 알고리즘

|   시간 복잡도    | 공간 복잡도 |
| :--------------: | :---------: |
| O(W \* log_2(N)) |    O(1)     |

확장 유클리드 알고리즘은 다음과 같이 구현 가능하다.

```cpp
// recursive
vector<long long> extended_gcd(long long a, long long b) {
  if (a == 0) {
    return {b, 0, 1};
  }

  // gcd, x, y
  vector<long long> ret = extended_gcd(b % a, a);
  long long gcd = ret[0], x = ret[1], y = ret[2];

  return {gcd, (y - (b / a) * x), x};
}

// loop
vector<long long> extended_gcd(long long a, long long b) {
  long long x = 1, y = 0;

  if (0 == b) return {a, x, y};

  long long new_x = 0, new_g = 1, new_r = b;
  long long g = a;
  while (new_r) {
    long long quotient = g / new_r;
    long long tmp = g;

    g = new_r;
    new_r = tmp - quotient * new_r;

    tmp = x;
    x = new_x;
    new_x = tmp - quotient * new_x;

    tmp = y;
    y = new_g;
    new_g = tmp - quotient * new_g;
  }
  return {g, x, y};
}
```

두 수 a, b에 대해 다음과 같은 식이 성립한다.

- D \* x + N \* y = (a - b)

여기서 x가 의미하는 것은 두 수를 같게 만들기 위한 움직이는 횟수이다.

이를 구하기 위해 확장 유클리드 알고리즘을 사용한다.

이를 통해 x, y 그리고 D와 N의 최대공약수 g를 구할 수 있다.

만약 (a-b)가 g로 나누어 떨어지지 않는 경우 두 수를 같게 만들 수 없으므로 이는 불가능하다.

이후 x, y를 이용해 a, b를 같게 만들 수 있는 최소 횟수를 구할 수 있다.

a에서 D를 더하며 만들 수 있는 수의 갯수를 loop라 하자. 이는 N을 g로 나눈 값과 같다.

해당 loop에서 a->b로 만들 때의 횟수와 b->a로 만들 때의 횟수를 비교해 최소값을 반환한다.


```cpp
vector<long long> extended_gcd(long long a, long long b) {
  long long x = 1, y = 0;

  if (0 == b) return {a, x, y};

  long long new_x = 0, new_g = 1, new_r = b;
  long long g = a;
  while (new_r) {
    long long quotient = g / new_r;
    long long tmp = g;

    g = new_r;
    new_r = tmp - quotient * new_r;

    tmp = x;
    x = new_x;
    new_x = tmp - quotient * new_x;

    tmp = y;
    y = new_g;
    new_g = tmp - quotient * new_g;
  }
  return {g, x, y};
}

long long getDistance(long long dist, long long limit, long long x1,
                      long long x2) {
  vector<long long> ret = extended_gcd(dist, limit);
  long long diff = x1 - x2;
  long long g = ret[0], x = ret[1], y = ret[2];

  if (diff % g != 0) return -1;

  // dist * x + limit * y = diff
  x *= (diff / g);
  y *= (diff / g);

  long long move = x % (limit / g);

  return min(abs(move), limit / g - abs(move));
}

long long solution(long long size, vector<long long> &nums, long long limit,
                   long long dist) {
  long long answer = 0;
  int left = 0, right = size - 1;

  while (left < right) {
    long long leftVal = nums[left], rightVal = nums[right];

    // minimum movement to make nums[left] == nums[right]
    long long minimumCount = getDistance(dist, limit, leftVal, rightVal);

    if (minimumCount == -1) return -1;
    answer += minimumCount;

    left++, right--;
  }

  return answer;
}
```

## 고생한 점
