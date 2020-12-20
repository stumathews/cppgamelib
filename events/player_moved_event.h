#pragma once
#include <memory>
#include "Event.h"
#include "objects/player_component.h"
namespace gamelib
{
	class player_moved_event final : public event
	{
	public:
		explicit player_moved_event(std::shared_ptr<player_component> &component) : event(event_type::PlayerMovedEventType), player(component) { }
		std::shared_ptr<player_component> get_player_component() const { return player; }
		std::string to_str() override;
	private:
		std::shared_ptr<player_component> player;
	};
}

