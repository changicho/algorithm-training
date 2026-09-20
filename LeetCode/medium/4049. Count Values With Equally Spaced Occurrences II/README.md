# 4049. Count Values With Equally Spaced Occurrences II

[링크](https://leetcode.com/problems/count-values-with-equally-spaced-occurrences-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

각 값별로 index를 저장 후 비교할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 값마다 index들을 hash map에 저장할 경우 O(N)의 공간 복잡도를 사용한다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     236      |    O(N)     |    O(N)     |

각 값별로 index들을 저장 후, index가 3개 이상인 경우 간격을 확인한다.

```cpp
int countSpecialIntegers(vector<int>& nums) {
  int size = nums.size();

  unordered_map<int, vector<int>> um;

  for (int i = 0; i < size; i++) {
    int num = nums[i];

    um[num].push_back(i);
  }

  int answer = 0;
  for (auto& [num, indices] : um) {
    if (indices.size() < 3) continue;
    int isize = indices.size();
    int diff = indices[1] - indices[0];
    bool isValid = true;

    for (int i = 2; i < isize; i++) {
      if (diff != indices[i] - indices[i - 1]) {
        isValid = false;
        break;
      }
    }

    answer += isValid;
  }
  return answer;
}
```

## 고생한 점
