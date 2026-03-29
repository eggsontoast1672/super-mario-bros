#include <concepts>
#include <cstddef>
#include <cstdint>
#include <print>
#include <span>
#include <type_traits>
#include <vector>

// Magic number SMBCMAP
// 0x534D42434D4150
//
// u32 - number of tiles in the file
//
// {
// |   u16 - x position of the tile
// |   u16 - y position of the tile
// |   u16 - type of tile
// }

template <typename T>
concept Numeric = std::is_arithmetic_v<T>;

template <Numeric T>
struct Vector2 {
    T x;
    T y;

    Vector2<T> operator+(Vector2<T> rhs) const
    {
        return {x + rhs.x, y + rhs.y};
    }

    Vector2<T> operator*(T rhs) const
    {
        return {x * rhs, y * rhs};
    }
};

enum class TileType : std::uint16_t {};

struct Tile {
    Vector2<std::uint16_t> position;
    TileType type;
};

// For now, we will only store the tile data. Levels cannot yet have entities, and the player will
// spawn in a fixed position. A level will be a vector of tiles, which are each made up of a
// position (two integers) and a type.

struct Level {
    std::vector<Tile> tiles;
};

Level parse_level_from_bytes(std::span<const std::byte> bytes)
{
    // Hwllo
}

int main()
{
    std::println("Hello, world!");
}
