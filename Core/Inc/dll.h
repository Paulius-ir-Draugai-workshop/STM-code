#ifndef _DLL_H
#define _DLL_H
#include <stdint.h>

#define MAX_MAILBOX 4
#define MAILBOX_SIZE 4096
//#define COMPILE_STANDALONE_DLL

enum {
	DLL_NSYNC = 0,	//
	DLL_SYNC		//
};


enum {
	DLL_VER_1 = 0, DLL_VER_2
};

typedef struct {
	uint8_t dataBuffer[MAILBOX_SIZE];
	uint16_t dataCount;

	uint8_t dllBuffer[MAILBOX_SIZE];
	uint8_t sof;
	uint16_t dllIndex;
	uint16_t count;
	uint8_t type;
	uint16_t dataReceiveIndex;

	uint8_t state;
	uint8_t escFlag;
	uint8_t escCount;
	unsigned char previousChar;
} Dll;

extern Dll dll;

extern void dllInit(uint8_t type);
extern void dllPack(uint8_t *inputBuffer, int16_t size);
extern void dllRcv(char c, Dll *dll);
#endif
