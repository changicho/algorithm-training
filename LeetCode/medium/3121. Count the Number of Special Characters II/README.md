# 3121. Count the Number of Special Characters II

[링크](https://leetcode.com/problems/count-the-number-of-special-characters-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 크기를 N이라 하자.

순회를 이용해 조건을 판단할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 알파벳마다 조건을 저장하는데 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      67      |    O(N)     |    O(1)     |

각 알파벳마다 다음 조건이 필요하다.

- 이전에 소문자가 나왔는지
- 이전에 대문자가 나왔는지

이를 이용해 순회하며 정답 조건을 만족하지 못하는 경우 해당 알파벳을 정답에서 제외한다.

이후 정답 조건을 만족하는 알파벳의 수를 센다.

```cpp
int numberOfSpecialChars(string word) {
  int isNotFine = 0;
  int upper = 0;
  int lower = 0;

  for (char& c : word) {
    if (islower(c)) {
      lower |= 1 << (c - 'a');
      if (upper & 1 << (c - 'a')) {
        isNotFine |= 1 << (c - 'a');
      }
    } else {
      upper |= 1 << (c - 'A');
      if (lower & 1 << (c - 'A') == 0) {
        isNotFine |= 1 << (c - 'A');
      }
    }
  }

  int answer = 0;
  for (int i = 0; i < 26; i++) {
    if ((upper & 1 << i) && (lower & 1 << i) && !(isNotFine & 1 << i))
      answer++;
  }
  return answer;
}
```

## 고생한 점
