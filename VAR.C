#define ABS(x)  ((x) >> 31 ^ (x) - ((unsigned)(x) >> 31))

#define V0(i)   (&y0)[i]
#define V1(i)  ((&y0)[i] + (B[0][i]                     << z))
#define V2(i)  ((&y0)[i] + (          B[1][i]           << z))
#define V3(i)  ((&y0)[i] + (B[0][i] + B[1][i]           << z))
#define V4(i)  ((&y0)[i] + (                    B[2][i] << z))
#define V5(i)  ((&y0)[i] + (B[0][i]           + B[2][i] << z))
#define V6(i)  ((&y0)[i] + (          B[1][i] + B[2][i] << z))
#define V7(i)  ((&y0)[i] + (B[0][i] + B[1][i] + B[2][i] << z))

#define Z   16
#define J   1 << Z - 1
int N = 3 << Z;

#define L(i)    (&L0)[i << 2]
#define U(i)    (&U0)[i << 2]
#define R(i)    (&R0)[i << 2]
#define D(i)    (&D0)[i << 2]

#define L8(i, j)    M(L(i), L(j))
#define U8(i, j)    M(U(i), U(j))
#define R8(i, j)    M(R(i), R(j))
#define D8(i, j)    M(D(i), D(j))

#define F(i, j) (&L0)[(i << 2) + (j)]
#define RJ(x, y)    if ((y = NU(L8 >> Z, x, R8 >> Z, D8 >> Z)) < 0) return

#define B(j)    (i << 30 >> 31 ^ V##j(i & 0x1)) < (i << 30 >> 31 ^ F(j, i) + (F(j, i + 2 & 0x3) - F(j, i) >> k))

void M3D2D(int L0, int U0, int R0, int D0, int L1, int U1, int R1, int D1, int L2, int U2, int R2, int D2, int L3, int U3, int R3, int D3, int L4, int U4, int R4, int D4, int L5, int U5, int R5, int D5, int L6, int U6, int R6, int D6, int L7, int U7, int R7, int D7, int L8, int U8, int R8, int D8, unsigned x0, unsigned x1, unsigned x2, int y0, int y1, int y2, int z, unsigned O[], int t)
{
    int i, j, k;

    for (i = 4; i--;)
        for (k = 1; ABS(F(8, i + 2 & 0x3) - F(8, i) >> k) >= J;)
            if (B(0) || B(1) || B(2) || B(4) || B(3) || B(5) || B(6) || B(7))
                k++;
            else {
                F(8, i) += F(8, i + 2 & 0x3) - F(8, i) >> k;
                RJ((j = U8 >> Z) + (j - t >> 31 & t - j), t);
                for (j = 8; j--; F(j, i) += F(j, i + 2 & 0x3) - F(j, i) >> k);
            }
    if (R8 - L8 <= N || D8 - U8 <= N || !z) {
        if (y2 >= 0)
            RC(L8 >> Z, t, R8 >> Z, D8 >> Z, O[0] << 8 & 0xff0000 | O[0] >> 8 & 0xff00 | O[0] & 0xff);
    } else
        for (i = 7, j = x2 >> 31 << 2 | x1 >> 31 << 1 | x0 >> 31, k = i ^ j; i >= 0; i--, k = i ^ j)
            if (O[0] & 1 << k + 24) {
                M3D2D(L8(k, 0), U8(k, 0), R8(k, 0), D8(k, 0), L8(k, 1), U8(k, 1), R8(k, 1), D8(k, 1), L8(k, 2), U8(k, 2), R8(k, 2), D8(k, 2), L8(k, 3), U8(k, 3), R8(k, 3), D8(k, 3), L8(k, 4), U8(k, 4), R8(k, 4), D8(k, 4), L8(k, 5), U8(k, 5), R8(k, 5), D8(k, 5), L8(k, 6), U8(k, 6), R8(k, 6), D8(k, 6), L8(k, 7), U8(k, 7), R8(k, 7), D8(k, 7), L8, U8, R8, D8, x0 + (1 - (k << 1 & 0x2) << 6 + z), x1 + (1 - (k & 0x2) << 6 + z), x2 + (1 - (k >> 1 & 0x2) << 6 + z), y0 + ((k << 31 >> 31 & B[0][0]) + (k << 30 >> 31 & B[1][0]) + (k << 29 >> 31 & B[2][0]) << z - 1), y1 + ((k << 31 >> 31 & B[0][1]) + (k << 30 >> 31 & B[1][1]) + (k << 29 >> 31 & B[2][1]) << z - 1), y2 + ((k << 31 >> 31 & B[0][2]) + (k << 30 >> 31 & B[1][2]) + (k << 29 >> 31 & B[2][2]) << z - 1), z - 1, O[1] + (rk[O[0] >> 24 & (1 << k) - 1] << 3), t);
                RJ(t, t);
            }
}

#define J   1 << Z
#define B(j)    ((-(i >> 1) ^ V##j(i & 0x1)) >= (-(i >> 1) ^ F(j, i)) + (D[j] >> 1))
#define C() B(0) && B(1) && B(2) && B(4) && B(3) && B(5) && B(6) && B(7)

void M3D2D(int L0, int U0, int R0, int D0, int L1, int U1, int R1, int D1, int L2, int U2, int R2, int D2, int L3, int U3, int R3, int D3, int L4, int U4, int R4, int D4, int L5, int U5, int R5, int D5, int L6, int U6, int R6, int D6, int L7, int U7, int R7, int D7, int L8, int U8, int R8, int D8, unsigned x0, unsigned x1, unsigned x2, int y0, int y1, int y2, int z, unsigned O[], int t)
{
    int i, j, k, D[9];

    for (i = 4; i--;) {
        for (j = 9; j--; D[j] = F(j, (i & 0x1) + 2) - F(j, i & 0x1));
        for (; D[8] >= J;) {
            if (C()) {
                F(8, i) += (-(i >> 1) ^ D[8] >> 1) + (i >> 1);
                RJ((j = U8 >> Z) + (j - t >> 31 & t - j), t);
                for (D[j = 8]++; j--; F(j, i) += (-(i >> 1) ^ D[j]++ >> 1) + (i >> 1));
            }
            for (j = 9; j--; D[j] >>= 1);
        }
    }
    if (R8 - L8 < N || D8 - U8 < N || !z) {
        if (y2 >= 0)
            RC(L8 >> Z, t, R8 >> Z, D8 >> Z, O[0] << 8 & 0xff0000 | O[0] >> 8 & 0xff00 | O[0] & 0xff);
    } else
        for (i = 7, j = x2 >> 31 << 2 | x1 >> 31 << 1 | x0 >> 31, k = i ^ j; i >= 0; k = --i ^ j)
            if (O[0] & 1 << k + 24) {
                M3D2D(L8(k, 0), U8(k, 0), R8(k, 0), D8(k, 0), L8(k, 1), U8(k, 1), R8(k, 1), D8(k, 1), L8(k, 2), U8(k, 2), R8(k, 2), D8(k, 2), L8(k, 3), U8(k, 3), R8(k, 3), D8(k, 3), L8(k, 4), U8(k, 4), R8(k, 4), D8(k, 4), L8(k, 5), U8(k, 5), R8(k, 5), D8(k, 5), L8(k, 6), U8(k, 6), R8(k, 6), D8(k, 6), L8(k, 7), U8(k, 7), R8(k, 7), D8(k, 7), L8, U8, R8, D8, x0 + (1 - (k << 1 & 0x2) << 6 + z), x1 + (1 - (k & 0x2) << 6 + z), x2 + (1 - (k >> 1 & 0x2) << 6 + z), y0 + ((k << 31 >> 31 & B[0][0]) + (k << 30 >> 31 & B[1][0]) + (k << 29 >> 31 & B[2][0]) << z - 1), y1 + ((k << 31 >> 31 & B[0][1]) + (k << 30 >> 31 & B[1][1]) + (k << 29 >> 31 & B[2][1]) << z - 1), y2 + ((k << 31 >> 31 & B[0][2]) + (k << 30 >> 31 & B[1][2]) + (k << 29 >> 31 & B[2][2]) << z - 1), z - 1, O[1] + (rk[O[0] >> 24 & (1 << k) - 1] << 3), t);
                RJ(t, t);
            }
}

#define B(x, y) (i << 30 >> 31 ^ V##x(i & 0x1)) < (i << 30 >> 31 ^ F(x, i) + (y))

void M3D2D(int L0, int U0, int R0, int D0, int L1, int U1, int R1, int D1, int L2, int U2, int R2, int D2, int L3, int U3, int R3, int D3, int L4, int U4, int R4, int D4, int L5, int U5, int R5, int D5, int L6, int U6, int R6, int D6, int L7, int U7, int R7, int D7, int L8, int U8, int R8, int D8, unsigned x0, unsigned x1, unsigned x2, int y0, int y1, int y2, int z, unsigned O[], int t)
{
    if (V0(2) >= 0 || V1(2) >= 0 || V2(2) >= 0 || V4(2) >= 0 || V3(2) >= 0 || V5(2) >= 0 || V6(2) >= 0 || V7(2) >= 0) {
        int i, j, k;

        for (i = 4; i--;)
            if (!(B(0, 0) || B(1, 0) || B(2, 0) || B(4, 0) || B(3, 0) || B(5, 0) || B(6, 0) || B(7, 0)))
                for (k = 1; ABS(F(8, i + 2 & 0x3) - F(8, i) >> k) >= J;)
                    if (B(0, F(0, i + 2 & 0x3) - F(0, i) >> k) || B(1, F(1, i + 2 & 0x3) - F(1, i) >> k) || B(2, F(2, i + 2 & 0x3) - F(2, i) >> k) || B(4, F(4, i + 2 & 0x3) - F(4, i) >> k) || B(3, F(3, i + 2 & 0x3) - F(3, i) >> k) || B(5, F(5, i + 2 & 0x3) - F(5, i) >> k) || B(6, F(6, i + 2 & 0x3) - F(6, i) >> k) || B(7, F(7, i + 2 & 0x3) - F(7, i) >> k))
                        k++;
                    else {
                        F(8, i) += F(8, i + 2 & 0x3) - F(8, i) >> k;
                        RJ((j = U8 >> Z) + (j - t >> 31 & t - j), t);
                        for (j = 8; j--; F(j, i) += F(j, i + 2 & 0x3) - F(j, i) >> k);
                    }
        if (R8 - L8 <= N || D8 - U8 <= N || !z)
            RC(L8 >> Z, t, R8 >> Z, D8 >> Z, O[0] << 8 & 0xff0000 | O[0] >> 8 & 0xff00 | O[0] & 0xff);
        else
            for (i = 7, j = x2 >> 31 << 2 | x1 >> 31 << 1 | x0 >> 31, k = i ^ j; i >= 0; i--, k = i ^ j)
                if (O[0] & 1 << k + 24) {
                    M3D2D(L8(k, 0), U8(k, 0), R8(k, 0), D8(k, 0), L8(k, 1), U8(k, 1), R8(k, 1), D8(k, 1), L8(k, 2), U8(k, 2), R8(k, 2), D8(k, 2), L8(k, 3), U8(k, 3), R8(k, 3), D8(k, 3), L8(k, 4), U8(k, 4), R8(k, 4), D8(k, 4), L8(k, 5), U8(k, 5), R8(k, 5), D8(k, 5), L8(k, 6), U8(k, 6), R8(k, 6), D8(k, 6), L8(k, 7), U8(k, 7), R8(k, 7), D8(k, 7), L8, U8, R8, D8, x0 + (1 - (k << 1 & 0x2) << 6 + z), x1 + (1 - (k & 0x2) << 6 + z), x2 + (1 - (k >> 1 & 0x2) << 6 + z), y0 + ((k << 31 >> 31 & B[0][0]) + (k << 30 >> 31 & B[1][0]) + (k << 29 >> 31 & B[2][0]) << z - 1), y1 + ((k << 31 >> 31 & B[0][1]) + (k << 30 >> 31 & B[1][1]) + (k << 29 >> 31 & B[2][1]) << z - 1), y2 + ((k << 31 >> 31 & B[0][2]) + (k << 30 >> 31 & B[1][2]) + (k << 29 >> 31 & B[2][2]) << z - 1), z - 1, O[1] + (rk[O[0] >> 24 & (1 << k) - 1] << 3), t);
                    RJ(t, t);
                }
    }
}

#define V(i, j) ((&y0)[j] + ((i << 31 >> 31 & B[0][j]) + (i << 30 >> 31 & B[1][j]) + (i << 29 >> 31 & B[2][j]) << z))
#define B(j)    (i << 30 >> 31 ^ V(j, i & 0x1)) < (i << 30 >> 31 ^ F(j, i) + (G[j] >> 1))

void M3D2D(int L0, int U0, int R0, int D0, int L1, int U1, int R1, int D1, int L2, int U2, int R2, int D2, int L3, int U3, int R3, int D3, int L4, int U4, int R4, int D4, int L5, int U5, int R5, int D5, int L6, int U6, int R6, int D6, int L7, int U7, int R7, int D7, int L8, int U8, int R8, int D8, unsigned x0, unsigned x1, unsigned x2, int y0, int y1, int y2, int z, unsigned O[], int t)
{
    int i, j, k, G[9];

    for (i = 4; i--;) {
        for (j = 9; j--; G[j] = F(j, i + 2 & 0x3) - F(j, i));
        for (k = 7; ABS(G[8] >> 1) >= J;) {
            for (j = k; j >= 0; j--)
                if (B(j)) { k = j; goto L0; }
            F(8, i) += G[8] >> 1;
            RJ((j = U8 >> Z) + (j - t >> 31 & t - j), t);
            for (G[j = 8]++; j--; F(j, i) += G[j]++ >> 1);
L0:;
            for (j = 9; j--; G[j] >>= 1);
        }
    }
    if (R8 - L8 <= N || D8 - U8 <= N || !z) {
        if (y2 >= 0)
            RC(L8 >> Z, t, R8 >> Z, D8 >> Z, O[0] << 8 & 0xff0000 | O[0] >> 8 & 0xff00 | O[0] & 0xff);
    } else
        for (i = 7, j = x2 >> 31 << 2 | x1 >> 31 << 1 | x0 >> 31, k = i ^ j; i >= 0; i--, k = i ^ j)
            if (O[0] & 1 << k + 24) {
                M3D2D(L8(k, 0), U8(k, 0), R8(k, 0), D8(k, 0), L8(k, 1), U8(k, 1), R8(k, 1), D8(k, 1), L8(k, 2), U8(k, 2), R8(k, 2), D8(k, 2), L8(k, 3), U8(k, 3), R8(k, 3), D8(k, 3), L8(k, 4), U8(k, 4), R8(k, 4), D8(k, 4), L8(k, 5), U8(k, 5), R8(k, 5), D8(k, 5), L8(k, 6), U8(k, 6), R8(k, 6), D8(k, 6), L8(k, 7), U8(k, 7), R8(k, 7), D8(k, 7), L8, U8, R8, D8, x0 + (1 - (k << 1 & 0x2) << 6 + z), x1 + (1 - (k & 0x2) << 6 + z), x2 + (1 - (k >> 1 & 0x2) << 6 + z), y0 + ((k << 31 >> 31 & B[0][0]) + (k << 30 >> 31 & B[1][0]) + (k << 29 >> 31 & B[2][0]) << z - 1), y1 + ((k << 31 >> 31 & B[0][1]) + (k << 30 >> 31 & B[1][1]) + (k << 29 >> 31 & B[2][1]) << z - 1), y2 + ((k << 31 >> 31 & B[0][2]) + (k << 30 >> 31 & B[1][2]) + (k << 29 >> 31 & B[2][2]) << z - 1), z - 1, O[1] + (rk[O[0] >> 24 & (1 << k) - 1] << 3), t);
                RJ(t, t);
            }
}

#define B(j)    ((-(i >> 1) ^ V(j, i & 0x1)) < (-(i >> 1) ^ F(j, i)) + (F(j, (i & 0x1) + 2) - F(j, i & 0x1) >> k[1]))

void M3D2D(int L0, int U0, int R0, int D0, int L1, int U1, int R1, int D1, int L2, int U2, int R2, int D2, int L3, int U3, int R3, int D3, int L4, int U4, int R4, int D4, int L5, int U5, int R5, int D5, int L6, int U6, int R6, int D6, int L7, int U7, int R7, int D7, int L8, int U8, int R8, int D8, unsigned x0, unsigned x1, unsigned x2, int y0, int y1, int y2, int z, unsigned O[], int t)
{
    int i, j, k[2];

    for (i = 4; i--;)
        for (k[0] = 0, k[1] = 1, j = F(8, (i & 0x1) + 2) - F(8, i & 0x1); j >> k[1] >= J;)
            if (k[0] < 8)
                k[B(k[0])]++;
            else {
                F(8, i) += (-(i >> 1) ^ F(8, (i & 0x1) + 2) - F(8, i & 0x1) >> k[1]) + (i >> 1);
                RJ((j = U8 >> Z) + (j - t >> 31 & t - j), t);
                for (k[0] = 0, j = 8; j--; F(j, i) += (-(i >> 1) ^ F(j, (i & 0x1) + 2) - F(j, i & 0x1) >> k[1]) + (i >> 1));
                j = F(8, (i & 0x1) + 2) - F(8, i & 0x1);
            }
    if (R8 - L8 < N || D8 - U8 < N || !z) {
        if (y2 >= 0)
            RC(L8 >> Z, t, R8 >> Z, D8 >> Z, O[0] << 8 & 0xff0000 | O[0] >> 8 & 0xff00 | O[0] & 0xff);
    } else
        for (i = 7, k[0] = x2 >> 31 << 2 | x1 >> 31 << 1 | x0 >> 31, j = i ^ k[0]; i >= 0; i--, j = i ^ k[0])
            if (O[0] & 1 << j + 24) {
                M3D2D(L8(j, 0), U8(j, 0), R8(j, 0), D8(j, 0), L8(j, 1), U8(j, 1), R8(j, 1), D8(j, 1), L8(j, 2), U8(j, 2), R8(j, 2), D8(j, 2), L8(j, 3), U8(j, 3), R8(j, 3), D8(j, 3), L8(j, 4), U8(j, 4), R8(j, 4), D8(j, 4), L8(j, 5), U8(j, 5), R8(j, 5), D8(j, 5), L8(j, 6), U8(j, 6), R8(j, 6), D8(j, 6), L8(j, 7), U8(j, 7), R8(j, 7), D8(j, 7), L8, U8, R8, D8, x0 + (1 - (j << 1 & 0x2) << 6 + z), x1 + (1 - (j & 0x2) << 6 + z), x2 + (1 - (j >> 1 & 0x2) << 6 + z), y0 + ((j << 31 >> 31 & B[0][0]) + (j << 30 >> 31 & B[1][0]) + (j << 29 >> 31 & B[2][0]) << z - 1), y1 + ((j << 31 >> 31 & B[0][1]) + (j << 30 >> 31 & B[1][1]) + (j << 29 >> 31 & B[2][1]) << z - 1), y2 + ((j << 31 >> 31 & B[0][2]) + (j << 30 >> 31 & B[1][2]) + (j << 29 >> 31 & B[2][2]) << z - 1), z - 1, O[1] + (rk[O[0] >> 24 & (1 << j) - 1] << 3), t);
                RJ(t, t);
            }
}

void M3D2D(int L0, int U0, int R0, int D0, int L1, int U1, int R1, int D1, int L2, int U2, int R2, int D2, int L3, int U3, int R3, int D3, int L4, int U4, int R4, int D4, int L5, int U5, int R5, int D5, int L6, int U6, int R6, int D6, int L7, int U7, int R7, int D7, int L8, int U8, int R8, int D8, unsigned x0, unsigned x1, unsigned x2, int y0, int y1, int y2, int z, unsigned O[], int t)
{
    int i, j, k;

    for (i = 4; i--;)
        for (k = 1, j = F(8, (i & 0x1) + 2) - F(8, i & 0x1); j >> k >= J;)
            if (B(0) || B(1) || B(2) || B(4) || B(3) || B(5) || B(6) || B(7))
                k++;
            else {
                F(8, i) += (-(i >> 1) ^ F(8, (i & 0x1) + 2) - F(8, i & 0x1) >> k) + (i >> 1);
                RJ((j = U8 >> Z) + (j - t >> 31 & t - j), t);
                for (j = 8; j--; F(j, i) += (-(i >> 1) ^ F(j, (i & 0x1) + 2) - F(j, i & 0x1) >> k) + (i >> 1));
                j = F(8, (i & 0x1) + 2) - F(8, i & 0x1);
            }
    if (R8 - L8 < N || D8 - U8 < N || !z) {
        if (y2 >= 0)
            RC(L8 >> Z, t, R8 >> Z, D8 >> Z, O[8] << 8 & 0xff0000 | O[8] >> 8 & 0xff00 | O[8] & 0xff);
    } else
        for (i = 7, j = x2 >> 31 << 2 | x1 >> 31 << 1 | x0 >> 31, k = i ^ j; i >= 0; i--, k = i ^ j)
            if (O[k]) {
                M3D2D(L8(k, 0), U8(k, 0), R8(k, 0), D8(k, 0), L8(k, 1), U8(k, 1), R8(k, 1), D8(k, 1), L8(k, 2), U8(k, 2), R8(k, 2), D8(k, 2), L8(k, 3), U8(k, 3), R8(k, 3), D8(k, 3), L8(k, 4), U8(k, 4), R8(k, 4), D8(k, 4), L8(k, 5), U8(k, 5), R8(k, 5), D8(k, 5), L8(k, 6), U8(k, 6), R8(k, 6), D8(k, 6), L8(k, 7), U8(k, 7), R8(k, 7), D8(k, 7), L8, U8, R8, D8, x0 + (1 - (k << 1 & 0x2) << 6 + z), x1 + (1 - (k & 0x2) << 6 + z), x2 + (1 - (k >> 1 & 0x2) << 6 + z), y0 + ((k << 31 >> 31 & B[0][0]) + (k << 30 >> 31 & B[1][0]) + (k << 29 >> 31 & B[2][0]) << z - 1), y1 + ((k << 31 >> 31 & B[0][1]) + (k << 30 >> 31 & B[1][1]) + (k << 29 >> 31 & B[2][1]) << z - 1), y2 + ((k << 31 >> 31 & B[0][2]) + (k << 30 >> 31 & B[1][2]) + (k << 29 >> 31 & B[2][2]) << z - 1), z - 1, O[k], t);
                RJ(t, t);
            }
}

#define V0(i)   ((&y0)[i] + (-B[0][i] - B[1][i] - B[2][i] << OH))
#define V1(i)   ((&y0)[i] + ( B[0][i] - B[1][i] - B[2][i] << OH))
#define V2(i)   ((&y0)[i] + (-B[0][i] + B[1][i] - B[2][i] << OH))
#define V3(i)   ((&y0)[i] + ( B[0][i] + B[1][i] - B[2][i] << OH))
#define V4(i)   ((&y0)[i] + (-B[0][i] - B[1][i] + B[2][i] << OH))
#define V5(i)   ((&y0)[i] + ( B[0][i] - B[1][i] + B[2][i] << OH))
#define V6(i)   ((&y0)[i] + (-B[0][i] + B[1][i] + B[2][i] << OH))
#define V7(i)   ((&y0)[i] + ( B[0][i] + B[1][i] + B[2][i] << OH))

#define Z   16
#define J   1 << Z - 1
int N = 5 << Z;

#define L(i)    (&L0)[i << 2]
#define U(i)    (&U0)[i << 2]
#define R(i)    (&R0)[i << 2]
#define D(i)    (&D0)[i << 2]

#define L8(i, j)    L(i) + L(j)
#define U8(i, j)    U(i) + U(j)
#define R8(i, j)    R(i) + R(j)
#define D8(i, j)    D(i) + D(j)

#define F(i, j) (&L0)[(i << 2) + (j)]
#define RJ(x, y)    if ((y = NU(L8 >> Z, x, R8 >> Z, D8 >> Z)) < 0) return
#define B(j)    ((-(i >> 1) ^ V##j(i & 0x1)) < (-(i >> 1) ^ F(j, i)) + (F(j, (i & 0x1) + 2) - F(j, i & 0x1) >> k))

int OH = 12;

void M3D2D(int L0, int U0, int R0, int D0, int L1, int U1, int R1, int D1, int L2, int U2, int R2, int D2, int L3, int U3, int R3, int D3, int L4, int U4, int R4, int D4, int L5, int U5, int R5, int D5, int L6, int U6, int R6, int D6, int L7, int U7, int R7, int D7, int L8, int U8, int R8, int D8, unsigned x0, unsigned x1, unsigned x2, int y0, int y1, int y2, unsigned O[], int t)
{
    int i, j, k;

    for (i = 4; i--;)
        for (k = 1, j = F(8, (i & 0x1) + 2) - F(8, i & 0x1); j >> k >= J;)
            if (B(0) || B(1) || B(2) || B(4) || B(3) || B(5) || B(6) || B(7))
                k++;
            else {
                F(8, i) += (-(i >> 1) ^ F(8, (i & 0x1) + 2) - F(8, i & 0x1) >> k) + (i >> 1);
                RJ((j = U8 >> Z) + (j - t >> 31 & t - j), t);
                for (j = 8; j--; F(j, i) += (-(i >> 1) ^ F(j, (i & 0x1) + 2) - F(j, i & 0x1) >> k) + (i >> 1));
                j = F(8, (i & 0x1) + 2) - F(8, i & 0x1);
            }
    if (R8 - L8 < N || D8 - U8 < N) {
        if (y2 >= 0)
            RC(L8 >> Z, t, R8 >> Z, D8 >> Z, O[0] << 8 & 0xff0000 | O[0] >> 8 & 0xff00 | O[0] & 0xff);
    } else
        for (i = 7, j = x2 >> 31 << 2 | x1 >> 31 << 1 | x0 >> 31, k = i ^ j; i >= 0; i--, k = i ^ j)
            if (O[0] & 1 << k + 24) {
                M3D2D(L8(k, 0), U8(k, 0), R8(k, 0), D8(k, 0), L8(k, 1), U8(k, 1), R8(k, 1), D8(k, 1), L8(k, 2), U8(k, 2), R8(k, 2), D8(k, 2), L8(k, 3), U8(k, 3), R8(k, 3), D8(k, 3), L8(k, 4), U8(k, 4), R8(k, 4), D8(k, 4), L8(k, 5), U8(k, 5), R8(k, 5), D8(k, 5), L8(k, 6), U8(k, 6), R8(k, 6), D8(k, 6), L8(k, 7), U8(k, 7), R8(k, 7), D8(k, 7), L8, U8, R8, D8, (x0 << 1) + (1 - (k << 1 & 0x2) << 7 + OH), (x1 << 1) + (1 - (k & 0x2) << 7 + OH), (x2 << 1) + (1 - (k >> 1 & 0x2) << 7 + OH), (y0 << 1) + (((k << 31 >> 31 & B[0][0]) << 1) - B[0][0] + ((k << 30 >> 31 & B[1][0]) << 1) - B[1][0] + ((k << 29 >> 31 & B[2][0]) << 1) - B[2][0] << OH - 1), (y1 << 1) + (((k << 31 >> 31 & B[0][1]) << 1) - B[0][1] + ((k << 30 >> 31 & B[1][1]) << 1) - B[1][1] + ((k << 29 >> 31 & B[2][1]) << 1) - B[2][1] << OH - 1), (y2 << 1) + (((k << 31 >> 31 & B[0][2]) << 1) - B[0][2] + ((k << 30 >> 31 & B[1][2]) << 1) - B[1][2] + ((k << 29 >> 31 & B[2][2]) << 1) - B[2][2] << OH - 1), O[1] + (rk[O[0] >> 24 & (1 << k) - 1] << 3), t);
                RJ(t, t);
            }
}

le(int a[], int b[])
{
    int i, j;

    for (i = 31; i >= 0; i--)
        for (j = 2; j >= 0; j--)
            if ((a[j] ^ b[j]) >> i)
                return a[j] < b[j];
    return 1;
}

int T[PTS][4];
void sort(int P[][4], int l, int r)
{
    int i, j, k;

    if (l < r) {
        k = M(l, r);
        sort(P, l, k);
        sort(P, k + 1, r);
        for (i = k - l; i >= 0; i--)
            for (j = 0; j < 4; j++) {
                T[r - i][j] = P[k + 1 + i][j];
                T[k - i][j] = P[k - i][j];
            }
        for (k = l, j = r; k <= j; k++)
            if (le(T[l], T[r])) {
                for (i = 3; i >= 0; i--)
                    P[k][i] = T[l][i];
                l++;
            } else {
                for (i = 3; i >= 0; i--)
                    P[k][i] = T[r][i];
                r--;
            }
    }
}

#define DIR(x, y, z, t) (x >> t & 0x1 | y >> t << 1 & 0x2 | z >> t << 2 & 0x4)

#define OH  20
#define H   0

int t[PTS][4];
int O[(500244 + H) * 9], Q[126553 /* 8351857 */ * 9];

int merge(int t[][4], int n, int O[], int P[], int l, int r)
{
    int i, j, *k, *z8 = O;

    for (i = 0; i < n; i++) {
        k = O;
        for (j = l - 1; j >= r; j--) {
            if (!k[DIR(t[i][0], t[i][1], t[i][2], j)]) {
                z8 += 9;
                k[DIR(t[i][0], t[i][1], t[i][2], j)] = z8;
            }
            k = k[DIR(t[i][0], t[i][1], t[i][2], j)];
        }
        if (P)
            for (j = 8; j--; k[j] = P[j]);
        k[8] = t[i][3];
    }
    return (z8 - O) / 9 + (n > 0);
}

#define R(x)    (x >> 16)
#define G(x)    (x >> 8 & 0xff)
#define B(x)    (x & 0xff)

int color(int O[], int z)
{
    int i, j, k[8] = { 0 };

    if (z) {
        for (i = 8, j = 0; i--; j += !!O[i] << 8 | !!O[i] << i);
        for (i = 8; i--;)
            if (j & 1 << i)
                k[i] = color(O[i], z - 1);
            O[8] =  (B(k[0]) + B(k[1]) + B(k[2]) + B(k[3]) + B(k[4]) + B(k[5]) + B(k[6]) + B(k[7])) / (j >> 8)      |
                    (G(k[0]) + G(k[1]) + G(k[2]) + G(k[3]) + G(k[4]) + G(k[5]) + G(k[6]) + G(k[7])) / (j >> 8) << 8 |
                    (R(k[0]) + R(k[1]) + R(k[2]) + R(k[3]) + R(k[4]) + R(k[5]) + R(k[6]) + R(k[7])) / (j >> 8) << 16;
    }
    return O[8] & (1 << 24) - 1;
}

unsigned O3(unsigned A[], int P[][4], unsigned Q[], unsigned n, int l, int r)
{
    int i, j, k;
    unsigned *O, *Z;

    sort(P, 0, n - 1);
    for (Z = A + 2, i = l - 1; i >= r; i--)
        for (j = 0; j < n; j++)
            for (O = A, k = l - 1; k >= i; k--) {
                if (~O[0] & 1 << D(j, k) + 24) {
                    if (!O[1])
                        O[1] = Z;
                    Z += 2;
                    O[0] |= 1 << D(j, k) + 24;
                }
                O = O[1] + (rk[O[0] >> 24 & (1 << D(j, k)) - 1] << 3);
            }
    for (i = 0; i < n; i++) {
        for (O = A, j = l - 1; j >= r; j--)
            O = O[1] + (rk[O[0] >> 24 & (1 << D(i, j)) - 1] << 3);
        O[0] = P[i][3] & (1 << 24) - 1;
        if (Q) {
            O[0] |= Q[0] & 0xff << 24;
            O[1] = Q[1];
        }
    }
    return Z - A >> 1;
}

int CL(unsigned A[], int z)
{
    if (z) {
        int i, j[5] = { 0 }, *k;

        for (i = 0; i < 8; i++)
            if (A[0] & 1 << i + 24) {
                j[3] += j[4] = CL(k = A[1] + (rk[A[0] >> 24 & (1 << i) - 1] << 3), z - 1);
                j[2] += (k[0] >> 16 & 0xff) * j[4];
                j[1] += (k[0] >> 8  & 0xff) * j[4];
                j[0] += (k[0]       & 0xff) * j[4];
            }
        A[0] |= j[0] / j[3] | j[1] / j[3] << 8 | j[2] / j[3] << 16;
        return j[3];
    }
    return 1;
}

short sines[] = { 0, 6, 12, 18, 25, 31, 37, 43, 49, 56, 62, 68, 74, 80, 86, 92, 97, 103, 109, 115, 120, 126, 131, 136, 142, 147, 152, 157, 162, 167, 171, 176, 181, 185, 189, 193, 197, 201, 205, 209, 212, 216, 219, 222, 225, 228, 231, 234, 236, 238, 241, 243, 244, 246, 248, 249, 251, 252, 253, 254, 254, 255, 255, 255, 256, 255, 255, 255, 254, 254, 253, 252, 251, 249, 248, 246, 244, 243, 241, 238, 236, 234, 231, 228, 225, 222, 219, 216, 212, 209, 205, 201, 197, 193, 189, 185, 181, 176, 171, 167, 162, 157, 152, 147, 142, 136, 131, 126, 120, 115, 109, 103, 97, 92, 86, 80, 74, 68, 62, 56, 49, 43, 37, 31, 25, 18, 12, 6, 0, -6, -12, -18, -25, -31, -37, -43, -49, -56, -62, -68, -74, -80, -86, -92, -97, -103, -109, -115, -120, -126, -131, -136, -142, -147, -152, -157, -162, -167, -171, -176, -181, -185, -189, -193, -197, -201, -205, -209, -212, -216, -219, -222, -225, -228, -231, -234, -236, -238, -241, -243, -244, -246, -248, -249, -251, -252, -253, -254, -254, -255, -255, -255, -256, -255, -255, -255, -254, -254, -253, -252, -251, -249, -248, -246, -244, -243, -241, -238, -236, -234, -231, -228, -225, -222, -219, -216, -212, -209, -205, -201, -197, -193, -189, -185, -181, -176, -171, -167, -162, -157, -152, -147, -142, -136, -131, -126, -120, -115, -109, -103, -97, -92, -86, -80, -74, -68, -62, -56, -49, -43, -37, -31, -25, -18, -12, -6 };

#define XR  1024
#define YR  768

int YMXR[YR];
int W[(XR * YR + 31) / 32];

#define YX  ((float)YR / (float)XR)

le(int a[], int b[])
{
    int i, j;

    for (i = 31; i >= 0; i--)
        for (j = 2; j >= 0; j--)
            if ((a[j] ^ b[j]) >> i)
                return a[j] < b[j];
    return 1;
}

#define OH  20
#define H   2

#define SBLR    7   //10
#define PTS 172974  //1024 * 1024   //6 * ((1 << SBLR) - 2) * ((1 << SBLR) - 2)

int P[PTS][4];

#define M(x, y) ((x) + (y) >> 1)    //(((x) & (y)) + (((x) ^ (y)) >> 1))

int T[PTS][4];
void sort(int P[][4], int l, int r)
{
    int i, j, k;

    if (l < r) {
        k = M(l, r);
        sort(P, l, k);
        sort(P, k + 1, r);
        for (i = k - l; i >= 0; i--)
            for (j = 0; j < 4; j++) {
                T[r - i][j] = P[k + 1 + i][j];
                T[k - i][j] = P[k - i][j];
            }
        for (k = l, j = r; k <= j; k++)
            if (le(T[l], T[r])) {
                for (i = 3; i >= 0; i--)
                    P[k][i] = T[l][i];
                l++;
            } else {
                for (i = 3; i >= 0; i--)
                    P[k][i] = T[r][i];
                r--;
            }
    }
}

#define D(i, j) (P[i][2] >> j << 2 & 0x4 | P[i][1] >> j << 1 & 0x2 | P[i][0] >> j & 0x1)

unsigned rk[256];
int /* O[(1 + H * 8) * 2], */ A[520244 * 2], Q[126553 /* 8351857 */ * 2] /*, PR[1396059 * 2] */;

unsigned O3(unsigned A[], int P[][4], unsigned Q[], unsigned n, int l, int r)
{
    int i, j, k;
    unsigned *O, *Z;

    sort(P, 0, n - 1);
    for (Z = A + 2, i = l - 1; i >= r; i--)
        for (j = 0; j < n; j++)
            for (O = A, k = l - 1; k >= i; k--) {
                if (~O[0] & 1 << D(j, k) + 24) {
                    if (!O[1])
                        O[1] = Z;
                    Z += 2;
                    O[0] |= 1 << D(j, k) + 24;
                }
                O = O[1] + (rk[O[0] >> 24 & (1 << D(j, k)) - 1] << 3);
            }
    for (i = 0; i < n; i++) {
        for (O = A, j = l - 1; j >= r; j--)
            O = O[1] + (rk[O[0] >> 24 & (1 << D(i, j)) - 1] << 3);
        O[0] = P[i][3] & (1 << 24) - 1;
        if (Q) {
            O[0] |= Q[0] & 0xff << 24;
            O[1] = Q[1];
        }
    }
    return Z - A >> 1;
}

int CL(unsigned A[], int z)
{
    if (z) {
        int i, j, k[3] = { 0 };

        for (i = 0; i < 8; i++)
            if (A[0] & 1 << i + 24) {
                j = CL(A[1] + (rk[A[0] >> 24 & (1 << i) - 1] << 3), z - 1);
                k[0] += j & 0xff, k[1] += j >> 8 & 0xff, k[2] += j >> 16;
            }
        j = rk[A[0] >> 24];
        A[0] |= k[2] / j << 16 | k[1] / j << 8 | k[0] / j;
    }
    return A[0] & (1 << 24) - 1;
}

int *p;

int V[3] = { (128 << OH) + 128,  (/* 128 */ /* 240 */ 64 << OH /* 0 */) + 128, (128 << OH) + 128 }, D[3] = { -32, -32, 0 };
int B[3][3];

int NU(int L, int U, int R, int D)
{
    int i, j;

    if (L >> 5 ^ (j = R >> 5))
        for (; U < D; U++) {
            if (-1 << (L & 0x1f) & W[YMXR[U] + L >> 5] || (1 << (R & 0x1f)) - 1 & W[YMXR[U] + R >> 5])
                return U;
            for (i = L + 32 >> 5; i < j; i++)
                if (W[YMXR[U] + (i << 5) >> 5])
                    return U;
        }
    else
        for (; U < D; U++)
            if (-1 << (L & 0x1f) & (1 << (R & 0x1f)) - 1 & W[YMXR[U] + L >> 5])
                return U;
    return -1;
}

void RC(int L, int U, int R, int D, int c)
{
    int i, j, k;

    for (i = U; i < D; i++)
        for (j = L; j < R; j++)
            if (W[(k = YMXR[i] + j) >> 5] & 1 << (k & 0x1f))
                p[YMXR[i] + j] = c;
    if (L >> 5 ^ (k = R >> 5))
        for (; U < D; U++) {
            W[YMXR[U] + L >> 5] &= (1 << (L & 0x1f)) - 1; W[YMXR[U] + R >> 5] &= -(1 << (R & 0x1f));
            for (j = L + 32 >> 5; j < k; j++)
                W[YMXR[U] + (j << 5) >> 5] = 0;
        }
    else
        for (j = (1 << (L & 0x1f)) - 1 | -(1 << (R & 0x1f)); U < D; U++)
            W[YMXR[U] + L >> 5] &= j;
}

#define ABS(x)  ((x) >> 31 ^ (x) - ((unsigned)(x) >> 31))

#define V(i, j) ((&y0)[j] + (((i) << 31 >> 31 & B[0][j]) + ((i) << 30 >> 31 & B[1][j]) + ((i) << 29 >> 31 & B[2][j]) << z))

#define V0(i)   (&y0)[i]
#define V1(i)  ((&y0)[i] + (B[0][i]                     << z))
#define V2(i)  ((&y0)[i] + (          B[1][i]           << z))
#define V3(i)  ((&y0)[i] + (B[0][i] + B[1][i]           << z))
#define V4(i)  ((&y0)[i] + (                    B[2][i] << z))
#define V5(i)  ((&y0)[i] + (B[0][i]           + B[2][i] << z))
#define V6(i)  ((&y0)[i] + (          B[1][i] + B[2][i] << z))
#define V7(i)  ((&y0)[i] + (B[0][i] + B[1][i] + B[2][i] << z))

#define Z   16
#define J   1 << Z - 1
int N = 3 << Z;

#define L(i)    (&L0)[i << 2]
#define U(i)    (&U0)[i << 2]
#define R(i)    (&R0)[i << 2]
#define D(i)    (&D0)[i << 2]

#define L8(i, j)    M(L(i), L(j))
#define U8(i, j)    M(U(i), U(j))
#define R8(i, j)    M(R(i), R(j))
#define D8(i, j)    M(D(i), D(j))

#define F(i, j) (&L0)[((i) << 2) + (j)]
#define RJ(x, y)    if ((y = NU(L8 >> Z, x, R8 >> Z, D8 >> Z)) < 0) return

#define B(j)    ((-(i >> 1) ^ V(j, i & 0x1)) < (-(i >> 1) ^ F(j, i)) + (F(j, (i & 0x1) + 2) - F(j, i & 0x1) >> k))

#define S8(x)   \
do  \
    for (i = 7, j = x2 >> 31 << 2 | x1 >> 31 << 1 | x0 >> 31, k = i ^ j; i >= 0; k = --i ^ j)   \
        if (O[0] & 1 << k + 24) {   \
            M3D2D(L8(k, 0), U8(k, 0), R8(k, 0), D8(k, 0), L8(k, 1), U8(k, 1), R8(k, 1), D8(k, 1), L8(k, 2), U8(k, 2), R8(k, 2), D8(k, 2), L8(k, 3), U8(k, 3), R8(k, 3), D8(k, 3), L8(k, 4), U8(k, 4), R8(k, 4), D8(k, 4), L8(k, 5), U8(k, 5), R8(k, 5), D8(k, 5), L8(k, 6), U8(k, 6), R8(k, 6), D8(k, 6), L8(k, 7), U8(k, 7), R8(k, 7), D8(k, 7), L8, U8, R8, D8, x0 + (1 - (k << 1 & 0x2) << 6 + z), x1 + (1 - (k & 0x2) << 6 + z), x2 + (1 - (k >> 1 & 0x2) << 6 + z), y0 + ((k << 31 >> 31 & B[0][0]) + (k << 30 >> 31 & B[1][0]) + (k << 29 >> 31 & B[2][0]) << z - 1), y1 + ((k << 31 >> 31 & B[0][1]) + (k << 30 >> 31 & B[1][1]) + (k << 29 >> 31 & B[2][1]) << z - 1), y2 + ((k << 31 >> 31 & B[0][2]) + (k << 30 >> 31 & B[1][2]) + (k << 29 >> 31 & B[2][2]) << z - 1), z - 1, O[1] + (rk[O[0] >> 24 & (1 << k) - 1] << 3), t, s | ~j ^ k);   \
            x;  \
        }   \
while (0)

#define C2R(x)  \
do  \
    for (i = 4; i--;)   \
        for (k = 1, j = F(8, (i & 0x1) + 2) - F(8, i & 0x1); j >> k >= J;)  \
            if (B(a & 0x7) || B(a >> 4 & 0x7) || B(a >> 8 & 0x7) x) \
                k++;    \
            else {  \
                F(8, i) += (-(i >> 1) ^ F(8, (i & 0x1) + 2) - F(8, i & 0x1) >> k) + (i >> 1);   \
                RJ((j = U8 >> Z) + (j - t >> 31 & t - j), t);   \
                for (j = 8; j--; F(j, i) += (-(i >> 1) ^ F(j, (i & 0x1) + 2) - F(j, i & 0x1) >> k) + (i >> 1)); \
                j = F(8, (i & 0x1) + 2) - F(8, i & 0x1);    \
            }   \
while (0)

void M3D2D(int L0, int U0, int R0, int D0, int L1, int U1, int R1, int D1, int L2, int U2, int R2, int D2, int L3, int U3, int R3, int D3, int L4, int U4, int R4, int D4, int L5, int U5, int R5, int D5, int L6, int U6, int R6, int D6, int L7, int U7, int R7, int D7, int L8, int U8, int R8, int D8, unsigned x0, unsigned x1, unsigned x2, int y0, int y1, int y2, int z, unsigned O[], int t, int s)
{
    int i, j, k, a;

    for (a = 0, k = x2 >> 31 << 2 | x1 >> 31 << 1 | x0 >> 31, j = 0, i = 8; i--;)
        if (rk[(i ^ k) & s] - 1 < 2) {
            a = a << 4 | i;
            j++;
        }
    if (j) {
        if (j < 6)
            C2R(|| B(a >> 12));
        else
            C2R(|| B(a >> 12 & 0x7) || B(a >> 16 & 0x7) || B(a >> 20));
        if (R8 - L8 < N || D8 - U8 < N || !z) {
            if (y2 >= 0)
                RC(L8 >> Z, t, R8 >> Z, D8 >> Z, O[0] << 8 & 0xff0000 | O[0] >> 8 & 0xff00 | O[0] & 0xff);
        } else
            S8(RJ(t, t));
    } else
        S8();
}

void M3D2D(int L0, int U0, int R0, int D0, int L1, int U1, int R1, int D1, int L2, int U2, int R2, int D2, int L3, int U3, int R3, int D3, int L4, int U4, int R4, int D4, int L5, int U5, int R5, int D5, int L6, int U6, int R6, int D6, int L7, int U7, int R7, int D7, int L8, int U8, int R8, int D8, unsigned x0, unsigned x1, unsigned x2, int y0, int y1, int y2, int z, unsigned O[], int t, int s)
{
    int i, j, k;

    if (V(M[6], 0) <= -V(M[6], 2) || V(M[7], 1) <= -V(M[7], 2) || V(M[8], 0) >= V(M[8], 2) || V(M[9], 1) >= V(M[9], 2) || V(M[5], 2) < XR / 2 + 444)
        return;
    if (V(M[4], 2) < XR / 2)
        S8();
    else {
        int a;

        for (a = 0, k = x2 >> 31 << 2 | x1 >> 31 << 1 | x0 >> 31, j = 0, i = 8; i--;)
            if (rk[(i ^ k) & s] - 1 < 2) {
                a = a << 4 | i;
                j++;
            }
        if (j < 6)
            C2R(|| B(a >> 12));
        else
            C2R(|| B(a >> 12 & 0x7) || B(a >> 16 & 0x7) || B(a >> 20));
        if (R8 - L8 < N || D8 - U8 < N || !z)
            RC(L8 >> Z, t, R8 >> Z, D8 >> Z, O[0] << 8 & 0xff0000 | O[0] >> 8 & 0xff00 | O[0] & 0xff);
        else
            S8(RJ(t, t));
    }
}

void SB(int P[][4], int a)
{
    int x, y, z, i;

    for (a = (1 << a) - 1, z = (a - 1) * (a - 1), x = 1; x < a; x++)
        for (y = 1; y < a; y++)
            for (i = 3; i--; P[i * z + (x - 1) * (a - 1) + y - 1][i] = 0, P[(i + 3) * z + (x - 1) * (a - 1) + y - 1][i] = a, P[i * z + (x - 1) * (a - 1) + y - 1][(i + 1) % 3] = P[(i + 3) * z + (x - 1) * (a - 1) + y - 1][(i + 1) % 3] = x, P[i * z + (x - 1) * (a - 1) + y - 1][(i + 2) % 3] = P[(i + 3) * z + (x - 1) * (a - 1) + y - 1][(i + 2) % 3] = y, P[i * z + (x - 1) * (a - 1) + y - 1][3] = P[(i + 3) * z + (x - 1) * (a - 1) + y - 1][3] = (x ^ y) << (i << 3));
}

void PY(int P[][4], int a)
{
    int x, z;

    for (z = 0; z < 1 << a; z++)
        for (x = 0; x < 1 << a; x++) {
            P[(z << a) + x][0] = x;
            P[(z << a) + x][1] = x ^ z;
            P[(z << a) + x][2] = z;
            P[(z << a) + x][3] = z << 16 | (x ^ z & 0xff) << 8 | x & 0xff;
        }
}

#include <stdio.h>

void loadxyzrgba(char *xyzrgba, int n, float s)
{
    int i, j;
    float k;
    FILE *f;

    if (f = fopen(xyzrgba, "r")) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < 3; fscanf(f, "%f", &k), P[i][j++] = k * s);
            for (; j >= 0; fscanf(f, "%d", (char *)&P[i][3] + 3 - j--));
        }
        fclose(f);
    }
}

#include <windows.h>

HDC hdcm;
HBITMAP hbm;

POINT S;
int ESB;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;

    switch (uMsg) {
    case WM_KEYDOWN:
        switch (wParam) {
        case 'S':
            ESB = !ESB;
            break;
        case VK_SUBTRACT:
            N += 1 << Z;
            break;
        case VK_ADD:
            N -= (N > 1 << Z) << Z;
            break;
        case VK_ESCAPE:
            PostMessage(hwnd, WM_DESTROY, 0, 0);
            break;
        }
        return 0;
    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        BitBlt(hdc, 0, 0, XR, YR, hdcm, 0, 0, SRCCOPY);
        EndPaint(hwnd, &ps);
        return 0;
    case WM_MOUSEMOVE:
        if (wParam & MK_LBUTTON) { D[1] -= S.x - LOWORD(lParam) >> 3; D[0] += S.y - HIWORD(lParam) >> 3; }
        S.x = LOWORD(lParam); S.y = HIWORD(lParam);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int IM(int x, int y)
{
    __asm {
        MOV     EAX, x
        IMUL    y
        SHRD    EAX, EDX, 8
    }
}

#define SIN(x)  sines[(x) & 0xff]
#define COS(x)  SIN(x + 64)

#define V(i, j) (((i << 31 >> 31 & B[0][j]) + (i << 30 >> 31 & B[1][j]) + (i << 29 >> 31 & B[2][j]) << OH) - (IM(V[0] & (256 << OH) - 1, B[0][j]) + IM(V[1] & (256 << OH) - 1, B[1][j]) + IM(V[2] & (256 << OH) - 1, B[2][j])))
#define K(i, j, k)  (((i << 31 >> 31 & B[0][j]) + (i << 30 >> 31 & B[1][j]) + (i << 29 >> 31 & B[2][j]) << k + 8) - ((128 << k) * B[0][j] + (128 << k) * B[1][j] + (128 << k) * B[2][j]) >> 8)

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASS wc;
    HWND hwnd;
    MSG msg;
    BITMAPINFO bmi;
    HBITMAP hbmold;
    RECT rec, rect;
    HDC hdc;

    int S[3], C[3];
    int i, j, k;

    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = NULL;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WindowProc;
    wc.lpszClassName = "M3D2D";
    wc.lpszMenuName = NULL;
    wc.style = 0;

    if (!RegisterClass(&wc))
        return 0;
    if (!(hwnd = CreateWindow("M3D2D", "M3D2D", WS_MINIMIZEBOX | WS_SYSMENU, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL)))
        return 0;

    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biWidth = XR;
    bmi.bmiHeader.biHeight = -YR;
    bmi.bmiHeader.biCompression = BI_RGB;

    GetWindowRect(hwnd, &rec);
    GetClientRect(hwnd, &rect);
    rec.right = rect.left - rec.left + XR + rec.right - rect.right;
    rec.bottom = rect.top - rec.top + YR + rec.bottom - rect.bottom;
    MoveWindow(hwnd, rec.left, rec.top, rec.right, rec.bottom, 0);

    hdc = GetDC(hwnd);
    hbm = CreateDIBSection(hdc, &bmi, DIB_RGB_COLORS, &p, NULL, 0);
    hdcm = CreateCompatibleDC(hdc);
    hbmold = SelectObject(hdcm, hbm);

    loadxyzrgba("armadillo", /* PTS */ 172974, -(1732 /* >> H */));
    for (C[i = 0] = C[1] = C[2] = (1 << 31) - 1, S[0] = S[1] = S[2] = -1 << 31; i < /* PTS */ 172974; i++)
        for (j = 3; j--;) {
            if (P[i][j] < C[j])
                C[j] = P[i][j];
//            if (P[i][j] > S[j])
//                S[j] = P[i][j];
        }
    for (i = 0; i < /* PTS */ 172974; i++)
        for (j = 3; j--;)
            P[i][j] -= C[j];    //M(C[j], S[j]);

    for (i = 256; i--;)
        for (j = i; j; rk[i]++, j &= j - 1);
/*
    for (O[0] = 0xff << 24, O[1] = &O[k = 2], i = H - 1; i > 0; i--, k += 8 * 2)
        for (j = 0; j < 8; O[k + (j << 1)] = 0xff << 24, O[k + (j << 1) + 1] = &O[k + 8 * 2], j++);
*/
    O3(A, P, /* O */ A, /* PTS */ 172974, /* 10 - H */ 18, 8);
/*
    PY(P, 8);
    O3(PR, P, A, 256 * 256, 8, 0);
    CL(PR, 8);
*/
//    for (j = 0; j < 8; O[k + (j << 1)] = /* A[0] */ PR[0], O[k + (j << 1) + 1] = /* A[1] */ PR[1], j++);

    CL(/* O */ A, 10);
//    CL(O, H);

    SB(P, SBLR);
    O3(Q, P, 0, 6 * ((1 << SBLR) - 2) * ((1 << SBLR) - 2), SBLR, 0);
    CL(Q, SBLR);

    for (i = YR; i--; YMXR[i] = i * XR);

    ShowWindow(hwnd, nCmdShow);

    for (;;) {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT)
                break;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        } else {
            S[0] = SIN(D[0]); S[1] = SIN(D[1]); S[2] = SIN(D[2]);
            C[0] = COS(D[0]); C[1] = COS(D[1]); C[2] = COS(D[2]);

            B[0][0] = (C[1] * C[2] << 8) + S[0] * S[1] * S[2] >> 16; B[0][1] = S[0] * S[1] * C[2] - (C[1] * S[2] << 8) >> 16; B[0][2] = C[0] * S[1] >> 8;
            B[1][0] = C[0] * S[2] >> 8; B[1][1] = C[0] * C[2] >> 8; B[1][2] = -S[0];
            B[2][0] = S[0] * C[1] * S[2] - (S[1] * C[2] << 8) >> 16; B[2][1] = (S[1] * S[2] << 8) + S[0] * C[1] * C[2] >> 16; B[2][2] = C[0] * C[1] >> 8;

            for (i = !!GetAsyncKeyState(VK_UP) | !!GetAsyncKeyState(VK_DOWN) << 1 | !!GetAsyncKeyState(VK_LEFT) << 2 | !!GetAsyncKeyState(VK_RIGHT) << 3 /* A, START */ | !!(GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT)) << 4, j = 3; j--; V[j] += (i << 31 >> 31 & B[j][2]) - (i << 30 >> 31 & B[j][2]) - (i << 29 >> 31 & B[j][0]) + (i << 28 >> 31 & B[j][0]) << (5 << (i >> 4)));

            memset(W, 0xff, (XR * YR + 31) / 32 * 4);

            for (i = 8; i--;) {
                for (j = 4; j--;)
                    if ((-(j >> 1) ^ K(i, j & 0x1, 0)) < (-(j >> 1) ^ K(M[j], j & 0x1, 0)))
                        M[j] = i;
                for (j = 2; j--;)
                    if ((-j ^ K(i, 2, 0)) < (-j ^ K(M[4 + j], 2, 0)))
                        M[4 + j] = i;
                for (k = 160 << 24 | 160 << 16 | 224 << 8 | 224, j = 4; j--; k >>= 8)
                    if (K(i, j & 0x1, 0) * COS(k) + K(i, 2, 0) * SIN(k) < K(M[6 + j], j & 0x1, 0) * COS(k) + K(M[6 + j], 2, 0) * SIN(k))
                        M[6 + j] = i;
            }

            M3D2D(-V(0, 2), -V(0, 2) * YX, V(0, 2), V(0, 2) * YX, -V(1, 2), -V(1, 2) * YX, V(1, 2), V(1, 2) * YX, -V(2, 2), -V(2, 2) * YX, V(2, 2), V(2, 2) * YX, -V(3, 2), -V(3, 2) * YX, V(3, 2), V(3, 2) * YX, -V(4, 2), -V(4, 2) * YX, V(4, 2), V(4, 2) * YX, -V(5, 2), -V(5, 2) * YX, V(5, 2), V(5, 2) * YX, -V(6, 2), -V(6, 2) * YX, V(6, 2), V(6, 2) * YX, -V(7, 2), -V(7, 2) * YX, V(7, 2), V(7, 2) * YX, 0, 0, XR << Z, YR << Z, V[0] - (128 << OH), V[1] - (128 << OH), V[2] - (128 << OH), V(0, 0), V(0, 1), V(0, 2), OH, /* O */ A /* PR */, 0, 0);
            if (ESB) {
                if ((i = NU(0, 0, XR, YR)) >= 0)
                    M3D2D(-K(0, 2, SBLR), -K(0, 2, SBLR) * YX, K(0, 2, SBLR), K(0, 2, SBLR) * YX, -K(1, 2, SBLR), -K(1, 2, SBLR) * YX, K(1, 2, SBLR), K(1, 2, SBLR) * YX, -K(2, 2, SBLR), -K(2, 2, SBLR) * YX, K(2, 2, SBLR), K(2, 2, SBLR) * YX, -K(3, 2, SBLR), -K(3, 2, SBLR) * YX, K(3, 2, SBLR), K(3, 2, SBLR) * YX, -K(4, 2, SBLR), -K(4, 2, SBLR) * YX, K(4, 2, SBLR), K(4, 2, SBLR) * YX, -K(5, 2, SBLR), -K(5, 2, SBLR) * YX, K(5, 2, SBLR), K(5, 2, SBLR) * YX, -K(6, 2, SBLR), -K(6, 2, SBLR) * YX, K(6, 2, SBLR), K(6, 2, SBLR) * YX, -K(7, 2, SBLR), -K(7, 2, SBLR) * YX, K(7, 2, SBLR), K(7, 2, SBLR) * YX, 0, 0, XR << Z, YR << Z, 0, 0, 0, K(0, 0, SBLR), K(0, 1, SBLR), K(0, 2, SBLR), SBLR, Q, i, 0);
            }

            BitBlt(hdc, 0, 0, XR, YR, hdcm, 0, 0, SRCCOPY);
            ZeroMemory(p, XR * YR * 4);
        }
    }

    ReleaseDC(hwnd, hdc);
    SelectObject(hdcm, hbmold);
    DeleteDC(hdcm);
    DeleteObject(hbm);

    return msg.wParam;
}

le(int a[], int b[])
{
    int i, j;

    for (i = 31; i >= 0; i--)
        for (j = 2; j >= 0; j--)
            if ((a[j] ^ b[j]) >> i)
                return a[j] < b[j];
    return 1;
}

#define PTS 172974  //693896
#define OC3 373380  //1776078
#define H   10  //16

int t[PTS][4], O[OC3];

#define M(x, y) ((x) + (y) >> 1)

int z[PTS][4];

void sort(int t[][4], int l, int r)
{
    int i, j, k;

    if (l < r) {
        k = M(l, r);
        sort(t, l, k);
        sort(t, k + 1, r);
        for (i = k - l; i >= 0; i--)
            for (j = 0; j < 4; j++) {
                z[r - i][j] = t[k + 1 + i][j];
                z[k - i][j] = t[k - i][j];
            }
        for (k = l, j = r; k <= j; k++)
            if (le(z[l], z[r])) {
                for (i = 3; i >= 0; i--)
                    t[k][i] = z[l][i];
                l++;
            } else {
                for (i = 3; i >= 0; i--)
                    t[k][i] = z[r][i];
                r--;
            }
    }
}

#define D(x, y, z, i)   ((z) >> (i) << 2 & 0x4 | (y) >> (i) << 1 & 0x2 | (x) >> (i) & 0x1)

unsigned merge(int O[], int t[][4], unsigned n, int l, int r)
{
    int S[H + 1], j, a, z;
    unsigned i, k;

    for (i = 0; i < n; O[k] = t[i][3] << 8, i++)
        for (k = 0, j = l - 1; j >= r; j--)
            for (z = 0, O[k] |= 1 << D(t[i][0], t[i][1], t[i][2], j), a = O[k++] & (1 << D(t[i][0], t[i][1], t[i][2], j)) - 1; a; a &= a - 1)
                for (S[z++] = O[k++] & 0xff; z;)
                    if (S[z - 1]) {
                        S[z - 1] &= S[z - 1] - 1;
                        S[z++] = O[k++] & 0xff;
                    } else
                        z--;

    return k + (n > 0);
}

unsigned color(int O[])
{
    int S[H + 1][5], j;
    unsigned i, k;

    for (i = k = S[0][1] = S[0][2] = S[0][3] = S[0][4] = 0, S[i++][0] = O[k++] & 0xff;;)
        if (S[i - 1][0] & 0xff) {
            S[i - 1][0] += 1 << 8;
            S[i - 1][0] &= S[i - 1][0] - 1;
            S[i][0] = O[k] & 0xff;
            S[i][1] = S[i][2] = S[i][3] = 0;
            S[i++][4] = k++;
        } else {
            if (O[S[i - 1][4]] & 0xff) {
                j = S[i - 1][0] >> 8;
                O[S[i - 1][4]] |= S[i - 1][1] / j << 8 | S[i - 1][2] / j << 16 | S[i - 1][3] / j << 24;
            }
            if (--i)
                for (j = 2; j >= 0; S[i - 1][1 + j] += O[S[i][4]] >> (1 + j << 3) & 0xff, j--);
            else
                return k;
        }
}

int V[3], D[3] = { -32, 32, 0 }, B[3][3];

#define LOG_R   10

int zbuffer[1 << (LOG_R << 1)];
int *p;

#define L(i)    (&L0)[i << 1]
#define U(i)    (&U0)[i << 1]
#define R(i)    (L(i) + (V(i, 2) << 1 >> LOG_R - t))
#define D(i)    (U(i) + (V(i, 2) << 1 >> LOG_R - t))

#define L8(i, j)    M(L(i), L(j))
#define U8(i, j)    M(U(i), U(j))

#define V(i, j) ((&y0)[j] + ((i << 31 >> 31 & B[0][j]) + (i << 30 >> 31 & B[1][j]) + (i << 29 >> 31 & B[2][j]) << z))
#define V0(i)    (&y0)[i]
#define V1(i)   ((&y0)[i] + (B[0][i]                     << z))
#define V2(i)   ((&y0)[i] + (          B[1][i]           << z))
#define V3(i)   ((&y0)[i] + (B[0][i] + B[1][i]           << z))
#define V4(i)   ((&y0)[i] + (                    B[2][i] << z))
#define V5(i)   ((&y0)[i] + (B[0][i]           + B[2][i] << z))
#define V6(i)   ((&y0)[i] + (          B[1][i] + B[2][i] << z))
#define V7(i)   ((&y0)[i] + (B[0][i] + B[1][i] + B[2][i] << z))

#define N(j)    ((j << 30 >> 31 ^ V0(j & 0x1)) < (j << 30 >> 31 ^ G[0][j]) + (V0(2) >> LOG_R - i) || (j << 30 >> 31 ^ V1(j & 0x1)) < (j << 30 >> 31 ^ G[1][j]) + (V1(2) >> LOG_R - i) || (j << 30 >> 31 ^ V2(j & 0x1)) < (j << 30 >> 31 ^ G[2][j]) + (V2(2) >> LOG_R - i) || (j << 30 >> 31 ^ V3(j & 0x1)) < (j << 30 >> 31 ^ G[3][j]) + (V3(2) >> LOG_R - i) || (j << 30 >> 31 ^ V4(j & 0x1)) < (j << 30 >> 31 ^ G[4][j]) + (V4(2) >> LOG_R - i) || (j << 30 >> 31 ^ V5(j & 0x1)) < (j << 30 >> 31 ^ G[5][j]) + (V5(2) >> LOG_R - i) || (j << 30 >> 31 ^ V6(j & 0x1)) < (j << 30 >> 31 ^ G[6][j]) + (V6(2) >> LOG_R - i) || (j << 30 >> 31 ^ V7(j & 0x1)) < (j << 30 >> 31 ^ G[7][j]) + (V7(2) >> LOG_R - i))
#define DIR(i)  (G[8][1 + (i & 0x2)] - (i >> 1) >> t - 1 << 1 & 0x2 | G[8][i << 1 & 0x2] - (i & 0x1) >> t - 1 & 0x1)
#define DIR0(i) (G[8][1] >> i - 1 << 1 & 0x2 | G[8][0] >> i - 1 & 0x1)
#define DIR1(i) (G[8][1] >> i - 1 << 1 & 0x2 | G[8][2] - 1 >> i - 1 & 0x1)
#define DIR2(i) (G[8][3] - 1 >> i - 1 << 1 & 0x2 | G[8][0] >> i - 1 & 0x1)
#define DIR3(i) (G[8][3] - 1 >> i - 1 << 1 & 0x2 | G[8][2] - 1 >> i - 1 & 0x1)

int Z = 2;

unsigned D2D3M(int L0, int U0, int L1, int U1, int L2, int U2, int L3, int U3, int L4, int U4, int L5, int U5, int L6, int U6, int L7, int U7, int z0, int z1, int t, int y0, int y1, int y2, int z, unsigned O[], unsigned K)
{
    int S[H + 1], i, j, k, G[9][4];

    for (G[8][0] = z0, G[8][1] = z1, G[8][2] = z0 + (1 << t), G[8][3] = z1 + (1 << t), i = 8; i--; G[i][0] = L(i), G[i][1] = U(i), G[i][2] = L(i) + (V(i, 2) << 1 >> LOG_R - t), G[i][3] = U(i) + (V(i, 2) << 1 >> LOG_R - t));
    for (i = t; i; i--)
        for (j = 4; j--;)
            if (!N(j))
                for (G[8][j] += (j << 30 >> 31 ^ 1 << i - 1) + (j >> 1), k = 8; k--; G[k][j] += (j << 30 >> 31 ^ V(k, 2) >> LOG_R - i) + (j >> 1));
    for (k = M(V0(2), V7(2)), i = G[8][1]; i < G[8][3]; i++)
        for (j = G[8][0]; j < G[8][2]; j++)
            if (k < zbuffer[(i << LOG_R) + j]) {
                if (G[8][2] - G[8][0] <= Z || G[8][3] - G[8][1] <= Z || !z) {
                    if (y2 >= 0)
                        for (; i < G[8][3]; j = G[8][0], i++)
                            for (; j < G[8][2]; j++)
                                if (k < zbuffer[(i << LOG_R) + j]) {
                                    p[(i << LOG_R) + j] = O[K] & 0xff0000 | O[K] >> 16 & 0xff00 | O[K] >> 8 & 0xff;
                                    zbuffer[(i << LOG_R) + j] = k;
                                }
                    goto L0;
                }
                for (; t; t--) {
                    if ((j = DIR0(t)) ^ DIR1(t) || j ^ DIR2(t) || j ^ DIR3(t)) {
                        for (k = O[K++], i = 0; i < 8; i++)
                            if (k & 1 << i)
                                K = D2D3M(L8(i, 0), U8(i, 0), L8(i, 1), U8(i, 1), L8(i, 2), U8(i, 2), L8(i, 3), U8(i, 3), L8(i, 4), U8(i, 4), L8(i, 5), U8(i, 5), L8(i, 6), U8(i, 6), L8(i, 7), U8(i, 7), z0, z1, t, y0 + ((i << 31 >> 31 & B[0][0]) + (i << 30 >> 31 & B[1][0]) + (i << 29 >> 31 & B[2][0]) << z - 1), y1 + ((i << 31 >> 31 & B[0][1]) + (i << 30 >> 31 & B[1][1]) + (i << 29 >> 31 & B[2][1]) << z - 1), y2 + ((i << 31 >> 31 & B[0][2]) + (i << 30 >> 31 & B[1][2]) + (i << 29 >> 31 & B[2][2]) << z - 1), z - 1, O, K);
                        return K;
                    }
                    for (z0 += (j & 0x1) << t - 1, z1 += j >> 1 << t - 1, i = 8; i--; L(i) += j << 31 >> 31 & V(i, 2) >> LOG_R - t, U(i) += j << 30 >> 31 & V(i, 2) >> LOG_R - t);
                }
            }
L0:
    for (i = 0, S[i++] = O[K++] & 0xff; i;)
        if (S[i - 1]) {
            S[i - 1] &= S[i - 1] - 1;
            S[i++] = O[K++] & 0xff;
        } else
            i--;

    return K;
}

#include <stdio.h>

void loadxyzrgba(char *xyzrgba, int n, float s)
{
    int i, j;
    float k;
    FILE *f;

    if (f = fopen(xyzrgba, "r")) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < 3; fscanf(f, "%f", &k), t[i][j] = (int)(k * s), j++);
            for (; j >= 0; fscanf(f, "%d", (char *)&t[i][3] + 3 - j), j--);
        }
        fclose(f);
    }
}

void store83(int O[], char *oc3, unsigned n)
{
    FILE *f;

    if (f = fopen(oc3, "wb")) {
        fwrite(O, sizeof(int), n, f);
        fclose(f);
    }
}

unsigned load83(char *oc3, int O[])
{
    FILE *f;
    unsigned n;

    if (f = fopen(oc3, "rb")) {
        fseek(f, 0L, SEEK_END);
        n = ftell(f) >> 2;
        fseek(f, 0L, SEEK_SET);
        fread(O, sizeof(int), n, f);
        fclose(f);
    }

    return n;
}

short sines[] = { 0, 6, 12, 18, 25, 31, 37, 43, 49, 56, 62, 68, 74, 80, 86, 92, 97, 103, 109, 115, 120, 126, 131, 136, 142, 147, 152, 157, 162, 167, 171, 176, 181, 185, 189, 193, 197, 201, 205, 209, 212, 216, 219, 222, 225, 228, 231, 234, 236, 238, 241, 243, 244, 246, 248, 249, 251, 252, 253, 254, 254, 255, 255, 255, 256, 255, 255, 255, 254, 254, 253, 252, 251, 249, 248, 246, 244, 243, 241, 238, 236, 234, 231, 228, 225, 222, 219, 216, 212, 209, 205, 201, 197, 193, 189, 185, 181, 176, 171, 167, 162, 157, 152, 147, 142, 136, 131, 126, 120, 115, 109, 103, 97, 92, 86, 80, 74, 68, 62, 56, 49, 43, 37, 31, 25, 18, 12, 6, 0, -6, -12, -18, -25, -31, -37, -43, -49, -56, -62, -68, -74, -80, -86, -92, -97, -103, -109, -115, -120, -126, -131, -136, -142, -147, -152, -157, -162, -167, -171, -176, -181, -185, -189, -193, -197, -201, -205, -209, -212, -216, -219, -222, -225, -228, -231, -234, -236, -238, -241, -243, -244, -246, -248, -249, -251, -252, -253, -254, -254, -255, -255, -255, -256, -255, -255, -255, -254, -254, -253, -252, -251, -249, -248, -246, -244, -243, -241, -238, -236, -234, -231, -228, -225, -222, -219, -216, -212, -209, -205, -201, -197, -193, -189, -185, -181, -176, -171, -167, -162, -157, -152, -147, -142, -136, -131, -126, -120, -115, -109, -103, -97, -92, -86, -80, -74, -68, -62, -56, -49, -43, -37, -31, -25, -18, -12, -6 };

#include <windows.h>

HDC hdcm;
HBITMAP hbm;

POINT P;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;

    switch (uMsg) {
    case WM_KEYDOWN:
        switch (wParam) {
        case VK_SUBTRACT:
            Z += Z < 8;
            break;
        case VK_ADD:
            Z -= Z > 1;
            break;
        case VK_ESCAPE:
            PostMessage(hwnd, WM_DESTROY, 0, 0);
            break;
        }
        return 0;
    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        BitBlt(hdc, 0, 0, 1 << LOG_R, 1 << LOG_R /* 768 */, hdcm, 0, 0, SRCCOPY);
        EndPaint(hwnd, &ps);
        return 0;
    case WM_MOUSEMOVE:
        if (wParam & MK_LBUTTON) { D[1] -= P.x - LOWORD(lParam) >> 3; D[0] += P.y - HIWORD(lParam) >> 3; }
        P.x = LOWORD(lParam); P.y = HIWORD(lParam);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

#define SIN(x)  sines[(x) & 0xff]
#define COS(x)  SIN(x + 64)

#define V(i, j) (-(V[0] & (256 << H) - 1) * B[0][j] - (V[1] & (256 << H) - 1) * B[1][j] - (V[2] & (256 << H) - 1) * B[2][j] + ((i << 31 >> 31 & B[0][j]) + (i << 30 >> 31 & B[1][j]) + (i << 29 >> 31 & B[2][j]) << H << 8) >> 8)   //#define V(i, j) (-((V[0] & (256 << H) - 1) >> 6) * B[0][j] - ((V[1] & (256 << H) - 1) >> 6) * B[1][j] - ((V[2] & (256 << H) - 1) >> 6) * B[2][j] + ((i << 31 >> 31 & B[0][j]) + (i << 30 >> 31 & B[1][j]) + (i << 29 >> 31 & B[2][j]) << H << 2) >> 2)

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASS wc;
    HWND hwnd;
    MSG msg;
    BITMAPINFO bmi;
    HBITMAP hbmold;
    RECT rec, rect;
    HDC hdc;

    int S[3], C[3];
    int i, j;

    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = NULL;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WindowProc;
    wc.lpszClassName = "M3D2D";
    wc.lpszMenuName = NULL;
    wc.style = 0;

    if (!RegisterClass(&wc))
        return 0;
    if (!(hwnd = CreateWindow("M3D2D", "M3D2D", WS_MINIMIZEBOX | WS_SYSMENU, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL)))
        return 0;

    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biWidth = 1 << LOG_R;
    bmi.bmiHeader.biHeight = -(1 << LOG_R) /* -768 */;
    bmi.bmiHeader.biCompression = BI_RGB;

    GetWindowRect(hwnd, &rec);
    GetClientRect(hwnd, &rect);
    rec.right = rect.left - rec.left + (1 << LOG_R) + rec.right - rect.right;
    rec.bottom = rect.top - rec.top + (1 << LOG_R) /* 768 */ + rec.bottom - rect.bottom;
    MoveWindow(hwnd, rec.left, rec.top, rec.right, rec.bottom, 0);

    hdc = GetDC(hwnd);
    hbm = CreateDIBSection(hdc, &bmi, DIB_RGB_COLORS, &p, NULL, 0);
    hdcm = CreateCompatibleDC(hdc);
    hbmold = SelectObject(hdcm, hbm);
/*
    loadxyzrgba("armadillo", PTS, -(1 << H));
    for (C[i = 0] = C[1] = C[2] = 0x7fffffff; i < PTS; i++)
        for (j = 3; j--;)
            if (t[i][j] < C[j])
                C[j] = t[i][j];
    for (i = 0; i < PTS; i++)
        for (j = 3; j--;)
            t[i][j] -= C[j];
    sort(t, 0, PTS - 1);
    merge(O, t, PTS, 8 + H, 8);
    store83(O, "armadillo.83", color(O));
*/
    load83("armadillo.83", O);
//    load83("stadium.83", O);
    ShowWindow(hwnd, nCmdShow);

    for (;;) {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT)
                break;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        } else {
            S[0] = SIN(D[0]); S[1] = SIN(D[1]); S[2] = SIN(D[2]);
            C[0] = COS(D[0]); C[1] = COS(D[1]); C[2] = COS(D[2]);

            B[0][0] = (C[1] * C[2] << 8) + S[0] * S[1] * S[2] >> 16; B[0][1] = S[0] * S[1] * C[2] - (C[1] * S[2] << 8) >> 16; B[0][2] = C[0] * S[1] >> 8;
            B[1][0] = C[0] * S[2] >> 8; B[1][1] = C[0] * C[2] >> 8; B[1][2] = -S[0];
            B[2][0] = S[0] * C[1] * S[2] - (S[1] * C[2] << 8) >> 16; B[2][1] = (S[1] * S[2] << 8) + S[0] * C[1] * C[2] >> 16; B[2][2] = C[0] * C[1] >> 8;

            for (i = !!GetAsyncKeyState(VK_UP) | !!GetAsyncKeyState(VK_DOWN) << 1 | !!GetAsyncKeyState(VK_LEFT) << 2 | !!GetAsyncKeyState(VK_RIGHT) << 3 /* A, START */ | !!(GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT)) << 4, j = 3; j--; V[j] += (i << 31 >> 31 & B[j][2]) - (i << 30 >> 31 & B[j][2]) - (i << 29 >> 31 & B[j][0]) + (i << 28 >> 31 & B[j][0]) << (2 << (i >> 4)));
            for (i = 1 << (LOG_R << 1); i--; zbuffer[i] = 0x7fffffff);
            D2D3M(-V(0, 2), -V(0, 2), -V(1, 2), -V(1, 2), -V(2, 2), -V(2, 2), -V(3, 2), -V(3, 2), -V(4, 2), -V(4, 2), -V(5, 2), -V(5, 2), -V(6, 2), -V(6, 2), -V(7, 2), -V(7, 2), 0, 0, LOG_R, V(0, 0), V(0, 1), V(0, 2), H, O, 0);
            BitBlt(hdc, 0, 0, 1 << LOG_R, 1 << LOG_R /* 768 */, hdcm, 0, 0, SRCCOPY);
            ZeroMemory(p, 1 << (LOG_R << 1) << 2 /* 768 << 10 << 2 */);
        }
    }

    ReleaseDC(hwnd, hdc);
    SelectObject(hdcm, hbmold);
    DeleteDC(hdcm);
    DeleteObject(hbm);

    return msg.wParam;
}

short sines[] = { 0, 6, 12, 18, 25, 31, 37, 43, 49, 56, 62, 68, 74, 80, 86, 92, 97, 103, 109, 115, 120, 126, 131, 136, 142, 147, 152, 157, 162, 167, 171, 176, 181, 185, 189, 193, 197, 201, 205, 209, 212, 216, 219, 222, 225, 228, 231, 234, 236, 238, 241, 243, 244, 246, 248, 249, 251, 252, 253, 254, 254, 255, 255, 255, 256, 255, 255, 255, 254, 254, 253, 252, 251, 249, 248, 246, 244, 243, 241, 238, 236, 234, 231, 228, 225, 222, 219, 216, 212, 209, 205, 201, 197, 193, 189, 185, 181, 176, 171, 167, 162, 157, 152, 147, 142, 136, 131, 126, 120, 115, 109, 103, 97, 92, 86, 80, 74, 68, 62, 56, 49, 43, 37, 31, 25, 18, 12, 6, 0, -6, -12, -18, -25, -31, -37, -43, -49, -56, -62, -68, -74, -80, -86, -92, -97, -103, -109, -115, -120, -126, -131, -136, -142, -147, -152, -157, -162, -167, -171, -176, -181, -185, -189, -193, -197, -201, -205, -209, -212, -216, -219, -222, -225, -228, -231, -234, -236, -238, -241, -243, -244, -246, -248, -249, -251, -252, -253, -254, -254, -255, -255, -255, -256, -255, -255, -255, -254, -254, -253, -252, -251, -249, -248, -246, -244, -243, -241, -238, -236, -234, -231, -228, -225, -222, -219, -216, -212, -209, -205, -201, -197, -193, -189, -185, -181, -176, -171, -167, -162, -157, -152, -147, -142, -136, -131, -126, -120, -115, -109, -103, -97, -92, -86, -80, -74, -68, -62, -56, -49, -43, -37, -31, -25, -18, -12, -6 };

#define XR  1024
#define YR  768

int YMXR[YR];
int W[(XR * YR + 31) / 32];

#define YX  ((float)YR / (float)XR)

le(int a[], int b[])
{
    int i, j;

    for (i = 31; i >= 0; i--)
        for (j = 2; j >= 0; j--)
            if ((a[j] ^ b[j]) >> i)
                return a[j] < b[j];
    return 1;
}

#define OH  20
#define H   2

#define SBLR    7   //10
#define PTS 172974  //1024 * 1024   //6 * ((1 << SBLR) - 2) * ((1 << SBLR) - 2)

int P[PTS][4];

#define M(x, y) ((x) + (y) >> 1)    //(((x) & (y)) + (((x) ^ (y)) >> 1))

int T[PTS][4];
void sort(int P[][4], int l, int r)
{
    int i, j, k;

    if (l < r) {
        k = M(l, r);
        sort(P, l, k);
        sort(P, k + 1, r);
        for (i = k - l; i >= 0; i--)
            for (j = 0; j < 4; j++) {
                T[r - i][j] = P[k + 1 + i][j];
                T[k - i][j] = P[k - i][j];
            }
        for (k = l, j = r; k <= j; k++)
            if (le(T[l], T[r])) {
                for (i = 3; i >= 0; i--)
                    P[k][i] = T[l][i];
                l++;
            } else {
                for (i = 3; i >= 0; i--)
                    P[k][i] = T[r][i];
                r--;
            }
    }
}

#define D(i, j) (P[i][2] >> j << 2 & 0x4 | P[i][1] >> j << 1 & 0x2 | P[i][0] >> j & 0x1)

unsigned rk[256];
int /* O[(1 + H * 8) * 2], */ A[520244 * 2], Q[126553 /* 8351857 */ * 2] /*, PR[1396059 * 2] */;

unsigned O3(unsigned A[], int P[][4], unsigned Q[], unsigned n, int l, int r)
{
    int i, j, k;
    unsigned *O, *Z;

    sort(P, 0, n - 1);
    for (Z = A + 2, i = l - 1; i >= r; i--)
        for (j = 0; j < n; j++)
            for (O = A, k = l - 1; k >= i; k--) {
                if (~O[0] & 1 << D(j, k) + 24) {
                    if (!O[1])
                        O[1] = Z;
                    Z += 2;
                    O[0] |= 1 << D(j, k) + 24;
                }
                O = O[1] + (rk[O[0] >> 24 & (1 << D(j, k)) - 1] << 3);
            }
    for (i = 0; i < n; i++) {
        for (O = A, j = l - 1; j >= r; j--)
            O = O[1] + (rk[O[0] >> 24 & (1 << D(i, j)) - 1] << 3);
        O[0] = P[i][3] & (1 << 24) - 1;
        if (Q) {
            O[0] |= Q[0] & 0xff << 24;
            O[1] = Q[1];
        }
    }
    return Z - A >> 1;
}

int CL(unsigned A[], int z)
{
    if (z) {
        int i, j, k[3] = { 0 };

        for (i = 0; i < 8; i++)
            if (A[0] & 1 << i + 24) {
                j = CL(A[1] + (rk[A[0] >> 24 & (1 << i) - 1] << 3), z - 1);
                k[0] += j & 0xff, k[1] += j >> 8 & 0xff, k[2] += j >> 16;
            }
        j = rk[A[0] >> 24];
        A[0] |= k[2] / j << 16 | k[1] / j << 8 | k[0] / j;
    }
    return A[0] & (1 << 24) - 1;
}

int *p;

int V[3] = { (128 << OH) + 128,  (/* 128 */ /* 240 */ 64 << OH /* 0 */) + 128, (128 << OH) + 128 }, D[3] = { -32, -32, 0 };
int B[3][3];

int NU(int L, int U, int R, int D)
{
    int i, j;

    if (L >> 5 ^ (j = R >> 5))
        for (; U < D; U++) {
            if (-1 << (L & 0x1f) & W[YMXR[U] + L >> 5] || (1 << (R & 0x1f)) - 1 & W[YMXR[U] + R >> 5])
                return U;
            for (i = L + 32 >> 5; i < j; i++)
                if (W[YMXR[U] + (i << 5) >> 5])
                    return U;
        }
    else
        for (; U < D; U++)
            if (-1 << (L & 0x1f) & (1 << (R & 0x1f)) - 1 & W[YMXR[U] + L >> 5])
                return U;
    return -1;
}

void RC(int L, int U, int R, int D, int c)
{
    int i, j, k;

    for (i = U; i < D; i++)
        for (j = L; j < R; j++)
            if (W[(k = YMXR[i] + j) >> 5] & 1 << (k & 0x1f))
                p[YMXR[i] + j] = c;
    if (L >> 5 ^ (k = R >> 5))
        for (; U < D; U++) {
            W[YMXR[U] + L >> 5] &= (1 << (L & 0x1f)) - 1; W[YMXR[U] + R >> 5] &= -(1 << (R & 0x1f));
            for (j = L + 32 >> 5; j < k; j++)
                W[YMXR[U] + (j << 5) >> 5] = 0;
        }
    else
        for (j = (1 << (L & 0x1f)) - 1 | -(1 << (R & 0x1f)); U < D; U++)
            W[YMXR[U] + L >> 5] &= j;
}

#define ABS(x)  ((x) >> 31 ^ (x) - ((unsigned)(x) >> 31))

#define V(i, j) ((&y0)[j] + (((i) << 31 >> 31 & B[0][j]) + ((i) << 30 >> 31 & B[1][j]) + ((i) << 29 >> 31 & B[2][j]) << z))

#define V0(i)   (&y0)[i]
#define V1(i)  ((&y0)[i] + (B[0][i]                     << z))
#define V2(i)  ((&y0)[i] + (          B[1][i]           << z))
#define V3(i)  ((&y0)[i] + (B[0][i] + B[1][i]           << z))
#define V4(i)  ((&y0)[i] + (                    B[2][i] << z))
#define V5(i)  ((&y0)[i] + (B[0][i]           + B[2][i] << z))
#define V6(i)  ((&y0)[i] + (          B[1][i] + B[2][i] << z))
#define V7(i)  ((&y0)[i] + (B[0][i] + B[1][i] + B[2][i] << z))

#define Z   16
#define J   1 << Z - 1
int N = 3 << Z;

#define L(i)    (&L0)[i << 2]
#define U(i)    (&U0)[i << 2]
#define R(i)    (&R0)[i << 2]
#define D(i)    (&D0)[i << 2]

#define L8(i, j)    M(L(i), L(j))
#define U8(i, j)    M(U(i), U(j))
#define R8(i, j)    M(R(i), R(j))
#define D8(i, j)    M(D(i), D(j))

#define F(i, j) (&L0)[((i) << 2) + (j)]
#define RJ(x, y)    if ((y = NU(L8 >> Z, x, R8 >> Z, D8 >> Z)) < 0) return
#define B() ((-(i >> 1) ^ V(R[k[0]][i], i & 0x1)) < (-(i >> 1) ^ F(R[k[0]][i], i)) + (F(R[k[0]][i], (i & 0x1) + 2) - F(R[k[0]][i], i & 0x1) >> k[1]))

char R[XR][4];

void M3D2D(int L0, int U0, int R0, int D0, int L1, int U1, int R1, int D1, int L2, int U2, int R2, int D2, int L3, int U3, int R3, int D3, int L4, int U4, int R4, int D4, int L5, int U5, int R5, int D5, int L6, int U6, int R6, int D6, int L7, int U7, int R7, int D7, int L8, int U8, int R8, int D8, unsigned x0, unsigned x1, unsigned x2, int y0, int y1, int y2, int z, unsigned O[], int t)
{
    int i, j, k[2];

    for (i = 4; i--;)
        for (k[1] = 1, j = F(8, (i & 0x1) + 2) - F(8, i & 0x1); j >> k[1] >= J;) {
            k[0] = (F(8, i) + (-(i >> 1) ^ j >> k[1]) + (i >> 1) >> Z) + (i << 31 >> 31 & (XR - YR) / 2);
            if (B())
                k[1]++;
            else {
                F(8, i) += (-(i >> 1) ^ j >> k[1]) + (i >> 1);
                RJ((j = U8 >> Z) + (j - t >> 31 & t - j), t);
                for (j = 8; j--; F(j, i) += (-(i >> 1) ^ F(j, (i & 0x1) + 2) - F(j, i & 0x1) >> k[1]) + (i >> 1));
                j = F(8, (i & 0x1) + 2) - F(8, i & 0x1);
            }
        }
    if (R8 - L8 < N || D8 - U8 < N || !z) {
        if (y2 >= 0)
            RC(L8 >> Z, t, R8 >> Z, D8 >> Z, O[0] << 8 & 0xff0000 | O[0] >> 8 & 0xff00 | O[0] & 0xff);
    } else
        for (i = 7, j = x2 >> 31 << 2 | x1 >> 31 << 1 | x0 >> 31, k[0] = i ^ j; i >= 0; k[0] = --i ^ j)
            if (O[0] & 1 << k[0] + 24) {
                M3D2D(L8(k[0], 0), U8(k[0], 0), R8(k[0], 0), D8(k[0], 0), L8(k[0], 1), U8(k[0], 1), R8(k[0], 1), D8(k[0], 1), L8(k[0], 2), U8(k[0], 2), R8(k[0], 2), D8(k[0], 2), L8(k[0], 3), U8(k[0], 3), R8(k[0], 3), D8(k[0], 3), L8(k[0], 4), U8(k[0], 4), R8(k[0], 4), D8(k[0], 4), L8(k[0], 5), U8(k[0], 5), R8(k[0], 5), D8(k[0], 5), L8(k[0], 6), U8(k[0], 6), R8(k[0], 6), D8(k[0], 6), L8(k[0], 7), U8(k[0], 7), R8(k[0], 7), D8(k[0], 7), L8, U8, R8, D8, x0 + (1 - (k[0] << 1 & 0x2) << 6 + z), x1 + (1 - (k[0] & 0x2) << 6 + z), x2 + (1 - (k[0] >> 1 & 0x2) << 6 + z), y0 + ((k[0] << 31 >> 31 & B[0][0]) + (k[0] << 30 >> 31 & B[1][0]) + (k[0] << 29 >> 31 & B[2][0]) << z - 1), y1 + ((k[0] << 31 >> 31 & B[0][1]) + (k[0] << 30 >> 31 & B[1][1]) + (k[0] << 29 >> 31 & B[2][1]) << z - 1), y2 + ((k[0] << 31 >> 31 & B[0][2]) + (k[0] << 30 >> 31 & B[1][2]) + (k[0] << 29 >> 31 & B[2][2]) << z - 1), z - 1, O[1] + (rk[O[0] >> 24 & (1 << k[0]) - 1] << 3), t);
                RJ(t, t);
            }
}

void SB(int P[][4], int a)
{
    int x, y, z, i;

    for (a = (1 << a) - 1, z = (a - 1) * (a - 1), x = 1; x < a; x++)
        for (y = 1; y < a; y++)
            for (i = 3; i--; P[i * z + (x - 1) * (a - 1) + y - 1][i] = 0, P[(i + 3) * z + (x - 1) * (a - 1) + y - 1][i] = a, P[i * z + (x - 1) * (a - 1) + y - 1][(i + 1) % 3] = P[(i + 3) * z + (x - 1) * (a - 1) + y - 1][(i + 1) % 3] = x, P[i * z + (x - 1) * (a - 1) + y - 1][(i + 2) % 3] = P[(i + 3) * z + (x - 1) * (a - 1) + y - 1][(i + 2) % 3] = y, P[i * z + (x - 1) * (a - 1) + y - 1][3] = P[(i + 3) * z + (x - 1) * (a - 1) + y - 1][3] = (x ^ y) << (i << 3));
}

void PY(int P[][4], int a)
{
    int x, z;

    for (z = 0; z < 1 << a; z++)
        for (x = 0; x < 1 << a; x++) {
            P[(z << a) + x][0] = x;
            P[(z << a) + x][1] = x ^ z;
            P[(z << a) + x][2] = z;
            P[(z << a) + x][3] = z << 16 | (x ^ z & 0xff) << 8 | x & 0xff;
        }
}

#include <stdio.h>

void loadxyzrgba(char *xyzrgba, int n, float s)
{
    int i, j;
    float k;
    FILE *f;

    if (f = fopen(xyzrgba, "r")) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < 3; fscanf(f, "%f", &k), P[i][j++] = k * s);
            for (; j >= 0; fscanf(f, "%d", (char *)&P[i][3] + 3 - j--));
        }
        fclose(f);
    }
}

#include <windows.h>

HDC hdcm;
HBITMAP hbm;

POINT S;
int ESB;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;

    switch (uMsg) {
    case WM_KEYDOWN:
        switch (wParam) {
        case 'S':
            ESB = !ESB;
            break;
        case VK_SUBTRACT:
        case 'Q':
            N += 1 << Z;
            break;
        case VK_ADD:
        case 'W':
            N -= (N > 1 << Z) << Z;
            break;
        case VK_ESCAPE:
            PostMessage(hwnd, WM_DESTROY, 0, 0);
            break;
        }
        return 0;
    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        BitBlt(hdc, 0, 0, XR, YR, hdcm, 0, 0, SRCCOPY);
        EndPaint(hwnd, &ps);
        return 0;
    case WM_MOUSEMOVE:
        if (wParam & MK_LBUTTON) { D[1] -= S.x - LOWORD(lParam) >> 3; D[0] += S.y - HIWORD(lParam) >> 3; }
        S.x = LOWORD(lParam); S.y = HIWORD(lParam);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int IM(int x, int y)
{
    __asm {
        MOV     EAX, x
        IMUL    y
        SHRD    EAX, EDX, 8
    }
}

#define SIN(x)  sines[(x) & 0xff]
#define COS(x)  SIN(x + 64)

#define V(i, j) (((i << 31 >> 31 & B[0][j]) + (i << 30 >> 31 & B[1][j]) + (i << 29 >> 31 & B[2][j]) << OH) - (IM(V[0] & (256 << OH) - 1, B[0][j]) + IM(V[1] & (256 << OH) - 1, B[1][j]) + IM(V[2] & (256 << OH) - 1, B[2][j])))
#define K(i, j, k)  (((i << 31 >> 31 & B[0][j]) + (i << 30 >> 31 & B[1][j]) + (i << 29 >> 31 & B[2][j]) << k + 8) - ((128 << k) * B[0][j] + (128 << k) * B[1][j] + (128 << k) * B[2][j]) >> 8)

short U[XR][2] = { { -181, -181 }, { -181, -180 }, { -181, -180 }, { -181, -180 }, { -181, -180 }, { -181, -180 }, { -182, -179 }, { -182, -179 }, { -182, -179 }, { -182, -179 }, { -182, -179 }, { -182, -179 }, { -183, -178 }, { -183, -178 }, { -183, -178 }, { -183, -178 }, { -183, -178 }, { -184, -177 }, { -184, -177 }, { -184, -177 }, { -184, -177 }, { -184, -177 }, { -184, -177 }, { -185, -176 }, { -185, -176 }, { -185, -176 }, { -185, -176 }, { -185, -176 }, { -186, -175 }, { -186, -175 }, { -186, -175 }, { -186, -175 }, { -186, -175 }, { -186, -174 }, { -187, -174 }, { -187, -174 }, { -187, -174 }, { -187, -174 }, { -187, -173 }, { -188, -173 }, { -188, -173 }, { -188, -173 }, { -188, -173 }, { -188, -172 }, { -188, -172 }, { -189, -172 }, { -189, -172 }, { -189, -172 }, { -189, -171 }, { -189, -171 }, { -190, -171 }, { -190, -171 }, { -190, -171 }, { -190, -170 }, { -190, -170 }, { -190, -170 }, { -191, -170 }, { -191, -170 }, { -191, -169 }, { -191, -169 }, { -191, -169 }, { -192, -169 }, { -192, -169 }, { -192, -168 }, { -192, -168 }, { -192, -168 }, { -193, -168 }, { -193, -167 }, { -193, -167 }, { -193, -167 }, { -193, -167 }, { -193, -167 }, { -194, -166 }, { -194, -166 }, { -194, -166 }, { -194, -166 }, { -194, -165 }, { -195, -165 }, { -195, -165 }, { -195, -165 }, { -195, -165 }, { -195, -164 }, { -196, -164 }, { -196, -164 }, { -196, -164 }, { -196, -163 }, { -196, -163 }, { -196, -163 }, { -197, -163 }, { -197, -163 }, { -197, -162 }, { -197, -162 }, { -197, -162 }, { -198, -162 }, { -198, -161 }, { -198, -161 }, { -198, -161 }, { -198, -161 }, { -199, -160 }, { -199, -160 }, { -199, -160 }, { -199, -160 }, { -199, -160 }, { -200, -159 }, { -200, -159 }, { -200, -159 }, { -200, -159 }, { -200, -158 }, { -200, -158 }, { -201, -158 }, { -201, -158 }, { -201, -157 }, { -201, -157 }, { -201, -157 }, { -202, -157 }, { -202, -156 }, { -202, -156 }, { -202, -156 }, { -202, -156 }, { -203, -155 }, { -203, -155 }, { -203, -155 }, { -203, -155 }, { -203, -154 }, { -204, -154 }, { -204, -154 }, { -204, -154 }, { -204, -153 }, { -204, -153 }, { -204, -153 }, { -205, -153 }, { -205, -152 }, { -205, -152 }, { -205, -152 }, { -205, -152 }, { -206, -151 }, { -206, -151 }, { -206, -151 }, { -206, -151 }, { -206, -150 }, { -207, -150 }, { -207, -150 }, { -207, -149 }, { -207, -149 }, { -207, -149 }, { -208, -149 }, { -208, -148 }, { -208, -148 }, { -208, -148 }, { -208, -148 }, { -209, -147 }, { -209, -147 }, { -209, -147 }, { -209, -146 }, { -209, -146 }, { -209, -146 }, { -210, -146 }, { -210, -145 }, { -210, -145 }, { -210, -145 }, { -210, -145 }, { -211, -144 }, { -211, -144 }, { -211, -144 }, { -211, -143 }, { -211, -143 }, { -212, -143 }, { -212, -143 }, { -212, -142 }, { -212, -142 }, { -212, -142 }, { -213, -141 }, { -213, -141 }, { -213, -141 }, { -213, -141 }, { -213, -140 }, { -214, -140 }, { -214, -140 }, { -214, -139 }, { -214, -139 }, { -214, -139 }, { -214, -138 }, { -215, -138 }, { -215, -138 }, { -215, -138 }, { -215, -137 }, { -215, -137 }, { -216, -137 }, { -216, -136 }, { -216, -136 }, { -216, -136 }, { -216, -135 }, { -217, -135 }, { -217, -135 }, { -217, -135 }, { -217, -134 }, { -217, -134 }, { -218, -134 }, { -218, -133 }, { -218, -133 }, { -218, -133 }, { -218, -132 }, { -218, -132 }, { -219, -132 }, { -219, -131 }, { -219, -131 }, { -219, -131 }, { -219, -131 }, { -220, -130 }, { -220, -130 }, { -220, -130 }, { -220, -129 }, { -220, -129 }, { -221, -129 }, { -221, -128 }, { -221, -128 }, { -221, -128 }, { -221, -127 }, { -222, -127 }, { -222, -127 }, { -222, -126 }, { -222, -126 }, { -222, -126 }, { -222, -125 }, { -223, -125 }, { -223, -125 }, { -223, -124 }, { -223, -124 }, { -223, -124 }, { -224, -123 }, { -224, -123 }, { -224, -123 }, { -224, -122 }, { -224, -122 }, { -224, -122 }, { -225, -121 }, { -225, -121 }, { -225, -121 }, { -225, -120 }, { -225, -120 }, { -226, -120 }, { -226, -119 }, { -226, -119 }, { -226, -119 }, { -226, -118 }, { -226, -118 }, { -227, -118 }, { -227, -117 }, { -227, -117 }, { -227, -116 }, { -227, -116 }, { -228, -116 }, { -228, -115 }, { -228, -115 }, { -228, -115 }, { -228, -114 }, { -228, -114 }, { -229, -114 }, { -229, -113 }, { -229, -113 }, { -229, -113 }, { -229, -112 }, { -230, -112 }, { -230, -111 }, { -230, -111 }, { -230, -111 }, { -230, -110 }, { -230, -110 }, { -231, -110 }, { -231, -109 }, { -231, -109 }, { -231, -109 }, { -231, -108 }, { -231, -108 }, { -232, -107 }, { -232, -107 }, { -232, -107 }, { -232, -106 }, { -232, -106 }, { -233, -106 }, { -233, -105 }, { -233, -105 }, { -233, -104 }, { -233, -104 }, { -233, -104 }, { -234, -103 }, { -234, -103 }, { -234, -102 }, { -234, -102 }, { -234, -102 }, { -234, -101 }, { -235, -101 }, { -235, -101 }, { -235, -100 }, { -235, -100 }, { -235, -99 }, { -235, -99 }, { -236, -99 }, { -236, -98 }, { -236, -98 }, { -236, -97 }, { -236, -97 }, { -236, -97 }, { -237, -96 }, { -237, -96 }, { -237, -95 }, { -237, -95 }, { -237, -95 }, { -237, -94 }, { -237, -94 }, { -238, -93 }, { -238, -93 }, { -238, -93 }, { -238, -92 }, { -238, -92 }, { -238, -91 }, { -239, -91 }, { -239, -91 }, { -239, -90 }, { -239, -90 }, { -239, -89 }, { -239, -89 }, { -240, -89 }, { -240, -88 }, { -240, -88 }, { -240, -87 }, { -240, -87 }, { -240, -86 }, { -240, -86 }, { -241, -86 }, { -241, -85 }, { -241, -85 }, { -241, -84 }, { -241, -84 }, { -241, -84 }, { -241, -83 }, { -242, -83 }, { -242, -82 }, { -242, -82 }, { -242, -81 }, { -242, -81 }, { -242, -81 }, { -242, -80 }, { -243, -80 }, { -243, -79 }, { -243, -79 }, { -243, -78 }, { -243, -78 }, { -243, -78 }, { -243, -77 }, { -244, -77 }, { -244, -76 }, { -244, -76 }, { -244, -75 }, { -244, -75 }, { -244, -75 }, { -244, -74 }, { -245, -74 }, { -245, -73 }, { -245, -73 }, { -245, -72 }, { -245, -72 }, { -245, -71 }, { -245, -71 }, { -245, -71 }, { -246, -70 }, { -246, -70 }, { -246, -69 }, { -246, -69 }, { -246, -68 }, { -246, -68 }, { -246, -67 }, { -246, -67 }, { -247, -67 }, { -247, -66 }, { -247, -66 }, { -247, -65 }, { -247, -65 }, { -247, -64 }, { -247, -64 }, { -247, -63 }, { -248, -63 }, { -248, -63 }, { -248, -62 }, { -248, -62 }, { -248, -61 }, { -248, -61 }, { -248, -60 }, { -248, -60 }, { -248, -59 }, { -249, -59 }, { -249, -58 }, { -249, -58 }, { -249, -57 }, { -249, -57 }, { -249, -57 }, { -249, -56 }, { -249, -56 }, { -249, -55 }, { -249, -55 }, { -250, -54 }, { -250, -54 }, { -250, -53 }, { -250, -53 }, { -250, -52 }, { -250, -52 }, { -250, -51 }, { -250, -51 }, { -250, -50 }, { -250, -50 }, { -251, -50 }, { -251, -49 }, { -251, -49 }, { -251, -48 }, { -251, -48 }, { -251, -47 }, { -251, -47 }, { -251, -46 }, { -251, -46 }, { -251, -45 }, { -251, -45 }, { -252, -44 }, { -252, -44 }, { -252, -43 }, { -252, -43 }, { -252, -42 }, { -252, -42 }, { -252, -41 }, { -252, -41 }, { -252, -40 }, { -252, -40 }, { -252, -40 }, { -252, -39 }, { -253, -39 }, { -253, -38 }, { -253, -38 }, { -253, -37 }, { -253, -37 }, { -253, -36 }, { -253, -36 }, { -253, -35 }, { -253, -35 }, { -253, -34 }, { -253, -34 }, { -253, -33 }, { -253, -33 }, { -253, -32 }, { -253, -32 }, { -254, -31 }, { -254, -31 }, { -254, -30 }, { -254, -30 }, { -254, -29 }, { -254, -29 }, { -254, -28 }, { -254, -28 }, { -254, -27 }, { -254, -27 }, { -254, -26 }, { -254, -26 }, { -254, -25 }, { -254, -25 }, { -254, -24 }, { -254, -24 }, { -254, -23 }, { -254, -23 }, { -254, -22 }, { -255, -22 }, { -255, -21 }, { -255, -21 }, { -255, -20 }, { -255, -20 }, { -255, -19 }, { -255, -19 }, { -255, -18 }, { -255, -18 }, { -255, -17 }, { -255, -17 }, { -255, -16 }, { -255, -16 }, { -255, -15 }, { -255, -15 }, { -255, -14 }, { -255, -14 }, { -255, -13 }, { -255, -13 }, { -255, -12 }, { -255, -12 }, { -255, -11 }, { -255, -11 }, { -255, -10 }, { -255, -10 }, { -255, -9 }, { -255, -9 }, { -255, -8 }, { -255, -8 }, { -255, -7 }, { -255, -7 }, { -255, -6 }, { -255, -6 }, { -255, -5 }, { -255, -5 }, { -255, -4 }, { -255, -4 }, { -255, -3 }, { -255, -3 }, { -255, -2 }, { -255, -2 }, { -255, -1 }, { -255, -1 }, { -255, 0 }, { -255, 0 }, { -256, 0 }, { -255, 0 }, { -255, 0 }, { -255, 1 }, { -255, 1 }, { -255, 2 }, { -255, 2 }, { -255, 3 }, { -255, 3 }, { -255, 4 }, { -255, 4 }, { -255, 5 }, { -255, 5 }, { -255, 6 }, { -255, 6 }, { -255, 7 }, { -255, 7 }, { -255, 8 }, { -255, 8 }, { -255, 9 }, { -255, 9 }, { -255, 10 }, { -255, 10 }, { -255, 11 }, { -255, 11 }, { -255, 12 }, { -255, 12 }, { -255, 13 }, { -255, 13 }, { -255, 14 }, { -255, 14 }, { -255, 15 }, { -255, 15 }, { -255, 16 }, { -255, 16 }, { -255, 17 }, { -255, 17 }, { -255, 18 }, { -255, 18 }, { -255, 19 }, { -255, 19 }, { -255, 20 }, { -255, 20 }, { -255, 21 }, { -255, 21 }, { -255, 22 }, { -254, 22 }, { -254, 23 }, { -254, 23 }, { -254, 24 }, { -254, 24 }, { -254, 25 }, { -254, 25 }, { -254, 26 }, { -254, 26 }, { -254, 27 }, { -254, 27 }, { -254, 28 }, { -254, 28 }, { -254, 29 }, { -254, 29 }, { -254, 30 }, { -254, 30 }, { -254, 31 }, { -254, 31 }, { -253, 32 }, { -253, 32 }, { -253, 33 }, { -253, 33 }, { -253, 34 }, { -253, 34 }, { -253, 35 }, { -253, 35 }, { -253, 36 }, { -253, 36 }, { -253, 37 }, { -253, 37 }, { -253, 38 }, { -253, 38 }, { -253, 39 }, { -252, 39 }, { -252, 40 }, { -252, 40 }, { -252, 40 }, { -252, 41 }, { -252, 41 }, { -252, 42 }, { -252, 42 }, { -252, 43 }, { -252, 43 }, { -252, 44 }, { -252, 44 }, { -251, 45 }, { -251, 45 }, { -251, 46 }, { -251, 46 }, { -251, 47 }, { -251, 47 }, { -251, 48 }, { -251, 48 }, { -251, 49 }, { -251, 49 }, { -251, 50 }, { -250, 50 }, { -250, 50 }, { -250, 51 }, { -250, 51 }, { -250, 52 }, { -250, 52 }, { -250, 53 }, { -250, 53 }, { -250, 54 }, { -250, 54 }, { -249, 55 }, { -249, 55 }, { -249, 56 }, { -249, 56 }, { -249, 57 }, { -249, 57 }, { -249, 57 }, { -249, 58 }, { -249, 58 }, { -249, 59 }, { -248, 59 }, { -248, 60 }, { -248, 60 }, { -248, 61 }, { -248, 61 }, { -248, 62 }, { -248, 62 }, { -248, 63 }, { -248, 63 }, { -247, 63 }, { -247, 64 }, { -247, 64 }, { -247, 65 }, { -247, 65 }, { -247, 66 }, { -247, 66 }, { -247, 67 }, { -246, 67 }, { -246, 67 }, { -246, 68 }, { -246, 68 }, { -246, 69 }, { -246, 69 }, { -246, 70 }, { -246, 70 }, { -245, 71 }, { -245, 71 }, { -245, 71 }, { -245, 72 }, { -245, 72 }, { -245, 73 }, { -245, 73 }, { -245, 74 }, { -244, 74 }, { -244, 75 }, { -244, 75 }, { -244, 75 }, { -244, 76 }, { -244, 76 }, { -244, 77 }, { -243, 77 }, { -243, 78 }, { -243, 78 }, { -243, 78 }, { -243, 79 }, { -243, 79 }, { -243, 80 }, { -242, 80 }, { -242, 81 }, { -242, 81 }, { -242, 81 }, { -242, 82 }, { -242, 82 }, { -242, 83 }, { -241, 83 }, { -241, 84 }, { -241, 84 }, { -241, 84 }, { -241, 85 }, { -241, 85 }, { -241, 86 }, { -240, 86 }, { -240, 86 }, { -240, 87 }, { -240, 87 }, { -240, 88 }, { -240, 88 }, { -240, 89 }, { -239, 89 }, { -239, 89 }, { -239, 90 }, { -239, 90 }, { -239, 91 }, { -239, 91 }, { -238, 91 }, { -238, 92 }, { -238, 92 }, { -238, 93 }, { -238, 93 }, { -238, 93 }, { -237, 94 }, { -237, 94 }, { -237, 95 }, { -237, 95 }, { -237, 95 }, { -237, 96 }, { -237, 96 }, { -236, 97 }, { -236, 97 }, { -236, 97 }, { -236, 98 }, { -236, 98 }, { -236, 99 }, { -235, 99 }, { -235, 99 }, { -235, 100 }, { -235, 100 }, { -235, 101 }, { -235, 101 }, { -234, 101 }, { -234, 102 }, { -234, 102 }, { -234, 102 }, { -234, 103 }, { -234, 103 }, { -233, 104 }, { -233, 104 }, { -233, 104 }, { -233, 105 }, { -233, 105 }, { -233, 106 }, { -232, 106 }, { -232, 106 }, { -232, 107 }, { -232, 107 }, { -232, 107 }, { -231, 108 }, { -231, 108 }, { -231, 109 }, { -231, 109 }, { -231, 109 }, { -231, 110 }, { -230, 110 }, { -230, 110 }, { -230, 111 }, { -230, 111 }, { -230, 111 }, { -230, 112 }, { -229, 112 }, { -229, 113 }, { -229, 113 }, { -229, 113 }, { -229, 114 }, { -228, 114 }, { -228, 114 }, { -228, 115 }, { -228, 115 }, { -228, 115 }, { -228, 116 }, { -227, 116 }, { -227, 116 }, { -227, 117 }, { -227, 117 }, { -227, 118 }, { -226, 118 }, { -226, 118 }, { -226, 119 }, { -226, 119 }, { -226, 119 }, { -226, 120 }, { -225, 120 }, { -225, 120 }, { -225, 121 }, { -225, 121 }, { -225, 121 }, { -224, 122 }, { -224, 122 }, { -224, 122 }, { -224, 123 }, { -224, 123 }, { -224, 123 }, { -223, 124 }, { -223, 124 }, { -223, 124 }, { -223, 125 }, { -223, 125 }, { -222, 125 }, { -222, 126 }, { -222, 126 }, { -222, 126 }, { -222, 127 }, { -222, 127 }, { -221, 127 }, { -221, 128 }, { -221, 128 }, { -221, 128 }, { -221, 129 }, { -220, 129 }, { -220, 129 }, { -220, 130 }, { -220, 130 }, { -220, 130 }, { -219, 131 }, { -219, 131 }, { -219, 131 }, { -219, 131 }, { -219, 132 }, { -218, 132 }, { -218, 132 }, { -218, 133 }, { -218, 133 }, { -218, 133 }, { -218, 134 }, { -217, 134 }, { -217, 134 }, { -217, 135 }, { -217, 135 }, { -217, 135 }, { -216, 135 }, { -216, 136 }, { -216, 136 }, { -216, 136 }, { -216, 137 }, { -215, 137 }, { -215, 137 }, { -215, 138 }, { -215, 138 }, { -215, 138 }, { -214, 138 }, { -214, 139 }, { -214, 139 }, { -214, 139 }, { -214, 140 }, { -214, 140 }, { -213, 140 }, { -213, 141 }, { -213, 141 }, { -213, 141 }, { -213, 141 }, { -212, 142 }, { -212, 142 }, { -212, 142 }, { -212, 143 }, { -212, 143 }, { -211, 143 }, { -211, 143 }, { -211, 144 }, { -211, 144 }, { -211, 144 }, { -210, 145 }, { -210, 145 }, { -210, 145 }, { -210, 145 }, { -210, 146 }, { -209, 146 }, { -209, 146 }, { -209, 146 }, { -209, 147 }, { -209, 147 }, { -209, 147 }, { -208, 148 }, { -208, 148 }, { -208, 148 }, { -208, 148 }, { -208, 149 }, { -207, 149 }, { -207, 149 }, { -207, 149 }, { -207, 150 }, { -207, 150 }, { -206, 150 }, { -206, 151 }, { -206, 151 }, { -206, 151 }, { -206, 151 }, { -205, 152 }, { -205, 152 }, { -205, 152 }, { -205, 152 }, { -205, 153 }, { -204, 153 }, { -204, 153 }, { -204, 153 }, { -204, 154 }, { -204, 154 }, { -204, 154 }, { -203, 154 }, { -203, 155 }, { -203, 155 }, { -203, 155 }, { -203, 155 }, { -202, 156 }, { -202, 156 }, { -202, 156 }, { -202, 156 }, { -202, 157 }, { -201, 157 }, { -201, 157 }, { -201, 157 }, { -201, 158 }, { -201, 158 }, { -200, 158 }, { -200, 158 }, { -200, 159 }, { -200, 159 }, { -200, 159 }, { -200, 159 }, { -199, 160 }, { -199, 160 }, { -199, 160 }, { -199, 160 }, { -199, 160 }, { -198, 161 }, { -198, 161 }, { -198, 161 }, { -198, 161 }, { -198, 162 }, { -197, 162 }, { -197, 162 }, { -197, 162 }, { -197, 163 }, { -197, 163 }, { -196, 163 }, { -196, 163 }, { -196, 163 }, { -196, 164 }, { -196, 164 }, { -196, 164 }, { -195, 164 }, { -195, 165 }, { -195, 165 }, { -195, 165 }, { -195, 165 }, { -194, 165 }, { -194, 166 }, { -194, 166 }, { -194, 166 }, { -194, 166 }, { -193, 167 }, { -193, 167 }, { -193, 167 }, { -193, 167 }, { -193, 167 }, { -193, 168 }, { -192, 168 }, { -192, 168 }, { -192, 168 }, { -192, 169 }, { -192, 169 }, { -191, 169 }, { -191, 169 }, { -191, 169 }, { -191, 170 }, { -191, 170 }, { -190, 170 }, { -190, 170 }, { -190, 170 }, { -190, 171 }, { -190, 171 }, { -190, 171 }, { -189, 171 }, { -189, 171 }, { -189, 172 }, { -189, 172 }, { -189, 172 }, { -188, 172 }, { -188, 172 }, { -188, 173 }, { -188, 173 }, { -188, 173 }, { -188, 173 }, { -187, 173 }, { -187, 174 }, { -187, 174 }, { -187, 174 }, { -187, 174 }, { -186, 174 }, { -186, 175 }, { -186, 175 }, { -186, 175 }, { -186, 175 }, { -186, 175 }, { -185, 176 }, { -185, 176 }, { -185, 176 }, { -185, 176 }, { -185, 176 }, { -184, 177 }, { -184, 177 }, { -184, 177 }, { -184, 177 }, { -184, 177 }, { -184, 177 }, { -183, 178 }, { -183, 178 }, { -183, 178 }, { -183, 178 }, { -183, 178 }, { -182, 179 }, { -182, 179 }, { -182, 179 }, { -182, 179 }, { -182, 179 }, { -182, 179 }, { -181, 180 }, { -181, 180 }, { -181, 180 }, { -181, 180 }, { -181, 180 } };

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASS wc;
    HWND hwnd;
    MSG msg;
    BITMAPINFO bmi;
    HBITMAP hbmold;
    RECT rec, rect;
    HDC hdc;

    int SC[2][3], CS[2];
    int i, j, k;

    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = NULL;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WindowProc;
    wc.lpszClassName = "M3D2D";
    wc.lpszMenuName = NULL;
    wc.style = 0;

    if (!RegisterClass(&wc))
        return 0;
    if (!(hwnd = CreateWindow("M3D2D", "M3D2D", WS_MINIMIZEBOX | WS_SYSMENU, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL)))
        return 0;

    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biWidth = XR;
    bmi.bmiHeader.biHeight = -YR;
    bmi.bmiHeader.biCompression = BI_RGB;

    GetWindowRect(hwnd, &rec);
    GetClientRect(hwnd, &rect);
    rec.right = rect.left - rec.left + XR + rec.right - rect.right;
    rec.bottom = rect.top - rec.top + YR + rec.bottom - rect.bottom;
    MoveWindow(hwnd, rec.left, rec.top, rec.right, rec.bottom, 0);

    hdc = GetDC(hwnd);
    hbm = CreateDIBSection(hdc, &bmi, DIB_RGB_COLORS, &p, NULL, 0);
    hdcm = CreateCompatibleDC(hdc);
    hbmold = SelectObject(hdcm, hbm);

    loadxyzrgba("armadillo", /* PTS */ 172974, -(1732 /* >> H */));
    for (SC[1][i = 0] = SC[1][1] = SC[1][2] = (1 << 31) - 1, SC[0][0] = SC[0][1] = SC[0][2] = -1 << 31; i < /* PTS */ 172974; i++)
        for (j = 3; j--;) {
            if (P[i][j] < SC[1][j])
                SC[1][j] = P[i][j];
//            if (P[i][j] > SC[0][j])
//                SC[0][j] = P[i][j];
        }
    for (i = 0; i < /* PTS */ 172974; i++)
        for (j = 3; j--;)
            P[i][j] -= SC[1][j];    //M(SC[1][j], SC[0][j]);

    for (i = 256; i--;)
        for (j = i; j; rk[i]++, j &= j - 1);

/*
    for (O[0] = 0xff << 24, O[1] = &O[k = 2], i = H - 1; i > 0; i--, k += 8 * 2)
        for (j = 0; j < 8; O[k + (j << 1)] = 0xff << 24, O[k + (j << 1) + 1] = &O[k + 8 * 2], j++);
*/
    O3(A, P, /* O */ A, /* PTS */ 172974, /* 10 - H */ 18, 8);
/*
    PY(P, 8);
    O3(PR, P, A, 256 * 256, 8, 0);
    CL(PR, 8);
*/
//    for (j = 0; j < 8; O[k + (j << 1)] = /* A[0] */ PR[0], O[k + (j << 1) + 1] = /* A[1] */ PR[1], j++);

    CL(/* O */ A, 10);
//    CL(O, H);

    SB(P, SBLR);
    O3(Q, P, 0, 6 * ((1 << SBLR) - 2) * ((1 << SBLR) - 2), SBLR, 0);
    CL(Q, SBLR);

    for (i = YR; i--; YMXR[i] = i * XR);

    ShowWindow(hwnd, nCmdShow);

    for (;;) {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT)
                break;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        } else {
            SC[0][0] = SIN(D[0]); SC[0][1] = SIN(D[1]); SC[0][2] = SIN(D[2]);
            SC[1][0] = COS(D[0]); SC[1][1] = COS(D[1]); SC[1][2] = COS(D[2]);

            B[0][0] = (SC[1][1] * SC[1][2] << 8) + SC[0][0] * SC[0][1] * SC[0][2] >> 16; B[0][1] = SC[0][0] * SC[0][1] * SC[1][2] - (SC[1][1] * SC[0][2] << 8) >> 16; B[0][2] = SC[1][0] * SC[0][1] >> 8;
            B[1][0] = SC[1][0] * SC[0][2] >> 8; B[1][1] = SC[1][0] * SC[1][2] >> 8; B[1][2] = -SC[0][0];
            B[2][0] = SC[0][0] * SC[1][1] * SC[0][2] - (SC[0][1] * SC[1][2] << 8) >> 16; B[2][1] = (SC[0][1] * SC[0][2] << 8) + SC[0][0] * SC[1][1] * SC[1][2] >> 16; B[2][2] = SC[1][0] * SC[1][1] >> 8;

//            for (i = !!GetAsyncKeyState(VK_UP) | !!GetAsyncKeyState(VK_DOWN) << 1 | !!GetAsyncKeyState(VK_LEFT) << 2 | !!GetAsyncKeyState(VK_RIGHT) << 3 /* A, START */ | !!(GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT)) << 4, j = 3; j--; V[j] += (i << 31 >> 31 & B[j][2]) - (i << 30 >> 31 & B[j][2]) - (i << 29 >> 31 & B[j][0]) + (i << 28 >> 31 & B[j][0]) << (i >> 4 << 2));
            for (i = !!GetAsyncKeyState(VK_UP) | !!GetAsyncKeyState(VK_DOWN) << 1 | !!GetAsyncKeyState(VK_LEFT) << 2 | !!GetAsyncKeyState(VK_RIGHT) << 3 /* A, START */ | !!(GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT)) << 4 | !!(GetAsyncKeyState(VK_LCONTROL) | GetAsyncKeyState(VK_RCONTROL)) << 5, j = 3; j--; V[j] += (i << 31 >> 31 & B[j][2]) - (i << 30 >> 31 & B[j][2]) - (i << 29 >> 31 & B[j][0]) + (i << 28 >> 31 & B[j][0]) << (i >> 4 << 2) >> 5);

            memset(W, 0xff, (XR * YR + 31) / 32 * 4);

            for (i = XR; i--;)
                for (j = 2; j--; R[i][j + 2] = (unsigned)B[2][j] * U[i][0] + B[2][2] * U[i][1] >> 31 << 2 | (unsigned)B[1][j] * U[i][0] + B[1][2] * U[i][1] >> 31 << 1 | (unsigned)B[0][j] * U[i][0] + B[0][2] * U[i][1] >> 31, R[i][j] = R[i][j + 2] ^ 0x7);

            M3D2D(-V(0, 2), -V(0, 2) * YX, V(0, 2), V(0, 2) * YX, -V(1, 2), -V(1, 2) * YX, V(1, 2), V(1, 2) * YX, -V(2, 2), -V(2, 2) * YX, V(2, 2), V(2, 2) * YX, -V(3, 2), -V(3, 2) * YX, V(3, 2), V(3, 2) * YX, -V(4, 2), -V(4, 2) * YX, V(4, 2), V(4, 2) * YX, -V(5, 2), -V(5, 2) * YX, V(5, 2), V(5, 2) * YX, -V(6, 2), -V(6, 2) * YX, V(6, 2), V(6, 2) * YX, -V(7, 2), -V(7, 2) * YX, V(7, 2), V(7, 2) * YX, 0, 0, XR << Z, YR << Z, V[0] - (128 << OH), V[1] - (128 << OH), V[2] - (128 << OH), V(0, 0), V(0, 1), V(0, 2), OH, /* O */ A /* PR */, 0 /*, 0 */);
            if (ESB)
                if ((i = NU(0, 0, XR, YR)) >= 0)
                    M3D2D(-K(0, 2, SBLR), -K(0, 2, SBLR) * YX, K(0, 2, SBLR), K(0, 2, SBLR) * YX, -K(1, 2, SBLR), -K(1, 2, SBLR) * YX, K(1, 2, SBLR), K(1, 2, SBLR) * YX, -K(2, 2, SBLR), -K(2, 2, SBLR) * YX, K(2, 2, SBLR), K(2, 2, SBLR) * YX, -K(3, 2, SBLR), -K(3, 2, SBLR) * YX, K(3, 2, SBLR), K(3, 2, SBLR) * YX, -K(4, 2, SBLR), -K(4, 2, SBLR) * YX, K(4, 2, SBLR), K(4, 2, SBLR) * YX, -K(5, 2, SBLR), -K(5, 2, SBLR) * YX, K(5, 2, SBLR), K(5, 2, SBLR) * YX, -K(6, 2, SBLR), -K(6, 2, SBLR) * YX, K(6, 2, SBLR), K(6, 2, SBLR) * YX, -K(7, 2, SBLR), -K(7, 2, SBLR) * YX, K(7, 2, SBLR), K(7, 2, SBLR) * YX, 0, 0, XR << Z, YR << Z, 0, 0, 0, K(0, 0, SBLR), K(0, 1, SBLR), K(0, 2, SBLR), SBLR, Q, i /*, 0 */);

            BitBlt(hdc, 0, 0, XR, YR, hdcm, 0, 0, SRCCOPY);
            ZeroMemory(p, XR * YR * 4);
        }
    }

    ReleaseDC(hwnd, hdc);
    SelectObject(hdcm, hbmold);
    DeleteDC(hdcm);
    DeleteObject(hbm);

    return msg.wParam;
}
