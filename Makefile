PROG=		wpakey
SRCS=		wpakey.c

CFLAGS += -Werror -Wall -Wunused-variable

LDADD = -lutil
NOMAN = Yes

PREFIX ?= /usr/local
BINDIR ?= ${PREFIX}/bin
.if "${BINDIR}" == "${HOME}/bin"
BINOWN ?= ${USER}
BINGRP != id -g -n
.endif

.include <bsd.prog.mk>
