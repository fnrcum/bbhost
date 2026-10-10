#include "host/bindings.h"
#include "core/config.h"

#include <cstdio>
#include <cassert>

#if defined(BBHOST_HAVE_SDL3)
#include <SDL3/SDL.h>
#endif

bool debug_menu_active() { return false; }
std::uint32_t menu_confirm_button() { return 0x4000u; }
std::uint32_t menu_back_button() { return 0x2000u; }

int main() {
    // 1. Action parsing
    assert(host_gamepad_action_parse("interact") == GamepadAction::Interact);
    assert(host_gamepad_action_parse("cross") == GamepadAction::Interact);
    assert(host_gamepad_action_parse("roll") == GamepadAction::Roll);
    assert(host_gamepad_action_parse("circle") == GamepadAction::Roll);
    assert(host_gamepad_action_parse("use_item") == GamepadAction::UseItem);
    assert(host_gamepad_action_parse("blood_vial") == GamepadAction::BloodVial);
    assert(host_gamepad_action_parse("gestures") == GamepadAction::Gestures);
    assert(host_gamepad_action_parse("touchpad_left") == GamepadAction::Gestures);
    assert(host_gamepad_action_parse("personal_effects") == GamepadAction::PersonalEffects);
    assert(host_gamepad_action_parse("touchpad_right") == GamepadAction::PersonalEffects);
    assert(host_gamepad_action_parse("none") == GamepadAction::None);

#if defined(BBHOST_HAVE_SDL3)
    // 2. Default actions for paddles and extra buttons (Steam Controller / Steam Deck support)
    assert(host_gamepad_button_action(SDL_GAMEPAD_BUTTON_SOUTH) == GamepadAction::Interact);
    assert(host_gamepad_button_action(SDL_GAMEPAD_BUTTON_EAST) == GamepadAction::Roll);
    assert(host_gamepad_button_action(SDL_GAMEPAD_BUTTON_WEST) == GamepadAction::UseItem);
    assert(host_gamepad_button_action(SDL_GAMEPAD_BUTTON_NORTH) == GamepadAction::BloodVial);
    assert(host_gamepad_button_action(SDL_GAMEPAD_BUTTON_BACK) == GamepadAction::Gestures);
    assert(host_gamepad_button_action(SDL_GAMEPAD_BUTTON_TOUCHPAD) == GamepadAction::PersonalEffects);
    assert(host_gamepad_button_action(SDL_GAMEPAD_BUTTON_LEFT_PADDLE1) == GamepadAction::Gestures);
    assert(host_gamepad_button_action(SDL_GAMEPAD_BUTTON_RIGHT_PADDLE1) == GamepadAction::PersonalEffects);
    assert(host_gamepad_button_action(SDL_GAMEPAD_BUTTON_LEFT_PADDLE2) == GamepadAction::L3);
    assert(host_gamepad_button_action(SDL_GAMEPAD_BUTTON_RIGHT_PADDLE2) == GamepadAction::Roll);
    assert(host_gamepad_button_action(SDL_GAMEPAD_BUTTON_MISC1) == GamepadAction::PersonalEffects);
#endif

    std::printf("gamepad_mapping_test: ok\n");
    return 0;
}
