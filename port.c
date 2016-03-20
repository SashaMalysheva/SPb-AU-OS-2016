#include "port.h"

void port_init() {

	out8(LINE_CONTROL_REGISTER, 3); // 3_{10} = 11_{2}, т.е. биты 0 и 1 LCR теперь
									// равны 1 => 8 бит данных в формате кадра
	out8(INTERRUPT_ENABLE_REGISTER, 0);
}

void port_write_char(char c) {
	
	while (((in8(LINE_STATUS_REGISTER) >> 5) & 1) == 0) {}; // если пятый бит LST
		// установлен, значит, можно писать следующий байт, иначе нужно ждать
	out8(DATA_REGISTER, c);
}

void port_write_line(char* s) {
	for (; *s != 0; ++s)
		port_write_char(*s);
}