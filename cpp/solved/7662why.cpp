#include <map>
#include <stdio.h>
#include <iterator>
std::map<int, int> M;
int last = 0, t, q, n, i, j;
char c;
void del_max() {
  auto i = M.rbegin();
  if (i->second == 1) {
    M.erase(i->first);
  } else {
    M[i->first]--;
  }
  last--;
}
void del_min() {
  auto i = M.begin();
  if (i->second == 1) {
    M.erase(i->first);
  } else {
    M[i->first]--;
  }
  last--;
}
void put(int a) {
  if (M.find(a) != M.end()) {
    M[a]++;
  } else {
    M[a] = 1;
  }
  last++;
}
int get_min() {
  auto i = M.begin();
  return i->first;
}
int get_max() {
  auto i = M.rbegin();
  return i->first;
}
int main() {
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    M.clear();
    last = 0;
    scanf("%d", &n);
    for (j = 0; j < n; j++) {
      scanf(" %c %d", &c, &q);
      if (c == 'I') {
        put(q);
      } else if (c == 'D') {
        if (last <= 0)
          continue;
        if (q == -1) {
          del_min();
        } else if (q == 1) {
          del_max();
        }
      }
    }
    if (last <= 0) {
      printf("EMPTY\n");
      continue;
    }
    printf("%d %d\n", get_max(), get_min());
  }
}