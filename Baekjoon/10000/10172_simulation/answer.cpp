#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  vector<string> v;

  v.push_back("|\\_/|");
  v.push_back("|q p|   /}");
  v.push_back("( 0 )\"\"\"\\");
  v.push_back("|\"^\"`    |");
  v.push_back("||_/=\\\\__|");

  for (string s : v) {
    cout << s << "\n";
  }
}