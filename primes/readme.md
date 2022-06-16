# prime searcher
Searches for the nth prime number. The algorithm gets successively more efficient each iteration.

# descriptions
`1`: Naive search, no optimizations. O(n^2)  
`2`: Only search up to the square root of the number, and ignore even numbers after two. O(n sqrt(n))

# parameters
Each compiled item takes a single command line parameter, the nth prime to return.

# examples
```bash
$ ./np2 20500
230761
```

# other notes
All precompiled binaries work on Linux WSL kernel only. Don't expect them to work 100% on other OSes, but if you recompile them, they should work fine.

All benchmarks found in `notes` files are run on the following machine:

    CPU: Intel Core i7-10750H (6C/12T) @ 2.6GHz (boost 5.0GHz)
    RAM: 7.7 GB (allocated to VM)
    GPU: NVIDIA GeForce RTX 2060, 6GB
    OS: Ubuntu 22.04 LTS on WSL
    SSD: PC SN730 NVMe SSD (512GB)

I will be testing on another computer soon, but with a native Ubuntu 22.04 kernel, rather than a VM. The machine will have the following hardware:

    CPU: Intel Core i7-7820X (8C/16T) @ 3.6GHz (boost 4.5GHz)
    RAM: 31.2 GB
    GPU: AMD Radeon HD Graphics 6950, 2GB
    OS: Ubuntu 22.04 LTS
    SSD: Samsung 970 EVO SSD (512GB)

