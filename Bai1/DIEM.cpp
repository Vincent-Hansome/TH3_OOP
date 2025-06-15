#include "DIEM.h"

DIEM::DIEM(double x, double y) : x(x), y(y) {}

double DIEM::getX() const { return x; }
double DIEM::getY() const { return y; }
void DIEM::setX(double x) { this->x = x; }
void DIEM::setY(double y) { this->y = y; }

void DIEM::Nhap() {
    std::cout << "Nhap x y: ";
    std::cin >> x >> y;
}

void DIEM::Xuat() const {
    std::cout << "(" << x << ", " << y << ")";
}

double DIEM::KhoangCach(const DIEM& d) const {
    return std::sqrt((x - d.x) * (x - d.x) + (y - d.y) * (y - d.y));
}

void DIEM::TinhTien(double dx, double dy) {
    x += dx;
    y += dy;
}

void DIEM::Quay(double goc, const DIEM& tam) {
    double x_new = tam.x + (x - tam.x) * cos(goc) - (y - tam.y) * sin(goc);
    double y_new = tam.y + (x - tam.x) * sin(goc) + (y - tam.y) * cos(goc);
    x = x_new;
    y = y_new;
}

void DIEM::PhongToThuNho(double tyLe, const DIEM& tam) {
    x = tam.x + tyLe * (x - tam.x);
    y = tam.y + tyLe * (y - tam.y);
}