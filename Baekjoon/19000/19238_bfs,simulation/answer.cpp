#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

struct Person {
  bool isEnd;
  Axis end;
};
struct Taxi {
  Axis axis;
  int fuel;
};
struct AxisDist {
  Axis axis;
  int dist;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int map[21][21];
bool visited[21][21];
vector<Person> people;
int M;
Axis limit;
Taxi taxi;

bool compare(Axis a, Axis b) {
  if (a.y == b.y) {
    return a.x < b.x;
  }
  return a.y < b.y;
}

AxisDist getClosePerson() {
  memset(visited, 0, sizeof(visited));

  if (map[taxi.axis.y][taxi.axis.x] > 0) {
    return {taxi.axis, 0};
  }
  vector<Axis> v;
  queue<AxisDist> q;
  q.push({taxi.axis, 0});
  int dist = 500;

  while (!q.empty()) {
    AxisDist cur = q.front();
    q.pop();

    if (dist <= cur.dist) continue;
    if (visited[cur.axis.y][cur.axis.x]) continue;
    visited[cur.axis.y][cur.axis.x] = true;

    for (int d = 0; d < 4; d++) {
      Axis dir = dirs[d];
      Axis next = cur.axis;
      next.x += dir.x;
      next.y += dir.y;

      if (next.y > limit.y || next.y < 1 || next.x > limit.y || next.x < 1)
        continue;
      if (map[next.y][next.x] == -1) continue;
      if (map[next.y][next.x] > 0) {
        v.push_back(next);
        dist = cur.dist + 1;
        continue;
      }
      q.push({next, cur.dist + 1});
    }
  }

  if (v.size() == 0) {
    return {-1, -1, -1};
  }

  sort(v.begin(), v.end(), compare);

  AxisDist ret = {v.front(), dist};
  v.resize(0);

  return ret;
}

int getDist(Axis from, Axis to) {
  memset(visited, 0, sizeof(visited));

  queue<AxisDist> q;
  q.push({from, 0});
  int dist = -1;

  while (!q.empty()) {
    AxisDist cur = q.front();
    q.pop();

    if (cur.axis.y == to.y && cur.axis.x == to.x) {
      return cur.dist;
    }

    if (visited[cur.axis.y][cur.axis.x]) continue;
    visited[cur.axis.y][cur.axis.x] = true;

    for (Axis dir : dirs) {
      Axis next = cur.axis;
      next.x += dir.x;
      next.y += dir.y;

      if (next.y > limit.y || next.y < 1 || next.x > limit.y || next.x < 1)
        continue;
      if (map[next.y][next.x] == -1) continue;

      q.push({next, cur.dist + 1});
    }
  }

  return dist;
}

void solution() {
  cin >> limit.y >> M >> taxi.fuel;
  limit.x = limit.y;

  for (int y = 1; y <= limit.y; y++) {
    for (int x = 1; x <= limit.x; x++) {
      cin >> map[y][x];
      map[y][x] *= -1;
    }
  }

  cin >> taxi.axis.y >> taxi.axis.x;

  people.push_back({false, {-1, -1}});
  for (int i = 1; i <= M; i++) {
    Axis start;
    Person person;
    person.isEnd = false;

    cin >> start.y >> start.x >> person.end.y >> person.end.x;

    people.push_back(person);
    map[start.y][start.x] = i;
  }

  int count = M;
  while (count > 0) {
    AxisDist target = getClosePerson();
    taxi.fuel -= target.dist;

    if (taxi.fuel <= 0 || target.dist == -1) {
      taxi.fuel = -1;
      break;
    }

    taxi.axis = target.axis;
    int index = map[target.axis.y][target.axis.x];
    Axis destination = people[index].end;
    map[target.axis.y][target.axis.x] = 0;
    people[index].isEnd = true;

    int dist = getDist(taxi.axis, destination);
    taxi.fuel -= dist;
    if (dist == -1 || 0 > taxi.fuel) {
      taxi.fuel = -1;
      break;
    }

    taxi.axis = destination;
    taxi.fuel += dist * 2;
    count -= 1;
  }

  cout << taxi.fuel << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("./data/input.txt", "r", stdin);
  solution();

  return 0;
}