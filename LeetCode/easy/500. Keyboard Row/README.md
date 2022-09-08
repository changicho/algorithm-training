# 500. Keyboard Row

[링크](https://leetcode.com/problems/keyboard-row/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 words의 모든 글자의 수를 N이라 하자.

a-z까지 순회하며 키보드의 줄로 해당한다.

이후 각 word를 순회하며 해당 글자가 어느 줄을 입력해야 하는지 저장한다.

이 경우 모든 words를 순회하므로 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 키마다 해당하는 줄을 저장한다. 해당 공간에 O(1)의 공간 복잡도를 사용한다.

정답에 O(N)의 공간 복잡도를 사용한다.

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(N)     |

각 키에 해당하는 줄을 저장한다.

이후 각 word를 순회하며 해당 단어를 입력하는데 필요한 줄이 2줄 이상인 경우 정답에 추가하지 않는다.

```cpp
vector<string> findWords(vector<string> &words) {
  string lines[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

  int colors[256] = {
      0,
  };
  for (int color = 0; color < 3; color++) {
    for (char c : lines[color]) {
      colors[c] = color;
    }
  }

  vector<string> answer;
  for (string &word : words) {
    set<int> need;

    for (char &c : word) {
      int color = colors[tolower(c)];
      need.insert(color);
    }

    if (need.size() == 1) {
      answer.push_back(word);
    }
  }
  return answer;
}
```

## 고생한 점
