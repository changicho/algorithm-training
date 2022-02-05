# 791. Custom Sort String

[링크](https://leetcode.com/problems/custom-sort-string/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 L, order의 길이를 M이라 하자.

(M은 26 이하이다)

order를 이용해 우선순위 테이블을 만든 뒤 s를 정렬할 수 있다.

이 경우 시간 복잡도는 O(M + L \* log_2(L))이다.

문제에서 문자열의 범위가 한정되므로 카운팅 정렬을 이용할 수 있다.

이 경우 O(L + M)의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

우선순위 테이블을 만들 경우 O(M)의 공간 복잡도를 사용한다.

이후 정답 문자열을 생성하는 데 O(L)의 공간 복잡도를 사용한다.

최종적으로 O(L + M)의 공간 복잡도를 사용한다.

카운팅 정렬을 이용할 경우 카운팅 배열에 O(M)의 공간 복잡도를 사용한다.

따라서 공간 복잡도는 O(L + M)이다.

### 정렬

| 내 코드 (ms) |     시간 복잡도      | 공간 복잡도 |
| :----------: | :------------------: | :---------: |
|      2       | O(M + L \* log_2(L)) |  O(L + M)   |

각 글자마다 우선순위를 찾는 배열을 만든다.

이후 정렬을 수행한다.

이 때 order에 나오지 않은 문자는 어디에나 위치해도 상관 없으므로 우선순위를 제일 낮은수로 설정한다.

정렬의 compare함수는 람다식으로 설정한다.

```cpp
string customSortString(string order, string s) {
  vector<int> orders(26, 100);
  for (int i = 0; i < order.length(); i++) {
    char c = order[i];

    orders[c - 'a'] = i;
  }

  sort(s.begin(), s.end(),
        [&](char a, char b) { return orders[a - 'a'] < orders[b - 'a']; });

  return s;
}
```

### 카운팅 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(L + M)   |  O(L + M)   |

s의 문자들을 카운팅한 배열을 만든다.

이후 order의 순서대로 s를 우선순위가 높은 순으로 채운다.

이후 남은 글자들은 뒤에 채워넣는다.

```cpp
string customSortString(string order, string s) {
  vector<int> cnt(128, 0);

  for (char &c : s) {
    cnt[c]++;
  }

  int index = 0;

  for (char &c : order) {
    while (cnt[c] > 0) {
      s[index++] = c;
      cnt[c]--;
    }
  }

  for (char c = 'a'; c <= 'z'; ++c) {
    while (cnt[c] > 0) {
      s[index++] = c;
      cnt[c]--;
    }
  }

  return s;
}
```

## 고생한 점
