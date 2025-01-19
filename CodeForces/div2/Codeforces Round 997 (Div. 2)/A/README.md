# A. Shape Perimeter

[링크](https://codeforces.com/contest/2056/problem/A)

| 난이도 |
| :----: |
|  822   |

## 설계

### 시간 복잡도

입력받은 좌표의 수를 N, 도장의 크기를 M이라 하자.

좌표의 크기는 최대 100 이다.

모든 경우를 직접 탐색할 경우 시간 복잡도는 O((N \* M)^2) 이므로 제한시간 내에 불가능하다.

각 좌표를 이동하며 겹치는 부분은 삭제하며 정답을 갱신하는 방법을 사용한다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답과 이전 좌표를 저장하는데 O(1)의 공간 복잡도가 필요하다.

### 수학

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      62      |    O(N)     |    O(1)     |

각 이동 배열을 순차적으로 순회하며 둘레의 길이를 계산한다.

이 때 현재 좌표에서 도장을 찍었을 때 이전에 도장을 찍은 부분과 겹치는 경우가 생길 수 있다.

이 경우 이전 도장의 끝 좌표와 현재 도장의 시작 좌표의 x좌표 차이, y좌표 차이의 2배만큼 둘레의 길이를 줄여준다.

```cpp
struct Axis {
  int y, x;
};

int solution(int n, int m, vector<Axis>& axises) {
  Axis cur = {0, 0};

  int answer = 0;
  int beforeY = -m, beforeX = -m;

  for (Axis& axis : axises) {
    cur.y += axis.y;
    cur.x += axis.x;

    answer += 4 * m;
    if (beforeX + m > cur.x) {
      answer -= 2 * (beforeX + m - cur.x);
    }
    if (beforeY + m > cur.y) {
      answer -= 2 * (beforeY + m - cur.y);
    }

    beforeY = cur.y;
    beforeX = cur.x;
  }

  return answer;
}
```

## 고생한 점
