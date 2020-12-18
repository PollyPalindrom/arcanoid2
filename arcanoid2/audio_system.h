#pragma once
#include "i_system.h"
#include "music_manager.h"
#include <memory>
class AudioSystem :public ISystem {
	unique_ptr<MusicManager> manager;
public:
	AudioSystem();
	MusicManager* GetMusicManager() const;
protected:
	void Update(Context& ctx, Entity* entity) override;
	bool Filter(Entity* entity)const override;

};