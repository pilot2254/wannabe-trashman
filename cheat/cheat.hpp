#pragma once
#include "pch.h"

class Cheat {
public:
    void Tick();

private:
    bool FetchPointers();
    void SpeedHack();

    UWorld* World = nullptr;
    APlayerController* PC = nullptr;
    ACharacter* Character = nullptr;
    UCharacterMovementComponent* Movement = nullptr;

    bool SpeedEnabled = true;
    float SpeedMultiplier = 3.0f;
};