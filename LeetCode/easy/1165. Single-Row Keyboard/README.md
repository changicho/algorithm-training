# 1165. Single-Row Keyboard

[링크](https://leetcode.com/problems/single-row-keyboard/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

word의 길이를 N이라 하자.

각 글자마다의 키보드 위치를 이동하며 cost를 계산해야 한다.

따라서 글자의 순회에 O(N)의 시간 복잡도를 사용한다.

각 글자마다의 위치를 배열에 저장해 사용할 경우 O(1)의 시간 복잡도로 검색이 가능하다.

### 공간 복잡도

각 글자마다의 위치를 저장할 경우 O(1)의 공간 복잡도를 사용한다.

### 테이블

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |    O(N)     |    O(1)     |

```cpp
int calculateTime(string keyboard, string word) {
  int indexes[26] = {
      0,
  };
  for (int i = 0; i < 26; i++) {
    char cur = keyboard[i];

    indexes[cur - 'a'] = i;
  }

  int answer = 0;
  int before = 0;
  for (char &c : word) {
    answer += abs(before - indexes[c - 'a']);
    before = indexes[c - 'a'];
  }
  return answer;
}
```

## 고생한 점
