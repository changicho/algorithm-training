# 186. Reverse Words in a String II

[링크](https://leetcode.com/problems/reverse-words-in-a-string-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

문자열을 한번 순회하며 뒤집어야 하므로 outer 시간 복잡도는 O(N)이다.

내부적으로 subString들을 뒤집는 모든 연산의 시간 복잡도는 O(N) 이다.

결과적으로 모든 문자를 한번 순회하면 되므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

index만을 이용해 뒤집을 경우 별도의 배열이 필요하지 않다.

따라서 공간 복잡도는 O(1)이다.

### part reverse, total reverse

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |    O(N)     |    O(1)     |

각 단어들의 순서를 뒤바꿔주면 된다.

이는 모든 문자를 뒤집은 뒤, 각 단어들을 다시 뒤집을 경우 형태는 유지하되, 순서만 바꿀 수 있다.

이를 이용해 각 경우별로 뒤집을 index들만 사용해 공간 복잡도를 줄일 수 있다.

```cpp
  int left = 0, right = 0;

  for (char c : s) {
    if (c == ' ') {
      reverse(s.begin() + left, s.begin() + right);

      left = right + 1;
    }
    right += 1;
  }
  reverse(s.begin() + left, s.begin() + right);

  reverse(s.begin(), s.end());
}
```

## 고생한 점
