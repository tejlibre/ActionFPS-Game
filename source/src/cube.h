#ifndef __CUBE_H__
#define __CUBE_H__

#include "platform.h"
#include "tools.h"
#include "geom.h"
#include "model.h"
#include "protocol.h"
#include "sound.h"
#include "weapon.h"
#include "entity.h"
#include "world.h"
#include "command.h"

#ifndef STANDALONE
 #include "varray.h"
 #include "vote.h"
 #include "console.h"
 enum
 {
   SDL_AF_BUTTON_WHEELDOWN = -5,
   SDL_AF_BUTTON_WHEELUP = -4,
   SDL_AF_BUTTON_RIGHT = -3,
   SDL_AF_BUTTON_MIDDLE = -2,
   SDL_AF_BUTTON_LEFT = -1
 };
#endif

extern sqr *world, *wmip[];             // map data, the mips are sequential 2D arrays in memory
extern header hdr;                      // current map header
extern _mapconfigdata mapconfigdata;    // current mapconfig
extern int sfactor, ssize;              // ssize = 2^sfactor
extern int cubicsize, mipsize;          // cubicsize = ssize^2
extern physent *camera1;                // camera representing perspective of player, usually player1
extern playerent *player1;              // special client ent that receives input and acts as camera
extern vector<playerent *> players;     // all the other clients (in multiplayer)
extern vector<bounceent *> bounceents;
extern bool editmode;
extern int unsavededits;
extern vector<entity> ents;             // map entities
extern vector<int> eh_ents;             // edithide entities
extern vec worldpos, camup, camright, camdir; // current target of the crosshair in the world
extern int lastmillis, totalmillis, nextmillis; // last time
extern int curtime;                     // current frame time
extern int interm;
extern int gamemode, nextmode;
extern int gamespeed;
extern int xtraverts;
extern float fovy, aspect;
extern int farplane;
extern bool minimap, reflecting, refracting;
extern int stenciling, stencilshadow;
extern bool intermission;
extern int arenaintermission;
extern hashtable<char *, enet_uint32> mapinfo;
extern int hwtexsize, hwmaxaniso;
extern int numspawn[3], maploaded, numflagspawn[2];
extern int verbose;
extern float waterlevel;

#define AF_VERSION 900
#define AF_WEBSITE "http://actionfps.com"
#define AF_DOWNLOAD "http://actionfps.com/download/?ref=game"
#define AF_MASTER_URI "actionfps.com"
#define AF_MASTER_PORT 28760
#define MAXCL 24
#define CONFIGROTATEMAX 5               // keep 5 old versions of saved.cfg and init.cfg around

#define DEFAULT_FOG 180
#define DEFAULT_FOGCOLOUR 0x8099B3
#define DEFAULT_SHADOWYAW 45

#include "protos.h"                     // external function decls

#endif

