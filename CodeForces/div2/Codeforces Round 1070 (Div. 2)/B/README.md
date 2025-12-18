# B. Optimal Shifts

[링크](https://codeforces.com/contest/2176/problem/B)

| 난이도 |
| :----: |
|        |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

문자열에서 0인 부분을 1로 변경하기 위해선 1인 문자를 한칸씩 이동시키며 0인 부분을 덮어써야 한다.

따라서 연속된 0의 갯수를 순회로 구하는데 O(N)이 소요된다.

### 공간 복잡도

0의 연속된 길이를 저장하는데 O(1)의 공간이 소요된다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      46      |    O(N)     |    O(1)     |

특정 index에 1이 존재할 경우 해당 1을 한칸씩 오른쪽으로 이동시키며 연산을 수행할 경우 모든 값을 1로 변경 가능하다.

따라서 연속된 0의 최대 길이만큼 연산이 필요하다.

이 때 circular하게 이동이 가능하므로 문자열의 앞과 뒤에 존재하는 0의 길이도 합산하여 최대값을 갱신해주면 된다.

```cpp
int solution(int size, string& s) {
  int answer = INT_MAX;

  int zeroMax = 0;
  int zeroCount = 0;
  for (int i = 0; i < size; i++) {
    if (s[i] == '0') {
      zeroCount++;
      zeroMax = max(zeroMax, zeroCount);
    } else {
      zeroCount = 0;
    }
  }

  int prefixZeroCount = 0;
  int suffixZeroCount = 0;
  for (int i = 0; i < size; i++) {
    if (s[i] == '0') {
      prefixZeroCount++;
    } else {
      break;
    }
  }
  for (int i = size - 1; i >= 0; i--) {
    if (s[i] == '0') {
      suffixZeroCount++;
    } else {
      break;
    }
  }
  zeroMax = max(zeroMax, prefixZeroCount + suffixZeroCount);

  return zeroMax;
}
```

## 고생한 점
