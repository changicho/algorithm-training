# 1371. Find the Longest Substring Containing Vowels in Even Counts

[링크](https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

각 모음의 수가 홀수, 짝수인지 여부를 비트마스크로 표현하고 해당 마스크의 최초 index를 저장한다.

같은 비트 마스크가 나온 경우 두 index의 차이가 정답이 될 수 있다. 

(각 모음의 짝수 홀수 여부가 같으므로 겹치는 구간을 제외한 구간)

### 공간 복잡도

각 마스크의 index를 저장해야 한다. 이에 O(2^5)의 공간 복잡도가 필요하다.

따라서 공간 복잡도는 O(1)이다.

### 비트마스크

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      79      |    O(N)     |    O(1)     |

시작점부터 각 index마다 모음의 짝수 홀수 여부를 비트마스크로 표현한다.

현재 마스크에 대해 해당 마스크를 이전에 방문한 경우 두 구간이 겹치지 않는 부분을 구할 수 있다.

해당 부분은 모음의 갯수가 짝수인 구간이다.

이는 모음의 갯수가 두 구간 모두 홀수인 경우 이 차이는 짝수가 되며 짝수도 동일하기 때문이다.

(현재 짝수,홀수인 모음의 종류, 이전 마스크의 짝수,홀수인 모음의 종류가 같음)

이를 이용해 구하면 다음과 같다.

```cpp
int convert(char c) {
  switch (c) {
    case 'a':
      return 0;
    case 'e':
      return 1;
    case 'i':
      return 2;
    case 'o':
      return 3;
    case 'u':
      return 4;
  }
  return -1;
}

int findTheLongestSubstring(string s) {
  int size = s.size();

  unordered_map<int, int> beforeIs;
  int bit = 0;
  beforeIs[0] = -1;

  int answer = 0;
  for (int i = 0; i < size; i++) {
    int cur = convert(s[i]);
    if (cur != -1) {
      bit ^= (1 << cur);
    }

    if (beforeIs.count(bit) == 0) {
      beforeIs[bit] = i;
    } else {
      answer = max(answer, i - (beforeIs[bit] + 1) + 1);
    }
  }
  return answer;
}
```

## 고생한 점
