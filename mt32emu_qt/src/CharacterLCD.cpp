#ifdef WITH_CHARACTER_LCD

#include "CharacterLCD.h"
#include <wiringSerial.h>
#include <termios.h>

static int serialHandle;

void OpenSerial() {
	serialHandle = serialOpen("/dev/ttyAMA0", 19200);
	
	struct termios options;
	tcgetattr(serialHandle, &options);
	options.c_cflag &= ~CSIZE;
	options.c_cflag |= CS8;
	options.c_cflag |= PARENB;
	tcsetattr(serialHandle, TCSANOW, &options);
	
	SerialWrite(0x16);
	ClearScreen();
}

void CloseSerial() {
	ClearScreen();
	
	serialClose(serialHandle);
}

void SerialWrite(const unsigned char c) {
	serialPutchar(serialHandle, c);
}

void SerialWrite(const char *s) {
	serialPuts(serialHandle, s);
}

void ClearScreen() {
	SerialWrite(D_CLR);
	SerialWrite(D_CR);
}

#endif
