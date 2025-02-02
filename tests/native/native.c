#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "native.h"
#include "utf8.h"

LIB_EXPORT int take_0(void) {
	return 0;
}
LIB_EXPORT int take_1(int a1) {
	return 1;
}
LIB_EXPORT int take_2(int a1, int a2) {
	return 2;
}
LIB_EXPORT int take_3(int a1, int a2, int a3) {
	return 3;
}
LIB_EXPORT int take_4(int a1, int a2, int a3, int a4) {
	return 4;
}
LIB_EXPORT int take_5(int a1, int a2, int a3, int a4, int a5) {
	return 5;
}
LIB_EXPORT int take_6(int a1, int a2, int a3, int a4, int a5, int a6) {
	return 6;
}
LIB_EXPORT int take_7(int a1, int a2, int a3, int a4, int a5, int a6, int a7) {
	return 7;
}
LIB_EXPORT int take_8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8) {
	return 8;
}
LIB_EXPORT int take_9(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9) {
	return 9;
}
LIB_EXPORT int take_10(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10) {
	return 10;
}
LIB_EXPORT void nop(void) {}

LIB_EXPORT int add_ints(int a, int b) {
	return a + b;
}
LIB_EXPORT unsigned int add_uints(unsigned int a, unsigned int b) {
	return a + b;
}
LIB_EXPORT double add_floats(double a, double b) {
	return a + b;
}
LIB_EXPORT bool logic_and(bool a, bool b) {
	return a && b;
}
LIB_EXPORT bool logic_or(bool a, bool b) {
	return a || b;
}
LIB_EXPORT int logic_ternary(bool a, int b, int c) {
	return a ? b : c;
}

LIB_EXPORT char *id_string(char *a) {
	return strdup(a);
}
LIB_EXPORT char *rev_string(char *a) {
	int len = strlen(a);
	char *ret = malloc(len + 1);
	int *cc = malloc(len * sizeof(int));
	int pos = 0;
	while (*a != 0) cc[pos++] = utf8_decode((unsigned char **)&a);
	char *retcur = ret;
	while (pos >= 0) utf8_encode((unsigned char **)&retcur, cc[--pos]);
	return ret;
}

LIB_EXPORT unsigned char *id_bytes(unsigned char *a, size_t b) {
	return memcpy(malloc(b), a, b);
}
LIB_EXPORT unsigned char *id_bytes_1(unsigned char *a, unsigned char *c, size_t b) {
	return memcpy(malloc(b), a, b);
}
LIB_EXPORT unsigned char *id_bytes_2(unsigned char *c, unsigned char *a, size_t b) {
	return memcpy(malloc(b), a, b);
}
LIB_EXPORT unsigned char *id_bytes_3(unsigned char *a, size_t b, unsigned char *c) {
	return memcpy(malloc(b), a, b);
}
LIB_EXPORT unsigned char *id_bytes_4(unsigned char *c, size_t b, unsigned char *a) {
	return memcpy(malloc(b), a, b);
}
LIB_EXPORT unsigned char *id_bytes_5(size_t b, unsigned char *a, unsigned char *c) {
	return memcpy(malloc(b), a, b);
}
LIB_EXPORT unsigned char *id_bytes_6(size_t b, unsigned char *c, unsigned char *a) {
	return memcpy(malloc(b), a, b);
}
LIB_EXPORT unsigned char *give_bytes(int n, size_t *ret_size) {
	unsigned char *ret = malloc(n);
	for (int i = 0; i < n; i++) ret[i] = i + 1;
	*ret_size = n;
	return ret;
}
