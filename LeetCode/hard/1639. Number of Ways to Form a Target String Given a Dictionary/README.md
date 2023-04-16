# 1639. Number of Ways to Form a Target String Given a Dictionary

[링크](https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 words의 갯수를 N, 각 단어의 길이를 L, target의 길이는 M이라 하자.

각 과정마다 words를 매번 순회할 경우 O(N)의 시간 복잡도를 사용한다.

미리 각 단어의 자리수마다의 알파벳의 수를 세놓을 경우 각 index만 순회하면 되므로 O(1)의 시간 복잡도를 사용한다. (전처리에 O(N \* L)의 시간 복잡도가 필요하다.)

동적 계획법을 이용해 풀이할 수 있다.

이 경우 각 단어의 길이, target의 길이에 대해 순회해야 하므로 O(L \* M)의 시간 복잡도를 사용한다.

각 과정마다 직전 값들을 순회해 더할 경우 O(L)의 시간 복잡도를 추가로 사용한다.

이를 미리 prefix sum으로 구하며 저장해놓을 경우 O(1)의 시간 복잡도를 사용할 수 있다.

따라서 총 시간 복잡도는 O(L \* (N + M))이다.

### 공간 복잡도

동적 계획법에 O(L \* M)의 공간 복잡도가 필요하다.

직전 값들만 사용하므로 이를 최적화 할 경우 O(L)의 공간 복잡도를 사용한다.

### 동적 계획법 & prefix sum

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|     237      | O(L \* (N + M)) |  O(M \* L)  |

다음과 같은 동적 계획법 식을 사용할 수 있다.

```cpp
// definition
long dp[1001][1001]; // [wordLen i][target i]; // dp[i][j] : 단어들의 i번째까지 사용하여 j번째 target까지 만들 수 있는 경우의 수

// update
for(int before = 0; before < i; before++){
  dp[i][len] += dp[before][len-1] * counts[i][curChar - 'a'];
  dp[i][len] %= MOD;
}

// init
dp[i][0] = counts[i][target[0] - 'a']; // 단어들의 i번째 까지 사용해 target의 0번째까지 만들 수 있는 경우의 수
```

이 과정에서 값의 갱신 시에 before를 모두 순회할 경우 wordI, targetI에 대해 O(L \* M)의 시간 복잡도에 내부적으로 O(L)의 시간 복잡도를 추가적으로 사용한다.

이는 최악의 경우 1,000^3 의 시간 복잡도를 사용하므로 제한시간 내에 불가능하다.

이기서 직전 before들에 대해 재사용 하므로 prefix sum을 이용해 O(1)의 시간 복잡도로 갱신할 수 있다.

이를 이용해 최적화 된 dp를 이용하면 다음과 같이 구현이 가능하다.

```cpp
int numWays(vector<string>& words, string target) {
  int size = words.size();
  int wordLength = words[0].size();
  int length = target.size();

  int counts[1001][26] = {
      0,
  };
  for (int i = 0; i < wordLength; i++) {
    for (int j = 0; j < size; j++) {
      counts[i][words[j][i] - 'a']++;
    }
  }

  long dp[1001][1001] = {
      0,
  };  // index, length;
  long prefixes[1001] = {
      0,
  };  // length

  for (int i = 0; i < wordLength; i++) {
    char curChar = target[0];
    dp[i][0] = counts[i][curChar - 'a'];
  }

  for (int len = 0; len < length; len++) {
    prefixes[0] += dp[0][len];
  }

  for (int i = 1; i < wordLength; i++) {
    for (int len = 1; len < length; len++) {
      char curChar = target[len];

      // for(int before = 0; before < i; before++){
      //     dp[i][len] += dp[before][len-1] * counts[i][curChar - 'a'];
      //     dp[i][len] %= MOD;
      // }
      dp[i][len] += prefixes[len - 1] * counts[i][curChar - 'a'];
      dp[i][len] %= MOD;
    }

    // prefix update
    for (int len = 0; len < length; len++) {
      prefixes[len] = prefixes[len] + dp[i][len];
      prefixes[len] %= MOD;
    }
  }

  int answer = 0;
  for (int i = 0; i < wordLength; i++) {
    answer += dp[i][length - 1];
    answer %= MOD;
  }

  return answer;
}
```

## 고생한 점
