// status flags
enum PSW
{
	F_CARRY=0x1,
	F_ZERO=0x2,
	F_INTERRUPT_OFF=0x4,
	F_BCD=0x8,
	F_DECIMAL=F_BCD,
	F_BREAK=0x10,
	F_RESERVED=0x20, // not used (always set)
	F_OVERFLOW=0x40,
	F_NEGATIVE=0x80,
	F_SIGN=F_NEGATIVE,
	F__NV=F_NEGATIVE|F_OVERFLOW
};

// irq types
enum IRQ
{
    NONE=0x0,
    NMI=0x1,
    BRK=0x2,
	RST=0x4
};

namespace interrupt
{
	// global functions
	void request(const IRQ type);

	bool pending(const IRQ type);
}

namespace cpu
{
	// global functions
	void reset();
	void start();

	int nextInstruction();
}