# Trinkets
Just a random collection of miscellaneous utilities for whatever purpose.

## PyProgress
A super-simple python console/text mode progress bar.  There's a ton of them
around (StackOverflow, etc.), just my own version.  Output looks something like
the following:
```
▐█████████░░░░░░░░▌ 3/15 (downloading...)
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

i = 0
for f in files:
    pyprogress(15, i, len(files)-1, f)
    i += 1
    time.sleep(0.1)
```