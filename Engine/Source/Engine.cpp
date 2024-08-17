#include "Engine.h"
#include <crtdbg.h>


bool Engine::Initialize()
{
	//eneble memory leak check
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	m_renderer = std::make_unique<Renderer>();
	m_input = std::make_unique<Input>();
	m_audio = std::make_unique<Audio>();
	m_time = std::make_unique<Time>();
	m_ps = std::make_unique<ParticleSystem>();

	m_renderer->Initialize();
	m_renderer->CreateWindow("Game Engine", 800, 600);

	m_input->Initialize();
	m_audio->Initialize();
	return true;
}

void Engine::Update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			quit = true;
		}
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
			quit = true;
		}
	}
	m_input->Update();
	m_audio->Update();
	m_time->Tick();
	m_ps->Update(m_time->GetDeltaTime());

}

bool Engine::IsQuit()
{
	return quit;
}

void Engine::Shutdown()
{
	m_renderer->Shutdown();
	m_input->Shutdown();
	m_audio->Shutdown();

	//display memory leaks
	_CrtMemDumpAllObjectsSince(NULL);
}