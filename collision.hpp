#ifndef ARKANOID_COLLISION_HPP
#define ARKANOID_COLLISION_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <cmath>

#include "simpleBrick.hpp"
#include "explodeBrick.hpp"
#include "strongBrick.hpp"
#include "absBrick.hpp"
#include "ball.hpp"
#include "brick.hpp"
#include "vaus.hpp"
#include "box.hpp"

class Collision
{
public: 
    explicit Collision() = default;
    ~Collision() = default;

    // bool ball_brick_collision(Ball &a_ball, Brick &a_brick);
    // bool ball_vaus_collision(Ball &a_ball, Vaus &a_vaus);
    bool ball_box_walls_collision(Ball &a_ball, Box &a_box);
    bool ball_box_floor_collision(Ball &a_ball, Box &a_box);


    sf::Vector2f ball_brick_collision_new(Ball &a_ball, AbsBrick* a_brick);
    sf::Vector2f ball_vaus_collision_new(Ball &a_ball, Vaus &a_vaus);

    bool vaus_box_left_collision(Vaus &a_vaus, Box &a_box, float a_x_step);
    bool vaus_box_right_collision(Vaus &a_vaus, Box &a_box, float a_x_step);

    sf::Vector2f final_collision(Ball &a_ball, sf::FloatRect &a_rect_bounds);


private:
    sf::Vector2f calc_circle_center(const sf::CircleShape& a_circle);
    float clamp(float a_var, float a_min_var, float a_max_var);
    float distance(float a_x1, float a_y1, float a_x2, float a_y2);

    //void collision_rect_area(Ball &a_ball, sf::FloatRect &a_rect_bounds);
    //bool ball_rect_collision(Ball &a_ball, sf::FloatRect &a_rect_bounds);
    
};

#endif // ARKANOID_COLLISION_HPP