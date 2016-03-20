#ifndef __PORT_H__
#define __PORT_H__

#include "ioport.h"

#define SERIAL_PORT_BASE           0x3f8

#define DATA_REGISTER             (0x3f8 + 0)
#define INTERRUPT_ENABLE_REGISTER (0x3f8 + 1)
#define LINE_CONTROL_REGISTER     (0x3f8 + 3)
#define LINE_STATUS_REGISTER      (0x3f8 + 5)

void port_init();
void port_write_char(char c);
void port_write_line(char* s);

#endif /* __PORT_H__ */