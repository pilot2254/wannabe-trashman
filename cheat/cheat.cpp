#include "pch.h"
#include "cheat.hpp"

bool Cheat::FetchPointers()
{
    World = UWorld::GetWorld();
    if (!World) return false;

    PC = World->OwningGameInstance->LocalPlayers[0]->PlayerController;
    if (!PC) return false;

    Character = static_cast<ACharacter*>(PC->AcknowledgedPawn);
    if (!Character) return false;

    Movement = Character->CharacterMovement;
    if (!Movement) return false;

    return true;
}

void Cheat::SpeedHack()
{
    Movement->MaxWalkSpeed = SpeedEnabled ? 600.0f * SpeedMultiplier : 600.0f;
}

void Cheat::Tick()
{
    if (!FetchPointers()) return;

    SpeedHack();
}