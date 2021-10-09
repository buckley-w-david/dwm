# dwm - dynamic window manager
dwm is an extremely fast, small, and dynamic window manager for X.

This is my fork

## XMonad Migration TODO

### Important
 * auto float some stuff
 * fix colours (Like active window outline)
 * scratchpads
 * Migrate xmobar config (Conky?)
 * FocusFollowsMouse off
 * Run Starup script - Migrate it into startdwm or .xinitrc
 * Applications
 *   - <Print>        , spawn "maim -s | xclip -selection clipboard -t image/png"
 *   - M-<Print>      , spawn "maim -i $((16#$(xwininfo | grep \"Window id\" | awk '{print $4}' | cut -c3-))) ~/Pictures/Screenshots/$(date +%s).png"
 *   - M-C-<Print>    , spawn "/home/david/scripts/pinta-ss"
 *   - M-S-s          , namedScratchpadAction myScratchPads "spotify"
 *   - M-<F12>        , namedScratchpadAction myScratchPads "terminal"
 * screensaver stuff
 * real quit (`killall startdwm`?)

### Misc
 * Dynamic tag bindings
 *   - M-v - Create new workspace by string from dmenu
 *   - M-S-v - Move current window to tag by string from dmenu
 *   - M-m - Create new tag from title of current window (meh)
 *   - M-backspace - Delete current tag (meh)
 *   - M-S-r - Rename tag by string from dmenu
 * left/right arrow to move tags left/right
 * Remove all tags from window except current viewed one(s?)
