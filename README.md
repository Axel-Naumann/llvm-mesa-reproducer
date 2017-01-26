Reproducer for https://bugs.freedesktop.org/show_bug.cgi?id=93103

You need a RHEL7 / CentOS7 / SL7 machine with a Radeon (=AMD) graphics card.

`make && ./mesa_llvm` should do. If you see


```
This symbol should be called!
```

then the reproducer doesn't reproduce the bug. If instead you see either a crash or an error message "WRONG SYMBOL CALLED!" then the reproducer is working for you: mesa is polluting the binary with mesa's llvm symbols, shadowing "local" llvm symbols.

Axel Naumann (axel@cern.ch), 2017-01-26
