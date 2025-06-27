# C - Black Intervals

[링크](https://atcoder.jp/contests/abc411/tasks/abc411_c)

| 난이도 |
| :----: |
|  350   |

## 설계

### 시간 복잡도

입력받은 좌표의 수를 N, 쿼리의 수를 Q라고 하자.

각 쿼리를 순회하며 특정 좌표의 색을 변경한다. 이 때 매번 수를 셀 경우 O(Q \* N)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

각 좌표에 연결된 다른 좌표의 경우의 수를 이용해 색을 변경할 경우 O(Q)의 시간 복잡도로 해결할 수 있다.

### 공간 복잡도

각 좌표마다 색을 저장하는데 O(N)의 공간 복잡도를 사용한다.

정답에 O(Q)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      53      |    O(Q)     |  O(N + Q)   |

특정 좌표 X의 색을 흰색으로 변경할 때 다음과 같은 경우의 수들이 존재한다.

- X-1, X+1 좌표의 색이 모두 검정색인 경우
- X-1, X+1 좌표의 색이 모두 흰색인 경우
- 두 좌표의 색이 다른경우

만약 두 좌표의 색이 모두 흰색이며 현재 좌표를 흰색으로 칠할 경우 흰색 덩어리의 수가 1개 줄어들게 된다.

반대로 두 좌표의 색이 검정색인 경우 덩어리의 수가 1개 늘어나게 된다.

만약 두 좌표중 하나의 색이 흰색인 경우 덩어리의 수는 변하지 않는다.

이는 X의 색을 검정색으로 변경할 때도 유사하게 적용된다.

이를 이용해 각 좌표의 색을 변경할 때마다 현재 흰색 덩어리의 수를 세는 시뮬레이션을 구현한다.

```cpp
vector<int> solution(int n, int q, vector<int> &a) {
  vector<bool> colors(n + 2, false);

  int count = 0;

  vector<int> answer;

  for (int &x : a) {
    if (colors[x] == true) {
      // black
      if (colors[x - 1] == true && colors[x + 1] == true) {
        count++;
      } else if (colors[x - 1] == false && colors[x + 1] == false) {
        count--;
      }

      colors[x] = false;
    } else {
      // white
      if (colors[x - 1] == true && colors[x + 1] == true) {
        count--;
      } else if (colors[x - 1] == false && colors[x + 1] == false) {
        count++;
      }

      colors[x] = true;
    }

    answer.push_back(count);
  }

  return answer;
}
```

## 고생한 점
