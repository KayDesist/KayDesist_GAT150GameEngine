#include "CircleCollisionComponent.h"
#include "../Framework/Actor.h"


FACTORY_REGISTER(CircleCollisionComponent)

void CircleCollisionComponent::Initialize()
{
    //
}

void CircleCollisionComponent::Update(float dt)
{
    //
}

bool CircleCollisionComponent::CheckCollision(const CollisionComponent* collision)
{
    float r1 = radius;
    float r2 = (dynamic_cast<const CircleCollisionComponent*>(collision))->radius;

    float distance = owner->transform.position.Distance(collision->owner->transform.position);

    return (distance <= (r1 + r2));
}

void CircleCollisionComponent::read(const json_t& value)
{
    READ_DATA(value, radius);
}

void CircleCollisionComponent::Write(json_t& value)
{
    //
}