#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

using namespace sf;
using namespace std;

void Demo()
{
    // Crée une fenêtre avec une taille et un titre
    // Fenetre de rendu
    // Plusieur mode de rendu
    RenderWindow _window(VideoMode({ 200, 200 }), "SFML works!");

    CircleShape _shape(100.f);
    _shape.setFillColor(Color::Green);

    while (_window.isOpen())
    {
        while (const std::optional _event = _window.pollEvent())
        {
            if (_event->is<Event::Closed>())
                _window.close();
        }

        _window.clear();
        _window.draw(_shape);
        _window.display();
    }

}

void UpdateTileIndex(unsigned int& _tileIndex, const Keyboard::Key& _currentKey, const unsigned int _movementSpeed)
{
    static Keyboard::Key _previousKey = Keyboard::Key::Unknown;
    static unsigned int _time = 0;

    if (_currentKey != _previousKey)
    {
        _tileIndex = 0;
        _previousKey = _currentKey;
    }
    else
    {
        int _speedValue = 10 - _movementSpeed + 1;
        int _module = (_speedValue < 1 ? 1 : 10 - _movementSpeed + 1);
        if (++_time % _module == 0)
        {
            ++_tileIndex %= 4;
        }
    }
}

int main()
{

    //Demo();

    return EXIT_SUCCESS;
}