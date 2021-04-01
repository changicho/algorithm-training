# 3. Longest Substring Without Repeating Characters

[링크](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이는 최대 5 \* 10^4 이다.

가능한 모든 sub 문자열을 탐색할 경우 start, end index를 변경해가며 탐색하므로 시간 복잡도는 O(N^2)이다.

이는 제한시간 내에 아슬아슬하다.

투 포인터를 이용할 경우 현재 end_index에서 만들 수 있는 가장 짧은 sub 문자열만 탐색할 수 있다.

이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

문자열의 문자 종류는 영문, 숫자, 공백, 그리고 특수문자이다.

특정문자가 이전에 사용되었는지 체크하기 위해 테이블(배열) 혹은 set 형태의 자료 구조를 이용할 수 있다.

문자열의 문자 종류가 ASCII 코드표로 전부 나타낼 수 있으므로 array를 이용한다.

### sub string

문제에서 요구하는 sub string은 다음과 같다.

- 0 ~ (s.length - 1) 범위인 start_index, end_index가 있다. (start_index <= end_index)
- sub_string은 기존 string에서 start_index ~ end_index 까지의 문자열이다.
- sub_string의 문자들은 서로 중복되지 않는다.

### 투 포인터

> 4ms

start index와 end index를 이용한다.

현재 end index에서 만들 수 있는 가장 작은 sub 문자열을 탐색하며, 이 때 이전에 만들어 놓은 sub 문자열을 이용할 수 있다.

현재 문자가 이전에 사용되지 않은 경우 sub문자열에 추가한다.

만약 이전에 사용된 문자인 경우, 현재 문자가 나타나지 않을 때 까지 sub문자열의 start index를 증가시킨다.

매 경우마다 sub 문자열을 만들 수 있으므로 정답을 갱신한다.

```cpp
int lengthOfLongestSubstring(string s) {
  int count = 0;
  int temp_count = 0;
  bool visited[128] = {
      false,
  };

  for (int start = 0, end = 0; end < s.length(); end++) {
    char cur = s[end];
    while (visited[cur] && start < end) {
      char target = s[start];
      start += 1;
      if (visited[target]) {
        visited[target] = false;
        temp_count -= 1;
      }
    }

    visited[cur] = true;
    temp_count += 1;

    if (count < temp_count) {
      count = temp_count;
    }
  }

  return count;
}
```

### table을 이용

> 4ms

투 포인터를 응용해서 다음과 같은 table을 이용하자

- key : 문자
- value : 해당 문자를 포함한 subString이 끝나는 위치

그리고 시작점 start와 끝점 end을 이용한다.

현재 문자가 이전에 사용된 문자인 경우 해당 문자가 이전에 사용된 index 이후부터 시작해야한다.

따라서 start를 해당 위치까지 옮겨준다. (이때 start가 해당 위치보다 큰 경우 기존 start를 유지한다.)

```cpp
int lengthOfLongestSubstring(string s) {
  int myMap[128] = {
      0,
  };

  int res = 0;
  int start = 0;
  for (int end = 0; end < s.size(); end++) {
    if (myMap[s[end]] != 0) {
      start = max(start, myMap[s[end]]);
    }
    myMap[s[end]] = end + 1;

    res = max(res, end - start + 1 );
  }

  return res;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      4       |

## 고생한 점
