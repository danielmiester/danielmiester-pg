@ECHO OFF
cd sta00908
"c:/program files/kpit cummins/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/rx-elf-gcc"  -c -fno-builtin  -DMISSING_SYSCALL_NAMES  -DINTERNAL_NEWLIB -DDEFINE_MALLOC -DDEFINE_FREE    -DDEFINE_REALLOC -DDEFINE_CALLOC  -mlittle-endian-data -O2  -Wa,--mlittle-endian-data   -Ic:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/include -Ic:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/libm/common   c:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/libc/common/*.c  c:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/libc/stdio/*.c  c:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/libc/stdlib/*.c  c:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/libc/string/*.c  c:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/libc/ctype/*.c  c:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/libm/common/*.c  c:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/libm/math/*.c  c:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/libgloss/rx/*.S c:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/libgloss/rx/*.c -Ic:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/libgloss -Ic:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/libgloss/rx >error_log 2>&1
"c:/program files/kpit cummins/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/rx-elf-gcc"  -c -fno-builtin  -DMISSING_SYSCALL_NAMES  -DINTERNAL_NEWLIB -DDEFINE_MALLOC -DDEFINE_FREE    -DDEFINE_REALLOC -DDEFINE_CALLOC  -DINTEGER_ONLY -o vfiprintf.o -mlittle-endian-data -O2  -Wa,--mlittle-endian-data   -Ic:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/include -Ic:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/libm/common   c:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/libc/stdio/vfprintf.c  >error_log 2>&1
"c:/program files/kpit cummins/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/rx-elf-gcc"  -c -fno-builtin  -DMISSING_SYSCALL_NAMES  -DINTERNAL_NEWLIB -DDEFINE_MALLOC -DDEFINE_FREE    -DDEFINE_REALLOC -DDEFINE_CALLOC  -DINTEGER_ONLY -o vfiscanf.o -mlittle-endian-data -O2  -Wa,--mlittle-endian-data   -Ic:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/include -Ic:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/libm/common   c:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/libc/stdio/vfscanf.c  >error_log 2>&1
"c:/program files/kpit cummins/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/rx-elf-gcc"  -c -fno-builtin  -DMISSING_SYSCALL_NAMES  -DINTERNAL_NEWLIB -DDEFINE_MALLOC -DDEFINE_FREE    -DDEFINE_REALLOC -DDEFINE_CALLOC  -DSTRING_ONLY  -o svfprintf.o -mlittle-endian-data -O2  -Wa,--mlittle-endian-data   -Ic:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/include -Ic:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/libm/common   c:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/libc/stdio/vfprintf.c  >error_log 2>&1
"c:/program files/kpit cummins/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/rx-elf-gcc"  -c -fno-builtin  -DMISSING_SYSCALL_NAMES  -DINTERNAL_NEWLIB -DDEFINE_MALLOC -DDEFINE_FREE    -DDEFINE_REALLOC -DDEFINE_CALLOC  -DSTRING_ONLY  -o svfscanf.o -mlittle-endian-data -O2  -Wa,--mlittle-endian-data   -Ic:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/include -Ic:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/libm/common   c:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/libc/stdio/vfscanf.c  >error_log 2>&1
"c:/program files/kpit cummins/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/rx-elf-gcc"  -c -fno-builtin  -DMISSING_SYSCALL_NAMES  -DINTERNAL_NEWLIB -DDEFINE_MALLOC -DDEFINE_FREE    -DDEFINE_REALLOC -DDEFINE_CALLOC  -DSTRING_ONLY  -DINTEGER_ONLY  -o svfiprintf.o -mlittle-endian-data -O2  -Wa,--mlittle-endian-data   -Ic:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/include -Ic:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/libm/common   c:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/libc/stdio/vfprintf.c  >error_log 2>&1
"c:/program files/kpit cummins/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/rx-elf-gcc"  -c -fno-builtin  -DMISSING_SYSCALL_NAMES  -DINTERNAL_NEWLIB -DDEFINE_MALLOC -DDEFINE_FREE    -DDEFINE_REALLOC -DDEFINE_CALLOC  -DSTRING_ONLY  -DINTEGER_ONLY  -o svfiscanf.o -mlittle-endian-data -O2  -Wa,--mlittle-endian-data   -Ic:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/include -Ic:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/libm/common   c:/"program files"/"kpit cummins"/kpit-eclipse/gnurxv10.03-elf/rx-elf/bin/../bin/newlib/libc/stdio/vfscanf.c  >error_log 2>&1
cd ..
@ECHO ON