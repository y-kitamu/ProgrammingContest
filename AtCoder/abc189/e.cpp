#include <bits/stdc++.h>


struct Matrix {
    Matrix() {
        mat = std::vector<std::vector<long long int>>(2, std::vector<long long int>(3));
        mat[0][0] = 1;
        mat[0][1] = 0;
        mat[0][2] = 0;
        mat[1][0] = 0;
        mat[1][1] = 1;
        mat[1][2] = 0;
    }

    std::vector<std::vector<long long int>> mat;

    std::vector<long long int> translate(std::vector<long long int> pt) {
        std::vector transed{
            mat[0][0] * pt[0] + mat[0][1] * pt[1] + mat[0][2],
            mat[1][0] * pt[0] + mat[1][1] * pt[1] + mat[1][2],
        };
        return transed;
    }

    Matrix rotate1() {
        Matrix rot;
        rot.mat[0][0] = mat[1][0];
        rot.mat[0][1] = mat[1][1];
        rot.mat[0][2] = mat[1][2];
        rot.mat[1][0] = -mat[0][0];
        rot.mat[1][1] = -mat[0][1];
        rot.mat[1][2] = -mat[0][2];
        return rot;
    }

    Matrix rotate2() {
        Matrix rot;
        rot.mat[0][0] = -mat[1][0];
        rot.mat[0][1] = -mat[1][1];
        rot.mat[0][2] = -mat[1][2];
        rot.mat[1][0] = mat[0][0];
        rot.mat[1][1] = mat[0][1];
        rot.mat[1][2] = mat[0][2];
        return rot;
    }

    Matrix flip_horizontal(long long int x) {
        Matrix flip = *this;
        flip.mat[0][2] -= x;
        flip.mat[0][0] *= -1;
        flip.mat[0][1] *= -1;
        flip.mat[0][2] *= -1;
        flip.mat[0][2] += x;
        return flip;
    }

    Matrix flip_vertical(long long int y) {
        Matrix flip = *this;
        flip.mat[1][2] -= y;
        flip.mat[1][0] *= -1;
        flip.mat[1][1] *= -1;
        flip.mat[1][2] *= -1;
        flip.mat[1][2] += y;
        return flip;
    }
};


int main() {
    long long int N;
    std::cin >> N;

    std::vector<std::vector<long long int>> pts(N, std::vector<long long int>(2));
    for (int i = 0; i < N; i++) {
        std::cin >> pts[i][0] >> pts[i][1];
    }

    int M;
    std::cin >> M;

    std::vector<Matrix> mats(M + 1);
    for (int i = 1; i <= M; i++) {
        int cmd;
        std::cin >> cmd;
        if (cmd == 1) {
            mats[i] = mats[i - 1].rotate1();
        } else if (cmd == 2) {
            mats[i] = mats[i - 1].rotate2();
        } else {
            int val;
            std::cin >> val;
            if (cmd == 3) {
                mats[i] = mats[i - 1].flip_horizontal(val);
            } else {
                mats[i] = mats[i - 1].flip_vertical(val);
            }
        }
    }

    int Q;
    std::cin >> Q;

    for (int i = 0; i < Q; i++) {
        int a, b;
        std::cin >> a >> b;
        b--;
        std::vector<long long int> pt = mats[a].translate(pts[b]);
        std::cout << pt[0] << " " << pt[1] << std::endl;
    }
}
