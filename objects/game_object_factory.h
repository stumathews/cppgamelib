#pragma once
#include <memory>
#include "tinyxml2.h"
#include "GameObject.h"
namespace gamelib
{
	class resource_manager;

	class game_object_factory
	{
	public:
		static game_object_factory& get_instance();
		 game_object_factory(game_object_factory const&)  = delete;
		 ~game_object_factory();
		void operator=(game_object_factory const&)  = delete;
		 
		std::shared_ptr<GameObject> build_game_object(tinyxml2::XMLElement * scene_object_xml, std::shared_ptr<resource_manager> resource_admin,  std::shared_ptr<settings_manager> settings_admin) const;
		std::shared_ptr<GameObject>& initialize_game_object(std::shared_ptr<GameObject>& game_object, uint x, uint y, bool is_visible, std::shared_ptr<graphic_resource>& resource, bool color_key_enabled, const uint& red, const uint& green, const uint& blue, std::shared_ptr<resource_manager> resource_admin, std::shared_ptr<settings_manager> settings_admin) const;
	private:
		static game_object_factory& m_Instance;
		 game_object_factory();
	};
}

