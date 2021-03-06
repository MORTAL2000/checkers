#pragma once

#include <cassert>
#include <experimental/filesystem>
#include <random>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

namespace fs = std::experimental::filesystem;

const int BoardWidth = 8;
const int BoardHeight = 8;
const int WindowWidth = 640;
const int WindowHeight = 768;
const int TileSize = 64;
const int OffsetX = 1;
const int OffsetY = 3;

const sf::Time TimePerFrame = sf::seconds(1.f / 30.f);

const std::string FontsDirectory = "resources/Fonts";
const std::string ShadersDirectory = "resources/Shaders";
const std::string SoundsDirectory = "resources/Sounds";
const std::string TexturesDirectory = "resources/Textures";

const std::string MusicDirectory = "resources/Music";

enum class Color : int
{
    Light,
    Dark
};

enum class Message : int
{
    Training,
    EasyAI,
    NormalAI,
    HardAI,
};

bool isValidPosition(int x, int y);
bool isValidPosition(const sf::Vector2i& position);
void centerOrigin(sf::Text& text);
void centerOrigin(sf::Sprite& sprite);

static std::random_device device{};
static std::mt19937 engine{ device() };

size_t randomInt(size_t min, size_t max);

std::vector<std::pair<std::string, std::string>> getDirectoryEntries(const std::string& directoryPath, std::vector<std::string> extensions);