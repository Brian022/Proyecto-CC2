#include <iostream>
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Player.h"
#include "Player1.h"
#include "Platform.h"
using namespace sf;
using namespace std;

static const float viewHeight = 600;
void ResizeView(const RenderWindow& window, View& view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(viewHeight * aspectRatio, viewHeight);
}

int main()
{
    RenderWindow window(VideoMode(1200, 600), "SFML works!", Style::Resize | Style::Close);
    View view(Vector2f(0.0f,0.0f), Vector2f(1200, 600));
    view.setViewport(sf::FloatRect(0.f, 0.f, 0.5f, 1.f));

    View view1(Vector2f(0.0f,0.f), Vector2f(1200, 600));
    view1.setViewport(sf::FloatRect(0.5f, 0.f, 0.5f, 1.f));
    //background sprite
    RectangleShape background(Vector2f(1200, 600));
    background.setTextureRect(sf::IntRect(0, 0, 1200, 600));
    Texture backgroundtexture;
    backgroundtexture.loadFromFile("../cityArt.jpg");
    background.setTexture(&backgroundtexture);
    //TEXTURA DEL PRIMER JUGADOR
    Texture playerTexture;
    playerTexture.loadFromFile("../Boy1.png");
    //TEXTURA DE OTRO JUGADOR
    Texture player1Texture;
    player1Texture.loadFromFile("../Girl1.png");
    Texture ground;
    ground.loadFromFile("../ground.png");

    Player player(&playerTexture, Vector2u(4,4), 0.3, 100.0f, 50.0f);
    Player1 player1(&player1Texture, Vector2u(8,4), 0.3f, 100.0f, 50.0f);

    Platform platform1(&ground, Vector2f(1000.0f, 200.0f), Vector2f(500.0f,400.0f));





    float deltaTime = 0.0f;
    Clock clock;


    while (window.isOpen() )
    {
        deltaTime = clock.restart().asSeconds();
        if(deltaTime > 1.0f/20.0f)
            deltaTime = 1.0f/20.0f;

        Event evnt;
        while (window.pollEvent(evnt))
        {
            switch(evnt.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::Resized:
                ResizeView(window, view);
                ResizeView(window, view1);
                break;
            }
        }

        player.Update(deltaTime);
        player1.Update(deltaTime);

        Vector2f direction;

        platform1.GetCollider().CheckCollision(player.GetCollider(), direction, 0.0f);
        platform1.GetCollider().CheckCollision(player1.GetCollider(), direction, 0.0f);


        window.clear();

        window.setView(view1);
        view.setCenter(player.GetPosition());
        window.draw(background);
        player.Draw(window);
        player1.Draw(window);
        platform1.Draw(window);


        window.setView(view);
        view1.setCenter(player1.GetPosition());
        window.draw(background);
        player.Draw(window);
        player1.Draw(window);
        platform1.Draw(window);




        window.display();
    }

    return 0;
}
