# 2768. Number of Black Blocks

[링크](https://leetcode.com/problems/number-of-black-blocks/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 좌표의 크기 M, N 그리고 색칠할 좌표의 수를 C라 하자.

N과 M이 매우 크므로 직접 탐색할 경우 시간 복잡도는 O(N \* M)이며 제한시간 내에 불가능하다.

따라서 색칠할 좌표들을 hash set으로 관리하며 각 좌표마다 영향을 주는 색칠된 갯수를 갱신한다.

이 때 중복방문을 줄이기 위해 방문여부를 체크한다.

이 경우 O(C)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash set에 방문 여부와 색칠된 갯수를 저장한다. 이에 O(C)의 공간 복잡도를 사용한다.

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     1233     |    O(C)     |    O(C)     |

정답으로 채우는 크기가 5인 배열은 다음을 의미한다.

- index : 2x2 블록에서 색칠된 블록 갯수가 index일때 이 갯수

모든 경우를 배열로 만들어 탐색할 경우 제한시간 내에 불가능하다.

따라서 색칠된 좌표들을 관리해 각 좌표마다 영향을 주는 색칠된 갯수를 갱신한다.

여기서 정답에서 index가 0인 경우는 아래와 같이 구할수 있다.

```cpp
long long total = (long long)(m - 1) * (n - 1);
answer[0] = total - answer[1] - answer[2] - answer[3] - answer[4];
```

2x2 크기의 블록들에서 색칠된 좌표를 찾아야 하므로 하나의 좌표가 색칠되었을 때 4가지 블록에 영향을 주게 된다.

아래와 같은 3x3 크기의 배열을 생각해보자

```plain_text
0 0 0
0 1 0
0 0 0
```

1,1좌표에 색이 칠해진 경우 2x2 블록에 영향을 주는 경우는 다음과 같다. (블록의 왼쪽 위 좌표로 블록을 구분)

- 0,0
- 0,1
- 1,0
- 1,1

따라서 색칠된 좌표들을 순회하며 다음 4가지 블록 경우에 대해 정답을 갱신한다.

이 때 블록이 색칠된 범위가 겹쳐 서로 영향을 줄 수 있으므로 중복 방문 제거를 위해 hash set을 사용한다.

각 좌표를 long long형으로 치환 가능하므로 이를 이용해 key를 생성 후 중복 방문, 색칠된 좌표 등을 같이 관리한다.

```cpp
vector<vector<int>> cornerDiffs = {{-1, -1}, {-1, 0}, {0, -1}, {0, 0}};

long long convert(int y, int x) { return y * 1000000LL + x; }

vector<long long> countBlackBlocks(int m, int n,
                                    vector<vector<int>> &coordinates) {
  // y : m, x : n
  vector<long long> answer(5);

  unordered_set<long long> us;
  for (vector<int> &coord : coordinates) {
    int y = coord[0], x = coord[1];

    us.insert(convert(y, x));
  }

  unordered_set<long long> visited;

  for (vector<int> &cur : coordinates) {
    int y = cur[0], x = cur[1];

    for (vector<int> &cornerDiff : cornerDiffs) {
      int oy = y + cornerDiff[0], ox = x + cornerDiff[1];

      if (oy < 0 || oy >= m - 1 || ox < 0 || ox >= n - 1) continue;
      long long key = convert(oy, ox);
      if (visited.count(key) > 0) continue;
      visited.insert(key);

      int count = 0;
      if (us.count(convert(oy, ox))) count++;
      if (us.count(convert(oy, ox + 1))) count++;
      if (us.count(convert(oy + 1, ox))) count++;
      if (us.count(convert(oy + 1, ox + 1))) count++;

      answer[count]++;
    }
  }

  long long total = (long long)(m - 1) * (n - 1);
  answer[0] = total - answer[1] - answer[2] - answer[3] - answer[4];
  return answer;
}
```

## 고생한 점
