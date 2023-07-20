# Place tesing script in here to build and test linux kernel
# Then run make test

make -j 24
qemu-system-x86_64 -kernel arch/x86/boot/bzImage -initrd ~/initramfs.cpio.gz --append "root=/dev/ram init=/init console=ttyS0" -nographic