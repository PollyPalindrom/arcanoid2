#include "audio_system.h"
#include "entity.h"
#include "audio_component.h"
MusicManager* AudioSystem::GetMusicManager() const
{
    return manager.get();
}
void AudioSystem::Update(Context& ctx, Entity* entity)
{
    auto ac = entity->Get<AudioComponent>();
    if (ac->IsPlaying( )) {
        if (ac->IsMusic) {
            manager->PlayMusic(ac->name,ac->loops);
        }
        else {
            manager->PlaySound(ac->name, ac->loops);
        }
        ac->Stop();
    }
}

bool AudioSystem::Filter(Entity* entity) const
{
    return entity->Contains<AudioComponent>();
}
AudioSystem::AudioSystem() : manager(std::make_unique<MusicManager>()) {
    manager->GetAssets()->RegistMusic("music1", "D:\\arcanoid2\\arcanoid2\\grazhdanskaya-oborona-tarasyuk-remiks--po-planu-vse-chiki-pu (online-audio-converter.com).WAV");
    manager->GetAssets()->RegistSound("hit", "D:\\arcanoid2\\arcanoid2\\jg-032316-sfx-8-bit-punch (online-audio-converter.com).WAV");
    manager->GetAssets()->RegistSound("platform", "D:\\arcanoid2\\arcanoid2\\jg-032316-sfx-8-bit-score-1 (online-audio-converter.com).WAV");
    manager->GetAssets()->RegistSound("bonus", "D:\\arcanoid2\\arcanoid2\\aa4b773936bb0cb (online-audio-converter.com).WAV");
}