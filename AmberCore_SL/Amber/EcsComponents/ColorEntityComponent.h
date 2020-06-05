
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
#pragma once

#include <Amber3D/Entities/ColorEntity.h>
#include <Amber3D/OpenGL/Window3D.h>

#include "Amber/ECS/Ecs.h"


namespace Amber
{
	namespace EcsComponents
	{
		struct ColorEntityComponent : public ECSComponent<ColorEntityComponent>
		{
			Amber3D::Entities::ColorEntity* colorEntity = nullptr;
		};



		class ColorEntitySystem : public BaseECSSystem
		{
			Amber3D::OpenGL::Window3D* m_window;

		public:
			ColorEntitySystem(Amber3D::OpenGL::Window3D* window);

			virtual void UpdateComponents(float delta, BaseECSComponent** components);
		};
	}
}

