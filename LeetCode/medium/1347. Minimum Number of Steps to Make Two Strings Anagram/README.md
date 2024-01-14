# 1347. Minimum Number of Steps to Make Two Strings Anagram

[링크](https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s, t의 길이를 N이라 하자.

두 문자열의 갯수를 세고 다른 문자의 갯수를 세서 해당 문자들만 변경할 수 있다.

이 경우 순회에 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

알파벳 소문자 26개의 갯수를 저장할 공간이 필요하다. 이에 O(1)의 공간 복잡도를 사용한다.

### 카운팅

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      42      |    O(N)     |    O(1)     |

s와 t를 아나그램으로 만들기 위해선 각각의 문자의 갯수가 같아야 한다.

따라서 s와 t의 각 문자의 갯수를 센 뒤, 각 알파벳의 다른 갯수를 센다.

한 문자를 변경하면 다른 문자의 갯수에 대한 차이가 2개 줄어들게 되므로 다른 문자의 갯수를 2로 나눈 값이 정답이 된다.

- 문자를 하나 변경했을 때 갯수가 아래와 같이 변한다.
- 변경 전 문자 - 1
- 변경 후 문자 + 1
- 따라서 하나의 변화에 갯수는 2개씩 바뀐다.

```cpp
int minSteps(string s, string t) {
  int count1[26] =
      {
          0,
      },
      count2[26] = {
          0,
      };

  for (char &c : s) {
    count1[c - 'a']++;
  }
  for (char &c : t) {
    count2[c - 'a']++;
  }

  int answer = 0;
  for (int i = 0; i < 26; i++) {
    if (count2[i] != count1[i]) {
      answer += abs(count2[i] - count1[i]);
    }
  }
  return answer / 2;
}
```

## 고생한 점
