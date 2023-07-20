# Linux kernel

This is my modified verison of the linux kernel. It might contain weird changes, comments and code. This repositroy is mainly for me to learn about the linux kernel and for testing purposes.

## Building

### Prerequisites

You need a few packages to build the kernel. On Ubuntu you can install them with:

```bash
sudo apt install build-essential libncurses-dev bison flex libssl-dev libelf-dev
```

### Building

To build the kernel, run:

```bash
make
```

If you want to build the kernel with multiple threads, run:

```bash
make -j$(nproc)
```

