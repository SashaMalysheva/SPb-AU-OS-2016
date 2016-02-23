#include "pit.h"
#include "ioport.h"
#include "interrupt.h"
#include "port.h"
#include "memory.h"

void pit_init() {

	out8(PP_CONTROL, CMND_FOR_CONTROL);
	out8(PP_DATA, get_bits(MAX_NUM, 0, 8));
	out8(PP_DATA, get_bits(MAX_NUM, 8, 16));
	descriptor_init(ICV_MASTER, (uint64_t) &pit,
		IFLAG_NOW | IFLAG_INT64);
}

void pit() {

	port_write_line("done/n");	
	ending_interrupt(1);
}
