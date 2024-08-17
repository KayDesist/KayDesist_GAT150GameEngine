#include "Actor.h"
#include "../Engine.h"
#include "../Components/RenderComponent.h"

void Actor::Initialize() {
	for (auto& component : m_components) {

	}
}

void Actor::Update(float dt)
{
	//check for lifespan
	if (m_lifespan != 0) {
		m_lifespan -= dt;
		if (m_lifespan <= 0) {
			m_destroyed = true;
		}
	}

	for (auto& component : m_components) {
		component->Update(dt);
	}

	m_transform.position += (m_velocity * dt);
	m_velocity *= 1.0f / (1.0f + m_damping * dt);
}

void Actor::Draw(Renderer& renderer)
{
	if (m_destroyed) return;

	for (auto& component : m_components) {

		RenderComponent* renderComponent = dynamic_cast<RenderComponent*>(component.get());
		if (renderComponent) {

			renderComponent#include "Actor.h"
#include "Engine.h"
#include "Components/RenderComponent.h"
#include "Core/Factory.h"

#include <iostream>

				void Actor::Initialize() {
				for (auto& component : components) {
					component->Initialize();
				}
			}

			void Actor::Update(float dt)
			{
				//check for lifespan
				if (lifespan != 0) {
					lifespan -= dt;
					if (lifespan <= 0) {
						destroyed = true;
					}
				}

				for (auto& component : components) {
					component->Update(dt);
				}
			}

			void Actor::Draw(Renderer & renderer)
			{
				if (destroyed) return;

				for (auto& component : components) {

					RenderComponent* renderComponent = dynamic_cast<RenderComponent*>(component.get());
					if (renderComponent) {

						renderComponent->Draw(renderer);
					}

				}
			}

			void Actor::AddComponent(std::unique_ptr<Component> component)
			{
				component->owner = this;
				components.push_back(std::move(component));
			}

			void Actor::read(const json_t & value) {
				Object::read(value);

				READ_DATA(value, tag);
				READ_DATA(value, lifespan);

				if (HAS_DATA(value, transform)) transform.read(GET_DATA(value, transform));

				//read components
				if (HAS_DATA(value, components) && GET_DATA(value, components).IsArray()) {
					for (auto& componentValue : GET_DATA(value, components).GetArray()) {

						std::string type;
						READ_DATA(componentValue, type);

						auto component = Factory::Instance().Create<Component>(type);
						if (!component) {
							std::cerr << "Could not read value: " << type << std::endl;
							continue;
						}
						component->read(componentValue);
						AddComponent(move(component));
					}
				}
			}

			void Actor::Write(json_t & value) {

			} >Draw(renderer);
		}

	}
}

void Actor::AddComponent(std::unique_ptr<Component> component)
{
	component->owner = this;
	m_components.push_back(std::move(component));
}

void Actor::Read(const json_t& value)
{  
	Object::Read(value); 

	READ_DATA(value, m_tag);
	READ_DATA(value, m_lifespan);
}

void Actor::Write(json_t& value)
{ 
	//
}
