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

    void push(State::Type type);
    void pop();
    void run();
    void closeWindow();
private:
    StateStack();
    void updateCursor();
    
    sf::RenderWindow mWindow;
    State::Type mActual;
    std::map<State::Type, State::Ptr> mStates;
    std::stack<State::Type> mStack;
    sf::Sprite mCursor;
};