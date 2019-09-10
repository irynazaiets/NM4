#define _USE_MATH_DEFINES


#include <iostream>
#include <cmath>


double u(double t) {
    double one = 1;
    //значення, отримане з програмного середовища Maple
    double u = -2 * M_PI - ((exp(-cos(t + 1)) * (-8 - 2 * M_PI)) / exp(-1));
    return u;
}

double fi(double t) {
    double result = M_PI;
    return result;
}

double psi(double t) {
    double result = 2 * sin(t + 1);
    return result;
}

double g(double t) {
    double result = -sin(t + 1);
    return result;
}

double f(double t, double y) {
    double result = fi(t) * psi(t) - g(t) * y;
    return result;
}

double max(double a, double b) {
    if (a > b) { return a; }
    else return b;
}

double min(double a, double b) {
    if (a < b) { return a; }
    else return b;
}

int main() {
    //пункт 1
    double p = 4; //порядок апроксимації
    double t0 = -1.00;
    double T = 2 * M_PI - 1;
    //double T = -0.800;

    double y0 = 8.00;
    double eps = 0.00001;
    double epsM = 0.000001;
    double tow0 = 0.50; //крок

    //пункт 2
    double t = t0; //точка
    double y = y0;
    double tow = tow0;
    double emax = 0.00;
    double one = 1.00;
    std::cout << "t= " << t << "\t" << "y= " << y << "\t" << "u= " << u(t) << "\t" << "|y-u(t)|= " << abs(y - u(t))
              << std::endl;
    //пункт 3
    p3:
    if (abs(T - t) < epsM) {
        goto p10;
    }

    //пункт 4

    if ((t + tow) > T) {
        tow = T - t;
    }

    //пункт 5
    double v = y, t1 = t;

    p6:
    double kf = 0.0;
    //пункт 6

    p7:
    double k1 = f(t, y);

    //пункт 7
    p8:
    double row2[2];
    row2[0] = 1.00 / 2.00;
    row2[1] = 1.00 / 2.00;
    double row3[3];
    row3[0] = 1.00 / 2.00;
    row3[1] = 0.00;
    row3[2] = 1.00 / 2.00;
    double row4[4];
    row4[0] = 1.00;
    row4[1] = 0.00;
    row4[2] = 0.00;
    row4[3] = 1.00;
    double row5[4];
    row5[0] = 1.00 / 6.00;
    row5[1] = 2.00 / 6.00;
    row5[2] = 2.00 / 6.00;
    row5[3] = 1.00 / 6.00;
    double k2 = f(t + row2[0], y + tow * row2[1] * k1);
    double k3 = f(t + row3[0], y + tow * row3[1] * k1 + tow * row3[2] * k2);
    double k4 = f(t + row4[0], y + tow * row4[1] * k1 + tow * row4[2] * k2 + tow * row4[3] * k3);
    //double w = 1.00;
    double w = y + tow * (row4[0] * k1 + row4[1] * k2 + row4[2] * k3 + row4[3] * k4);
    y = y + (tow / 6) * (row5[0] * k1 + row5[1] * k2 * 2 + row5[2] * k3 * 3 + row5[3] * k4);
    if (kf == 0.0) {
        w = y;
        y = v;
        tow = tow / 2;
        kf = 1;
        goto p8;
    }
    if (kf == 1.0) {
        t = t + tow;
        kf = 2;
        goto p7;

    }
    //пункт 8
    double E = (abs(y - w)) / max(1.00, abs(y));
    double towH = tow * min(5.00, max(0.10, 0.90 * pow(eps / E, 1.00 / p + 1)));

    //пункт 9
    if (E <= eps) {
        t = t + tow;
        y = y + ((y - w) / (pow(2, p) - 1));
        u(t);
        tow = towH;
        std::cout << std::endl << "t= " << t << "\ty= " << y << "\tu(t)= " << u(t) << "\t|y-u(t)|= " << abs(y - u(t));
        if (emax < abs(y - u(t))) {
            emax = abs(y - u(t));
            goto p3;
        }


    } else {
        y = v;
        t = t1;
        tow = towH;
        goto p6;
    }

    //пункт 10
    p10:
    std::cout << std::endl << "Emax= " << emax << std::endl;

    //пункт 11
    system("pause");
    return 0;

}