#include "title.hpp"
#include "state_stack.hpp"

Title::Title()
{
}

void Title::activation()
{
}

void Title::deactivation()
{
}

void Title::processEvent(const sf::Event& event)
{
    switch (event.type)
    {
        case sf::Event::Closed:
        {
            StateStack::get().closeWindow();
        }
        break;

        case sf::Event::KeyPressed:
        {
            if (event.key.code == sf::Keyboard::Enter)
                StateStack::get().push(State::Type::Game);
        }
        break;
    }
}

void Title::update(sf::Time dt)
{
}

void Title::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}
