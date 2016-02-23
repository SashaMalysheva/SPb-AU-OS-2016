#ifndef __PORT_H__
#define __PORT_H__

#define PORT_BASE           0x3f8

#define DATA_REGISTER              (0x3f8 + 0)
#define REGISTER_OF_INTERRUPT_ABLE (0x3f8 + 1)
#define CONTROL_LINE               (0x3f8 + 3)
#define STATUS_OF_LINE             (0x3f8 + 5)

void port_write_char(char c);
void port_write_line(char* s);
void port_init();

#endif /* __PORT_H__ */
