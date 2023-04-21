#include <stdio.h>  // printf, scanf
#include <math.h>   // sqrt, pow
#include <conio.h>  // getch
#include <string.h> // strlen, strcmp, strcpy, strcat, strupr, strlwr, strrev, stricmp, strnicmp, strchr, strrchr, strstr, strtok
#define sl 100
struct Date
{
  int ngay;
  int thang;
  int nam;
};
typedef Date date;

struct NhanVien
{
  int msnv;
  char ho[20];
  char ten[20];
  date namsinh;
  char noisinh[100];
  char diachi[200];
  float luong;
  date ngayvao;
};
typedef NhanVien nhanvien;

struct DanhSach
{
  nhanvien a[sl];
  int n;
};
typedef DanhSach danhsach;
// khai bao ham
void menu();
void nhapngaythang(date &ntn);
void nhap1nv(danhsach ds, nhanvien &nv);
void xuat1nv(nhanvien nv);
void xuatngaythang(date ntn);
void nhapdanhsach(danhsach &ds);
void xuatdanhsach(danhsach ds);
int timten(danhsach ds, char *c);
void themnv(danhsach &ds, nhanvien x, int k);
int timMSNV(danhsach ds, int d);
void xoanv(danhsach &ds, int d);
void sapxep(danhsach &ds);
void nhapdanhsach(danhsach &ds)
{
  do
  {
    printf("\nNhap so luong nhan vien: ");
    scanf("%d", &ds.n);
    if (ds.n < 0 || ds.n > sl)
    {
      printf("So luong nhan vien khong hop le, vui long nhap lai!\n");
    }
  } while (ds.n < 0 || ds.n > sl);
  for (int i = 0; i < ds.n; i++)
  {
    printf("\nNhap thong tin cho nhan vien thu %d:\n", i + 1);
    nhap1nv(ds, ds.a[i]);
  }
}

void nhapngaythang(date &ntn)
{
  do
  {
    printf("\nNhap ngay: ");
    scanf("%d", &ntn.ngay);
    if (ntn.ngay < 1 || ntn.ngay > 31)
    {
      printf("Ngay khong hop le, vui long nhap lai!\n");
    }
  } while (ntn.ngay < 1 || ntn.ngay > 31);
  do
  {
    printf("\nNhap thang: ");
    scanf("%d", &ntn.thang);
    if (ntn.thang < 1 || ntn.thang > 12)
    {
      printf("Thang khong hop le, vui long nhap lai!\n");
    }
  } while (ntn.thang < 1 || ntn.thang > 12);
  do
  {
    printf("\nNhap nam: ");
    scanf("%d", &ntn.nam);
    if (ntn.nam < 1900 || ntn.nam > 10000)
    {
      printf("Nam khong hop le, vui long nhap lai!\n");
    }
  } while (ntn.nam < 1900 || ntn.nam > 10000);
}

void xuatdanhsach(danhsach ds)
{
  printf("\nDanh sach nhan vien:");
  printf("\n%5s %20s %20s %20s %20s %20s %20s %20s",
         "MSNV", "Ho", "Ten", "Ngay sinh", "Noi sinh", "Dia chi", "Luong", "Ngay vao");
  for (int i = 0; i < ds.n; i++)
  {
    printf("\n%5d %20s %20s ", ds.a[i].msnv, ds.a[i].ho, ds.a[i].ten);
    xuatngaythang(ds.a[i].namsinh);
    printf("%20s %20s %15.2f ", ds.a[i].noisinh, ds.a[i].diachi, ds.a[i].luong);
    printf("\t");
    xuatngaythang(ds.a[i].ngayvao);
  }
}

void nhap1nv(danhsach ds, nhanvien &nv)
{
  do
  {
    printf("\nNhap ma so nhan vien: ");
    scanf("%d", &nv.msnv);
    if (timMSNV(ds, nv.msnv) != -1)
    {
      printf("Ma so nhan vien da ton tai, vui long nhap lai!\n");
    }
  } while (timMSNV(ds, nv.msnv) != -1);
  fflush(stdin);
  printf("\nNhap ho nhan vien: ");
  gets(nv.ho);
  printf("\nNhap ten nhan vien: ");
  gets(nv.ten);
  printf("\nNhap nam sinh: ");
  nhapngaythang(nv.namsinh);
  fflush(stdin);
  printf("\nNhap noi sinh: ");
  gets(nv.noisinh);
  printf("\nNhap dia chi: ");
  gets(nv.diachi);
  printf("\nNhap luong: ");
  scanf("%f", &nv.luong);
  fflush(stdin);
  printf("\nNhap ngay vao lam: ");
  nhapngaythang(nv.ngayvao);
}

void xuat1nv(nhanvien nv)
{
  printf("\n%5s %20s %20s %20s %20s %20s %15s %15s",
         "MSNV", "Ho", "Ten", "Ngay sinh", "Noi sinh", "Dia chi", "Luong", "Ngay vao");
  printf("\n%5d %20s %20s ", nv.msnv, nv.ho, nv.ten);
  xuatngaythang(nv.namsinh);
  printf("%20s %20s %15.2f ", nv.noisinh, nv.diachi, nv.luong);
  xuatngaythang(nv.ngayvao);
}

void xuatngaythang(date ntn)
{
  printf("\t%d/%d/%d", ntn.ngay, ntn.thang, ntn.nam);
}
int timten(danhsach ds, char *c)
{
  for (int i = 0; i < ds.n; i++)
  {
    if (strcasecmp(ds.a[i].ten, c) == 0)
    {
      return i;
    }
  }
  printf("Khong tim thay nhan vien co ten %s trong danh sach!\n", c);
  return -1;
}

int timMSNV(danhsach ds, int d)
{
  for (int i = 0; i < ds.n; i++)
  {
    if (ds.a[i].msnv == d)
    {
      return i;
    }
  }
  return -1;
}

void xoanv(danhsach &ds, int d)
{
  int i = timMSNV(ds, d);
  if (i == -1)
  {
    printf("Khong tim thay nhan vien co ma so %d de xoa.\n", d);
    return;
  }
  for (int j = i; j < ds.n - 1; j++)
  {
    ds.a[j] = ds.a[j + 1];
  }
  ds.n--;
  printf("Da xoa nhan vien co ma so %d.\n", d);
}
void sapxep(danhsach &ds)
{
  int i, j;
  for (i = 0; i < ds.n - 1; i++)
  {
    for (j = 0; j < ds.n - i - 1; j++)
    {
      if (ds.a[j + 1].luong > ds.a[j].luong)
      {
        nhanvien temp = ds.a[j];
        ds.a[j] = ds.a[j + 1];
        ds.a[j + 1] = temp;
      }
    }
  }
}
void themnv(danhsach &ds, nhanvien x, int k)
{
  while (k < 0 || k > ds.n)
  {
    printf("\nVi tri khong hop le, vui long nhap lai!");
    printf("\nNhap vi tri can them: ");
    scanf("%d", &k);
  }
  if (ds.n >= sl)
  {
    printf("\nDanh sach day!");
    return;
  }
  for (int i = ds.n - 1; i >= k; i--)
  {
    ds.a[i + 1] = ds.a[i];
  }
  ds.a[k] = x;
  ds.n++;
  printf("\nThem thanh cong!");
}

void menu()
{
  printf("\n\t\t+++++++++++++++++++++++++++++++CHUONG TRINH QUAN LY NHAN VIEN+++++++++++++++++++++++++++++++");
  printf("\n\t");
  int ch;
  int d, k;
  danhsach ds;
  nhanvien x;
  nhapdanhsach(ds);
  xuatdanhsach(ds);
  do
  {
    printf("\n\t\t+++++++++++++++++++++++++++++++MENU+++++++++++++++++++++++++++++++");
    printf("\n\t1.Them vao 1 nhan vien");
    printf("\n\t2.Tim nhan vien theo ma so");
    printf("\n\t3.Tim nhan vien thoe ten");
    printf("\n\t4.Bang luong cua nhan vien giam dan");
    printf("\n\t5.Xoa 1 nhan vien");
    printf("\n\t0.Thoat chuong trinh");
    printf("\n\t\t+++++++++++++++++++++++++++++++END+++++++++++++++++++++++++++++++");
    printf("\n\tChon 1 trong chuc nang tren: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("\nNhap thong tin nhan vien can them: ");
      nhap1nv(ds, x);
      printf("\nNhap vi tri can them: ");
      scanf("%d", &k);
      themnv(ds, x, k);
      printf("\nDanh sach sau khi them:");
      xuatdanhsach(ds);
      break;
    case 2:
      printf("\nNhap ma so nhan vien can tim: ");
      scanf("%d", &d);
      k = timMSNV(ds, d);
      if (k == -1)
      {
        printf("\nKhong tim thay nhan vien co ma so %d", d);
      }
      else
      {
        printf("\nThong tin nhan vien can tim: ");
        xuat1nv(ds.a[k]);
      }
      break;
    case 3:
      printf("\nNhap ten nhan vien can tim: ");
      char ten[30];
      fflush(stdin);
      gets(ten);
      k = timten(ds, ten);
      if (k == -1)
      {
        printf("\nKhong tim thay nhan vien co ma so %d", d);
      }
      else
      {
        printf("\nThong tin nhan vien can tim: ");
        xuat1nv(ds.a[k]);
      }
      break;
    case 4:
      printf("\nDanh sach sau khi sap xep theo bang luong giam dan:");
      sapxep(ds);
      xuatdanhsach(ds);
      break;
    case 5:
      printf("\nNhap ma so nhan vien can xoa: ");
      scanf("%d", &d);
      xoanv(ds, d);
      printf("\nDanh sach sau khi xoa:");
      xuatdanhsach(ds);
      break;
    case 0:
      printf("\nChuong trinh da thoat!");
      break;
    default:
      printf("\nChuc nang khong ton tai!");
      break;
    }
  } while (ch != 0);
}
int main()
{
  menu();
  getch();
  return 0;
}
