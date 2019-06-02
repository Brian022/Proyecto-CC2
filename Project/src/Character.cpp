#include "Character.h"
#include <iostream>
Character::Character(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpHeight):
    animation(texture, imageCount, switchTime)
{

}

void Character::Update(float deltaTime)
{

}
void Character::OnCollision(Vector2f direction)
{
    if(direction.x < 0.0f){velocity.x = 0.0f;}
    if(direction.x > 0.0f){velocity.x = 0.0f;}
    if(direction.y < 0.0f){velocity.y = 0.0f; jump = true; }
    if(direction.y > 0.0f){velocity.y = 0.0f;}
}

void Character::Draw(RenderWindow& window)
{
    window.draw(body);
}
