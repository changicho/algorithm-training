# ASCII Art (9pts, 20pts)

[링크](https://codingcompetitions.withgoogle.com/codejam/round/0000000000c95b94/0000000000cad9c2)

## 설계

### 시간 복잡도

입력받은 숫자를 N이라 하자. N은 최대 10^12 이다.

각 경우마다 직접 계산할 경우 O(N)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

따라서 각 순회마다의 끝 좌표와 나누기를 이용해 구한다.

이 때 입력받은 N에 해당하는 순회의 번째를 이분 탐색으로 구할 수 있다.

N이 최대값일 때 루프의 횟수는 최대 277,351번 이다. 이를 L이라 하자.

각 경우마다 O(log_2(L))의 시간 복잡도를 사용한다.

### 공간 복잡도

입력받은 숫자가 매우 크므로 long long 형을 사용한다.

각 루프의 횟수를 저장하는 데 O(L)의 공간 복잡도를 사용한다.

### 이분 탐색

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
| O(log_2(L)) |    O(L)     |

문자열은 다음 규칙을 이용해 생성된다.

- A~Z가 1번씩 반복
- A~Z가 2번씩 반복
- ...

여기서 반복되는 횟수에 따라서 이를 루프라고 하자.

- 첫번째 루프의 범위는 1 ~ 26
- 두번째 루프의 범위는 27 ~ (27 + 26\*2)
- 세번째 루프의 범위는 (27 + 26*2) ~ (27 + 26*2 + 26\*3)

이렇게 각 루프의 시작점과 끝점을 위와 같이 나타낼 수 있다.

이를 N이 입력되는 범위인 10^12 까지 구한다.

이후 입력받은 N에 대해서 루프의 번째를 이분 탐색으로 구한다.

이후 해당 루프에서의 문자의 위치를 구한다.

이는 루프의 번째와 시작점에서의 위치를 이용해 구할 수 있다.

- 현재 루프의 번째를 X, 현재 루프의 시작점에서부터 떨어진 위치를 Y라 하자.
- ceil(Y/X) 번째 알파벳이 해당 위치의 문자가 된다.

```cpp
vector<long long> boundaryEnds;
vector<long long> loops;

char solution(long long num) {
  int idx = lower_bound(boundaryEnds.begin(), boundaryEnds.end(), num) -
            boundaryEnds.begin();

  long long boundaryEnd = boundaryEnds[idx - 1];
  long long loop = loops[idx - 1];

  long long target = num - boundaryEnd;

  int move = ceil((double)target / loop);
  return (move - 1) + 'A';
}

void init() {
  long long boundaryEnd = 0;
  long long loop = 1;

  boundaryEnds.push_back(boundaryEnd);
  loops.push_back(loop);

  while (boundaryEnd <= 1e12) {
    loop++;
    boundaryEnd += (loop - 1) * 26;

    boundaryEnds.push_back(boundaryEnd);
    loops.push_back(loop);
  }
}
```

## 고생한 점
