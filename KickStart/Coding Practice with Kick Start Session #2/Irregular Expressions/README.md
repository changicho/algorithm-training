# Irregular Expressions (5pts, 12pts)

[링크](https://codingcompetitions.withgoogle.com/kickstart/round/00000000008f4a94/0000000000b55464)

|    난이도     |
| :-----------: |
| (5pts, 12pts) |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

각 index를 순회하며 start를 찾고, 이후 end들을 검색하며 유효한 주문이 있는지 판단한다.

이 때의 시간 복잡도는 순회에 O(N), start를 찾는데 O(N) 이후 end를 검색하는 데 O(N^2)의 시간 복잡도를 사용한다. (이는 모두 중첩됨)

이후 내부적으로 유효한 주문이 맞는지 판단하는데 O(N)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N^4)가 된다.

### 공간 복잡도

각 경우마다 start를 저장하는데 O(N)의 공간 복잡도를 사용한다.

### 완전 탐색

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|   O(N^4)    |    O(N)     |

각 index를 시작점으로 잡고 순회하며 start를 찾는다.

이후 해당 start가 valid한지 검사한 뒤, 유효한 경우 start이후에 나타나는 같은 end들을 모두 찾는다.

이후 start ~ end 사이의 middle을 찾고 해당 구조가 valid한지 검색한다.

다음과 같은 경우 음절이라고 볼 수 있다.

- 모음 하나가 존재
- 자음(여러개 가능) + 모음 조합
- 모음 + 자음(여러개 가능) 조합

이를 이용해 특정 문자열에 음절이 몇개 들어가있는지는 다음과 같이 판단이 가능하다.

- 문자열에 들어있는 모음의 갯수 : 음절의 갯수

이는 위 3가지 경우의 조합으로 문자열을 나타내는것이 가능하고, 여기서 모음의 갯수로 음절을 구분하기 때문이다.

따라서 각 경우마다 유효한지 검사할 수 있다.

```cpp
int getCount(string &word) {
  int vowelCount = 0;
  for (char &c : word) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      vowelCount += 1;
    }
  }
  return vowelCount;
}

bool search(string &s, int index) {
  int length = s.length();
  string prefix = "";
  for (int i = index; i < length; i++) {
    prefix += s[i];

    int left = i + 1;
    int prefixCount = getCount(prefix);

    if (prefixCount <= 1) continue;
    int right = left;
    while (s.find(prefix, right) != string::npos) {
      if (right + prefix.length() - 1 >= length) {
        right += 1;
        continue;
      }
      string middle = "";
      for (int j = left; j < right; j++) {
        middle += s[j];
      }
      if (getCount(middle) == 1 && middle.length() > 0) {
        return true;
      }
      right += 1;
    }
  }
  return false;
}

bool isSpell(string &s) {
  int length = s.length();

  for (int i = 0; i < length; i++) {
    bool cur = search(s, i);

    if (cur) return true;
  }

  return false;
}
```

## 고생한 점
