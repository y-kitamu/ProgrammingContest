/*
 * alds1_5_c.cpp
 *
 * Create Date : 2019-11-17 16:25:47
 * Copyright (c) 2019 Yusuke Kitamura <ymyk6602@gmail.com>
 */

#include <iostream>
#include <cmath>

double cos_60 = std::cos(M_PI / 3);
double sin_60 = std::sin(M_PI / 3);

void koch_curve(int n, double start_x, double start_y, double end_x, double end_y) {
    //std::cout << start_x << " " << start_y << std::endl;
    if (n == 0) {
        return;
    }
    
    double grad_x = (end_x - start_x) / 3.0, grad_y = (end_y - start_y) / 3.0;
    double x_x = grad_x + start_x, x_y = grad_y + start_y;
    double u_x = x_x + grad_x * cos_60 - grad_y * sin_60,
        u_y = x_y + grad_x * sin_60 + grad_y * cos_60;
    double t_x = x_x + grad_x, t_y = x_y + grad_y;

    koch_curve(n - 1, start_x, start_y, x_x, x_y);
    std::cout << x_x << " " << x_y << std::endl;
    koch_curve(n - 1, x_x, x_y, u_x, u_y);
    std::cout << u_x << " " << u_y << std::endl;
    koch_curve(n - 1, u_x, u_y, t_x, t_y);
    std::cout << t_x << " " << t_y << std::endl;
    koch_curve(n - 1, t_x, t_y, end_x, end_y);
}


int main() {
    int n;
    std::cin >> n;

    std::cout << "0.0 0.0" << std::endl;
    koch_curve(n, 0.0, 0.0, 100.0, 0.0);
    std::cout << "100.0 0.0" << std::endl;
}
