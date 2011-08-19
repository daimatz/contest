#include <iostream>
using namespace std;

int dist2(int a[3], int b[3]) {
  return ((a[0]-b[0]) * (a[0]-b[0])
          + (a[1]-b[1]) * (a[1]-b[1])
          + (a[2]-b[2]) * (a[2]-b[2]));
}

int main(int argc, char *argv[]) {
  int input[3];
  int color[16][3];
  int i;
  int d2;
  for (i = 0; i < 16; i++) {
    cin >> color[i][0] >> color[i][1] >> color[i][2];
  }
  while (1) {
    int min = 255*255+255*255+255*255+1;
    int min_i[3];
    cin >> input[0] >> input[1] >> input[2];
    if (input[0] == -1 && input[1] == -1 && input[2] == -1)
      return 0;
    for (i = 0; i < 16; i++) {
      d2 = dist2(color[i], input);
      if (min > d2) {
        for (int j = 0; j < 3; j++)
          min_i[j] = color[i][j];
        min = d2;
      }
    }
    cout << "(" << input[0] << "," << input[1] << "," << input[2]
         << ") maps to ("   << min_i[0] << "," << min_i[1]
         << "," << min_i[2] << ")" << endl;
  }
  return 0;
}
