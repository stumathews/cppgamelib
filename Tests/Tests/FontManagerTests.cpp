﻿#include "pch.h"

#include "common/static_config.h"
#include "events/event_manager.h"
#include "font/font_manager.h"
#include "graphic/sdl_graphics_manager.h"
#include "resource/resource_manager.h"

using namespace std;
using namespace gamelib;

class FontManager : public testing::Test {
 protected:
  void SetUp() override
  { 
	font_admin = make_shared<font_manager>();
  	const shared_ptr<font_resource> ptr(new font_resource(0, resource_name, resource_path, resource_type, resource_scene));  	
  	font_asset_ptr = dynamic_pointer_cast<asset>(ptr);
  }
    
  //void TearDown() override {}
   
  shared_ptr<font_manager> font_admin;

  const string resource_name = "arial.ttf";
  const string resource_path = "Assets/fonts/arial.ttf";
  const string resource_type = "font";
  const int resource_scene = 0;
	
  asset *audio_asset = nullptr;
  shared_ptr<asset> font_asset_ptr;	
};

TEST_F(FontManager, to_resource)
{
	// When casting a asset* to a font_resource...
	auto resource = font_admin->to_resource(font_asset_ptr);

	// Ensure that...
	EXPECT_STREQ(resource->name.c_str(), resource_name.c_str()) << "Resource name is invalid";
	EXPECT_EQ(resource->is_loaded, false) << "is loaded flag is invalid";
	EXPECT_STREQ(resource->path.c_str(), resource_path.c_str()) << "resource path is invalid";
	EXPECT_EQ(resource->scene, resource_scene) << "Resource scene is invalid";
}

