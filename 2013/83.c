/* The cause of cancer is immorality e.g., covetousness, lewdness & such. Fear God, for He is fierce in His retribution */

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

int V[3], D[3], B[3][3];

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

unsigned D2D3M(int L0, int U0, int L1, int U1, int L2, int U2, int L3, int U3, int L4, int U4, int L5, int U5, int L6, int U6, int L7, int U7, int z0, int z1, int t, int y0, int y1, int y2, int z, unsigned O[], unsigned K)
{
    int S[H + 1], i, j, k, G[9][4];

    for (G[8][0] = z0, G[8][1] = z1, G[8][2] = z0 + (1 << t), G[8][3] = z1 + (1 << t), i = 7; i >= 0; G[i][0] = L(i), G[i][1] = U(i), G[i][2] = L(i) + (V(i, 2) << 1 >> LOG_R - t), G[i][3] = U(i) + (V(i, 2) << 1 >> LOG_R - t), i--);
    for (i = t; i; i--)
        for (j = 3; j >= 0; j--)
            if (!N(j))
                for (G[8][j] += (j << 30 >> 31 ^ 1 << i - 1) + (j >> 1), k = 7; k >= 0; G[k][j] += (j << 30 >> 31 ^ V(k, 2) >> LOG_R - i) + (j >> 1), k--);
    for (k = M(V0(2), V7(2)), i = G[8][1]; i < G[8][3]; i++)
        for (j = G[8][0]; j < G[8][2]; j++)
            if (k < zbuffer[(i << LOG_R) + j]) {
                if (G[8][2] - G[8][0] <= 2 || G[8][3] - G[8][1] <= 2 || !z) {
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
                    for (z0 += (j & 0x1) << t - 1, z1 += j >> 1 << t - 1, i = 7; i >= 0; L(i) += j << 31 >> 31 & V(i, 2) >> LOG_R - t, U(i) += j << 30 >> 31 & V(i, 2) >> LOG_R - t, i--);
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
/*
    loadxyzrgba("armadillo", PTS, 128 << H, 128 << H, 128 << H, 1 << H);
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

            for (i = !!GetAsyncKeyState(VK_UP) | !!GetAsyncKeyState(VK_DOWN) << 1 | !!GetAsyncKeyState(VK_LEFT) << 2 | !!GetAsyncKeyState(VK_RIGHT) << 3 /* A, START */ | !!(GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT)) << 4, j = 2; j >= 0; V[j] += (i << 31 >> 31 & B[j][2]) - (i << 30 >> 31 & B[j][2]) - (i << 29 >> 31 & B[j][0]) + (i << 28 >> 31 & B[j][0]) << (2 << (i >> 4)), j--);
            for (i = (1 << (LOG_R << 1)) - 1; i >= 0; zbuffer[i] = 0x7fffffff, i--);
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