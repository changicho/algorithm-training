# [현대모비스][예선] Dead or Arrive

[링크](https://level.goorm.io/exam/152114/%ED%98%84%EB%8C%80%EB%AA%A8%EB%B9%84%EC%8A%A4-%EC%98%88%EC%84%A0-dead-or-arrive/quiz/1)

## 설계

### 시간 복잡도

입력받은 차량의 수를 N이라 하자.

각 차량의 속력에 대해 구분하고, 각 속력에서 가장 무게가 많이나가는 id가 큰 값을 고르면 된다.

hash map을 이용해 속력에 대해 구분하면 되므로 시간 복잡도는 O(N) 이다.

### 공간 복잡도

hash map을 사용하므로 O(N)의 공간 복잡도를 사용한다.

### hash map

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(N)     |

각 차량의 정보를 순차적으로 입력받으며 id값또한 설정한다.

이후 각 차량의 속력에 대해 묶으며 가장 무거운 차량의 id를 저장한다.

```cpp
struct Car {
  long v, w, id;
};

long long solution(vector<Car> &cars) {
  unordered_map<int, Car> um;

  for (Car &c : cars) {
    if (um.count(c.v) == 0 || um[c.v].w <= c.w) {
      um[c.v] = c;
    }
  }

  long long answer = 0;

  for (auto &it : um) {
    long key = it.first;
    Car val = it.second;

    answer += val.id;
  }

  return answer;
}
```

## 고생한 점
