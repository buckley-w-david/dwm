# dwm - dynamic window manager
dwm is an extremely fast, small, and dynamic window manager for X.

This is my fork

## XMonad Migration TODO

### Important
 * auto float some stuff
 * fix colours (Like active window outline and statusbar)
 * spotify scratchpad
 * terminal scratchpad initial height
 * Migrate xmobar config (Conky?)
 * Applications
     - \<Print>        , spawn "maim -s | xclip -selection clipboard -t image/png"
     - M-\<Print>      , spawn "maim -i $((16#$(xwininfo | grep \"Window id\" | awk '{print $4}' | cut -c3-))) ~/Pictures/Screenshots/$(date +%s).png"
     - M-C-\<Print>    , spawn "/home/david/scripts/pinta-ss"
     - M-S-s          , namedScratchpadAction myScratchPads "spotify"
     - M-\<F12>        , namedScratchpadAction myScratchPads "terminal"
 * screensaver stuff

### Misc
 * Dynamic tag bindings
     - M-v - Create new workspace by string from dmenu
     - M-S-v - Move current window to tag by string from dmenu
     - M-m - Create new tag from title of current window (meh)
     - M-backspace - Delete current tag (meh)
     - M-S-r - Rename tag by string from dmenu
 * left/right arrow to move tags left/right
 * Remove all tags from window except current viewed one(s?)

## General TODO
 * [Create a PKGBUILD](https://bitbucket.org/jokerboy/dwm/raw/0b70c4351b887fbfdb5d694ce4451d52ad9e9422/PKGBUILD)
 * Check out interesting looking patches
   - [Store/retrieve tags on an xprop](https://bitbucket.org/jokerboy/dwm/src/master/14-dwm-6.0-remember-tags.diff) - I think this should "save" the tagset of windows between restarts for things like firefox
   - [Single shared tagset between monitors](https://dwm.suckless.org/patches/single_tagset/)
   - [autostart](https://dwm.suckless.org/patches/autostart/) or [cool autostart](https://dwm.suckless.org/patches/cool_autostart/)
   - [swallow](https://dwm.suckless.org/patches/swallow/) or [dynamic swallow](https://dwm.suckless.org/patches/dynamicswallow/)
   - [noborder](https://dwm.suckless.org/patches/noborder/) or [smart border](https://dwm.suckless.org/patches/smartborders/) or [removeborder](https://dwm.suckless.org/patches/removeborder/)
   - [shiftview.c](https://lists.suckless.org/dev/att-7590/shiftview.c)
   - [systray](https://dwm.suckless.org/patches/systray/)
 * investigate status bars
   - [slstatus](https://tools.suckless.org/slstatus/)
   - [conky](https://wiki.archlinux.org/title/Conky)
   - [dwmstatus](https://github.com/kamiyaa/dwmstatus)
   - [dwmblocks](https://github.com/torrinfail/dwmblocks)

## Resources

### Other configs (inspiration)
 * https://github.com/lukesmithxyz/dwm
