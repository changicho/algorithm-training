# 3. Longest Substring Without Repeating Characters

[링크](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이는 최대 5 \* 10^4 이다.

가능한 모든 sub 문자열을 탐색할 경우 start, end index를 변경해가며 탐색하므로 시간 복잡도는 O(N^2)이다.

이는 제한시간 내에 아슬아슬하다.

투 포인터를 이용할 경우 현재 end_index에서 만들 수 있는 가장 짧은 sub 문자열만 탐색할 수 있다.

이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

문자열의 문자 종류는 영문, 숫자, 공백, 그리고 특수문자이다.

특정문자가 이전에 사용되었는지 체크하기 위해 테이블(배열) 혹은 set 형태의 자료 구조를 이용할 수 있다.

문자열의 문자 종류가 ASCII 코드표로 전부 나타낼 수 있으므로 array를 이용한다.

### sub string

문제에서 요구하는 sub string은 다음과 같다.

- 0 ~ (s.length - 1) 범위인 start_index, end_index가 있다. (start_index <= end_index)
- sub_string은 기존 string에서 start_index ~ end_index 까지의 문자열이다.
- sub_string의 문자들은 서로 중복되지 않는다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      47      |    O(N)     |    O(N)     |

가능한 subString의 left index와 right index를 이용한다.

right index를 순회하며 현재 문자가 이전에 사용되지 않은 경우 sub문자열에 추가한다.

만약 이전에 사용된 문자인 경우, hash set에 현재 문자가 없을 때 까지 sub문자열의 left index를 증가시키며 hash set에서 삭제한다.

따라서 현재 index가 subString의 마지막 index인 경우의 최대 subString을 유지하며 탐색할 수 있다.

```cpp
// use hash set
int lengthOfLongestSubstring(string s) {
  int length = s.length();
  // O(M)
  unordered_set<char> hashSet;

  int answer = 0;
  // O(N)
  for (int left = 0, right = 0; right < length; right++) {
    char c = s[right];
    // total : O(N)
    while (left < right && hashSet.find(c) != hashSet.end()) {
      hashSet.erase(s[left]);
      left++;
    }

    hashSet.insert(c);
    int length = right - left + 1;
    answer = max(length, answer);
  }

  return answer;
}
```

배열을 이용하는 경우 다음과 같이 풀이가 가능하다.

```cpp
int lengthOfLongestSubstring(string s) {
  int length = s.length();
  int answer = 0;
  int tempLength = 0;
  // english letters, digits, symbols and spaces
  // O(M)
  bool visited[256] = {
      false,
  };

  // O(N)
  for (int left = 0, right = 0; right < length; right++) {
    char c = s[right];
    // total O(N)
    while (left < right && visited[c]) {
      char target = s[left];
      left += 1;

      if (visited[target]) tempLength--;
      visited[target] = false;
    }

    visited[c] = true;
    tempLength++;
    answer = max(answer, tempLength);
  }

  return answer;
}
```

### 슬라이딩 윈도우 (end index)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      14      |    O(N)     |    O(N)     |

다음과 같은 hash map을 생성한다.

- key : 문자
- value : 해당 문자를 포함한 subString이 끝나는 위치

index를 순회하며 해당 문자가 가장 마지막에 나타난 index를 갱신한다.

기존에 해당 문자가 나타났던 경우 index + 1번째부터 해당 문자가 없으므로 길이를 바로 구할 수 있다.

이후 현재 문자가 나타난 위치를 현재 index로 갱신한다.

모든 문자들은 맨 처음에는 나타나지 않았으므로 만약 hash set에 포함되지 않은경우 left를 갱신하지않는다.

```cpp
// use hash map
int lengthOfLongestSubstring(string s) {
  int length = s.length();
  unordered_map<char, int> lastApearIdx;

  int answer = 0;
  for (int left = 0, right = 0; right < length; right++) {
    char c = s[right];

    if (lastApearIdx.count(c) > 0) {
      left = max(left, lastApearIdx[c] + 1);
    }
    // update lastIdx of cur
    lastApearIdx[c] = right;
    answer = max(answer, right - left + 1);
  }

  return answer;
}
```

```cpp
int lengthOfLongestSubstring(string s) {
  int length = s.length();
  int lastApearIdx[128] = {
      0,
  };

  int answer = 0;
  for (int left = 0, right = 0; right < length; right++) {
    char c = s[right];

    if (lastApearIdx[c] != 0) {
      left = max(left, lastApearIdx[c]);
    }
    lastApearIdx[c] = right + 1;

    answer = max(answer, right - left + 1);
  }

  return answer;
}
```

## 고생한 점
