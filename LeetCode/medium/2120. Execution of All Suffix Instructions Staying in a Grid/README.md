# 2120. Execution of All Suffix Instructions Staying in a Grid

[링크](https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 L이라 하자.

각 문자열의 index마다 순회하며 이후에 나오는 연산들을 수행할 수 있는지 판단해야한다.

한번의 index마다 O(L)의 시간 복잡도로 순회를 하므로 총 시간 복잡도는 O(L^2)이다.

### 공간 복잡도

정답을 생성하는데 O(L)의 공간 복잡도를 사용한다.

좌표의 넘침 판단은 단순 숫자로 가능하므로 O(1)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      45      |   O(L^2)    |    O(L)     |

문자열의 시작점을 순회하며 이후 나오는 operation들을 수행하며 좌표의 범위를 벗어나는지를 판단한다.

```cpp
vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
  int length = s.length();

  vector<int> answer;
  for (int left = 0; left < length; left++) {
    int y = startPos[0], x = startPos[1];
    int count = 0;

    for (int i = left; i < length; i++) {
      char operation = s[i];

      switch (operation) {
        case 'U': {
          y -= 1;
          break;
        }
        case 'R': {
          x += 1;
          break;
        }
        case 'D': {
          y += 1;
          break;
        }
        case 'L': {
          x -= 1;
          break;
        }
      }

      if (y < 0 || y >= n || x < 0 || x >= n) break;
      count++;
    }

    answer.push_back(count);
  }

  return answer;
}
```

## 고생한 점
