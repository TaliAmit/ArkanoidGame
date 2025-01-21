#include "collision.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "strongBrick.hpp"
#include "simpleBrick.hpp"
#include "explodeBrick.hpp"

#include <iostream>
#include <algorithm>



float Collision::clamp(float a_var, float a_min_var, float a_max_var)
{
    return (a_var < a_min_var) ? a_min_var : ((a_var > a_max_var) ? a_max_var : a_var);
}


float Collision::distance(float a_x1, float a_y1, float a_x2, float a_y2)
{
    float diff_x = a_x2 - a_x1;
    float diff_y = a_y2 - a_y1;
    return sqrt(pow(diff_x,2) + pow(diff_y,2));
}





bool Collision::ball_box_walls_collision(Ball &a_ball, Box &a_box)
{
    float ball_radius = a_ball.radius();
    sf::Vector2f position = a_ball.position();
    sf::FloatRect rect_bounds = a_box.bounds();
    
    if(position.x >= rect_bounds.left + rect_bounds.width - ball_radius
    || position.x <= rect_bounds.left + ball_radius)
    {
        a_ball.set_step_direction(sf::Vector2f(-1, 1));
        return true;
    }
    else if(position.y <= rect_bounds.top + ball_radius)
    {
        a_ball.set_step_direction(sf::Vector2f(1, -1));
        return true;
    }

    return false;
}




bool Collision::ball_box_floor_collision(Ball &a_ball, Box &a_box)
{
    float ball_radius = a_ball.radius();
    sf::Vector2f position = a_ball.position();
    sf::FloatRect rect_bounds = a_box.bounds();

    return position.y >= rect_bounds.top + rect_bounds.height - ball_radius;
}




bool Collision::vaus_box_left_collision(Vaus &a_vaus, Box &a_box, float a_x_step)
{
    return a_vaus.position().x + a_x_step <= a_box.bounds().left;
}




bool Collision::vaus_box_right_collision(Vaus &a_vaus, Box &a_box, float a_x_step)
{
    float next_vaus_pos = a_vaus.position().x + a_x_step;
    float boundery = a_box.bounds().left + a_box.bounds().width - a_vaus.bounds().width;

    return next_vaus_pos >= boundery;
}





sf::Vector2f Collision::final_collision(Ball &a_ball, sf::FloatRect &a_rect_bounds)
{
    sf::Vector2f circle_center = a_ball.circle_center();
    float circle_radius = a_ball.radius();

    float closest_x = clamp(circle_center.x, a_rect_bounds.left, a_rect_bounds.left + a_rect_bounds.width);
    float closest_y = clamp(circle_center.y, a_rect_bounds.top, a_rect_bounds.top + a_rect_bounds.height);

    float dist = distance(circle_center.x, circle_center.y, closest_x, closest_y);

    if(!(dist <= circle_radius))
    {
        return sf::Vector2f(1.0,1.0);
    }
    
    if( (closest_x == a_rect_bounds.left && closest_y == a_rect_bounds.top)
    || (closest_x == a_rect_bounds.left + a_rect_bounds.width && closest_y == a_rect_bounds.top)
    || (closest_x == a_rect_bounds.left + a_rect_bounds.width && closest_y == a_rect_bounds.top + a_rect_bounds.height)
    || (closest_x == a_rect_bounds.left && closest_y == a_rect_bounds.top))
    {
        return sf::Vector2f(-1.0, -1.0);
    }
    
    if(closest_x == circle_center.x)
    {
        return sf::Vector2f(1.0,-1.0);
    }

    if(closest_y == circle_center.y)
    {
        return sf::Vector2f(-1.0,1.0);
    } 

    return sf::Vector2f(1.0, -1.0);      
}

sf::Vector2f Collision::ball_brick_collision_new(Ball &a_ball, AbsBrick* a_brick)
{
    sf::FloatRect rect_bounds = a_brick->bounds();
    return final_collision(a_ball, rect_bounds);
}

sf::Vector2f Collision::ball_vaus_collision_new(Ball &a_ball, Vaus &a_vaus)
{
    sf::FloatRect rect_bounds = a_vaus.bounds();
    return final_collision(a_ball, rect_bounds);
}

