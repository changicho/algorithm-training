# 2024. Maximize the Confusion of an Exam

[링크](https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

answerKey의 길이를 N이라 하자. (N <= 5 \* 10^4)

연속된 같은 특정 길이를 만족하는 subString을 찾는데 O(N)의 시간 복잡도가 소요된다. 이를 이용해 특정 길이를 이분탐색을 수행한다면 O(N \* log_2(N))의 시간 복잡도를 사용한다.

슬라이딩 윈도우를 이용해 특정 길이를 만족하는 subString을 찾는 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

T와 F의 길이를 저장할 공간이 필요하다. 이에 O(1)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      99      |    O(N)     |    O(1)     |

최대 K개의 정답을 뒤집어 연속된 같은 subString을 만들 수 있다.

여기서 정답의 종류는 T, F 두 가지 밖에 존재하지 않는다.

따라서 슬라이딩 윈도우를 이용해 T혹은 F중 가장 갯수가 작은 것을 모두 뒤집어 연속된 subString을 만들 수 있다.

이 때 갯수가 작은 것이 K개 이하여야 한다.

이를 이용해 슬라이딩 윈도우를 증가시키며, 둘 중 작은것의 갯수가 K 이하이면 right를 증가시키고, 그 외의 경우는 left를 증가시킨다.

이를 반복하며 최대 길이의 정답을 갱신한다.

```cpp
int maxConsecutiveAnswers(string answerKey, int k) {
  int size = answerKey.size();

  int answer = 0;
  unordered_map<char, int> count;

  for (int right = 0, left = 0; right < size; right++) {
    count[answerKey[right]]++;

    while (min(count['T'], count['F']) > k && left < right) {
      count[answerKey[left]]--;
      left++;
    }

    answer = max(answer, right - left + 1);
  }

  return answer;
}
```

## 고생한 점
