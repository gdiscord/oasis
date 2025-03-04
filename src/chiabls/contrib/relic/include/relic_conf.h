/* contrib/relic/include/relic_conf.h.  Generated from relic_conf.h.in by configure.  */
/* contrib/relic/include/relic_conf.h.in.  Generated from configure.ac by autoheader.  */

#ifndef RLC_CONF_H

#define RLC_CONF_H

/* Byte boundary to align digit vectors. */
#define ALIGN 1

/* Chosen memory allocation policy. */
#define ALLOC AUTO

/* Almost inverse algorithm. */
#define ALMOS 3

/* ANSI-compatible timer. */
#define ANSI 5

/* Architecture. */
#define ARCH X64

/* Arithmetic backend. */
#define ARITH GMP

/* ARM 32-bit architecture. */
#define ARM 3

/* Automatic memory allocation. */
#define AUTO 1

/* Atmel AVR ATMega128 8-bit architecture. */
#define AVR 1

/* BLAKE2s-160 hash function. */
#define B2S160 6

/* BLAKE2s-256 hash function. */
#define B2S256 7

/* Basic method. */
#define BASIC 1

/* Binary inversion. */
#define BINAR 2

/* Chosen multiple precision greatest common divisor method. */
#define BN_GCD BASIC

/* Chosen prime generation algorithm. */
#define BN_GEN BASIC

/* Number of Karatsuba steps. */
#define BN_KARAT 0

/* Effective size of a multiple precision integer. */
#define BN_MAGNI DOUBLE

/* Multiple precision arithmetic method. */
#define BN_METHD "COMBA;COMBA;MONTY;SLIDE;BASIC;BASIC"

/* Chosen multiple precision modular reduction method. */
#define BN_MOD MONTY

/* Chosen multiple precision multiplication method. */
#define BN_MUL COMBA

/* Chosen multiple precision modular exponentiation method. */
#define BN_MXP SLIDE

/* Required precision in bits. */
#define BN_PRECI 1024

/* Chosen multiple precision multiplication method. */
#define BN_SQR COMBA

/* Hardware-friendly inversion by Brunner-Curiger-Hofstetter. */
#define BRUCH 6

/* Override library generator with the callback. */
#define CALL 4

/* A multiple precision integer can store the result of an addition. */
#define CARRY 1

/* Binary curves. */
#define CHAR2 2

/* Comba method. */
#define COMBA 2

/* Double-table comb method. */
#define COMBD 3

/* Single-table comb method. */
#define COMBS 2

/* Support for faster CRT-based exponentiation in factoring-based
   cryptosystems. */
#define CP_CRT /**/

/* Chosen RSA padding method. */
#define CP_RSAPD PKCS2

/* Constant-time version of almost inverse. */
#define CTAIA 7

/* Cycle-counting timer. */
#define CYCLE 6

/* Constant-time inversion by Bernstein-Yang division steps. */
#define DIVST 5

/* A multiple precision integer can store the result of a multiplication. */
#define DOUBLE 2

/* Android operating system. */
#define DROID 5

/* Arduino platform. */
#define DUINO 6

/* Dynamic memory allocation. */
#define DYNAMIC 2

/* Easy C-only backend. */
#define EASY 1

/* Chosen binary elliptic curve coordinate method. */
#define EB_ADD PROJC

/* Width of precomputation table for fixed point methods. */
#define EB_DEPTH 4

/* Chosen binary elliptic curve point multiplication method. */
#define EB_FIX COMBS

/* Support for Koblitz anomalous binary curves. */
#define EB_KBLTZ /**/

/* Binary elliptic curve arithmetic method. */
#define EB_METHD "PROJC;LWNAF;COMBS;INTER"

/* Use mixed coordinates. */
#define EB_MIXED /**/

/* Chosen binary elliptic curve point multiplication method. */
#define EB_MUL LWNAF

/* Support for ordinary curves without endormorphisms. */
#define EB_PLAIN /**/

/* Build precomputation table for generator. */
#define EB_PRECO /**/

/* Chosen binary elliptic curve simulteanous point multiplication method. */
#define EB_SIM INTER

/* Width of window processing for unknown point methods. */
#define EB_WIDTH 4

/* Chosen elliptic curve type. */
#define EC_CUR PRIME

/* Chosen elliptic curve cryptography method. */
#define EC_METHD "PRIME"

/* Edwards curves. */
#define EDDIE 3

/* Chosen binary elliptic curve coordinate method. */
#define ED_ADD PROJC

/* Width of precomputation table for fixed point methods. */
#define ED_DEPTH 4

/* Chosen prime elliptic twisted Edwards curve point multiplication method. */
#define ED_FIX COMBS

/* Edwards elliptic curve arithmetic method. */
#define ED_METHD "PROJC;LWNAF;COMBS;INTER"

/* Chosen prime elliptic twisted Edwards curve point multiplication method. */
#define ED_MUL LWNAF

/* Build precomputation table for generator. */
#define ED_PRECO /**/

/* Chosen prime elliptic curve simulteanous point multiplication method. */
#define ED_SIM INTER

/* Width of window processing for unknown point methods. */
#define ED_WIDTH 4

/* Chosen prime elliptic curve coordinate method. */
#define EP_ADD PROJC

/* Enable isogeny map for SSWU map-to-curve. */
#define EP_CTMAP /**/

/* Width of precomputation table for fixed point methods. */
#define EP_DEPTH 4

/* Support for prime curves with efficient endormorphisms. */
#define EP_ENDOM /**/

/* Chosen prime elliptic curve point multiplication method. */
#define EP_FIX COMBS

/* Prime elliptic curve arithmetic method. */
#define EP_METHD "PROJC;LWNAF;COMBS;INTER"

/* Use mixed coordinates. */
#define EP_MIXED /**/

/* Chosen prime elliptic curve point multiplication method. */
#define EP_MUL LWNAF

/* Build precomputation table for generator. */
#define EP_PRECO /**/

/* Chosen prime elliptic curve simulteanous point multiplication method. */
#define EP_SIM INTER

/* Width of window processing for unknown point methods. */
#define EP_WIDTH 4

/* Extended Euclidean algorithm. */
#define EXGCD 4

/* Extended projective twisted Edwards coordinates. */
#define EXTND 3

/* Chosen multiple precision modular exponentiation method. */
#define FB_EXP SLIDE

/* Chosen binary field inversion method. */
#define FB_INV EXGCD

/* Chosen method to solve a quadratic equation. */
#define FB_ITR QUICK

/* Number of Karatsuba levels. */
#define FB_KARAT 0

/* Binary field arithmetic method */
#define FB_METHD "LODAH;QUICK;QUICK;QUICK;QUICK;QUICK;EXGCD;SLIDE;QUICK"

/* Chosen binary field multiplication method. */
#define FB_MUL LODAH

/* Irreducible polynomial size in bits. */
#define FB_POLYN 283

/* Precompute multiplication table for sqrt(z). */
#define FB_PRECO /**/

/* Chosen binary field modular reduction method. */
#define FB_RDC QUICK

/* Chosen method to solve a quadratic equation. */
#define FB_SLV QUICK

/* Chosen binary field squaring method. */
#define FB_SQR QUICK

/* Chosen binary field modular reduction method. */
#define FB_SRT QUICK

/* Chosen trace computation method. */
#define FB_TRC QUICK

/* Prefer trinomials over pentanomials. */
#define FB_TRINO /**/

/* Width of window processing for exponentiation methods. */
#define FB_WIDTH 4

/* Chosen extension field arithmetic method. */
#define FPX_CBC INTEG

/* Prime extension field arithmetic method. */
#define FPX_METHD "INTEG;INTEG;LAZYR"

/* Chosen extension field arithmetic method. */
#define FPX_QDR INTEG

/* Chosen extension field arithmetic method. */
#define FPX_RDC LAZYR

/* Chosen prime field multiplication method. */
#define FP_ADD INTEG

/* Chosen multiple precision modular exponentiation method. */
#define FP_EXP SLIDE

/* Chosen prime field inversion method. */
#define FP_INV LOWER

/* Number of Karatsuba steps. */
#define FP_KARAT 0

/* Prime field arithmetic method. */
#define FP_METHD "INTEG;INTEG;INTEG;MONTY;LOWER;SLIDE"

/* Chosen prime field multiplication method. */
#define FP_MUL INTEG

/* Prime field size in bits. */
#define FP_PRIME 381

/* Use -1 as quadratic non-residue. */
#define FP_QNRES /**/

/* Chosen prime field reduction method. */
#define FP_RDC MONTY

/* Chosen prime field multiplication method. */
#define FP_SQR INTEG

/* Width of window processing for exponentiation methods. */
#define FP_WIDTH 4

/* FreeBSD operating system. */
#define FREEBSD 2

/* GMP backend. */
#define GMP 2

/* GMP constant-time backend. */
#define GMP_SEC 3

/* Halving. */
#define HALVE 3

/* NIST HASH-DRBG generator. */
#define HASHD 1

/* define if the compiler supports basic C++14 syntax */
#define HAVE_CXX14 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define if you have POSIX threads libraries and header files. */
#define HAVE_PTHREAD 1

/* Have PTHREAD_PRIO_INHERIT. */
#define HAVE_PTHREAD_PRIO_INHERIT 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Per-process high-resolution timer. */
#define HPROC 2

/* Per-process high-resolution timer. */
#define HREAL 1

/* Per-thread high-resolution timer. */
#define HTHRD 3

/* Integrated modular addtion. */
#define INTEG 3

/* Interleaving of w-(T)NAFs. */
#define INTER 3

/* Itoh-Tsuji inversion. */
#define ITOHT 5

/* Jacobian coordinates. */
#define JACOB 3

/* Joint sparse form. */
#define JOINT 4

/* Lazy-reduced extension field arithmetic. */
#define LAZYR 2

/* Lehmer's fast GCD Algorithm. */
#define LEHME 2

/* Standard C library generator. */
#define LIBC 1

/* GNU/Linux operating system. */
#define LINUX 1

/* Lopez-Dahab multiplication. */
#define LODAH 2

/* Use implementation provided by the lower layer. */
#define LOWER 8

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#define LT_OBJDIR ".libs/"

/* Left-to-right Width-w NAF. */
#define LWNAF 4

/* Left-to-right Width-w NAF. */
#define LWREG 5

/* MacOS operating system. */
#define MACOSX 3

/* Chosen hash function. */
#define MD_MAP SH256

/* Choice of hash function. */
#define MD_METHD "SH256"

/* Montgomery method. */
#define MONTY 3

/* MSP430 16-bit architecture. */
#define MSP 2

/* Chosen multithreading API. */
#define MULTI PTHREAD

/* Reuse multiplication for squaring. */
#define MULTP 4

/* Optimal ate pairing. */
#define OATEP 3

/* OpenBSD operating system. */
#define OPENBSD 7

/* OpenMP multithreading support. */
#define OPENMP 1

/* Detected operation system. */
#define OPSYS MACOSX

/* Name of package */

/* Define to the address where bug reports for this package should be sent. */

/* Define to the full name of this package. */

/* Define to the full name and version of this package. */

/* Define to the one symbol short name of this package. */

/* Define to the home page for this package. */

/* Define to the version of this package. */

/* Performance monitoring framework. */
#define PERF 7

/* RSA PKCS#1 v1.5 padding. */
#define PKCS1 2

/* RSA PKCS#1 v2.1 padding. */
#define PKCS2 3

/* Pseudo-Mersenne method. */
#define PMERS 4

/* POSIX-compatible timer. */
#define POSIX 4

/* Chosen extension field arithmetic method. */
#define PP_EXT LAZYR

/* Chosen pairing method over prime elliptic curves. */
#define PP_MAP OATEP

/* Bilinear pairing method. */
#define PP_METHD "LAZYR;OATEP"

/* Prime curves. */
#define PRIME 1

/* Projective coordinates. */
#define PROJC 2

/* POSIX multithreading support. */
#define PTHREAD 2

/* Define to necessary symbol if this constant uses a non-standard name on
   your system. */
/* #undef PTHREAD_CREATE_JOINABLE */

/* Fast reduction modulo special form prime. */
#define QUICK 2

/* Chosen random generator. */
#define RAND HASHD

/* Intel RdRand instruction. */
#define RDRND 2

/* Relic Version */
#define RLC_VERSION "0.5.0"

/* Safe prime generation. */
#define SAFEP 2

/* Chosen random generator seeder. */
#define SEED UDEV

/* SHA-224 hash function. */
#define SH224 2

/* SHA-256 hash function. */
#define SH256 3

/* SHA-384 hash function. */
#define SH384 4

/* SHA-512 hash function. */
#define SH512 5

/* A multiple precision integer can store w words. */
#define SINGLE 0

/* Sliding window modular exponentiation. */
#define SLIDE 2

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Stein's binary GCD Algorithm. */
#define STEIN 3

/* Strong prime generation. */
#define STRON 3

/* Tate pairing. */
#define TATEP 1

/* Chosen timer. */
#define TIMER CYCLE

/* Shamir's trick. */
#define TRICK 2

/* Operating system underlying generator. */
#define UDEV 3

/* Version number of package */

/* Use Windows' CryptGenRandom. */
#define WCGR 4

/* Weil pairing. */
#define WEILP 2

/* Windows operating system. */
#define WINDOWS 4

/* Build block ciphers. */
#define WITH_BC /**/

/* Build multiple precision integer module. */
#define WITH_BN /**/

/* Build cryptographic protocols. */
#define WITH_CP /**/

/* Temporary double-precision digit vectors. */
#define WITH_DV /**/

/* Build binary elliptic curve module. */
#define WITH_EB /**/

/* Build elliptic curve cryptography module. */
#define WITH_EC /**/

/* Build elliptic Edwards curve module. */
#define WITH_ED /**/

/* Build prime elliptic curve module. */
#define WITH_EP /**/

/* Build prime field extension elliptic curve module. */
#define WITH_EPX /**/

/* Build binary field module. */
#define WITH_FB /**/

/* Build binary field extension module. */
#define WITH_FBX /**/

/* Build prime field module. */
#define WITH_FP /**/

/* Build prime field extension module. */
#define WITH_FPX /**/

/* Build hash functions. */
#define WITH_MD /**/

/* Build Multi-party computation primitives. */
#define WITH_MPC /**/

/* Build pairing-based cryptography module. */
#define WITH_PC /**/

/* Build pairings over prime curves module. */
#define WITH_PP /**/

/* Size of word in this architecture. */
#define WSIZE 64

/* AMD64-compatible 64-bit architecture. */
#define X64 5

/* Intel x86-compatible 32-bit architecture. */
#define X86 4

#endif /*RLC_CONF_H*/
