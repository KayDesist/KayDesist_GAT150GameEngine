#pragma once 
#include "../Resources/Resource.h"
#include <SDL_ttf.h>
#include <string>


class Font : public Resource{
public:
	Font() = default;
	~Font();

	bool Load(const std::string& name, int fontsize);

	friend class Text;

	_TTF_Font* GetFont() { return m_ttfFont; }

	// Inherited via Resource
	bool Create(std::string name, ...) override;

private:
	_TTF_Font* m_ttfFont{ nullptr };

};
