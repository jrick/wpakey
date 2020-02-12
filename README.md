# wpakey

wpakey is a simple tool to derive 32-byte WPA-PSK encryption keys, outputting
keys in hexadecimal format.

This tool has been occasionally useful in OpenBSD hostname.if(5) configuration
files where WiFi passwords contain special characters that are difficult or
impossible to escape correctly.  Luckily, ifconfig(8) allows keys to
additionally be written in hexadecimal form.
