#pragma once

#include "Color.h"
#include "Renderer.h"
#include "../Math/Vector2.h" 
#include "../Math/Transform.h"
#include <vector>
class Model
{
public:
	Model() = default;
	Model(const std::vector<Vector2>& points, Color color) :
		m_points{ points },
		m_color{ color }
	{}

	void Draw(Renderer& renderer, const Vector2& position, float angle, float scale);
	void Draw(Renderer& renderer, const Transform& transform); 


	float GetRadius();

private:
	std::vector<Vector2> m_points;
	Color m_color;
};