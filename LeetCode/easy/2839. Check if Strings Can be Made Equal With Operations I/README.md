# 2839. Check if Strings Can be Made Equal With Operations I

[링크](https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자. (N은 4)

index 차이가 2인 두 문자를 바꾸는 연산을 수행할 수 있다.

따라서 바꿀 수 있는 문자쌍은 정해져 있으므로 해당 문자쌍을 오름차순으로 변환 후 두 문자열을 비교한다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

별도의 문자열을 생성할 경우 O(N)의 공간 복잡도가 필요하다.

### 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

변환 가능한 문자 index는 다음과 같다.

- 0,2
- 1,3

두 쌍의 문자를 각각 오름차순으로 정렬 한다.

이를 두 문자열에 대해 수행 후 비교한다.

```cpp
string convert(string s) {
  string part1 = "", part2 = "";

  part1 += s[0];
  part1 += s[2];
  part2 += s[1];
  part2 += s[3];

  sort(part1.begin(), part1.end());
  sort(part2.begin(), part2.end());

  return part1 + part2;
}

bool canBeEqual(string s1, string s2) { return convert(s1) == convert(s2); }
```

## 고생한 점
