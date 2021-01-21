#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct Wspolczynniki {
    int a, b, c;
};

struct MiejscaZerowe {
    double x1, x2;
};

struct Punkt {
    double x, y;
};

struct FunkcjaKwadratowa {
    struct Wspolczynniki wspolczynniki;
    int delta;
    struct MiejscaZerowe miejscaZerowe;
    struct Punkt wierzcholek;
};

struct FunkcjaKwadratowa *WczytajDane();

void PoliczDelte(struct FunkcjaKwadratowa *funkcjaKwadratowa);

void WyznaczMiejscaZerowe(struct FunkcjaKwadratowa *funkcjaKwadratowa);

void WyznaczWierzcholek(struct FunkcjaKwadratowa *funkcjaKwadratowa);

void wypiszDane(struct FunkcjaKwadratowa *funkcjaKwadratowa);


int main() {
    struct FunkcjaKwadratowa *mojaFunkcjaKwadratowa = WczytajDane();
    PoliczDelte(mojaFunkcjaKwadratowa);
    WyznaczMiejscaZerowe(mojaFunkcjaKwadratowa);
    WyznaczWierzcholek(mojaFunkcjaKwadratowa);
    wypiszDane(mojaFunkcjaKwadratowa);
    return 0;
}

struct FunkcjaKwadratowa *WczytajDane() {
    struct FunkcjaKwadratowa *funkcjaKwadratowa = (struct FunkcjaKwadratowa *) malloc(
            sizeof(struct FunkcjaKwadratowa));
    scanf("%d %d %d", &(funkcjaKwadratowa->wspolczynniki.a), &(funkcjaKwadratowa->wspolczynniki.b),
          &(funkcjaKwadratowa->wspolczynniki.c));
    return funkcjaKwadratowa;
}

void PoliczDelte(struct FunkcjaKwadratowa *funkcjaKwadratowa) {
    funkcjaKwadratowa->delta = funkcjaKwadratowa->wspolczynniki.b * funkcjaKwadratowa->wspolczynniki.b -
                               4 * funkcjaKwadratowa->wspolczynniki.a * funkcjaKwadratowa->wspolczynniki.c;
}

void WyznaczMiejscaZerowe(struct FunkcjaKwadratowa *funkcjaKwadratowa) {
    double pierwiastekDelta;
    pierwiastekDelta = sqrt((double) funkcjaKwadratowa->delta);
    if (funkcjaKwadratowa->delta > 0) {
        funkcjaKwadratowa->miejscaZerowe.x1 = (funkcjaKwadratowa->wspolczynniki.b * (-1) - pierwiastekDelta) /
                                              (2 * funkcjaKwadratowa->wspolczynniki.a);
        funkcjaKwadratowa->miejscaZerowe.x2 = (funkcjaKwadratowa->wspolczynniki.b * (-1) + pierwiastekDelta) /
                                              (2 * funkcjaKwadratowa->wspolczynniki.a);
    } else if (funkcjaKwadratowa->delta == 0) {
        funkcjaKwadratowa->miejscaZerowe.x1 =
                funkcjaKwadratowa->wspolczynniki.b * (-1) / (2 * funkcjaKwadratowa->wspolczynniki.a);
        funkcjaKwadratowa->miejscaZerowe.x2 =
                funkcjaKwadratowa->wspolczynniki.b * (-1) / (2 * funkcjaKwadratowa->wspolczynniki.a);
    }
}


void WyznaczWierzcholek(struct FunkcjaKwadratowa *funkcjaKwadratowa) {
    funkcjaKwadratowa->wierzcholek.x = funkcjaKwadratowa->wspolczynniki.b * (-1) / (double)(2 * funkcjaKwadratowa->wspolczynniki.a);
    funkcjaKwadratowa->wierzcholek.y = funkcjaKwadratowa->delta * (-1) / (double)(4 * funkcjaKwadratowa->wspolczynniki.a);
}

void wypiszDane(struct FunkcjaKwadratowa *funkcjaKwadratowa) {
    printf("\n f(x) = %dx^2 + %dx + %d ", funkcjaKwadratowa->wspolczynniki.a, funkcjaKwadratowa->wspolczynniki.b, funkcjaKwadratowa->wspolczynniki.c);
    printf("\n delta = %d", funkcjaKwadratowa->delta);
    if (funkcjaKwadratowa->delta > 0) {
        printf("\n Miejsca Zerowe = %.3f;%.3f", funkcjaKwadratowa->miejscaZerowe.x1, funkcjaKwadratowa->miejscaZerowe.x2);
    } else if (funkcjaKwadratowa->delta == 0) {
        printf("\n Miejsce Zerowe = %.3f;", funkcjaKwadratowa->miejscaZerowe.x1);
    } else {
        printf("\n Brak miejsc zerowych");
    }
    printf("\n Wierzcholek = (%.5f ; %.5f)", funkcjaKwadratowa->wierzcholek.x, funkcjaKwadratowa->wierzcholek.y);
}






