# 438. Find All Anagrams in a String

[링크](https://leetcode.com/problems/find-all-anagrams-in-a-string/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

두 문자열의 길이를 N, M이라 하자.

모든 N에 대해서 M의 anagram인지 판별할 경우 시간 복잡도는 O(N \* M)이 된다.

슬라이딩 윈도우를 이용해 탐색할 경우 매번 직접 탐색하지 않고 이전 결과를 이용해 탐색 할 수 있다.

이 경우 미리 M에 대한 anagram을 만들어야 하므로 시간 복잡도는 O(N + M)이다.

### 공간 복잡도

두 문자열의 anagram을 비교할 알파벳들의 count 배열이 필요하다. 이는 O(26)의 공간 복잡도를 사용한다.

또한 anagram인 모든 index를 정답에 저장해야 한다.

따라서 O(N)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      11      |  O(N + M)   |    O(N)     |

anagram을 구하기 위해 모든 p을 구성하는 모든 알파벳의 숫자를 카운트 한 배열을 생성한다.

cpp에서 vector가 같은지의 비교는 단순히 두 벡터가 같은지를 비교하면 된다.

```cpp
vector<int> a, b;
bool isSame = a == b;
```

s에 대해서 시작점이 0인 인덱스부터 M 크기의 anagram 카운트 벡터를 만든다.

이후 인덱스를 증가시키며 직전 시작점의 알파벳을 빼고, 현재 끝점의 알파벳을 더한다.

이를 이용해 매번 직접 anagram 벡터를 구하지 않고 직전의 값을 이용할 수 있다.

```cpp
vector<int> findAnagrams(string s, string p) {
  int lengthS = s.length(), lengthP = p.length();
  if (lengthS < lengthP) {
    return {};
  }

  vector<int> res;
  vector<int> countS(26, 0), countP(26, 0);

  for (int i = 0; i < lengthP; ++i) {
    countP[p[i] - 'a'] += 1;
    countS[s[i] - 'a'] += 1;
  }

  for (int left = 0; left < lengthS - lengthP; ++left) {
    int right = left + lengthP;

    if (countP == countS) {
      res.push_back(left);
    }

    countS[s[right] - 'a'] += 1;
    countS[s[left] - 'a'] -= 1;
  }

  if (countP == countS) {
    res.push_back(s.length() - p.length());
  }

  return res;
}
```

## 고생한 점
