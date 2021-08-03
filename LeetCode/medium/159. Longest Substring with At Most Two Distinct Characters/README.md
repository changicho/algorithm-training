# 159. Longest Substring with At Most Two Distinct Characters

[링크](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

subString의 left와 right의 모든 경우를 비교해 정답을 구할 경우 시간 복잡도는 O(N^2)이다.

이는 N이 크므로 제한시간 내에 불가능하다.

슬라이딩 윈도우를 이용해 최대 subString의 길이를 구할 수 있다. 이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

슬라이딩 윈도우를 사용할 경우 각 글자의 count를 셀 hash map이 필요하다.

이는 O(1)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

subString의 시작 index와 끝 index를 다음과 같이 설정한다.

- left : 시작 index
- right : 끝 index + 1

이후 right를 증가시키며 다음 기준에 따라 범위를 설정한다.

- right를 증가시켰을 때 subString의 문자가 2개일 경우 : 정답을 갱신
- 문자가 2개를 초과할 경우 : 증가시킨 right를 원래대로 되돌리고 left를 증가해 subString의 문자의 개수를 갱신

이 때 left가 right를 넘어갈 수 없음에 유의한다.

(이를 처리하기 위해 right - 1을 subString의 끝으로 설정함. subString의 길이가 0이 되는 경우는 left == right)

이는 각 탐색마다 right에 대한 최적의 left를 매번 구하는 방식이 된다.

따라서 시간 복잡도는 O(N)이다.

```cpp
int lengthOfLongestSubstringTwoDistinct(string s) {
  int length = s.length();
  int left = 0, right = 0;
  int answer = 0;
  unordered_map<char, int> counts;

  while (left < length) {
    counts[s[right]] += 1;

    if (right < length && counts.size() <= 2) {
      right += 1;

      answer = max(answer, right - left);
    } else {
      counts[s[right]] -= 1;
      if (counts[s[right]] == 0) counts.erase(s[right]);
      counts[s[left]] -= 1;
      if (counts[s[left]] == 0) counts.erase(s[left]);
      left += 1;
    }
  }

  return answer;
}
```

## 고생한 점
