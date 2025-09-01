namespace offsets
{
    constexpr uintptr_t game_module_address = 0x00400000;
    constexpr uintptr_t LocalPlayer = 0x0017E0A8;

    constexpr uintptr_t player_offset = 0x28;

    constexpr uintptr_t player_rot_x_offset = 0xC;
    constexpr uintptr_t player_rot_y_offset = 0x10;

    constexpr uintptr_t player_pos_x_offset = 0x0;
    constexpr uintptr_t player_pos_y_offset = 0x4;
    constexpr uintptr_t player_pos_z_offset = 0x8;

    constexpr uintptr_t player_grenades_offset = 0x11C;
    constexpr uintptr_t health = 0x00EC;
    constexpr uintptr_t player_shield_offset = 0xC8;
}