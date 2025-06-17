#include <iostream>
#include <iomanip>
#include "cDaGiac.h"
#include <cmath>
#define M_PI 3.14159265358979323846

int main() {
    cDaGiac dg;
    std::cout << "Nhap da giac:\n";
    dg.Nhap();

    if (dg.KiemTraThangHang()) {
        std::cout << "Tat ca cac dinh da giac thang hang! Khong phai la da giac hop le.\n";
        return 1;
    }

    std::cout << "\nToa do cac dinh da giac: ";
    dg.Xuat();

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Chu vi: " << dg.ChuVi() << std::endl;
    std::cout << "Dien tich: " << dg.DienTich() << std::endl;

    double dx = 2, dy = 3;
    dg.TinhTien(dx, dy);
    std::cout << "\nSau khi tinh tien (" << dx << ", " << dy << "): ";
    dg.Xuat();

    dg.Quay(M_PI / 2, DIEM(0, 0));
    std::cout << "Sau khi quay 90 do quanh goc toa do: ";
    dg.Xuat();

    dg.PhongToThuNho(2, DIEM(0, 0));
    std::cout << "Sau khi phong to ty le 2 quanh goc toa do: ";
    dg.Xuat();

    return 0;
}