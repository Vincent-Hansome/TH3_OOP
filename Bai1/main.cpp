#include <iostream>
#include <iomanip>
#include "cTamGiac.h"
#include "DIEM.h"
#include <cmath>
#define M_PI 3.14159265358979323846

int main() {
    cTamGiac tg;
    std::cout << "Nhap tam giac:\n";
    tg.Nhap();

    std::cout << "\nToa do cac dinh tam giac: ";
    tg.Xuat();

    if (!tg.LaTamGiac()) {
        std::cout << "Khong phai la tam giac hop le.\n";
        return 1;
    }

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Chu vi: " << tg.ChuVi() << std::endl;
    std::cout << "Dien tich: " << tg.DienTich() << std::endl;

    if (tg.LaTamGiacDeu())
        std::cout << "Day la tam giac deu.\n";
    else if (tg.LaTamGiacCan())
        std::cout << "Day la tam giac can.\n";
    else if (tg.LaTamGiacVuong())
        std::cout << "Day la tam giac vuong.\n";
    else
        std::cout << "Day la tam giac thuong.\n";

    double dx = 2, dy = 3;
    tg.TinhTien(dx, dy);
    std::cout << "\nSau khi tinh tien (" << dx << ", " << dy << "): ";
    tg.Xuat();
    tg.Quay(M_PI / 2, DIEM(0, 0));
    std::cout << "Sau khi quay 90 do quanh goc toa do: ";
    tg.Xuat();
    tg.PhongToThuNho(2, DIEM(0, 0));
    std::cout << "Sau khi phong to ty le 2 quanh goc toa do: ";
    tg.Xuat();

    return 0;
}