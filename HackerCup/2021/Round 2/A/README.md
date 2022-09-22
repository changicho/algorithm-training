# Problem A: Runway

[링크](https://www.facebook.com/codingcompetitions/hacker-cup/2021/round-2/problems/A)

| 난이도 |
| :----: |
| 12 pt  |

## 설계

### 시간 복잡도

입력받은 쇼의 수를 N, 인원의 수를 M이라 하자.

그리디 알고리즘을 이용해 옷을 변경할 때 가장 적합한 인원을 배정한다.

이 때 각 경우마다 정렬을 이용해 가장 적합한 인원을 배정할 수 있다.

이 경우 한 쇼마다 인원에 대해 정렬하므로 O(M \* log_2(M))의 시간 복잡도를 사용한다.

이를 모든 쇼마다 반복하므로 O(N \* M \* log_2(M))의 시간 복잡도를 사용한다.

### 공간 복잡도

각 쇼마다 변경해야할 color를 체크하는데 O(M)의 공간 복잡도를 사용한다.

각 모델별로 현재 상황을 저장하기 위해 O(M)의 공간 복잡도를 사용한다.

### 그리디 알고리즘

|      시간 복잡도      | 공간 복잡도 |
| :-------------------: | :---------: |
| O(N \* M \* log_2(M)) |    O(M)     |

현재 모델들과, 각 쇼에 대해서 다음과 같이 생각할 수 있다.

현재 입은 옷과 같은 옷을 입고있는 인원들은 옷을 갈아입을 필요가 없다.

옷을 갈아입을 필요가 있는 모델들은 옷을 갈아입힌다.

만약 같은 옷을 입고있는 모델이 존재할 경우 그 중 덜 옷을 갈아입은 인원부터 옷을 갈아입힌다.

이는 옷을 갈아입는 횟수를 한번씩 차감 가능하기 때문이다.

이를 이용해 각 쇼마다 옷을 갈아입을 필요가 없는 모델들을 구하고, 해당 인원들 중 우선순위가 높은 인원들만 옷을 갈아입히지 않는다.

이를 구현하면 다음과 같다.

```cpp
struct Model {
  int color, changeCount;

  bool operator<(const Model &b) const {
    if (color != b.color) {
      return color < b.color;
    }
    return changeCount > b.changeCount;
  }
};

int solution(int n, int m, vector<int> &s, vector<vector<int>> &p) {
  vector<Model> models(m);
  for (int i = 0; i < m; i++) {
    int color = s[i];
    models[i].color = color;
    models[i].changeCount = 0;
  }

  for (int i = 0; i < n; i++) {
    sort(models.begin(), models.end());

    unordered_map<int, int> colorCount;
    for (int &num : p[i]) {
      colorCount[num]++;
    }

    vector<int> unusedModelIdx;

    for (int i = 0; i < m; i++) {
      Model &model = models[i];
      if (colorCount.count(model.color) > 0) {
        colorCount[model.color]--;
        if (colorCount[model.color] == 0) {
          colorCount.erase(model.color);
        }
        continue;
      }

      unusedModelIdx.push_back(i);
    }

    for (int &idx : unusedModelIdx) {
      int color = colorCount.begin()->first;
      models[idx].color = color;
      models[idx].changeCount++;

      colorCount[color]--;
      if (colorCount[color] == 0) {
        colorCount.erase(color);
      }
    }
  }

  int answer = 0;
  for (Model &model : models) {
    answer += max(model.changeCount - 1, 0);
  }
  return answer;
}
```

## 고생한 점
