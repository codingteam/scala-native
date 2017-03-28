.. _setup:

Environment setup
=================

This is what you will be doing, in a nutshell:

* installation of SBT
* installation of LLVM and Clang
* installation of Boehm GC

Installing SBT
--------------

Please refer to `this link <http://www.scala-sbt.org/release/docs/Setup.html>`_
for instructions for your OS.

Installing LLVM, Clang and Boehm GC
-----------------------------------

Boehm GC and LLVM (that includes Clang) are Scala Native's only external
dependencies. Here are install instructions for a number of operating
systems Scala Native has been used with:

Ubuntu::

    $ sudo apt-get install clang libgc-dev libunwind-dev

macOS::

    $ brew install llvm bdw-gc

FreeBSD::

    $ pkg install llvm38 boehm-gc libunwind

nix/nixOS::

    $ wget https://raw.githubusercontent.com/scala-native/scala-native/master/bin/scala-native.nix

    $ nix-shell scala-native.nix -A clangEnv

Windows::

1. Install MSYS2 x86_64
2. Run "MSYS2 MinGW 64-bit" from the Start menu
3. Execute `pacman` to update the package database:

    $ pacman -Syuu

4. Terminate MSYS2 console as `pacman` suggests and start it again
5. Execute `pacman` again to finalize packages' upgrade process:

    $ pacman -Syuu

6. Install the necessary packages:

    $ pacman -S git llvm clang mingw-w64-x86_64-gcc autoconf automake libtool m4 make pkg-config

7. Clone and install Boehm GC according to bdwgc documentation:

    $ git clone https://github.com/ivmai/bdwgc.git
    $ cd bdwgc
    $ git clone https://github.com/ivmai/libatomic_ops.git
    $ ./autogen.sh
    $ ./configure
    $ make -j
    $ make check # Should report NO failures; be careful
    $ make install

8. TODO[F]: Check that
   `scala-native` build process sometimes uses `which` command that resolves
   paths relative to `<msys root>/mingw64`. So you'll need to symlimk
   `<msys root>/mingw64` to `<scala-native drive root>/mingw64`:

    $ cmd /c mklink /j "<msys root>\\mingw64" "<scala-native drive root>\\mingw64"

   For example, if scala-native will be cloned to `D:\scala-native`, execute the
   following:

   $ cmd /c mklink /j "C:\\msys2\\mingw64" "D:\\mingw64"

9.

    $ git clone https://github.com/scala-native/scala-native.git
    $ cd scala-native
    $ sbt rebuild

Continue to :ref:`sbt`.

.. _Boehm GC: http://www.hboehm.info/gc/
.. _LLVM: http://llvm.org
.. _MSYS2 x86_64: http://www.msys2.org/
.. _bdwgc documentation: https://github.com/ivmai/bdwgc#installation-and-portability
