# 3498. Reverse Degree of a String

[링크](https://leetcode.com/problems/reverse-degree-of-a-string/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

각 글자를 순회하며 index를 이용해 정답을 구하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 값을 구하는데 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

```cpp
int reverseDegree(string s) {
  int size = s.size();
  int answer = 0;

  for (int i = 0; i < size; i++) {
    char& c = s[i];
    int cur = c - 'a';
    answer += (26 - cur) * (i + 1);
  }
  return answer;
}
```

## 고생한 점
