# 1653. Minimum Deletions to Make String Balanced

[링크](https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

prefixSum, suffixSum을 사용해 각 위치에서의 삭제할 갯수를 구할 수 있다.

이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

prefixSum, suffixSum을 사용해 각 위치에서의 삭제할 갯수를 구할 수 있다.

이 경우 공간 복잡도는 O(N)이다.

한칸씩 이동하므로 직전값만 갱신해 사용할 수 있다.

이 경우 O(1)의 공간 복잡도를 사용한다.

### prefix two pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      89      |    O(N)     |    O(1)     |

각 index별로 순회한다 하자.

이 경우 0 ~ index, index+1 ~ N-1까지의 문자열을 나눌 수 있다.

이 중 앞부분은 a로만, 뒷부분은 b로만 이루어진 문자열을 만들 때의 삭제 횟수를 구할 수 있다.

이 중 최소값을 구하면 된다.

이 중 a와 b 중 하나를 기준으로 s에서 해당 문자의 수를 센 뒤 반대 방향으로 index를 이동시키며 두 문자의 수를 비교하며 최소값을 갱신한다.

```cpp
int minimumDeletions(string s) {
  int size = s.size();

  // a : left, b : right
  int aCount = 0, bCount = 0;
  for (int i = 0; i < size; i++) {
    if (s[i] == 'b') bCount++;
  }

  int answer = bCount;
  for (int i = size - 1; i >= 0; i--) {
    if (s[i] == 'a') {
      aCount++;
    } else {
      bCount--;
    }

    answer = min(answer, bCount + aCount);
  }
  return answer;
}
```

## 고생한 점
