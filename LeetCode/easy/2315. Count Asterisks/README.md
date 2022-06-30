# 2315. Count Asterisks

[링크](https://leetcode.com/problems/count-asterisks/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

s의 길이를 N이라 하자.

각 글자를 순회하며 '|'가 pair를 이룰때와 아닐때의 '\*' 마다 분기하며 count한다.

이 경우 한번의 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

'\*'의 갯수를 세는 데 별도의 공간 복잡도를 사용하지 않는다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(1)     |

현재 pair내부인지 아닌지를 관리하는 변수를 생성한다.

맨 왼쪽부터 순회하며 이후 |를 마주칠 때마다 이를 toggle한다.

\*을 마주한 경우 pair이 아닐때만 정답에 count한다.

```cpp
int countAsterisks(string s) {
  int count = 0;
  bool isPair = false;
  for (char &c : s) {
    if (c == '|') {
      isPair = !isPair;
    } else if (!isPair && c == '*') {
      count++;
    }
  }
  return count;
}
```

## 고생한 점
