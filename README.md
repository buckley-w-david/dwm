# dwm - dynamic window manager
dwm is an extremely fast, small, and dynamic window manager for X.

This is my fork

## XMonad Migration TODO

### Important
 * auto float some stuff
 * fix colours (Like active window outline and statusbar)
 * Applications
     - \<Print>        , spawn "maim -s | xclip -selection clipboard -t image/png"
     - M-\<Print>      , spawn "maim -i $((16#$(xwininfo | grep \"Window id\" | awk '{print $4}' | cut -c3-))) ~/Pictures/Screenshots/$(date +%s).png"
     - M-C-\<Print>    , spawn "/home/david/scripts/pinta-ss"
 * screensaver stuff

### Misc
 * Dynamic tag bindings - Might not be possible
     - M-v - Create new workspace by string from dmenu
     - M-S-v - Move current window to tag by string from dmenu
     - M-m - Create new tag from title of current window (meh)
     - M-backspace - Delete current tag (meh)
     - M-S-r - Rename tag by string from dmenu
 * left/right arrow to move tags left/right
 * coloured bar text
 * Checkout out dwmblocks as an alternative to dwm-bar

## General TODO
 * [Create a PKGBUILD](https://bitbucket.org/jokerboy/dwm/raw/0b70c4351b887fbfdb5d694ce4451d52ad9e9422/PKGBUILD)
 * Check out interesting looking patches
   - [Store/retrieve tags on an xprop](https://bitbucket.org/jokerboy/dwm/src/master/14-dwm-6.0-remember-tags.diff) - I think this should "save" the tagset of windows between restarts for things like firefox
   - [autostart](https://dwm.suckless.org/patches/autostart/) or [cool autostart](https://dwm.suckless.org/patches/cool_autostart/)
   - [swallow](https://dwm.suckless.org/patches/swallow/) or [dynamic swallow](https://dwm.suckless.org/patches/dynamicswallow/)
   - [shiftview.c](https://lists.suckless.org/dev/att-7590/shiftview.c)
   - [systray](https://dwm.suckless.org/patches/systray/)
   - [Single shared tagset between monitors](https://dwm.suckless.org/patches/single_tagset/) - Might not be feasable
 * Update documentation to reflect my changes

## Resources

### Other configs (inspiration)
 * https://github.com/lukesmithxyz/dwm
