# 948. Bag of Tokens

[링크](https://leetcode.com/problems/bag-of-tokens/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 tokens의 크기를 N이라 하자.

각 경우마다 가장 유리한 값을 선택해 점수를 늘리거나 파워를 늘려야 한다.


이를 위해 정렬을 사용할 경우 O(N \* log_2(N))의 시간 복잡도가 필요하다.
이후 투 포인터를 이용해 각 경우마다 가장 유리한 값을 선택한다.

### 공간 복잡도

정렬에 최대 O(N)의 공간 복잡도를 사용한다.

### 정렬 & 투 포인터

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      0       | O(N \* log_2(N)) |    O(N)     |

각 상황에서 파워의 증감과 점수의 증감에서 가장 유리한 경우는 다음과 같다.

- 점수를 줄이는 경우 : 파워가 가장 높은 token을 선택 (현재 파워에서 증가하므로)
- 점수를 늘리는 경우 : 파워가 가장 낮은 token을 선택 (현재 파워에서 감소하므로)

이를 위해 각 경우마다 가장 파워가 높은 token을 선택하거나, 가장 파워가 낮은 token을 선택한다.

미리 정렬 후 투 포인터를 사용할 경우 매번 최대, 최소값을 구할 수 있다.

또한 각 경우마다 점수를 최대한 늘릴 수 있을 때 까지 늘리며 정답을 갱신한다.

```cpp
int bagOfTokensScore(vector<int>& tokens, int power) {
  int size = tokens.size();

  sort(tokens.begin(), tokens.end());

  int left = 0, right = size - 1;

  int score = 0;
  int answer = 0;
  while (left <= right) {
    if (power >= tokens[left]) {
      score++;
      power -= tokens[left];
      left++;
    } else {
      if (score == 0) break;
      score--;
      power += tokens[right];
      right--;
    }
    answer = max(answer, score);
  }

  return answer;
}
```

## 고생한 점
