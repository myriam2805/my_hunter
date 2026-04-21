# my_hunter

> A Duck Hunt-inspired 2D shooter built in C with CSFML — featuring animated sprites, pixel art backgrounds, real-time score tracking and frame-independent movement.

## Gameplay

Birds fly across a pixel art sunset landscape. Click on them to shoot. Track your score in real time. Miss too many and the game is over.

---

## Features

### Must ✅
- Window closed by events
- Mouse click input handling
- Animated sprites via sprite sheets
- Moving elements (translation, rotation)
- `-h` option with usage description

### Should ✅
- Frame-independent movement (no speed dependency)
- Animations timed with `sfClock`
- Window resolution between 800x600 and 1920x1080
- Limited frame rate for smooth performance

### Bonuses ✅
- Real-time score display
- High score storage
- Custom cursor/target
- Multiple levels

---

## Build & Run

```bash
# Build
make

# Run
./my_hunter

# Help
./my_hunter -h

# Clean
make clean
make fclean
make re
```

---

## Controls

| Action | Input |
|--------|-------|
| Shoot | Left click |
| Quit | Escape / close window |

---

## Dependencies

- [CSFML](https://www.sfml-dev.org/download/csfml/) — C binding for SFML
- `libm` — math library
- `gcc` + `make`

---

## Author

> Built with ❤️ as part of the Epitech curriculum.
