#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <util.h>

__dead static void	usage(void);
static void		print_key(const u_int8_t *, size_t);

int
main(int argc, char *argv[])
{
	u_int8_t key[32];
	const char *nwid, *pass;
	size_t nwidlen, passlen;

	if (unveil("/", "") == -1)
		err(1, "unveil");
	if (pledge("stdio", NULL) == -1)
		err(1, "pledge");

	if (argc != 3)
		usage();

	nwid = argv[1];
	nwidlen = strlen(nwid);
	pass = argv[2];
	passlen = strlen(pass);

	if (nwidlen > 32)
		errx(1, "nwid length must not exceed 32 bytes");
	if (passlen < 8 || passlen > 63)
		errx(1, "passphrase must be between 8 and 63 bytes");

	if (pkcs5_pbkdf2(pass, passlen, nwid, nwidlen, key, sizeof(key),
	    4096) == -1)
		err(1, "pkcs5_pbkdf2");

	print_key(key, sizeof(key));

	return 0;
}

__dead static void
usage(void)
{
	fprintf(stderr, "usage: %s nwid passphrase\n", getprogname());
	exit(2);
}

static void
print_key(const u_int8_t *key, size_t len)
{
	unsigned int i;

	printf("0x");
	for (i = 0; i < len; i++)
		printf("%02x", key[i]);
	putchar('\n');
}
