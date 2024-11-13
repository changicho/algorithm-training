# 1213. Intersection of Three Sorted Arrays

[링크](https://leetcode.com/problems/intersection-of-three-sorted-arrays/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

세 배열의 총 크기를 N이라 하자.

hash set을 이용해 모든 경우를 탐색할 경우 O(N)의 시간 복잡도가 소요된다.

세개의 포인터를 사용할 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

hash set을 이용할 경우 O(N)의 공간 복잡도가 필요하다.

세개의 포인터를 사용할 경우 O(1)의 공간 복잡도가 필요하다.

정답 배열에 O(N)의 공간 복잡도가 필요하다.

### 3 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

세 배열의 index를 각각 저장한다.

이후 세 index가 모두 같은 경우에만 정답에 추가한다.

그 외의 경우 세 index중 가장 작은 index를 증가시킨다. (같은 경우도 포함)

```cpp
vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
  vector<int> answer;

  int size1 = arr1.size(), size2 = arr2.size(), size3 = arr3.size();
  int i1 = 0, i2 = 0, i3 = 0;

  while (i1 < size1 && i2 < size2 && i3 < size3) {
    if (arr1[i1] == arr2[i2] && arr2[i2] == arr3[i3]) {
      answer.push_back(arr1[i1]);
      i1++;
      i2++;
      i3++;
      continue;
    }

    if (arr1[i1] <= arr2[i2] && arr1[i1] <= arr3[i3]) {
      i1++;
      continue;
    }
    if (arr2[i2] <= arr1[i1] && arr2[i2] <= arr3[i3]) {
      i2++;
      continue;
    }
    if (arr3[i3] <= arr1[i1] && arr3[i3] <= arr2[i2]) {
      i3++;
      continue;
    }
  }
  return answer;
}
```

## 고생한 점
