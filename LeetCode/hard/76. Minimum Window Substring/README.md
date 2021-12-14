# 76. Minimum Window Substring

[링크](https://leetcode.com/problems/minimum-window-substring/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N, t의 길이를 M 이라 하자.

s의 모든 left, right range에 대해서 순회를 수행할 경우 left, right 범위 선택에 O(N^2)의 시간 복잡도를 사용한다.

이후 해당 범위의 문자들로 T를 만들 수 있는지 판별하는데 O(N)의 시간 복잡도를 사용하므로 O(N^3)이 되며 이는 제한시간 내에 불가능하다.

슬라이딩 윈도우를 이용해 한 문자씩 범위를 이동시키며 t를 만드는게 가능한 범위들을 순회할 수 있다.

t를 만들 수 있는지 여부를 빨리 판별하기 위해 hash map을 사용할 경우 초기 세팅에 O(M)의 시간 복잡도를 사용한다.

정답을 갱신할 때 매번 문자열을 갱신할 경우 이 연산에 O(N)이 소요되므로 최후에 한번만 갱신한다.

이 경우 s를 순회하는데 O(N)의 시간 복잡도가 소요되며 최종 시간 복잡도는 O(N + M)이다.

### 공간 복잡도

슬라이딩 윈도우를 사용하기 위해 t에 대한 hash map을 사용할 경우 O(M)의 시간 복잡도를 사용한다.

정답 공간으로 O(N)의 공간 복잡도를 사용하므로 최종 공간 복잡도는 O(N + M)이다.

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      20      |  O(N + M)   |  O(N + M)   |

아이디어

- 슬라이딩 윈도우
- hash map 카운팅 빠르게 하기 위한 변수 생성

슬라이딩 윈도우를 이용해 left, right를 최선의 경우마다 이동시킨다.

만약 현재 범위안의 문자열로 t를 만들지 못하는 경우는 범위의 right를 증가시킨다.

범위 안의 문자열로 t를 만들 수 있게 되었을 때 left를 증가시키며 범위를 좁혀나간다.

이를 반복해 최적의 범위마다 탐색을 계속한다.

여기서 t를 만들 수 있는지 빠르게 판단하기 위해 hash map을 사용한다.

t의 각 문자마다 counting을 수행하며 슬라이딩 윈도우의 right를 증가시킬 때마다 remain을 줄여나간다.

만약 hash map의 모든 value가 0 이하인 경우 t를 생성 가능하게 된다.

left를 증가시킬 때마다 hash map에서 해당 문자의 value를 증가시킨다.

여기서 hash map의 특정 value가 0이 되었을 때, 0을 초과했을 때마다 remainCount를 변화시켜 hash map의 검사를 빠르게 수행한다.

```cpp
string minWindow(string s, string t) {
  int length = s.length();
  if (t.length() > length) return "";
  int left = 0, right = 0;
  int answerLeft = 0, answerRight = length - 1;

  unordered_map<char, int> needs;
  for (char &c : t) {
    needs[c]++;
  }
  int leftCount = t.length();

  bool findAnswer = false;

  while (right < length) {
    if (needs[s[right]] > 0) leftCount--;
    needs[s[right]]--;

    while (left <= right && leftCount == 0) {
      if (answerRight - answerLeft + 1 >= right - left + 1) {
        findAnswer = true;
        answerLeft = left;
        answerRight = right;
      }

      if (needs[s[left]] == 0) {
        leftCount++;
      }
      needs[s[left]]++;
      left++;
    }

    right++;
  }

  if (!findAnswer) return "";
  return s.substr(answerLeft, answerRight - answerLeft + 1);
}
```

## 고생한 점
