# 3453. Separate Squares I

[링크](https://leetcode.com/problems/separate-squares-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 squares의 길이를 N, 정사각형의 최대 y좌표를 M이라 하자.

이분 탐색을 이용해 모든 정사각형 넓이의 합이 같아지는 y좌표를 찾는다.

이에 O(log_2(M))의 시간 복잡도를 사용한다.

매 과정마다 각 너비를 구하는데 O(N)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N \* log_2(M))이다.

### 공간 복잡도

이분탐색, 넓이 계산에 상수 개수의 변수를 사용하므로 O(1)의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      83      | O(N \* log_2(M)) |    O(1)     |

특정 y좌표에 대해서 해당 직선을 기준으로 잘라 아래쪽에 있는 정사각형의 넓이의 합을 구할 수 있다.

해당 넓이가 전체 정사각형 넓이의 절반 이상인지 확인하는 함수 check를 작성한다.

이분 탐색과정에서 y좌표를 탐색하며 특정 지점까지는 넓이의 합이 절반 이상이며, 그 외의 경우는 절반 미만인 경우를 찾는다.

```cpp
bool check(vector<vector<int>>& squares, double lineY, double totalArea) {
  double area = 0;

  for (vector<int>& s : squares) {
    double x = s[0], y = s[1], l = s[2];

    if (y < lineY) {
      area += l * min(lineY - y, l);
    }
  }

  return area >= totalArea / 2;
}

double separateSquares(vector<vector<int>>& squares) {
  double left = 0, right = 0;

  double totalArea = 0;
  for (vector<int>& s : squares) {
    double x = s[0], y = s[1], l = s[2];
    totalArea += l * l;
    right = max(right, y + l);
  }

  double answer = -1;
  while (abs(right - left) > 1e-5) {
    double mid = left + (right - left) / 2;

    if (check(squares, mid, totalArea)) {
      right = mid;
      answer = mid;
    } else {
      left = mid;
    }
  }

  return answer;
}
```

## 고생한 점
