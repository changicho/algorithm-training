# 64065. 튜플

[링크](https://programmers.co.kr/learn/courses/30/lessons/64065)

| 난이도 | 완료(명) |
| :----: | :------: |
|  lv2   |   1922   |

## 설계

### 시간복잡도

문자열 s를 파싱 하는데 N만큼의 시간이 소요된다.

s의 길이는 최대 1,000,000 이다.

정답 배열의 길이는 최대 500 이다. 이 경우 N^2로도 충분하다.

### 공간 복잡도

튜플은 원소의 갯수가 최대 500개 일 수 있다.

문자열 s를 parsing한 결과는 튜플들의 묶음인 tuples이다.

원소는 100,000까지의 자연수 이므로 int형으로 충분하다.

### 파싱

문자열의 요소를 하나하나 순회하며 parsing 한다.

닫히는 문자열 }일 때 tuples에 tuple을 push_back 한다.

마지막으로 튜플들을 size가 오름차수 순으로 정렬한다.

```cpp
vector<vector<int>> parsing(string s) {
  vector<vector<int>> tuples;
  vector<int> tuple;

  int temp = 0;
  for (char c : s) {
    switch (c) {
      case '}': {
        if (temp != 0) {
          tuple.push_back(temp);
        }
        if (tuple.size() != 0) {
          tuples.push_back(tuple);
        }

        temp = 0;
        tuple.resize(0);
      } break;
      case ',': {
        if (temp != 0) {
          tuple.push_back(temp);
        }
        temp = 0;
      } break;
      case '{': {
        temp = 0;
      } break;
      default: {
        temp = temp * 10 + (c - '0');
      }
    }
  }

  sort(tuples.begin(), tuples.end(), compare);

  return tuples;
}
```

### 정답 튜플 생성

튜플이 size순으로 오름차순 정렬되어 있을 때, 작은 크기의 tuple부터 순회하며 정답 배열에 없는 수인 경우 채워넣으면 된다.

이는 중복 원소가 없는 튜플이 주어지며, 튜플 내부의 원소의 순서가 바뀔 수 있기 때문이다.

따라서 작은 크기의 원소들 부터 채워넣어야 정답의 순서를 만들 수 있다.

- {{2}, {2, 1}, {2, 1, 3}, {2, 1, 3, 4}}
- {{2, 1, 3, 4}, {2}, {2, 1, 3}, {2, 1}}
- {{1, 2, 3}, {2, 1}, {1, 2, 4, 3}, {2}}

위 튜플들은 서로 같은 튜플을 나타낸다.

```cpp
vector<int> solution(string s) {
  vector<int> answer;
  bool check[100001] = {false};

  vector<vector<int>> tuples = parsing(s);

  for (vector<int> tuple : tuples) {
    for (int number : tuple) {
      if (!check[number]) {
        answer.push_back(number);
        check[number] = true;
      }
    }
  }

  return answer;
}
```

## 고생한 점
