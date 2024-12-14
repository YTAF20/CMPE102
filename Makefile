CC = aarch64-linux-gnu-gcc       # Cross-compiler for ARM64
AS = aarch64-linux-gnu-as        # Assembler for ARM64 assembly code
CFLAGS = -g -static              # Debugging flags and static linking
LDFLAGS = -lm                    # Link with math library for trigonometric functions

all: calculator

calculator: calculator.o calculator_core.o
	$(CC) $(CFLAGS) -o calculator calculator.o calculator_core.o $(LDFLAGS)

calculator.o: calculator.c
	$(CC) $(CFLAGS) -c calculator.c -o calculator.o

calculator_core.o: calculator_core.s
	$(AS) -g calculator_core.s -o calculator_core.o

clean:
	rm -f *.o calculator
