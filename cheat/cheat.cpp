#include "pch.h"
#include "cheat.hpp"

bool Cheat::FetchPointers()
{
    World = UWorld::GetWorld();
    if (!World) return false;

    PC = World->OwningGameInstance->LocalPlayers[0]->PlayerController;
    if (!PC) return false;

    Character = static_cast<ABP_FirstPersonCharacter_C*>(PC->AcknowledgedPawn);
    if (!Character) return false;

    Movement = Character->CharacterMovement;
    if (!Movement) return false;

    Inventory = Character->Inventorik;
    if (!Inventory) return false;

    return true;
}

void Cheat::SpeedHack()
{
    if (!SpeedEnabled) return;
    Movement->MaxWalkSpeed = 600.0f * SpeedMultiplier;
}

void Cheat::JumpHack()
{
    if (!JumpEnabled) return;

    Movement->JumpZVelocity = 420.0 * JumpMultiplier; //original is 420
    Movement->AirControl = 10.0;
}

void Cheat::UpdateInventory()
{
    if (!InventoryUpdatesEnabled) return;
    Inventory->max_kg = 1000.0f;
    Inventory->kg = 0.0f;
}

void Cheat::KeyPressEvents()
{
    if (GetAsyncKeyState(VK_F1) & 1) Inventory->Pridaj_mi_do_inv(1000.0, 0.0);

    if (GetAsyncKeyState(VK_RBUTTON) & 1) Character->K2_SetActorLocation(Character->K2_GetActorLocation() + Character->GetActorForwardVector() * 500.f, false, nullptr, true);

    Character->GetTransform();
    
}

void Cheat::Tick()
{
    if (!FetchPointers()) return;

    KeyPressEvents();

    SpeedHack();
    JumpHack();
    UpdateInventory();

    Sleep(tick_sleep_time);
}