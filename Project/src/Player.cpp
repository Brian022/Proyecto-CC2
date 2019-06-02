#include "Player.h"
#include <iostream>
Player::Player(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpHeight):
    Character(texture, imageCount, switchTime, speed, jumpHeight)
{
    cout<<"constructor de player"<<endl;
    this->speed = speed;
    this->jumpHeight = jumpHeight;
    row = 0;
    faceRight= true;
    body.setSize(Vector2f(50.0f, 100.0f));
    body.setPosition(600.0f, 200.0f);
    body.setTexture(texture);
}

void Player::Update(float deltaTime)
{
    velocity.x = 0.0f;

    if(Keyboard::isKeyPressed(Keyboard::A))
        velocity.x -= speed;
    if(Keyboard::isKeyPressed(Keyboard::D))
        velocity.x += speed;
    if(Keyboard::isKeyPressed(Keyboard::Q)&& jump)
    {
        jump = false;

        velocity.y = -sqrt(2.0f* 981.0f * jumpHeight);
    }

    velocity.y += 981.0f * deltaTime;

    if(velocity.x == 0.0f)
    {
        row = 0;
    }
    else
    {
        row = 3;
        if(velocity.x > 0.0f)
            faceRight = true;
        else
            faceRight = false;
    }

    animation.Update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(velocity * deltaTime);
}


