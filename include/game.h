#ifndef game_h
#define game_h
#include "config.h"
#include "assets.h"
#include "components.h"

#include "riggedPoly.h"
#include "projectileManager.h"
#include "collisionFuncs.h"
#include "enemyManager.h"

#include "player.h"
#include "miscGameObjs.h"

using namespace std;

class Game{
    public:        
        Screen* screen;
        Player plr;
        Box box;
        RiggedTest rigTest;
        SnakeTest snakeTest;
        ProjectileManager projMan;
        EnemyManager enemyMan;

        //TODO find better collision organization
        vector<Polygon*> nonEnemyPolys;
};

#endif