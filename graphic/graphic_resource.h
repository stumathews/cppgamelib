#pragma once
#include <SDL.h>
#include "asset/asset.h"
#include "common/aliases.h"
#include "util/settings_manager.h"

namespace gamelib
{
	class sdl_graphics_manager;

	// A stand-alone graphics resource with backing storage that can load and unload itself
	class graphic_resource : public asset
	{
		std::shared_ptr<sdl_graphics_manager> graphics_admin;
		std::shared_ptr<settings_manager> config;
	public:		
		graphic_resource(const int uid, std::string name, const std::string& path, const std::string& type, const int level, const bool is_animated, std::shared_ptr<sdl_graphics_manager> graphics_admin, std::shared_ptr<settings_manager> config);
		graphic_resource(const int uid, std::string name, const std::string& path, const std::string& type, const int level, const uint num_key_frames, uint key_frame_height, const uint key_frame_width, const bool is_animated, std::shared_ptr<sdl_graphics_manager> graphics_admin, std::shared_ptr<settings_manager> config);
		virtual ~graphic_resource();

		SDL_Texture* texture = nullptr; // The binary data that will represent the resource once its loaded.

		uint num_key_frames = 0;
		uint key_frame_height = 0;
		uint key_frame_width = 0;
		bool is_animated = false;
		SDL_Rect view_port = {};

		//Load the resource onto the surface
		void load() override;

		// a render resource can unload itself from memory
		bool unload() override;
	};
}

