#pragma once
#include "pch.h"

class Cheat {
public:
    void Tick();

private:
    bool FetchPointers();
    void SpeedHack();
    void UpdateInventory();
    void JumpHack();
    void KeyPressEvents();

    UWorld* World = nullptr;
    APlayerController* PC = nullptr;
    ABP_FirstPersonCharacter_C* Character = nullptr;
    UCharacterMovementComponent* Movement = nullptr;
    UInventorik_C* Inventory = nullptr;

    bool SpeedEnabled = true;
    bool JumpEnabled = true;
    bool InventoryUpdatesEnabled = true;

    int8_t tick_sleep_time = 50;

    float SpeedMultiplier = 3.0f;
    float JumpMultiplier = 3.0f;
};