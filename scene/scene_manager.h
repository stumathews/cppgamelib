#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <list>
#include "Layer.h"
#include "events/EventSubscriber.h"
#include "resource/resource_manager.h"
#include "objects/game_world_data.h"
#include <objects/MultipleInheritableEnableSharedFromThis.h>

using namespace std;

namespace gamelib
{
	// Represents the current scene
	class scene_manager final : public EventSubscriber, public inheritable_enable_shared_from_this<IEventSubscriber>
	{
		shared_ptr<event_manager> event_admin;
		shared_ptr<settings_manager> config;
		shared_ptr<resource_manager> resource_admin;
		shared_ptr<game_world_data> world;
	public:
		scene_manager(shared_ptr<event_manager> ea, shared_ptr<settings_manager> c, shared_ptr<resource_manager> resource_admin, std::shared_ptr<game_world_data> world, std::string scene_folder = "game/");	
		scene_manager(const scene_manager &) = default;
		scene_manager(scene_manager &&) = default;
	    scene_manager& operator=(scene_manager const&)  = delete;
		scene_manager& operator=(scene_manager &&) = default;
		virtual ~scene_manager() = default;

		bool initialize();	
		void start_scene(int scene_id);
		list<shared_ptr<layer>> get_scene_layers() const;
	private:
		void add_to_scene(const shared_ptr<GameObject>& game_object);	
		void load_new_scene(const shared_ptr<event> &the_event, shared_ptr<resource_manager> resource_admin);
		bool load_scene_file(const string &filename, shared_ptr<resource_manager> resource_admin);		
		void remove_layer(const string &name);
		void sort_layers();
		shared_ptr<layer> add_layer(const string &name);
		shared_ptr<layer> find_layer(const string &name);

		// Event management
		static void update();
		vector<shared_ptr<event>> handle_event(shared_ptr<event> the_event) override;
		void remove_from_layers(int game_object_id);
		string get_subscriber_name() override;
			
		list<shared_ptr<layer>> layers;
		string current_scene_name = {};
		bool is_initialized = false;
		std::string scene_folder;
	};
}
#endif