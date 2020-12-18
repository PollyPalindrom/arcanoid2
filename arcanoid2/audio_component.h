#pragma once
#include "i_component.h"
#include <string>
using namespace std;
class AudioComponent : public IComponent {
public:
	explicit AudioComponent(const string& name, bool IsMusic, int loops=0) :name(name), IsMusic(IsMusic), loops(loops) {}
	bool IsMusic=false;
	string name;
	bool play=false;
	int loops = 0;
	bool IsPlaying() {
		return play;
	}
	void Play() {
		play = true;
	}
	void Stop(){
		play = false;
	}
};