# 293. Flip Game

[링크](https://leetcode.com/problems/flip-game/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 길이를 L이라 하자.

모든 경우를 탐색할 경우 순회에 O(L)의 시간 복잡도를 사용한다.

각 경우마다 정답에 문자열을 복사해서 추가해야 하므로 이 또한 O(L)의 시간 복잡도가 필요하다.

따라서 시간 복잡도는 O(L^2)이다.

### 공간 복잡도

정답 공간에 O(L^2)의 공간 복잡도가 필요하다.

새로운 문자열을 생성하는데 O(L)의 공간 복잡도가 필요하다.

만약 기존 문자열을 재사용 할 경우 O(1)의 공간 복잡도가 필요하다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |   O(L^2)    |   O(L^2)    |

각 경우를 탐색하며 두 문자가 연속되고 +인 경우에 flip한 뒤 정답에 추가한다.

추가한 이후 원본 문자열로 복구한다.

```cpp
vector<string> generatePossibleNextMoves(string currentState) {
  int size = currentState.size();

  vector<string> answer;
  for (int i = 0; i < size - 1; i++) {
    if (currentState[i] == '+' && currentState[i] == currentState[i + 1]) {
      currentState[i] = currentState[i + 1] = '-';

      answer.push_back(currentState);

      currentState[i] = currentState[i + 1] = '+';
    }
  }

  return answer;
}
```

## 고생한 점
