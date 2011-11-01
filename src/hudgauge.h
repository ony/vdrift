#ifndef _HUDGAUGE_H
#define _HUDGAUGE_H

#include "text_draw.h"

class HUDGAUGE
{
public:
	HUDGAUGE();

	// startangle and endangle in rad
	// startvalue + endvalue = numvalues * delta
	void Set(
		SCENENODE & parent,
		FONT & font,
		float hwratio,
		float centerx,
		float centery,
		float radius,
		float startangle,
		float endangle,
		int startvalue,
		int endvalue,
		int numvalues,
		std::ostream & error_output);

	void Update(SCENENODE & parent, float value);

	void SetVisible(SCENENODE & parent, bool newvis)
	{
		DRAWABLE & drawref = parent.GetDrawlist().twodim.get(dial_draw);
		drawref.SetDrawEnable(newvis);
	}


private:
	keyed_container<SCENENODE>::handle pointer_node;
	//keyed_container<SCENENODE>::handle dial_node;
	keyed_container<DRAWABLE>::handle pointer_draw;
	keyed_container<DRAWABLE>::handle dial_draw;
	std::vector<TEXT_DRAW> dialnums;
	VERTEXARRAY dial;
	float offset;
	float scale;
};

#endif // _HUDGAUGE_H
