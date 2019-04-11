#include "resources.hpp"

Resources::Resources()
: mFonts{}
, mSoundBuffers{}
, mTextures{}
{
    loadFont("Candara", "resources/Candara.ttf");

    loadSoundBuffer("Fight", "resources/Fight.wav");
    loadSoundBuffer("Impossible", "resources/Impossible.wav");
    loadSoundBuffer("Move", "resources/Move.wav");
    loadSoundBuffer("Win", "resources/Win.wav");

    loadTexture("Background", "resources/Background.png");
    loadTexture("Board", "resources/Board.png");
    loadTexture("Cursor", "resources/Cursor.png");
    loadTexture("DarkKing", "resources/DarkKing.png");
    loadTexture("DarkKingSelected", "resources/DarkKingSelected.png");
    loadTexture("DarkPawn", "resources/DarkPawn.png");
    loadTexture("DarkPawnSelected", "resources/DarkPawnSelected.png");
    loadTexture("LightKing", "resources/LightKing.png");
    loadTexture("LightKingSelected", "resources/LightKingSelected.png");
    loadTexture("LightPawn", "resources/LightPawn.png");
    loadTexture("LightPawnSelected", "resources/LightPawnSelected.png");
    loadTexture("Options", "resources/Options.png");
    loadTexture("Shadow", "resources/Shadow.png");
}

Resources& Resources::get()
{
    static Resources instance{};
    return instance;
}

sf::Font& Resources::font(const std::string& name)
{
    return mFonts.at(name);
}

sf::SoundBuffer& Resources::soundBuffer(const std::string& name)
{
    return mSoundBuffers.at(name);
}

sf::Texture& Resources::texture(const std::string& name)
{
    return mTextures.at(name);
}

void Resources::loadFont(const std::string & key, const std::string & filename)
{
    if (mFonts.find(key) != mFonts.end())
        throw std::runtime_error("Unable to load Font from '" + filename + "' because key '" + key + "' already exists");

    mFonts[key] = sf::Font{};
    if (!mFonts[key].loadFromFile(filename))
        throw std::runtime_error("Unable to load Font from '" + filename + "' because loadFromFile method failed");
}

void Resources::loadSoundBuffer(const std::string& key, const std::string& filename)
{
    if(mSoundBuffers.find(key) != mSoundBuffers.end())
        throw std::runtime_error("Unable to load SoundBuffer from '" + filename + "' because key '" + key + "' already exists");

    mSoundBuffers[key] = sf::SoundBuffer{};
    if (!mSoundBuffers[key].loadFromFile(filename))
        throw std::runtime_error("Unable to load SoundBuffer from '" + filename + "' because loadFromFile method failed");
}

void Resources::loadTexture(const std::string& key, const std::string& filename)
{
    if (mTextures.find(key) != mTextures.end())
        throw std::runtime_error("Unable to load Texture from '" + filename + "' because key '" + key + "' already exists");

    mTextures[key] = sf::Texture{};
    if (!mTextures[key].loadFromFile(filename))
        throw std::runtime_error("Unable to load Texture from '" + filename + "' because loadFromFile method failed");
}