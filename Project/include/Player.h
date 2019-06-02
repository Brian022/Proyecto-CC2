#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Animation.h"


class Player : public Character
{
    public:
        Player(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpHeight);
        void Update(float deltaTime);
};

#endif // PLAYER_H
