#include "Player1.h"
#include <iostream>
Player1::Player1(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpHeight):
    Character(texture, imageCount, switchTime, speed, jumpHeight)
{
    cout<<"constructor de player"<<endl;
    this->speed = speed;
    this->jumpHeight = jumpHeight;
    row = 0;
    faceRight= true;
    body.setSize(Vector2f(100.0f, 100.0f));
    body.setPosition(900.0f, 200.0f);
    body.setTexture(texture);
}

void Player1::Update(float deltaTime)
{
    velocity.x = 0.0f;

    if(Keyboard::isKeyPressed(Keyboard::Left))
        velocity.x -= speed;
    if(Keyboard::isKeyPressed(Keyboard::Right))
        velocity.x += speed;
    if(Keyboard::isKeyPressed(Keyboard::Space)&& jump)
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
        row = 2;
        if(velocity.x > 0.0f)
            faceRight = true;
        else
            faceRight = false;
    }

    animation.Update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(velocity * deltaTime);
}
