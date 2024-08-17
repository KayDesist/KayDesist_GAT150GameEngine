#include "Scene.h"
#include "Actor.h"
#include "../Renderer/Model.h"
#include <algorithm>


void Scene::Update(float dt)
{
	//update
	for (auto& actor : m_actors) {
		actor->Update(dt);
	}
	//collision
	for (auto& actor1 : m_actors) {
		for (auto& actor2 : m_actors) {
			if (actor1 == actor2) continue;

			Vector2 direction = actor1->GetTransform().position - actor2->GetTransform().position;
			float distance = direction.Length();
			float radius = actor1->GetRadius() + actor2->GetRadius();

			if (distance <= radius) {
				actor1->OnCollision(actor2.get());
				actor2->OnCollision(actor1.get());
			}
		}
	}

	//destroy
	//auto iter = m_actors.begin();
	//while (iter != m_actors.end()) {
	//	iter = ((*iter)->m_destroyed) ? m_actors.erase(iter) : ++iter;
	//}

	std::_Erase_remove_if(m_actors, [](auto& actor) { return actor->m_destroyed; });

	//m_actors.erase(std::remove_if(m_actors.begin(), m_actors.end(), [](Actor* actor) {return actor->m_destroyed; }),m_actors.end());
}

void Scene::Draw(Renderer& renderer)
{
	for (auto& actor : m_actors) {
		actor->Draw(renderer);
	}
}

void Scene::AddActor(std::unique_ptr<Actor> actor)
{
	actor->m_scene = this;
	m_actors.push_back(std::move(actor));
}

void Scene::RemoveAll()
{
	m_actors.clear();
}