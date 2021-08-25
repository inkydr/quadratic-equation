#include <stdio.h>
#include <math.h>

const int SS_INF_ROOTS = -1;

int SolveLinear(double b, double c,    // линейное уравнение
                double* x1) {
    if (b == 0) {
        if (c == 0) {
            return SS_INF_ROOTS;
        }
        else {
            return 0;
        }
    }
    else {
        *x1 = -c / b;
        return 1;
    }

}
int SolveSquare(double a, double b, double c,   // квадратное уравнение
                double* x1, double* x2) {

    double D = b * b - 4 * a * c;

    if (D == 0) {
        *x1 = -b / (2 * a);
        return 1;
    }
    else {
        double sqrtD = sqrt(D);
        *x1 = (-b + sqrtD) / (2 * a);
        *x2 = (-b - sqrtD) / (2 * a);
        return 2;
    }
}

int Solver(double a, double b, double c,
           double* x1, double* x2) {
    if (a == 0) {
        return SolveLinear(b, c, x1);
    }
    else {
        return SolveSquare(a, b, c, x1, x2);
    }
}

int main() {
    double a = 0, b = 0, c = 0;
    printf("Введите коэфы a, b, c. (через пробел)\n");
    scanf("%lg %lg %lg", &a, &b, &c);

    double x1 = 0, x2 = 0;
    int nRoots = Solver(a, b, c, &x1, &x2);

    switch(nRoots) {
        case 0:
            printf("Нет корней.\n");
            break;

        case 1:
            printf("x = %lg\n", x1);
            break;

        case 2:
            printf("x1 = %lg, x2 = % lg\n", x1, x2);
            break;

        case SS_INF_ROOTS:
            printf("Любое число");
            break;

        default:
            printf("main() : ERROR: nRoots = %d\n", nRoots);
    }

    return 0;
}

