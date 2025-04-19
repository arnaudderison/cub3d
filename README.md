# 🎩 cub3d – 42 Project

A 3D graphical project made with **MiniLibX**, inspired by the classic **Wolfenstein 3D** game. This project is part of the 42 core curriculum and introduces fundamental concepts of **raycasting**, **event handling**, and **game rendering**.

![Project Score Screenshot](./.preview/score.png)

---

S

## 🌍 Project Overview

`cub3d` is a simple 3D engine that renders a world from a first-person perspective using raycasting. The player can move, rotate, and explore a map defined by a `.cub` file.

Features include:

- Real-time rendering with raycasting
- Player movement and rotation
- Wall textures and sprite rendering
- Minimap _(bonus)_
- Doors and animated sprites _(bonus)_
- Mouse support _(bonus)_

---

## 📂 Repository Structure

```
cub3d/
├── src/           # Main source files (parsing, rendering, raycasting)
├── obj/           # Object files
├── include/       # Header files
├── Makefile       # Build configuration
└── README.md      # Project documentation
```

---

## 📄 Map File Format

The `.cub` configuration file describes:

- Resolution
- Texture paths
- Floor and ceiling colors
- Map layout with walls (`1`), space (`0`), and player start position (`N`, `S`, `E`, `W`)

---

## 🎮 Controls

- `W` / `S`: Move forward / backward
- `A` / `D`: Strafe left / right
- `←` / `→`: Rotate left / right
- `MOUSE`: Rotate view _(bonus)_
- `ESC`: Exit the game

---

## 👤 Authors

**Arnaud Derison**  
Student at 42 | Passionate about low-level graphics & game engines  
[GitHub](https://github.com/arnaudDerison) • [Website](https://derison.dev)

**Lopine**  
[GitHub](https://github.com/Lopine)

---

## ⭐️ Support

Feel free to ⭐️ this repo if you found it useful or inspiring! Contributions and forks are always welcome.

---

## 📄 License

This project is open source and available under the [MIT License](LICENSE).
