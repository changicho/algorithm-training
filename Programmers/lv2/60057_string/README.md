# 60057. 문자열 압축

[링크](https://programmers.co.kr/learn/courses/30/lessons/60057)

| 난이도 | 완료(명) |
| :----: | :------: |
|  lv2   |   3411   |

## 설계

### 시간복잡도

문자열을 제일 첫번째 길이부터 잘라야 한다. 따라서 문제는 문자열을 단위 n으로 자르고, 연속적으로 같은 부분 문자열이 나오면 이를 압축하는 문제이다.

문자열의 길이 s의 길이는 최대 1,000 이다.

부분 문자열의 길이는 1부터 최대 500까지 가능하다. (절반으로 자르는 것이 균등하게 자를 때 최대)

문자열을 자를때는 문자열 전체를 한번 순회하며, 각 부분 문자열로 만들 수 있는 갯수만큼 반복한다.

따라서 최악의 시간복잡도는 O(500,000) 이다.

### split 함수

문자열을 자르는 것을 구현하기 위해 split 함수를 생성한다.

```cpp
vector<string> split(string s, int n) {
  vector<string> ret;
  string temp = "";

  for (char c : s) {
    temp += c;

    if (temp.length() >= n) {
      ret.push_back(temp);
      temp = "";
    }
  }

  if (temp != "") {
    ret.push_back(temp);
  }
  return ret;
}
```

이 때 맨 마지막 단어를 넣는것을 잊지 않아야 한다.

### 압축의 방법

현재 부분문자열과 이전 부분문자열을 비교해 같은경우와 다른경우에 분기처리한다.

- 같은경우 : count를 1 증가시킴
- 다른경우 : count.length + 부분문자열 길이만큼 정답을 증가시키고, count를 초기화함

맨 마지막 부분문자열까지 순회가 끝났을 때 count에 따라 분기처리를 수행한다

- count가 초기화된 값 : 맨 마지막 부분문자열 길이만큼 정답을 증가
- count가 초기화된 값이 아님 : count.length + 부분문자열 길이만큼 정답을 증가

이때 count는 int형이고, 문자열로 변환했을때 length만큼 정답을 증가시키는 것에유의한다.

```cpp
int count = 1;

for (int i = 1; i < parts.size(); i++) {
  if (parts[i - 1] == parts[i]) {
    count += 1;
    continue;
  }

  if (count == 1) {
    cur_answer += parts[i - 1].length();
  } else {
    cur_answer += to_string(count).length() + parts[i - 1].length();
  }
  count = 1;
}

// 맨 마지막 예외처리
if (count == 1) {
  cur_answer += parts.back().length();
} else {
  cur_answer += to_string(count).length() + parts.back().length();
}
```

## 고생한 점

문제를 이해하는것이 어려웠다.
