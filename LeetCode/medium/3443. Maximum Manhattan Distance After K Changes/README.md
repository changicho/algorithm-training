# 3443. Maximum Manhattan Distance After K Changes

[링크](https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N, 입력받은 수를 K라 하자.

문자열을 순회하며 좌표를 이동하고, 각 좌표에서 K를 이용해 가능한 최대값을 구한다.

이 경우 O(N)의 시간 복잡도들 사용한다.

### 공간 복잡도

좌표를 저장하는 데 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      69      |    O(N)     |    O(1)     |

s의 경로대로 순차적으로 좌표를 이동하며, 현재 좌표에서 K번의 연산을 이용해 가능한 최대 맨해튼 거리를 구한다.

이 때 K번 좌표를 바꾸는 것을 다음과 같이 생각할 수 있다.

- 한 축 (y축 혹은 x축)에서 +1, -1의 경로가 각각 주어진다.
- 하나의 경로를 반대 부호로 바꿀 경우 해당 축의 거리를 2만큼 늘릴 수 있다.
- 따라서 K번의 연산을 이용해서 각 축의 거리를 2 \* K만큼 늘릴 수 있다.
- 하나의 축에서 K번 미만으로 최대 거리를 구할 수 있는 경우 다른 축에 이를 사용할 수 있다.

이 때 현재까지 이동한 좌표의 수 이상의 맨해튼 거리를 생성할 수 없음에 유의한다.

```cpp
int maxDistance(string s, int k) {
  int size = s.size();
  int y = 0, x = 0, answer = 0;

  for (int i = 0; i < size; i++) {
    switch (s[i]) {
      case 'N':
        y++;
        break;
      case 'S':
        y--;
        break;
      case 'E':
        x++;
        break;
      case 'W':
        x--;
        break;
    }

    answer = max(answer, min(abs(x) + abs(y) + k * 2, i + 1));
  }
  return answer;
}
```

## 고생한 점
