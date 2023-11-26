# 1424. Diagonal Traverse II

[링크](https://leetcode.com/problems/diagonal-traverse-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 2차원 배열의 모든 원소의 갯수를 N이라 하자.

최대 행의 갯수를 R, 최대 열의 갯수를 C라 하자.

모든 원소를 한번씩 순회하며 정답을 구할 경우 시간 복잡도는 O(R \* C)이다. 이는 최악의 경우 제한시간 내에 불가능하다.

원소를 순회하며 해당 좌표를 이용해 몇번째 대각선에 속하는지를 구할 수 있다.

각 대각선차원마다 수를 저장하는 데 hash map을 사용할 경우 O(N)의 시간 복잡도를 사용한다.

이를 묶은 뒤 새 배열을 생성할 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

새로운 배열을 생성하는데 O(N)의 공간 복잡도를 사용한다.

hash map을 이용할 경우 O(N)의 공간 복잡도를 사용한다.

### 대각선 묶음

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     197      |    O(N)     |    O(N)     |

각 좌표마다 어느 대각선에 속하는 지는 해당 좌표의 y,x값의 합으로 구분할 수 있다.

이를 이용해 각 대각선마다 수를 묶고, 이를 순서대로 정답에 삽입한다.

이 때 정답에 순회하는 순서대로 삽입하기 위해선 y좌표 값이 큰 순서대로 삽입해야 한다.

따라서 2차원 배열의 수를 순회할 때 y값이 큰 순으로 순회해야 한다.

```cpp
vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
  int rows = nums.size();

  unordered_map<int, vector<int>> um;
  for (int y = rows - 1; y >= 0; y--) {
    int cols = nums[y].size();

    for (int x = 0; x < cols; x++) {
      int diagonal = y + x;

      um[diagonal].push_back(nums[y][x]);
    }
  }

  vector<int> answer;
  int d = 0;

  while (um.find(d) != um.end()) {
    for (int& num : um[d]) {
      answer.push_back(num);
    }

    d++;
  }

  return answer;
}
```

## 고생한 점
