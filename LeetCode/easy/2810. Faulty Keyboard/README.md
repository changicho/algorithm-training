# 2810. Faulty Keyboard

[링크](https://leetcode.com/problems/faulty-keyboard/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 문자열의 길이를 N이라 하자.

직접 문자열을 뒤집으며 구현할 경우 O(N^2)의 시간 복잡도를 사용한다.

deque를 사용해 직접 뒤집지 않고 문자열이 추가되는 방향을 변경하며 풀이할 수있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

반환할 문자열에 O(N)의 공간 복잡도를 사용한다.

deque에 O(N)의 공간 복잡도를 사용한다.

### 데큐 (deque)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|       9       |    O(N)         |    O(N)         |

i가 입력될 때마다 기존 문자열을 뒤집고 뒤에 문자를 추가한다.

이는 문자열을 뒤집지 않고 생각한다면 i가 입력될 때마다 문자가 추가되는 방향이 변경된다고 생각할 수 있다.

따라서 deque를 이용해 문자가 앞, 뒤로 삽입될 수 있게 하고 i가 입력될 때마다 뒤집는다.

이후 정답을 반환시에 현재 상태가 정방향, 역방향인지 판단해 정답을 반환한다.

```cpp
string finalString(string s) {
  deque<char> dq;
  bool isReversed = false;

  for (char &c : s) {
    if (c == 'i') {
      isReversed = !isReversed;
    } else {
      if (isReversed) {
        dq.push_front(c);
      } else {
        dq.push_back(c);
      }
    }
  }

  string answer =
      isReversed ? string(rbegin(dq), rend(dq)) : string(begin(dq), end(dq));
  return answer;
}
```

## 고생한 점
