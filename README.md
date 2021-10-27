# dwm - dynamic window manager

dwm fork with mainstream and custom patches.

## Mainstream Patches
 - [focusonclick](https://github.com/buckley-w-david/dwm/commit/4925f0387f27b7dcd1275a487839ea0dbba5ac76)
 - [scratchpads](https://github.com/buckley-w-david/dwm/commit/9b2003c3a99386e314ce705166c962ebcca39309)
 - [fakefullscreen](https://github.com/buckley-w-david/dwm/commit/3bde615344a1c40acda00421d2ffd25e26a5eb05)
 - [removeborder](https://github.com/buckley-w-david/dwm/commit/d2d65e3098edb419ad5fe6d84a8e28bc2dbe5366)
 - [statusallmons](https://github.com/buckley-w-david/dwm/commit/a53eec7a5c050df0f21b58db7ae97c7759cb0901)
 - [splitstatus](https://github.com/buckley-w-david/dwm/commit/9e60c9276734074c5047f97f1dd2abbfec4848e1) with changes to keep the window title, and position one of the splits immediatly after the title
 - [remember-tags](https://bitbucket.org/jokerboy/dwm/src/master/14-dwm-6.0-remember-tags.diff) with a slight modification in the form of an missing `NULL` check.

## Custom Features

| Description   | Commit(s)     |
| ------------- | ------------- |
| Refactor existing source and header files to better match my development setup. This mainly consisdes of adding include guards to header files and extracting the declarations from [dwm.c](dwm.c) into a new header [dwm.h](dwm.h).  | [commit](https://github.com/buckley-w-david/dwm/commit/5de4dd4fd97ac6672077affd8ed2745bf99fe497)  |
| Unconditionally use SchemeNorm when rendering selected window name in bar  | [commit](https://github.com/buckley-w-david/dwm/commit/362089a79df52b7cb156b0cd7c4307d09180e390)  |
| Add delimiters between sections of the bar (tags : title : status) | [commit](https://github.com/buckley-w-david/dwm/commit/9e60c9276734074c5047f97f1dd2abbfec4848e1) |
| Add option to truncate window title to a configurable length | [commit](https://github.com/buckley-w-david/dwm/commit/9e60c9276734074c5047f97f1dd2abbfec4848e1) |
| Apply rules again when clients change their WM\_CLASS (To handle broken applications like Spotify) | [commit](https://github.com/buckley-w-david/dwm/commit/64db9b4f96547f70b4ce5470b31942f7c0570401) |
| Custom client monitor manipulations | [commit](https://github.com/buckley-w-david/dwm/commit/92b49a1f06fb7ff47aabb1d203d93fa5a755f739), [commit](https://github.com/buckley-w-david/dwm/commit/ee26efbfa30b6f6f51b9d60124ccb57527ae42a3) |

## StatusBar
[I wrote my own statusbar for use with dwm.](https://github.com/buckley-w-david/statusbar)

Feel free to use it, or something else, I'm not the boss of you.

## TODO
 * [Create a PKGBUILD](https://bitbucket.org/jokerboy/dwm/raw/0b70c4351b887fbfdb5d694ce4451d52ad9e9422/PKGBUILD)
 * Update documentation to reflect my changes
 * Check out interesting looking patches
   - [status2d](https://dwm.suckless.org/patches/status2d/) or [colored status text](https://dwm.suckless.org/patches/statuscolors/) for fancier status.
   - [statuscmd](https://dwm.suckless.org/patches/statuscmd/) for interative status
     - Add a patch to the "what block did you click" loop, set on bye, unset on hitting the same stored byte. That way we can indicate start and close of blocks, which accounts for gaps without having to reserve a dedicated close byte
   - [autostart](https://dwm.suckless.org/patches/autostart/) or [cool autostart](https://dwm.suckless.org/patches/cool_autostart/)
   - [swallow](https://dwm.suckless.org/patches/swallow/) or [dynamic swallow](https://dwm.suckless.org/patches/dynamicswallow/)
   - [shiftview.c](https://lists.suckless.org/dev/att-7590/shiftview.c)
   - [systray](https://dwm.suckless.org/patches/systray/)
   - [Single shared tagset between monitors](https://dwm.suckless.org/patches/single_tagset/) - Might not be feasable
   - [this](https://github.com/fitrh/dwm/commit/d139433339ed9289293d7353c279052d7fe3507e) and [this](https://github.com/fitrh/dwm/commit/4e8cc1d41979ab729229940bd85825326d9c66ba) patch for colourfl tags

## Resources

### Other configs (inspiration)
 * https://github.com/lukesmithxyz/dwm
 * https://github.com/fitrh/dwm
