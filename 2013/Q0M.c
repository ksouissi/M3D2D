/*  http://godhatesfags.com/
    http://jesus-is-savior.com/
    http://www.newtonproject.sussex.ac.uk/

    Game developers, pornographers, professors, priests, fag enablers, all perverters of the youth

    And whosoever shall offend one of these little ones that believe in me [Jesus], it is better for him that a millstone were hanged about his neck, and he were cast into the sea. (Mark 9.42)

    May I emphatically suggest the rope?
    As for those who hold the truth in unrighteousness e.g., are under NDA:

    For the wrath of God is revealed from heaven against all ungodliness and unrighteousness of men, who hold the truth in unrighteousness;
    Because that which may be known of God is manifest in them; for God hath shewed it unto them.
    For the invisible things of him from the creation of the world are clearly seen, being understood by the things that are made, even his eternal power and Godhead;
    so that they are without excuse: Because that, when they knew God, they glorified him not as God, neither were thankful; but became vain in their imaginations, and their foolish heart was darkened.
    Professing themselves to be wise, they became fools, And changed the glory of the uncorruptible God into an image made like to corruptible man, and to birds, and fourfooted beasts, and creeping things.
    Wherefore God also gave them up to uncleanness through the lusts of their own hearts, to dishonour their own bodies between themselves:
    Who changed the truth of God into a lie, and worshipped and served the creature more than the Creator, who is blessed for ever. Amen.
    For this cause God gave them up unto vile affections: for even their women did change the natural use into that which is against nature:
    And likewise also the men, leaving the natural use of the woman, burned in their lust one toward another;
    men with men working that which is unseemly, and receiving in themselves that recompence of their error which was meet.
    And even as they did not like to retain God in their knowledge, God gave them over to a reprobate mind, to do those things which are not convenient;
    Being filled with all unrighteousness, fornication, wickedness, covetousness, maliciousness; full of envy, murder, debate, deceit, malignity; whisperers,
    Backbiters, haters of God, despiteful, proud, boasters, inventors of evil things, disobedient to parents,
    Without understanding, covenantbreakers, without natural affection, implacable, unmerciful:
    Who knowing the judgment of God, that they which commit such things are worthy of death, not only do the same, but have pleasure in them that do them. (Romans 1.18-32)

    Not only are you bad programmers but, as if that were not enough, ye are vile fags. Repent!
    B. Dell, I shall uncover the shame of UD's nakedness. Now, of course, an irrelevant fag enabling piece of byproduct of our squalid time coined you "snake oil salesmen".
    That is not the case for otherwise he would be right: reductio ad absurdum. What you are is, rather, an infidel. For while it is commanded not to worship the work of our hands you just do that by concealing your interpretation of that which was revealed unto you, namely UD.
    What if, eventually, I reveal something that is both faster & more elegant than UD? I shall kill your patents.
    Why don't you mention Donald J. Meagher? Our approaches are but mere reformulations of his work. Reader, study this author: http://goo.gl/sdjXVG.

    NVIDIA & clique: the days of your disgraceful trash are numbered.
    Death penalty for fags.

    2011-13, made in Tunisia */

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

#define M(x, y) ((x) + (y) >> 1)    /* (((x) & (y)) + (((x) ^ (y)) >> 1)) */

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

int *p;

int V[3] = { (256 << OH - 1) + 128, (504 /* 256 */ << OH - 1) + 128, (256 << OH - 1) + 128 };
int D[3] = { -32, -32, 0 }, B[3][3];

int W[(1 << (LOG_R << 1)) >> 5];

int NR(int L, int U, int R, int D)
{
    int i, j;

    if (L >> 5 ^ R >> 5)
        for (j = R >> 5; U < D; U++) {
            if (-(1 << (L & 0x1f)) & W[(U << LOG_R) + L >> 5] || (1 << (R & 0x1f)) - 1 & W[(U << LOG_R) + R >> 5])
                return 1;
            for (i = (L >> 5) + 1; i < j; i++)
                if (W[(U << LOG_R - 5) + i])
                    return 1;
        }
    else
        for (; U < D; U++)
            if (-(1 << (L & 0x1f)) & (1 << (R & 0x1f)) - 1 & W[(U << LOG_R) + L >> 5])
                return 1;
    return 0;
}

void RC(int L, int U, int R, int D, int c)
{
    int i, j, k;

    if (L >> 5 ^ R >> 5)
        for (j = R >> 5, i = U; i < D; i++) {
            W[(i << LOG_R) + L >> 5] &= (1 << (L & 0x1f)) - 1; W[(i << LOG_R) + R >> 5] &= -(1 << (R & 0x1f));
            for (k = (L >> 5) + 1; k < j; k++)
                W[(i << LOG_R - 5) + k] = 0;
        }
    else
        for (j = (1 << (L & 0x1f)) - 1 | -(1 << (R & 0x1f)), i = U; i < D; i++)
            W[(i << LOG_R) + L >> 5] &= j;
    for (; U < D; U++)
        for (i = L; i < R; i++)
            p[(U << LOG_R) + i] = -!p[(U << LOG_R) + i] & c | p[(U << LOG_R) + i];
}

#define ABS(x)  ((x) >> 31 ^ (x) - ((unsigned)(x) >> 31))
#define V(i, j) ((&y0)[j] + ((i << 31 >> 31 & B[0][j]) + (i << 30 >> 31 & B[1][j]) + (i << 29 >> 31 & B[2][j]) << z))

#define DIRECT

#ifdef DIRECT

#define S2  V(i, 2)
#define L(i)    L * (S2 >> LOG_R - 1) - S2
#define U(i)    U * (S2 >> LOG_R - 1) - S2
#define R(i)    R * (S2 >> LOG_R - 1) - S2
#define D(i)    D * (S2 >> LOG_R - 1) - S2

void D2D3M(int L, int U, int R, int D, int x0, int x1, int x2, int y0, int y1, int y2, int z, unsigned O[])
{
    int i, j, k, G[9][4][2];

    for (G[8][0][0] = L, G[8][1][0] = U, G[8][2][0] = R, G[8][3][0] = D, i = 7; i >= 0; G[i][0][0] = L(i), G[i][1][0] = U(i), G[i][2][0] = R(i), G[i][3][0] = D(i), i--);
    for (j = 3; j >= 0; j--) {
        for (i = 8; i >= 0; G[i][j][1] = G[i][j + 2 & 0x3][0], i--);
        while (ABS(G[8][j][0] - G[8][j][1]) > 1)
            for (i = 8, k = (j << 30 >> 31 ^ V(0, j & 0x1)) < (j << 30 >> 31 ^ M(G[0][j][0], G[0][j][1])) || (j << 30 >> 31 ^ V(1, j & 0x1)) < (j << 30 >> 31 ^ M(G[1][j][0], G[1][j][1])) || (j << 30 >> 31 ^ V(2, j & 0x1)) < (j << 30 >> 31 ^ M(G[2][j][0], G[2][j][1])) || (j << 30 >> 31 ^ V(3, j & 0x1)) < (j << 30 >> 31 ^ M(G[3][j][0], G[3][j][1])) || (j << 30 >> 31 ^ V(4, j & 0x1)) < (j << 30 >> 31 ^ M(G[4][j][0], G[4][j][1])) || (j << 30 >> 31 ^ V(5, j & 0x1)) < (j << 30 >> 31 ^ M(G[5][j][0], G[5][j][1])) || (j << 30 >> 31 ^ V(6, j & 0x1)) < (j << 30 >> 31 ^ M(G[6][j][0], G[6][j][1])) || (j << 30 >> 31 ^ V(7, j & 0x1)) < (j << 30 >> 31 ^ M(G[7][j][0], G[7][j][1])); i >= 0; G[i][j][k] = M(G[i][j][0], G[i][j][1]), i--);
    }
    if (NR(G[8][0][0], G[8][1][0], G[8][2][0], G[8][3][0])) {
        if (G[8][2][0] - G[8][0][0] <= 2 || G[8][3][0] - G[8][1][0] <= 2 || !z  /* (256 << z) - 256 <= ABS(y0) + ABS(y1) + ABS(y2) >> LOG_R - 1 */) {
            if (y2 >= 0)
                RC(G[8][0][0], G[8][1][0], G[8][2][0], G[8][3][0], O[8] << 8 & 0xff0000 | O[8] >> 8 & 0xff00 | O[8] & 0xff);
        } else
            for (i = 7, j = ((V[2] & (256 << OH) - 1) < x2 + (128 << z)) << 2 | ((V[1] & (256 << OH) - 1) < x1 + (128 << z)) << 1 | (V[0] & (256 << OH) - 1) < x0 + (128 << z), k = i ^ j; i >= 0; --i, k = i ^ j)
                if (O[k]) {
                    D2D3M(G[8][0][0], G[8][1][0], G[8][2][0], G[8][3][0], x0 + ((k & 0x1) << 8 << z - 1), x1 + ((k >> 1 & 0x1) << 8 << z - 1), x2 + (k >> 2 << 8 << z - 1), y0 + ((k << 31 >> 31 & B[0][0]) + (k << 30 >> 31 & B[1][0]) + (k << 29 >> 31 & B[2][0]) << z - 1), y1 + ((k << 31 >> 31 & B[0][1]) + (k << 30 >> 31 & B[1][1]) + (k << 29 >> 31 & B[2][1]) << z - 1), y2 + ((k << 31 >> 31 & B[0][2]) + (k << 30 >> 31 & B[1][2]) + (k << 29 >> 31 & B[2][2]) << z - 1), z - 1, O[k]);
                    if (!NR(G[8][0][0], G[8][1][0], G[8][2][0], G[8][3][0]))
                        return;
                }
    }
}
#else
#define L(i)    z0 * (V(i, 2) >> LOG_R - 1) - V(i, 2)
#define U(i)    z1 * (V(i, 2) >> LOG_R - 1) - V(i, 2)
#define R(i)    L(i) + (V(i, 2) << 1 >> LOG_R - t)
#define D(i)    U(i) + (V(i, 2) << 1 >> LOG_R - t)

#define DIR0(i) (G[8][1][0] >> i - 1 << 1 & 0x2 | G[8][0][0] >> i - 1 & 0x1)
#define DIR1(i) (G[8][1][0] >> i - 1 << 1 & 0x2 | G[8][2][0] - 1 >> i - 1 & 0x1)
#define DIR2(i) (G[8][3][0] - 1 >> i - 1 << 1 & 0x2 | G[8][0][0] >> i - 1 & 0x1)
#define DIR3(i) (G[8][3][0] - 1 >> i - 1 << 1 & 0x2 | G[8][2][0] - 1 >> i - 1 & 0x1)

void D2D3M(int z0, int z1, int t, int x0, int x1, int x2, int y0, int y1, int y2, int z, unsigned O[])
{
    int i, j, k, G[9][4][2];

    for (G[8][0][0] = G[8][2][1] = z0, G[8][1][0] = G[8][3][1] = z1, G[8][0][1] = G[8][2][0] = z0 + (1 << t), G[8][1][1] = G[8][3][0] = z1 + (1 << t), i = 7; i >= 0; G[i][0][0] = G[i][2][1] = L(i), G[i][1][0] = G[i][3][1] = U(i), G[i][0][1] = G[i][2][0] = R(i), G[i][1][1] = G[i][3][0] = D(i), i--);
    for (i = t; i; i--)
        for (j = 3; j >= 0; j--) {
            int i;

            for (i = 8, k = (j << 30 >> 31 ^ V(0, j & 0x1)) < (j << 30 >> 31 ^ M(G[0][j][0], G[0][j][1])) || (j << 30 >> 31 ^ V(1, j & 0x1)) < (j << 30 >> 31 ^ M(G[1][j][0], G[1][j][1])) || (j << 30 >> 31 ^ V(2, j & 0x1)) < (j << 30 >> 31 ^ M(G[2][j][0], G[2][j][1])) || (j << 30 >> 31 ^ V(3, j & 0x1)) < (j << 30 >> 31 ^ M(G[3][j][0], G[3][j][1])) || (j << 30 >> 31 ^ V(4, j & 0x1)) < (j << 30 >> 31 ^ M(G[4][j][0], G[4][j][1])) || (j << 30 >> 31 ^ V(5, j & 0x1)) < (j << 30 >> 31 ^ M(G[5][j][0], G[5][j][1])) || (j << 30 >> 31 ^ V(6, j & 0x1)) < (j << 30 >> 31 ^ M(G[6][j][0], G[6][j][1])) || (j << 30 >> 31 ^ V(7, j & 0x1)) < (j << 30 >> 31 ^ M(G[7][j][0], G[7][j][1])); i >= 0; G[i][j][k] = M(G[i][j][0], G[i][j][1]), i--);
        }
    if (NR(G[8][0][0], G[8][1][0], G[8][2][0], G[8][3][0])) {
        if (G[8][2][0] - G[8][0][0] <= 2 || G[8][3][0] - G[8][1][0] <= 2 || !z  /* (256 << z) - 256 <= ABS(y0) + ABS(y1) + ABS(y2) >> LOG_R - 1 */) {
            if (y2 >= 0)
                RC(G[8][0][0], G[8][1][0], G[8][2][0], G[8][3][0], O[8] << 8 & 0xff0000 | O[8] >> 8 & 0xff00 | O[8] & 0xff /* O[8] */);
        } else 
            for (;; --t, z0 += (i & 0x1) << t, z1 += i >> 1 << t)
                if ((i = DIR0(t)) ^ DIR1(t) || i ^ DIR2(t) || i ^ DIR3(t)) {
                    for (i = 7, j = ((V[2] & (256 << OH) - 1) < x2 + (128 << z)) << 2 | ((V[1] & (256 << OH) - 1) < x1 + (128 << z)) << 1 | (V[0] & (256 << OH) - 1) < x0 + (128 << z), k = i ^ j; i >= 0; --i, k = i ^ j)
                        if (O[k]) {
                            D2D3M(z0, z1, t, x0 + ((k & 0x1) << 8 << z - 1), x1 + ((k >> 1 & 0x1) << 8 << z - 1), x2 + (k >> 2 << 8 << z - 1), y0 + ((k << 31 >> 31 & B[0][0]) + (k << 30 >> 31 & B[1][0]) + (k << 29 >> 31 & B[2][0]) << z - 1), y1 + ((k << 31 >> 31 & B[0][1]) + (k << 30 >> 31 & B[1][1]) + (k << 29 >> 31 & B[2][1]) << z - 1), y2 + ((k << 31 >> 31 & B[0][2]) + (k << 30 >> 31 & B[1][2]) + (k << 29 >> 31 & B[2][2]) << z - 1), z - 1, O[k]);
                            if (!NR(G[8][0][0], G[8][1][0], G[8][2][0], G[8][3][0]))
                                return;
                        }
                    return;
                }
    }
}
#endif

#define V0(i)   y##i
#define V1(i)  (y##i + (B[0][i]                     << z))
#define V2(i)  (y##i + (          B[1][i]           << z))
#define V3(i)  (y##i + (B[0][i] + B[1][i]           << z))
#define V4(i)  (y##i + (                    B[2][i] << z))
#define V5(i)  (y##i + (B[0][i]           + B[2][i] << z))
#define V6(i)  (y##i + (          B[1][i] + B[2][i] << z))
#define V7(i)  (y##i + (B[0][i] + B[1][i] + B[2][i] << z))
#define CODE()  (V0(1) >= V0(2)) << 3 | (V0(0) >= V0(2)) << 2 | (V0(1) < -V0(2)) << 1 | V0(0) < -V0(2) | ((V1(1) >= V1(2)) << 3 | (V1(0) >= V1(2)) << 2 | (V1(1) < -V1(2)) << 1 | V1(0) < -V1(2)) << 4 | ((V2(1) >= V2(2)) << 3 | (V2(0) >= V2(2)) << 2 | (V2(1) < -V2(2)) << 1 | V2(0) < -V2(2)) << 8 | ((V3(1) >= V3(2)) << 3 | (V3(0) >= V3(2)) << 2 | (V3(1) < -V3(2)) << 1 | V3(0) < -V3(2)) << 12 | ((V4(1) >= V4(2)) << 3 | (V4(0) >= V4(2)) << 2 | (V4(1) < -V4(2)) << 1 | V4(0) < -V4(2)) << 16 | ((V5(1) >= V5(2)) << 3 | (V5(0) >= V5(2)) << 2 | (V5(1) < -V5(2)) << 1 | V5(0) < -V5(2)) << 20 | ((V6(1) >= V6(2)) << 3 | (V6(0) >= V6(2)) << 2 | (V6(1) < -V6(2)) << 1 | V6(0) < -V6(2)) << 24 | ((V7(1) >= V7(2)) << 3 | (V7(0) >= V7(2)) << 2 | (V7(1) < -V7(2)) << 1 | V7(0) < -V7(2)) << 28

void M3D2D(int x, int y, int t, int y0, int y1, int y2, int z, int O[])
{
    int i, j, k;

    if (i = CODE()) {
        if (z <= 4 || i & i >> 4 & i >> 8 & i >> 12 & i >> 16 & i >> 20 & i >> 24 & (unsigned)i >> 28)
            return;
        for (i = 7, j = ((V[2] & (256 << OH) - 1) < t + (128 << z)) << 2 | ((V[1] & (256 << OH) - 1) < y + (128 << z)) << 1 | (V[0] & (256 << OH) - 1) < x + (128 << z), k = i ^ j; i >= 0; --i, k = i ^ j)
            if (O[k])
                M3D2D(x + ((k & 0x1) << 8 << z - 1), y + ((k >> 1 & 0x1) << 8 << z - 1), t + (k >> 2 << 8 << z - 1), y0 + ((k << 31 >> 31 & B[0][0]) + (k << 30 >> 31 & B[1][0]) + (k << 29 >> 31 & B[2][0]) << z - 1), y1 + ((k << 31 >> 31 & B[0][1]) + (k << 30 >> 31 & B[1][1]) + (k << 29 >> 31 & B[2][1]) << z - 1), y2 + ((k << 31 >> 31 & B[0][2]) + (k << 30 >> 31 & B[1][2]) + (k << 29 >> 31 & B[2][2]) << z - 1), z - 1, O[k]);
    } else
        D2D3M(0, 0,
#ifdef DIRECT
                    1 << LOG_R, 1 << LOG_R, 
#else
                    LOG_R, 
#endif
                            x, y, t, y0, y1, y2, z, O);
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

#define V(i, j) (-((V[0] & (256 << OH) - 1) >> 6) * B[0][j] - ((V[1] & (256 << OH) - 1) >> 6) * B[1][j] - ((V[2] & (256 << OH) - 1) >> 6) * B[2][j] + ((i << 31 >> 31 & B[0][j]) + (i << 30 >> 31 & B[1][j]) + (i << 29 >> 31 & B[2][j]) << OH << 2) >> 2)

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

            memset(W, 0xff, 1 << (LOG_R << 1) >> 3);
//            M3D2D(0, 0, 0, V(0, 0), V(0, 1), V(0, 2), OH, octrees);
            D2D3M(0, 0, 1 << LOG_R, 1 << LOG_R, 0, 0, 0, V(0, 0), V(0, 1), V(0, 2), OH, octrees);
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
