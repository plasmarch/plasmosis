/*
PlasmARCH C Compiler Entry Point: void main(void); mapped to 0x0
*/

#include "ins.h"

void readfailint(void);

void main(void) {
	dih();
	seg(BIOS);
	hnj(READFAIL, readfailint);
	seg(BANK1);
	des(DRIVE);
	map(0x00, 0x20, 0x00);
	jmp(00);
	// We should never return
	dih();
	hlt();
}

db(DriveFail, "READFAIL");
void readfailint() {
	out(DriveFail, 0x8);
	dih();
	hlt();
	ret();
}
