# 476. Number Complement

[링크](https://leetcode.com/problems/number-complement/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 숫자를 N이라 하자.

2진수로 직접 변환 후 반전하고 다시 변환할 경우 O(log_2(N))의 공간 복잡도를 사용한다.

비트마스킹을 이용해 변환할 경우 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

2진수 변환시 O(log_2(N))의 공간 복잡도를 사용한다.

비트 마스킹을 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 직접 변환

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       | O(log_2(N)) | O(log_2(N)) |

num을 2진수로 변환 후 반전시킨 뒤 다시복구한다.

```cpp
int findComplement(int num) {
  vector<bool> bits;
  while (num > 0) {
    bits.push_back(num % 2 == 0 ? true : false);
    num /= 2;
  }

  int answer = 0;
  for (int i = 0; i < bits.size(); i++) {
    answer += (bits[i] << i);
  }
  return answer;
}
```

### 비트 마스킹

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

비트연산을 이용해 유효한 비트만 추출하고 이를 뒤집는다.

```cpp
int findComplement(int num) {
  unsigned mask = ~0;
  while (num & mask) mask <<= 1;
  return ~mask & ~num;
}
```

## 고생한 점
