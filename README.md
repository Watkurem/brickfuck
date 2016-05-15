brickfuck
======

Simple as brick brainfuck interpreter. Written in C, pretty slow and not really standing out whatsoever. Still, it works.

I should add proper documentation, command line switches for things like cell size, auto-resizing of both tape and stack, maybe bignums support, more profound error handling...

But it won't be brick-simple then, right?

Usage
------

Pass BF source file as first command line argument:
```bash
    $ ./brickfuck source.bf
```

Then provide input and ^d (ctrl+d, EOF) when you're finished. This also works, obviously:
```bash
    $ echo 'something' | ./brickfuck
```

Some BF programs require different EOF representations than -1, so you'll have to fine-tune the source if you happen to need one of those.
Yet some BF programs require specific cell sizes and break on 'wrong' ones. That, too, you'll have to patch in yourself for now.