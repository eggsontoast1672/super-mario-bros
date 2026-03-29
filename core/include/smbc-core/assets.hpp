#pragma once

#include <SDL3/SDL_render.h>

namespace smbc::core
{

using TextureHandle = SDL_Texture *;

struct AssetManager {
    TextureHandle atlas;

    /// Load all managed assets.
    ///
    /// Before any assets in the struct can be used, this function must be called (obviously). For
    /// now, all of the assets in the game combined do not take up much space, so they will remain
    /// loaded for the entire duration of the app. Once the game ends, they will be automatically
    /// reclaimed by the system. Thus, there is no need for an `unload_all` method.
    void load_all(SDL_Renderer *renderer);
};

/// The engine's global asset manager.
///
/// You must load the assets using the `load_all` method before any of them can be used. There is
/// no good way to load them automatically without running into the static initialization stuff, so
/// this is required. I am not too worried about this being globally accessible, just don't be
/// stupid.
extern AssetManager g_assets;

TextureHandle load_texture(const char *path, SDL_Renderer *renderer);

} // namespace smbc::core
