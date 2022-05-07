# 2075. Decode the Slanted Ciphertext

[링크](https://leetcode.com/problems/decode-the-slanted-ciphertext/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

원본 문자열의 길이를 N이라 하자.

주어진 순서대로 문자열을 순회해야 하며 결국 모든 문자를 중복없이 한번 순회하게 된다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

해석된 새로운 문자열을 생성하는 데 O(N)의 공간 복잡도를 사용한다.

### 순회 & 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     118      |    O(N)     |    O(N)     |

rows가 주어지므로 이를 이용해 cols를 계산할 수 있다.

(길이 / rows)

이후 1행의 각 x좌표들을 순회하며 대각선으로 이후 순회하며 각 문자들을 더해나간다.

이후 맨 뒤에 공백들을 제거한다.

이를 구현하면 다음과 같다.

```cpp
string decodeCiphertext(string encodedText, int rows) {
  string text = "";

  int length = encodedText.length();
  int cols = length / rows;

  for (int x = 0; x < cols; x++) {
    for (int i = 0; i < rows && x + i < cols; i++) {
      text += encodedText[i * cols + x + i];
    }
  }

  while (!text.empty() && text.back() == ' ') {
    text.pop_back();
  }

  return text;
}
```

## 고생한 점
