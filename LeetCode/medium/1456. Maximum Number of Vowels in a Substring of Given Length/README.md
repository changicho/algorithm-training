# 1456. Maximum Number of Vowels in a Substring of Given Length

[링크](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자. 입력받은 연속문자열의 크기를 K라 하자.

모든 쌍에 대해 직접 탐색할 경우 O(N * K)의 시간 복잡도를 사용한다. 이는 제한시간 내에 불가능하다.

슬라이딩 윈도우를 이용해 한번의 순회로 풀이할 수 있다. 이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 글자마다의 갯수를 저장해야 한다. 알파벳 소문자이므로 O(1)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      25      |    O(N)     |    O(1)     |

크기가 K인 슬라이딩 윈도우의 시작점 왼쪽을 left, 윈도으의 끝점을 right라 하자.

이후 right를 증가시키며 count에 더하고, left를 증가시키며 count에서 뺀다. (left + K = right)

이후 현재 윈도우의 모음의 갯수를 구한다.

```cpp
int maxVowels(string s, int k) {
  vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

  int counts[26] = {
      0,
  };
  int size = s.size();

  int answer = 0;
  for (int right = 0; right < size; right++) {
    counts[s[right] - 'a']++;

    int left = right - k;
    if (left >= 0) {
      counts[s[left] - 'a']--;
    }

    int cur = 0;
    for (char &v : vowels) {
      cur += counts[v - 'a'];
    }
    answer = max(answer, cur);
  }
  return answer;
}
```

## 고생한 점
