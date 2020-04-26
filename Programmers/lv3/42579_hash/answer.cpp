#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct song {
  int index, play;
};

struct genre {
  string genre;
  int count;
  vector<song> songs;
};

bool compare_genre(genre a, genre b) { return a.count > b.count; }

bool compare_song(song a, song b) { return a.play > b.play; }

vector<int> solution(vector<string> genres, vector<int> plays) {
  vector<int> answer;

  map<string, genre> m;

  for (string s : genres) {
    genre g;
    vector<song> songs;

    g.genre = s;
    g.count = 0;
    g.songs = songs;
    m[s] = g;
  }

  for (int i = 0; i < plays.size(); i++) {
    m[genres[i]].count += plays[i];
    m[genres[i]].songs.push_back({i, plays[i]});
  }

  vector<genre> g_order;

  for (auto it = m.begin(); it != m.end(); it++) {
    genre temp;
    temp.genre = it->first;
    temp.count = it->second.count;

    g_order.push_back(temp);
  }

  sort(g_order.begin(), g_order.end(), compare_genre);

  for (genre g : g_order) {
    vector<song> s = m[g.genre].songs;
    sort(s.begin(), s.end(), compare_song);

    answer.push_back(s[0].index);
    if (s.size() >= 2) {
      answer.push_back(s[1].index);
    }
  }

  return answer;
}