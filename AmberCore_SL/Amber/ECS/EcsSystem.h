#pragma once

#include "EcsComponent.h"

class BaseECSSystem
{
    float m_deltaTime;
    BaseECSComponent** m_components;
public:
	enum
	{
		FLAG_OPTIONAL = 1,
	};

	BaseECSSystem() {}
    virtual void UpdateComponents(float delta, BaseECSComponent** components)
    {
        m_deltaTime = delta;
        m_components = components;
    }
	const Array<uint32>& getComponentTypes()
	{
		return componentTypes;
	}
	const Array<uint32>& getComponentFlags()
	{
		return componentFlags;
	}
	bool isValid();
protected:
	void AddComponentType(uint32 componentType, uint32 componentFlag = 0)
	{
		componentTypes.push_back(componentType);
		componentFlags.push_back(componentFlag);
	}
private:
	Array<uint32> componentTypes;
	Array<uint32> componentFlags;
};

class ECSSystemList
{
public:
	inline bool addSystem(BaseECSSystem& system)
	{
		if(!system.isValid()) {
			return false;
		}
		systems.push_back(&system);
		return true;
	}
	inline size_t size() {
		return systems.size();
	}
	inline BaseECSSystem* operator[](uint32 index) {
		return systems[index];
	}
	bool removeSystem(BaseECSSystem& system);
private:
	Array<BaseECSSystem*> systems;
};
