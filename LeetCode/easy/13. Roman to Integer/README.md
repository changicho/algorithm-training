# 13. Roman to Integer

[링크](https://leetcode.com/problems/roman-to-integer/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 길이 N은 최대 15까지이다.

재귀호출의 연산마다 O(N)번이 소요되며 재귀호출 횟수를 최대 O(N)으로 하는 경우에도 제한시간 내에 충분하다.

### 공간 복잡도

정답은 3999 이내이다. 따라서 int형으로 충분하다.

### 재귀호출

로마 숫자는 다음 세 부분으로 나눌 수 있다.

- 빼는 부분
- 중앙점(기준점)
- 더하는 부분

여기서 빼는 부분과 더하는 부분은 모두 로마 숫자로 나타낼 수 있다.

따라서 각 로마 숫자마다 세 부분으로 나누며 재귀호출을 이용해 풀이할 수 있다.

여기서 중앙점은 로마 숫자에서 가장 첫번째로 나오는 큰 수이다.

```cpp
int romanToInt(string s) {
  if (s.length() == 0) return 0;

  string left = "", right = "";
  char target;

  int index = 0;
  int length = s.length();

  for (int i = 0; i < length; i++) {
    if (m[s[i]] > m[s[index]]) {
      index = i;
    }
  }

  for (int i = 0; i < index; i++) {
    left += s[i];
  }
  target = s[index];
  for (int i = index + 1; i < length; i++) {
    right += s[i];
  }

  int minusNum = romanToInt(left);
  int targetNum = m[target];
  int plusNum = romanToInt(right);

  return -minusNum + targetNum + plusNum;
}
```

### switch vs map

switch문을 사용할 때가 map을 이용할 때보다 실행시간과 메모리 사용량이 더 적다.

```cpp
map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

int getNumber(char c) {
  switch (c) {
    case 'I':
      return 1;
    case 'V':
      return 5;
    case 'X':
      return 10;
    case 'L':
      return 50;
    case 'C':
      return 100;
    case 'D':
      return 500;
    case 'M':
      return 1000;
    default:
      return 0;
  }
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      12      |

## 고생한 점
