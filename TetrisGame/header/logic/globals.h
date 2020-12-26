#ifndef GLOBALS_H
#define GLOBALS_H


/*This file includes the constants for the window grid and block size used in this game*/
#define ONE_SEC_TO_MILLI 1000

#define GAME_SPEED_1_HZ  1000
#define GAME_SPEED_2_HZ  500
#define GAME_SPEED_4_HZ  250
#define GAME_SPEED_8_HZ  125


#define DOWN_KEY         16777237
#define UP_KEY           16777235
#define LEFT_KEY         16777234
#define RIGHT_KEY        16777236


//openGL window measurements
static int window_length = 600;
static int window_width  = 400;

//window grid measurements
static float windowGridUnitX =  static_cast<float> (1.0f/8.0f);
static float windowGridUnitY =  static_cast<float> (1.0f/12.0f);


//window borders
static float xMaxCoordinate =  1.0f;
static float xMinCoordinate = -1.0f;
static float yMaxCoordinate =  1.0f;
static float yMinCoordinate = -1.0f;

//movement step
static float yMovementStepSize = 2.0f * windowGridUnitY;
static float xMovementStepSize = 2.0f * windowGridUnitX;

static float unit_window_length = 1.0f/ float(window_length) ;
static float unit_window_width = 1.0f / float(window_width) ;

static float block_width = 50 * unit_window_width;
static float block_length = 50 * unit_window_length;


#endif // GLOBALS_H
