# 19941. 햄버거 분배

[링크](https://www.acmicpc.net/problem/19941)

| 정답률 |  난이도  |
| :----: | :------: |
|  49%   | 실버 III |

## 설계

### 시간 복잡도

입력받은 인원의 수를 N이라 하자. (N <= 20,000)

각 인원마다 모든 경우를 탐색할 경우 매우 O(K^N)의 시간 복잡도를 사용한다. 이는 매우 큰 값이므로 제한시간 내에 불가능하다.

모노토닉 큐를 이용해 각 인원중 최선의 값을 선택해 할당할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

모노토닉 큐를 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 모노토닉 큐

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

각 인원들은 현재 선택할 수 있는 햄버거 중 가장 먼 햄버거를 선택하는 쪽이 유리하다.

이 때 한쪽 방향으로 탐색해야 하며, 이미 탐색한 햄버거 중에서 선택함에 유의한다.

이는 이전에 이미 선택받지 않은 햄버거 중에 가장 멀리있는 햄버거를 선택해야 이후 나오는 인원에게 유리하기 때문이다.

따라서 한쪽 방향으로 탐색을 진행하며 모노토닉 큐에 햄버거를 삽입하고, 현재 인원을 방문했을 때 큐의 가장 앞에있는 가능한 햄버거를 할당한다.

반대로 현재 햄버거를 방문한 경우, 이전까지 방문한 인원 중에서 할당할 수 있는 가장 유리한 인원을 선택한다.

이를 구현하면 다음과 같다.

```cpp
int solution(int size, int k, string &line) {
  int answer = 0;

  queue<int> hamburgers, peoples;
  for (int i = 0; i < size; i++) {
    while (!hamburgers.empty() && hamburgers.front() < i - k) {
      hamburgers.pop();
    }
    while (!peoples.empty() && peoples.front() < i - k) {
      peoples.pop();
    }

    if (line[i] == 'H') {
      if (!peoples.empty() && peoples.front() + k >= i) {
        answer++;
        peoples.pop();
        continue;
      }

      hamburgers.push(i);
    } else if (line[i] == 'P') {
      if (!hamburgers.empty() && hamburgers.front() + k >= i) {
        answer++;
        hamburgers.pop();
        continue;
      }

      peoples.push(i);
    }
  }

  return answer;
}
```

## 고생한 점
