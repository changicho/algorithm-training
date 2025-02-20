# C. Palindromic Subsequences

[링크](https://codeforces.com/contest/2056/problem/C)

| 난이도 |
| :----: |
|  1500  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

조건을 만족하는 크기 N의 배열을 만들어야 한다.

이를 모두 탐색할 경우 시간 복잡도는 O(100^N)이므로 제한시간 내에 불가능하다.

그리디 알고리즘을 사용해 조건을 만족하는 배열을 만들어야 한다.

이 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

정답 배열에 O(N)의 공간 복잡도가 필요하다.

### 탐욕 알고리즘 & 수학

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      62      |    O(N)     |    O(N)     |

다음 두 조건을 만족해야 한다.

- 배열의 가장 긴 팰린드롬의 길이를 X라 하자.
- 배열의 가장 긴 팰린드롬의 갯수는 N개를 넘어야 한다.

이를 만족하기 위해 X가 3인 배열을 강제로 만든다.

이를 위해 각 원소의 순서는 아래 규칙을 따른다.

- 배열의 첫번째 원소와 마지막 원소만 같게 만든다.
- 나머지 원소는 모두 다른값으로 채운다.

이 경우 X = 3인 조건을 만족할 수 있으나 두번째 조건을 만족할 수 없다.

따라서 X = 3인 조건을 만족하면서 두번째 조건을 만족하는 배열을 만들어야 한다.

이를 위해 N-1번째 원소 또한 1로 만든다.

이 경우 다음과 같은 형태를 따른다.

```javascript
const arr = [1, 2, 3, 4, ... , N-2, 1 , 1];
```

위 형태의 경우 X = 3이며 N개를 넘는 팰린드롬을 만들 수 있다.

```cpp
vector<int> solution(int n) {
  vector<int> answer(n, 1);
  for (int i = 0; i < n; i++) {
    answer[i] = i + 1;
  }
  answer[n - 1] = 1;
  answer[n - 2] = 1;

  return answer;
}
```

## 고생한 점
