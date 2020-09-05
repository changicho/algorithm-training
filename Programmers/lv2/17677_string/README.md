# 17677. [1차] 뉴스 클러스터링

[링크](https://programmers.co.kr/learn/courses/30/lessons/17677)

| 난이도 | 완료(명) |
| :----: | :------: |
|  lv2   |   2940   |

## 설계

### 시간 복잡도

최악의 경우 하나의 문자열에서 만들 수 있는 부분 문자열은 999개이다.

부분 문자열을 만들 때 들어가는 시간 복잡도 N

교집합을 만들 때 시간 복잡도는 NlogN으로 가능하다.

따라서 최악의 경우도 시간 복잡도는 NlogN이므로 제한 시간 내에 충분하다.

### 공간 복잡도

자료구조로 map을 이용한다.

(부분 문자열, 갯수) 를 나타내야 하므로 자료구조의 형태는

```cpp
map<string, int>
```

정답의 범위는 65,536,000이내 이므로 int형으로 선언한다.

### 문자열 parsing

문자열을 순회하며 2글자의 부분 문자열을 만든다.

이때 문자열이 유효한 경우에만 map에 insert한다.

```cpp
map<string, int> parse(string str) {
  map<string, int> result;

  for (int i = 0; i < str.length() - 1; i++) {
    string temp = "";
    temp += tolower(str[i]);
    temp += tolower(str[i + 1]);

    // 전부 영어 소문자인지 비교
    if (isFine(temp)) {
      result[temp] += 1;
    }
  }

  return result;
}
```

### 교집합의 원소의 수 파악

하나의 map을 순회하며, 다른 map에 자신의 key가 있는 경우 value를 감소시킨다.

이 때, 현재 key의 value가 여러 개인 경우 반복문을 통해 반복한다.

```cpp
for (auto it = first.begin(); it != first.end(); it++) {
  // 현재 원소의 개수만큼 반복
  for (int i = 0; i < it->second; i++) {
    if (second[it->first] > 0) {
      same += 1;
      second[it->first] -= 1;
    }
  }
}
```

## 고생한 점
