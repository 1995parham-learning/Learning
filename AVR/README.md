# Atmel-ATmega16


<p align="center">
  <img src="http://uupload.ir/files/2wv_avr-studio-logo.jpg">
</p>

AVR ATmega16 Microcontroller programming and simulation using AtmelStudio and Proteus.

**Quick Access**:
1. [Instructions](http://www.atmel.com/webdoc/avrassembler/avrassembler.wb_instruction_list.html)
2. [Directives](http://www.atmel.com/webdoc/avrassembler/avrassembler.wb_directives.html)
3. [Assembler Preprocessor](http://www.atmel.com/webdoc/avrassembler/avrassembler.wb_preprocessor.html)
4. [Known Issues](http://www.atmel.com/webdoc/avrassembler/avrassembler.wb_Known_Issues.html)
5. [Addressing Modes - See below for quick lookup](https://www.csee.umbc.edu/~tinoosh/cmpe311/notes/AVRAddressingModes.pdf)
6. [Analog to Digital Conversion Example](http://extremeelectronics.co.in/avr-tutorials/using-adc-of-avr-microcontroller/)
7. [AVR Simulator](https://github.com/buserror/simavr)


# Introduction
## Instruction Set and Addressing Modes
The following is a quick start on basic concepts of ATmega16 microcontroller.

## Instruction Set
This is a set of instructions for ATmega16 microcontroller which decides what operations the microcontroller can perform. Each instruction can control some parts of microcontroller.

## Addressing Modes
Instructions can be categorized based on **how they access data** and **how they perform operations** on those data. This category consist of about 10 modes that controls this access and operation.

## Instruction Format
Each instruction in ATmega16 consists of two parts:
* Opcode: Indicates to ALU what to do.
* Operands: Numbers on which the ALU operates.

# ATmega16 Addressing Modes Details
There are 5 sections in ATmega16 which have relationships with **data and program**. So the addressing mode category will spread over these 5 areas and they are mentioned down here:
* Register File (32 Registers - A part of SRAM which is built into the CPU - **32** bytes | 32 registers of 1 Byte)
* I/O Registers (64 Registers - A part of SRAM which is built into the CPU - **64** bytes | 64 registers of 1 Byte)
* SRAM (Data Memory - Separate from those mentioned above - out of CPU - **1024** Bytes considering 96 bytes for the above sections)
* EEPROM (**512** bytes)
* Flash Memory (AKA Program Memory - **16** Kbytes of On-chip In-system reprogrammable flash memory)

## Register Direct (Single Register) mode
<p align="center">
  <img src="http://uupload.ir/files/2xms_register_direct.png">
</p>

* Can operate on any 32 registers of the register file.

* Operations:
1. Read contents of registers
2. Operate on contents
3. Store back in same register

* Usage examples:
1. **INC R0**
2. **DEC R5**
3. **LSL R9**


## Register Direct (Two Registers) mode
<p align="center">
  <img src="http://uupload.ir/files/7nky_register_direct(two_regs).png">
</p>

* Two registers are included in this mode:
1. Rs: Source Register
2. Rd: Destination Register

* Operations:
1. Read two registers
2. Operate on the content
3. Store the result in the destination register

* Usage Examples:
1. **ADD R1,R3**
2. **SUB R5,R7**

## Immediate mode
* Constant value is in the instruction.
* Operates on the register and that constant value and stores the result back in the register.
* Usage Examples:
1. **SUBI R4,8** (Subtract with Immediate: R4 = R4 - 8)
2. **ADIW R26,5** (Add Immediate to Word: R27:R26 = R27:R26 + 5)

## I/O direct mode
Instructions are used to access I/O space **(64 I/O registers)** but **not extended I/O registers**.
* Usage Examples:
1. **IN R10,PORTADDRESS**
2. **OUT PORTADDRESS,R10**
3. **IN Rd,PORTADDRESS**
4. **OUT PORTADDRESS,Rs**
* PORTADDRESS is between 0x00 to 0x3F
* Rs and Rd are any registers from register file

## Data direct mode
<p align="center">
  <img src="http://uupload.ir/files/m8vm_datadirect_mode.png">
</p>

Two word instructions are used in this mode. One of the words is the address of the data memory space.
* Usage Examples:
1. **STS k,Rs** (Store dircet SRAM - Put the Rs contents in place K - K is a 16 bit address)
2. **LDS Rd,k** (Load direct from SRAM - Grab the contents of place K in the SRAM and put it in the Rd register)


## Data indirect mode
<p align="center">
  <img src="http://uupload.ir/files/l6vn_data_indirect_mode.png">
</p>

It's similar to the data direct except that:
* It has one word only
* The address of the memory location is stored in register Y or Z
* Usage Examples:
1. **LD Rd,X+** (Load indirect with post increment: Rd = X , X = X + 1)
2. **ELD Rd,X** (Extended indirect load: Rd = R27:R26)
3. **LDD Rd,(Y+q)** (Load indirect with displacement: Rd = (Y+q) () are showing the contents)
4. **ST -Y,Rs**

## I/O Ports using indirect mode
I/O ports can be accessed using indirect SRAM commands.
* Usage Examples:
1. **LDI R16,HIGH(PORTB+32)**

## Extended I/O mode
For extended I/O registers, we cannot use commands like **IN** or **OUT**. Instead we need to use the direct and indirect SRAM access commands like LDS, STS, etc.
* Some important commands are:
1. **LDS** - Load from SRAM
2. **STS** - Store to SRAM
3. **SBR** - Set bits in register
4. **CBR** - clear bits in register
5. **SBRS** - Skip if bit in register is set
6. **SBRC** - Skip if bit in register is clear

## Direct program memory addressing mode
Important command:
* Call: Call a subroutine and put the return address on the stack
* Usage Example:
1. **CALL k** (This will do the following: first, STACK = PC + 1 and then, PC = k)

## Implicit addressing mode
Important commands: **CLC** and **RET**

## Indirect program addressing mode
<p align="center">
  <img src="http://uupload.ir/files/0tw_indirect_program_addressing_mode.png">
</p>
These instructions use Z register to point to the program memory.

1. **ICALL** (Indirect call to Z)
2. **IJMP** (Indirect jump to Z)

## Relative program addressing mode
<p align="center">
  <img src="http://uupload.ir/files/o1y_relative_program_addressing_mode.png">
</p>

Instructions in this addressing mode are **RCALL** and **RJMP** which are used with an offset to change the current position of program counter.
* Usage Example:
1. **RCALL k** (STACK = PC + 1 , PC = PC + k + 1)
2. **RJMP k** (PC = PC + k + 1)

# Useful Examples
There are some important addressing modes in the following table. Make sure you practice hard :D
<p align="center">
  <img src="http://uupload.ir/files/dai1_table_of_examples.png">
</p>


# ATmega Programming
In this section I'll provide some good practices on programming an ATmega microcontroller in assembly language with AtmelStudio 7.

## Writing to EEPROM
This program is the first program I'll cover in these series. The objective is to write numbers 0-9 to the EEPROM Memory. In order to write the data into the EEPROM memory, we have to deal with some important registers:
* **EEARL** & **EEARH** (EEPROM Address Register - Low & High bytes)
* **EEDR** (EEPROM Data Register)
* **EECR** (EEPROM Control Register)

I believe two first registers are understandable for you. But the third register which is the EECR has to be explained more. EEPROM Control Register has 8 bits in which 4 of them are used by the microcontroller and is reserved. But the other 4 bits are known as:
* **EERE** (EEPROM Read Enable bit)
* **EEWE** (EEPROM Write Enable bit)
* **EEMWE** (EEPROM Master Write Enable bit)
* **EERIE** (EEPROM Read Interrup Enable bit)

The exact procedure of writing data into the EEPROM is as follows:
1. Wait untill the **EEWE** bit gets 0.
2. Wait untill the **SPMEN** bit in **SPMCR** gets 0.
3. Write the **new address** of EEPROM in which our data is going to be stored at.
4. Write the **new data** into the **EEDR**.
5. Write the **logical 1** into the **EEMWE** bit.
6. Write the **logical 1** into the **EEWE** in 4 cycles after turning the **EEMWE** 1.

## Calculating the addition of square of 5X numbers
In this coding procedure, I will show you how to find the addition of square of 5X numbers (5, 10, 15, 20 ...) and store them in the R1:R0 registers.
So the result will be something like (25 + 100 + 225 + 400 + ...) and we need to store this result in those two registers.

## Sorting the array elements in the program memory
Lets talk a bit about the flash(program) memory in ATmega16. The flash memory in ATmega16 is a **In-system On-chip programmable memory** that contains **16 Kbytes** of space.
Since the instructions need at most 16 or 32 bits in to run, the words in program memory are 16 bits, Hence there are 8K of these 16-bit words that is 16Kbytes in total.
The program memory is separated into two main parts: The **Boot** section and the **Application** section. The flash memory is able to be programmed about **1000** times. The **program counter** in ATmega16 is a **13 bit register**, hence it can point to the 8K space in the program memory.

## I/O Read and processing example
In this example, I'll show you how to read the data from an specific I/O address and processing that data with swap,tst and ...
This is an awesome example to learn more about ATmega16 programming.

## The Stack
The Stack is used by the ALU to store return addresses from subroutines.

Imagine you can't remember where you just left. You'd have to write down where you left and, if you're visiting several locations, put the notes onto a stack. Your stack pointer tells you where that stack is. A microcontroller is just doing that - when a subroutine is called, it leaves the place in flash where it was just working and saves the return address on the stack.

The Stack needs a stack pointer (SP) and space in SRAM (the stack pointer must point above the first SRAM address). When a return address is stored, the SP is **post-decremented**. In other words: The stack is **growing** towards **smaller SRAM addresses**. The biggest stack possible is initialised to **RAMEND**. It can then grow all the way down to the first SRAM address.
further reading: http://www.avr-tutorials.com/general/avr-microcontroller-stack-operation-and-stack-pointer

## 7-Segment connection
In this section, I'll show you how to connect a 7-Segment to the PORT B of the ATmega16 and encoding the numbers 0-9 to the what is going to be shown on the 7-Segment. So what we need is connecting to the PORT B with that 7-Segment at first. Then storing those numbers somewhere in program memory.

## Write to EEPROM, Configure the PORTS, Read from EEPROM and show the result (MERGED)
In this section, I'll merge some described sections together to write the 0-9 numbers to the EEPROM memory, configure the port B and finally read those data from EEPROM memory and printing them in the configured 7 Segment.

## Reading from program memory (LPM)
Using **LPM** instruction we can simply access 64K of program memory bytes (**32K** words). The address which we read from is defined in the **Z** pointer and it has **Low** and **High** bytes.
* **Example**:
```
ldi ZH, high(Table_1<<1) ; Initialize Z pointer
ldi ZL, low(Table_1<<1)
lpm r16, Z ; Load constant from program
; memory pointed to by Z (r31:r30)
```
## Error Parameters of ATmega16
There are some parameters that may distract the microcontroller from doing it's ideal job:
* **Offset Error**
* **Gain Error**
* **Integral Non-linearity**
* **Differential Non-linearity**
* **Quantization Error**
