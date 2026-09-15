#include "pch.h"
#include "cheat.hpp"

bool Cheat::FetchPointers()
{
    World = UWorld::GetWorld(); if (!World) return false;

    UGameInstance* GI = World->OwningGameInstance; if (!GI) return false;

    if (GI->LocalPlayers.Num() == 0) return false; ULocalPlayer* LP = GI->LocalPlayers[0]; if (!LP) return false;

    PC = LP->PlayerController; if (!PC) return false;

    APawn* Pawn = PC->AcknowledgedPawn; if (!Pawn || !Pawn->IsA(ABP_FirstPersonCharacter_C::StaticClass())) return false;

    Character = static_cast<ABP_FirstPersonCharacter_C*>(Pawn);

    Movement = Character->CharacterMovement; if (!Movement) return false;

    Inventory = Character->Inventorik; if (!Inventory) return false;

    return true;
}

void Cheat::SpeedHack()
{
    if (!SpeedEnabled) return;
    Movement->MaxWalkSpeed = 600.0f * SpeedMultiplier; //default was 600
}

void Cheat::JumpHack()
{
    if (!JumpEnabled) return;
    Movement->JumpZVelocity = 420.0f * JumpMultiplier; //default was 420
    Movement->AirControl = 100.0f;
}

void Cheat::UpdateInventory()
{
    if (!InventoryUpdatesEnabled) return;
    Inventory->max_kg = 1000.0f;
    Inventory->kg = 0.0f;
}

void Cheat::KeyPressEvents()
{
    if (GetAsyncKeyState(VK_F1) & 1) Inventory->Pridaj_mi_do_inv(11111.0, 0.0);

    if (GetAsyncKeyState(VK_RBUTTON) & 1) Character->K2_SetActorLocation(Character->K2_GetActorLocation() + Character->GetActorForwardVector() * 500.f, false, nullptr, true);
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