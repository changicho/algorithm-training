# 402. Remove K Digits

[링크](https://leetcode.com/problems/remove-k-digits/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 num의 길이를 N이라 하자.

모노토닉 스택을 이용해 top으로 갈 수록 작아지도록 만들 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

모노토닉 스택에 O(N)의 공간 복잡도를 사용한다.

### 모노토닉 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(N)     |

모노토닉 스택을 이용해 top으로 갈 수록 수가 작아지도록 저장한다.

이 때 삭제할 수 있는 숫자는 최대 k개 임에 유의한다.

해당 작업 이후 k가 남아있는 경우 남은 k만큼 뒤에서부터 제거한다.

```cpp
string removeKdigits(string num, int k) {
  int size = num.size();
  if (size == k) return "0";

  vector<char> stk;

  for (char &c : num) {
    while (k > 0 && !stk.empty() && stk.back() > c) {
      stk.pop_back();
      k--;
    }
    stk.push_back(c);
  }

  while (k > 0) {
    k--;
    stk.pop_back();
  }

  string answer = "";
  for (char &c : stk) {
    if (c == '0' && answer == "") continue;
    answer += c;
  }

  if (answer == "") return "0";
  return answer;
}
```

## 고생한 점
