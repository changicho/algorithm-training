# 1405. Longest Happy String

[링크](https://leetcode.com/problems/longest-happy-string/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수 A, B, C의 합을 N이라 하자.

모든 경우를 탐색할 경우 O(3^N)의 시간 복잡도가 소요되며 이는 제한시간 내에 불가능하다.

그리디 알고리즘을 사용할 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

정답 문자열에 대한 공간 복잡도는 O(N)이다.

그리디 알고리즘에 사용할 우선순위 큐에 대한 공간 복잡도는 O(1)이다.

### 그리디 알고리즘 & 힙

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

정답을 만족하는 문자열을 만들기 위해 다음과 같은 방법을 사용한다.

- 현재 가장 많이 남은 문자를 이어붙인다.
- 이 때 3개가 연속되는 경우 두번째로 많이 남은 문자를 이어붙인다.

이는 최대한 많은 문자를 매 경우 이어 붙일 수 있게 하기 위함이다.

이 과정에서 우선순위 큐를 이용해 가장 많이 남은 문자를 찾는다.

```cpp
bool isTripleSame(char &a, char &b, char &c) { return a == b && b == c; }

string longestDiverseString(int a, int b, int c) {
  string answer = "";
  priority_queue<pair<int, char>> pq;

  pq.push({a, 'a'});
  pq.push({b, 'b'});
  pq.push({c, 'c'});

  while (!pq.empty()) {
    int size = answer.size();
    auto first = pq.top();
    pq.pop();

    if (first.first == 0) break;

    if (answer.size() < 2 ||
        !isTripleSame(answer[size - 1], answer[size - 2], first.second)) {
      answer.push_back(first.second);

      pq.push({first.first - 1, first.second});
    } else {
      auto second = pq.top();
      pq.pop();

      if (second.first == 0) break;

      answer.push_back(second.second);

      pq.push({second.first - 1, second.second});
      pq.push(first);
    }
  }

  return answer;
}
```

## 고생한 점
