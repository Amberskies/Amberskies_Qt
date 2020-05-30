#include "EcsComponent.h"

Array<std::tuple<ECSComponentCreateFunction, ECSComponentFreeFunction, size_t> >* BaseECSComponent::componentTypes;

uint32 BaseECSComponent::registerComponentType(ECSComponentCreateFunction createfn,
			ECSComponentFreeFunction freefn, size_t size)
{
	if(componentTypes == nullptr) {
		componentTypes = new Array<std::tuple<ECSComponentCreateFunction, ECSComponentFreeFunction, size_t> >();
	}
	uint32 componentID = static_cast<uint32>(componentTypes->size());
	componentTypes->push_back(std::tuple<ECSComponentCreateFunction, ECSComponentFreeFunction, size_t>(
				createfn, freefn, size));
	return componentID;
}
