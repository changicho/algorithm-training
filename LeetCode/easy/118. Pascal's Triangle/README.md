# 118. Pascal's Triangle

[링크](https://leetcode.com/problems/pascals-triangle/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

numRows는 최대 30이다.

파스칼의 삼각형의 높이가 30이라고 할 때, 숫자의 개수는 N \* (N+1) / 2 이다. 이는 O(N^2) 미만이며 제한시간 내에 충분하다.

이를 이전의 연산결과를 이용해 구할 수 있으므로 dp를 사용한다.

### 공간 복잡도

O(N^2) 만큼의 (실제로는 N \* (N+1) / 2) 공간이 필요하다.

### 메모이제이션

> 0ms, O(N^2)

파스칼의 삼각형의 일반 식은 다음과 같다.

```cpp
pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
```

초기값은 다음과 같다.

```cpp
pascal[i][0] = 1;
pascal[i][i] = 1;
```

여기서 임계값인 경우(x좌표가 0, i인 경우)를 제외하기 위해 양 끝에는 1을 push한다.

numRows는 최소 1 이므로 i=0인 경우는 미리 생성해놓는다.

```cpp
vector<vector<int>> generate(int numRows) {
  vector<vector<int>> pascal;

  pascal.push_back({1});

  for (int i = 1; i < numRows; i++) {
    vector<int> row = {
        1,
    };
    int size = pascal[i - 1].size();
    for (int j = 1; j < size; j++) {
      row.push_back(pascal[i - 1][j - 1] + pascal[i - 1][j]);
    }
    row.push_back(1);

    pascal.push_back(row);
  }

  return pascal;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      0       |

## 고생한 점
