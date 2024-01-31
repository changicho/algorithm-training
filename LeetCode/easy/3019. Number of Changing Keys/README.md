# 3019. Number of Changing Keys

[링크](https://leetcode.com/problems/number-of-changing-keys/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

각 문자열을 순회하며 알파벳 종류가 다를 때마다 count를 증가 시킬 수 있다.

이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

count를 세는데 별도의 공간이 필요하지 않으므로 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

알파벳의 대소문자가 다른것은 구분하지 않는다.

직전 문자를 저장하고 현재 문자와 비교해 다른 경우 count를 증가시킨다.

이 때 직전 문자는 소문자로 변환한다.

```cpp
int countKeyChanges(string s) {
  int size = s.size();

  int answer = 0;

  char before = tolower(s[0]);
  for (char &c : s) {
    if (tolower(c) == before) {
      continue;
    }

    answer++;
    before = tolower(c);
  }

  return answer;
}
```

## 고생한 점
