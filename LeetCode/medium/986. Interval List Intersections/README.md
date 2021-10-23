# 986. Interval List Intersections

[링크](https://leetcode.com/problems/interval-list-intersections/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

두 list의 길이를 각각 N, M이라 하자.

두 리스트의 모든 값들을 조합해 순회할 경우 시간 복잡도는 O(N \* M)이 된다.

투 포인터를 이용할 경우 O(N + M)의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

투 포인터를 이용할 경우 index만을 이용하면 된다.

정답은 배열을 반환해야 하므로 O(N + M)의 공간 복잡도를 사용한다.

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      36      |  O(N + M)   |  O(N + M)   |

두 list 모두 오름차순으로 정렬되어있으므로 둘다 0번째 index에서부터 서로 겹치는지 판별한다.

겹치는지에 대한 판별은 다음과 같이 수행할 수 있다.

```cpp
Range range1, range2; // start, end

if(range1.start <= range2.end && range2.start <= range1.end){
  isOverlapped = true;
}else{
  isOverlapped = false;
}
```

두 리스트의 각 값마다 overlapped를 판별한다.

만약 첫번째 값의 end가 두번째 값의 end보다 작은 경우 첫번째 index를 증가시키고,

반대의 경우는 두번째 index를 증가시킨다.

두 index 모두 list에서 유효한 범위만 탐색해야 하므로 index가 범위를 초과한 경우 탐색을 중지한다.

```cpp
vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
vector<vector<int>>& secondList) {
  int size1 = firstList.size(), size2 = secondList.size();
  int idx1 = 0, idx2 = 0;
  vector<vector<int>> answer;

  while (idx1 < size1 && idx2 < size2) {
    vector<int> target1 = firstList[idx1];
    vector<int> target2 = secondList[idx2];

    // overlapped
    if (target1[0] <= target2[1] && target2[0] <= target1[1]) {
      int from = max(target1[0], target2[0]);
      int to = min(target1[1], target2[1]);

      answer.push_back({from, to});
    }

    if (target1[1] < target2[1]) {
      idx1++;
    } else {
      idx2++;
    }
  }

  return answer;
}
```

## 고생한 점
