# 125. Valid Palindrome

[링크](https://leetcode.com/problems/valid-palindrome/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 길이는 최대 2 \* 10^5이다.

팰린드롬인지 여부를 판단하는데 들어가는 시간 복잡도는 O(N) 이다.

이 때 특수문자, 공백을 제외한 알파벳, 숫자만으로 팰린드롬 여부를 비교해야한다.

다음 두가지 방법이 존재한다.

- 문자열을 trim한 후 양 끝부터 비교 : O(N) + O(N)
- 필요없는 문자를 무시하며 양 끝부터 비교 : O(N)

### 공간 복잡도

문자열을 trim하는 경우 새로운 문자열을 저장할 공간이 필요하다. 따라서 공간 복잡도는 O(N)이다.

필요없는 문자를 무시하며 양 끝부터 비교하는 경우 추가적인 공간이 필요하지 않다.

### 알파벳 혹은 숫자

STL의 isalnum 이라는 함수가 존재한다.

- digits (0123456789)
- uppercase letters (ABCDEFGHIJKLMNOPQRSTUVWXYZ)
- lowercase letters (abcdefghijklmnopqrstuvwxyz)

```cpp
char c;
isalnum(c);

// 직접 구현하는 경우 다음과 같다.
bool isalnum(char c){
  if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
    return true;
  }
  if(c>='0' && c<='9') return true;
  return false;
}
```

### 팰린드롬 비교

시작점을 start, 끝점을 end라고 하자. 양 끝에서부터 중앙으로 각 index들을 이동시키며 두개의 해당 index의 문자가 조건에 만족하는지 판단한다.

이 때 공백, 특수문자를 무시하는 방법을 사용한 경우 비교할 문자 순서를 맞춰주기 위해 미리 땡겨준다.

이렇게 공백, 특수문자를 제거하는과정에서 index 순서가 역전될 수 있음에 유의한다.

```cpp
bool isPalindrome(string s) {
  int length = s.length();
  int start = 0;
  int end = length - 1;

  while (start < end) {
    while (start < end && !isalnum(s[start])) start++;
    while (end > 0 && !isalnum(s[end])) end--;

    if (start > end) break;

    if (tolower(s[start]) != tolower(s[end])) return false;
    start++;
    end--;
  }

  return true;
}
```

만약 문자열을 trim한 경우 비교는 더 간단해진다.

```cpp
bool isPalindrome(string s) {
  s = trim(s);

  int length = s.length();
  int start = 0;
  int end = length - 1;

  while (start < end) {
    if (s[start] != s[end]) return false;
    start++;
    end--;
  }

  return true;
}

string trim(string s) {
  string ret = "";

  for (char c : s) {
    if (isalnum(c)) ret += tolower(c);
  }
  return ret;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      0       |

## 고생한 점
