# 838. Push Dominoes

[링크](https://leetcode.com/problems/push-dominoes/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 dominoes의 길이를 N이라 하자.

모든 경우를 직접 순회할 경우 O(N^2)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

한번의 순회로 해결할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

입력받은 문자열을 수정할 경우 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      13      |    O(N)     |    O(1)     |

왼쪽부터 순회하며 직전에 마주한 도미노의 쓰러지는 index를 기억한다.

현재 도미노가 쓰러질 경우, 직전의 쓰러지는 index와 현재 index 사이의 도미노들의 상태를 변경 한다.

```cpp
void change(string &line, int left, int right) {
  if (line[left] == 'L' && line[right] == '.') return;
  if (line[left] == '.' && line[right] == 'R') return;
  if (line[left] == 'L' && line[right] == 'R') return;

  if (line[left] == line[right] || line[left] == '.' || line[right] == '.') {
    char target = line[left] == '.' ? line[right] : line[left];

    for (int i = left; i <= right; i++) {
      line[i] = target;
    }
    return;
  }

  int centerR = (right + left + 1) / 2;
  int centerL = (right + left) / 2;

  for (int i = left; i <= centerR - 1; i++) {
    line[i] = 'R';
  }
  for (int i = centerL + 1; i <= right; i++) {
    line[i] = 'L';
  }
}

string pushDominoes(string dominoes) {
  int size = dominoes.size();

  int left = 0;
  for (int i = 0; i < size; i++) {
    char c = dominoes[i];

    if (c == '.') continue;

    change(dominoes, left, i);
    left = i;
  }
  change(dominoes, left, size - 1);

  return dominoes;
}
```

## 고생한 점
