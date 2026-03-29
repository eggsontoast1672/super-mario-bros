# Super Mario Bros Clone

A very long time ago (circa 2023), I thought it would be a fun idea to recreate
the original Super Mario Bros game for the NES as faithfully as I possibly
could. After a bit of working, I deemed the project to be too difficult.
However, I have returned full of vigor, ready to reattempt the project!

While I originally chose C with SDL2 as my tech stack, times have changed. I am
willing to deal with the complexity of C++ in exchange for the flexibility
provided by the standard library with templated collections. It saves time, and
C++ is the industry standard for video games after all. Since I began the
project, SDL3 has released, which I naturally switched to. Armed with these new
tools I am ready to continue.

The goal of this project is quite simple. That is, I would like to recreate a
subset of the game *Super Mario Bros.* (1985) as faithfully as I possibly can.
Than means hand-copying all of the assets; sprites, music, sound effects, and
all. I will likely limit my scope to the first level, since it is the most
ubiquitous. If I am feeling ready for more after that, I will go on to do more.

## Compiling

I am still working on a Windows build, so there are no instructions for that
platform yet. There are also no explicit instructions for MacOS and BSD
variants, but I am hoping that those will be similar enough to the Linux build.
The build prerequisites are the following:

* A C++ compiler with C++23 support
* A build tool such as Make or Ninja
* CMake
* SDL3 development files
* SDL3 Image development files

I trust that the reader can figure out how to acquire those programs. Once they
are installed, simply generate the cache and execute the build with the
following commands:

```bash
cmake -B build
cmake --build build
```

The level editor program will be placed under `build/editor/smbc-editor` and
the game itself under `build/game/smbc`. Everything is majorly work-in-progress
right now, but I hope you enjoy playing around with things anyhow!

## To Do

- [ ] Draw more tiles
- [ ] Orchestrate the music
- [ ] Write the level editor
