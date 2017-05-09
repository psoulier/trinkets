import time

def pyprogress(barwidth, completed, total, caption, conswidth=80):
    """
    barwidth: Number of characters in progress bar.
    completed: Things completed.
    total: Total number of things to do.
    caption: Caption for each thing.
    conswidth: Width of terminal console.

    Output looks something like this:
    #▐█████████░░░░░░░░▌ 3/15 (downloading...)
    """

    fill = '█'
    empty = '░'
    progressfmt = '\r▐{}{}▌ {}/{} '

    filled = int((barwidth*(completed/total)))
    progress = progressfmt.format(fill*filled, (barwidth-filled)*empty, completed, total)
    trailing = conswidth - len(progress)

    # Truncate caption if it's too big.  Usually files, so clip the beginning of the string
    # since the end is usually more interesting.
    if len(caption) > trailing:
        caption = '...' + caption[-trailing+3:]

    # Print progress (\r just moves cursor to the beginning of line without a linefeed.
    print(progress + caption + ' ' * (conswidth-len(progress)-len(caption)), end='')

    # When done, clear caption and print newline.
    if completed == total:
        caption = "Done."
        print(progress + caption + ' ' * (conswidth-len(progress)-len(caption)), end='')
        print('')


