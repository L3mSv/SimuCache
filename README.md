# **SimuCache**

**Programming Language:** C <br> 
**SO:** Windows 11 (but works on linux)

We have organized the files into the following ***folders***:

**Cache:** Invokes cache configuration creates and destroys the target cache. <br>
**Config:** Configures the cache and handles replacement and mapping. <br>
**Utils:** Functions that do not fall under the cache category but are still useful. <br>

> [!NOTE]
> To run execute `make` in terminal to build .o files of program.

## **Parameters Call** 

```
./cache_simulator <nsets> <bsize> <assoc> <substituição> <flag_saida> <arquivo.bin>
```

## **Output Examples**

### **Normalize**

```
./cache_simulator 1 4 32 f 1 vortex.in.sem.persons.bin

186676, 0.5530, 0.4470, 0.0004, 0.9996, 0.0000
```

### **Custom**

```
./cache_simulator 1 4 32 f 0 vortex.in.sem.persons.bin

Acesses: 186676
Hits: 103226
Misses: 83450
Compulsory Misses: 32
Capacity Misses: 83418
Conflict Misses: 0
Hit Ratio: 0.5530
Miss Ratio: 0.4470
Compulsory Miss Ratio: 0.0004
Capacity Miss Ratio: 0.9996
Conflict Miss Ratio: 0.0000
```