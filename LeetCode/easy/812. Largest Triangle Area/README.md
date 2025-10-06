# 812. Largest Triangle Area

[링크](https://leetcode.com/problems/largest-triangle-area/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 points의 크기를 N이라 하자.

3개의 점을 모두 탐색하는데 O(N^3)의 시간 복잡도를 사용한다.

각 3개의 점으로 면적을 구하는 데 수학을 사용할 경우 O(1)의 시간 복잡도로 구할 수 있다.

총 시간 복잡도는 O(N^3)이다.

### 공간 복잡도

값을 구하는데 별도의 공간복잡도를 사용하지 않는다.

### 완전 탐색 & 수학

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |   O(N^3)    |    O(1)     |

3개의 점을 모두 탐색하며 각 점으로 이루어진 삼각형의 넓이를 구한다.

3개의 점의 넓이는 단순 다각형의 넓이 공식을 사용한다.

세 점의 좌표를 각각 다음과 같이 표시한다.

```text
a[0] b[0] c[0]
a[1] b[1] c[1]
```

여기서 오른쪽 아래 화살표로 교차하는 값들끼리는 더하고, 왼쪽 아래 화살표로 교차하는 값들끼리는 뺀 후 2로 나누면 넓이를 구할 수 있다.

```cpp
double getArea(vector<int> &a, vector<int> &b, vector<int> &c) {
  return abs(a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - b[0] * a[1] - c[0] * b[1] - a[0] * c[1]) / 2.0;
}

double largestTriangleArea(vector<vector<int>> &points) {
  double answer = 0;

  int size = points.size();

  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      for (int k = j + 1; k < size; k++) {
        answer = max(answer, getArea(points[i], points[j], points[k]));
      }
    }
  }

  return answer;
}
```

## 고생한 점
