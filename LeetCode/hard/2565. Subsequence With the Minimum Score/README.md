# 2565. Subsequence With the Minimum Score

[링크](https://leetcode.com/problems/subsequence-with-the-minimum-score/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

s, t의 길이를 N, M이라 하자. (1 <= N, M <= 10^5)

t에서 특정 문자를 삭제하는 모든 경우에 대해 탐색할 경우 경우의 수는 2^M이 되며 이는 제한시간 내에 불가능하다.

동적 계획법과 슬라이딩 윈도우를 이용해 풀이할 수 있다.

이 경우 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

슬라이딩 윈도우를 사용할 때 t에 대해서 index들을 저장할 공간이 필요하다.

이에 O(M)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      9       |  O(N + M)   |    O(M)     |

s와 t에 대해 맨 뒤에서부터 순회하며 suffix에 대해 끝에서 부터 i번째 글자까지 s에 존재하는 index들을 저장하는 suffixMatches를 만든다.

이 과정에서 특정 문자를 제거한 suffix가 최대로 매칭하는 길이를 알 수 있다.

이후 prefix에 대해 순회를 진행한다.

만약 현재 순서의 s와 t의 글자가 같은 경우 현재 index를 i라 하자.

앞서 찾은 suffix에서 suffixMatches의 index가 i 이하인 것들을 모두 pop한다.

이 경우 현재의 prefix와 suffix을 선택하는 경우를 탐색 가능하며, 이 구간의 시작 index와 끝 index의 차이가 정답의 후보가 될 수 있다.

```javascript
[prefix, ...remove, ...suffix];
```

즉 위와 같이 정답으로 선택 가능한 부분을 단순화 해 생각할 수 있다.

따라서 t의 각 index에 대해 suffix, prefix를 구하고 구간의 차이를 정답으로 갱신한다.

```cpp
int minimumScore(string s, string t) {
  int sLength = s.size(), tLength = t.size();
  int right = tLength - 1;

  vector<int> suffixMatches(tLength, -1);

  for (int i = sLength - 1; i >= 0 && right >= 0; --i) {
    if (s[i] == t[right]) {
      suffixMatches[right] = i;
      right--;
    }
  }

  int answer = right + 1;
  for (int i = 0, j = 0; i < sLength && j < tLength && answer > 0; ++i) {
    if (s[i] == t[j]) {
      while (right < tLength && suffixMatches[right] <= i) {
        right++;
      }

      j++;
      answer = min(answer, right - j);
    }
  }

  return answer;
}
```

## 고생한 점
