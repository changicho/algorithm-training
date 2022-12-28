# 2515. Shortest Distance to Target String in a Circular Array

[링크](https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 단어의 갯수를 N이라 하자.

각 단어를 순회하며 target들을 찾고 해당 index들과 startIndex의 최소 차이를 구해야한다.

이 경우 순회에 O(N)의 시간 복잡도를 사용한다.

매 경우 직접 startIndex까지의 차이를 순회로 구할 경우 O(N^2)의 시간 복잡도를 사용한다.

계산을 이용해 구할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

별도로 index들을 저장할 경우 O(N)의 공간 복잡도를 사용한다.

탐색과 동시에 정답을 구할 경우 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      31      |    O(N)     |    O(1)     |

순환이 가능한 이동에서 두 index의 차이는 다음과 같은 두 경우 중 한가지이다.

- boundary를 넘지 않은 차이
- boundary를 넘은 차이

여기서 두 값의 합은 N이 됨에 유의하자.

여기서 첫번째 값은 다음과 같이 구할 수 있다.

- abs(first - second)

이를 이용해 각 target들의 index와 startIndex의 차이 중 최소값을 반환한다.

```cpp
int closetTarget(vector<string>& words, string target, int startIndex) {
  int size = words.size();

  int answer = INT_MAX;
  for (int i = 0; i < size; i++) {
    if (words[i] != target) continue;

    int first = abs(startIndex - i);
    int second = abs(size - first);

    answer = min({answer, first, second});
  }

  return answer == INT_MAX ? -1 : answer;
}
```

## 고생한 점
