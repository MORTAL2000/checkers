#pragma once

#include "board.hpp"
#include "pawn.hpp"
#include "sound_player.hpp"
#include "state.hpp"

class Game : public State
{
public:
    Game();

    void handlePlayerAction(const sf::Vector2i& destination);
    void nextTurn();

    virtual void activation() override;
    virtual void processEvent(const sf::Event& event) override;
    virtual void update(sf::Time dt) override;
    virtual void render(sf::RenderWindow& window) const override;
private:
    sf::Sprite mBackground;
    Board mBoard;
    Pawn* mSelected;
    bool mLock;
    Color mActualPlayerColor;
    sf::Text mTurnText;
    bool mFinished;
    sf::Sprite mShadow[2];
};