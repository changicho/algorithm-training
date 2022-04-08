# 2193. Minimum Number of Moves to Make Palindrome

[링크](https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

문자열 s의 길이를 L이라 하자.

각 문자마다 최적의 위치를 찾아 이동시키는 탐욕 알고리즘을 사용할 경우 O(L^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

### 탐욕 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |   O(L^2)    |    O(L)     |

문자열 s에서 특정 문자가 하나밖에 없는 경우를 살펴보자.

이 경우 해당 문자는 무조건 팰린드롬의 중앙에 위치해야 한다.

그 외의 경우 (쌍이 있는 경우)를 생각해보자.

결국 회문이 만들어지므로 회문의 절반에 대해서 탐색을 진행하며, 나머지 절반을 이동하며 채운다.

이 때 두 글자 모두 이동시키는것보다, 한쪽을 다른 한쪽에 맞춘다. (이동 횟수 자체는 동일하므로)

이를 이용해 s의 맨 뒤부터 쌍을 맞추며 나머지 한쪽을 얼마나 이동시켜야 하는지 계산한다.

자연스럽게 맨 뒤 문자부터 탐색하므로, 다른 쌍은 앞으로 이동하게 되며, 이는 이후 다음 쌍을 채울 때 다른 문자들의 이동 순서에 영향을 받지 않게된다.

따라서 문자열 s의 맨 뒤부터 각 쌍을 구해 이동 거리를 계산하고, 해당 쌍을 제거한다.

이를 모든 문자에 대해 반복하며 결과적으로 s가 빈 문자열이 될 때 탈출조건이 된다.

이는 맨 뒷글자가 아닌 맨 앞글자를 대상으로 해도 동일하다.

```cpp
int minMovesToMakePalindrome(string s) {
  int moves = 0;

  while (!s.empty()) {
    int index = s.find(s.back());
    // move to center
    if (index == s.size() - 1) {
      moves += index / 2;
    } else {
      moves += index;
      s.erase(index, 1);
    }

    s.pop_back();
  }

  return moves;
}
```

## 고생한 점
