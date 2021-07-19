#include <REG51F.H>
#include <string.h>

//--------------- Preprocessor Declaration ---------------//
#define MAX_LEN_RFID_STRING		12
#define Newline		TransmitString("\r\n");
#define DEBUG

//------------- Functions Prototypes ---------------------//
void InitUart(void);
void Transmit(unsigned char Abyte);
void TransmitString(unsigned char *Abyte);
unsigned char Receive(void);
void Delay(unsigned long int time);

unsigned char *ReceiveString(void);
int CompareRfid(unsigned char *Str1, unsigned char *Str2);

//-------------------- Variable Declarations -----------------//
unsigned char ADefaltString[][MAX_LEN_RFID_STRING+1] = {
	"1234567890ab",
	"abcdefghijkl",
	"12345abcdefg",
};


void main(void) {
	unsigned char *AReceiveId;
	int Status = 0;
	int Idx=0;

	//memset(AReceiveId, 0, sizeof(AReceiveId));
	InitUart();
#ifdef DEBUG
	TransmitString("RFID Testing...\r\n");
#endif

	while(1) {
		AReceiveId = ReceiveString();
		for (Idx=0; Idx<3; Idx++) {
#ifdef DEBUG
			TransmitString(AReceiveId);
			Newline;
			TransmitString(ADefaltString[Idx]);
			Newline;
#endif
			Status = CompareRfid(AReceiveId, ADefaltString[Idx]);
			if (1 == Status) {
#ifdef DEBUG
				TransmitString("Compared\r\n");
#endif
				P0 = 0x55;
			}
			else {
#ifdef DEBUG
				TransmitString("Not Compared\r\n");
#endif
				P0 = 0xAA;
			}
			Delay(500);
			P0 = 0x00;
			Delay(500);
		}
#ifdef DEBUG
		Newline;
		Newline;
#endif
	}
}

unsigned char *ReceiveString(void) {
	static unsigned char AString[MAX_LEN_RFID_STRING + 1];
	int Idx = 0;

	memset(AString, 0, sizeof(AString));
	for (Idx=0; Idx<MAX_LEN_RFID_STRING; Idx++) {
		AString[Idx] = Receive();
	}
	AString[Idx] = '\0';
	
	return (AString);
}

int CompareRfid(unsigned char *Str1, unsigned char *Str2) {
	int Status = 0;

	if (0 == strcmp(Str1, Str2))
		Status = 1;
	else
		Status = 0;

	return (Status);	
}

void InitUart(void) {
	TMOD = 0x20;
	TH1 = 0xFD;
	TR1 = 1;
	SCON = 0x50;
}

void Transmit(unsigned char Abyte) {
	SBUF = Abyte;	
	while (0 == TI);
	TI = 0;
}

void TransmitString(unsigned char *Abyte) {
	while ('\0' != *Abyte) {
		Transmit(*Abyte);
		Abyte++;
	}
}

unsigned char Receive(void) {
	unsigned char Abyte;

	while(0 == RI);
	Abyte = SBUF;
	RI = 0;

	return (Abyte);
}

void Delay(unsigned long int time) {			  //Delay Function
	unsigned long int i;
	unsigned int j;

	for(i=0;i<time;i++){
		for(j=0;j<120;j++){}
	}
}