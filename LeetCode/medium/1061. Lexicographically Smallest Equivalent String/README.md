# 1061. Lexicographically Smallest Equivalent String

[링크](https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 문자열 s1, s2의 길이를 N, baseStr의 길이를 M이라 하자.

같은 위치에 있는 문자마다 그룹으로 묶고, 해당 그룹에서 가장 알파벳 순으로 앞서는 문자로 변환하는 문제이다.

유니온 파인드를 이용할 경우 각 문자의 순회만큼 시간 복잡도를 사용하므로 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

유니온 파인드를 이용할 경우 알파벳 소문자 26자에 대한 공간이 필요하므로 O(1)의 공간 복잡도를 사용한다.

정답 문자열에 O(M)의 공간 복잡도를 사용한다.

### 유니온 파인드

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |  O(N + M)   |    O(M)     |

s1, s2의 같은 위치에 있는 문자들은 서로 변환이 가능하다.

변환이 가능한 문자들끼리 그룹으로 묶는다고 하자.

이 때 각 그룹에 대해 변환값은 각 그룹에서 가장 앞선 순서의 알파벳으로 변환값이 된다. (사전순으로 앞서도록 정답을 생성하기 위해)

따라서 유니온 파인드를 이용해 각 그룹을 생성하고 그룹의 부모로 알파벳 순으로 앞서는 값을 선언한다.

이를 구현하면 다음과 같다.

```cpp
unordered_map<char, char> parents;

char find(char c) {
  if (parents[c] == c) return c;

  return parents[c] = find(parents[c]);
}

void merge(char a, char b) {
  a = find(a), b = find(b);
  if (a == b) return;
  if (a > b) swap(a, b);

  parents[b] = a;
}

string smallestEquivalentString(string s1, string s2, string baseStr) {
  for (char c = 'a'; c <= 'z'; c++) {
    parents[c] = c;
  }

  int size = s1.size();
  for (int i = 0; i < size; i++) {
    merge(s1[i], s2[i]);
  }

  string ret = "";
  for (char &c : baseStr) {
    ret += find(c);
  }
  return ret;
}
```

## 고생한 점
