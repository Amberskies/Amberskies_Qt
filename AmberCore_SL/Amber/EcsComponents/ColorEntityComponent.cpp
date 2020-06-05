
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Jun 5th
 *
 *      Amber - Qt C++
 *
 * Contact email  : amberskies@virginmail.com
 * Website        : www.amberskies.org.uk
 * Twitch         : FrazorBladezSharp
 * Youtube        : Amberskies
 *
 * All code is free to use as you please
 * Please be aware of the Open Source Licence
 * given by Qt    : doc.qt.io/qt-5/opensourcelicence.html
 *
 * ---------------------------------------------------*/
#include "ColorEntityComponent.h"

namespace Amber
{
	namespace EcsComponents
	{
		ColorEntitySystem::ColorEntitySystem(Amber3D::OpenGL::Window3D* window)
			: BaseECSSystem()
			, m_window(window)
		{
			AddComponentType(ColorEntityComponent::ID);
			// AddComponentType(TransformComponent::ID) - build towards this
		}

		void ColorEntitySystem::UpdateComponents(float delta, BaseECSComponent** components)
		{
			ColorEntityComponent* entityComponent = (ColorEntityComponent*)components[0];

			// add to batch Rendering. 
			m_window->RenderColorEntity(entityComponent->colorEntity);
		}
	}
}
