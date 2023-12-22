#include "Parrot.h"

Parrot::Parrot(JsonObject& obj) : IEntity(obj) {}

Parrot::~Parrot() {
    if (movementStrategy) delete movementStrategy;
}

void Parrot::update(double dt) {
    if (movementStrategy == nullptr) {
        movementStrategy = new CircleStrategy();
    }
    movementStrategy->move(this, dt);
    if (movementStrategy->isCompleted()) {
        delete movementStrategy;
        movementStrategy = nullptr;
    }
}
