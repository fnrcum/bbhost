# Steam Controller

bbhost reads the Steam Controller (the 2026 model), the Steam Deck and any
other pad through SDL3. SDL's Steam, HORI Steam and Steam Deck HIDAPI drivers
are switched on at start, so the grips (L4/R4/L5/R5), the touchpads and the
gyro come through as pad buttons.

## Steam setup

1. Add `run-bbhost.sh` (or `bbhost`) to Steam as a Non-Steam Game, and start
   it from Steam (Big Picture / Game Mode if you can) so Steam's desktop
   controls are off while it runs.
2. Properties, Controller: keep Steam Input on and use the **Gamepad** template.
3. Right trackpad: either **As Joystick** or **Mouse**. Both work - while a
   pad is the last thing used, mouse camera movement from the trackpad no
   longer flips the on-screen prompts to keyboard glyphs, and it works
   together with the left stick.
4. Grips and Back: bind them in Steam to gamepad buttons, or leave them to
   bbhost's defaults below.

## Controller only

If Steam still sends keys or clicks alongside the pad, pin the input to the
controller; the keyboard and mouse then never drive the game or switch the
prompts:

```toml
[input]
device = "controller"
```

(`BBHOST_INPUT_DEVICE=controller` does the same for one run.)

## Default grip and extra buttons

| Button | Action |
| --- | --- |
| Back / View | Gestures (touchpad left) |
| Touchpad click, Share / Misc | Personal effects (touchpad right) |
| L4 | Gestures |
| R4 | Personal effects |
| L5 | L3 |
| R5 | Roll |

## Rebinding

Add a `[gamepad]` (or `[controller]`) section to your `bbhost.toml`:

```toml
[gamepad]
l4 = "gestures"
r4 = "personal_effects"
l5 = "none"
```

Buttons and actions are listed in `bbhost.example.toml`. Unknown names are
logged and skipped.

## Building

See [building.md](building.md). From Linux:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=RelWithDebInfo
cmake --build build -j
ctest --test-dir build -R gamepad_mapping_test
```

Or let GitHub build it: the **build** workflow in your fork's Actions tab has
a "Run workflow" button, and every push runs it too.
