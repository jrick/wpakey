PROG=		wpakey
SRCS=		wpakey.c

LDADD = -lutil
NOMAN = Yes

.include <bsd.prog.mk>
