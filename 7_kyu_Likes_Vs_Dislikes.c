/*
YouTube had a like and a dislike button, which allowed users to express their opinions about particular content.
 It was set up in such a way that you cannot like and dislike a video at the same time.
 There are two other interesting rules to be noted about the interface: Pressing a button, which is already active, will undo your press.
 `If you press the like button after pressing the dislike button, the like button overwrites the previous "Dislike" state. The same is true for the other way round.

Task
        Create a function that takes in a list of button inputs and returns the final state.

Examples
like_or_dislike([Dislike]) ➞ Dislike
like_or_dislike([Like, Like]) ➞ Nothing
like_or_dislike([Dislike, Like]) ➞ Like
like_or_dislike([Like, Dislike, Dislike]) ➞ Nothing
        Notes
If no button is currently active, return Nothing.
If the list is empty, return Nothing.*/

#include <stddef.h>

enum button { NOTHING, LIKE, DISLIKE };

enum button like_or_dislike (size_t n, const enum button events[n]) {
    enum button current = NOTHING;
    for (int i = 0; i < n; ++i) {
        if (events[i] == current) current = NOTHING;
        else current = events[i];
    }
    return current;
}