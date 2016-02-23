#include "port.h"
#include "ioport.h"

void port_write_char(char c) {
	
	while (((in8(STATUS_OF_LINE) >> 5) & 1) == 0) {}; 
	out8(DATA_REGISTER, c);
}

void port_write_line(char* s) {
	for (; *s != 0; ++s)
		port_write_char(*s);
}

void port_init() {
	out8(CONTROL_LINE, 3); 
}
