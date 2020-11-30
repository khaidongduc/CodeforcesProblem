#include <stdio.h>

class FastIO {
public:
	static int readInt() {
		char c;
		for (c = getchar(); c != '-' && (c > '9' || c < '0'); c = getchar());
		int res, sgn = 1;
		if (c == '-') sgn = -1, res = 0;
		else res = c - '0';
		for (c = getchar(); '0' <= c && c <= '9'; c = getchar())
			(res *= 10) += c - '0';
		return res * sgn;
	}
 
	static void writeInt(int x) {
		if (x < 0) putchar('-'), x = -x;
		writePosInt(x);
	}
private:
	static void writePosInt(int x) {
		if (x > 10) writePosInt(x / 10);
		putchar(x % 10 + '0');
	}
};

int main() {
    int num = FastIO::readInt();
    FastIO::writeInt(num);   
}