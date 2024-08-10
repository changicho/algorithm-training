# 3228. Maximum Number of Operations to Move Ones to the End

[링크](https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

N에서 연이은 1들의 갯수를 세는데 O(N)의 시간 복잡도가 필요하다.

이를 이용해 각 연이은 1들의 갯수를 세고, 이를 이용해 정답을 구할 수 있다.

따라서 총 시간 복잡도는 O(N)이다.

### 공간 복잡도

연속된 1의 수를 세는데 O(1)의 공간 복잡도를 사용한다.

### 연속된 1의 갯수

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      33      |    O(N)     |    O(1)     |

현재 1이 움직일 수 있는 경우는 다음과 같다.

- 오른쪽에 0이 있을 때

만약 1이 연속되어 있는 경우, 해당 갯수를 X라 하자.

이후 0을 만났을 때 1을 이동시킬 수 있는 횟수는 X이다.

해당 X개의 1을 이동시킨 뒤 해당 이동한 1과 새로운 1들이 연속되어 있을 수 있다.

이 경우 위 방법을 반복한다.

따라서 연속된 1의 갯수들을 센 뒤, 이를 이용해 정답을 구할 수 있다.

```cpp
int maxOperations(string s) {
  int size = s.size();

  int answer = 0;
  int count = 0;
  int ones = 0;
  for (char &c : s) {
    if (c == '1') {
      count++;
    } else {
      if (count > 0) {
        ones += count;
        answer += ones;
      }
      count = 0;
    }
  }

  return answer;
}
```

## 고생한 점
