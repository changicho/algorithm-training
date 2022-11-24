# 246. Strobogrammatic Number

[링크](https://leetcode.com/problems/strobogrammatic-number/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

num의 길이를 N이라 하자.

투 포인터를 이용해 비교할 문자 두개를 서로 비교하며 진행할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

별도의 배열등을 사용하지 않으므로 상수 공간 복잡도를 사용한다.

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       |    O(N)     |    O(1)     |

뒤집었을 때 가능한 문자는 다음 5가지 이다.

- 0 : 0
- 1 : 1
- 6 : 9
- 8 : 8
- 9 : 6

따라서 위 문자 외에 다른 문자가 존재할 경우 정답은 false이다.

이후 맨앞과 맨끝의 index를 투 포인터로 사용해 비교해나간다.

```cpp
bool isStrobogrammatic(string num) {
  unordered_map<char, char> mirror;
  mirror['0'] = '0';
  mirror['1'] = '1';
  mirror['6'] = '9';
  mirror['8'] = '8';
  mirror['9'] = '6';

  int size = num.size();
  for (int left = 0, right = size - 1; left <= right; left++, right--) {
    if (mirror.count(num[left]) == 0 || mirror.count(num[right]) == 0)
      return false;
    if (mirror[num[left]] != num[right]) return false;
  }

  return true;
}
```

## 고생한 점
