*This project has been created as part of the 42 curriculum by nbaudoin.*
<a id="top"></a>
# so_long, a very beautiful game

- [so\_long, a very beautiful game](#so_long-a-very-beautiful-game)
	- [Description](#description)
	- [Instructions](#instructions)
		- [Getting the project and compilation](#getting-the-project-and-compilation)
		- [Usage](#usage)
		- [Game rules](#game-rules)
		- [Map Rules](#map-rules)
	- [Resources](#resources)
		- [Use of AI](#use-of-ai)
	- [Credits](#credits)

## Description

so_long is a small 2D game developed using the MiniLibX, a graphical library provided by 42.

I chose to do a top-down view to introduce easily concepts of this project. You will play a chicken that collect wheat, because i didn't find seeds i wanted, then, the chicken can escape by a hole.

The goal of the game is simple:

- Control the player 🐔
- Collect all collectibles
- Reach the exit to win

This project introduces:

- Parsing error handling
- Window management
- Event handling
- Basic game loop
- Texture rendering
- Path validation using algorithms (flood fill)
- Memory handling

## Instructions

### Getting the project and compilation

**1. Clone the repository**

```bash
git clone [vogsphere_link] [directory_custom_name]
```

**2. Enter the directory**

```bash
cd [directory_name]
```

**3. Compile the project using the Makefile:**

```bash
make all
```
For bonus part :
```bash
make bonus
```

[**back to top**](#top)
### Usage


**Input :**
```bash
>./so_long maps/map_name.ber
```
or
```bash
>./so_long_bonus maps/map_name.ber
```
[**back to top**](#top)

### Game rules

- Move player with **WASD** or **Arrow keys**
- Collect all collectibles before reaching the exit
- Reach the exit to win
- Can't walk through wall
- Floor is walkable

### Map Rules

A valid map must:

- Be rectangular
- Be surrounded by walls
- Contain:
  - 1 player (P)
  - 1 exit (E)
  - at least 1 collectible (C)
- Only contain valid characters:
  - 0 → floor
  - 1 → wall
  - C → collectible
  - E → exit
  - P → player
- Have a valid path (player must be able to reach all collectibles and the exit)

## Resources

- to find Bindings for /usr/include/X11/keysymdef.h constants but it is not necessary because we can print keycode from mlx_key_hook:
[x11.keysymdef from factorcode](https://docs.factorcode.org/content/vocab-x11.keysymdef.html)
- [GIMP DOC](https://docs.gimp.org/)
- mlx doc
- stackoverflow

Assets :

- [Assets background and collectible](https://pipoya.itch.io/pipoya-rpg-tileset-32x32)
- [Player animation assets](https://pixelplant.itch.io/chicken-sprite-sheet)

### Use of AI

- Help to optimize functions to get under 25 lines without breaking everything
- Debugging graphical issues (MLX rendering / flickering)
- Memory leak detection and fixes (Valgrind and Minilibx)
- General code review and best practices

## Credits

- Thanks to [PixelPlant](https://itch.io/profile/pixelplant) for the assets of the chicken
- Thanks to [Pipoya](https://pipoya.itch.io/) for the background, collectibles and exit assets
- Thanks to BYonis from 42 Angouleme for the help about leaks and general tips

[**back to top**](#top)
