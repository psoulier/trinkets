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
files = ['downloading: a.foo',
      'downloading: foo.bin',
      'downloading: f01.bin',
      'downloading: f02.bin',
      'downloading: f03.bin',
      'downloading: f04.bin',
      'downloading: f056bin',
      'downloading: f017bin',
      'downloading: f08.bin',
      'downloading: f09.bin',
      'downloading: f11.bin',
      'downloading: f21.bin',
      'downloading: f31.bin',
      'unpacking: blah/blah/nothing/nowhere/garbage/goforthandprint/piggyback/poohbear/piglet/somethingbig.bin',
      'unpacking: nothing.bin',
      'unpacking: barf.splat'
    ]

prog = PyProgress(15, len(files), percentage=True)
prog.start()
for f in files:
    prog.update(f)
    time.sleep(.1)
```
