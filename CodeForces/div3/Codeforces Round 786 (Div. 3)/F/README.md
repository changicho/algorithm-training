# F. Desktop Rearrangement

[링크](https://codeforces.com/contest/1674/problem/F)

time : over 60 min

## 풀이

> 2차원 배열을 1차원으로 치환. sliding window 기법

현재상황의 각 좌표에서 아이콘을 정렬한다고 하자.

총 아이콘의 갯수가 iconSize일 때 옮겨야 하는 아이콘의 최소 갯수는 다음과 같을 것이다.

- 1번째부터 iconSize번째 까지 좌표에서, 아이콘이 없는 좌표의 갯수

2차원 좌표에서 column별로 순회를 빠르게 하기 위해서 1차원으로 다음과 같이 치환한다.

```cpp
string line = "";
// column별로 순회하기 위해 x부터 순회함에 유의한다.
for (int x = 0; x < cols; x++) {
  for (int y = 0; y < rows; y++) {
    line += board[y][x];
  }
}
```

이후 우리는 iconSize와, 채워야 하는 범위의 아이콘이 없는 갯수를 알 수 있다.

이후 쿼리에서 특정 좌표를 채워 넣을 때 다음과 같은 경우가 존재한다.

- 좌표가 범위 내에 있는 여부
- 아이콘을 삭제하는지, 아이콘을 생성하는지 여부

또한 아이콘의 갯수가 변경됨에 따라 아래 조건을 판단한다.

- 만약 아이콘을 생성하는 경우 범위는 늘어나고, 새로 포함된 범위에 아이콘이 포함되는지 여부를 판단한다.
- 만약 아이콘을 삭제하는 경우 범위는 줄어들고, 삭제하는 좌표에 아이콘이 포함되는지를 판단한다.

위 조건들을 판단해 범위와, 채워야하는 좌표의 갯수, 범위의 아이콘의 갯수를 변화시켜가며 정답을 구한다.

만약 위 값을 모두 순회해 구할 경우 시간 복잡도는 O(N * M * Q)가 되며 이는 제한시간 내에 불가능하다.

미리 구해준 값을 이용해 변화시켜 구할 경우 O(N * M + Q)의 시간 복잡도를 사용한다.