# E. Living Sequence

[링크](https://codeforces.com/contest/1811/problem/E)

## 시간 복잡도

입력받은 숫자를 N이라 하자. (N <= 10^12)

1부터 N번째 '4'가 없는 숫자를 구할 경우 O(N)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

9진수 변환 이후 수를 변경할 경우 O(log_9(N))의 시간 복잡도를 사용한다.

## 공간 복잡도

9진수 변환 이후 수를 변경할 경우 O(log_9(N))의 공간 복잡도를 사용한다.

## 9진수 변환

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
| O(log_9(N)) | O(log_9(N)) |

숫자 4만 사라지는 것이므로 기존 10진수에서 9진수 변환을 수행하면 된다.

이후 4~8의 경우 5~9로 치환시킨다.

```cpp
string convert(long long k) {
  string ret = "";

  while (k > 0) {
    ret += to_string(k % 9);
    k /= 9;
  }

  reverse(ret.begin(), ret.end());

  return ret;
}

auto solution(long long k) {
  string converted = convert(k);

  int size = converted.size();
  for (int i = 0; i < size; i++) {
    if (converted[i] >= '4') {
      converted[i] = converted[i] + 1;
    }
  }

  return converted;
}
```