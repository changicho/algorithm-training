# 567. Permutation in String

[링크](https://leetcode.com/problems/permutation-in-string/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

s1의 길이를 N, s2의 길이를 M이라 하자.

s2 내부에서 s1의 팰린드롬을 찾기 위해 counting을 이용한다.

따라서 s2의 모든 index를 순회하며 N의 길이의 문자열에 대해 counting을 수행하고 s1의 counting과 비교한다.

이에 소요되는 시간 복잡도는 O(M \* N)이다.

혹은 슬라이딩 윈도우를 이용해 하나의 index씩만 슬라이딩 윈도우를 갱신할 수 있다.

이 경우 시간 복잡도는 s1과 s2에 대해 한번씩 순회하므로 O(N + M)이다.

### 공간 복잡도

알파벳 소문자로만 구성되어있으며 counting을 수행할 때 O(26)크기의 배열이 필요하다.

이는 거의 상수이며 변하지 않으므로 필요한 공간 복잡도는 O(1)이다.

### 팰린드롬 카운팅

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     220      |  O(M \* N)  |    O(1)     |

s1에 대해서 문자의 빈도를 counting한 배열을 생성한다.

이는 팰린드롬의 경우 결국 나타나는 문자들의 count한 수는 같은것을 이용하기 때문이다.

s2의 index를 순회하며 index ~ (index + N)까지의 부분문자열에 대해서 문자의 수를 counting하고 이를 s1의 counting과 비교한다.

비교는 직접 할수도 있으며 equal 함수를 이용할 수 있다.

```cpp
bool isSame(vector<int> &s1map, vector<int> &s2map) {
  for (int i = 0; i < 26; i++) {
    if (s1map[i] != s2map[i]) return false;
  }
  return true;
}

// use STL
s1map.size() == s2map.size() && equal(s1map.begin(), s1map.end(), s2map.begin())
```

```cpp
bool checkInclusion(string s1, string s2) {
  int s1Length = s1.length(), s2Length = s2.length();
  if (s1Length > s2Length) return false;

  vector<int> s1map(26, 0), s2map(26, 0);
  for (int i = 0; i < s1Length; i++) {
    s1map[s1[i] - 'a']++;
  }

  int limit = s2Length - s1Length;
  for (int start = 0; start <= limit; start++) {
    fill(s2map.begin(), s2map.end(), 0);
    for (int index = 0; index < s1Length; index++) {
      s2map[s2[start + index] - 'a']++;
    }

    if (s1map.size() == s2map.size() &&
        equal(s1map.begin(), s1map.end(), s2map.begin()))
      return true;
  }
  return false;
}
```

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N + M)   |    O(1)     |

s1에서 index는 한칸씩 이동하므로 기존에 구해놓은 s2의 counting배열에서 이전 시작 index와 현재 추가되는 제일 마지막 index에 대해서 갱신한다.

```cpp
bool checkInclusion(string s1, string s2) {
  if (s1.length() > s2.length()) return false;
  vector<int> s1map(26, 0), s2map(26, 0);

  for (int i = 0; i < s1.length(); i++) {
    s1map[s1[i] - 'a']++;
    s2map[s2[i] - 'a']++;
  }
  for (int i = 0; i < s2.length() - s1.length(); i++) {
    if (s1map.size() == s2map.size() &&
        equal(s1map.begin(), s1map.end(), s2map.begin()))
      return true;

    s2map[s2[i + s1.length()] - 'a']++;
    s2map[s2[i] - 'a']--;
  }
  return s1map.size() == s2map.size() &&
          equal(s1map.begin(), s1map.end(), s2map.begin());
}
```

## 고생한 점
