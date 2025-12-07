# C. Beautiful XOR

[링크](https://codeforces.com/contest/2162/problem/C)

| 난이도 |
| :----: |
|  1100  |

## 설계

### 시간 복잡도

입력받은 두 수를 A, B라 하자.

A의 비트마다 B의 비트로 변경하는 XOR 연산을 수행할 수 있다.

이를 비트마다 순회하는 경우 O(log_2(A))의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(log_2(A))의 공간 복잡도를 사용한다.

### 비트 조합

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      61      | O(log_2(A)) | O(log_2(A)) |

숫자 A를 B로 변경하기 위해 각 비트를 순회하며 변경해야하는지 판단한다.

만약 현재 비트를 변경해야 하는 경우 현재 비트만 포함된 수를 정답에 추가한다.

즉 현재 비트와 A를 XOR 연산하는 경우 해당 비트를 제외한 나머지는 유지하며 현재 비트만 변경된다.

이 때 A보다 커지는 2^i 비트는 불가능하므로 순회를 종료한다.

만약 정답에 추가된 수들로 A를 B로 변경하지 못하는 경우 -1을 반환한다.

```cpp
auto solution(int a, int b) {
  vector<int> answer;

  int temp = a;

  for (int i = 0; i <= 31; i++) {
    int digit = 1 << i;
    if (digit > a) break;

    if ((a & digit) == (b & digit)) continue;

    int cur = 0;
    cur += digit;

    answer.push_back(cur);
    temp ^= cur;
  }

  if (temp != b) {
    return vector<int>{-1};
  }

  return answer;
}
```

## 고생한 점
