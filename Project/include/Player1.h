#ifndef PLAYER1_H
#define PLAYER1_H
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Animation.h"


class Player1 : public Character
{
    public:
        Player1(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpHeight);
        void Update(float deltaTime);
};

#endif // PLAYER1_H
