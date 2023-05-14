# B. Conveyor Belts

[링크](https://codeforces.com/contest/1811/problem/B)

## 시간 복잡도

보드의 크기를 N이라 하자.

입력받은 두 좌표가 어느 루프에 속해있는지 판단 후 두 루프의 차이를 반환한다.

이는 각 좌표와 보드의 크기를 이용해 구할 수 있다.

이 경우 O(1)의 시간 복잡도를 사용한다.

## 공간 복잡도

별도의 배열을 사용하지 않으므로 O(1)의 공간 복잡도를 사용한다.

## 좌표 계산

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(1)     |    O(1)     |

입력받은 두 좌표가 어느 루프에 속해있는지를 구한다.

각 루프는 각 모서리에서 떨어진 가장 작은 거리가 된다.

따라서 입력받은 좌표를 토대로 각 모서리에서 떨어진 길이 중 가장 작은 값을 찾는다.

이후 두 루프의 차이를 구해 반환한다.

```cpp
auto solution(int size, int x1, int y1, int x2, int y2) {
  int firstX = min(x1, size + 1 - x1);
  int firstY = min(y1, size + 1 - y1);
  int secondX = min(x2, size + 1 - x2);
  int secondY = min(y2, size + 1 - y2);

  int firstLoop = min(firstX, firstY);
  int secondLoop = min(secondX, secondY);

  if (firstLoop == secondLoop) return 0;

  int answer = abs(firstLoop - secondLoop);

  return answer;
}
```