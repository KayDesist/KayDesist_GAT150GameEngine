#include "Engine.h"

#include <iostream>
#include <cstdlib>
#include <vector> 
#include <cassert>

int main(int argc, char* argv[])
{
	std::unique_ptr<Engine> engine = std::make_unique<Engine>();
	engine->Initialize();

	//ResourceManager rm = ResourceManager();


	//create texture, using shared_ptr so it can be shared
	res_t<Texture> texture = ResourceManager::Instance().Get<Texture>("laufeybee.jpg", engine->GetRenderer());

	//res_t<Font> Font =
	//texture->Load("laufeybee.jpg", engine->GetRenderer());

	res_t<Font> font = ResourceManager::Instance().Get<Font>("NATIONFD.TTF", 20); 
	std::unique_ptr<Text> text = std::make_unique<Text>(font); 
	text->Create(engine->GetRenderer(), "Hi world!", { 1,0,0,1 });

	

	while (!engine->isQuit()) {
		engine->Update();


		engine->GetRenderer().SetColor(0, 0, 0, 0);

		engine->GetRenderer().BeginFrame();  

		engine->GetPS().Draw(engine->GetRenderer());

		
		engine->GetRenderer().DrawTexture(texture.get(), 30, 30, 0);

		engine->GetRenderer().EndFrame();

	}
	engine->Shutdown();

	return 0;
}

