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

int rk[256];
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

int V[3] = { (128 << OH) + 128,  (/* 128 */ /* 240 */ 64 << OH /* 0 */) + 128, (128 << OH) + 128 };
int D[3] = { -32, -32, 0 }, B[3][3];

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

void M3D2D(int L0, int U0, int R0, int D0, int L1, int U1, int R1, int D1, int L2, int U2, int R2, int D2, int L3, int U3, int R3, int D3, int L4, int U4, int R4, int D4, int L5, int U5, int R5, int D5, int L6, int U6, int R6, int D6, int L7, int U7, int R7, int D7, int L8, int U8, int R8, int D8, int x0, int x1, int x2, int y0, int y1, int y2, int z, unsigned O[], int t)
{
    int i, j, k;

    for (i = 4; i--;)
        for (k = 1; ABS(F(8, i + 2 & 0x3) - F(8, i) >> k) > J;)
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
        for (i = 7, j = (x2 < 0) << 2 | (x1 < 0) << 1 | x0 < 0, k = i ^ j; i >= 0; i--, k = i ^ j)
            if (O[0] & 1 << k + 24) {
                M3D2D(L8(k, 0), U8(k, 0), R8(k, 0), D8(k, 0), L8(k, 1), U8(k, 1), R8(k, 1), D8(k, 1), L8(k, 2), U8(k, 2), R8(k, 2), D8(k, 2), L8(k, 3), U8(k, 3), R8(k, 3), D8(k, 3), L8(k, 4), U8(k, 4), R8(k, 4), D8(k, 4), L8(k, 5), U8(k, 5), R8(k, 5), D8(k, 5), L8(k, 6), U8(k, 6), R8(k, 6), D8(k, 6), L8(k, 7), U8(k, 7), R8(k, 7), D8(k, 7), L8, U8, R8, D8, x0 + (1 - (k << 1 & 0x2) << 6 + z), x1 + (1 - (k & 0x2) << 6 + z), x2 + (1 - (k >> 1 & 0x2) << 6 + z), y0 + ((k << 31 >> 31 & B[0][0]) + (k << 30 >> 31 & B[1][0]) + (k << 29 >> 31 & B[2][0]) << z - 1), y1 + ((k << 31 >> 31 & B[0][1]) + (k << 30 >> 31 & B[1][1]) + (k << 29 >> 31 & B[2][1]) << z - 1), y2 + ((k << 31 >> 31 & B[0][2]) + (k << 30 >> 31 & B[1][2]) + (k << 29 >> 31 & B[2][2]) << z - 1), z - 1, O[1] + (rk[O[0] >> 24 & (1 << k) - 1] << 3), t);
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

POINT M;
int ESB;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;

    switch (uMsg) {
    case WM_KEYDOWN:
        switch (wParam) {
        case 's':
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
        if (wParam & MK_LBUTTON) { D[1] -= M.x - LOWORD(lParam) >> 3; D[0] += M.y - HIWORD(lParam) >> 3; }
        M.x = LOWORD(lParam); M.y = HIWORD(lParam);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

#define SIN(x)  sines[(x) & 0xff]
#define COS(x)  SIN(x + 64)

#define V(i, j) (-((V[0] & (256 << OH) - 1) >> 6) * B[0][j] - ((V[1] & (256 << OH) - 1) >> 6) * B[1][j] - ((V[2] & (256 << OH) - 1) >> 6) * B[2][j] + ((i << 31 >> 31 & B[0][j]) + (i << 30 >> 31 & B[1][j]) + (i << 29 >> 31 & B[2][j]) << OH << 2) >> 2)
#define K(i, j) (-(128 << SBLR) * B[0][j] - (128 << SBLR) * B[1][j] - (128 << SBLR) * B[2][j] + ((i << 31 >> 31 & B[0][j]) + (i << 30 >> 31 & B[1][j]) + (i << 29 >> 31 & B[2][j]) << SBLR << 8) >> 8)

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
            M3D2D(-V(0, 2), -V(0, 2) * YX, V(0, 2), V(0, 2) * YX, -V(1, 2), -V(1, 2) * YX, V(1, 2), V(1, 2) * YX, -V(2, 2), -V(2, 2) * YX, V(2, 2), V(2, 2) * YX, -V(3, 2), -V(3, 2) * YX, V(3, 2), V(3, 2) * YX, -V(4, 2), -V(4, 2) * YX, V(4, 2), V(4, 2) * YX, -V(5, 2), -V(5, 2) * YX, V(5, 2), V(5, 2) * YX, -V(6, 2), -V(6, 2) * YX, V(6, 2), V(6, 2) * YX, -V(7, 2), -V(7, 2) * YX, V(7, 2), V(7, 2) * YX, 0, 0, XR << Z, YR << Z, V[0] - (128 << OH), V[1] - (128 << OH), V[2] - (128 << OH), V(0, 0), V(0, 1), V(0, 2), OH, /* O */ A /* PR */, 0);
            if (ESB) {
                if ((i = NU(0, 0, XR, YR)) >= 0)
                    M3D2D(-K(0, 2), -K(0, 2) * YX, K(0, 2), K(0, 2) * YX, -K(1, 2), -K(1, 2) * YX, K(1, 2), K(1, 2) * YX, -K(2, 2), -K(2, 2) * YX, K(2, 2), K(2, 2) * YX, -K(3, 2), -K(3, 2) * YX, K(3, 2), K(3, 2) * YX, -K(4, 2), -K(4, 2) * YX, K(4, 2), K(4, 2) * YX, -K(5, 2), -K(5, 2) * YX, K(5, 2), K(5, 2) * YX, -K(6, 2), -K(6, 2) * YX, K(6, 2), K(6, 2) * YX, -K(7, 2), -K(7, 2) * YX, K(7, 2), K(7, 2) * YX, 0, 0, XR << Z, YR << Z, 0, 0, 0, K(0, 0), K(0, 1), K(0, 2), SBLR, Q, i);
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
