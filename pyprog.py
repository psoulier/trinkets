import time

class PyProgress:
    """
    barwidth: Number of characters in progress bar.
    completed: Things completed.
    total: Total number of things to do.
    caption: Caption for each thing.
    conswidth: Width of terminal console.

    Output looks something like this:
    #▐█████████░░░░░░░░▌ 3/15 (downloading...)
    """
    def __init__(self, barwidth, total, conswidth=80, percentage=False):
        self.barwidth = barwidth
        self.total = total
        self.conswidth = conswidth
        self.percentage = percentage
        self.completed = 0

    def start(self):
        """
        Starts progress bar and shows 0% initial status.  Can also use to reset bar.
        """

        self.complete = 0

    def update(self, caption):
        """
        Complete one thing and update progress bar accordingly.
        """

        fill = '█'
        empty = '░'

        self.completed += 1

        # Show percentage complete or thingies of total...
        if self.percentage:
            updt = "{0:.1f}%".format(100.0*round(self.completed/self.total,2))
        else:
            updt = '{}/{}'.format(self.completed, self.total)

        filled = int((self.barwidth*(self.completed/self.total)))
        progress = '\r▐{}{}▌ {} '.format(fill*filled, (self.barwidth-filled)*empty, updt)
        trailing = self.conswidth - len(progress)

        # Truncate caption if it's too big.  
        if len(caption) > trailing:
            caption = caption[0:trailing-3:] + '...'

        # Print progress (\r just moves cursor to the beginning of line without a linefeed.
        print(progress + caption + ' ' * (self.conswidth-len(progress)-len(caption)), end='')

        # When done, clear caption and print newline.
        if self.completed == self.total:
            caption = "Done."
            print(progress + caption + ' ' * (self.conswidth-len(progress)-len(caption)), end='')
            print('')


