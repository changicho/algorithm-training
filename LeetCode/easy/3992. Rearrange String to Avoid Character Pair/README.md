# 3992. Rearrange String to Avoid Character Pair

[링크](https://leetcode.com/problems/rearrange-string-to-avoid-character-pair/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

앞서야 하는 문자를 최대한 앞으로 옮기는 방법을 사용할 수 있다. 이에 투 포인터를 사용할 경우 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

입력받은 문자열을 그대로 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

y에 해당하는 문자들은 x보다 앞서야 한다.

또한 정답 문자열에서 x에 해당하는 문자들은 모두 y보다 뒤에 위치해야 한다.

따라서 모든 y에 해당하는 문자를 최대한 앞으로 옮기는 방법을 사용할 수 있다.

이를 위해 투 포인터를 사용한다.

```cpp
string rearrangeString(string s, char x, char y) {
  int size = s.size();

  for (int i = 0, j = 0; i < size; i++) {
    if (s[i] == y) {
      swap(s[i], s[j]);
      j++;
    }
  }

  return s;
}
```

## 고생한 점
