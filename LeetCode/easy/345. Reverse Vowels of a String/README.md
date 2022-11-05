# 345. Reverse Vowels of a String

[링크](https://leetcode.com/problems/reverse-vowels-of-a-string/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

문자열을 왼쪽부터 순회하며 자음은 그대로 더하고, 모음 부분만 별도로 체크한 뒤 뒤집을 수 있다.

이 경우 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(N)의 공간 복잡도를 사용한다.

별도로 모음을 저장할 경우 O(N)의 공간 복잡도를 사용한다.

### two pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      28      |    O(N)     |    O(N)     |

각 문자열을 순회하며 자음과 모음을 구분한다.

이 때 자음은 그대로 정답에 더하고, 모음인 경우 정답에 임의의 문자열을 더하고 모음부분만 별도의 문자열에 저장한다.

이후 임의의 문자열을 순회하며 모음을 거꾸로 할당한다.

```cpp
bool isVowel(char c) {
  c = tolower(c);
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
    return true;
  }
  return false;
}

string reverseVowels(string s) {
  string answer = "";
  string vowels = "";

  for (char &c : s) {
    if (isVowel(c)) {
      vowels += c;
      answer += 'a';
    } else {
      answer += c;
    }
  }

  for (int i = 0; i < answer.length(); i++) {
    if (answer[i] != 'a') continue;

    answer[i] = vowels.back();
    vowels.pop_back();
  }

  return answer;
}
```

## 고생한 점
