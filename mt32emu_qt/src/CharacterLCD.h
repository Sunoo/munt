#define D_BS 0x08
#define D_HT 0x09
#define D_LF 0x0A
#define D_FF 0x0C
#define D_CR 0x0D
#define D_CLR 0x0E
#define D_ESC 0x1B

void OpenSerial();
void CloseSerial();
void SerialWrite(const unsigned char c);
void SerialWrite(const char *s);
void ClearScreen();
