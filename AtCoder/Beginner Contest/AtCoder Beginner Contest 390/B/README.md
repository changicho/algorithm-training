# B - Geometric Sequence

[링크](https://atcoder.jp/contests/abc390/tasks/abc390_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자. 이 값의 범위를 M이라 하자.

연이은 숫자들의 비율을 구해야 한다. 부동소숫점 오류를 피하기 위해 gcd를 사용할 경우 O(log_2(M))의 시간 복잡도가 소요된다.

이를 모든 수에 대해 구하므로 O(N \* log_2(M))의 시간 복잡도가 필요하다.

### 공간 복잡도

gcd를 구하는 데 공간복잡도는 최대 O(log_2(M))이다.

### gcd

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      1       | O(N \* log_2(M)) | O(log_2(M)) |

두 수의 비율을 구할 때 최대 공약수를 이용해 두개의 정수로 비를 표현한다.

연이은 두 수의 비율을 구하고 이전과 비율이 다른 경우 false를 반환한다.

```cpp
pair<int, int> getRatio(int a, int b) {
  int gcd = __gcd(a, b);
  return {a / gcd, b / gcd};
}

bool solution(int size, vector<int> &nums) {
  pair<int, int> ratio = getRatio(nums[0], nums[1]);

  for (int i = 2; i < size; i++) {
    pair<int, int> cur = getRatio(nums[i - 1], nums[i]);
    if (ratio != cur) {
      return false;
    }
  }
  return true;
}
```

## 고생한 점
