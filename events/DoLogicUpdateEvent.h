#pragma once
#include "Event.h"

namespace gamelib
{
	class do_logic_update_event final : public event
	{
	public:
		do_logic_update_event();
		std::string to_str() override;
	};
}
