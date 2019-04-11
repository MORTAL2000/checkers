#include "state_stack.hpp"

StateStack::StateStack()
: mWindow{ sf::VideoMode{unsigned(WindowWidth), unsigned(WindowHeight)}, "Checkers", sf::Style::Close }
, mStates{}
, mStack{}
, mBackground{ Resources::get().texture("Background") }
, mShadow{ sf::Sprite{Resources::get().texture("Shadow")}, sf::Sprite{Resources::get().texture("Shadow")} }
, mCursor{ Resources::get().texture("Cursor") }
{
    sf::Image icon{};
    if (!icon.loadFromFile("resources/Icon.png"))
        throw std::runtime_error("Unable to load Icon from 'resources/Icon.png' because loadFromFile method failed");

    mWindow.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    mStates[State::Type::Game] = State::Ptr(new Game{});
    mStates[State::Type::Options] = State::Ptr(new Options{});
    mStates[State::Type::Title] = State::Ptr(new Title{});

    mShadow[0].move(-WindowWidth, 0.f);

    mWindow.setMouseCursorVisible(false);
    mCursor.setOrigin(5.f, 0.f);
}

void StateStack::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
        mStack.top()->processEvent(event);
}

void StateStack::update(sf::Time dt)
{
    for (size_t i = 0; i <= 1; i++)
    {
        if (mShadow[i].getPosition().x >= WindowWidth) mShadow[i].move(-2.f * WindowWidth, 0.f);
        mShadow[i].move(30.f * dt.asSeconds(), 0.f);
    }

    mCursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(mWindow)));

    mStack.top()->update(dt);

    // SoundPlayer::get().updateMusic();
}

void StateStack::render()
{
    mWindow.clear();

    mWindow.draw(mBackground);
    mWindow.draw(mShadow[0]);
    mWindow.draw(mShadow[1]);
    mStack.top()->render(mWindow);
    mWindow.draw(mCursor);

    mWindow.display();
}

StateStack& StateStack::get()
{
    static StateStack instance{};
    return instance;
}

void StateStack::push(State::Type type)
{
    mStack.push(mStates[type].get());
    mStack.top()->activation();
}

void StateStack::pop()
{
    if (mStack.empty())
        throw std::runtime_error("Unable to pop an empty stack");

    mStack.top()->deactivation();
    mStack.pop();
}

void StateStack::run()
{
    while (!mStack.empty() && mWindow.isOpen())
    {
        sf::Clock clock{};

        processEvents();
        update(TimePerFrame);
        render();

        sf::sleep(TimePerFrame - clock.restart());
    }
}

void StateStack::closeWindow()
{
    mWindow.close();
}