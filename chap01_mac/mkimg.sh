qemu-img create -f raw disk.img 200M
/usr/local/Cellar/dosfstools/4.2/sbin/mkfs.fat -n 'MIKAN OS' -s 2 -f 2 -R 32 -F 32 disk.img         
open disk.img
sleep 1
mkdir -p /Volumes/MIKAN\ OS/EFI/BOOT
cp BOOTX64.EFI /Volumes/MIKAN\ OS/EFI/BOOT
