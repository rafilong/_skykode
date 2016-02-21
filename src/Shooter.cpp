#include "Shooter.h"

Shooter::Shooter(int LPort, int RPort) :
    HitterState(State::RETRACTED),
    Hitter((uint32_t) LPort, (uint32_t) RPort)
{
}

void Shooter::Switch() {
    if (HitterState == State::EXTENDED) {
        Hitter.Set(DoubleSolenoid::kReverse);
        HitterState = State::RETRACTED;
    } else {
        Hitter.Set(DoubleSolenoid::kForward);
        HitterState = State::EXTENDED;
    }
}

State Shooter::GetState() {
    return HitterState;
}

void Shooter::ForceExtend() {
    Hitter.Set(DoubleSolenoid::kForward);
    HitterState = State::EXTENDED;
}

void Shooter::ForceRetract() {
    Hitter.Set(DoubleSolenoid::kReverse);
    HitterState = State::RETRACTED;
}

void Shooter::AutoShoot() {
    if (HitterState != State::EXTENDED) {
        Hitter.Set(DoubleSolenoid::kForward);
        HitterState = State::EXTENDED;
    }

    Wait(0.5);

    if (HitterState == State::EXTENDED) {
        Hitter.Set(DoubleSolenoid::kReverse);
        HitterState = State::RETRACTED;
    }
}
