# 88. Merge Sorted Array

[링크](https://leetcode.com/problems/merge-sorted-array/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

두 배열의 크기의 합은 최대 200이다.

첫번째 배열의 값을 변경해야한다.

### 공간 복잡도

값의 범위는 -10^9 ~ 10^9이다. 이는 int형으로 충분하다.

### 병합 정렬

> 4ms

두 배열이 있을 때 맨 앞에있는 숫자들끼리 비교하고 기준에 따라 새로운 배열에 추가한다.

```cpp
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  vector<int> temp;

  int idx1 = 0;
  int idx2 = 0;
  while (idx1 < m || idx2 < n) {
    if (idx1 >= m) {
      temp.push_back(nums2[idx2]);
      idx2++;
      continue;
    }
    if (idx2 >= n) {
      temp.push_back(nums1[idx1]);
      idx1++;
      continue;
    }

    if (nums1[idx1] < nums2[idx2]) {
      temp.push_back(nums1[idx1]);
      idx1++;
      continue;
    }
    temp.push_back(nums2[idx2]);
    idx2++;
    continue;
  }

  nums1 = temp;
}
```

### 뒤에서부터 정렬

> 0ms

num1 배열의 크기는 m+n이고 뒷부분은 비어있으므로 뒤부터 정렬하는 경우 새로운 배열을 선언하지 않아도 된다.

```cpp
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  int i = m - 1, j = n - 1;
  // order from back
  while (i >= 0 && j >= 0) {
    int k = i + j + 1;

    if (nums1[i] > nums2[j]) {
      nums1[k] = nums1[i];
      i -= 1;
    } else {
      nums1[k] = nums2[j];
      j -= 1;
    }
  }

  // j == -1인 경우에는 이미 앞부분은 num1의 정렬된 숫자들로 채워져 있으므로 더이상 수행하지 않는다.
  if (i == -1) {
    for (int k = 0; k <= j; k++) {
      nums1[k] = nums2[k];
    }
  }
}
```

### STL 이용

```cpp
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  vector<int> res(m + n);
  nums1.resize(m);

  std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), res.begin());

  nums1 = res;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      0       |

## 고생한 점
