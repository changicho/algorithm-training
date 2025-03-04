# 1151. Minimum Swaps to Group All 1's Together

[링크](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 data의 크기를 N이라 하자.

슬라이딩 윈도우를 이용해 탐색할 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

슬라이딩 윈도우에 1의 갯수만 저장하면 되므로 O(1)의 공간 복잡도가 필요하다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

data의 1의 갯수를 M이라 하자.

크기가 M인 윈도우를 한칸씩 이동해가며 해당 윈도우에 1의 갯수와 윈도우의 크기의 차이만큼 1을 이동시켜야 한다.

해당 갯수 중 최소값이 정답이다.

따라서 슬라이딩 윈도우를 사용해 한칸씩 이동하며 정답을 구한다.

```cpp
int minSwaps(vector<int>& data) {
  int size = data.size();
  int ones = accumulate(data.begin(), data.end(), 0);

  int answer = size;
  int temp = 0;
  for (int left = 0, right = 0; right < size; right++) {
    temp += data[right];

    if (right - left >= ones) {
      temp -= data[left];
      left++;
    }

    if (right - left == ones - 1) {
      answer = min(answer, ones - temp);
    }
  }
  return answer;
}
```

## 고생한 점
