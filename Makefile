PROG=		wpakey
SRCS=		wpakey.c

CFLAGS += -Werror -Wall -Wunused-variable

LDADD = -lutil
NOMAN = Yes

.include <bsd.prog.mk>
