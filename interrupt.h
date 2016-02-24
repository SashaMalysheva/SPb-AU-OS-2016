#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__


#include "memory.h"
#include <stdint.h>
#include "ioport.h"

#define ICV_SLAVE  	0x28
#define ICV_MASTER 	0x20
#define EOI 	(1<<5)
#define MCOMMAND 	(0x20)
#define MDATA    	(0x20 + 1)
#define SCOMMAND  	(0xA0)
#define SDATA		(0xA0 + 1)

#define S_TO_M 0b00000100
#define M_TO_S 0b00000010

#define L_INIT	0b00010001
#define BIT_ONE		0b00000001

#define ICOUNT 0x100

#define IFLAG_NOW 0b10000000
#define IFLAG_INT64   0b00001110

struct idt_ptr {
	uint16_t size;
	uint64_t base;
} __attribute__((packed));

struct idt_descriptor {
	uint16_t offset_low;
	uint16_t seg_selector;
	uint8_t reserved;
	uint8_t flag;
	uint16_t offset_middle;
	uint32_t offset_high;
	uint32_t reserved2;
} __attribute__((packed));

static inline void set_idt(const struct idt_ptr *ptr)
{ __asm__ volatile ("lidt (%0)" : : "a"(ptr)); }


static inline void clear_interrupt_enable_flag()
{ __asm__ volatile ("cli"); }

static inline void set_interrupt_enable_flag()
{ __asm__ volatile ("sti"); }

void interrupt_init();
void ending_interrupt(uint8_t is_master);

void idt_init();
void descriptor_init(uint8_t id, uint64_t handler, uint8_t flags);

void handler_empty();
void handler_pop();

#endif /*__INTERRUPT_H__*/
