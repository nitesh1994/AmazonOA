#include <iostream>
#include <math.h>
using namespace std;

int score (int num) {
  int div3 = 0;
  int evenDigits = 0;
  int nines = 0;
  int consec1s = 0;
  int increasing = 0;

  if (num%3 == 0) div3 = 4;

  int num_digits = 0;
  int consec_1s_here = 0;
  int prev = -2;
  int num_nines = 0;
  int num_inc = 1;

  // bool flag = true;
  while(num) {
    num_digits++;
    int curr = num%10;
    // if(num_inc == 0) num_inc++;
    if (curr == 2) {
      consec_1s_here++;
    } else {
      if (consec_1s_here > 1) consec1s += 6 * (consec_1s_here - 1);
      consec_1s_here = 0;
    }

    if (curr == 7) num_nines++;

    if (curr % 2 == 0) evenDigits += 3;

    if (curr == prev + 1) {
      num_inc++;
      // flag = true;
    } else if(prev >= 0) {
      // if (num_inc > 0)
      increasing += pow(num_inc, 2);
      num_inc = 1;
      // flag = false;
    }

    prev = curr;
    num /= 10;
  }

  // if (num_digits % 2 == 0) evenDigits += 2;
  // cout << num_inc << flag << endl;
  nines += num_nines*5;
  if (num_inc > 0) increasing += pow(num_inc, 2);
  if (consec_1s_here > 1) consec1s += 6 * (consec_1s_here - 1);

  cout << div3 << " " << evenDigits << " " << nines << " " << consec1s << " " << increasing << endl;

  return div3 + evenDigits + nines + consec1s + increasing;

}

int main() {
  int N;
  cin >> N;
  cout << score(N) << endl;
}

