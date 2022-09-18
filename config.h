/* See LICENSE file for copyright and license details. */

#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

#include <X11/XF86keysym.h>

#include "dwm.h"

#define TERMINAL     "kitty"
#define BROWSER      "firefox-developer-edition"
#define FILE_EXPLORER "rox"

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */

/* status bar */
static const int splitstatus        = 1;        /* 0 means don't split status */
static const char *splitdelim       = ";";      /* Character to split status on */
static const int delimbar           = 1;        /* 0 means don't delimit bar sections */
static const char *bardelimiter     = ":";      /* str to separate bar sections with */
static const int limittitle         = 1;        /* 0 means don't limit the title length */
static const int titlelength        = 35;       /* length to truncate window titles to - DON'T SET LARGER THAN ~250, you'll probably segfault*/


static const int focusonwheel       = 0;
static const char *fonts[] = {
	"Source Code Pro:size=10",
    "FontAwesome:size=10",
};
static const char dmenufont[]       = "Source Code Pro:size=10";
static const char normbgcolor[]     = "#202020";
static const char normbordercolor[] = "#444444";
static const char normfgcolor[]     = "#bbbbbb";
static const char selfgcolor[]      = "#eeeeee";
static const char selbordercolor[]  = "#770000";
static const char selbgcolor[]      = "#005577";

static const char col_red[]         = "#FF0000";
static const char col_orange[]      = "#FF8800";

static const char *colors[][3]      = {
	/*               fg           bg           border   */
	[SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
	[SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
 	[SchemeScratchSel]  = { selfgcolor, selbgcolor,  col_red  },
 	[SchemeScratchNorm] = { selfgcolor, selbgcolor,  col_orange },
};

/* tagging */
static const char *tags[] = { "1:main", "2:main", "3:comms", "4:media", "5:dev", "6:dev", "7:dev", "8:games", "9:games" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class         instance            title      tags mask     isfloating   monitor   scratch key */
	// { "Gimp",     NULL,               NULL,      0,            1,           -1,       0  },
	// { "Firefox",  NULL,               NULL,      1 << 8,       0,           -1,       0  },
	{ NULL,          NULL,	             NULL,      0,            False,       -1,       0  },
	{ "Steam",       NULL,               NULL,      1 << 7,       0,           -1,       0  },
	{ "Gamehub",     NULL,               NULL,      1 << 7,       0,           -1,       0  },
	{ "Lutris",      NULL,               NULL,      1 << 7,       0,           -1,       0  },
	{ "discord",     NULL,               NULL,      1 << 2,       0,           -1,       0  },
	{ "Thunderbird", NULL,               NULL,      1 << 2,       0,           -1,       0  },
	{ "mpvIdle",     NULL,               NULL,      1 << 3,       0,           -1,       0  },
	{ NULL,          "term-scratchpad",  NULL,      0,            1,           -1,       't' },
    { NULL,          "logseq",           NULL,      0,            1,           -1,       'l' },
};

/* layout(s) */
static const float mfact        = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster        = 1;    /* number of clients in master area */
static const int resizehints    = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0;    /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      tagtagmon,      {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run_history", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { TERMINAL, NULL };

/*First arg only serves to match against key in rules*/
static const char *scratchtermcmd[] = { "t", TERMINAL, "--name", "term-scratchpad", "-o", "initial_window_height=600", NULL };
static const char *scratchnotescmd[] = { "l", "logseq", NULL };

#define SCRIPT_DIR "/home/david/scripts/"
#define SCRIPT(COMMAND) { SCRIPT_DIR COMMAND, NULL }
#define VOLCTL(COMMAND) { "/home/david/scripts/vol-ctl", COMMAND, NULL }
#define PLAYERCTL(COMMAND) { "playerctl", COMMAND, NULL }

// Media Commands
static const char *volupcmd[]   = VOLCTL("up");
static const char *voldowncmd[] = VOLCTL("down");
static const char *volmutecmd[] = VOLCTL("toggle");

static const char *nextcmd[] = PLAYERCTL("next");
static const char *prevcmd[] = PLAYERCTL("previous");
static const char *stopcmd[] = PLAYERCTL("stop");
static const char *ppcmd[]   = PLAYERCTL("play-pause");

// Pass Commands
static const char *pmenucmd[]        = { "/home/david/scripts/pmenu", "--type", NULL };
static const char *passmenutypecmd[] = { "passmenu", "--type", NULL };
static const char *passmenucmd[]     = { "passmenu", NULL };

// Scripts
static const char *rulercmd[]    = SCRIPT("toggle-ruler");
static const char *turbocmd[]    = SCRIPT("turbo");
static const char *pythoncmd[]   = SCRIPT("dmenu_python");
static const char *opencmd[]     = SCRIPT("open");
static const char *emojicmd[]    = SCRIPT("emoji");
static const char *pintacmd[]    = SCRIPT("pinta-ss");

// Applications
static const char *browsercmd[]     = { BROWSER, NULL };
static const char *filecmd[]        = { FILE_EXPLORER, NULL };

// Exit
static const char *quitcmd[]      = { "killall", "startdwm", NULL };
static const char *rebootcmd[]    = { "shutdown", "-r", "now", NULL };
static const char *shutdowncmd[]  = { "shutdown", "-h", "now", NULL };



static const Key keys[] = {
	/* modifier                     key        function        argument */

	// Applications
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },   // Spawn dmenu_run_history
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },    // Spawn terminal
	{ MODKEY,                       XK_w,      spawn,          {.v = browsercmd } },
	{ MODKEY,                       XK_e,      spawn,          {.v = filecmd } },
	{ 0,                            XK_Print,  spawn,          SHCMD("maim -s | xclip -selection clipboard -t image/png") },
	{ MODKEY,                       XK_Print,  spawn,          SHCMD("maim -i $((16#$(xwininfo | grep \"Window id\" | awk '{print $4}' | cut -c3-))) ~/Pictures/Screenshots/$(date +%s).png") },
	{ MODKEY|ControlMask,           XK_Print,  spawn,          {.v = pintacmd } },

	// Pass
	{ MODKEY|ShiftMask,             XK_p,      spawn,          {.v = pmenucmd } },
	{ MODKEY|ControlMask,           XK_p,      spawn,          {.v = passmenutypecmd } },
	{ MODKEY|Mod1Mask,              XK_p,      spawn,          {.v = passmenucmd } },
    
    // Scratchpads
	{ MODKEY,                       XK_F12,      togglescratch,  {.v = scratchtermcmd } },
    { MODKEY,                       XK_z,        togglescratch,  {.v = scratchnotescmd } },
	/* { MODKEY|ShiftMask,             XK_g,      removescratch,  {.v = scratchpadcmd } }, */
	/* { MODKEY|ControlMask,           XK_g,      setscratch,     {.v = scratchpadcmd } }, */

	// Misc Controls
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
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },       // Move focus one monitor to the left
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },       // Move the focused window to the monitor to the left

	// scripts
	{ MODKEY,                       XK_c,      spawn,          {.v = pythoncmd } },   // spawn python dmenu prompt
	{ MODKEY,                       XK_o,      spawn,          {.v = opencmd } },     // spawn open script
	{ MODKEY,                       XK_period, spawn,          {.v = emojicmd } },    // spawn emoji script
	{ MODKEY|Mod1Mask,              XK_r,      spawn,          {.v = rulercmd } },    // spawn ruler script
	{ MODKEY|Mod1Mask,              XK_c,      spawn,          {.v = turbocmd } },    // spawn tubro script

	// Media
	{ 0,                            XF86XK_AudioMute,        spawn,   {.v = volmutecmd } }, // mute volume
	{ 0,                            XF86XK_AudioRaiseVolume, spawn,   {.v = volupcmd } },   // raise volume
	{ 0,                            XF86XK_AudioLowerVolume, spawn,   {.v = voldowncmd } }, // lower volume
	{ 0,                            XF86XK_AudioNext,        spawn,   {.v = nextcmd } },    // lower volume
	{ 0,                            XF86XK_AudioPrev,        spawn,   {.v = prevcmd } },    // lower volume
	{ 0,                            XF86XK_AudioStop,        spawn,   {.v = stopcmd } },    // lower volume
	{ 0,                            XF86XK_AudioPlay,        spawn,   {.v = ppcmd } },      // lower volume

	// Tags
	TAGKEYS(                        XK_1,                      0)                  // Show tag 0
	TAGKEYS(                        XK_2,                      1)                  // Show tag 1
	TAGKEYS(                        XK_3,                      2)                  // Show tag 2
	TAGKEYS(                        XK_4,                      3)                  // Show tag 3
	TAGKEYS(                        XK_5,                      4)                  // Show tag 4
	TAGKEYS(                        XK_6,                      5)                  // Show tag 5
	TAGKEYS(                        XK_7,                      6)                  // Show tag 6
	TAGKEYS(                        XK_8,                      7)                  // Show tag 7
	TAGKEYS(                        XK_9,                      8)                  // Show tag 8
	{ MODKEY,                       XK_m,                      swapmon,      {.i = 1 } }, // Swap current client to right monitor, retain tags
	{ MODKEY|ControlMask,           XK_m,                      pulltags,     {.i = 1 } }, // Pull all clients tagged with the selected tagset to the selected monitor
	{ MODKEY|ShiftMask,             XK_m,                      pullmon,      {.i = 1 } }, // Pull all visible clients from one monitor to the current

	// Exit
	// TODO: Recompile and restart
	{ MODKEY,                       XK_q,        quit,           {0} },                 // restart dwm
	{ MODKEY|ShiftMask,             XK_q,        spawn,          {.v = quitcmd } },     // quit dwm
	{ MODKEY|ControlMask,           XK_Delete,   spawn,          {.v = rebootcmd  } },  // reboot computer
	{ MODKEY|ControlMask,           XK_Insert,   spawn,           {.v = shutdowncmd } }, // shutdown computer

	// Custom
	{ MODKEY,                       XK_apostrophe,      banishpointer,  {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} }, // MOD + left click to move a window following the mouse
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} }, // MOD + right click to resize following the mouse
	{ ClkTagBar,            0,              Button1,        view,           {0} }, // click a tag to view it
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} }, // right click a tag to toggle viewing it
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} }, // MOD + left click a tag replace current window tag to clicked
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} }, // MOD + right click to toggle clicked tag to current window
};

#endif
