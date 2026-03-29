#pragma once

#include <cstdint>
#include <iosfwd>
#include <vector>

#include <SDL3/SDL_render.h>

namespace smbc::core
{

/// The type of a tile.
///
/// Every tile has a particular type which is used to determine which texture to render for it.
enum class TileType : std::uint16_t {
    Air,
    Ground,
    Bricks,
    Block,
    Count,
};

struct Tile {
    std::uint16_t position_x = 0;
    std::uint16_t position_y = 0;
    TileType type = TileType::Air;
};

struct Level {
    std::vector<Tile> tiles;
};

/// Parse level data from a binary stream.
Level parse_level_from_bytes(std::istream &bytes);

/// Dump level data to a binary stream.
void dump_level(const Level &level, std::ostream &stream);

/// Render a level to the screen.
void render_level(const Level &level, SDL_Renderer *renderer);

} // namespace smbc::core
