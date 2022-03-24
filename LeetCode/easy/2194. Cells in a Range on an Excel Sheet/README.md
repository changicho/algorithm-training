# 2194. Cells in a Range on an Excel Sheet

[링크](https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

알파벳의 범위를 N, 숫자의 범위를 M이라 하자.

한번씩 순회하며 가능한 세트를 만들어야 하므로 O(N \* M)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답의 경우의 수는 최대 N \* M개를 만들 수 있으므로 공간 복잡도는 O(N \* M)이다.

### 브루트 포스

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |  O(N \* M)  |  O(N \* M)  |

입력받은 s에서 알파벳, 숫자의 범위를 가져오고 순회하며 정답에 추가한다.

```cpp
vector<string> cellsInRange(string s) {
  int charFrom = s[0], charTo = s[3];
  int numFrom = s[1], numTo = s[4];

  vector<string> answer;
  for (char c = charFrom; c <= charTo; c++) {
    for (char num = numFrom; num <= numTo; num++) {
      answer.push_back({c, num});
    }
  }

  return answer;
}
```

## 고생한 점
