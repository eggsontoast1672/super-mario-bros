#include "smbc-core/level.hpp"

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

#include <SDL3/SDL_render.h>

#include "smbc-core/assets.hpp"

namespace smbc::core
{

Level parse_level_from_bytes(std::istream &bytes)
{
    char header[7];
    bytes.read(header, sizeof header);
    if (std::strncmp(header, "SMBCMAP", 7) != 0) {
        throw std::runtime_error("map header missing");
    }

    std::uint32_t num_tiles = 0;

    // This reinterpret cast is surely safe. The alignment works out since we are casting a pointer
    // of higher alignment to one of lower alignment. It the pointer is aligned to a 4 byte
    // boundary, it will obviously be aligned to a 1 byte boundary as well.
    bytes.read(reinterpret_cast<char *>(&num_tiles), sizeof num_tiles);

    std::vector<Tile> tiles(num_tiles);

    for (std::uint32_t i = 0; i < num_tiles; i++) {
        Tile &tile = tiles[i];

        bytes.read(reinterpret_cast<char *>(&tile.position_x), sizeof tile.position_x);
        bytes.read(reinterpret_cast<char *>(&tile.position_y), sizeof tile.position_y);
        bytes.read(reinterpret_cast<char *>(&tile.type), sizeof tile.type);

        if (tile.type >= TileType::Count) {
            throw std::runtime_error("tile type index out of range");
        }
    }

    return {tiles};
}

void dump_level(const Level &level, std::ostream &stream)
{
    stream << "SMBCMAP";
    stream << static_cast<std::uint32_t>(level.tiles.size());

    for (const Tile &tile : level.tiles) {
        stream << tile.position_x;
        stream << tile.position_y;
        stream << std::to_underlying(tile.type);
    }
}

void render_level(const Level &level, SDL_Renderer *renderer)
{
    constexpr float block_size = 32.0f;

    SDL_FRect source{.w = 16.0f, .h = 16.0f};
    
    // FIXME: Change these values back to 1.0f
    SDL_FRect dest{.w = block_size, .h = block_size};

    for (const Tile &tile : level.tiles) {
        const std::div_t indices = std::div(std::to_underlying(tile.type), 16);

        source.x = indices.rem * 16.0f;
        source.y = indices.quot * 16.0f;

        // FIXME: The origin of the world is (0, 0). My intent is to have that position in the
        // bottom left corner of the world. However, SDL3 renders stuff with (0, 0) at the top left
        // corner by default, so we will need to know the height of the game world to perform the
        // conversion.
        dest.x = tile.position_x * block_size;
        dest.y = tile.position_y * block_size;

        SDL_RenderTexture(renderer, g_assets.atlas, &source, &dest);
    }
}

} // namespace smbc::core
