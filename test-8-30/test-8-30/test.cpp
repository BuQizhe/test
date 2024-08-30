//#include<iostream>
//#include<Windows.h>
//using namespace std;
//#define scta(a) SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE),a);
//int main() {
//    scta(0xf0);
//    cout << "Hello,World!\n";
//    scta(243);
//    cout << "Hello,World!\n";
//    return 0;
//}

#include<iostream>
#include<Windows.h>
#include<wchar.h>
using namespace std;
int color(int r1, int g1, int b1, int r2, int g2, int b2) {
	HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hd == INVALID_HANDLE_VALUE) return GetLastError();
	DWORD dm = 0;
	if (!GetConsoleMode(hd, &dm)) return GetLastError();
	dm |= 0x0004;
	if (!SetConsoleMode(hd, dm)) return GetLastError();
	wprintf(L"\x1b[38;2;%d;%d;%d\x1b[48;2;%d;%d;%dmHello,World!", r2, g2, b2, r1, g1, b1);
}
int main() {
	color(128, 237, 180, 7, 82, 14);
	return 0;
}