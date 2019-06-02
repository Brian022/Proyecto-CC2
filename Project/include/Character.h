#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

class Character
{
    public:
        Character(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpHeight);
        virtual void Update(float deltaTime);
        void OnCollision(Vector2f direction);
        void Draw(RenderWindow& window);

        Vector2f GetPosition() {return body.getPosition();}
        Collider GetCollider() {return Collider(body);}

    public:
        Animation animation;
        float speed;
        RectangleShape body;
        unsigned int row;
        bool faceRight;

        Vector2f velocity;
        bool jump;
        float jumpHeight;

};

#endif // CHARACTER_H
