# 1320. Minimum Distance to Type a Word Using Two Fingers

[링크](https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 문자열의 길이를 N이라 하자.

동적 계획법을 사용할 경우 두 손가락의 위치의 경우의 수는 26^2가 된다.

이를 각 index마다 계산하므로 시간 복잡도는 O(N \* 26^2)가 된다. 이는 O(N)이다.

### 공간 복잡도

동적 계획법을 사용할 경우 두 손가락의 위치의 경우의 수는 26^2가 된다.

각 index마다 저장할 경우 O(N)의 공간 복잡도를 사용한다.

직전값만 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 동적 계획법 (space optimize)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      9       |    O(N)     |    O(1)     |

각 손가락이 어디에 위치하는지 경우의 수는 26^2가지가 된다.

따라서 각 index마다 26^2가지의 경우의 수를 계산하며 정답을 갱신해나간다.

이 때 직전 위치에서 현재 위치로 이동할 때, valid한 경우만 진행하게 되므로 두 손가락중 하나는 현재 문자에 위치하게 된다.

이를 이용해 현재 dp를 갱신한다.

```cpp
int getDist(int a, int b) {
  int ay = a / 6, ax = a % 6;
  int by = b / 6, bx = b % 6;

  return abs(ay - by) + abs(ax - bx);
}

int minimumDistance(string word) {
  int size = word.size();

  // [first * 26 + second]
  vector<int> dp(26 * 26, INT_MAX);

  for (int i = 0; i < 26 * 26; i++) {
    int c = word[0] - 'A';
    int first = i / 26;
    int second = i % 26;

    if (first == c || second == c) {
      dp[i] = 0;
    }
  }

  for (int i = 1; i < size; i++) {
    vector<int> temp(26 * 26, INT_MAX);

    int c = word[i] - 'A';

    for (int before = 0; before < 26 * 26; before++) {
      int first = before / 26, second = before % 26;
      if (dp[before] == INT_MAX) continue;

      // move first
      int diffFirst = getDist(c, first);

      temp[c * 26 + second] =
          min(temp[c * 26 + second], dp[before] + diffFirst);

      // move second
      int diffSecond = getDist(c, second);
      temp[first * 26 + c] =
          min(temp[first * 26 + c], dp[before] + diffSecond);
    }
    dp = temp;
  }

  int answer = INT_MAX;
  for (int i = 0; i < 26 * 26; i++) {
    int c = word[0] - 'A';
    int first = i / 26;
    int second = i % 26;

    answer = min(answer, dp[first * 26 + second]);
  }
  return answer;
}
```

## 고생한 점
