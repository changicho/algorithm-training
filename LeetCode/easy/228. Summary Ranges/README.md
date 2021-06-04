# 228. Summary Ranges

[링크](https://leetcode.com/problems/summary-ranges/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

한번의 순회를 통해서 연속된 수들을 range로 묶을 수 있다.

이후 연속된 수들을 묶은 뒤 다음 시작점을 이 range 이후로 설정한 뒤 탐색을 진행한다.

이 경우 outer 시간 복잡도는 O(N)이다.

내부적으로 range를 생성하고 정답에 저장하는데 들어가는 시간 복잡도는 O(1)이다.

따라서 최종 시간 복잡도는 O(N)이다.

### 공간 복잡도

range의 범위만 index를 이용해 관리하고 시작값과 끝값만 알면 된다.

따라서 공간 복잡도는 O(1)이다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

범위의 시작점을 left, 끝점을 right로 저장한다.

left가 배열의 크기보다 커질 때 까지 순회를 진행하며 각 경우마다 range의 right를 갱신한다.

이후 범위를 구하고 정답을 저장한 뒤 left를 right + 1 로 갱신한다.

```cpp
vector<string> summaryRanges(vector<int>& nums) {
  vector<string> answer;
  int size = nums.size();
  if (0 == size) return answer;

  int left = 0, right = 0;
  while (left < size) {
    while (right + 1 < size && nums[right] == nums[right + 1] - 1) right++;

    if (left < right) {
      answer.push_back(convert(nums[left], nums[right]));
    } else {
      answer.push_back(convert(nums[left]));
    }

    right += 1;
    left = right;
  }

  return answer;
}

string convert(int number) {
  return to_string(number);
}

string convert(int from, int to) {
  return to_string(from) + "->" + to_string(to);
}
```

### one pass (other way)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

매 순회마다 right의 최대치를 찾는 방법 대신에 매 index를 순회하며 범위를 갱신하는 방법을 이용한다.

따라서 outer iteration만 존재하며 right를 갱신하기 위한 inner iteration은 존재하지 않는다.

연속 관계가 깨졌을 때 정답을 갱신하며 이때 left의 크기가 right 이상인 경우는 숫자가 하나만 들어가는 상황이다.

이후 iteration이 끝난 뒤에 맨 마지막 범위를 정답에 넣는다.

```cpp
vector<string> summaryRanges(vector<int>& nums) {
  int size = nums.size();
  vector<string> answer;
  if (size == 0) return answer;

  int left = 0, right = 0;
  for (int i = 1; i < size; i++) {
    if (nums[i] - 1 == nums[i - 1]) {
      right = i;
      continue;
    }

    if (left >= right) {
      right = left;
      answer.push_back(convert(nums[left]));
    } else {
      answer.push_back(convert(nums[left], nums[right]));
    }
    left = i;
  }

  if (left >= right) {
    answer.push_back(convert(nums[left]));
  } else {
    answer.push_back(convert(nums[left], nums[right]));
  }

  return answer;
}

string convert(int number) {
  return to_string(number);
}

string convert(int from, int to) {
  return to_string(from) + "->" + to_string(to);
}
```

## 고생한 점
