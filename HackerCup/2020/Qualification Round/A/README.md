# Problem A: Travel Restrictions

[링크](https://www.facebook.com/codingcompetitions/hacker-cup/2020/qualification-round/problems/A)

| 난이도 |
| :----: |
| 10 pt  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

바로 옆에 있는 노드들로 이동할 수 있으며, 이를 계속해서 최대 어디까지 갈 수 있는지 판단하면 된다.

플로이드 와샬 알고리즘을 사용할 경우 O(N^3)의 시간 복잡도로 각 노드에서 다음 노드까지 탐색 가능한 경우를 탐색할 수 있다.

혹은 각 노드에서 다른 노드까지 연이어 탐색해보며 정답을 구할 수 있다.

이 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(N^2)의 공간 복잡도를 사용한다.

### 브루트 포스

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|   O(N^2)    |   O(N^2)    |

현재 노드 X에서 이웃노드 X`로 이동할 수 있는 경우는 다음과 같다.

- X에서 out이 가능
- X`에서 in이 가능

이를 이용해 각 노드에서 다른 노드들까지 이동할 수 있는지 모두 탐색한다.

```cpp
vector<string> solution(int n, string in, string out) {
  vector<string> answer(n, string(n, 'N'));

  for (int i = 0; i < n; i++) {
    answer[i][i] = 'Y';
  }

  for (int from = 0; from < n; from++) {
    for (int to = from + 1; to < n; to++) {
      if (in[to] == 'Y' && out[to - 1] == 'Y') {
        answer[from][to] = 'Y';
      } else {
        break;
      }
    }

    for (int to = from - 1; to >= 0; to--) {
      if (in[to] == 'Y' && out[to + 1] == 'Y') {
        answer[from][to] = 'Y';
      } else {
        break;
      }
    }
  }

  return answer;
}
```

## 고생한 점
