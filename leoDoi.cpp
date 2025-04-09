// *bai toan dat ra:
//   cho 1 tam giac ABC, tim diem M sao cho MA + MB + MC min (chap nhan sai so epsilon 10^-3)
// *Ytuong:
//   Khi tim duoc diem tot hon diem hien tai thi nhay toi va tim kiem trong khu vuc do
//   Neu ko tim dc diem tot hon thi thu hep pham vi diem hien tai
// -----------------------------------------------------------------------------------------

#include <bits/stdc++.h>
#define diem pair<double, double>
#define x first
#define y second
using namespace std;

double kc(diem A, diem B)
{
  A.x = A.x - B.x;
  A.y = A.y - B.y;
  return sqrt(A.x * A.x + A.y * A.y);
}
int main()
{
  diem A, B, C, M;
  cout << "*bai toan dat ra:" << endl;
  cout << "  cho 1 tam giac ABC, tim diem M sao cho MA + MB + MC min (chap nhan sai so epsilon 10^-3)" << endl;
  cout << "*Ytuong:" << endl;
  cout << "  Khi tim duoc diem tot hon diem hien tai thi nhay toi va tim kiem trong khu vuc do" << endl;
  cout << "  Neu ko tim dc diem tot hon thi thu hep pham vi diem hien tai" << endl;
  cout << "-------------------------------------------------------------------------------------" << endl;
  cout << "Khoi tao diem A: ";
  cin >> A.x >> A.y;
  cout << "Khoi tao diem B: ";
  cin >> B.x >> B.y;
  cout << "Khoi tao diem C: ";
  cin >> C.x >> C.y;
  M = diem((A.x + B.x + C.x) / 3, (A.y + B.y + C.y) / 3);
  double eps = 1e-3;
  double k = kc(A, M) + kc(B, M) + kc(C, M);
  double d = 10;
  while (d > eps)
  {
    diem next[] = {diem(M.x + d, M.y), diem(M.x - d, M.y), diem(M.x, M.y + d), diem(M.x, M.y - d)};
    for (diem i : next)
    {
      double z = kc(i, A) + kc(i, B) + kc(i, C);
      if (z < k)
      {
        k = z;
        M = i;
        d = d * 2;
        break;
      }
    }
    d = d / 2;
  }
  cout << k;
}
