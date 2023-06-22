/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Points: 3
 */
int bitAnd(int x, int y) {
  return ~(~x|~y);
}

/* 
 * getByte - Extract nth byte from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + - << >>
 *   Points: 6
 */
int getByte(int x, int n) {
  return (x >> (n << 3)) & 0xff;
}

/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + - << >>
 *  Points: 6
 */
int byteSwap(int x, int n, int m) {
    int y = 0;
    n = n << 3;
    m = m << 3;
    y = 0xff & ((x >> n) ^ (x >> m));
    x = x ^ (y << n);
    x = x ^ (y << m);
    return x;
}

/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + - << >>
 *   Points: 10
 */
int logicalShift(int x, int n) {
  	int iff = ~(!n + ~0);
	int y = ((x >> 1) & ~(1 << 31)) >> (n + ~0);

	return (iff&x) | (~iff&y);
}

/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + - << >>
 *   Points: 15
 */
int bitCount(int x) {
  	int masking = 1 + (1 << 8) + (1 << 16) + (1 << 24);
	int sum = ((x >> 0) & masking) + ((x >> 1) & masking) +
		  ((x >> 2) & masking) + ((x >> 3) & masking) +
		  ((x >> 4) & masking) + ((x >> 5) & masking) +
                  ((x >> 6) & masking) + ((x >> 7) & masking);

	return ((sum >> 0) & 0xff) + ((sum >> 8) & 0xff) +
	       ((sum >> 16) & 0xff) + ((sum >> 24) & 0xff);
}

/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + - << >>
 *   Points: 15
 */
int bang(int x) {
  int minX = ~x + 1;
  int xMs = (x >> 31) & 1;
  int minXms = (minX >> 31) & 1;
  int xNot0 = xMs | minXms;

  return ~xNot0 & 1;
}

/*
 * bitParity - returns 1 if x contains an odd number of 1's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + - << >>
 *   Points: 15
 */
int bitParity(int x) {
  	x ^= x >> 1;
	x ^= x >> 2;
	x ^= x >> 4;
	x ^= x >> 8;
	x ^= x >> 16;

	return x & 0x01;
}
