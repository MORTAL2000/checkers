#pragma once

#include <map>
#include <stack>
#include "game.hpp"
#include "options.hpp"
#include "state.hpp"
#include "title.hpp"

class StateStack
{
public:
    StateStack(const StateStack&) = delete;
    StateStack& operator=(const StateStack&) = delete;
    static StateStack& get();

    void push(State::Type type, void* data = nullptr);
    void pop(void* data = nullptr);

    void run();
    void closeWindow();
    sf::Time globalTimer();
private:
    StateStack();

    void processEvents();
    void update(sf::Time dt);
    void render();
    void transition();

    sf::RenderWindow mWindow;
    sf::RenderTexture mTexture;
    std::map<State::Type, State::Ptr> mStates;
    std::stack<State*> mStack;
    sf::Sprite mBackground;
    sf::Sprite mFrame;
    sf::Time mGlobalTimer;
    sf::Sprite mCursor;

    bool mTransition;
    sf::Time mTransitionTimer;
};