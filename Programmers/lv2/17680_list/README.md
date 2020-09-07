# 17680. [1차] 캐시

[링크](https://programmers.co.kr/learn/courses/30/lessons/17680)

| 난이도 | 완료(명) |
| :----: | :------: |
|  lv2   |   2964   |

## 설계

### 시간복잡도

최대 도시의 수는 100,000개이다.

캐시의 최대 크기는 30 이므로,

모든 도시에 대해 캐시를 직접 탐색한다 하더라도 시간복잡도는 3,000,000 이다.

따라서 제한시간 1초 내에 충분하다.

### 공간 복잡도

문자열이 들어오므로 string vector를 이용한다.

### C++ vector를 이용한 LRU

vector의 iter를 사용해 LRU 캐시를 만들 수 있다.

다음과 같은 메소드를 사용한다.

- erase : 특정 위치 원소 제거
- insert : 특정 위치 원소 삽입
- pop_back : 맨 뒤의 원소 제거

```cpp
for (string city : cities) {
  // 캐시에 저장되어있는지 확인
  auto it = find(LRU.begin(), LRU.end(), city);

  // 캐시에 해당 정보가 있으면
  if (it != LRU.end()) {
    answer += 1;

    // 삭제
    LRU.erase(it);
  } else {
    answer += 5;
  }

  // 새로 캐시에 추가
  LRU.insert(LRU.begin(), city);
  // 캐시의 최대 크기를 벗어난 경우 맨 뒤의 원소 삭제
  if (cacheSize < LRU.size()) {
    LRU.pop_back();
  }
}
```

## 고생한 점

g++ 에서 vector.erase(vector.end()) 부분에서 segmentation fault가 발생했다.

이를 해결하기 위해 pop_back() 메소드를 사용
