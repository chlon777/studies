#include <stdio.h>
#include <stdlib.h>

void menuMacierzy2x2();
void wczytajMacierz2x2(double A[2][2], double B[2][2]);
void wyswietlMacierz2x2(double M[2][2]);
void suma2x2(double A[2][2], double B[2][2], double wynik[2][2]);
void iloczyn2x2(double A[2][2], double B[2][2], double wynik[2][2]);
double wyznacznik2x2(double M[2][2]);
int odwrotnosc2x2(double M[2][2], double wynik[2][2]);

void menuMacierzy3x3();
void wczytajMacierz3x3(double A[3][3], double B[3][3]);
void wyswietlMacierz3x3(double M[3][3]);
void suma3x3(double A[3][3], double B[3][3], double wynik[3][3]);
void iloczyn3x3(double A[3][3], double B[3][3], double wynik[3][3]);
double wyznacznik3x3(double M[3][3]);
int odwrotnosc3x3(double M[3][3], double wynik[3][3]);

void wyswietlMenu();

int main() {
    int wybor;

    while (1) {
        wyswietlMenu();
        printf("Wybierz opcje: ");
        scanf("%d", &wybor);

        switch (wybor) {
            case 1:
                menuMacierzy2x2();
                break;
            case 2:
                menuMacierzy3x3();
                break;
            case 3:
                printf("Koniec programu.\n");
                exit(0);
            default:
                printf("Niepoprawny wybor. Sprobuj ponownie.\n");
        }
    }

    return 0;
}

void wyswietlMenu() {
    printf("\nMenu glowne:\n");
    printf("1. Tryb macierzy 2x2\n");
    printf("2. Tryb macierzy 3x3\n");
    printf("3. Zakoncz program\n");
}

void menuMacierzy2x2() {
    double A[2][2], B[2][2];
    double wynik[2][2];
    int danePodane = 0;
    int wybor;

    while (1) {
        printf("\nTryb macierzy 2x2:\n");
        printf("1. Podaj dane macierzy\n");
        printf("2. Suma A + B\n");
        printf("3. Iloczyn A * B\n");
        printf("4. Odwrotnosc A^-1 oraz B^-1\n");
        printf("5. Powrot do menu glownego\n");
        printf("Wybierz opcje: ");
        scanf("%d", &wybor);

        switch (wybor) {
            case 1:
                wczytajMacierz2x2(A, B);
                danePodane = 1;
                break;
            case 2:
                if (!danePodane) {
                    printf("Najpierw podaj dane macierzy.\n");
                } else {
                    suma2x2(A, B, wynik);
                    printf("Suma A + B:\n");
                    wyswietlMacierz2x2(wynik);
                }
                break;
            case 3:
                if (!danePodane) {
                    printf("Najpierw podaj dane macierzy.\n");
                } else {
                    iloczyn2x2(A, B, wynik);
                    printf("Iloczyn A * B:\n");
                    wyswietlMacierz2x2(wynik);
                }
                break;
            case 4:
                if (!danePodane) {
                    printf("Najpierw podaj dane macierzy.\n");
                } else {
                    printf("Odwrotnosc macierzy A:\n");
                    if (odwrotnosc2x2(A, wynik)) {
                        wyswietlMacierz2x2(wynik);
                    } else {
                        printf("Macierz A nie ma odwrotnosci (wyznacznik = 0).\n");
                    }
                    printf("Odwrotnosc macierzy B:\n");
                    if (odwrotnosc2x2(B, wynik)) {
                        wyswietlMacierz2x2(wynik);
                    } else {
                        printf("Macierz B nie ma odwrotnosci (wyznacznik = 0).\n");
                    }
                }
                break;
            case 5:
                return;
            default:
                printf("Niepoprawny wybor. Sprobuj ponownie.\n");
        }
    }
}

void wczytajMacierz2x2(double A[2][2], double B[2][2]) {
    printf("Podaj elementy macierzy A (2x2):\n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("A[%d][%d]: ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }
    printf("Podaj elementy macierzy B (2x2):\n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("B[%d][%d]: ", i, j);
            scanf("%lf", &B[i][j]);
        }
    }
}

void wyswietlMacierz2x2(double M[2][2]) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%6.2lf ", M[i][j]);
        }
        printf("\n");
    }
}

void suma2x2(double A[2][2], double B[2][2], double wynik[2][2]) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            wynik[i][j] = A[i][j] + B[i][j];
        }
    }
}

void iloczyn2x2(double A[2][2], double B[2][2], double wynik[2][2]) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            wynik[i][j] = A[i][0] * B[0][j] + A[i][1] * B[1][j];
        }
    }
}

double wyznacznik2x2(double M[2][2]) {
    return M[0][0] * M[1][1] - M[0][1] * M[1][0];
}

int odwrotnosc2x2(double M[2][2], double wynik[2][2]) {
    double det = wyznacznik2x2(M);
    if (det == 0) return 0;

    wynik[0][0] = M[1][1] / det;
    wynik[0][1] = -M[0][1] / det;
    wynik[1][0] = -M[1][0] / det;
    wynik[1][1] = M[0][0] / det;
    return 1;
}

void menuMacierzy3x3() {
    double A[3][3], B[3][3];
    double wynik[3][3];
    int danePodane = 0;
    int wybor;

    while (1) {
        printf("\nTryb macierzy 3x3:\n");
        printf("1. Podaj dane macierzy\n");
        printf("2. Suma A + B\n");
        printf("3. Iloczyn A * B\n");
        printf("4. Odwrotnosc A^-1 oraz B^-1\n");
        printf("5. Powrot do menu glownego\n");
        printf("Wybierz opcje: ");
        scanf("%d", &wybor);

        switch (wybor) {
            case 1:
                wczytajMacierz3x3(A, B);
                danePodane = 1;
                break;
            case 2:
                if (!danePodane) {
                    printf("Najpierw podaj dane macierzy.\n");
                } else {
                    suma3x3(A, B, wynik);
                    printf("Suma A + B:\n");
                    wyswietlMacierz3x3(wynik);
                }
                break;
            case 3:
                if (!danePodane) {
                    printf("Najpierw podaj dane macierzy.\n");
                } else {
                    iloczyn3x3(A, B, wynik);
                    printf("Iloczyn A * B:\n");
                    wyswietlMacierz3x3(wynik);
                }
                break;
            case 4:
                if (!danePodane) {
                    printf("Najpierw podaj dane macierzy.\n");
                } else {
                    printf("Odwrotnosc macierzy A:\n");
                    if (odwrotnosc3x3(A, wynik)) {
                        wyswietlMacierz3x3(wynik);
                    } else {
                        printf("Macierz A nie ma odwrotnosci (wyznacznik = 0).\n");
                    }
                    printf("Odwrotnosc macierzy B:\n");
                    if (odwrotnosc3x3(B, wynik)) {
                        wyswietlMacierz3x3(wynik);
                    } else {
                        printf("Macierz B nie ma odwrotnosci (wyznacznik = 0).\n");
                    }
                }
                break;
            case 5:
                return;
            default:
                printf("Niepoprawny wybor. Sprobuj ponownie.\n");
        }
    }
}

void wczytajMacierz3x3(double A[3][3], double B[3][3]) {
    printf("Podaj elementy macierzy A (3x3):\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("A[%d][%d]: ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }
    printf("Podaj elementy macierzy B (3x3):\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("B[%d][%d]: ", i, j);
            scanf("%lf", &B[i][j]);
        }
    }
}

void wyswietlMacierz3x3(double M[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%6.2lf ", M[i][j]);
        }
        printf("\n");
    }
}

void suma3x3(double A[3][3], double B[3][3], double wynik[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            wynik[i][j] = A[i][j] + B[i][j];
        }
    }
}

void iloczyn3x3(double A[3][3], double B[3][3], double wynik[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            wynik[i][j] = 0;
            for (int k = 0; k < 3; ++k) {
                wynik[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

double wyznacznik3x3(double M[3][3]) {
    return M[0][0] * (M[1][1] * M[2][2] - M[1][2] * M[2][1]) -
           M[0][1] * (M[1][0] * M[2][2] - M[1][2] * M[2][0]) +
           M[0][2] * (M[1][0] * M[2][1] - M[1][1] * M[2][0]);
}

int odwrotnosc3x3(double M[3][3], double wynik[3][3]) {
    double det = wyznacznik3x3(M);
    if (det == 0) return 0;

    wynik[0][0] = (M[1][1] * M[2][2] - M[1][2] * M[2][1]) / det;
    wynik[0][1] = (M[0][2] * M[2][1] - M[0][1] * M[2][2]) / det;
    wynik[0][2] = (M[0][1] * M[1][2] - M[0][2] * M[1][1]) / det;
    wynik[1][0] = (M[1][2] * M[2][0] - M[1][0] * M[2][2]) / det;
    wynik[1][1] = (M[0][0] * M[2][2] - M[0][2] * M[2][0]) / det;
    wynik[1][2] = (M[1][0] * M[0][2] - M[0][0] * M[1][2]) / det;
    wynik[2][0] = (M[1][0] * M[2][1] - M[2][0] * M[1][1]) / det;
    wynik[2][1] = (M[2][0] * M[0][1] - M[0][0] * M[2][1]) / det;
    wynik[2][2] = (M[0][0] * M[1][1] - M[1][0] * M[0][1]) / det;

    return 1;
}
