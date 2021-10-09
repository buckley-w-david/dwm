/* See LICENSE file for copyright and license details. */

#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

/* XMonad Migration TODO
 * Important
 * - tag names
 * - auto float some stuff
 * - window border should be red (colours in general)
 * - scratchpads
 * - Scripts
 *   - M-c spawn "scripts/dmenu_python"
 *   - M-o spawn "scripts/open"
 *   - M-. spawn "scripts/emoji"
 * - Pass
 *   - M-S-p spawn "pmenu --type"
 *   - M-C-p spawn "passmenu --type"
 *   - M-M1-p spawn "passmenu"
 * - Media
 *   - <XF86AudioMute>         spawn "scripts/vol-ctl toggle"
 *   - <XF86AudioRaiseVolume>  spawn "scripts/vol-ctl up"
 *   - <XF86AudioLowerVolume>  spawn "scripts/vol-ctl down"
 *
 *   - <XF86AudioPrev>         spawn "playerctl previous"
 *   - <XF86AudioNext>         spawn "playerctl next"
 *   - <XF86AudioStop>         spawn "playerctl stop"
 *   - <XF86AudioPlay>         spawn "playerctl play-pause"
 * - Applications
 *   - <Print>        , spawn "maim -s | xclip -selection clipboard -t image/png"
 *   - M-<Print>      , spawn "maim -i $((16#$(xwininfo | grep \"Window id\" | awk '{print $4}' | cut -c3-))) ~/Pictures/Screenshots/$(date +%s).png"
 *   - M-C-<Print>    , spawn "/home/david/scripts/pinta-ss"
 *   - M-S-s          , namedScratchpadAction myScratchPads "spotify"
 *   - M-<F12>        , namedScratchpadAction myScratchPads "terminal"
 *   - M-w            , spawn "firefox-developer-edition"
 *   - M-e            , spawn "rox"
 *   - M-z            , spawn "/home/david/scripts/obsidian.sh"
 *   - M-M1-r         , spawn "/home/david/scripts/toggle-ruler"
 *   - M-M1-c         , spawn "/home/david/scripts/turbo"
 * - Migrate xmobar (Conky?)
 * - FocusFollowsMouse off
 * - Run Starup script
 * - Dynamic tag bindings
 *   - M-v - Create new workspace by string from dmenu
 *   - M-S-v - Move current window to tag by string from dmenu
 *   - M-m - Create new tag from title of current window (meh)
 *   - M-backspace - Delete current tag (meh)
 *   - M-S-r - Rename tag by string from dmenu
 * Misc
 *  - left/right arrow to move tags left/right
 *  - banish mouse to lower left corner
 *  - Remove all tags from window except current viewed one(s?)
 */

#include "dwm.h"

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[] = {
	"Iosevka:size=10",
	"Icons:size=10"
};
static const char dmenufont[]       = "Iosevka:size=10";
// static const char *fonts[]          = { "xft:Monospace:pixelsize=20" };
// static const char dmenufont[]       = "xft:Monospace:pixelsize=20";
// static const char *fonts[]          = { "monospace:size=10" };
// static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run_history", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "kitty", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } }, // Spawn dmenu_run_history
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },  // Spawn terminal
	{ MODKEY,                       XK_b,      togglebar,      {0} },              // Toggle status bar
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },       // Move focus down
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },       // Move focus up
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },       // Add 1 to # of windows in master
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },       // Remove 1 from # of windows in master
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },     // Make master wider
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },     // Make master less wide
	{ MODKEY,                       XK_Return, zoom,           {0} },              // Zoom?
	{ MODKEY,                       XK_Tab,    view,           {0} },              // Not sure
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },              // Kill currently selected window
	{ MODKEY,                       XK_space,  setlayout,      {0} },              // Toggle layout
	{ MODKEY,                       XK_t,      togglefloating, {0} },              // Toggle current window to/from floating
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },      // View all windows from all tags (I think)
//	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },      // Give current window all tags (unsigned complement of 0 is 111...)
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },       // Move focus one monitor to the left
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },       // Move focus one monitor to the right
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },       // Move the focused window to the monitor to the left
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },       // Move the focused window to the monitor to the right
	TAGKEYS(                        XK_1,                      0)                  // Show tag 0
	TAGKEYS(                        XK_2,                      1)                  // Show tag 1
	TAGKEYS(                        XK_3,                      2)                  // Show tag 2
	TAGKEYS(                        XK_4,                      3)                  // Show tag 3
	TAGKEYS(                        XK_5,                      4)                  // Show tag 4
	TAGKEYS(                        XK_6,                      5)                  // Show tag 5
	TAGKEYS(                        XK_7,                      6)                  // Show tag 6
	TAGKEYS(                        XK_8,                      7)                  // Show tag 7
	TAGKEYS(                        XK_9,                      8)                  // Show tag 8
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },              // DIE!
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} }, // Left click layout symbol to toggle
//	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} }, // Middle click window title to zoom
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } }, // What is StatusText?
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} }, // MOD + left click to move a window following the mouse
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} }, // MOD + middle click to toggle floating
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} }, // MOD + right click to resize following the mouse
	{ ClkTagBar,            0,              Button1,        view,           {0} }, // click a tag to view it
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} }, // right click a tag to toggle viewing it
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} }, // MOD + left click a tag replace current window tag to clicked
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} }, // MOD + right click to toggle clicked tag to current window
};

#endif
