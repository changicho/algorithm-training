# B - Permute to Minimize

[링크](https://atcoder.jp/contests/abc432/tasks/abc432_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

입력받은 숫자의 길이를 N이라 하자.

각 숫자를 count한 뒤 정답을 생성할 수 있다.

이에 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

각 숫자를 count하기 위해 O(1)의 공간 복잡도가 소요된다.

### 카운팅

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(1)     |

입력받은 숫자의 각 숫자를 count한다.

이후 0이 아닌 가장 작은 수를 찾고, 해당 수를 첫번째 숫자로 설정한 뒤 카운트를 하나 줄인다.

이후 나머지 숫자들을 오름차순으로 정답에 추가한다.

```cpp
string solution(string& x) {
  int count[10] = {
      0,
  };

  for (char c : x) {
    count[c - '0']++;
  }

  int minimum = INT_MAX;
  for (int i = 1; i <= 9; i++) {
    if (count[i] > 0) {
      minimum = i;
      break;
    }
  }

  if (minimum == INT_MAX) {
    return "0";
  }
  string answer = "";
  count[minimum]--;
  answer += to_string(minimum);
  for (int i = 0; i <= 9; i++) {
    while (count[i] > 0) {
      answer += to_string(i);
      count[i]--;
    }
  }

  return answer;
}
```

## 고생한 점
