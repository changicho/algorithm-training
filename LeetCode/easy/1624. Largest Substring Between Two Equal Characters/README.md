# 1624. Largest Substring Between Two Equal Characters

[링크](https://leetcode.com/problems/largest-substring-between-two-equal-characters/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N^2)이다.

각 문자별로 처음 나타나는 위치를 저장하고 현재 문자의 처음 위치와 마지막 위치를 이용해 정답을 갱신할 수 있다.

이 경우 O(N)의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

알파벳 소문자 각 문자마다 처음 나타나는 위치를 저장해야 하므로 O(1)의 공간 복잡도가 필요하다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

두 문자 사이의 최대값을 구하기 위해선 각 문자별로 가장 처음 나타난 위치를 저장해야 한다.

문자열 s를 순회하며 각 문자별로 처음 나타나는 위치를 저장한다.

이후 현재 문자가 이전에 나타난 경우 현재 index와 이전 위치를 이용해 정답을 갱신한다.

```cpp
int maxLengthBetweenEqualCharacters(string s) {
  int size = s.size();

  int before[26] = {
      -1,
  };
  memset(before, -1, sizeof(before));

  int answer = 0;
  for (int i = 0; i < size; i++) {
    if (before[s[i] - 'a'] != -1) {
      int cur = i - before[s[i] - 'a'];
      answer = max(answer, cur);
    } else {
      before[s[i] - 'a'] = i;
    }
  }

  return answer - 1;
}
```

## 고생한 점
