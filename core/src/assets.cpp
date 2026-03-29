#include "smbc-core/assets.hpp"

#include <print>

#include <SDL3/SDL_render.h>
#include <SDL3_image/SDL_image.h>

namespace smbc::core
{

void AssetManager::load_all(SDL_Renderer *renderer)
{
    atlas = load_texture(ASSET_PATH "atlas.png", renderer);
}

TextureHandle load_texture(const char *path, SDL_Renderer *renderer)
{
    SDL_Texture *const texture = IMG_LoadTexture(renderer, path);

    if (texture == nullptr)
    {
        // TODO: It would be cool to have this function return some statically generated texture
        // (something like what Valve games do with the black and pink checkerboard) if loading
        // fails. For now we will just return a null pointer and watch hilarity ensue. Of course,
        // we can still print the error that occurred.
        std::println(stderr, "Failed to load texture \"{}\": {}", path, SDL_GetError());
    }

    return texture;
}

} // namespace smbc::core
