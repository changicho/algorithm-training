# 1323. Maximum 69 Number

[링크](https://leetcode.com/problems/maximum-69-number/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 숫자를 문자열로 변환했을 때의 길이를 N이라 하자.

각 글자마다 6인경우 9로 변환하며 완전 탐색을 진행할 수 있다.

이 경우 바꿀 수 있는 글자의 갯수는 N개이다.

따라서 글자 순회에 O(N)의 시간 복잡도를 사용한다.

이후 내부 정답 비교에 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

문자열을 이용할 경우 O(N)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

입력받은 수를 문자열로 변환한다.

아무것도 바꾸지 않은 경우 또한 정답이 될 수 있으므로 초기 정답으로 설정한다.

이후 각 index를 순회하며 현재 글자가 6인 경우 9로 변경하며 탐색을 계속한다.

```cpp
int maximum69Number(int num) {
  string numStr = to_string(num);
  string answer = numStr;
  int length = numStr.length();
  for (int i = 0; i < length; i++) {
    string cur = numStr;
    if (cur[i] == '6') {
      cur[i] = '9';
    }

    answer = max(answer, cur);
  }

  return stoi(answer);
}
```

## 고생한 점
