#include "interrupt.h"

static struct idt_descriptor descriptor[ICOUNT];
static struct idt_ptr idt;

static const uint8_t COUNT_OF_ERRORS 	= 8;
static const uint8_t ERROR_NUM[] 	= {8, 10, 11, 12, 13, 14, 17};

void descriptor_init(uint8_t index, uint64_t handler, uint8_t flags) {	
	descriptor[index].offset_low = get_bits(handler, 0, 16);
	descriptor[index].seg_selector = KERNEL_CODE;
	descriptor[index].reserved = 0;
	descriptor[index].flag = flags;
	descriptor[index].offset_middle = get_bits(handler, 16, 32);;
	descriptor[index].offset_high = get_bits(handler, 32, 64);;
	descriptor[index].reserved2 = 0;
}

void idt_init() {

	idt.base = (uint64_t) &descriptor;
	idt.size = sizeof(descriptor) - 1;
	
	for (int i = 0; i < ICOUNT; i++)
		descriptor_init(i, (uint64_t) &handler_empty,
			IFLAG_NOW | IFLAG_INT64);

	for (int i = 0; i < COUNT_OF_ERRORS; i++)
		descriptor_init(ERROR_NUM[i], (uint64_t) &handler_pop,
			IFLAG_NOW | IFLAG_INT64);

	set_idt(&idt);
}

void interrupt_init() {


	out8(MCOMMAND, L_INIT);
	out8(MDATA, ICV_MASTER);
	out8(MDATA, S_TO_M);
	out8(MDATA, BIT_ONE);

	out8(MDATA, 0b11111111 ^ BIT_ONE);
	out8(SDATA, 0b11111111);
}


void ending_interrupt(uint8_t is_master) {
	if (!is_master)
		out8(SCOMMAND, EOI);
	out8(MCOMMAND, EOI);
}
