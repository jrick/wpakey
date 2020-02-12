package main

import (
	"crypto/sha1"
	"flag"
	"fmt"
	"os"

	"golang.org/x/crypto/pbkdf2"
)

var password = flag.String("password", "", "password (8-63 characters)")
var nwid = flag.String("nwid", "", "nwid (up to 32 characters)")

func main() {
	flag.Parse()
	switch {
	case len(*password) < 8, len(*password) > 63, len(*nwid) > 32:
		flag.Usage()
		os.Exit(2)
	}
	key := pbkdf2.Key([]byte(*password), []byte(*nwid), 4096, 32, sha1.New)
	fmt.Printf("%#x\n", key)
}
