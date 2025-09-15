# 3675. Minimum Operations to Transform String

[링크](https://leetcode.com/problems/minimum-operations-to-transform-string/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

각 문자열을 순회하며 존재하는 알파벳 중 a를 제외한 가장 작은 알파벳을 찾는다.

해당 알파벳부터 이동하며 결과적으로 a로 변환해야 하므로 a까지의 거리를 더한다. (알파벳은 증가함)

해당 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |    O(N)     |    O(1)     |

각 알파벳들은 증가시키는 방향으로 변화시킬 수 있다.

b부터 z까지 순회하며 가장 작은 알파벳 순으로 증가시키며 기존에 존재하던 큰 알파벳이 되면 이를 같이 증가시키는 방향이 유리하다.

(묶어서 증가시킴)

이 때 총 횟수는 가장 작은 알파벳을 a로 바꾸는 횟수와 같다.

따라서 s를 순회하며 각 알파벳마다 a로 만들기 위한 비용을 구하고 이 중 최대값을 구한다.

```cpp
int minOperations(string s) {
  int answer = 0;

  for (char &c : s) {
    int dist = (26 - (c - 'a')) % 26;

    answer = max(answer, dist);
  }

  return answer;
}
```

## 고생한 점
