# Trinkets
Just a random collection of miscellaneous utilities for whatever purpose.

## PyProgress
A super-simple python console/text mode progress bar.  There's a ton of them
around (StackOverflow, etc.), just my own version.  Output looks something like
the following:
```
▐█████░░░░░░░░░░▌ 5/15 downloading: f04.bin
```

Sample code to use `pyprog.py`:
```
files = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
         'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't']

prog = PyProgress(15, len(files), percentage=True)
prog.start()
for f in files:
    prog.update('downloading: ' + f)
    time.sleep(.1)
```

## printd (`printdbg.cpp` and `printdbg.hpp`)
The `printd` function is a formatted print function that provides a subset of C's`printf`, but not as full-featured.  It's intended for small, embedded systems
and utilizes C++ templates to a) make it safer than `printf` and b) avoids
dragging in the varargs library.  This code does not require any
library support and is a good drop-in for debug prints to a serial console.
Supported formatting options include: `d`, `u`, `x`, `p`, `c`, `s`, and padding
width (e.g., `%6d` or `%08x`).  The `l` qualifier for numbers is also supported,
but is ignored.  

### Limitations
* `printd` supports integer types only as large as `uintptr_t`. 
* Floats are not supported (wouldn't be a big deal to add them, I just don't use
them for debugging all that often).
