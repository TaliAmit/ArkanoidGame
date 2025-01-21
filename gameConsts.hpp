#ifndef ARKANOID_GAME_CONSTS_HPP
#define ARKANOID_GAME_CONSTS_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <array>



//--------------OBJECTS SIZES-------------------------------

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const int MIDDLE_WIDTH = WINDOW_WIDTH / 2;
const int MIDDLE_HEIGHT = WINDOW_HEIGHT / 2;

const float BOX_WIDTH = (float)WINDOW_WIDTH;   
const float BOX_HEIGHT = 11.0/12 * WINDOW_HEIGHT; 

const float BRICK_X_GAP = 4 *(6 / 5.0);
const float BRICK_Y_GAP = 5.0;

const float BRICK_WIDTH = (float)BOX_WIDTH / 5 - BRICK_X_GAP;   
const float BRICK_HEIGHT =  0.2 * BRICK_WIDTH;  
  

const float VAUS_WIDTH = (float)BOX_WIDTH / 5;
const float VAUS_HEIGHT = 0.2 * VAUS_WIDTH;

const float BALL_RADUIS = WINDOW_WIDTH / 80.0; //10.0;

//--------------OBJECTS AMOUNT----------------------------

const size_t NUM_OF_BRICKS = 15;
#define BRICKS_ROWS 3
#define BRICKS_COLUMNS 5

const size_t PLAYER_LIVES = 3;

const size_t HIT_BRICK_SCORE = 40;

const size_t TOP_SCORES_AMOUNT = 10;

const size_t SLEEP_WAIT_AMOUNT = 3;

const size_t PLAYER_NAME_LETTERS = 5;

//----------------FILES-------------------------

const std::string TOP_SCORES_FILE_NAME = "topScores.dat";


//------------OBJECTS MOVEMENT----------------------

const float BALL_LOWER_BOUND_ANGLE = 30.0;
const float BALL_UPPER_BOUND_ANGLE = 120.0;
const float BALL_SPEED = 5.0;

const sf::Vector2f BALL_STEP{2.5, -2.5};
const sf::Vector2f vaus_default_movement{20.0, 0.0};




//--------------------DESIGN--------------------------

//const float outline_thickness = -2.0;
const std::array<sf::Color, 3> lines_colors = {sf::Color(0,75,58), sf::Color(0,45,34), sf::Color(0,31,23)};
const sf::Color outline_color = sf::Color::Transparent;


//------------------BRICKS_SCORE----------------------------------------------

const std::map<std::string, size_t> bricks_scores
{
    {"simple", 40},
    {"strong", 500},
    {"explode", 50}
};

#endif // ARKANOID_GAME_CONSTS_HPP
