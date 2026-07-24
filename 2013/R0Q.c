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
    "...prosto i ne zeitgeist-ichno" (concerning H. Samet's version of the front-to-back octree splatter by D. Meagher).  Why the facepalm, Hybernaculum? We would have been done with UD already in 2012.
    B. Dell, I shall uncover the shame of UD's nakedness. Now, of course, an irrelevant fag enabling piece of byproduct of our squalid time coined you "snake oil salesmen".
    That is not the case for otherwise he would be right: reductio ad absurdum. What you are is, rather, an infidel. For while it is commanded not to worship the work of our hands you just do that by concealing your interpretation of that which was revealed unto you, namely UD.
    What if, eventually, I reveal something that is both faster & more elegant than UD? I shall kill your patents.
    Why don't you mention Donald J. Meagher? Our approaches are but mere reformulations of his work. Reader, study this author: http://goo.gl/sdjXVG.

    NVIDIA & clique: the days of your disgraceful trash are numbered.
    Redundant faggots, of all the things there are, you chose that one all shameful, downright filthy, dishonoring, unmanly aberration as your defining concept.
    Death penalty for fags.

    Crowdfunding maggots all over the place! Loss of face Mammon worship. You indecent harlots, where is your shame? So much squander on foolishness in unclean heathendom.
    War will straighten this out & war shall there be for faggots & licentiousness doom nations.

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

#define OH  17
#define H   7

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

#define M(x, y) x + y >> 1  /* (x & y) + ((x ^ y) >> 1) */

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

#define NW(x)   (quadtrees[x >> 5] & 0x1 << (x & 0x1f))

/* #define PURE */

#ifdef PURE
#define QS  (((1 << (LOG_R + 2 + 1 << 1)) - 1) / 3 + 3 + 31) / 32
#define QR()    /* quadtrees[0] = 0xe00070, quadtrees[9] = 0xcc, ZeroMemory(quadtrees + 10, QS - 10 << 2) */    quadtrees[0] = 0xe00070, ZeroMemory(quadtrees + 1, QS - 1 << 2)
#else
#define QS  (((1 << (LOG_R + 1 << 1)) - 1) / 3 + 3 + 31) / 32
#define QR()    /* quadtrees[0] = 0xcc0000, ZeroMemory(quadtrees + 1, QS - 1 << 2) */   ZeroMemory(quadtrees, QS << 2)
#endif

#define ABS(x)  (x >> 31 ^ x - ((unsigned)x >> 31))
#define O_  ((256 << z) - 256 <= /* ABS(y0) + ABS(y1) + ABS(y2) */ y2 >> LOG_R - 1)

int quadtrees[QS];

#define B(x)    quadtrees[x >> 5] |= 0x1 << (x & 0x1f)
#define CNB(x)  (~quadtrees[QC(x, 0) >> 5] & 0xf << (QC(x, 0) & 0x1f))
#define ACB(x)  !CNB(x)

#define QF(x)   (x >> 2) + 2
#define QC(x, y)    (x - 2 << 2) + y

int *p;

int V[3] = { (256 << OH - 1) + 128, (480 /* 256 */ << OH - 1) + 128, (256 << OH - 1) + 128 };
int D[3] = { -32, -32, 0 }, B[3][3];

void RC(int L, int U, int R, int D, int x, int y, int z, unsigned Q, int c)
{
    int i, j;

    if (x < L || y < U || x + (1 << z) > R || y + (1 << z) > D) {
        for (i = 3; i >= 0; i--)
            if (!NW(QC(Q, i)) && x + ((i & 0x1) << z - 1) < R && y + (i >> 1 << z - 1) < D && x + (1 << z - (~i & 0x1)) > L && y + (1 << z - (~i >> 1 & 0x1)) > U)
                RC(L, U, R, D, x + ((i & 0x1) << z - 1), y + (i >> 1 << z - 1), z - 1, QC(Q, i), c);
        quadtrees[Q >> 5] |= ACB(Q) << (Q & 0x1f);
    } else
#ifdef PURE
#define MIN(x, y)   (-((x) < (y)) & (x) | -((y) <= (x)) & (y))
#define MAX(x, y)   (-((x) > (y)) & (x) | -((y) >= (x)) & (y))
        for (y -= 1 << LOG_R << 1, x -= 1 << LOG_R << 1, i = MAX(0, y), B(Q); i < MIN(y + (1 << z), 1 << LOG_R); i++)
            for (j = MAX(0, x); j < MIN(x + (1 << z), 1 << LOG_R); j++)
#else
        for (i = y, B(Q); i < y + (1 << z); i++)
            for (j = x; j < x + (1 << z); j++)
#endif
                p[(i << LOG_R) + j] = -!p[(i << LOG_R) + j] & c | p[(i << LOG_R) + j];
}

#define V(i, j) ((&y0)[j] + ((i << 31 >> 31 & B[0][j]) + (i << 30 >> 31 & B[1][j]) + (i << 29 >> 31 & B[2][j]) << z))

/* #define MUL */

#ifdef MUL
#define L(i)    (z0 * (V(i, 2) >> LOG_R - 1) - V(i, 2))
#define U(i)    (z1 * (V(i, 2) >> LOG_R - 1) - V(i, 2))
#define R(i)    ((z0 + (1 << t)) * (V(i, 2) >> LOG_R - 1) - V(i, 2))
#define D(i)    ((z1 + (1 << t)) * (V(i, 2) >> LOG_R - 1) - V(i, 2))
#else
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
#endif

void QD(
#ifndef MUL
        int L0, int U0, int R0, int D0, int L1, int U1, int R1, int D1, int L2, int U2, int R2, int D2, int L3, int U3, int R3, int D3, int L4, int U4, int R4, int D4, int L5, int U5, int R5, int D5, int L6, int U6, int R6, int D6, int L7, int U7, int R7, int D7, 
#endif
                                                                                                                                                                                                                                                                        int y0, int y1, int y2, int z, int z0, int z1, int t, unsigned Q, int c)
{
    int i, j, k, G[9][4][2];

    for (G[8][0][0] = G[8][2][1] = z0, G[8][1][0] = G[8][3][1] = z1, G[8][0][1] = G[8][2][0] = z0 + (1 << t), G[8][1][1] = G[8][3][0] = z1 + (1 << t), i = 7; i >= 0; G[i][0][0] = G[i][2][1] = L(i), G[i][1][0] = G[i][3][1] = U(i), G[i][0][1] = G[i][2][0] = R(i), G[i][1][1] = G[i][3][0] = D(i), i--);
    for (i = t; i; i--)
        for (j = 3; j >= 0; j--) {
            int i;

            for (i = 8, k = (j << 30 >> 31 ^ V(0, j & 0x1)) < (j << 30 >> 31 ^ M(G[0][j][0], G[0][j][1])) || (j << 30 >> 31 ^ V(1, j & 0x1)) < (j << 30 >> 31 ^ M(G[1][j][0], G[1][j][1])) || (j << 30 >> 31 ^ V(2, j & 0x1)) < (j << 30 >> 31 ^ M(G[2][j][0], G[2][j][1])) || (j << 30 >> 31 ^ V(3, j & 0x1)) < (j << 30 >> 31 ^ M(G[3][j][0], G[3][j][1])) || (j << 30 >> 31 ^ V(4, j & 0x1)) < (j << 30 >> 31 ^ M(G[4][j][0], G[4][j][1])) || (j << 30 >> 31 ^ V(5, j & 0x1)) < (j << 30 >> 31 ^ M(G[5][j][0], G[5][j][1])) || (j << 30 >> 31 ^ V(6, j & 0x1)) < (j << 30 >> 31 ^ M(G[6][j][0], G[6][j][1])) || (j << 30 >> 31 ^ V(7, j & 0x1)) < (j << 30 >> 31 ^ M(G[7][j][0], G[7][j][1])); i >= 0; G[i][j][k] = M(G[i][j][0], G[i][j][1]), i--);
        }
    RC(G[8][0][0], G[8][1][0], G[8][2][0], G[8][3][0], z0, z1, t, Q, c);
}

#define V0(i)   y##i
#define V1(i)  (y##i + (B[0][i]                     << z))
#define V2(i)  (y##i + (          B[1][i]           << z))
#define V3(i)  (y##i + (B[0][i] + B[1][i]           << z))
#define V4(i)  (y##i + (                    B[2][i] << z))
#define V5(i)  (y##i + (B[0][i]           + B[2][i] << z))
#define V6(i)  (y##i + (          B[1][i] + B[2][i] << z))
#define V7(i)  (y##i + (B[0][i] + B[1][i] + B[2][i] << z))

#define DIR(i)  ((V##i(1) >= M(U##i, D##i)) << 1 | V##i(0) >= M(L##i, R##i))

#ifdef PURE
void M3D2D(int x0, int x1, int x2, int y0, int y1, int y2, int z, int O[], int x, int y, int t, unsigned Q, int L0, int U0, int R0, int D0, int L1, int U1, int R1, int D1, int L2, int U2, int R2, int D2, int L3, int U3, int R3, int D3, int L4, int U4, int R4, int D4, int L5, int U5, int R5, int D5, int L6, int U6, int R6, int D6, int L7, int U7, int R7, int D7)
{
    int i;

    if (O_)
        for (QD(L(0), U(0), R(0), D(0), L(1), U(1), R(1), D(1), L(2), U(2), R(2), D(2), L(3), U(3), R(3), D(3), L(4), U(4), R(4), D(4), L(5), U(5), R(5), D(5), L(6), U(6), R(6), D(6), L(7), U(7), R(7), D(7), y0, y1, y2, z, x, y, t, Q, O[8]);;) {
            Q = QF(Q);
            if (CNB(Q))
                break;
            B(Q);
        }
    else
        for (;; --t, x += (i & 0x1) << t, y += i >> 1 << t, L0 = L4(0, i), U0 = U4(0, i), R0 = R4(0, i), D0 = D4(0, i), L1 = L4(1, i), U1 = U4(1, i), R1 = R4(1, i), D1 = D4(1, i), L2 = L4(2, i), U2 = U4(2, i), R2 = R4(2, i), D2 = D4(2, i), L3 = L4(3, i), U3 = U4(3, i), R3 = R4(3, i), D3 = D4(3, i), L4 = L4(4, i), U4 = U4(4, i), R4 = R4(4, i), D4 = D4(4, i), L5 = L4(5, i), U5 = U4(5, i), R5 = R4(5, i), D5 = D4(5, i), L6 = L4(6, i), U6 = U4(6, i), R6 = R4(6, i), D6 = D4(6, i), L7 = L4(7, i), U7 = U4(7, i), R7 = R4(7, i), D7 = D4(7, i), Q = QC(Q, i)) {
            if ((i = DIR(0)) ^ DIR(1) || i ^ DIR(2) || i ^ DIR(3) || i ^ DIR(4) || i ^ DIR(5) || i ^ DIR(6) || i ^ DIR(7)) {
                int j, k;

                for (i = 7, j = ((V[2] & (256 << OH) - 1) < x2 + (128 << z)) << 2 | ((V[1] & (256 << OH) - 1) < x1 + (128 << z)) << 1 | (V[0] & (256 << OH) - 1) < x0 + (128 << z), k = i ^ j; i >= 0; --i, k = i ^ j)
                    if (O[k]) {
                        M3D2D(x0 + ((k & 0x1) << 8 << z - 1), x1 + ((k >> 1 & 0x1) << 8 << z - 1), x2 + (k >> 2 << 8 << z - 1), y0 + ((k << 31 >> 31 & B[0][0]) + (k << 30 >> 31 & B[1][0]) + (k << 29 >> 31 & B[2][0]) << z - 1), y1 + ((k << 31 >> 31 & B[0][1]) + (k << 30 >> 31 & B[1][1]) + (k << 29 >> 31 & B[2][1]) << z - 1), y2 + ((k << 31 >> 31 & B[0][2]) + (k << 30 >> 31 & B[1][2]) + (k << 29 >> 31 & B[2][2]) << z - 1), z - 1, O[k], x, y, t, Q, L8(k, 0), U8(k, 0), R8(k, 0), D8(k, 0), L8(k, 1), U8(k, 1), R8(k, 1), D8(k, 1), L8(k, 2), U8(k, 2), R8(k, 2), D8(k, 2), L8(k, 3), U8(k, 3), R8(k, 3), D8(k, 3), L8(k, 4), U8(k, 4), R8(k, 4), D8(k, 4), L8(k, 5), U8(k, 5), R8(k, 5), D8(k, 5), L8(k, 6), U8(k, 6), R8(k, 6), D8(k, 6), L8(k, 7), U8(k, 7), R8(k, 7), D8(k, 7));
                        if (NW(Q))
                            return;
                    }
                return;
            }
            if (NW(QC(Q, i)))
                return;
        }
}
#else
#define CODE()  (V0(1) >= V0(2)) << 3 | (V0(0) >= V0(2)) << 2 | (V0(1) < -V0(2)) << 1 | V0(0) < -V0(2) | ((V1(1) >= V1(2)) << 3 | (V1(0) >= V1(2)) << 2 | (V1(1) < -V1(2)) << 1 | V1(0) < -V1(2)) << 4 | ((V2(1) >= V2(2)) << 3 | (V2(0) >= V2(2)) << 2 | (V2(1) < -V2(2)) << 1 | V2(0) < -V2(2)) << 8 | ((V3(1) >= V3(2)) << 3 | (V3(0) >= V3(2)) << 2 | (V3(1) < -V3(2)) << 1 | V3(0) < -V3(2)) << 12 | ((V4(1) >= V4(2)) << 3 | (V4(0) >= V4(2)) << 2 | (V4(1) < -V4(2)) << 1 | V4(0) < -V4(2)) << 16 | ((V5(1) >= V5(2)) << 3 | (V5(0) >= V5(2)) << 2 | (V5(1) < -V5(2)) << 1 | V5(0) < -V5(2)) << 20 | ((V6(1) >= V6(2)) << 3 | (V6(0) >= V6(2)) << 2 | (V6(1) < -V6(2)) << 1 | V6(0) < -V6(2)) << 24 | ((V7(1) >= V7(2)) << 3 | (V7(0) >= V7(2)) << 2 | (V7(1) < -V7(2)) << 1 | V7(0) < -V7(2)) << 28

#ifdef MUL
#define MMUL

#ifndef MMUL
#define DIR(i)  ((V##i(1) >= F[i][1] + (V##i(2) >> LOG_R - t)) << 1 | V##i(0) >= F[i][0] + (V##i(2) >> LOG_R - t))

void D2D3M(int x0, int x1, int x2, int y0, int y1, int y2, int z, int O[], int x, int y, int t, unsigned Q)
{
    int i;

    if (O_)
        for (QD(y0, y1, y2, z, x, y, t, Q, O[8]);;) {
            Q = QF(Q);
            if (CNB(Q))
                break;
            B(Q);
        }
    else {
        int F[8][2];

        for (i = 7; i >= 0; F[i][0] = x * (V(i, 2) >> LOG_R - 1) - V(i, 2), F[i][1] = y * (V(i, 2) >> LOG_R - 1) - V(i, 2), i--);
        for (i = DIR(0);; F[0][0] += i << 31 >> 31 & (V(0, 2) >> LOG_R - t), F[0][1] += i << 30 >> 31 & (V0(2) >> LOG_R - t), F[1][0] += i << 31 >> 31 & (V1(2) >> LOG_R - t), F[1][1] += i << 30 >> 31 & (V1(2) >> LOG_R - t), F[2][0] += i << 31 >> 31 & (V2(2) >> LOG_R - t), F[2][1] += i << 30 >> 31 & (V2(2) >> LOG_R - t), F[3][0] += i << 31 >> 31 & (V3(2) >> LOG_R - t), F[3][1] += i << 30 >> 31 & (V3(2) >> LOG_R - t), F[4][0] += i << 31 >> 31 & (V4(2) >> LOG_R - t), F[4][1] += i << 30 >> 31 & (V4(2) >> LOG_R - t), F[5][0] += i << 31 >> 31 & (V5(2) >> LOG_R - t), F[5][1] += i << 30 >> 31 & (V5(2) >> LOG_R - t), F[6][0] += i << 31 >> 31 & (V6(2) >> LOG_R - t), F[6][1] += i << 30 >> 31 & (V6(2) >> LOG_R - t), F[7][0] += i << 31 >> 31 & (V7(2) >> LOG_R - t), F[7][1] += i << 30 >> 31 & (V7(2) >> LOG_R - t), --t, x += (i & 0x1) << t, y += i >> 1 << t, Q = QC(Q, i), i = DIR(0))
            if (i ^ DIR(1) || i ^ DIR(2) || i ^ DIR(3) || i ^ DIR(4) || i ^ DIR(5) || i ^ DIR(6) || i ^ DIR(7)) {
                int j, k;

                for (i = 7, j = ((V[2] & (256 << OH) - 1) < x2 + (128 << z)) << 2 | ((V[1] & (256 << OH) - 1) < x1 + (128 << z)) << 1 | (V[0] & (256 << OH) - 1) < x0 + (128 << z), k = i ^ j; i >= 0; --i, k = i ^ j)
                    if (O[k]) {
                        D2D3M(x0 + ((k & 0x1) << 8 << z - 1), x1 + ((k >> 1 & 0x1) << 8 << z - 1), x2 + (k >> 2 << 8 << z - 1), y0 + ((k << 31 >> 31 & B[0][0]) + (k << 30 >> 31 & B[1][0]) + (k << 29 >> 31 & B[2][0]) << z - 1), y1 + ((k << 31 >> 31 & B[0][1]) + (k << 30 >> 31 & B[1][1]) + (k << 29 >> 31 & B[2][1]) << z - 1), y2 + ((k << 31 >> 31 & B[0][2]) + (k << 30 >> 31 & B[1][2]) + (k << 29 >> 31 & B[2][2]) << z - 1), z - 1, O[k], x, y, t, Q);
                        if (NW(Q))
                            return;
                    }
                return;
            } else if (NW(QC(Q, i)))
                return;
    }
}
#else
#define DIR(i)  ((V##i(1) >= (y + (1 << t >> 1)) * (V##i(2) >> LOG_R - 1) - V##i(2)) << 1 | V##i(0) >= (x + (1 << t >> 1)) * (V##i(2) >> LOG_R - 1) - V##i(2))

void D2D3M(int x0, int x1, int x2, int y0, int y1, int y2, int z, int O[], int x, int y, int t, unsigned Q)
{
    int i;

    if (O_)
        for (QD(y0, y1, y2, z, x, y, t, Q, O[8]);;) {
            Q = QF(Q);
            if (CNB(Q))
                break;
            B(Q);
        }
    else
        for (i = DIR(0);; t--, x += (i & 0x1) << t, y += i >> 1 << t, Q = QC(Q, i), i = DIR(0))
            if (i ^ DIR(1) || i ^ DIR(2) || i ^ DIR(3) || i ^ DIR(4) || i ^ DIR(5) || i ^ DIR(6) || i ^ DIR(7)) {
                int j, k;

                for (i = 7, j = ((V[2] & (256 << OH) - 1) < x2 + (128 << z)) << 2 | ((V[1] & (256 << OH) - 1) < x1 + (128 << z)) << 1 | (V[0] & (256 << OH) - 1) < x0 + (128 << z), k = i ^ j; i >= 0; i--, k = i ^ j)
                    if (O[k]) {
                        D2D3M(x0 + ((k & 0x1) << 8 << z - 1), x1 + ((k >> 1 & 0x1) << 8 << z - 1), x2 + (k >> 2 << 8 << z - 1), y0 + ((k << 31 >> 31 & B[0][0]) + (k << 30 >> 31 & B[1][0]) + (k << 29 >> 31 & B[2][0]) << z - 1), y1 + ((k << 31 >> 31 & B[0][1]) + (k << 30 >> 31 & B[1][1]) + (k << 29 >> 31 & B[2][1]) << z - 1), y2 + ((k << 31 >> 31 & B[0][2]) + (k << 30 >> 31 & B[1][2]) + (k << 29 >> 31 & B[2][2]) << z - 1), z - 1, O[k], x, y, t, Q);
                        if (NW(Q))
                            return;
                    }
                return;
            } else if (NW(QC(Q, i)))
                return;
}
#endif
#else
#define LU
#ifndef LU

void D2D3M(int x0, int x1, int x2, int y0, int y1, int y2, int z, int O[], int x, int y, int t, unsigned Q, int L0, int U0, int R0, int D0, int L1, int U1, int R1, int D1, int L2, int U2, int R2, int D2, int L3, int U3, int R3, int D3, int L4, int U4, int R4, int D4, int L5, int U5, int R5, int D5, int L6, int U6, int R6, int D6, int L7, int U7, int R7, int D7)
{
    int i;

    if (O_)
        for (QD(L(0), U(0), R(0), D(0), L(1), U(1), R(1), D(1), L(2), U(2), R(2), D(2), L(3), U(3), R(3), D(3), L(4), U(4), R(4), D(4), L(5), U(5), R(5), D(5), L(6), U(6), R(6), D(6), L(7), U(7), R(7), D(7), y0, y1, y2, z, x, y, t, Q, O[8]);;) {
            Q = QF(Q);
            if (CNB(Q))
                break;
            B(Q);
        }
    else
        for (;; --t, x += (i & 0x1) << t, y += i >> 1 << t, L0 = L4(0, i), U0 = U4(0, i), R0 = R4(0, i), D0 = D4(0, i), L1 = L4(1, i), U1 = U4(1, i), R1 = R4(1, i), D1 = D4(1, i), L2 = L4(2, i), U2 = U4(2, i), R2 = R4(2, i), D2 = D4(2, i), L3 = L4(3, i), U3 = U4(3, i), R3 = R4(3, i), D3 = D4(3, i), L4 = L4(4, i), U4 = U4(4, i), R4 = R4(4, i), D4 = D4(4, i), L5 = L4(5, i), U5 = U4(5, i), R5 = R4(5, i), D5 = D4(5, i), L6 = L4(6, i), U6 = U4(6, i), R6 = R4(6, i), D6 = D4(6, i), L7 = L4(7, i), U7 = U4(7, i), R7 = R4(7, i), D7 = D4(7, i), Q = QC(Q, i)) {
            if ((i = DIR(0)) ^ DIR(1) || i ^ DIR(2) || i ^ DIR(3) || i ^ DIR(4) || i ^ DIR(5) || i ^ DIR(6) || i ^ DIR(7)) {
                int j, k;

                for (i = 7, j = ((V[2] & (256 << OH) - 1) < x2 + (128 << z)) << 2 | ((V[1] & (256 << OH) - 1) < x1 + (128 << z)) << 1 | (V[0] & (256 << OH) - 1) < x0 + (128 << z), k = i ^ j; i >= 0; --i, k = i ^ j)
                    if (O[k]) {
                        D2D3M(x0 + ((k & 0x1) << 8 << z - 1), x1 + ((k >> 1 & 0x1) << 8 << z - 1), x2 + (k >> 2 << 8 << z - 1), y0 + ((k << 31 >> 31 & B[0][0]) + (k << 30 >> 31 & B[1][0]) + (k << 29 >> 31 & B[2][0]) << z - 1), y1 + ((k << 31 >> 31 & B[0][1]) + (k << 30 >> 31 & B[1][1]) + (k << 29 >> 31 & B[2][1]) << z - 1), y2 + ((k << 31 >> 31 & B[0][2]) + (k << 30 >> 31 & B[1][2]) + (k << 29 >> 31 & B[2][2]) << z - 1), z - 1, O[k], x, y, t, Q, L8(k, 0), U8(k, 0), R8(k, 0), D8(k, 0), L8(k, 1), U8(k, 1), R8(k, 1), D8(k, 1), L8(k, 2), U8(k, 2), R8(k, 2), D8(k, 2), L8(k, 3), U8(k, 3), R8(k, 3), D8(k, 3), L8(k, 4), U8(k, 4), R8(k, 4), D8(k, 4), L8(k, 5), U8(k, 5), R8(k, 5), D8(k, 5), L8(k, 6), U8(k, 6), R8(k, 6), D8(k, 6), L8(k, 7), U8(k, 7), R8(k, 7), D8(k, 7));
                        if (NW(Q))
                            return;
                    }
                return;
            }
            if (NW(QC(Q, i)))
                return;
        }
}
#else
#define L(i)    (&L0)[i << 1]
#define U(i)    (&U0)[i << 1]
#define R(i)    L##i + (V##i(2) << 1 >> LOG_R - t)
#define D(i)    U##i + (V##i(2) << 1 >> LOG_R - t)
#define DIR(i)  ((V##i(1) >= U##i + (V##i(2) >> LOG_R - t)) << 1 | V##i(0) >= L##i + (V##i(2) >> LOG_R - t))

void D2D3M(int x0, int x1, int x2, int y0, int y1, int y2, int z, int O[], int x, int y, int t, unsigned Q, int L0, int U0, int L1, int U1, int L2, int U2, int L3, int U3, int L4, int U4, int L5, int U5, int L6, int U6, int L7, int U7)
{
    int i;

    if (O_)
        for (QD(L(0), U(0), R(0), D(0), L(1), U(1), R(1), D(1), L(2), U(2), R(2), D(2), L(3), U(3), R(3), D(3), L(4), U(4), R(4), D(4), L(5), U(5), R(5), D(5), L(6), U(6), R(6), D(6), L(7), U(7), R(7), D(7), y0, y1, y2, z, x, y, t, Q, O[8] << 8 & 0xff0000 | O[8] >> 8 & 0xff00 | O[8] & 0xff);;) {
            Q = QF(Q);
            if (CNB(Q))
                break;
            B(Q);
        }
    else
        for (;; L0 += i << 31 >> 31 & V0(2) >> LOG_R - t, U0 += i << 30 >> 31 & V0(2) >> LOG_R - t, L1 += i << 31 >> 31 & V1(2) >> LOG_R - t, U1 += i << 30 >> 31 & V1(2) >> LOG_R - t, L2 += i << 31 >> 31 & V2(2) >> LOG_R - t, U2 += i << 30 >> 31 & V2(2) >> LOG_R - t, L3 += i << 31 >> 31 & V3(2) >> LOG_R - t, U3 += i << 30 >> 31 & V3(2) >> LOG_R - t, L4 += i << 31 >> 31 & V4(2) >> LOG_R - t, U4 += i << 30 >> 31 & V4(2) >> LOG_R - t, L5 += i << 31 >> 31 & V5(2) >> LOG_R - t, U5 += i << 30 >> 31 & V5(2) >> LOG_R - t, L6 += i << 31 >> 31 & V6(2) >> LOG_R - t, U6 += i << 30 >> 31 & V6(2) >> LOG_R - t, L7 += i << 31 >> 31 & V7(2) >> LOG_R - t, U7 += i << 30 >> 31 & V7(2) >> LOG_R - t, --t, x += (i & 0x1) << t, y += i >> 1 << t, Q = QC(Q, i)) {
            if ((i = DIR(0)) ^ DIR(1) || i ^ DIR(2) || i ^ DIR(3) || i ^ DIR(4) || i ^ DIR(5) || i ^ DIR(6) || i ^ DIR(7)) {
                int j, k;

                for (i = 7, j = ((V[2] & (256 << OH) - 1) < x2 + (128 << z)) << 2 | ((V[1] & (256 << OH) - 1) < x1 + (128 << z)) << 1 | (V[0] & (256 << OH) - 1) < x0 + (128 << z), k = i ^ j; i >= 0; --i, k = i ^ j)
                    if (O[k]) {
                        D2D3M(x0 + ((k & 0x1) << 8 << z - 1), x1 + ((k >> 1 & 0x1) << 8 << z - 1), x2 + (k >> 2 << 8 << z - 1), y0 + ((k << 31 >> 31 & B[0][0]) + (k << 30 >> 31 & B[1][0]) + (k << 29 >> 31 & B[2][0]) << z - 1), y1 + ((k << 31 >> 31 & B[0][1]) + (k << 30 >> 31 & B[1][1]) + (k << 29 >> 31 & B[2][1]) << z - 1), y2 + ((k << 31 >> 31 & B[0][2]) + (k << 30 >> 31 & B[1][2]) + (k << 29 >> 31 & B[2][2]) << z - 1), z - 1, O[k], x, y, t, Q, L8(k, 0), U8(k, 0), L8(k, 1), U8(k, 1), L8(k, 2), U8(k, 2), L8(k, 3), U8(k, 3), L8(k, 4), U8(k, 4), L8(k, 5), U8(k, 5), L8(k, 6), U8(k, 6), L8(k, 7), U8(k, 7));
                        if (NW(Q))
                            return;
                    }
                return;
            }
            if (NW(QC(Q, i)))
                return;
        }
}

void M3D2D(int x, int y, int t, int y0, int y1, int y2, int z, int O[])
{
    int i, j, k;

    if (i = CODE()) {
        if (i & i >> 4 & i >> 8 & i >> 12 & i >> 16 & i >> 20 & i >> 24 & (unsigned)i >> 28)
            return;
        if (!O_) {
            for (i = 7, j = ((V[2] & (256 << OH) - 1) < t + (128 << z)) << 2 | ((V[1] & (256 << OH) - 1) < y + (128 << z)) << 1 | (V[0] & (256 << OH) - 1) < x + (128 << z), k = i ^ j; i >= 0; --i, k = i ^ j)
                if (O[k]) {
                    M3D2D(x + ((k & 0x1) << 8 << z - 1), y + ((k >> 1 & 0x1) << 8 << z - 1), t + (k >> 2 << 8 << z - 1), y0 + ((k << 31 >> 31 & B[0][0]) + (k << 30 >> 31 & B[1][0]) + (k << 29 >> 31 & B[2][0]) << z - 1), y1 + ((k << 31 >> 31 & B[0][1]) + (k << 30 >> 31 & B[1][1]) + (k << 29 >> 31 & B[2][1]) << z - 1), y2 + ((k << 31 >> 31 & B[0][2]) + (k << 30 >> 31 & B[1][2]) + (k << 29 >> 31 & B[2][2]) << z - 1), z - 1, O[k]);
                    if (NW(3))
                        return;
                }
            return;
        }
    }
    D2D3M(x, y, t, y0, y1, y2, z, O, 0, 0, LOG_R, 3, -V0(2), -V0(2), -V1(2), -V1(2), -V2(2), -V2(2), -V3(2), -V3(2), -V4(2), -V4(2), -V5(2), -V5(2), -V6(2), -V6(2), -V7(2), -V7(2));
}
#endif
#endif
#ifndef LU

void M3D2D(int x, int y, int t, int y0, int y1, int y2, int z, int O[])
{
    int i, j, k;

    if (i = CODE()) {
        if (i & i >> 4 & i >> 8 & i >> 12 & i >> 16 & i >> 20 & i >> 24 & (unsigned)i >> 28)
            return;
        if (!O_) {
            for (i = 7, j = ((V[2] & (256 << OH) - 1) < t + (128 << z)) << 2 | ((V[1] & (256 << OH) - 1) < y + (128 << z)) << 1 | (V[0] & (256 << OH) - 1) < x + (128 << z), k = i ^ j; i >= 0; --i, k = i ^ j)
                if (O[k]) {
                    M3D2D(x + ((k & 0x1) << 8 << z - 1), y + ((k >> 1 & 0x1) << 8 << z - 1), t + (k >> 2 << 8 << z - 1), y0 + ((k << 31 >> 31 & B[0][0]) + (k << 30 >> 31 & B[1][0]) + (k << 29 >> 31 & B[2][0]) << z - 1), y1 + ((k << 31 >> 31 & B[0][1]) + (k << 30 >> 31 & B[1][1]) + (k << 29 >> 31 & B[2][1]) << z - 1), y2 + ((k << 31 >> 31 & B[0][2]) + (k << 30 >> 31 & B[1][2]) + (k << 29 >> 31 & B[2][2]) << z - 1), z - 1, O[k]);
                    if (NW(3))
                        return;
                }
            return;
        }
    }
    D2D3M(x, y, t, y0, y1, y2, z, O, 0, 0, LOG_R, 3
#ifndef MUL
                                                    , -V0(2), -V0(2), V0(2), V0(2), -V1(2), -V1(2), V1(2), V1(2), -V2(2), -V2(2), V2(2), V2(2), -V3(2), -V3(2), V3(2), V3(2), -V4(2), -V4(2), V4(2), V4(2), -V5(2), -V5(2), V5(2), V5(2), -V6(2), -V6(2), V6(2), V6(2), -V7(2), -V7(2), V7(2), V7(2)
#endif
);
}
#endif
#endif
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

            QR();
#ifndef LU
            M3D2D(0, 0, 0, V(0, 0), V(0, 1), V(0, 2), OH, octrees, 0, 0, LOG_R + 2, 3
#ifdef PURE
                                                                                    , -(V(0, 2) << 2) - V(0, 2), -(V(0, 2) << 2) - V(0, 2), (V(0, 2) << 1) + V(0, 2), (V(0, 2) << 1) + V(0, 2), -(V(1, 2) << 2) - V(1, 2), -(V(1, 2) << 2) - V(1, 2), (V(1, 2) << 1) + V(1, 2), (V(1, 2) << 1) + V(1, 2), -(V(2, 2) << 2) - V(2, 2), -(V(2, 2) << 2) - V(2, 2), (V(2, 2) << 1) + V(2, 2), (V(2, 2) << 1) + V(2, 2), -(V(3, 2) << 2) - V(3, 2), -(V(3, 2) << 2) - V(3, 2), (V(3, 2) << 1) + V(3, 2), (V(3, 2) << 1) + V(3, 2), -(V(4, 2) << 2) - V(4, 2), -(V(4, 2) << 2) - V(4, 2), (V(4, 2) << 1) + V(4, 2), (V(4, 2) << 1) + V(4, 2), -(V(5, 2) << 2) - V(5, 2), -(V(5, 2) << 2) - V(5, 2), (V(5, 2) << 1) + V(5, 2), (V(5, 2) << 1) + V(5, 2), -(V(6, 2) << 2) - V(6, 2), -(V(6, 2) << 2) - V(6, 2), (V(6, 2) << 1) + V(6, 2), (V(6, 2) << 1) + V(6, 2), -(V(7, 2) << 2) - V(7, 2), -(V(7, 2) << 2) - V(7, 2), (V(7, 2) << 1) + V(7, 2), (V(7, 2) << 1) + V(7, 2)
#endif
            );
#else
            M3D2D(0, 0, 0, V(0, 0), V(0, 1), V(0, 2), OH, octrees, 0, 0, LOG_R + 2, 3, -V(0, 2), -V(0, 2), -V(1, 2), -V(1, 2), -V(2, 2), -V(2, 2), -V(3, 2), -V(3, 2), -V(4, 2), -V(4, 2), -V(5, 2), -V(5, 2), -V(6, 2), -V(6, 2), -V(7, 2), -V(7, 2));
#endif
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
