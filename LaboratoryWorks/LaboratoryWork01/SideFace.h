#pragma once
#include "Face.h"

namespace GraphicElements
{
	class SideFace : public Face
	{
	protected:
		float _height;
		glm::vec3 _topFaceTranslation;
		Face *_topFacePointer;
		Face *_bottomFacePointer;
		void init() override;
	public:
		SideFace();
		SideFace(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, glm::vec3 topFaceTrans, float h, Face * topFace, Face * bottomFace);
		SideFace(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float h, Face * topFace, Face * bottomFace);
		SideFace(glm::vec3 pos, glm::vec3 col, float h, Face * topFace, Face * bottomFace);
		SideFace(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, glm::vec3 topFaceTrans, float h, Face * face);
		SideFace(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float h, Face * face);
		SideFace(glm::vec3 pos, glm::vec3 col, float h, Face * face);

		void init(Face * topFace, Face * bottomFace, glm::vec3 topFaceTrans);
		void saveProperties(CProperties & propertyRS, long figureID, long faceID) override;

		~SideFace();
	};
}

