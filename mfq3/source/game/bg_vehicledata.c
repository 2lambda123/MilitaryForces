/*
 * $Id: bg_vehicledata.c,v 1.34 2002-02-25 12:48:26 thebjoern Exp $
*/

#include "q_shared.h"
#include "bg_public.h"

// eek!
completeLoadout_t defaultLoadout =
{
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{	{"","","","","","",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{"","","","","","",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{"","","","","","",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{"","","","","","",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{"","","","","","",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{"","","","","","",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{"","","","","","",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{"","","","","","",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	}
};

completeLoadout_t availableLoadouts[MAX_LOADOUTS];

// just contains data of all the available vehicles
completeVehicleData_t availableVehicles[] = 
{
	// ---------------------------------------------
	// Planes
	// ---------------------------------------------
    {	"F-16 Falcon",		    // descriptiveName
	"F-16",						// tinyName
	"f-16",						// modelName
	SHADOW_DEFAULT,				// alpha shadow
	MF_GAMESET_MODERN,			// id
	MF_TEAM_2,
	CAT_PLANE,
	CLASS_PLANE_FIGHTER,
	0,							// flags
	HC_GEAR|HC_SPEEDBRAKE|
	HC_VAPOR,					// capabilities
	{0,0,0,0,0,0,0,0},			// handles MUST BE NULL!
	{-26, -21, -4},				// mins (bounding box)
	{36, 21, 15},				// max (bounding box)
	{80, 80, 260},				// turnspeed around the three axis
	{0, 100, 70},				// camera distance {min,max,default}
	{0, 100, 20},				// camera height {min,max,default}
	200,						// stallspeed
	700,						// maxspeed
	0,							// min throttle
	15,							// max throttle
	1,							// engines
	0,							// wheels
	0,							// wheel circumference
	260,						// acceleration
	130,						// health
	{16.65f, -3.391f, 0.378f},	// gun tag
	60,							// max fuel
	3,							// gearheight
	0,							// tailangle
	WI_MG_20MM, WI_SIDEWINDER, WI_AMRAAM, WI_MK82, 0, 0, 0, WI_FLARE,	// weapons  WI_MG_20MM
	450, 2, 2, 12, 0, 0, 0, 30,		// ammo
	0,0,0,0,0,0,0,0,			// turret - useful ??
	PT_WINGTIP,PT_WING_M,PT_WING_H,PT_WING_H,PT_BODY_CENTER_M,0,0,0,// pylons
	{19, 0, 5},					// cameraposition for cockpit view
	AB_BALL,					// effect model
	8000,						// radar range
	4000,						// radar range ground
	0,							// trackcone
	-1,							// trackcone ground
	0,							// swingangle
	1400,						// geartime
	47,							// max gear frame
	1000,						// baytime
	47,							// max bay frame
	0,							// renderflags
	{4,0,34,24},				// shadow coordinates
	{0,0,0,0}					// shadow orientation adjusters
    },

    {	"Saab JAS 39 Gripen",    // descriptiveName
	"Jas-39",					// tinyName
	"jas-39",					// modelName
	SHADOW_DEFAULT,				// alpha shadow
	MF_GAMESET_MODERN,			// id
	MF_TEAM_1,
	CAT_PLANE,
	CLASS_PLANE_FIGHTER,
	0,							// flags
	HC_GEAR|HC_SPEEDBRAKE|
	HC_VAPOR,					// capabilities
	{0,0,0,0,0,0,0,0},			// handles MUST BE NULL!
	{-26, -19, -4},				// mins (bounding box)
	{38, 19, 12},				// max (bounding box)
	{70, 80, 340},				// turnspeed around the three axis
	{0, 100, 70},				// camera distance {min,max,default}
	{0, 100, 20},				// camera height {min,max,default}
	200,						// stallspeed
	720,						// maxspeed
	0,							// min throttle
	15,							// max throttle
	1,							// engines
	0,							// wheels
	0,							// wheel circumference
	250,						// acceleration
	130,						// health
	{19.698f, -1.328f, -3.016f},// gun tag
	60,							// max fuel
	3,							// gearheight
	0,							// tailangle
	WI_MG_20MM, WI_AMRAAM, WI_SIDEWINDER, 0, 0, 0, 0, WI_FLARE,		// weapons
	450, 5, 4, 0, 0, 0, 0, 28,	// ammo
	0,0,0,0,0,0,0,0,			// turret
	0,0,0,0,0,0,0,0,			// pylons
	{19, 0, 5},					// cameraposition for cockpit view
	AB_BALL,					// effect model
	10000,						// radar range
	3000,						// radar range ground
	0,							// trackcone
	-1,							// trackcone ground
	0,							// swingangle
	1400,						// geartime
	47,							// max gear frame
	1000,						// baytime
	47,							// max bay frame
	0,							// renderflags
	{6,0,36,20},				// shadow coordinates
	{0,0,0,0}					// shadow orientation adjusters
    },

    {	"Harrier GR-7",		    // descriptiveName
	"GR-7",						// tinyName
	"gr7",						// modelName
	SHADOW_DEFAULT,				// alpha shadow
	MF_GAMESET_MODERN,			// id
	MF_TEAM_1,
	CAT_PLANE,
	CLASS_PLANE_FIGHTER,
	0,							// flags
	HC_GEAR|
	HC_VAPOR,					// capabilities
	{0,0,0,0,0,0,0,0},			// handles MUST BE NULL!
	{-26, -19, -1},				// mins (bounding box)
	{38, 19, 12},				// max (bounding box)
	{70, 80, 340},				// turnspeed around the three axis
	{0, 100, 70},				// camera distance {min,max,default}
	{0, 100, 20},				// camera height {min,max,default}
	200,						// stallspeed
	720,						// maxspeed
	0,							// min throttle
	10,							// max throttle
	1,							// engines
	0,							// wheels
	0,							// wheel circumference
	250,						// acceleration
	130,						// health
	{19.698f, -1.328f, -3.016f},// gun tag
	60,							// max fuel
	3,							// gearheight
	0,							// tailangle
	WI_MG_20MM, WI_SIDEWINDER, WI_AMRAAM, WI_FFAR, WI_MK82, 0, 0, WI_FLARE,		// weapons
	450, 2, 2, 38, 6, 0, 0, 28,	// ammo
	0,0,0,0,0,0,0,0,			// turret
	PT_WING_L,PT_WING_L,PT_WING_H,PT_WING_H,0,0,0,0,// pylons
	{19, 0, 5},					// cameraposition for cockpit view
	AB_BALL,					// effect model
	10000,						// radar range
	3000,						// radar range ground
	0,							// trackcone
	-1,							// trackcone ground
	0,							// swingangle
	1400,						// geartime
	69,							// max gear frame
	1000,						// baytime
	47,							// max bay frame
	0,							// renderflags
	{0,0,0,0},					// shadow coordinates
	{0,0,0,0}					// shadow orientation adjusters
    },

    {	"A-10 Thunderbolt II",  // descriptiveName
	"A-10",						// tinyName
	"a10",						// modelName
	SHADOW_DEFAULT,				// alpha shadow
	MF_GAMESET_MODERN,			// id
	MF_TEAM_2,
	CAT_PLANE,
	CLASS_PLANE_BOMBER,
	0,							// flags
	HC_GEAR|HC_SPEEDBRAKE|
	HC_VAPOR|HC_DUALGUNS,		// capabilities
	{0,0,0,0,0,0,0,0},			// handles MUST BE NULL!
	{-24, -16, -1.5},			// mins (bounding box)
	{36, 16, 11},				// max (bounding box)
	{70, 80, 300},				// turnspeed around the three axis
	{0, 100, 70},				// camera distance {min,max,default}
	{0, 100, 20},				// camera height {min,max,default}
	170,						// stallspeed
	620,						// maxspeed
	0,							// min throttle
	10,							// max throttle
	2,							// engines
	0,							// wheels
	0,							// wheel circumference
	270,						// acceleration
	100,						// health
	{26.25f, -0.94f, 1.811f},	// gun tag
	80,							// max fuel
	3,							// gearheight
	0,							// tailangle
	WI_MG_2X20MM, WI_AMRAAM, WI_SIDEWINDER, WI_FFAR, 0, 0, 0, WI_FLARE,	// weapons
	500, 2, 2, 38, 0, 0, 0, 32,		// ammo
	0,0,0,0,0,0,0,0,			// turret
	0,0,0,0,0,0,0,0,			// pylons
	{11, 0, 5},					// cameraposition for cockpit view
	0,							// effect model
	6000,						// radar range
	2000,						// radar range ground
	0,							// trackcone
	-1,							// trackcone ground
	0,							// swingangle
	1400,						// geartime
	47,							// max gear frame
	1000,						// baytime
	47,							// max bay frame
	0,							// renderflags
	{5,0,34,26},				// shadow coordinates
	{0,0,0,0}					// shadow orientation adjusters
    },

    {	"F-5 Tiger",		    // descriptiveName
	"F-5",						// tinyName
	"f-5",						// modelName
	SHADOW_DEFAULT,				// alpha shadow
	MF_GAMESET_MODERN,			// id
	MF_TEAM_2,
	CAT_PLANE,
	CLASS_PLANE_FIGHTER,
	0,							// flags
	HC_GEAR|HC_SPEEDBRAKE|
	HC_VAPOR|HC_DUALGUNS,		// capabilities
	{0,0,0,0,0,0,0,0},			// handles MUST BE NULL!
	{-24, -16, -1.5},				// mins (bounding box)
	{36, 16, 11},				// max (bounding box)
	{70, 80, 380},				// turnspeed around the three axis
	{0, 100, 70},				// camera distance {min,max,default}
	{0, 100, 20},				// camera height {min,max,default}
	170,						// stallspeed
	620,						// maxspeed
	0,							// min throttle
	15,							// max throttle
	2,							// engines
	0,							// wheels
	0,							// wheel circumference
	270,						// acceleration
	100,						// health
	{26.25f, -0.94f, 1.811f},	// gun tag
	80,							// max fuel
	3,							// gearheight
	0,							// tailangle
	WI_MG_2X20MM, WI_AMRAAM, WI_SIDEWINDER, WI_FFAR, 0, 0, 0, WI_FLARE,	// weapons
	500, 2, 2, 38, 0, 0, 0, 32,		// ammo
	0,0,0,0,0,0,0,0,			// turret
	0,0,0,0,0,0,0,0,			// pylons
	{11, 0, 5},					// cameraposition for cockpit view
	AB_RED_SMALL,				// effect model
	6000,						// radar range
	2000,						// radar range ground
	0,							// trackcone
	-1,							// trackcone ground
	0,							// swingangle
	1400,						// geartime
	47,							// max gear frame
	1000,						// baytime
	47,							// max bay frame
	0,							// renderflags
	{5,0,34,26},				// shadow coordinates
	{0,0,0,0}					// shadow orientation adjusters
    },

    {	"F-15 Eagle",		    // descriptiveName
	"F-15",						// tinyName
	"f-15",						// modelName
	SHADOW_DEFAULT,				// alpha shadow
	MF_GAMESET_MODERN,			// id
	MF_TEAM_1,
	CAT_PLANE,
	CLASS_PLANE_FIGHTER,
	0,							// flags
	HC_GEAR|HC_SPEEDBRAKE|
	HC_VAPOR,					// capabilities
	{0,0,0,0,0,0,0,0},			// handles MUST BE NULL!
	{-31, -28, -5},				// mins (bounding box)
	{54, 28, 14},				// max (bounding box)
	{60, 80, 200},				// turnspeed around the three axis
	{0, 100, 70},				// camera distance {min,max,default}
	{0, 100, 20},				// camera height {min,max,default}
	220,						// stallspeed
	880,						// maxspeed
	0,							// min throttle
	15,							// max throttle
	2,							// engines
	0,							// wheels
	0,							// wheel circumference
	260,						// acceleration
	150,						// health
	{19.1f,7.87f,-0.112f},		// gun tag
	80,							// max fuel
	3,							// gearheight
	0,							// tailangle
	WI_MG_20MM, WI_AMRAAM, WI_SIDEWINDER, WI_MK82, 0, 0, 0, WI_FLARE,	// weapons
	450, 2, 4, 16, 0, 0, 0, 35,		// ammo
	0,0,0,0,0,0,0,0,			// turret
	0,0,0,0,0,0,0,0,			// pylons
	{28, 0, 6},					// cameraposition for cockpit view
	AB_RED,						// effect model
	12000,						// radar range
	6000,						// radar range ground
	0,							// trackcone
	-1,							// trackcone ground
	0,							// swingangle
	1400,						// geartime
	47,							// max gear frame
	1000,						// baytime
	47,							// max bay frame
	MFR_DUALPILOT|MFR_BIGVAPOR,	// renderflags
	{6,0,48,34},				// shadow coordinates
	{0,0,0,0}					// shadow orientation adjusters
    },

    {	"F-14 Tomcat",		    // descriptiveName
	"F-14",						// tinyName
	"f-14",						// modelName
	SHADOW_DEFAULT,				// alpha shadow
	MF_GAMESET_MODERN,			// id
	MF_TEAM_2,
	CAT_PLANE,
	CLASS_PLANE_FIGHTER,
	0,							// flags
	HC_GEAR|HC_SPEEDBRAKE|
	HC_VAPOR|HC_SWINGWING,		// capabilities
	{0,0,0,0,0,0,0,0},			// handles MUST BE NULL!
	{-29, -28, -3},				// mins (bounding box)
	{46, 28, 14},				// max (bounding box)
	{60, 80, 200},				// turnspeed around the three axis
	{0, 100, 70},				// camera distance {min,max,default}
	{0, 100, 20},				// camera height {min,max,default}
	220,						// stallspeed
	840,						// maxspeed
	0,							// min throttle
	15,							// max throttle
	2,							// engines
	0,							// wheels
	0,							// wheel circumference
	260,						// acceleration
	150,						// health
	{37.8f,2.4f,-1.3f},			// gun tag
	70,							// max fuel
	2,							// gearheight
	0,							// tailangle
	WI_MG_20MM, WI_PHOENIX, WI_SIDEWINDER, 0, 0, 0, 0, WI_FLARE,	// weapons
	450, 6, 2, 0, 0, 0, 0, 35,		// ammo
	0,0,0,0,0,0,0,0,			// turret
	0,0,0,0,0,0,0,0,			// pylons
	{28, 0, 6},					// cameraposition for cockpit view
	AB_RED,						// effect model
	16000,						// radar range
	1500,						// radar range ground
	0,							// trackcone
	-1,							// trackcone ground
	50,							// swingangle
	1400,						// geartime
	47,							// max gear frame
	1000,						// baytime
	47,							// max bay frame
	MFR_DUALPILOT|MFR_BIGVAPOR,	// renderflags
	{0,0,0,0},					// shadow coordinates
	{0,0,0,0}					// shadow orientation adjusters
    },

    {	"F-18 Hornet",		    // descriptiveName
	"F-18",						// tinyName
	"f-18",						// modelName
	SHADOW_DEFAULT,				// alpha shadow
	MF_GAMESET_MODERN,			// id
	MF_TEAM_1,
	CAT_PLANE,
	CLASS_PLANE_FIGHTER,
	0,							// flags
	HC_GEAR|HC_SPEEDBRAKE|
	HC_VAPOR,					// capabilities
	{0,0,0,0,0,0,0,0},			// handles MUST BE NULL!
	{-26, -25, -5},				// mins (bounding box)
	{44, 25, 10},				// max (bounding box)
	{80, 80, 260},				// turnspeed around the three axis
	{0, 100, 70},				// camera distance {min,max,default}
	{0, 100, 20},				// camera height {min,max,default}
	200,						// stallspeed
	720,						// maxspeed
	0,							// min throttle
	15,							// max throttle
	2,							// engines
	0,							// wheels
	0,							// wheel circumference
	260,						// acceleration
	130,						// health
	{40.3f, 0, 0.478f},			// gun tag
	60,							// max fuel
	3,							// gearheight
	0,							// tailangle
	WI_MG_20MM, WI_FFAR, WI_MK82, WI_SIDEWINDER, WI_AMRAAM, WI_PHOENIX, WI_HELLFIRE, WI_FLARE,	// weapons
	450, 24, 8, 4, 4, 4, 8, 30,		// ammo
	0,0,0,0,0,0,0,0,			// turret
	0,0,0,0,0,0,0,0,			// pylons
	{19, 0, 5},					// cameraposition for cockpit view
	AB_BALL,					// effect model
	7500,						// radar range
	6500,						// radar range ground
	0,							// trackcone
	-1,							// trackcone ground
	0,							// swingangle
	1400,						// geartime
	47,							// max gear frame
	1000,						// baytime
	47,							// max bay frame
	0,							// renderflags
	{8,0,42,42},				// shadow coordinates
	{0,0,0,0}					// shadow orientation adjusters
    },

    {	"F-22 Raptor",		    // descriptiveName
	"F-22",						// tinyName
	"f-22",						// modelName
	SHADOW_DEFAULT,				// alpha shadow
	MF_GAMESET_MODERN,			// id
	MF_TEAM_1,
	CAT_PLANE,
	CLASS_PLANE_FIGHTER,
	0,							// flags
	HC_GEAR|HC_SPEEDBRAKE|
	HC_VAPOR|HC_WEAPONBAY,		// capabilities
	{0,0,0,0,0,0,0,0},			// handles MUST BE NULL!
	{-26, -25, -5},				// mins (bounding box)
	{44, 25, 10},				// max (bounding box)
	{80, 80, 260},				// turnspeed around the three axis
	{0, 100, 70},				// camera distance {min,max,default}
	{0, 100, 20},				// camera height {min,max,default}
	200,						// stallspeed
	720,						// maxspeed
	0,							// min throttle
	15,							// max throttle
	2,							// engines
	0,							// wheels
	0,							// wheel circumference
	260,						// acceleration
	130,						// health
	{40.3f, 0, 0.478f},			// gun tag
	60,							// max fuel
	3,							// gearheight
	0,							// tailangle
	WI_MG_20MM, WI_FFAR, WI_MK82, WI_SIDEWINDER, WI_AMRAAM, WI_PHOENIX, WI_HELLFIRE, WI_FLARE,	// weapons
	450, 24, 8, 4, 4, 4, 8, 30,		// ammo
	0,0,0,0,0,0,0,0,			// turret
	0,0,0,0,0,0,0,0,			// pylons
	{19, 0, 5},					// cameraposition for cockpit view
	AB_BALL,					// effect model
	7500,						// radar range
	6500,						// radar range ground
	0,							// trackcone
	-1,							// trackcone ground
	0,							// swingangle
	1400,						// geartime
	47,							// max gear frame
	1000,						// baytime
	47,							// max bay frame
	0,							// renderflags
	{0,0,0,0},					// shadow coordinates
	{0,0,0,0}					// shadow orientation adjusters
    },

    {	"B-2 Spirit",		    // descriptiveName
	"B-2",						// tinyName
	"b-2",						// modelName
	SHADOW_DEFAULT,				// alpha shadow
	MF_GAMESET_MODERN,			// id
	MF_TEAM_1,
	CAT_PLANE,
	CLASS_PLANE_BOMBER,
	0,							// flags
	HC_GEAR|HC_SPEEDBRAKE|
	HC_VAPOR|HC_WEAPONBAY,		// capabilities
	{0,0,0,0,0,0,0,0},			// handles MUST BE NULL!
	{-26, -21, -4},				// mins (bounding box)
	{36, 21, 15},				// max (bounding box)
	{80, 80, 260},				// turnspeed around the three axis
	{0, 120, 100},				// camera distance {min,max,default}
	{0, 100, 35},				// camera height {min,max,default}
	200,						// stallspeed
	700,						// maxspeed
	0,							// min throttle
	10,							// max throttle
	2,							// engines
	0,							// wheels
	0,							// wheel circumference
	260,						// acceleration
	130,						// health
	{16.65f, -3.391f, 0.378f},	// gun tag
	60,							// max fuel
	3,							// gearheight
	0,							// tailangle
	WI_MG_20MM, WI_MK82, WI_MAVERICK, 0, 0, 0, 0, WI_FLARE,	// weapons
	450, 16, 4, 0, 0, 0, 0, 30,		// ammo
	0,0,0,0,0,0,0,0,			// turret
	0,0,0,0,0,0,0,0,			// pylons
	{19, 0, 5},					// cameraposition for cockpit view
	AB_BALL,					// effect model
	8000,						// radar range
	4000,						// radar range ground
	0,							// trackcone
	-1,							// trackcone ground
	0,							// swingangle
	1400,						// geartime
	47,							// max gear frame
	100,						// baytime
	47,							// max bay frame
	0,							// renderflags
	{3,0,76,76},				// shadow coordinates
	{0,0,0,0}					// shadow orientation adjusters
    },

    {	"P-51d Mustang",		// descriptiveName
	"P-51d",					// tinyName
	"p-51d",					// modelName
	SHADOW_DEFAULT,				// alpha shadow
	MF_GAMESET_WW2,				// id
	MF_TEAM_1,
	CAT_PLANE,
	CLASS_PLANE_FIGHTER,
	0,							// flags
	HC_GEAR|HC_PROP|
	HC_TAILDRAGGER|
	HC_DUALGUNS,				// capabilities
	{0,0,0,0,0,0,0,0},			// handles MUST BE NULL!
	{-28, -26, -3},				// mins (bounding box)
	{16, 26, 10},				// max (bounding box)
	{60, 80, 240},				// turnspeed around the three axis
	{0, 100, 50},				// camera distance {min,max,default}
	{0, 100, 10},				// camera height {min,max,default}
	130,					    // stallspeed
	600,					    // maxspeed
	0,							// min throttle
	10,						    // max throttle
	1,							// engines
	0,							// wheels
	0,							// wheel circumference
	220,						// acceleration
	100,						// health
	{3.5f, -9.2f, 0.136f},		// gun tag
	60,							// max fuel
	3,							// gearheight
	-14,						// tailangle
	WI_MG_6XCAL50, 0, 0, 0, 0, 0, 0, 0,		// weapons
	450, 0, 0, 0, 0, 0, 0, 0,	// ammo
	0,0,0,0,0,0,0,0,			// turret
	0,0,0,0,0,0,0,0,			// pylons
	{-4, 0, 8},					// cameraposition for cockpit view
	0,							// effect model
	0,							// radar range
	0,							// radar range ground
	0,							// trackcone
	-1,							// trackcone ground
	0,							// swingangle
	1400,						// geartime
	47,							// max gear frame
	1000,						// baytime
	47,							// max bay frame
	0,							// renderflags
	{2,0,30,26},				// shadow coordinates
	{0,0,0,0}					// shadow orientation adjusters
    },

    {	"Spitfire Mk 5b",		// descriptiveName
	"Spitfire",					// tinyName
	"spitfire_mk5b",			// modelName
	SHADOW_DEFAULT,				// alpha shadow
	MF_GAMESET_WW2,				// id
	MF_TEAM_1,
	CAT_PLANE,
	CLASS_PLANE_FIGHTER,
	0,							// flags
	HC_GEAR|HC_PROP|
	HC_TAILDRAGGER|
	HC_DUALGUNS,				// capabilities
	{0,0,0,0,0,0,0,0},			// handles MUST BE NULL!
	{-21, -20, -1},				// mins (bounding box)
	{10, 20, 6},				// max (bounding box)
	{70, 80, 300},				// turnspeed around the three axis
	{0, 100, 50},				// camera distance {min,max,default}
	{0, 100, 10},				// camera height {min,max,default}
	120,					    // stallspeed
	500,					    // maxspeed
	0,							// min throttle
	10,						    // max throttle
	1,							// engines
	0,							// wheels
	0,							// wheel circumference
	220,						// acceleration
	100,						// health
	{2.518f, -7.371f, -0.155f},	// gun tag
	60,							// max fuel
	3,							// gearheight
	-14,							// tailangle
	WI_MG_8XCAL50, 0, 0, 0, 0, 0, 0, 0,		// weapons
	450, 0, 0, 0, 0, 0, 0, 0,	// ammo
	0,0,0,0,0,0,0,0,			// turret
	0,0,0,0,0,0,0,0,			// pylons
	{-4, 0, 6},					// cameraposition for cockpit view
	0,							// effect model
	0,							// radar range
	0,							// radar range ground
	0,							// trackcone
	-1,							// trackcone ground
	0,							// swingangle
	1400,						// geartime
	47,							// max gear frame
	1000,						// baytime
	47,							// max bay frame
	0,							// renderflags
	{-4,0,22,20},				// shadow coordinates
	{0,0,0,0}					// shadow orientation adjusters
    },

    {	"Messerschmitt Bf-109g",// descriptiveName
	"Bf-109",					// tinyName
	"bf-109g",					// modelName
	SHADOW_DEFAULT,				// alpha shadow
	MF_GAMESET_WW2,				// id
	MF_TEAM_2,
	CAT_PLANE,
	CLASS_PLANE_FIGHTER,
	0,							// flags
	HC_GEAR|HC_PROP|
	HC_TAILDRAGGER|
	HC_DUALGUNS,				// capabilities
	{0,0,0,0,0,0,0,0},			// handles MUST BE NULL!
	{-21, -20, -1},				// mins (bounding box)
	{10, 20, 6},				// max (bounding box)
	{70, 80, 300},				// turnspeed around the three axis
	{0, 100, 50},				// camera distance {min,max,default}
	{0, 100, 10},				// camera height {min,max,default}
	120,					    // stallspeed
	500,					    // maxspeed
	0,							// min throttle
	10,						    // max throttle
	1,							// engines
	0,							// wheels
	0,							// wheel circumference
	220,						// acceleration
	100,						// health
	{2.518f, -7.371f, -0.155f},	// gun tag
	60,							// max fuel
	3,							// gearheight
	-14,							// tailangle
	WI_MG_8XCAL50, 0, 0, 0, 0, 0, 0, 0,		// weapons
	450, 0, 0, 0, 0, 0, 0, 0,	// ammo
	0,0,0,0,0,0,0,0,			// turret
	0,0,0,0,0,0,0,0,			// pylons
	{-4, 0, 6},					// cameraposition for cockpit view
	0,							// effect model
	0,							// radar range
	0,							// radar range ground
	0,							// trackcone
	-1,							// trackcone ground
	0,							// swingangle
	1400,						// geartime
	47,							// max gear frame
	1000,						// baytime
	47,							// max bay frame
	0,							// renderflags
	{-3,0,18,16},				// shadow coordinates
	{0,0,0,0}					// shadow orientation adjusters
    },

    {	"Focke-Wulf Fw190 A8",// descriptiveName
	"Fw-190",					// tinyName
	"fw190a8",					// modelName
	SHADOW_DEFAULT,				// alpha shadow
	MF_GAMESET_WW2,				// id
	MF_TEAM_2,
	CAT_PLANE,
	CLASS_PLANE_FIGHTER,
	0,							// flags
	HC_GEAR|HC_PROP|
	HC_TAILDRAGGER|
	HC_DUALGUNS,				// capabilities
	{0,0,0,0,0,0,0,0},			// handles MUST BE NULL!
	{-21, -20, -1},				// mins (bounding box)
	{10, 20, 6},				// max (bounding box)
	{70, 80, 300},				// turnspeed around the three axis
	{0, 100, 50},				// camera distance {min,max,default}
	{0, 100, 10},				// camera height {min,max,default}
	120,					    // stallspeed
	500,					    // maxspeed
	0,							// min throttle
	10,						    // max throttle
	1,							// engines
	0,							// wheels
	0,							// wheel circumference
	220,						// acceleration
	100,						// health
	{2.518f, -7.371f, -0.155f},	// gun tag
	60,							// max fuel
	3,							// gearheight
	-14,							// tailangle
	WI_MG_8XCAL50, 0, 0, 0, 0, 0, 0, 0,		// weapons
	450, 0, 0, 0, 0, 0, 0, 0,	// ammo
	0,0,0,0,0,0,0,0,			// turret
	0,0,0,0,0,0,0,0,			// pylons
	{-4, 0, 6},					// cameraposition for cockpit view
	0,							// effect model
	0,							// radar range
	0,							// radar range ground
	0,							// trackcone
	-1,							// trackcone ground
	0,							// swingangle
	1400,						// geartime
	47,							// max gear frame
	1000,						// baytime
	47,							// max bay frame
	0,							// renderflags
	{-2,0,18,18},				// shadow coordinates
	{0,0,0,0}					// shadow orientation adjusters
    },


    {	"B-17g",				// descriptiveName
	"B-17",						// tinyName
	"b17g",						// modelName
	SHADOW_DEFAULT,				// alpha shadow
	MF_GAMESET_WW2,				// id
	MF_TEAM_1,
	CAT_PLANE,
	CLASS_PLANE_BOMBER,
	0,							// flags
	HC_GEAR|HC_PROP|
	HC_TAILDRAGGER|
	HC_WEAPONBAY,				// capabilities
	{0,0,0,0,0,0,0,0},			// handles MUST BE NULL!
	{-36, -40, -3},				// mins (bounding box)
	{30, 40, 9},				// max (bounding box)
	{40, 50, 120},				// turnspeed around the three axis
	{0, 100, 80},				// camera distance {min,max,default}
	{0, 100, 10},				// camera height {min,max,default}
	120,					    // stallspeed
	500,					    // maxspeed
	0,							// min throttle
	10,						    // max throttle
	4,							// engines
	0,							// wheels
	0,							// wheel circumference
	220,						// acceleration
	100,						// health
	{2.518f, -7.371f, -0.155f},	// gun tag
	60,							// max fuel
	3,							// gearheight
	-8,							// tailangle
	WI_MG_8XCAL50, WI_MK82, 0, 0, 0, 0, 0, 0,		// weapons
	450, 10, 0, 0, 0, 0, 0, 0,	// ammo
	0,0,0,0,0,0,0,0,			// turret
	0,0,0,0,0,0,0,0,			// pylons
	{-4, 0, 6},					// cameraposition for cockpit view
	0,							// effect model
	0,							// radar range
	0,							// radar range ground
	0,							// trackcone
	-1,							// trackcone ground
	0,							// swingangle
	1400,						// geartime
	47,							// max gear frame
	500,						// baytime
	19,							// max bay frame
	0,							// renderflags
	{-12,0,60,60},				// shadow coordinates
	{0,0,0,0}					// shadow orientation adjusters
	},

    {	"Fokker Dr.1",			// descriptiveName
	"Fokker",					// tinyName
	"dr1",						// modelName
	SHADOW_DEFAULT,				// alpha shadow
	MF_GAMESET_WW1,				// id
	MF_TEAM_1,
	CAT_PLANE,
	CLASS_PLANE_FIGHTER,
	0,							// flags
	HC_PROP|
	HC_TAILDRAGGER|
	HC_DUALGUNS,				// capabilities
	{0,0,0,0,0,0,0,0},			// handles MUST BE NULL!
	{-21, -20, -1},				// mins (bounding box)
	{10, 20, 6},				// max (bounding box)
	{70, 80, 300},				// turnspeed around the three axis
	{0, 100, 30},				// camera distance {min,max,default}
	{0, 100, 10},				// camera height {min,max,default}
	50,						    // stallspeed
	150,					    // maxspeed
	0,							// min throttle
	10,						    // max throttle
	1,							// engines
	0,							// wheels
	0,							// wheel circumference
	220,						// acceleration
	100,						// health
	{2.518f, -1.371f, -0.155f},	// gun tag
	60,							// max fuel
	3,							// gearheight
	-14,							// tailangle
	WI_MG_2XCAL312, 0, 0, 0, 0, 0, 0, 0,		// weapons
	450, 0, 0, 0, 0, 0, 0, 0,	// ammo
	0,0,0,0,0,0,0,0,			// turret
	0,0,0,0,0,0,0,0,			// pylons
	{-4, 0, 6},					// cameraposition for cockpit view
	0,							// effect model
	0,							// radar range
	0,							// radar range ground
	0,							// trackcone
	-1,							// trackcone ground
	0,							// swingangle
	1400,						// geartime
	47,							// max gear frame
	1000,						// baytime
	47,							// max bay frame
	0,							// renderflags
	{-3,0,13,12},				// shadow coordinates
	{0,0,0,0}					// shadow orientation adjusters
    },

    {	"Sopwith camel",		// descriptiveName
	"Camel",					// tinyName
	"camel",					// modelName
	SHADOW_DEFAULT,				// alpha shadow
	MF_GAMESET_WW1,				// id
	MF_TEAM_2,
	CAT_PLANE,
	CLASS_PLANE_FIGHTER,
	0,							// flags
	HC_PROP|
	HC_TAILDRAGGER|
	HC_DUALGUNS,				// capabilities
	{0,0,0,0,0,0,0,0},			// handles MUST BE NULL!
	{-21, -14, -1},				// mins (bounding box)
	{10, 14, 6},				// max (bounding box)
	{70, 80, 300},				// turnspeed around the three axis
	{0, 100, 30},				// camera distance {min,max,default}
	{0, 100, 10},				// camera height {min,max,default}
	50,						    // stallspeed
	150,					    // maxspeed
	0,							// min throttle
	10,						    // max throttle
	1,							// engines
	0,							// wheels
	0,							// wheel circumference
	220,						// acceleration
	100,						// health
	{2.518f, -1.371f, -0.155f},	// gun tag
	60,							// max fuel
	3,							// gearheight
	-14,							// tailangle
	WI_MG_2XCAL303, 0, 0, 0, 0, 0, 0, 0,		// weapons
	450, 0, 0, 0, 0, 0, 0, 0,	// ammo
	0,0,0,0,0,0,0,0,			// turret
	0,0,0,0,0,0,0,0,			// pylons
	{-4, 0, 6},					// cameraposition for cockpit view
	0,							// effect model
	0,							// radar range
	0,							// radar range ground
	0,							// trackcone
	-1,							// trackcone ground
	0,							// swingangle
	1400,						// geartime
	47,							// max gear frame
	1000,						// baytime
	47,							// max bay frame
	0,							// renderflags
	{-1,0,15,14},				// shadow coordinates
	{0,0,0,0}					// shadow orientation adjusters
    },

	// ---------------------------------------------
	// Ground Vehicles
	// ---------------------------------------------

    {	"M1A1i Abrams",			// descriptiveName
	"M1",						// tinyName
	"m1",						// modelName
	SHADOW_DEFAULT,				// alpha shadow
	MF_GAMESET_MODERN,			// id
	MF_TEAM_1,
	CAT_GROUND,
	CLASS_GROUND_MBT,
	0,							// flags
	0,							// capabilities
	{0,0,0,0,0,0,0,0},			// handles MUST BE NULL!
	{-18, -9, -1},				// mins (bounding box)
	{18, 9, 9},					// max (bounding box)
	{50, 100, 100},				// turnspeed around the three axis
	{0, 100, 40},				// camera distance {min,max,default}
	{0, 100, 20},				// camera height {min,max,default}
	0,							// stallspeed
	60,						    // maxspeed
	-5,							// min throttle
	10,						    // max throttle
	1,							// engines
	0,							// wheels
	0,							// wheel circumference
	15,							// acceleration
	400,						// health
	{5, 0, 8},					// gun tag
	150,						// max fuel
	310,						// max gun pitch (upwards = negative) <- gearheight
	3,							// min gun pitch (downwards = positive) <- tailangle
	WI_MG_12_7MM, WI_125MM_GUN, WI_STINGER, WI_HELLFIRE, 0, 0, 0, WI_FLARE,// weapons
	500, 40, 4, 2, 0, 0, 0, 20,	// ammo
	0,0,0,0,0,0,0,0,			// turret
	0,0,0,0,0,0,0,0,			// pylons
	{0, 0, 14},					// cameraposition for cockpit view
	0,							// effect model
	8000,						// radar range
	4000,						// radar range ground
	-1,							// trackcone
	0,							// trackcone ground
	0,							// swingangle
	1400,						// geartime
	47,							// max gear frame
	1000,						// baytime
	47,							// max bay frame
	0,							// renderflags
	{0,0,0,0},					// shadow coordinates
	{0,0,0,0}					// shadow orientation adjusters
    },

    {	"T-90",					// descriptiveName
	"T-90",						// tinyName
	"t-90",						// modelName
	SHADOW_DEFAULT,				// alpha shadow
	MF_GAMESET_MODERN,			// id
	MF_TEAM_2,
	CAT_GROUND,
	CLASS_GROUND_MBT,
	0,							// flags
	0,							// capabilities
	{0,0,0,0,0,0,0,0},			// handles MUST BE NULL!
	{-17, -9, -1},				// mins (bounding box)
	{17, 9, 7},					// max (bounding box)
	{50, 100, 100},				// turnspeed around the three axis
	{0, 100, 40},				// camera distance {min,max,default}
	{0, 100, 20},				// camera height {min,max,default}
	0,							// stallspeed
	65,						    // maxspeed
	-5,							// min throttle
	10,						    // max throttle
	1,							// engines
	0,							// wheels
	0,							// wheel circumference
	15,							// acceleration
	450,						// health
	{25, 0, 2},					// gun tag
	150,						// max fuel
	310,						// max gun pitch (upwards = negative) <- gearheight
	3,							// min gun pitch (downwards = positive) <- tailangle
	WI_MG_12_7MM, WI_125MM_GUN, WI_STINGER, WI_HELLFIRE, 0, 0, 0, WI_FLARE,// weapons
	500, 40, 4, 2, 0, 0, 0, 20,	// ammo
	0,0,0,0,0,0,0,0,			// turret
	0,0,0,0,0,0,0,0,			// pylons
	{0, 0, 14},					// cameraposition for cockpit view
	0,							// effect model
	8000,						// radar range
	4000,						// radar range ground
	-1,							// trackcone
	0,							// trackcone ground
	0,							// swingangle
	1400,						// geartime
	47,							// max gear frame
	1000,						// baytime
	47,							// max bay frame
	0,							// renderflags
	{0,0,0,0},					// shadow coordinates
	{0,0,0,0}					// shadow orientation adjusters
    },

    {	"BMP 3",				// descriptiveName
	"BMP-3",					// tinyName
	"bmp-3",					// modelName
	SHADOW_DEFAULT,				// alpha shadow
	MF_GAMESET_MODERN,			// id
	MF_TEAM_1,
	CAT_GROUND,
	CLASS_GROUND_RECON,
	0,							// flags
	HC_DUALGUNS,				// capabilities
	{0,0,0,0,0,0,0,0},			// handles MUST BE NULL!
	{-10, -5, -1},				// mins (bounding box)
	{11, 5, 4.5},				// max (bounding box)
	{50, 100, 100},				// turnspeed around the three axis
	{0, 100, 30},				// camera distance {min,max,default}
	{0, 100, 10},				// camera height {min,max,default}
	0,							// stallspeed
	75,						    // maxspeed
	-5,							// min throttle
	10,						    // max throttle
	1,							// engines
	0,							// wheels
	0,							// wheel circumference
	18,							// acceleration
	240,						// health
	{8, 1, 2},					// gun tag
	160,						// max fuel
	300,						// max gun pitch (upwards = negative) <- gearheight
	6,							// min gun pitch (downwards = positive) <- tailangle
	WI_MG_14_5MM, WI_100MM_GUN, WI_STINGER, WI_HELLFIRE, 0, 0, 0, WI_FLARE,// weapons
	500, 35, 2, 2, 0, 0, 0, 20,	// ammo
	0,0,0,0,0,0,0,0,			// turret
	0,0,0,0,0,0,0,0,			// pylons
	{0, 0, 10},					// cameraposition for cockpit view
	0,							// effect model
	8000,						// radar range
	4000,						// radar range ground
	-1,							// trackcone
	0,							// trackcone ground
	0,							// swingangle
	1400,						// geartime
	47,							// max gear frame
	1000,						// baytime
	47,							// max bay frame
	0,							// renderflags
	{0,0,0,0},					// shadow coordinates
	{0,0,0,0}					// shadow orientation adjusters
    },

    {	"Hummer",				// descriptiveName
	"HMV",						// tinyName
	"humvee_50cal",				// modelName
	SHADOW_DEFAULT,				// alpha shadow
	MF_GAMESET_MODERN,			// id
	MF_TEAM_1,
	CAT_GROUND,
	CLASS_GROUND_RECON,
	0,							// flags
	HC_WHEELS,					// capabilities
	{0,0,0,0,0,0,0,0},			// handles MUST BE NULL!
	{-10, -5, -2},				// mins (bounding box)
	{11, 5, 4.5},				// max (bounding box)
	{50, 100, 100},				// turnspeed around the three axis
	{0, 100, 30},				// camera distance {min,max,default}
	{0, 100, 10},				// camera height {min,max,default}
	0,							// stallspeed
	85,						    // maxspeed
	-5,							// min throttle
	10,						    // max throttle
	1,							// engines
	4,							// wheels
	8,							// wheel circumference
	18,							// acceleration
	240,						// health
	{8, 0, 2},					// gun tag
	160,						// max fuel
	300,						// max gun pitch (upwards = negative) <- gearheight
	6,							// min gun pitch (downwards = positive) <- tailangle
	WI_MG_12_7MM, 0, 0, 0, 0, 0, 0, WI_FLARE,// weapons
	500, 0, 0, 0, 0, 0, 0, 20,	// ammo
	0,0,0,0,0,0,0,0,			// turret
	0,0,0,0,0,0,0,0,			// pylons
	{0, 0, 10},					// cameraposition for cockpit view
	0,							// effect model
	8000,						// radar range
	4000,						// radar range ground
	-1,							// trackcone
	0,							// trackcone ground
	0,							// swingangle
	1400,						// geartime
	47,							// max gear frame
	1000,						// baytime
	47,							// max bay frame
	0,							// renderflags
	{0,0,0,0},					// shadow coordinates
	{0,0,0,0}					// shadow orientation adjusters
    },

    {	"BRDM 2",				// descriptiveName
	"BRDM2",					// tinyName
	"brdm2",					// modelName
	SHADOW_DEFAULT,				// alpha shadow
	MF_GAMESET_MODERN,			// id
	MF_TEAM_2,
	CAT_GROUND,
	CLASS_GROUND_RECON,
	0,							// flags
	HC_DUALGUNS|HC_AMPHIBIOUS|HC_WHEELS,	// capabilities
	{0,0,0,0,0,0,0,0},			// handles MUST BE NULL!
	{-10, -5, -2},				// mins (bounding box)
	{10, 5, 7},					// max (bounding box)
	{50, 100, 100},				// turnspeed around the three axis
	{0, 100, 30},				// camera distance {min,max,default}
	{0, 100, 10},				// camera height {min,max,default}
	0,							// stallspeed
	90,						    // maxspeed
	-5,							// min throttle
	10,						    // max throttle
	1,							// engines
	4,							// wheels
	9,							// wheel circumference
	18,							// acceleration
	180,						// health
	{3, 1, 6},					// gun tag
	160,						// max fuel
	285,						// max gun pitch (upwards = negative) <- gearheight
	5,							// min gun pitch (downwards = positive) <- tailangle
	WI_MG_14_5MM, WI_STINGER, WI_HELLFIRE, 0, 0, 0, 0, WI_FLARE,// weapons
	600, 2, 4, 0, 0, 0, 0, 20,	// ammo
	0,0,0,0,0,0,0,0,			// turret
	0,0,0,0,0,0,0,0,			// pylons
	{0, 0, 10},					// cameraposition for cockpit view
	0,							// effect model
	8000,						// radar range
	4000,						// radar range ground
	-1,							// trackcone
	0,							// trackcone ground
	0,							// swingangle
	1400,						// geartime
	47,							// max gear frame
	1000,						// baytime
	47,							// max bay frame
	0,							// renderflags
	{0,0,0,0},					// shadow coordinates
	{0,0,0,0}					// shadow orientation adjusters
    },

    {	"Panzer III",			// descriptiveName
	"Pz 3",						// tinyName
	"panzeriii",				// modelName
	SHADOW_DEFAULT,				// alpha shadow
	MF_GAMESET_WW2,				// id
	MF_TEAM_1,
	CAT_GROUND,
	CLASS_GROUND_MBT,
	0,							// flags
	0,							// capabilities
	{0,0,0,0,0,0,0,0},			// handles MUST BE NULL!
	{-12, -6, -2},				// mins (bounding box)
	{12, 6, 9},					// max (bounding box)
	{50, 100, 100},				// turnspeed around the three axis
	{0, 100, 30},				// camera distance {min,max,default}
	{0, 100, 10},				// camera height {min,max,default}
	0,							// stallspeed
	60,						    // maxspeed
	-5,							// min throttle
	10,						    // max throttle
	1,							// engines
	0,							// wheels
	0,							// wheel circumference
	15,							// acceleration
	400,						// health
	{5, 0, 8},					// gun tag
	150,						// max fuel
	335,						// max gun pitch (upwards = negative) <- gearheight
	3,							// min gun pitch (downwards = positive) <- tailangle
	WI_MG_12_7MM, WI_125MM_GUN, 0, 0, 0, 0, 0, WI_FLARE,// weapons
	500, 40, 0, 0, 0, 0, 0, 20,	// ammo
	0,0,0,0,0,0,0,0,			// turret
	0,0,0,0,0,0,0,0,			// pylons
	{0, 0, 14},					// cameraposition for cockpit view
	0,							// effect model
	8000,						// radar range
	4000,						// radar range ground
	-1,							// trackcone
	0,							// trackcone ground
	0,							// swingangle
	1400,						// geartime
	47,							// max gear frame
	1000,						// baytime
	47,							// max bay frame
	0,							// renderflags
	{0,0,0,0},					// shadow coordinates
	{0,0,0,0}					// shadow orientation adjusters
    },

	// ---------------------------------------------
	// Boats
	// ---------------------------------------------

    {	"Patrolboat",			// descriptiveName
	"PBR31",					// tinyName
	"pbr31mk2",					// modelName
	SHADOW_DEFAULT,				// alpha shadow
	MF_GAMESET_MODERN,			// id
	MF_TEAM_1,
	CAT_BOAT,
	CLASS_BOAT_PATROL,
	0,							// flags
	HC_DUALGUNS,				// capabilities
	{0,0,0,0,0,0,0,0},			// handles MUST BE NULL!
	{-16, -7, -2},				// mins (bounding box)
	{16, 7, 6},					// max (bounding box)
	{50, 100, 20},				// turnspeed around the three axis
	{0, 100, 30},				// camera distance {min,max,default}
	{0, 100, 10},				// camera height {min,max,default}
	0,							// stallspeed
	50,						    // maxspeed
	-5,							// min throttle
	10,						    // max throttle
	1,							// engines
	0,							// wheels
	0,							// wheel circumference
	15,							// acceleration
	400,						// health
	{5, 0, 8},					// gun tag
	150,						// max fuel
	8,							// max angle to lean when turning <- gearheight
	-5,							// bowangle (depends on speeed) <-tailangle 
	0, WI_MGT_2X30MM, WI_MGT_12_7MM, 0, 0, 0, 0, WI_FLARE,// weapons
	0, 500, 300, 0, 0, 0, 0, 20,	// ammo
	1,2,0,0,0,0,0,0,			// turret
	0,0,0,0,0,0,0,0,			// pylons
	{0, 0, 6},					// cameraposition for cockpit view
	0,							// effect model
	8000,						// radar range
	4000,						// radar range ground
	-1,							// trackcone
	0,							// trackcone ground
	0,							// swingangle
	1400,						// geartime
	47,							// max gear frame
	1000,						// baytime
	47,							// max bay frame
	0,							// renderflags
	{0,0,0,0},					// shadow coordinates
	{0,0,0,0}					// shadow orientation adjusters
    }
};

int bg_numberOfVehicles = sizeof(availableVehicles) / sizeof(availableVehicles[0]);

const char *gameset_items[MF_MAX_GAMESETS+1] =
{
	"Modern",
	"World War II",
	"World War I",
	0,
	0,
	0,
	0,
	0,
	0
};

const char *team_items[MF_MAX_GAMESETS][MF_MAX_TEAMS+1] =
{
	// modern
	{
		"NATO",
		"Rebels",
		0,
		0,
		0,
		0,
		0,
		0,
		0
	},

	// world war 2
	{
		"U.S.Air Force",
		"Royal Air Force",
		0,
		0,
		0,
		0,
		0,
		0,
		0
	},

	// world war 1
	{
		"Germany",
		"England",
		0,
		0,
		0,
		0,
		0,
		0,
		0
	},

	// free
	{
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	},

	// free
	{
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	},

	// free
	{
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	},

	// free
	{
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	},

	// free
	{
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	}
};

const char *cat_fileRef[MF_MAX_CATEGORIES+1] =
{
	// categories
	"Plane",
	"GroundVehicle",
	"Helicopter",	// ok that way, Mark ?
	"Infantry",
	"Boat",
	0,
	0,
	0,
	0
};

const char *cat_items[MF_MAX_CATEGORIES+1] =
{
	// categories
	"Planes",
	"Ground Vehicles",
	"Helicopters",
	"Infantry",
	"Boats",
	0,
	0,
	0,
	0
};

const char *class_items[MF_MAX_CATEGORIES][MF_MAX_CLASSES+1] =
{	
	// planes
	{
		"Fighter",
		"Bomber",
		0,
		0,
		0,
		0,
		0,
		0,
		0
	},

	// ground vehicles
	{
		"MBT",
		"Recon",
		"APC",
		"SAM",
		"AAG",
		"Transport",
		"Light",
		0,
		0
	},

	// helicopters
	{
		"Attack",
		"Recon",
		"Transport",
		0,
		0,
		0,
		0,
		0,
		0
	},

	// infantry
	{
		"Special Unit",
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	},

	// boats
	{
		"Patrol Boat",
		"Transport Boat",
		0,
		0,
		0,
		0,
		0,
		0,
		0
	},

	// free
	{
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	},

	// free
	{
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	},

	// free
	{
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	}
};

