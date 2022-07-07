# LLVM-PASS BY Mohamed Abaker

# Forked from \_**\_ with credit to \_\_**

Modify:

- Modify skeleton/skeleton.cpp to modify your pass
- Modify llvm-pass/test.c to modify the test file your pass will run on
- Remeber to use the following commands after modifying the test c file

  $ clang test.c -o test
  $ clang -O3 -emit-llvm test.c -c -o test.bc

Build:

    $ cd llvm-pass-skeleton
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make
    $ cd ..

Run:

    $ /usr/local/opt/llvm/bin/opt -load build/skeleton/libSkeletonPass.so -mohamed < test.bc > /dev/null  -enable-new-pm=0
