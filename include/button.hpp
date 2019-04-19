#pragma once

#include <functional>
#include "common.hpp"
#include "resources.hpp"

class Button : public sf::Drawable
{
public:
    Button(const std::string& text, float height, std::function<void()> callback);
    void processEvent(const sf::Event& event);
    void update(sf::Time dt);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::Sprite mSprite;
    sf::Text mText;
    sf::Time mTimer;
    bool mHover;
    std::function<void()> mCallback;
};