#ifndef ENTITIES_H
#define ENTITIES_H

#include "framework.h";
#include "includes.h"
#include "mesh.h"
#include "texture.h"
#include "shader.h"
#include "camera.h"
#include "animation.h"


enum eEntityType {
	NONE = 0,
	ENTITY_MESH = 1,
};

class Entity {
public:
	Entity();
	//virtual ~Entity(); //destructor

	eEntityType entity_type;
	Matrix44 model;
	std::string name;

	virtual void render() {};
	virtual void update(float elapsed_time) {};

	Entity* parent;

	//pointers to my children
	std::vector<Entity*> children;

	//methods
	void addChild(Entity* ent);
	void removeChild(Entity* ent);
	
	//Vector3 getPosition();
};


class EntityMesh : public Entity {
public:
	Mesh* mesh;
	Texture* texture;
	Shader* shader;
	Vector4 color;

	EntityMesh();
	EntityMesh(Mesh* mesh, Texture* texture, Shader* shader, Vector4 color);
	void render();
	void render(Matrix44 model);
	void render_anim(Animation* anim);
	void render_anim(Skeleton* skel);
	void update(float dt);
};

enum eObstacleType {
	BAD,
	GOOD,
	GOAL
};

class Obstacle : public EntityMesh {
public:
	Obstacle(Mesh* mesh, Texture* texture, Shader* shader, Vector4 color, eObstacleType type);
	eObstacleType type;
	
};


class Goal : public Entity {
public:
	Mesh* mesh;
	Texture* texture;
	Shader* shader;
	Vector4 color;

	Goal();
	Goal(Mesh* mesh, Texture* texture, Shader* shader, Vector4 color);
	void render(int currentLaps);

};
	

#endif
