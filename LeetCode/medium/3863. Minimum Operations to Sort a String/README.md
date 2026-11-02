# 3863. Minimum Operations to Sort a String

[링크](https://leetcode.com/problems/minimum-operations-to-sort-a-string/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

문자열의 경우들 별로 최소 이동 횟수를 판단한다.

이를 위해 각 문자중 최소, 최대값이 어느 위치에 존재하는지 순회해 구하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

최대, 최소값을 저장하는데 O(1)의 공간 복잡도를 사용한다.

### 경우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      13      |    O(N)     |    O(1)     |

문자열 안의 최소값을 A, 최대값을 Z라 하자.

문자열들은 각 경우별로 존재한다.

- 이미 정렬된 케이스
- 길이가 2인 케이스 : 정렬되지 않은 경우 정렬 불가
- 맨 앞이 A, 맨 뒤가 Z인 경우 : 가운데 부분만 정렬함
- 2번째 ~ N-1번째 사이에 A,Z가 포함된 경우 : 양 끝값으로 구간을 정렬한 뒤 나머지 구간을 정렬
- 역순으로 정렬된 케이스 : 일부 구간을 정렬 후 다시 양 끝 구간을 정렬함

위 경우 중 속하는 경우를 찾은 뒤 정답을 반환한다.

```cpp
int minOperations(string s) {
  int size = s.size();
  char maximum = 'a', minimum = 'z';

  bool isSorted = true;
  for (int i = 0; i < size; i++) {
    char& c = s[i];
    maximum = max(maximum, c);
    minimum = min(minimum, c);

    if (i + 1 < size && s[i] > s[i + 1]) {
      isSorted = false;
    }
  }
  if (isSorted) {
    return 0;
  }
  if (size == 2) {
    return -1;
  }
  if (s[0] == minimum || s[size - 1] == maximum) {
    return 1;
  }
  for (int i = 1; i < size - 1; i++) {
    if (s[i] == minimum || s[i] == maximum) {
      return 2;
    }
  }
  // cba
  return 3;
}
```

## 고생한 점
