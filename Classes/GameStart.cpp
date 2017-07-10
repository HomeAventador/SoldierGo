#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GameStart.h"
#include <iostream>

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace cocostudio;
using namespace std;

//choose level
static int level = 1;

//get star number
static int star = 0;

//blood
static int blood = 5;

//monster
static int mondire = 0;

//monsterX
Point monspoint;

//monsterblood
static int monblood = 3;

//////////////////////1==yellow;2==green;3==monster;5==grass;6==ice;7==trap;8==spring;9==cloud;10==stone;11==hero;12==endpoint;13==tree_01;14==tree_02;
//////////////////////15==startpoint1;16==endpoint1;17==startpoint2;18==endpoint2;19==notsee;20==star1;21==star2;22==star3;23==star4;24==star5
int map_2[27][48] = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 
					{ 1, 1, 1, 1, 1, 1, 1, 1, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 1, 1, 1, 1,18, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 1, 1, 1, 1,24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2 },
					{ 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 0, 1, 0,23, 1, 1, 1 },
					{ 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1 },
					{ 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 0, 0, 0, 0, 0, 0, 0,19, 0, 0, 1, 1, 1 },
					{ 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0,22, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,19, 0, 0, 1, 1, 1 },
					{ 1, 1, 1, 1,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 2, 2, 1, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,19, 1, 1, 1 },
					{ 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 9, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 2, 1, 1, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 1, 1, 1,19, 1, 1, 1 },
					{ 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 7, 7, 7, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10,10,10,10,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,14,17, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,16, 0, 0, 0, 0, 0,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 2, 2, 2, 8, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 1, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,21, 0, 0, 2, 2, 2, 2, 2 },
					{ 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 2, 1, 1, 1, 1 },
					{ 1, 1, 1, 2, 2,11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,10, 7, 7,10, 7, 7,10, 0, 0, 0, 0, 2, 1, 1, 1, 1 },
					{ 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1 },
					{ 1, 1, 1, 1, 2, 2, 2, 2, 0,13, 0, 0, 0, 0, 0,10,10, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1 },
					{ 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 7, 7, 2, 1, 2, 2, 2, 2, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 2, 1, 1, 1, 1 },
					{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 7, 7, 2, 7, 7, 2, 7, 7, 2, 7, 7, 2, 2, 1, 1, 1, 1 },
					{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
					{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
					{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };
//////////////////////1==dirtall;2==dirtleft;3==dirtright;4==dirttop;5==grass;6==ice;7==trap;8==spring;9==cloud;10==stone;11==hero;12==endpoint;13==tree_01;14==tree_02
//////////////////////15==startpoint1;16==endpoint1;17==startpoint2;18==endpoint2;19==notsee;20==star1;21==star2;22==star3;23==star4;24==star5
int map_3[27][48] = {   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10, 0,10, 0, 0, 0, 0, 0,10,10, 1, 1, 1 },
						{ 1, 1, 0, 0, 2, 0, 2,24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1 },
						{ 1, 1, 0, 0, 2, 0, 2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 },
						{ 1, 1, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 2, 2, 2, 2, 7, 2, 7, 2, 0, 0, 1, 1, 1 },
						{ 1, 1, 0,17, 2, 0, 0, 0, 0, 0, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0,16, 0, 0, 0, 2, 1, 1, 1 },
						{ 1, 1, 2, 2, 2, 8, 2, 2, 2, 2,19, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,19, 2, 2, 2, 2, 2, 2, 8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 1, 1 },
						{ 1, 1, 2, 0, 0, 0, 0, 0, 0, 2,23, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 8,19, 1, 1, 1 },
						{ 1, 1, 2, 0, 0, 0,11, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,19, 1, 1, 1 },
						{ 1, 1, 2, 0, 0, 0, 0, 0, 0, 2, 8, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,19, 1, 1, 1 },
						{ 1, 1,10, 0, 2, 2, 2, 2, 2, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 },
						{ 1, 1,10, 0, 2,18, 0, 0, 0, 0, 1, 2, 0,20, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1,22, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 },
						{ 1, 1,10, 0, 2, 0, 0, 0,12, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 7, 7, 7, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 1, 1, 1 },
						{ 1, 1,10, 0, 2, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 },
						{ 1, 1,10, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,15, 0, 0, 0, 1, 1, 1 },
						{ 1, 1,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1 },
						{ 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,21, 1, 1, 1 },
						{ 1, 1, 2, 2, 0, 0, 2, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 7, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 },
						{ 1, 1, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 8, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 },
						{ 1, 1, 2, 7, 7, 7, 7, 2, 7, 7, 7, 7, 7, 7, 1, 1, 7, 7, 7, 7, 7, 7, 1, 1, 8, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1  },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };
//////////////////////1==dirtall;2==dirtleft;3==dirtright;4==dirttop;5==grass;6==ice;7==trap;8==spring;9==cloud;10==stone;11==hero;12==endpoint;13==tree_01;14==tree_02
//////////////////////15==startpoint1;16==endpoint1;17==startpoint2;18==endpoint2;19==notsee;20==star1;21==star2;22==star3;23==star4;24==star5
int map_1[27][48] = {   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,24, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10, 0, 0, 0, 0, 0, 0, 0, 0,23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 2, 0,11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12, 2, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 2, 0, 0, 0, 0,20, 0, 0, 0, 0, 0, 0, 0,21, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 7, 7, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 8, 2, 2, 2, 8, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };
Scene* GameStart::createScene(int _level)
{	
	level = _level;
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0, -2000));

	// 'layer' is an autorelease object
	auto layer = GameStart::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;

}

// on "init" you need to initialize your instance
bool GameStart::init()
{
	blood = 5;
	monblood = 3;
	star = 0;
	if (!Layer::init())
	{
		return false;
	}

	//init map
	switch (level)
	{
		case 1:{
			loadingBox(map_1);
			break;
		}
		case 2:{
			loadingBox(map_2);
			break;
		}
		case 3:{
			loadingBox(map_3);
			break;
		}
		default:
			break;
			
	}

	//KeyBoardListener
	auto keyBoardListener = EventListenerKeyboard::create();
	keyBoardListener->onKeyPressed = CC_CALLBACK_2(GameStart::onKeyPressed, this);
	keyBoardListener->onKeyReleased = CC_CALLBACK_2(GameStart::onKeyReleased, this);

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyBoardListener, this);

	scheduleUpdate();

	addListener();

	 delay_action_open = false;
	return true;
}

void GameStart::loadingBox(int map[27][48]){
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//Background
	auto backPic = Sprite::create("StartBack1.png");
	backPic->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	addChild(backPic, 0);

	//edge
	auto edge = Edge::create();
	addChild(edge, 1);

	//add cloud
	initCloud();

	auto sun = Sprite::create("cloud3.png");
	sun->setPosition(800, 600);
	addChild(sun, 1);

	for (int i = 26; i >= 0; i--){
		for (int j = 0; j < 48; j++){
			if (map[i][j] == 1){
				yellow = YellowBox::create();
				yellow->setPosition(Vec2(80 * j - 1250, 1390 - 80 * i));
				addChild(yellow, 1);
			}
			if (map[i][j] == 2){
				green = GreenBox::create();
				green->setPosition(Vec2(80 * j - 1250, 1390 - 80 * i));
				addChild(green, 1);
			}
			if (map[i][j] == 3){
				monster = Block::create();
				monster->setPosition(Vec2(80 * j - 1250, 1520 - 80 * i ));
				addChild(monster, 1);
				monspoint.x = monsterPoint.x = 80 * j - 1250;
				monspoint.y = monsterPoint.y = 1520 - 80 * i;
			}
			if (map[i][j] == 5){
				grass = Grass::create();
				grass->setPosition(Vec2(80 * j - 1250, 1390 - 80 * i));
				addChild(grass, 1);
			}
			if (map[i][j] == 6){
				ice = Ice::create();
				ice->setPosition(Vec2(80 * j - 1250, 1390 - 80 * i));
				addChild(ice, 1);
			}
			if (map[i][j] == 7){
				trap = Trap::create();
				trap->setPosition(Vec2(80 * j - 1250, 1390 - 80 * i));
				addChild(trap, 1);
			}
			if (map[i][j] == 8){
				spring = Spring::create();
				spring->setPosition(Vec2(80 * j - 1250, 1390 - 80 * i));
				addChild(spring, 1);
			}
			if (map[i][j] == 9){
				cl = Cloud::create();
				cl->setPosition(Vec2(80 * j - 1250, 1390 - 80 * i));
				addChild(cl, 1);
			}
			if (map[i][j] == 10){
				st = Stone::create();
				st->setPosition(Vec2(80 * j - 1250, 1390 - 80 * i));
				addChild(st, 1);
			}
			if (map[i][j] == 11){
				//hero 
				hero = Hero::create();
				hero->setPosition(Vec2(80 * j - 1250, 1390 - 80 * i));
				addChild(hero, 2);
			}
			if (map[i][j] == 12){
				ep = EndPoint::create();
				ep->setPosition(Vec2(80 * j - 1250, 1390 - 80 * i - 5));
				addChild(ep, 2);
			}
			if (map[i][j] == 13){
				ts = TreeSmall::create();
				ts->setPosition(Vec2(80 * j - 1250, 1390 - 80 * i + 110));
				addChild(ts, 2);
			}
			if (map[i][j] == 14){
				tr = TreeRight::create();
				tr->setPosition(Vec2(80 * j - 1215, 1390 - 80 * i ));
				addChild(tr, 2);
			}
			if (map[i][j] == 15){
				ds = Delivers::create();
				ds->setPosition(Vec2(80 * j - 1250, 1390 - 80 * i));
				addChild(ds, 2);
			}
			if (map[i][j] == 16){
				de = Delivere::create();
				de->setPosition(Vec2(80 * j - 1250, 1390 - 80 * i));
				addChild(de, 1);
			}
			if (map[i][j] == 17){
				det = Delivert::create();
				det->setPosition(Vec2(80 * j - 1250, 1390 - 80 * i));
				addChild(det, 1);
			}
			if (map[i][j] == 18){
				dn = Delivern::create();
				dn->setPosition(Vec2(80 * j - 1250, 1390 - 80 * i));
				addChild(dn, 1);
			}
			if (map[i][j] == 19){
				lu = Lucency::create();
				lu->setPosition(Vec2(80 * j - 1250, 1390 - 80 * i));
				addChild(lu, 1);
			}
			if (map[i][j] == 20){
				st1 = Star::create();
				st1->getPhysicsBody()->setTag(120);
				st1->setPosition(Vec2(80 * j - 1250, 1390 - 80 * i));
				addChild(st1, 1);
			}
			if (map[i][j] == 21){
				st2 = Star::create();
				st2->getPhysicsBody()->setTag(121);
				st2->setPosition(Vec2(80 * j - 1250, 1390 - 80 * i));
				addChild(st2, 1);
			}
			if (map[i][j] == 22){
				st3 = Star::create();
				st3->getPhysicsBody()->setTag(122);
				st3->setPosition(Vec2(80 * j - 1250, 1390 - 80 * i));
				addChild(st3, 1);
			}
			if (map[i][j] == 23){
				st4 = Star::create();
				st4->getPhysicsBody()->setTag(123);
				st4->setPosition(Vec2(80 * j - 1250, 1390 - 80 * i));
				addChild(st4, 1);
			}
			if (map[i][j] == 24){
				st5 = Star::create();
				st5->getPhysicsBody()->setTag(124);
				st5->setPosition(Vec2(80 * j - 1250, 1390 - 80 * i));
				addChild(st5, 1);
			}
		}
	}
	//记分板
	score = Label::create();
	score->setString(to_string(star) + " / 5");
	score->setSystemFontSize(40);
	score->setColor(Color3B::BLACK);
	addChild(score, 2);
	//人物头像
	head = Sprite::create("character.png");
	addChild(head, 2);
	//星星
	_star = Sprite::create("star1.png");

	addChild(_star, 2);

	m_preal = ProgressTimer::create(Sprite::create("blood.png"));
	m_preal->setType(ProgressTimer::Type::BAR);
	m_preal->setMidpoint(Point(0, 0.5));
	m_preal->setBarChangeRate(Point(1.0, 0));
	//m_preal->setPosition(HeroHp->getContentSize() );
	m_preal->setPercentage(100);
	addChild(m_preal, 2);

}

void GameStart::initCloud(){

	cloud1 = Sprite::create("cloud2.png");
	cloud1->setPosition(540, 360);
	addChild(cloud1, 0);

	cloud2 = Sprite::create("cloud2.png");
	cloud2->setPosition(cloud1->getContentSize().width + 540, 360);
	addChild(cloud2, 0);
}

//cloud move
void GameStart::update(float dt){
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//镜头随人物移动
	this->runAction(Follow::create(hero));
	//label随镜头移动
	score->runAction(Place::create(Vec2(hero->getPositionX() - visibleSize.width / 2 + 280, hero->getPositionY() + visibleSize.height / 2 - 70)));
	//头像随镜头移动
	head->runAction(Place::create(Vec2(hero->getPositionX() - visibleSize.width / 2 + 70, hero->getPositionY() + visibleSize.height / 2 - 70)));
	//星星随镜头移动
	_star->runAction(Place::create(Vec2(hero->getPositionX() - visibleSize.width / 2 + 180, hero->getPositionY() + visibleSize.height / 2 - 70)));
	//HP的移动
	m_preal->runAction(Place::create(Vec2(hero->getPositionX() - visibleSize.width / 2 + 110, hero->getPositionY() + visibleSize.height / 2 - 140)));

	//monster的移动
	if (monster != NULL){
		if (mondire==0){
			monster->runAction(Place::create(Vec2(monsterPoint.x + 2, monsterPoint.y)));
			monsterPoint.x = monster->getPositionX();
			if (monster->getPositionX() > monspoint.x + 150)
				mondire = 1;
		}
		if (mondire == 1){
			monster->runAction(Place::create(Vec2(monsterPoint.x - 2, monsterPoint.y)));
			monsterPoint.x = monster->getPositionX();
			if (monster->getPositionX() < monspoint.x - 150)
				mondire = 0;
		}
	}



	//add cloud
	int posX1 = cloud1->getPositionX();
	int posX2 = cloud2->getPositionX();

	posX1 -= 2;
	posX2 -= 2;


	auto mapSize = cloud1->getContentSize();

	if (posX1 < -mapSize.width / 2){
		posX1 = mapSize.width + mapSize.width / 2;
		posX2 = mapSize.width / 2;
	}
	if (posX2 < -mapSize.width / 2){
		posX2 = mapSize.width + mapSize.width / 2;
		posX1 = mapSize.width / 2;
	}

	cloud1->setPositionX(posX1);
	cloud2->setPositionX(posX2);

	if (delay_action_open){
		//则开启一个一次的定时器  
		this->scheduleOnce(schedule_selector(GameStart::delay_action), 0.5f);
		delay_action_open = false;
	}
	if (monster){

		if (Rect(hero->getPositionX(), hero->getPositionY()-200, 200, 400).containsPoint(monster->getPosition())) {

			if (blood > 4){
				monster->statenum = 3;
			}
			else{
				monster->statenum = 2;
			}
		}
		else{
			monster->statenum = 1;
		}
	}



}

void GameStart::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{

	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		log("up");
		hero->jumpUp();

	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		hero->getPhysicsBody()->setVelocity(Vec2(-400, 0));
		hero->setLeft();
		hero->run();
		log("left");

	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		hero->getPhysicsBody()->setVelocity(Vec2(400, 0));
		hero->setRight();
		hero->run();
		log("right");
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_CTRL)
	{
		hero->attack();
		auto missile = Missile::create();
		if (hero->getDirection() == 1){
			missile->setPosition(Vec2(hero->getPositionX() - 50, hero->getPositionY()));
			missile->left();
		}
		else{
			missile->setPosition(Vec2(hero->getPositionX() + 50, hero->getPositionY()));
			missile->right();
		}

		addChild(missile);
		log("attack");

	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_BACK)
	{
		//得到窗口的大小  
		Size visibleSize = Director::getInstance()->getVisibleSize();
		RenderTexture *renderTexture = RenderTexture::create(visibleSize.width, visibleSize.height);

		//遍历当前类的所有子节点信息，画入renderTexture中。  
		//这里类似截图。  
		renderTexture->begin();
		this->getParent()->visit();
		renderTexture->end();

		//将游戏界面暂停，压入场景堆栈。并切换到GamePause界面 
		Director::getInstance()->pushScene(PauseScene::createScene(renderTexture));
		log("choice");
	}

}

void GameStart::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event){

	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		hero->getPhysicsBody()->setVelocity(Vec2(0, 0));
		hero->setLeft();
		log("left");
		hero->stand();

	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		hero->getPhysicsBody()->setVelocity(Vec2(0, 0));
		hero->setRight();
		log("right");
		hero->stand();

	}
}

void GameStart::addListener(){

	auto listener = EventListenerPhysicsContact::create();
	listener->onContactBegin = [=](PhysicsContact & contact){

		auto TagA = contact.getShapeA()->getBody()->getTag();
		auto TagB = contact.getShapeB()->getBody()->getTag();

		//Hero与Block遇到
		if (TagA + TagB == 108){
			log("die!");
			
			if (blood > 0){
				blood--;
				hero->heart();
				m_preal->setPercentage(blood * 20);
			}
			if (blood == 0){

				hero->die();
				delay_action_open = true;
				
			}
		}

		if (TagA + TagB == 106){
			log("Spring");
			hero->getPhysicsBody()->setVelocity(Vec2(0, 1200));
		}

		if (TagA + TagB == 114){
			log("deliver1");
			hero->runAction(Place::create(Vec2(de->getPosition().x - 90, de->getPosition().y)));
		}

		if (TagA + TagB == 116){
			log("deliver2");
			hero->runAction(Place::create(Vec2(ds->getPosition().x + 90, ds->getPosition().y)));
		}

		if (TagA + TagB == 118){
			log("deliver3");
			hero->runAction(Place::create(Vec2(dn->getPosition().x , dn->getPosition().y - 90)));
		}

		if (TagA + TagB == 120){
			log("deliver4");
			hero->runAction(Place::create(Vec2(det->getPosition().x - 90, det->getPosition().y )));
		}
		if (TagA + TagB == 122){
			star++;
			st1->removeFromParent();
			score->cleanup();
			score->setString(to_string(star) + " / 5");
		}
		if (TagA + TagB == 123){
			star++;
			st2->removeFromParent();
			score->cleanup();
			score->setString(to_string(star) + " / 5");
		}
		if (TagA + TagB == 124){
			star++;
			st3->removeFromParent();
			score->cleanup();
			score->setString(to_string(star) + " / 5");
		}
		if (TagA + TagB == 125){
			star++;
			st4->removeFromParent();
			score->cleanup();
			score->setString(to_string(star) + " / 5");
		}
		if (TagA + TagB == 126){
			star++;
			st5->removeFromParent();
			score->cleanup();
			score->setString(to_string(star) + " / 5");
		}
		if (TagA + TagB == 128){
			if (star == 5){
				level++;
				score->cleanup();
				star = 0;
				if (level == 4){
					Director::getInstance()->replaceScene(GameEnd::createScene());
				}
				else{
					auto start = GameStart::createScene(level);
					Director::getInstance()->purgeCachedData();
					Director::getInstance()->replaceScene(TransitionFadeBL::create(3.0f, start));
				}
				
			}
		}
		if (TagA + TagB == 130){
			if (blood > 0){
				blood--;
				hero->heart();
				log("die!");
				m_preal->setPercentage(blood * 20);
			}
			if (blood == 0){
				hero->die();
				delay_action_open = true;
			}
		}

		if (TagA + TagB == 153 ){
			removeChild(getChildByTag(50));
			log("zzzzzzzzzzzzzzzzzz");
		}

		if (TagA + TagB == 179){
			monster = NULL;
			monblood--;
			if (monblood == 0){
				removeChild(getChildByTag(127));
			}
			removeChild(getChildByTag(50));
			
			log("yyyyyyyyyyyyyyyy");
		}

		return true;
	};

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}
void GameStart::delay_action(float delta){

	Director::getInstance()->replaceScene(GameOver::createScene());
}