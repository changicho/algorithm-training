# 422. Valid Word Square

[링크](https://leetcode.com/problems/valid-word-square/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

words 내부에서 행, 열로 가장 긴 문자열의 길이를 N이라 하자.

각 좌표를 순회하며 행, 열 문자열이 같은지 확인해야 하므로 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

words에 빈 칸을 모두 채울 경우 O(N^2)의 공간 복잡도를 사용한다.

words의 좌표들을 순회하며 풀이할 경우 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |   O(N^2)    |   O(N^2)    |

가장 긴 행 또는 열의 길이 K를 구한 뒤 words의 빈칸들을 채운다.

이후 각 좌표를 순회하며 조건에 어긋난 것들이 있는지 검사한다.

```cpp
bool validWordSquare(vector<string> &words) {
  int length = words.size();
  for (string &w : words) {
    int cur = w.length();
    length = max(length, cur);
  }
  while (words.size() < length) {
    words.push_back(string(length, ' '));
  }
  for (string &w : words) {
    while (w.length() < length) {
      w += " ";
    }
  }

  for (int y = 0; y < length; y++) {
    for (int i = 0; i < length; i++) {
      if (words[y][i] != words[i][y]) return false;
    }
  }
  return true;
}
```

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      20      |   O(N^2)    |    O(1)     |

각 word와 word의 각 index를 순회하며 판별한다.

```cpp
bool validWordSquare(vector<string> &words) {
  for (int y = 0; y < words.size(); y++) {
    for (int x = 0; x < words[y].size(); x++) {
      if (x >= words.size() || words[x].size() <= y || words[x][y] != words[y][x]) {
        return false;
      }
    }
  }
  return true;
}
```

## 고생한 점
