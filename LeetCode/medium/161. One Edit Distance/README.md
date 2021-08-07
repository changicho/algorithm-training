# 161. One Edit Distance

[링크](https://leetcode.com/problems/one-edit-distance/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

하나의 문자열에서 다른 문자열로 한글자만 삽입, 삭제, 바꾸기를 통해 변경 가능한지 알아봐야 한다.

하나의 문자열만 특정 위치에 추가할 경우 변환이 가능한 지 알아보기 위해 one pass로 구현이 가능하다.

해당 순회에 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

길이가 긴 문자열에서 해야할 index를 삭제했을 때 변환이 가능한지 여부를 확인하면 된다.

별도의 문자열을 생성하는 경우 O(N)의 공간 복잡도가 필요하다.

그 외에는 index만을 이용하므로 별도의 공간 복잡도가 필요하지 않다.

### index diff

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(1)     |

두 문자열에서 한 글자만 삽입, 삭제, 변환해서 같은 문자열을 만들지 못하는 경우는 다음과 같다.

- 두 문자열의 글자 수가 같은경우
- 두 문자열의 글자 수의 차이가 2글자 이상인 경우
- 두 문자열에서 두글자 이상이 다른경우

여기서 글자수가 같거나 2글자 이상 길이의 차이가 발생하는 경우는 빠르게 파악이 가능하다.

만약 두 문자열의 길이가 같고 한글자만 다른 경우는 한번의 순회로 O(N)만에 비교가 가능하다.

그 외의 경우 s가 t보다 1글자 긴 상황을 가정해보자.

만약 s의 하나의 다른 문자를 제거했을 때 제거한 s'와 t가 같은 경우 true를 반환하면 된다.

여기서 하나의 다른 문자를 브루트 포스를 이용해 찾을 경우 O(N)의 경우를 살펴봐야 하고, 삭제 연산에 O(N)의 시간 복잡도가 소요되므로 O(N^2)의 시간 복잡도를 소요한다.

이는 최악의 경우 10^8의 시간 복잡도를 소요하므로 제한시간 내에 불가능하다.

만약 한번의 순회를 진행하며 다른 하나의 문자열을 발견했을 때, 해당 문자를 지워버리고 s'와 t를 비교할 경우 O(N)의 시간 복잡도로 풀이가 가능하다.

여기서 공간 복잡도를 줄이기 위해 index로만 비교를 진행하고 새로운 문자열을 생성하지 않는다.

```cpp
int countDiff(string &s, string &t) {
  int length = s.length();
  int count = 0;

  for (int i = 0; i < length; i++) {
    if (s[i] != t[i]) count += 1;
  }
  return count;
}

bool isOneEditDistance(string s, string t) {
  if (s.length() == t.length()) {
    return countDiff(s, t) == 1;
  }
  if (s.length() < t.length()) swap(s, t);

  int length = s.length();
  int sIdx = 0, tIdx = 0;

  while (sIdx < length) {
    if (s[sIdx] != t[tIdx]) {
      if (sIdx != tIdx) return false;
      sIdx += 1;
    } else {
      sIdx += 1;
      tIdx += 1;
    }
  }

  return true;
}
```

## 고생한 점
