#pragma once
#include "i_system.h"
// как только бонус сталківается с платформой, юонус унічтожается, платформа ізменяет размер фіз і ренд 
class ResizeBonusSystem: public ISystem {
protected:
	bool Filter(Entity* entity) const override;
	void Update(Context& ctx, Entity* entity) override;
};