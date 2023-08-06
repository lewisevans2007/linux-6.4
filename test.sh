# Place tesing script in here to build and test linux kernel
# Then run make test



qemu-system-x86_64 -kernel arch/x86/boot/bzImage -initrd ~/initramfs.cpio.gz \
  --append "root=/dev/ram init=/init console=ttyS0" -nographic \
  -device usb-ehci,id=ehci \
  -device usb-kbd \
  -device virtio-rng-pci \
  -device virtio-net-pci,netdev=usernet \
  -netdev user,id=usernet,hostfwd=tcp::5555-:22 \
  -device virtio-gpu-pci \
  -device usb-tablet \
  -device usb-mouse \
  -device virtio-serial-pci \
  -device virtio-net-pci \
