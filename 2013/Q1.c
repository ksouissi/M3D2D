/*	2011-13, made in Tunisia */

short sines[] = { 0, 6, 12, 18, 25, 31, 37, 43, 49, 56, 62, 68, 74, 80, 86, 92, 97, 103, 109, 115, 120, 126, 131, 136, 142, 147, 152, 157, 162, 167, 171, 176, 181, 185, 189, 193, 197, 201, 205, 209, 212, 216, 219, 222, 225, 228, 231, 234, 236, 238, 241, 243, 244, 246, 248, 249, 251, 252, 253, 254, 254, 255, 255, 255, 256, 255, 255, 255, 254, 254, 253, 252, 251, 249, 248, 246, 244, 243, 241, 238, 236, 234, 231, 228, 225, 222, 219, 216, 212, 209, 205, 201, 197, 193, 189, 185, 181, 176, 171, 167, 162, 157, 152, 147, 142, 136, 131, 126, 120, 115, 109, 103, 97, 92, 86, 80, 74, 68, 62, 56, 49, 43, 37, 31, 25, 18, 12, 6, 0, -6, -12, -18, -25, -31, -37, -43, -49, -56, -62, -68, -74, -80, -86, -92, -97, -103, -109, -115, -120, -126, -131, -136, -142, -147, -152, -157, -162, -167, -171, -176, -181, -185, -189, -193, -197, -201, -205, -209, -212, -216, -219, -222, -225, -228, -231, -234, -236, -238, -241, -243, -244, -246, -248, -249, -251, -252, -253, -254, -254, -255, -255, -255, -256, -255, -255, -255, -254, -254, -253, -252, -251, -249, -248, -246, -244, -243, -241, -238, -236, -234, -231, -228, -225, -222, -219, -216, -212, -209, -205, -201, -197, -193, -189, -185, -181, -176, -171, -167, -162, -157, -152, -147, -142, -136, -131, -126, -120, -115, -109, -103, -97, -92, -86, -80, -74, -68, -62, -56, -49, -43, -37, -31, -25, -18, -12, -6 };

le(int a[], int b[])
{
    int i, j;

    for (i = 31; i >= 0; i--)
        for (j = 2; j >= 0; j--)
            if ((a[j] ^ b[j]) >> i)
                return a[j] < b[j];
    return 1;
}

#define DIR(x, y, z, t) (x >> t & 0x1 | y >> t << 1 & 0x2 | z >> t << 2 & 0x4)

#define OH  20
#define H   10

#define PTS 172974
#define OC3 (373380 + OH - 10)

int t[PTS][4];
int octrees[OC3 * 9], *z8;

/* 0) sort, 1) merge = Z */

void merge(int t[][4], int n, int octree[], int l, int r)
{
    int i, j, *k;

    for (i = 0; i < n; i++) {
        k = octree;
        for (j = l - 1; j >= r; j--) {
            if (!k[DIR(t[i][0], t[i][1], t[i][2], j)]) {
                z8 += 9;
                k[DIR(t[i][0], t[i][1], t[i][2], j)] = z8;
            }
            k = k[DIR(t[i][0], t[i][1], t[i][2], j)];
        }
        k[8] = t[i][3];
    }
}

#define M(x, y)	((x) + (y) >> 1)	/* ((x & y) + ((x ^ y) >> 1)) */

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

#define R(x)    (x >> 16)
#define G(x)    (x >> 8 & 0xff)
#define B(x)    (x & 0xff)

color(int octree[])
{
    int i, j, k[8];

    if (octree) {
        for (i = 7, j = 0; i >= 0; i--) {
            j |= !!octree[i] << i;
            j += !!octree[i] << 8;
        }
        if (j) {
            for (i = 7; i >= 0; i--)
                k[i] = color(octree[i]);
            octree[8] = ((j << 31 >> 31 & B(k[0])) + (j << 30 >> 31 & B(k[1])) + (j << 29 >> 31 & B(k[2])) + (j << 28 >> 31 & B(k[3])) + (j << 27 >> 31 & B(k[4])) + (j << 26 >> 31 & B(k[5])) + (j << 25 >> 31 & B(k[6])) + (j << 24 >> 31 & B(k[7]))) / (j >> 8)      |
                        ((j << 31 >> 31 & G(k[0])) + (j << 30 >> 31 & G(k[1])) + (j << 29 >> 31 & G(k[2])) + (j << 28 >> 31 & G(k[3])) + (j << 27 >> 31 & G(k[4])) + (j << 26 >> 31 & G(k[5])) + (j << 25 >> 31 & G(k[6])) + (j << 24 >> 31 & G(k[7]))) / (j >> 8) << 8 |
                        ((j << 31 >> 31 & R(k[0])) + (j << 30 >> 31 & R(k[1])) + (j << 29 >> 31 & R(k[2])) + (j << 28 >> 31 & R(k[3])) + (j << 27 >> 31 & R(k[4])) + (j << 26 >> 31 & R(k[5])) + (j << 25 >> 31 & R(k[6])) + (j << 24 >> 31 & R(k[7]))) / (j >> 8) << 16;
        }
        return octree[8];
    }
    return 0;
}

#define LOG_R   10

/* Q (rectangles) test, PURE */

#define QS  (((1 << (LOG_R + 2 + 1 << 1)) - 1) / 3 + 3 + 31) / 32
#define QR()	/* quadtrees[0] = 0xe00070, quadtrees[9] = 0xcc, ZeroMemory(quadtrees + 10, QS - 10 << 2) */	quadtrees[0] = 0xe00070, ZeroMemory(quadtrees + 1, QS - 1 << 2)

#define ABS(x)  (x >> 31 ^ x - ((unsigned)x >> 31))
#define O_  ((256 << z) - 256 <= /* ABS(y0) + ABS(y1) + ABS(y2) */ y2 >> LOG_R - 1) /* G[8][2][0] - G[8][0][0] <= 2 || G[8][3][0] - G[8][1][0] <= 2 || !z */

int quadtrees[QS];

#define B(x)    quadtrees[x >> 5] |= 0x1 << (x & 0x1f)
#define NW(x)   (quadtrees[x >> 5] & 0x1 << (x & 0x1f))
#define CW(x)   (~quadtrees[QC(x, 0) >> 5] & 0xf << (QC(x, 0) & 0x1f))
#define ACB(x)  !CW(x)

#define QF(x)   (x >> 2) + 2
#define QC(x, y)    (x - 2 << 2) + y

int *p;

int V[3] = { (256 << OH - 1) + 128, (496 /* 256 */ << OH - 1) + 128, (256 << OH - 1) + 128 };
int D[3] = { -32, -32, 0 }, B[3][3];

#define L(i)    (&L0)[i << 2]
#define U(i)    (&U0)[i << 2]
#define R(i)    (&R0)[i << 2]
#define D(i)    (&D0)[i << 2]

#define L4(i, j)    ~j << 31 >> 31 & L##i | j << 31 >> 31 & M(L##i, R##i)
#define U4(i, j)    ~j << 30 >> 31 & U##i | j << 30 >> 31 & M(U##i, D##i)
#define R4(i, j)    j << 31 >> 31 & R##i | ~j << 31 >> 31 & M(L##i, R##i)
#define D4(i, j)    j << 30 >> 31 & D##i | ~j << 30 >> 31 & M(U##i, D##i)

#define L8(i, j)    M(L(i), L(j))
#define U8(i, j)    M(U(i), U(j))
#define R8(i, j)    M(R(i), R(j))
#define D8(i, j)    M(D(i), D(j))

#define V(i, j) ((&y0)[j] + ((i << 31 >> 31 & B[0][j]) + (i << 30 >> 31 & B[1][j]) + (i << 29 >> 31 & B[2][j]) << z))

int NR(int L, int U, int R, int D, int x, int y, int z, unsigned Q)
{
    int i;

    if (NW(Q) || x >= R || y >= D || x + (1 << z) <= L || y + (1 << z) <= U)
        return 0;
    if (x < L || y < U || x + (1 << z) > R || y + (1 << z) > D) {
        for (i = 3; i >= 0; i--)
            if (NR(L, U, R, D, x + ((i & 0x1) << z - 1), y + (i >> 1 << z - 1), z - 1, QC(Q, i)))
                return 1;
        return 0;
    }
    return 1;
}

#define MIN(x, y)	(-((x) < (y)) & (x) | -((y) <= (x)) & (y))
#define MAX(x, y)	(-((x) > (y)) & (x) | -((y) >= (x)) & (y))

void RC(int L, int U, int R, int D, int x, int y, int z, unsigned Q, int c)
{
    int i, j;

    if (x < L || y < U || x + (1 << z) > R || y + (1 << z) > D) {
        for (i = 3; i >= 0; i--)
            if (!NW(QC(Q, i)) && x + ((i & 0x1) << z - 1) < R && y + (i >> 1 << z - 1) < D && x + (1 << z - (~i & 0x1)) > L && y + (1 << z - (~i >> 1 & 0x1)) > U)
                RC(L, U, R, D, x + ((i & 0x1) << z - 1), y + (i >> 1 << z - 1), z - 1, QC(Q, i), c);
        quadtrees[Q >> 5] |= ACB(Q) << (Q & 0x1f);
    } else
        for (y -= (1 << LOG_R << 1), x -= (1 << LOG_R << 1), i = MAX(0, y), B(Q); i < MIN(y + (1 << z), 1 << LOG_R); i++)
            for (j = MAX(0, x); j < MIN(x + (1 << z), 1 << LOG_R); j++)
                p[(i << LOG_R) + j] = -!p[(i << LOG_R) + j] & c | p[(i << LOG_R) + j];
}

#define DIR0(i) (G[8][1][0] >> i - 1 << 1 & 0x2 | G[8][0][0] >> i - 1 & 0x1)
#define DIR1(i) (G[8][1][0] >> i - 1 << 1 & 0x2 | G[8][2][0] - 1 >> i - 1 & 0x1)
#define DIR2(i) (G[8][3][0] - 1 >> i - 1 << 1 & 0x2 | G[8][0][0] >> i - 1 & 0x1)
#define DIR3(i) (G[8][3][0] - 1 >> i - 1 << 1 & 0x2 | G[8][2][0] - 1 >> i - 1 & 0x1)

#define N(j)	(j << 30 >> 31 ^ V(0, j & 0x1)) < (j << 30 >> 31 ^ M(G[0][j][0], G[0][j][1])) || (j << 30 >> 31 ^ V(1, j & 0x1)) < (j << 30 >> 31 ^ M(G[1][j][0], G[1][j][1])) || (j << 30 >> 31 ^ V(2, j & 0x1)) < (j << 30 >> 31 ^ M(G[2][j][0], G[2][j][1])) || (j << 30 >> 31 ^ V(3, j & 0x1)) < (j << 30 >> 31 ^ M(G[3][j][0], G[3][j][1])) || (j << 30 >> 31 ^ V(4, j & 0x1)) < (j << 30 >> 31 ^ M(G[4][j][0], G[4][j][1])) || (j << 30 >> 31 ^ V(5, j & 0x1)) < (j << 30 >> 31 ^ M(G[5][j][0], G[5][j][1])) || (j << 30 >> 31 ^ V(6, j & 0x1)) < (j << 30 >> 31 ^ M(G[6][j][0], G[6][j][1])) || (j << 30 >> 31 ^ V(7, j & 0x1)) < (j << 30 >> 31 ^ M(G[7][j][0], G[7][j][1]))

void M3D2D(int L0, int U0, int R0, int D0, int L1, int U1, int R1, int D1, int L2, int U2, int R2, int D2, int L3, int U3, int R3, int D3, int L4, int U4, int R4, int D4, int L5, int U5, int R5, int D5, int L6, int U6, int R6, int D6, int L7, int U7, int R7, int D7, int x0, int x1, int x2, int y0, int y1, int y2, int z, int z0, int z1, int t, unsigned O[], unsigned Q)
{
    int i, j, k, G[9][4][2];

    for (G[8][0][0] = G[8][2][1] = z0, G[8][1][0] = G[8][3][1] = z1, G[8][0][1] = G[8][2][0] = z0 + (1 << t), G[8][1][1] = G[8][3][0] = z1 + (1 << t), i = 7; i >= 0; G[i][0][0] = G[i][2][1] = L(i), G[i][1][0] = G[i][3][1] = U(i), G[i][0][1] = G[i][2][0] = R(i), G[i][1][1] = G[i][3][0] = D(i), i--);
    for (; t; --t, z0 += (i & 0x1) << t, z1 += i >> 1 << t, L0 = L4(0, i), U0 = U4(0, i), R0 = R4(0, i), D0 = D4(0, i), L1 = L4(1, i), U1 = U4(1, i), R1 = R4(1, i), D1 = D4(1, i), L2 = L4(2, i), U2 = U4(2, i), R2 = R4(2, i), D2 = D4(2, i), L3 = L4(3, i), U3 = U4(3, i), R3 = R4(3, i), D3 = D4(3, i), L4 = L4(4, i), U4 = U4(4, i), R4 = R4(4, i), D4 = D4(4, i), L5 = L4(5, i), U5 = U4(5, i), R5 = R4(5, i), D5 = D4(5, i), L6 = L4(6, i), U6 = U4(6, i), R6 = R4(6, i), D6 = D4(6, i), L7 = L4(7, i), U7 = U4(7, i), R7 = R4(7, i), D7 = D4(7, i), Q = QC(Q, i)) {
        for (j = 3; j >= 0; j--)
            for (i = 8, k = N(j); i >= 0; G[i][j][k] = M(G[i][j][0], G[i][j][1]), i--);
        if ((i = DIR0(t)) ^ DIR1(t) || i ^ DIR2(t) || i ^ DIR3(t)) {
            for (i = t - 1; i; i--)
                for (j = 3; j >= 0; j--) {
                    int i;

                    for (i = 8, k = N(j); i >= 0; G[i][j][k] = M(G[i][j][0], G[i][j][1]), i--);
                }
            if (NR(G[8][0][0], G[8][1][0], G[8][2][0], G[8][3][0], z0, z1, t, Q)) {
                if (O_)
                    for (RC(G[8][0][0], G[8][1][0], G[8][2][0], G[8][3][0], z0, z1, t, Q, O[8] << 8 & 0xff0000 | O[8] >> 8 & 0xff00 | O[8] & 0xff);;) {
                        Q = QF(Q);
                        if (CW(Q))
                            break;
                        B(Q);
                    }
                else
                    for (i = 7, j = ((V[2] & (256 << OH) - 1) < x2 + (128 << z)) << 2 | ((V[1] & (256 << OH) - 1) < x1 + (128 << z)) << 1 | (V[0] & (256 << OH) - 1) < x0 + (128 << z), k = i ^ j; i >= 0; --i, k = i ^ j)
                        if (O[k]) {
                            M3D2D(L8(k, 0), U8(k, 0), R8(k, 0), D8(k, 0), L8(k, 1), U8(k, 1), R8(k, 1), D8(k, 1), L8(k, 2), U8(k, 2), R8(k, 2), D8(k, 2), L8(k, 3), U8(k, 3), R8(k, 3), D8(k, 3), L8(k, 4), U8(k, 4), R8(k, 4), D8(k, 4), L8(k, 5), U8(k, 5), R8(k, 5), D8(k, 5), L8(k, 6), U8(k, 6), R8(k, 6), D8(k, 6), L8(k, 7), U8(k, 7), R8(k, 7), D8(k, 7), x0 + ((k & 0x1) << 8 << z - 1), x1 + ((k >> 1 & 0x1) << 8 << z - 1), x2 + (k >> 2 << 8 << z - 1), y0 + ((k << 31 >> 31 & B[0][0]) + (k << 30 >> 31 & B[1][0]) + (k << 29 >> 31 & B[2][0]) << z - 1), y1 + ((k << 31 >> 31 & B[0][1]) + (k << 30 >> 31 & B[1][1]) + (k << 29 >> 31 & B[2][1]) << z - 1), y2 + ((k << 31 >> 31 & B[0][2]) + (k << 30 >> 31 & B[1][2]) + (k << 29 >> 31 & B[2][2]) << z - 1), z - 1, z0, z1, t, O[k], Q);
                            if (!NR(G[8][0][0], G[8][1][0], G[8][2][0], G[8][3][0], z0, z1, t, Q))
                                return;
                        }
            }
            return;
        }
        if (NW(QC(Q, i)))
            return;
    }
    for (p[(z1 - (1 << LOG_R << 1) << LOG_R) + z0 - (1 << LOG_R << 1)] = O[8] << 8 & 0xff0000 | O[8] >> 8 & 0xff00 | O[8] & 0xff;;) {
        B(Q);
        Q = QF(Q);
        if (CW(Q))
            return;
    }
}

#include <stdio.h>

void loadxyzrgba(char *xyzrgba, int n, float x, float y, float z, float s)
{
    int i, j;
    FILE *f;

    if (f = fopen(xyzrgba, "r")) {
        fseek(f, 0L, SEEK_SET);
        for (i = 0; i < n; i++) {
            for (j = 0; j < 3; t[i][j] = (int)((&x)[j] + *(float *)&t[i][j] * s), j++) {
                fscanf(f, "%f", (float *)&t[i][j]);
                t[i][j] ^= j << 31;
            }
            for (; j >= 0; j--)
                fscanf(f, "%d", (char *)&t[i][3] + 3 - j);
        }
        fclose(f);
    }
}

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

#define V(i, j)	(-((V[0] & (256 << OH) - 1) >> 6) * B[0][j] - ((V[1] & (256 << OH) - 1) >> 6) * B[1][j] - ((V[2] & (256 << OH) - 1) >> 6) * B[2][j] + ((i << 31 >> 31 & B[0][j]) + (i << 30 >> 31 & B[1][j]) + (i << 29 >> 31 & B[2][j]) << OH << 2) >> 2)

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASS wc;
    HWND hwnd;
    MSG msg;
    BITMAPINFO bmi;
    HBITMAP hbmold;
    RECT rec, rect;
    HDC hdc;

    short S[3], C[3];
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

    loadxyzrgba("armadillo", PTS, 131072., 131072, 131072., 1024.);
    sort(t, 0, PTS - 1);
    for (i = H; i > 0; i--)
/*        for (j = 0; j < 8; j++)
            octrees[(H - i) * 9 + j] = &octrees[(H - i + 1) * 9]; */
        octrees[(H - i) * 9 + 2] = octrees[(H - i) * 9 + 3] = octrees[(H - i) * 9 + 6] = octrees[(H - i) * 9 + 7] = &octrees[(H - i + 1) * 9];
    z8 = &octrees[H * 9];
    merge(t, PTS, &octrees[H * 9], OH + 8 - H, 8);
    color(&octrees[H * 9]);

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

            for (i = !!GetAsyncKeyState(VK_UP) | !!GetAsyncKeyState(VK_DOWN) << 1 | !!GetAsyncKeyState(VK_LEFT) << 2 | !!GetAsyncKeyState(VK_RIGHT) << 3 /* A, START */ | !!(GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT)) << 4, j = 2; j >= 0; V[j] += (i << 31 >> 31 & B[j][2]) - (i << 30 >> 31 & B[j][2]) - (i << 29 >> 31 & B[j][0]) + (i << 28 >> 31 & B[j][0]) << (4 << (i >> 4)), j--);

            QR();
			M3D2D(-(V(0, 2) << 2) - V(0, 2), -(V(0, 2) << 2) - V(0, 2), (V(0, 2) << 1) + V(0, 2), (V(0, 2) << 1) + V(0, 2), -(V(1, 2) << 2) - V(1, 2), -(V(1, 2) << 2) - V(1, 2), (V(1, 2) << 1) + V(1, 2), (V(1, 2) << 1) + V(1, 2), -(V(2, 2) << 2) - V(2, 2), -(V(2, 2) << 2) - V(2, 2), (V(2, 2) << 1) + V(2, 2), (V(2, 2) << 1) + V(2, 2), -(V(3, 2) << 2) - V(3, 2), -(V(3, 2) << 2) - V(3, 2), (V(3, 2) << 1) + V(3, 2), (V(3, 2) << 1) + V(3, 2), -(V(4, 2) << 2) - V(4, 2), -(V(4, 2) << 2) - V(4, 2), (V(4, 2) << 1) + V(4, 2), (V(4, 2) << 1) + V(4, 2), -(V(5, 2) << 2) - V(5, 2), -(V(5, 2) << 2) - V(5, 2), (V(5, 2) << 1) + V(5, 2), (V(5, 2) << 1) + V(5, 2), -(V(6, 2) << 2) - V(6, 2), -(V(6, 2) << 2) - V(6, 2), (V(6, 2) << 1) + V(6, 2), (V(6, 2) << 1) + V(6, 2), -(V(7, 2) << 2) - V(7, 2), -(V(7, 2) << 2) - V(7, 2), (V(7, 2) << 1) + V(7, 2), (V(7, 2) << 1) + V(7, 2), 0, 0, 0, V(0, 0), V(0, 1), V(0, 2), OH, 0, 0, LOG_R + 2, octrees, 3);
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
