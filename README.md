Reproducer for https://bugs.freedesktop.org/show_bug.cgi?id=93103

You need a RHEL7 / CentOS7 / SL7 machine with a Radeon (=AMD) graphics card.

`make && ./mesa_llvm` should do. If you see


```
REPRODUCER!

```

then the reproducer is working for you: mesa is polluting the binary with mesa's llvm symbols.

     Axel Naumann (axel@cern.ch), 2017-01-25
