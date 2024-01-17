# 2957. Remove Adjacent Almost-Equal Characters

[링크](https://leetcode.com/problems/remove-adjacent-almost-equal-characters/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 word의 길이를 N이라 하자.

각 index별로 알파벳을 변경했을 때의 최소 횟수를 동적 계획법을 이용해 구할 수 있다.

이 경우 O(N)의 시간 복잡도가 소요된다.

그리디 알고리즘을 사용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(N)의 공간 복잡도가 필요하다.

동적 계획법에서 직전값만 필요하므로 O(1)의 공간 복잡도를 사용할 수 있다.

그리디 알고리즘을 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     147      |    O(N)     |    O(1)     |

dp배열을 다음과 같이 설정한다.

```cpp
int dp[index][c]; // 0 ~ index까지 순회하며 index번째 문자를 c로 변경했을 때의 최소 횟수
```

직전 까지의 dp배열을 구한 경우 현재 index번째 문자를 변경했을 때의 최소 횟수를 다음과 같이 구할 수 있다.

- 현재 문자를 변경할 때 직전 문자와 같거나 인접한 알파벳인 경우
- 현재 문자를 변경할 때 직전 문자와 인접하지 않은 경우

여기서 직전 문자를 각각의 알파벳으로 바꾸는 데 최소 횟수를 이미 알고 있으므로 현재 문자를 변경할 때의 최소 횟수를 구할 수 있다.

여기서 dp배열의 직전값만 필요하므로 공간 복잡도를 줄일 수 있다.

```cpp
int removeAlmostEqualCharacters(string word) {
  int size = word.size();
  vector<int> dp(26, INT_MAX);

  for (int i = 0; i < 26; i++) {
    dp[i] = i != word[0] - 'a';
  }

  for (int i = 1; i < size; i++) {
    vector<int> temp(26, INT_MAX);
    for (int cur = 0; cur < 26; cur++) {
      for (int before = 0; before < 26; before++) {
        if (abs(cur - before) <= 1) continue;

        temp[cur] = min(temp[cur], dp[before] + (cur != word[i] - 'a'));
      }
    }

    dp = temp;
  }

  int answer = INT_MAX;
  for (int i = 0; i < 26; i++) {
    answer = min(answer, dp[i]);
  }
  return answer;
}
```

### 그리디 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

index번째 문자가 존재한다고 하자.

여기서 index-1, index+1번째 문자와 같거나 연속되지 않은 문자로 변경할 수 있다.

(알파벳의 종류는 26가지 이므로)

따라서 각 index를 순회하며 직전 문자와 같거나 연속된 경우 현재 문자를 변경한다.

이 때 직전 문자가 변경된 경우 현재 문자는 비교를 수행할 필요가 없다.

왼쪽부터 순회하며 최소 횟수를 구한다.

```cpp
int removeAlmostEqualCharacters(string s) {
  int size = s.size();

  int changed = 0;
  for (int i = 1; i < size; i++) {
    if (abs(s[i] - s[i - 1]) <= 1) {
      changed++;
      i++;
    }
  }

  return changed;
}
```

## 고생한 점
