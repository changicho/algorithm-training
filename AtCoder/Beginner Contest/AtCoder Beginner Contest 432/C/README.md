# C - Candy Tribulation

[링크](https://atcoder.jp/contests/abc432/tasks/abc432_c)

| 난이도 |
| :----: |
|  350   |

## 설계

### 시간 복잡도

입력받은 배열의 크기를 N이라 하자.

방정식을 이용해 각 숫자별로 사탕의 개수를 구할 수 있다.

이에 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

방정식을 푸는데 O(1)의 공간 복잡도가 소요된다.

### 방정식

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      9       |    O(N)     |    O(1)     |

특정 두 num에 대해서 다음 조건을 만족해야 한다.

```cpp
// 두 index를 0, i라 하자.
(nums[i] - b[i]) * x + b[i] * y == (nums[0] - b[0]) * x + b[0] * y

// 위 식을 변환하면 아래처럼 된다.
b[i] == b[0] - (nums[i] - nums[0]) * x / (y - x)

// 아래 부분을 D[i]라 하자.
(nums[i] - nums[0]) * x / (y - x) == D[i]
```

여기서 `b[i]` 는 0이상이여야만 한다. 따라 서 `D[i]` 는 `b[0]` 이하가 되어야 한다.

여기서 최대값을 만들기 위해선 특정 num에서 큰 캔디만을 선택해야 한다.

따라서 `b[0]`과 `nums[0]`을 고정할 수 있다. 이는 nums 중 최소값이 된다.

따라서 위 식을 아래와 같이 바꿀 수 있다.

```cpp
b[i] == nums[0] - (nums[i] - nums[0]) * x / (y - x)

// 여기서 위 식을 변환하면 아래처럼 된다.
b[i] == nums[i] - (nums[i] - nums[0]) * y / (y - x)

// 변환 과정
(A1 * (Y - X) - (Ak - A1) * X) / (Y - X) // 이 식을 풀면 아래처럼 된다

(A1 * Y - A1 * X - Ak * X + A1 * X) / (Y - X) // 이걸 정리하면
(A1 * Y - Ak * X) / (Y - X) // 가 되며 여기에 분자에 Ak * Y - Ak * Y 를 더해준다.

(A1 * Y - Ak * X + Ak * Y - Ak * Y) / (Y - X) // 이걸 정리하면
(Ak * (Y - X) - Y * (Ak - A1)) / (Y - X)

(Ak - (Ak - A1) * Y) / (Y - X) // 최종식

// 따라서
(A1 * (Y - X) - (Ak - A1) * X) / (Y - X) == (Ak - (Ak - A1) * Y) / (Y - X)
```

따라서 `b[i] == nums[i] - (nums[i] - nums[0]) * y / (y - x)` 식을 이용해 각 b값을 구한다.

이 때 nums[0]은 nums의 최소값이 된다.

만약 분자를 분모로 나눴을 때 나누어 떨어지지 않는 경우 정답이 없는 경우이므로 -1을 반환한다.

```cpp
long long solution(int size, vector<long long>& nums, int x, int y) {
  long long minimum = *min_element(nums.begin(), nums.end());

  long long sum = 0;

  // (nums[i] - b[i]) * x + b[i] * y = (nums[0] - b[0]) * x + b[0] * y
  // b[i] = b[0] - (nums[i] - nums[0]) * x / (y - x)

  // b[i] = nums[i] - (nums[i] - nums[0]) * y / (y - x)
  for (int i = 0; i < size; i++) {
    long long vs = (nums[i] - minimum) * y;
    long long vt = (y - x);

    if (vs % vt != 0) {
      return -1;
    }
    long long minor = vs / vt;

    if (minor > nums[i]) {
      return -1;
    }
    long long b = nums[i] - minor;
    sum += b;
  }
  return sum;
}
```

## 고생한 점
