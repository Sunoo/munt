#ifdef WITH_CHARACTER_LCD

#include <QDebug>

#include "CharacterLCD.h"
#include <wiringSerial.h>

static int serialHandle;

void OpenSerial() {
	serialHandle = serialOpen("/dev/ttyAMA0", 19200);
}

void CloseSerial() {
	serialClose(serialHandle);
}

void SerialWrite(const unsigned char c) {
	serialPutchar(serialHandle, c);
	qDebug() << (char)c;
}

void SerialWrite(const char *s) {
	serialPuts(serialHandle, s);
	qDebug() << s;
}

#endif
