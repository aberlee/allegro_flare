#ifndef __AF_AUTOMATION_HEADER
#define __AF_AUTOMATION_HEADER


/*{


AUTOMATION

automation allows you to create or hook objects and their parameters into
the automation system where their parameters can be controlled by a list
of instructions that occur over time.  You can think of it as scripting,
but it's more like a piece of music, where instructions are given in a
static script. the Actor class controls the parameters for the object,
as well as interpolates values between keyframes (with various available
curves).

Anything can be controlled by an Actor (but right now only float parameters
are controlled).  You could automate the position of an object, or the
value of a volume knob over time, for example.  You could, in essence,
create entire complex animation sequences if you wished.


}*/



#include <allegro_flare/allegro_flare.h>
#include <allegro_flare/timeline.h>




namespace automation
{



class BasicScriptReader
{
private:
	unsigned current_line_index;
	std::vector<std::string> lines;
	static std::string remove_comments(std::string &line);

public:
	BasicScriptReader(std::string script);
	bool at_end();
	std::string get_next_line(bool remove_comments=true);
};





// the Actor class is a pure virtual class and should be user-created
// for their purposes.  An Actor2d example class has been provided

typedef int actor_t;

class Actor
{
public:
	actor_t type;
	std::string identifier;
	std::vector<Timeline::Track<float> *> params;

	Actor(std::string identifier, actor_t type);
	Timeline::Track<float> *get_param_by_id(const char *id);

	virtual void load_script(std::string script_filename);
	virtual void render(double time) = 0;
	virtual void register_params() = 0;
};





class ActorManager
{
protected:
	std::vector<Actor *> actors;

public:
	ActorManager();

	//Actor *create_actor2d(std::string identifier, ALLEGRO_BITMAP *bitmap);
	bool register_actor(Actor *actor);
	bool unregister_actor(Actor *actor);

	Actor *get_actor_by_id(const char *id);
	void render(double time);
};







// here is an example of a user-created Actor-derived class
// A user may also choose to create a factory for their derived classes as well :)
class Actor2D : public Actor
{
public:
	ALLEGRO_BITMAP *bitmap;
	
	Actor2D(std::string identifier, ALLEGRO_BITMAP *bitmap);
	// IMPORTANT
	void register_params();
	void render(double time);
};







/*

class ActorBin : public Bin<Actor *>
{
public:
	ActorBin() : Bin("") {}
	~ActorBin() { clear(); }
	Actor *load_data(std::string identifier);
	void destroy_data(Actor *actor);
};

*/



} // (end namespace automation)





#endif