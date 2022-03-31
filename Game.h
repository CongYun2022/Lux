#pragma once
#include <unordered_map>
#include <string>
#include <vector>
#include "Math.h"
#include "SoundEvent.h"
#include <SDL/SDL_types.h>

class Game
{
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class AActor* actor);
	void RemoveActor(class AActor* actor);

	class Renderer* GetRenderer() { return mRenderer; }
	class SAudio* GetAudioSystem() { return mAudioSystem; }
	class SPhys* GetPhysWorld() { return mPhysWorld; }
	class UIHUD* GetHUD() { return mHUD; }
	
	// Manage UI stack
	const std::vector<class UIScreen*>& GetUIStack() { return mUIStack; }
	void PushUI(class UIScreen* screen);
	
	class AFPS* GetPlayer() { return mFPSActor; }
	
	enum GameState
	{
		EGameplay,
		EPaused,
		EQuit
	};
	
	GameState GetState() const { return mGameState; }
	void SetState(GameState state) { mGameState = state; }
	
	class Font* GetFont(const std::string& fileName);

	void LoadText(const std::string& fileName);
	const std::string& GetText(const std::string& key);
	// Game-specific
	void AddPlane(class APlane* plane);
	void RemovePlane(class APlane* plane);
	std::vector<class APlane*>& GetPlanes() { return mPlanes; }
private:
	void ProcessInput();
	void HandleKeyPress(int key);
	void UpdateGame();
	void GenerateOutput();
	void LoadData();
	void UnloadData();
	
	// All the actors in the game
	std::vector<class AActor*> mActors;
	std::vector<class UIScreen*> mUIStack;
	std::unordered_map<std::string, class Font*> mFonts;

	// Map for text localization
	std::unordered_map<std::string, std::string> mText;
	// Any pending actors
	std::vector<class AActor*> mPendingActors;

	class Renderer* mRenderer;
	class SAudio* mAudioSystem;
	class SPhys* mPhysWorld;
	class UIHUD* mHUD;

	Uint32 mTicksCount;
	GameState mGameState;
	// Track if we're updating actors right now
	bool mUpdatingActors;

	// Game-specific code
	std::vector<class APlane*> mPlanes;
	class AFPS* mFPSActor;
	class CSprite* mCrosshair;
	SoundEvent mMusicEvent;
};
