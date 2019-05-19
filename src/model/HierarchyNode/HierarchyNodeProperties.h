#ifndef MODEL_HIERARCHYNODEPROPERTIES_H
#define MODEL_HIERARCHYNODEPROPERTIES_H

#include <model/model_Export.h>
#include <string>

namespace HierarchyNodeProperties {

	model_EXPORT const std::string name();
	model_EXPORT const std::string type();
	model_EXPORT const std::string emptyChild();
	model_EXPORT const std::string boundChild(std::string type);

}


#endif //MODEL_HIERARCHYNODEPROPERTIES_H