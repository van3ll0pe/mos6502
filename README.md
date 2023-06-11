# mos6502
MOS6502 cpu emulator


---

Hi ! <br>
There is again another emulator of mos6502 !

---
## How it works ?

First of all, include the file "cpu.hpp" in your source files.

Now, you can create an object of type ```mos6502::Cpu```

Here the list of public functions :

```cpp
    void run();
    void load(std::vector<uint8_t> &instr, uint16_t addr);
    void set_NMI_VECTOR(uint16_t value);
    void set_IRQ_VECTOR(uint16_t value);
    void set_RESET_VECTOR(uint16_t value);
    bool is_BRK();
    void IRQ();
    void NMI();
    void RESET();
```

the functions `set_NMI_VECTOR`, `set_IRQ_VECTOR` and `set_RESET_VECTOR` allows to put a value of the memory range for each interruption (the value of PC register after interruption).<br>
the functions `IRQ`, `NMI` and `RESET` cause choosen interruption.<br>

the function `is_BRK` returns true if the current opcode is the BRK instruction, else false.<br>
the function `load` allows you to put a binary value vector in the memory at the given address.<br>
the function `run` execute the opcode.<br>


example :
```cpp

    std::vector<uint8_t> bin {0xA2, 0x0A, 0x8E, 0x00, 0x00, 0xA2, 0x03, 0x8E, 0x01, 0x00, 0xAC, 0x00, 0x00, 0xA9, 0x00, 0x18, 0x6D, 0x01, 0x00, 0x88, 0xD0, 0xFA, 0x8D, 0x02, 0x00, 0xEA, 0xEA, 0xEA};
    mos6502::Cpu cpu{};

    cpu.set_RESET_VECTOR(0x8000);
    cpu.load(bin, 0x8000);

    while (true) {
        cpu.run();

        if (cpu.is_BRK())
            break;
    }
```

---

## How to use it ?

In the file `CMakeLists.txt`, there is 3 lines in comment.
```
#add_compile_definitions(DEBUG_INFO)
#add_executable(<name> srcs)
#target_link_libraries(<name> mos6502_cpu)
```

- the first line allows you to print the value of each register at each loop of the run function of the cpu.
- the second line allows you to create your executable, replace the `name` by the name of your executable and replace `srcs` by all your source files.
- the third line links the library (object file of the cpu) to your project. So replace `name` by the name of your executable name.

now you can follow these lines :

```
mkdir build
cd build
cmake ..
make
```

now you have your executable and the library.

---


Enjoy !

