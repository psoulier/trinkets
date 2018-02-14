#include <string>
#include <string.h>
#include <stdio.h>

class CppProgress {
    size_t barwidth;
    size_t total;
    size_t conswidth;
    size_t percentage;
    size_t completed;
    /*
    barwidth: Number of characters in progress bar.
    completed: Things completed.
    total: Total number of things to do.
    caption: Caption for each thing.
    conswidth: Width of terminal console.

    Output looks something like this:
    #▐█████████░░░░░░░░▌ 3/15 (downloading...)
    */

    CppProgress(size_t barwidth, size_t total, size_t conswidth=80, bool percentage=false) :
        barwidth(barwidth),
        total(total),
        conswidth(conswidth),
        percentage(percentage),
        completed(0)
    {
    }

    void start()
    {
        completed = 0;
    }

    void update(std::string caption)
    {
        std::string fill = "█";
        std::string empty = "░";
        std::string progress;
        char updt[100];


        completed += 1;

        // Show percentage complete or thingies of total...
        if (percentage) {
            sprintf(updt, "%3.1f%%", 100.0 * (completed/total));
        }
        else {
            sprintf(updt, "%d/%d", completed, total);
        }

        auto filled = barwidth * (completed / total);
        progress = "\r";
        progress += "▐";
        progress.append(filled, fill);
        progress.append((barwidth-filled), empty);
        progress += "▌ ";
        progress += updt;

        progress = '\r▐{}{}▌ {} '.format(fill*filled, (self.barwidth-filled)*empty, updt)
        trailing = conswidth - progress.length();

        // Truncate caption if it's too big.
        if (caption.length() > trailing) {
            caption = caption.substr(0, trailing-3);
            caption += "...";
        }

        std::string end_fill = "";

        end_fill.append(conswidth -progress.length() - caption.length(), ' ');

        // Print progress (\r just moves cursor to the beginning of line without a linefeed.
        printf("%s%s%s", progress.c_str(), caption.c_str(), end_fill.c_str());

        // When done, clear caption and print newline.
        if (completed == total) {
            caption = "Done.";
            end_fill = "";
            end_fill.append(conswidth -progress.length() - caption.length(), ' ');
            printf("%s%s%s\n", progress.c_str(), caption.c_str(), end_fill.c_str());
        }
    }
};


