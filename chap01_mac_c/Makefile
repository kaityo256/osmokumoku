all: hello.efi

%.o: %.c
	clang -target x86_64-pc-win32-coff -o $@ -c $<

%.efi: %.o
	lld-link /subsystem:efi_application /entry:EfiMain /out:$@ $<

.PHONY: run

run: hello.efi
	./mkimg.sh
	./run.sh

clean:
	rm -f hello.efi
	rm -f hello.o
	rm -f disk.img
	rm -rf mnt
