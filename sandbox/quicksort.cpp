#include <cstdio>
#include <string>

using namespace std;

bool check(char c1, char c2) {
  printf("? %c %c\n", c1, c2);
  fflush(stdout);
  char ans;
  scanf(" %c", &ans);
  if(ans == '>') return true;
  return false;
}

int partition (string s, int l, int r) {
    int pivot = s[r];
    int i = (l - 1);

    for (int j = l; j <= r - 1; j++) {
        if (check(s[j], pivot)) {
            i++;
            swap(s[i], s[j]);
        }
    }
    swap(s[i + 1], s[r]);
    return (i + 1);
}

void quickSort(string s, int l, int r) {
    if (l < r) {
        int pivot = partition(s, l, r);
        quickSort(s, l, pivot - 1);
        quickSort(s, pivot + 1, r);
    }
}

int main(void){
  int N,Q,i,j;

  scanf("%d%d", &N, &Q);

  string s;
  for(i=0;i<N;i++) s += (char)('A' + i);

  quickSort(s, 0, sizeof(s) - 1);

  printf("! %s\n", s.c_str());
  fflush(stdout);

  return 0;
}
