#ifndef __PIT_H__
#define __PIT_H__

#define PP_CONTROL 	0x43
#define PP_DATA	 	0x40

#define MAX_NUM	0xFFFF

#define CMND_FOR_CONTROL 0b00110100

void pit_init();
void pit();
void handler();

#endif /* __PIT_H__ */
