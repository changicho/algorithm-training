# 3330. Find the Original Typed String I

[링크](https://leetcode.com/problems/find-the-original-typed-string-i/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 word의 길이를 N이라 하자.

순회를 이용해 풀이할 경우 O(N)의 시간 복잡도를 갖는다.

### 공간 복잡도

연이은 문자의 수를 저장하는데 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      5       |    O(N)     |    O(N)     |

연이은 문자들이 존재할 경우, 해당 문자들은 키를 너무 길게 눌러 생성된 것일 수 있다.

따라서 연이은 문자 X가 존재할 때 X의 길이-1개의 경우가 존재할 수 있다.

따라서 순회와 동시에 연이은 문자들의 갯수를 센 뒤, 정답을 증가시킨다.

```cpp
int possibleStringCount(string word) {
  int answer = 0;
  int count = 0;
  char before = word[0];

  for (char &c : word) {
    if (before != c) {
      answer += (count - 1);

      count = 1;
      before = c;
    } else {
      count++;
    }
  }

  answer += count;

  return answer;
}
```

## 고생한 점
